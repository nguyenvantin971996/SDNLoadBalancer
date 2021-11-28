from mininet.net import Mininet
from mininet.node import Controller, RemoteController, OVSKernelSwitch
from mininet.cli import CLI
from mininet.log import setLogLevel
from mininet.link import TCLink

def topology():
	net = Mininet(controller=RemoteController, link=TCLink, switch=OVSKernelSwitch)

	c0 = net.addController('c0', controller=RemoteController, ip='127.0.0.1', port=6653)

	h1 = net.addHost('h1', mac='00:00:00:00:00:01', ip='10.0.0.1')
	h2 = net.addHost('h2', mac='00:00:00:00:00:02', ip='10.0.0.2')

	s1 = net.addSwitch('s1')
	s2 = net.addSwitch('s2')
	s3 = net.addSwitch('s3')
	s4 = net.addSwitch('s4')
	s5 = net.addSwitch('s5')

	net.addLink(s1, h1, 1, 1, bw=1, delay='1ms', loss=0)
	net.addLink(s2, s1, 1, 2, bw=40, delay='20ms', loss=0)
	net.addLink(s3, s1, 1, 3, bw=80, delay='60ms', loss=0)
	net.addLink(s4, s1, 1, 4, bw=90, delay='90ms', loss=0)
	net.addLink(s4, s2, 2, 2, bw=90, delay='90ms', loss=0)
	net.addLink(s5, s2, 1, 3, bw=20, delay='20ms', loss=0)
	net.addLink(s4, s3, 3, 2, bw=20, delay='80ms', loss=0)
	net.addLink(s5, s3, 2, 3, bw=50, delay='90ms', loss=0)
	net.addLink(s5, s4, 3, 4, bw=10, delay='60ms', loss=0)
	net.addLink(h2, s5, 1, 4, bw=1, delay='1ms', loss=0)

	c0.start()
	s1.start([c0])
	s2.start([c0])
	s3.start([c0])
	s4.start([c0])
	s5.start([c0])
	net.build()

	
	CLI(net)
	net.stop()

if __name__ == '__main__':
	setLogLevel( 'info' )
	topology()

