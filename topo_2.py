from mininet.net import Mininet
from mininet.node import Controller, RemoteController, OVSKernelSwitch
from mininet.cli import CLI
from mininet.log import setLogLevel, info
from mininet.link import TCLink
from functools import partial
from mininet.topo import Topo

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

		self.addLink(s2, s1, 1, 1, bw=1000, delay='10ms', loss=0)
		self.addLink(s3, s2, 1, 2, bw=1000, delay='30ms', loss=0)
		self.addLink(s7, s3, 1, 2, bw=1000, delay='20ms', loss=0)
		self.addLink(s5, s7, 1, 2, bw=1000, delay='30ms', loss=0)
		self.addLink(s4, s5, 1, 2, bw=1000, delay='20ms', loss=0)
		self.addLink(s1, s4, 2, 2, bw=1000, delay='40ms', loss=0)
		self.addLink(s2, s6, 3, 1, bw=1000, delay='70ms', loss=0)
		self.addLink(s3, s6, 3, 2, bw=1000, delay='80ms', loss=0)
		self.addLink(s5, s6, 3, 3, bw=1000, delay='90ms', loss=0)
		self.addLink(s4, s6, 3, 4, bw=1000, delay='60ms', loss=0)
		self.addLink(s1, h1, 3, 1, bw=1000, delay='1ms', loss=0)
		self.addLink(s2, h2, 4, 1, bw=1000, delay='1ms', loss=0)
		self.addLink(h3, s3, 1, 4, bw=1000, delay='1ms', loss=0)
		self.addLink(h7, s7, 1, 3, bw=1000, delay='1ms', loss=0)
		self.addLink(h6, s6, 1, 5, bw=1000, delay='1ms', loss=0)
		self.addLink(h5, s5, 1, 4, bw=1000, delay='1ms', loss=0)
		self.addLink(h4, s4, 1, 4, bw=1000, delay='1ms', loss=0)
def topology():
	topo = MyTopo()
	link = partial(TCLink)
	net = Mininet( topo=topo,controller=RemoteController, link=link)
	net.start()
	serverbw = net.iperf([net['h1'], net['h7']], l4Type='UDP', udpBw='10M',seconds=30 )
	info( serverbw, '\n' )
	CLI(net)
	net.stop()

if __name__ == '__main__':
	setLogLevel( 'info' )
	topology()

