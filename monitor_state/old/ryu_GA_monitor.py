from ryu.base import app_manager
from ryu.controller import mac_to_port
from ryu.controller import ofp_event
from ryu.controller.handler import CONFIG_DISPATCHER, MAIN_DISPATCHER
from ryu.controller.handler import set_ev_cls
from ryu.ofproto import ofproto_v1_3
from ryu.lib.mac import haddr_to_bin
from ryu.lib.packet import packet
from ryu.lib.packet import arp
from ryu.lib.packet import ethernet
from ryu.lib.packet import ipv4
from ryu.lib.packet import ipv6
from ryu.lib.packet import ether_types
from ryu.lib import mac, ip
from ryu.topology.api import get_switch, get_link
from ryu.app.wsgi import ControllerBase
from ryu.topology import event
from collections import defaultdict
from operator import itemgetter
import os
import random
import time
import copy
from Al_GA import GA
import network_monitor
import network_delay_detector
import network_awareness
from ryu import cfg
import setting
from ryu.lib import hub
from ryu.base.app_manager import lookup_service_brick
import json
import numpy as np

CONF = cfg.CONF

class ProjectController(app_manager.RyuApp):
    OFP_VERSIONS = [ofproto_v1_3.OFP_VERSION]

    _CONTEXTS = {
        "network_awareness": network_awareness.NetworkAwareness,
        "network_monitor": network_monitor.NetworkMonitor,
        "network_delay_detector": network_delay_detector.NetworkDelayDetector}

    def __init__(self, *args, **kwargs):
        super(ProjectController, self).__init__(*args, **kwargs)
        self.name = 'GA_monitor'
        self.mac_to_port = {}
        self.topology_api_app = self
        self.datapath_list = {}
        self.arp_table = {}
        self.switches = []
        self.hosts = {}
        self.multipath_group_ids = {}
        self.adjacency = defaultdict(dict)
        self.paths = []
        self.awareness = kwargs["network_awareness"]
        self.monitor = kwargs["network_monitor"]
        self.delay_detector = kwargs["network_delay_detector"]
        self.modify = hub.spawn(self._modify_group)
        self.node_ports = {}
        self.paths_dict = {}
        self.pw_dict = {}
        self.get_paths()
    
    def get_paths(self):
        with open('paths.json') as f:
            self.paths_dict = json.load(f)
        f.close()
        with open('paths_w.json') as f:
            self.pw_dict = json.load(f)
        f.close()

    def _modify_group(self):
        while True:
            hub.sleep(setting.MODIDY_GROUP_PERIOD)
            self.modify_group()

    def modify_group(self):
        with open('paths_w.json') as f:
            self.pw_dict = json.load(f)
        f.close()
        for key in self.multipath_group_ids.keys():
            node = key[0]
            src = key[1]
            dst = key[2]
            ip_src = key[3]
            ip_dst = key[4]
            first_port = key[5]
            last_port = key[6]
            self.make_group(src, first_port, dst, last_port, ip_src, ip_dst)
    
    def add_ports_to_paths(self, paths, first_port, last_port):
        '''
        Add the ports that connects the switches for all paths
        '''
        paths_p = []
        for path in paths:
            p = {}
            in_port = first_port
            for s1, s2 in zip(path[:-1], path[1:]):
                out_port = self.adjacency[s1][s2]
                p[s1] = (in_port, out_port)
                in_port = self.adjacency[s2][s1]
            p[path[-1]] = (in_port, last_port)
            paths_p.append(p)
        return paths_p

    def generate_openflow_gid(self):
        '''
        Returns a random OpenFlow group id
        '''
        n = random.randint(0, 2**32)
        while n in self.multipath_group_ids.values():
            n = random.randint(0, 2**32)
        return n


    def install_paths(self, src, first_port, dst, last_port, ip_src, ip_dst):
        para = str([dst, src])
        self.paths = copy.deepcopy(self.paths_dict[para])
        pw = copy.deepcopy(self.pw_dict[para])
        sum_of_pw = sum(pw)
        if(sum_of_pw==0):
            pw = [1 for item in pw]
            sum_of_pw = sum(pw)
        paths_with_ports = self.add_ports_to_paths(self.paths, first_port, last_port)
        switches_in_paths = set().union(*self.paths)

        for node in switches_in_paths:

            dp = self.datapath_list[node]
            ofp = dp.ofproto
            ofp_parser = dp.ofproto_parser

            ports = defaultdict(list)
            actions = []
            i = 0

            for path in paths_with_ports:
                if node in path:
                    in_port = path[node][0]
                    out_port = path[node][1]
                    if (out_port, pw[i]) not in ports[in_port]:
                        ports[in_port].append((out_port, pw[i]))
                i += 1

            self.node_ports[node] = ports
            for in_port in ports:

                match_ip = ofp_parser.OFPMatch(
                    in_port=in_port,
                    eth_type=0x0800, 
                    ipv4_src=ip_src, 
                    ipv4_dst=ip_dst
                )
                match_arp = ofp_parser.OFPMatch(
                    in_port=in_port,
                    eth_type=0x0806, 
                    arp_spa=ip_src, 
                    arp_tpa=ip_dst
                )

                out_ports = ports[in_port]
                if len(out_ports) > 1:
                    group_id = None
                    group_new = False

                    if (node, src, dst, ip_src, ip_dst, first_port, last_port) not in self.multipath_group_ids:
                        group_new = True
                        self.multipath_group_ids[
                            node, src, dst, ip_src, ip_dst, first_port, last_port] = self.generate_openflow_gid()
                    group_id = self.multipath_group_ids[node, src, dst, ip_src, ip_dst, first_port, last_port]

                    buckets = []
                    for port, weight in out_ports:
                        bucket_weight = int(round((1-weight/sum_of_pw) * 100))
                        bucket_action = [ofp_parser.OFPActionOutput(port)]
                        buckets.append(
                            ofp_parser.OFPBucket(
                                weight=bucket_weight,
                                watch_port=port,
                                watch_group=ofp.OFPG_ANY,
                                actions=bucket_action
                            )
                        )

                    if group_new:
                        req = ofp_parser.OFPGroupMod(
                            dp, ofp.OFPGC_ADD, ofp.OFPGT_SELECT, group_id,
                            buckets
                        )
                        dp.send_msg(req)
                    else:
                        req = ofp_parser.OFPGroupMod(
                            dp, ofp.OFPGC_MODIFY, ofp.OFPGT_SELECT,
                            group_id, buckets)
                        dp.send_msg(req)

                    actions = [ofp_parser.OFPActionGroup(group_id)]

                    self.add_flow(dp, 32768, match_ip, actions)
                    self.add_flow(dp, 1, match_arp, actions)

                elif len(out_ports) == 1:
                    actions = [ofp_parser.OFPActionOutput(out_ports[0][0])]

                    self.add_flow(dp, 32768, match_ip, actions)
                    self.add_flow(dp, 1, match_arp, actions)
        return paths_with_ports[0][src][1]
    
    def make_group(self, src, first_port, dst, last_port, ip_src, ip_dst):
        para = str([dst, src])
        self.paths = copy.deepcopy(self.paths_dict[para])
        pw = copy.deepcopy(self.pw_dict[para])
        sum_of_pw = sum(pw)
        if(sum_of_pw==0):
            pw = [1 for item in pw]
            sum_of_pw = sum(pw)
        paths_with_ports = self.add_ports_to_paths(self.paths, first_port, last_port)
        switches_in_paths = set().union(*self.paths)

        for node in switches_in_paths:

            dp = self.datapath_list[node]
            ofp = dp.ofproto
            ofp_parser = dp.ofproto_parser

            ports = defaultdict(list)
            i = 0

            for path in paths_with_ports:
                if node in path:
                    in_port = path[node][0]
                    out_port = path[node][1]
                    if (out_port, pw[i]) not in ports[in_port]:
                        ports[in_port].append((out_port, pw[i]))
                i += 1

            self.node_ports[node] = ports
            for in_port in ports:
                out_ports = ports[in_port]
                if len(out_ports) > 1:
                    group_id = self.multipath_group_ids[node, src, dst, ip_src, ip_dst, first_port, last_port]
                    buckets = []
                    for port, weight in out_ports:
                        bucket_weight = int(round((1-weight/sum_of_pw) * 100))
                        bucket_action = [ofp_parser.OFPActionOutput(port)]
                        buckets.append(
                            ofp_parser.OFPBucket(
                                weight=bucket_weight,
                                watch_port=port,
                                watch_group=ofp.OFPG_ANY,
                                actions=bucket_action
                            )
                        )
                    req = ofp_parser.OFPGroupMod(
                        dp, ofp.OFPGC_MODIFY, ofp.OFPGT_SELECT,
                        group_id, buckets)
                    dp.send_msg(req)

    def add_flow(self, dp, priority, match, actions, idle_timeout=0, hard_timeout=0):
        """
            Send a flow entry to datapath.
        """
        ofproto = dp.ofproto
        parser = dp.ofproto_parser
        inst = [parser.OFPInstructionActions(ofproto.OFPIT_APPLY_ACTIONS, actions)]
        mod = parser.OFPFlowMod(datapath=dp, command=dp.ofproto.OFPFC_ADD, priority=priority,
                                idle_timeout=idle_timeout,
                                hard_timeout=hard_timeout,
                                match=match, instructions=inst)
        dp.send_msg(mod)

    @set_ev_cls(ofp_event.EventOFPPacketIn, MAIN_DISPATCHER)
    def _packet_in_handler(self, ev):
        msg = ev.msg
        datapath = msg.datapath
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser
        in_port = msg.match['in_port']

        pkt = packet.Packet(msg.data)
        eth = pkt.get_protocol(ethernet.ethernet)
        arp_pkt = pkt.get_protocol(arp.arp)

        # avoid broadcast from LLDP
        if eth.ethertype == 35020:
            return

        if pkt.get_protocol(ipv6.ipv6):  # Drop the IPV6 Packets.
            match = parser.OFPMatch(eth_type=eth.ethertype)
            actions = []
            self.add_flow(datapath, 1, match, actions)
            return None

        dst = eth.dst
        src = eth.src
        dpid = datapath.id

        if src not in self.hosts:
            self.hosts[src] = (dpid, in_port)

        out_port = ofproto.OFPP_FLOOD

        if arp_pkt:
            src_ip = arp_pkt.src_ip
            dst_ip = arp_pkt.dst_ip
            if arp_pkt.opcode == arp.ARP_REPLY:
                self.arp_table[src_ip] = src
                h1 = self.hosts[src]
                h2 = self.hosts[dst]
                out_port = self.install_paths(h1[0], h1[1], h2[0], h2[1], src_ip, dst_ip)
                self.install_paths(h2[0], h2[1], h1[0], h1[1], dst_ip, src_ip) # reverse
            elif arp_pkt.opcode == arp.ARP_REQUEST:
                if dst_ip in self.arp_table:
                    self.arp_table[src_ip] = src
                    dst_mac = self.arp_table[dst_ip]
                    h1 = self.hosts[src]
                    h2 = self.hosts[dst_mac]
                    out_port = self.install_paths(h1[0], h1[1], h2[0], h2[1], src_ip, dst_ip)
                    self.install_paths(h2[0], h2[1], h1[0], h1[1], dst_ip, src_ip) # reverse

        actions = [parser.OFPActionOutput(out_port)]
        data = None
        if msg.buffer_id == ofproto.OFP_NO_BUFFER:
            data = msg.data
        out = parser.OFPPacketOut(
            datapath=datapath, buffer_id=msg.buffer_id, in_port=in_port,
            actions=actions, data=data)
        datapath.send_msg(out)

    @set_ev_cls(event.EventSwitchEnter)
    def switch_enter_handler(self, ev):
        switch = ev.switch.dp
        ofp_parser = switch.ofproto_parser

        if switch.id not in self.switches:
            self.switches.append(switch.id)
            self.datapath_list[switch.id] = switch

    @set_ev_cls(event.EventSwitchLeave, MAIN_DISPATCHER)
    def switch_leave_handler(self, ev):
        print (ev)
        switch = ev.switch.dp.id
        if switch in self.switches:
            self.switches.remove(switch)
            del self.datapath_list[switch]
            del self.adjacency[switch]

    @set_ev_cls(event.EventLinkAdd, MAIN_DISPATCHER)
    def link_add_handler(self, ev):
        s1 = ev.link.src
        s2 = ev.link.dst
        self.adjacency[s1.dpid][s2.dpid] = s1.port_no
        self.adjacency[s2.dpid][s1.dpid] = s2.port_no

    @set_ev_cls(event.EventLinkDelete, MAIN_DISPATCHER)
    def link_delete_handler(self, ev):
        s1 = ev.link.src
        s2 = ev.link.dst
        # Exception handling if switch already deleted
        try:
            del self.adjacency[s1.dpid][s2.dpid]
            del self.adjacency[s2.dpid][s1.dpid]
        except KeyError:
            pass