from time import sleep
from mininet.net import Mininet
from mininet.node import Controller, RemoteController, OVSKernelSwitch
from mininet.cli import CLI
from mininet.log import setLogLevel, info
from mininet.link import TCLink
from functools import partial
from mininet.topo import Topo
from mininet.term import makeTerm
import random
from setting import MAX_CAPACITY
import numpy as np
import subprocess
import threading
class MyTopo(Topo):	
	def build(self, **param):

		h1 = self.addHost('h1', mac='00:00:00:00:00:01', ip='10.0.0.1')
		h2 = self.addHost('h2', mac='00:00:00:00:00:02', ip='10.0.0.2')
		h3 = self.addHost('h3', mac='00:00:00:00:00:03', ip='10.0.0.3')
		h4 = self.addHost('h4', mac='00:00:00:00:00:04', ip='10.0.0.4')
		h5 = self.addHost('h5', mac='00:00:00:00:00:05', ip='10.0.0.5')
		h6 = self.addHost('h6', mac='00:00:00:00:00:06', ip='10.0.0.6')
		h7 = self.addHost('h7', mac='00:00:00:00:00:07', ip='10.0.0.7')

		s1 = self.addSwitch('s1')
		s2 = self.addSwitch('s2')
		s3 = self.addSwitch('s3')
		s4 = self.addSwitch('s4')
		s5 = self.addSwitch('s5')
		s6 = self.addSwitch('s6')
		s7 = self.addSwitch('s7')

		self.addLink(s2, s1, 1, 1, bw=MAX_CAPACITY, delay='10ms', loss=0)
		self.addLink(s1, s3, 2, 1, bw=MAX_CAPACITY, delay='80ms', loss=0)
		self.addLink(s1, h1, 3, 1, bw=MAX_CAPACITY, delay='1ms', loss=0)
		self.addLink(s2, h2, 2, 1, bw=MAX_CAPACITY, delay='1ms', loss=0)
		self.addLink(s5, s2, 1, 3, bw=MAX_CAPACITY, delay='60ms', loss=0)
		self.addLink(s7, s5, 1, 2, bw=MAX_CAPACITY, delay='80ms', loss=0)
		self.addLink(s6, s7, 1, 2, bw=MAX_CAPACITY, delay='20ms', loss=0)
		self.addLink(s3, s6, 2, 2, bw=MAX_CAPACITY, delay='50ms', loss=0)
		self.addLink(s2, s4, 4, 1, bw=MAX_CAPACITY, delay='50ms', loss=0)
		self.addLink(s3, s4, 3, 2, bw=MAX_CAPACITY, delay='70ms', loss=0)
		self.addLink(s5, s4, 3, 3, bw=MAX_CAPACITY, delay='60ms', loss=0)
		self.addLink(s6, s4, 3, 4, bw=MAX_CAPACITY, delay='70ms', loss=0)
		self.addLink(h5, s5, 1, 4, bw=MAX_CAPACITY, delay='1ms', loss=0)
		self.addLink(h7, s7, 1, 3, bw=MAX_CAPACITY, delay='1ms', loss=0)
		self.addLink(h6, s6, 1, 4, bw=MAX_CAPACITY, delay='1ms', loss=0)
		self.addLink(h4, s4, 1, 5, bw=MAX_CAPACITY, delay='1ms', loss=0)
		self.addLink(h3, s3, 1, 4, bw=MAX_CAPACITY, delay='1ms', loss=0)

class TrafficThread(threading.Thread):
	def __init__(self, net, src_host, dst_host):
		threading.Thread.__init__(self)
		self.src_host = src_host
		self.dst_host = dst_host
		self.bandwidth = None
		self.net = net

	def run(self):
		src = self.net.getNodeByName(self.src_host)
		dst = self.net.getNodeByName(self.dst_host)
		# P = np.random.randint(low=5, high=10, size = 3)
		# b = np.random.randint(low=1, high=2, size = 3)
		P = 10
		b = 5
		cmd = 'iperf -c {} -u -t 100 -i 1 -b {}M -P {}'.format(dst.IP(),b, P)
		iperf_client = src.popen(cmd)

class topology(object):
	def __init__(self, *_args, **_kwargs):
		self.net = self.create_topo()

	def create_topo(self):
		topo = MyTopo()
		link = partial(TCLink)
		net = Mininet(topo=topo, controller=RemoteController(name='c1', ip='127.0.0.1', port=6653), link=link)
		net.start()
		sleep(5)
		return net
	
	def Do(self):
		src_hosts = ['h1']
		dst_hosts = ['h5']
		threads = []
		for src_host, dst_host in zip(src_hosts, dst_hosts):
			thread = TrafficThread(self.net, src_host, dst_host)
			thread.start()
			threads.append(thread)
		for thread in threads:
			thread.join()

if __name__ == '__main__':
	setLogLevel( 'info' )
	ob = topology()
	for i in range(1):
		ob.Do()
	CLI(ob.net)

