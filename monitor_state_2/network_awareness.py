# Base:
from ryu.base import app_manager
from ryu.lib.packet import packet
from ryu.lib.packet import ethernet
from ryu.lib.packet import ipv4
from ryu.lib.packet import arp
from ryu.ofproto import ofproto_v1_3

# event:
from ryu.controller.handler import set_ev_cls
from ryu.topology import event
from ryu.controller import ofp_event
from ryu.controller.handler import CONFIG_DISPATCHER, MAIN_DISPATCHER, DEAD_DISPATCHER

# Topology
from ryu.controller.controller import Datapath
from ryu.topology.api import get_link, get_switch, get_host
from ryu.topology.switches import Switch, Link, Host, Port
from collections import defaultdict

from setting import DISCOVERY_PERIOD, MAX_CAPACITY

# Thread:
from ryu.lib import hub

# Graph:
import networkx as nx

class NetworkAwareness(app_manager.RyuApp):
    
    OFP_VERSIONS = [ofproto_v1_3.OFP_VERSION]
    
    def __init__(self, *_args, **_kwargs):
        super(NetworkAwareness, self).__init__(*_args, **_kwargs)
        self.name = "network_awareness"
        self.topology_api_app = self
        self.traffic = defaultdict(dict)
        
        # Threads
        # self.discover_thread = hub.spawn(self._discover_thread)
        
        # datapath:
        self.datapaths: dict[Datapath.id, Datapath] = {}  # Store switch in topology using OpenFlow
                
        # Link and switch
        self.switches = []
        self.access_table = {}       # {(sw,port) :(ip, mac)}
        self.switch_port_table = {}  # dpip->port_num
        self.access_ports = {}       # dpid->port_num
        self.interior_ports = {}     # {dpid: {port_num,...},...} - port_num is set of ports connected to other switches
        self.link_to_port = {}       # {(src.dpid, dst.dpid): (src.port_no, dst.port_no)}
        
        # Network Graph:
        self.graph = nx.DiGraph()
        
    def _discover_thread(self):
        while True:
            hub.sleep(DISCOVERY_PERIOD )
    
    def add_flow(self, dp, priority, match, actions, idle_timeout=0, hard_timeout=0):
        ofproto = dp.ofproto
        parser = dp.ofproto_parser
        inst = [parser.OFPInstructionActions(ofproto.OFPIT_APPLY_ACTIONS,
                                             actions)]
        mod = parser.OFPFlowMod(datapath=dp, priority=priority,
                                idle_timeout=idle_timeout,
                                hard_timeout=hard_timeout,
                                match=match, instructions=inst)
        dp.send_msg(mod)
    
    def _get_graph(self, link_list):
        """
            Get Adjacency matrix from link_to_port
        """
        for src in self.switches:
            for dst in self.switches:
                self.traffic[src][dst] = 0
                if src == dst:
                    self.graph.add_edge(src, dst, weight=0)
                    self.graph[src][dst]['port'] = None
                    self.graph[src][dst]['speed'] = None
                    self.graph[src][dst]['rw_bw'] = None
                elif (src, dst) in link_list.keys():
                    self.graph.add_edge(src, dst, weight=1)
                    self.graph[src][dst]['port'] = link_list[(src, dst)][0]
                    self.graph[src][dst]['speed'] = 0
                    self.graph[src][dst]['rm_bw'] = MAX_CAPACITY
        return self.graph
    
    def _create_port_map(self, switch_list):
        """
            Create interior_port table and access_port table.
        """
        for sw in switch_list:
            dpid = sw.dp.id
            self.switch_port_table.setdefault(dpid, set())
            self.interior_ports.setdefault(dpid, set())
            self.access_ports.setdefault(dpid, set())

            for p in sw.ports:
                self.switch_port_table[dpid].add(p.port_no)

    def _create_access_ports(self):
        """
            Get ports without link into access_ports
        """
        for sw in self.switch_port_table:
            all_port_table = self.switch_port_table[sw]
            interior_port = self.interior_ports[sw]
            self.access_ports[sw] = all_port_table - interior_port

    
    def _create_interior_links(self, link_list):
        """
            Get links source port to dst port from link_list,
            link_to_port:(src_dpid,dst_dpid)->(src_port,dst_port)
        """
        for link in link_list:
            src = link.src
            dst = link.dst
            self.link_to_port[(src.dpid, dst.dpid)] = (src.port_no, dst.port_no)

            # Find the access ports and interiorior ports
            if link.src.dpid in self.switches:
                self.interior_ports[link.src.dpid].add(link.src.port_no)
            if link.dst.dpid in self.switches:
                self.interior_ports[link.dst.dpid].add(link.dst.port_no)
    
    @set_ev_cls([event.EventSwitchEnter,
                 event.EventSwitchLeave, event.EventPortAdd,
                 event.EventPortDelete, event.EventPortModify,
                 event.EventLinkAdd, event.EventLinkDelete])        
    def _get_topology(self, ev):
        switch_list = get_switch(self.topology_api_app, None)
        self._create_port_map(switch_list)
        self.switches = self.switch_port_table.keys()
        links = get_link(self.topology_api_app, None)
        self._create_interior_links(links)
        self._create_access_ports()
        self._get_graph(self.link_to_port)

    @set_ev_cls(ofp_event.EventOFPStateChange,
                [MAIN_DISPATCHER, DEAD_DISPATCHER])
    def _state_change_handler(self, ev):
        datapath = ev.datapath
        if ev.state == MAIN_DISPATCHER:
            if datapath.id not in self.datapaths:
                self.logger.debug('register datapath: %016x', datapath.id)
                self.datapaths[datapath.id] = datapath
        elif ev.state == DEAD_DISPATCHER:
            if datapath.id in self.datapaths:
                self.logger.debug('unregister datapath: %016x', datapath.id)
                del self.datapaths[datapath.id]
    
    @set_ev_cls(ofp_event.EventOFPSwitchFeatures, CONFIG_DISPATCHER)
    def switch_features_handler(self, ev):
        """
            Install table-miss flow entry to datapaths.
        """       
        datapath = ev.msg.datapath
        # print("datapath features handler", datapath, datapath.id)
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser
        self.logger.info("switch:%s connected", datapath.id)


        # Install table-miss flow entry.
        match = parser.OFPMatch()
        actions = [parser.OFPActionOutput(ofproto.OFPP_CONTROLLER,
                                          ofproto.OFPCML_NO_BUFFER)]
        self.add_flow(datapath, 0, match, actions)
    
    @set_ev_cls(ofp_event.EventOFPPacketIn, MAIN_DISPATCHER)
    def _packet_in_handler(self, ev):
        """
            Handle the packet_in packet, and register the access info.
        """
        msg = ev.msg
        datapath = msg.datapath
        in_port = msg.match['in_port']
        pkt = packet.Packet(msg.data)
        eth_type = pkt.get_protocols(ethernet.ethernet)[0].ethertype #delay
        arp_pkt = pkt.get_protocol(arp.arp)
        ip_pkt = pkt.get_protocol(ipv4.ipv4)

        if arp_pkt:
            arp_src_ip = arp_pkt.src_ip
            arp_dst_ip = arp_pkt.dst_ip #delay
            mac = arp_pkt.src_mac
            # Record the access infomation.
            self.register_access_info(datapath.id, in_port, arp_src_ip, mac)

        elif ip_pkt:
            ip_src_ip = ip_pkt.src
            eth = pkt.get_protocols(ethernet.ethernet)[0]
            mac = eth.src
            # Record the access infomation.
            self.register_access_info(datapath.id, in_port, ip_src_ip, mac)
        # else:
        #     self.flood(msg)
        
    '''
        accessor api:
    '''
    def get_link_to_port(self, src_dpid, dst_dpid):
        if (src_dpid, dst_dpid) in self.link_to_port:
            return self.link_to_port[(src_dpid, dst_dpid)]
        else:
            self.logger.info("dpid:%s->dpid:%s is not in links" % (src_dpid, dst_dpid))
            return None
    
    def is_in_interior_ports(self, dpid, port_num):
        if port_num in self.interior_ports[dpid]: return True
        return False
    
    def get_interior_ports(self, dpid):
        if dpid in self.interior_ports:
            return self.interior_ports[dpid]
        else:
            self.logger.info("dpid:%s is not in interior_ports" % dpid)
            return None

    def get_topology_data(self):
        """_summary_
            Get topology data for the REST API
        Returns:
            A dict of topology data
            _type_: dict
        """
        hosts: list[Host] = get_host(self, None)
        switches: list[Switch] = get_switch(self, None)
        links: list[Link] = get_link(self, None)

        hosts_dict = [host.to_dict() for host in hosts]
        switches_dict = [switch.to_dict() for switch in switches]
        links_dict = [link.to_dict() for link in links]
        return hosts_dict, switches_dict, links_dict
    
    def get_link_quality(self):
        """_summary_
            Get link quality data for the REST API
        Returns:
            A dict of link graph data structure
        """
        link_quality = []
        for src, dst, value in self.graph.edges(data=True):
            if src != dst:
                
                # I wish i understood Lambda function
                if 'packet_loss' in value: packet_loss = value['packet_loss']
                else: packet_loss = None 
                
                if 'delay' in value: delay = value['delay']
                else: delay = None
                
                if 'link_usage' in value: link_usage = value['link_usage']
                else: link_usage = None
                
                if 'free_bandwith' in value: free_bandwith = value['free_bandwith']
                else: free_bandwith = None
                
                link_quality.append({
                    'src.dpid': src,
                    'dst.dpid': dst,
                    'delay': delay * 1000, # ms
                    'packet_loss': packet_loss,
                    'link_usage': link_usage,
                    'free_bandwidth': free_bandwith
                })
        return link_quality
        
    def register_access_info(self, dpid, in_port, ip, mac):
        """
            Register access host info into access table.
        """
        if in_port in self.access_ports[dpid]:
            if (dpid, in_port) in self.access_table:
                if self.access_table[(dpid, in_port)] == (ip, mac):
                    return
                else:
                    self.access_table[(dpid, in_port)] = (ip, mac)
                    return
            else:
                self.access_table.setdefault((dpid, in_port), None)
                self.access_table[(dpid, in_port)] = (ip, mac)
                return
    
    def get_host_location(self, host_ip):
        """
            Get host location info:(datapath, port) according to host ip.
        """
        for key in self.access_table.keys():
            if self.access_table[key][0] == host_ip:
                return key
        self.logger.info("%s location is not found." % host_ip)
        return None