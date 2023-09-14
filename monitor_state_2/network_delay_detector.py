from __future__ import division
from ryu import cfg
from ryu.base import app_manager
from ryu.base.app_manager import lookup_service_brick
from ryu.controller import ofp_event
from ryu.controller.handler import MAIN_DISPATCHER, DEAD_DISPATCHER
from ryu.controller.handler import set_ev_cls
from ryu.ofproto import ofproto_v1_3
from ryu.lib import hub
from ryu.topology.switches import Switches
from ryu.topology.switches import LLDPPacket
from collections import defaultdict
import networkx as nx
import json
import time
import setting
import copy
from Al_GA import GA


CONF = cfg.CONF
N = 10
Max = 10
K_paths = 2
Pc = 0.9
Pm = 0.9
Ts = 2

class NetworkDelayDetector(app_manager.RyuApp):
    """
        NetworkDelayDetector is a Ryu app for collecting link delay.
    """

    OFP_VERSIONS = [ofproto_v1_3.OFP_VERSION]

    def __init__(self, *args, **kwargs):
        super(NetworkDelayDetector, self).__init__(*args, **kwargs)
        self.name = 'network_delay_detector'
        self.sending_echo_request_interval = 0.05
        # Get the active object of swicthes and awareness module.
        # So that this module can use their data.
        self.sw_module = lookup_service_brick('switches')
        self.awareness = lookup_service_brick('network_awareness')
        self.paths_dict = {}
        self.pw_dict = {}
        self.datapaths = {}
        self.echo_latency = {}
        self.measure_thread = hub.spawn(self._detector)

    @set_ev_cls(ofp_event.EventOFPStateChange,
                [MAIN_DISPATCHER, DEAD_DISPATCHER])
    def _state_change_handler(self, ev):
        datapath = ev.datapath
        if ev.state == MAIN_DISPATCHER:
            if not datapath.id in self.datapaths:
                self.logger.debug('Register datapath: %016x', datapath.id)
                self.datapaths[datapath.id] = datapath
        elif ev.state == DEAD_DISPATCHER:
            if datapath.id in self.datapaths:
                self.logger.debug('Unregister datapath: %016x', datapath.id)
                del self.datapaths[datapath.id]

    def _detector(self):
        """
            Delay detecting functon.
            Send echo request and calculate link delay periodically
        """
        while CONF.delay == 1:
            self._send_echo_request()
            self.create_link_delay()
            # self.show_delay_statis()
            # if len(self.paths_dict)==0:
            #     self.get_paths()
            # self.get_paths_2()
            hub.sleep(setting.DELAY_DETECTING_PERIOD)

    def _send_echo_request(self):
        """
            Seng echo request msg to datapath.
        """
        for datapath in self.datapaths.values():
            parser = datapath.ofproto_parser

            data_time = "%.12f" % time.time()
            byte_arr = bytearray(data_time.encode())

            echo_req = parser.OFPEchoRequest(datapath,
                                                data=byte_arr)
            datapath.send_msg(echo_req)
            # Important! Don't send echo request together, Because it will
            # generate a lot of echo reply almost in the same time.
            # which will generate a lot of delay of waiting in queue
            # when processing echo reply in echo_reply_handler.

            hub.sleep(self.sending_echo_request_interval)

    @set_ev_cls(ofp_event.EventOFPEchoReply, MAIN_DISPATCHER)
    def echo_reply_handler(self, ev):
        """
            Handle the echo reply msg, and get the latency of link.
        """
        now_timestamp = time.time()
        try:
            latency = now_timestamp - eval(ev.msg.data)
            self.echo_latency[ev.msg.datapath.id] = latency
        except:
            return

    def get_delay(self, src, dst):
        """
            Get link delay.
                        Controller
                        |        |
        src echo latency|        |dst echo latency
                        |        |
                   SwitchA-------SwitchB
                        
                    fwd_delay--->
                        <----reply_delay
            delay = (forward delay + reply delay - src datapath's echo latency
        """
        try:
            fwd_delay = self.awareness.graph[src][dst]['lldpdelay']
            re_delay = self.awareness.graph[dst][src]['lldpdelay']
            src_latency = self.echo_latency[src]
            dst_latency = self.echo_latency[dst]
            
            delay = (fwd_delay + re_delay - src_latency - dst_latency)/2
            return max(delay, 0)
        except:
            return float('inf')

    def _save_lldp_delay(self, src=0, dst=0, lldpdelay=0):
        try:
            self.awareness.graph[src][dst]['lldpdelay'] = lldpdelay
        except:
            if self.awareness is None:
                self.awareness = lookup_service_brick('network_awareness')
            return

    def create_link_delay(self):
        """
            Create link delay data, and save it into graph object.
        """
        try:
            for src in self.awareness.graph:
                for dst in self.awareness.graph[src]:
                    if src == dst:
                        self.awareness.graph[src][dst]['delay'] = 0
                        continue
                    delay = self.get_delay(src, dst)
                    self.awareness.graph[src][dst]['delay'] = delay
        except:
            if self.awareness is None:
                self.awareness = lookup_service_brick('network_awareness')
            return

    @set_ev_cls(ofp_event.EventOFPPacketIn, MAIN_DISPATCHER)
    def packet_in_handler(self, ev):
        """
            Parsing LLDP packet and get the delay of link.
        """
        msg = ev.msg
        try:
            src_dpid, src_port_no = LLDPPacket.lldp_parse(msg.data)
            dpid = msg.datapath.id
            if self.sw_module is None:
                self.sw_module = lookup_service_brick('switches')

            for port in self.sw_module.ports.keys():
                if src_dpid == port.dpid and src_port_no == port.port_no:
                    delay = self.sw_module.ports[port].delay
                    self._save_lldp_delay(src=src_dpid, dst=dpid,
                                          lldpdelay=delay)
        except LLDPPacket.LLDPUnknownFormat as e:
            return

    def show_delay_statis(self):
        if setting.TOSHOW and self.awareness is not None:
            self.logger.info("\nsrc   dst      delay")
            self.logger.info("---------------------------")
            for src in self.awareness.graph:
                for dst in self.awareness.graph[src]:
                    delay = self.awareness.graph[src][dst]['delay']
                    self.logger.info("%s<-->%s : %s" % (src, dst, delay))
    
    def get_paths(self):
        # self.paths_dict = {}
        # self.pw_dict = {}
        b = True
        for src in self.awareness.graph:
            for dst in self.awareness.graph[src]:
                delay = self.awareness.graph[src][dst]['delay']
                if(delay==float('inf')):
                    b = False
                    return
        if setting.WEIGHT=='delay' and b==True:
            for src in self.awareness.switches:
                for dst in self.awareness.switches:
                    if(src!=dst):
                        para = str([src,dst])
                        if(para not in self.paths_dict.keys()):
                            wmp = defaultdict(dict)
                            for src1 in self.awareness.graph:
                                for dst1 in self.awareness.graph[src1]:
                                    if src1 != dst1:
                                        t = round(self.awareness.graph[src1][dst1]['delay']*1000)
                                        wmp[src1][dst1] = t
                            self.paths_dict[para] = []
                            self.pw_dict[para] = []
                            alg = GA(wmp,self.awareness.switches,dst,src, N, Max, K_paths, Pc, Pm, Ts)
                            alg.Do()
                            print('\n',src,'<-->',dst)
                            for gen in alg.best:
                                self.paths_dict[para].append(gen.path)
                                self.pw_dict[para].append(gen.fitness)
                                print(gen.path,'=',gen.fitness)
                        para_2 = str([dst,src])
                        self.paths_dict[para_2] = []
                        for i in range(len(self.paths_dict[para])):
                            path = copy.deepcopy(self.paths_dict[para][i])
                            path.reverse()
                            self.paths_dict[para_2].append(path)
                        self.pw_dict[para_2] = copy.deepcopy(self.pw_dict[para])