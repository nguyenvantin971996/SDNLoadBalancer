from __future__ import division
from audioop import avg
import copy
from importlib.util import spec_from_file_location
from re import S
import numpy as np
from operator import attrgetter
from ryu import cfg
from ryu.base import app_manager
from ryu.controller import ofp_event
from ryu.controller.handler import MAIN_DISPATCHER, DEAD_DISPATCHER
from ryu.controller.handler import CONFIG_DISPATCHER
from ryu.controller.handler import set_ev_cls
from ryu.ofproto import ofproto_v1_3
from ryu.lib import hub
from ryu.lib.packet import packet
import networkx as nx
from ryu.base.app_manager import lookup_service_brick
import setting
import json
from ryu.lib.packet import arp
from collections import defaultdict

CONF = cfg.CONF

class NetworkMonitor(app_manager.RyuApp):
    OFP_VERSIONS = [ofproto_v1_3.OFP_VERSION]

    def __init__(self, *args, **kwargs):
        super(NetworkMonitor, self).__init__(*args, **kwargs)
        self.name = 'network_monitor'
        self.awareness = lookup_service_brick('network_awareness')
        self.datapaths = {}
        self.port_stats = {}
        self.flow_stats = {}
        self.flow_speed = {}
        self.port_features = {}
        self.monitor_thread = hub.spawn(self._monitor)
        self.ult = 0

    @set_ev_cls(ofp_event.EventOFPStateChange,
                [MAIN_DISPATCHER, DEAD_DISPATCHER])
    def _state_change_handler(self, ev):
        datapath = ev.datapath
        if ev.state == MAIN_DISPATCHER:
            if not datapath.id in self.datapaths:
                self.logger.debug('register datapath: %016x', datapath.id)
                self.datapaths[datapath.id] = datapath
        elif ev.state == DEAD_DISPATCHER:
            if datapath.id in self.datapaths:
                self.logger.debug('unregister datapath: %016x', datapath.id)
                del self.datapaths[datapath.id]
    
    def _monitor(self):
        """
            Main entry method of monitoring traffic.
        """
        while CONF.bw == 1:
            for dp in self.datapaths.values():
                self.port_features.setdefault(dp.id, {})
                self._request_stats(dp)
            self.show_ult()
            hub.sleep(setting.MONITOR_PERIOD)

    def _request_stats(self, datapath):
        """
            Sending request msg to datapath
        """
        self.logger.debug('send stats request: %016x', datapath.id)
        ofproto = datapath.ofproto
        parser = datapath.ofproto_parser

        req = parser.OFPPortDescStatsRequest(datapath, 0)
        datapath.send_msg(req)

        req = parser.OFPPortStatsRequest(datapath, 0, ofproto.OFPP_ANY)
        datapath.send_msg(req)

        # req = parser.OFPFlowStatsRequest(datapath)
        # datapath.send_msg(req)

    @set_ev_cls(ofp_event.EventOFPPortStatsReply, MAIN_DISPATCHER)
    def _port_stats_reply_handler(self, ev):
        body = ev.msg.body
        dpid = ev.msg.datapath.id
        src = dpid
        for stat in sorted(body, key=attrgetter('port_no')):
            port_no = stat.port_no
            if port_no != ofproto_v1_3.OFPP_LOCAL:
                key = (dpid, port_no)
                value = (stat.tx_bytes, stat.rx_bytes, stat.rx_errors,
                         stat.duration_sec, stat.duration_nsec)
                self._save_stats(self.port_stats, key, value, 5)
                pre = 0
                period = 0
                tmp = self.port_stats[key]
                if len(tmp) > 1:
                    # pre = tmp[-2][0] + tmp[-2][1]
                    pre = tmp[-2][0]
                    period = self._get_period(tmp[-1][3], tmp[-1][4],
                                              tmp[-2][3], tmp[-2][4])
                # now = self.port_stats[key][-1][0] + self.port_stats[key][-1][1]
                now = self.port_stats[key][-1][0]
                speed = self._get_speed(now, pre, period)
                speed = round(speed,2)
                for dst in self.awareness.graph[src].keys():
                    if self.awareness.graph[src][dst]['port']==port_no:
                        self.awareness.graph[src][dst]['speed'] = speed
                        break
                self._save_freebandwidth(dpid, port_no, speed)

    # @set_ev_cls(ofp_event.EventOFPFlowStatsReply, MAIN_DISPATCHER)
    # def _flow_stats_reply_handler(self, ev):
    #     body = ev.msg.body
    #     dpid = ev.msg.datapath.id
    #     self.flow_stats.setdefault(dpid, {})
    #     self.flow_speed.setdefault(dpid, {})
    #     for dst in self.awareness.traffic[dpid].keys():
    #         self.awareness.traffic[dpid][dst] = 0
    #     for stat in sorted([flow for flow in body if ('ipv4_dst' in flow.match and flow.priority==32768)],
    #                        key=lambda flow: (flow.match.get('in_port'),
    #                                          flow.match.get('ipv4_dst'))):
    #         for ks in self.awareness.access_table.keys():
    #             if self.awareness.access_table[ks][0] == stat.match['ipv4_src']:
    #                 src = ks[0]
    #             if self.awareness.access_table[ks][0] == stat.match['ipv4_dst']:
    #                 dst = ks[0]
    #         try:
    #             key = (src, dst, stat.instructions[0].actions[0].port, stat.match.get('in_port'))
    #         except:
    #             key = (src, dst, stat.instructions[0].actions[0].group_id, stat.match.get('in_port'))
    #         value = (stat.packet_count, stat.byte_count, stat.duration_sec, stat.duration_nsec)
    #         self._save_stats(self.flow_stats[dpid], key, value, 5)
    #         pre = 0
    #         period = 0
    #         tmp = self.flow_stats[dpid][key]
    #         if len(tmp) > 1:
    #             pre = tmp[-2][1]
    #             period = self._get_period(tmp[-1][2], tmp[-1][3],
    #                                     tmp[-2][2], tmp[-2][3])
    #         now = tmp[-1][1]
    #         speed = round(self._get_speed(now, pre, period),4)
    #         self.flow_speed[dpid][key] = speed
    #         if src==dpid:
    #             self.awareness.traffic[src][dst] = speed

    @set_ev_cls(ofp_event.EventOFPPortDescStatsReply, MAIN_DISPATCHER)
    def port_desc_stats_reply_handler(self, ev):
        msg = ev.msg
        dpid = msg.datapath.id
        ofproto = msg.datapath.ofproto

        config_dict = {ofproto.OFPPC_PORT_DOWN: "Down",
                       ofproto.OFPPC_NO_RECV: "No Recv",
                       ofproto.OFPPC_NO_FWD: "No Farward",
                       ofproto.OFPPC_NO_PACKET_IN: "No Packet-in"}

        state_dict = {ofproto.OFPPS_LINK_DOWN: "Down",
                      ofproto.OFPPS_BLOCKED: "Blocked",
                      ofproto.OFPPS_LIVE: "Live"}

        for p in ev.msg.body:

            if p.config in config_dict:
                config = config_dict[p.config]
            else:
                config = "up"

            if p.state in state_dict:
                state = state_dict[p.state]
            else:
                state = "up"

            port_feature = (config, state, p.curr_speed/10**3)
            self.port_features[dpid][p.port_no] = port_feature

    @set_ev_cls(ofp_event.EventOFPPortStatus, MAIN_DISPATCHER)
    def _port_status_handler(self, ev):
        msg = ev.msg
        reason = msg.reason
        port_no = msg.desc.port_no
        dpid = msg.datapath.id
        ofproto = msg.datapath.ofproto

        reason_dict = {ofproto.OFPPR_ADD: "added",
                       ofproto.OFPPR_DELETE: "deleted",
                       ofproto.OFPPR_MODIFY: "modified", }
    
    def _save_freebandwidth(self, dpid, port_no, speed):
        port_state = self.port_features.get(dpid).get(port_no)
        if port_state:
            capacity = port_state[2]/100
            curr_bw = self._get_free_bw(capacity, speed)
            for src in self.awareness.graph:
                for dst in self.awareness.graph[src]:
                    if src==dpid and self.awareness.graph[src][dst]['port']==port_no:
                        self.awareness.graph[src][dst]['rm_bw'] = curr_bw
        else:
            self.logger.info("Fail in getting port state")

    def _save_stats(self, _dict, key, value, length):
        if key not in _dict:
            _dict[key] = []
        _dict[key].append(value)

        if len(_dict[key]) > length:
            _dict[key].pop(0)

    def _get_speed(self, now, pre, period):
        if period:
            return 8*(now - pre) / (period*10**6)
        else:
            return 0

    def _get_free_bw(self, capacity, speed):
        return max(capacity - speed, 0)

    def _get_time(self, sec, nsec):
        return sec + nsec / (10 ** 9)

    def _get_period(self, n_sec, n_nsec, p_sec, p_nsec):
        return self._get_time(n_sec, n_nsec) - self._get_time(p_sec, p_nsec)

    def show_ult(self):
        if setting.TOSHOW is False:
            return
        spd = []
        d = {}
        d['state'] = []
        d['reward'] = 0
        for src1 in sorted(self.awareness.graph):
            for dst1 in sorted(self.awareness.graph[src1]):
                if src1 != dst1:
                    # print([src1, dst1],self.awareness.graph[src1][dst1]['port'],self.awareness.graph[src1][dst1]['speed'])
                    t = self.awareness.graph[src1][dst1]['speed']/setting.MAX_CAPACITY
                    t = round(t,4)
                    spd.append(t)
        if len(spd)!=0:
            self.ult = round(np.std(spd),3)
            if self.ult!=0:
                d['reward'] = round(1/self.ult,3)
        term = False
        if self.ult < 0.001:
            term = True
        d['terminal'] = term
        d['state'] = spd
        with open("rs.json", "w") as outfile:
            json.dump(d, outfile)
        outfile.close()
        print("Utilization = ", self.ult)
        # for i in sorted(self.flow_speed.items()):
        #     print(i)
        # print(self.awareness.traffic)