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
	s6 = net.addSwitch('s6')
	s7 = net.addSwitch('s7')
	s8 = net.addSwitch('s8')
	s9 = net.addSwitch('s9')
	s10 = net.addSwitch('s10')

	net.addLink(s1, h1, 1, 1, bw=1, delay='1ms', loss=0)
	net.addLink(s2, s1, 1, 2, bw=1, delay='50ms', loss=0)
	net.addLink(s3, s2, 1, 2, bw=1, delay='70ms', loss=0)
	net.addLink(s4, s3, 1, 2, bw=1, delay='60ms', loss=0)
	net.addLink(s8, s1, 1, 3, bw=1, delay='60ms', loss=0)
	net.addLink(s9, s8, 1, 2, bw=1, delay='20ms', loss=0)
	net.addLink(s10, s9, 1, 2, bw=1, delay='40ms', loss=0)
	net.addLink(s4, s10, 2, 2, bw=1, delay='80ms', loss=0)
	net.addLink(s8, s2, 3, 3, bw=1, delay='50ms', loss=0)
	net.addLink(s9, s2, 3, 4, bw=1, delay='70ms', loss=0)
	net.addLink(s9, s3, 4, 3, bw=1, delay='90ms', loss=0)
	net.addLink(s10, s3, 3, 4, bw=1, delay='20ms', loss=0)
	net.addLink(s7, s3, 1, 5, bw=1, delay='50ms', loss=0)
	net.addLink(s4, s7, 3, 2, bw=1, delay='50ms', loss=0)
	net.addLink(s6, s7, 1, 3, bw=1, delay='20ms', loss=0)
	net.addLink(s2, s6, 5, 2, bw=1, delay='70ms', loss=0)
	net.addLink(s6, s3, 3, 6, bw=1, delay='90ms', loss=0)
	net.addLink(s1, s5, 4, 1, bw=1, delay='40ms', loss=0)
	net.addLink(s2, s5, 6, 2, bw=1, delay='30ms', loss=0)
	net.addLink(s6, s5, 4, 3, bw=1, delay='50ms', loss=0)
	net.addLink(h2, s4, 1, 4, bw=1, delay='1ms', loss=0)

	c0.start()
	s1.start([c0])
	s2.start([c0])
	s3.start([c0])
	s4.start([c0])
	s5.start([c0])
	s6.start([c0])
	s7.start([c0])
	s8.start([c0])
	s9.start([c0])
	s10.start([c0])
	net.build()

	
	CLI(net)
	net.stop()

if __name__ == '__main__':
	setLogLevel( 'info' )
	topology()

