from time import sleep
from mininet.net import Mininet
from mininet.node import Controller, RemoteController, OVSKernelSwitch
from mininet.cli import CLI
from mininet.log import setLogLevel,info
from mininet.link import TCLink
from mininet.term import makeTerm
def topology():
	net = Mininet()

	c0 = net.addController('c0', controller=RemoteController, ip='127.0.0.1', port=6653)

	h1 = net.addHost('h1', mac='00:00:00:00:00:01', ip='10.0.0.1')
	h2 = net.addHost('h2', mac='00:00:00:00:00:02', ip='10.0.0.2')
	h3 = net.addHost('h3', mac='00:00:00:00:00:03', ip='10.0.0.3')
	h4 = net.addHost('h4', mac='00:00:00:00:00:04', ip='10.0.0.4')
	h5 = net.addHost('h5', mac='00:00:00:00:00:05', ip='10.0.0.5')
	h6 = net.addHost('h6', mac='00:00:00:00:00:06', ip='10.0.0.6')
	h7 = net.addHost('h7', mac='00:00:00:00:00:07', ip='10.0.0.7')

	s1 = net.addSwitch('s1')
	s2 = net.addSwitch('s2')
	s3 = net.addSwitch('s3')
	s4 = net.addSwitch('s4')
	s5 = net.addSwitch('s5')
	s6 = net.addSwitch('s6')
	s7 = net.addSwitch('s7')

	net.addLink(s2, s1, 1, 1, bw=1000, delay='10ms', loss=0)
	net.addLink(s3, s2, 1, 2, bw=1000, delay='30ms', loss=0)
	net.addLink(s7, s3, 1, 2, bw=1000, delay='20ms', loss=0)
	net.addLink(s5, s7, 1, 2, bw=1000, delay='30ms', loss=0)
	net.addLink(s4, s5, 1, 2, bw=1000, delay='20ms', loss=0)
	net.addLink(s1, s4, 2, 2, bw=1000, delay='40ms', loss=0)
	net.addLink(s2, s6, 3, 1, bw=1000, delay='70ms', loss=0)
	net.addLink(s3, s6, 3, 2, bw=1000, delay='80ms', loss=0)
	net.addLink(s5, s6, 3, 3, bw=1000, delay='90ms', loss=0)
	net.addLink(s4, s6, 3, 4, bw=1000, delay='60ms', loss=0)
	net.addLink(s1, h1, 3, 1, bw=1000, delay='1ms', loss=0)
	net.addLink(s2, h2, 4, 1, bw=1000, delay='1ms', loss=0)
	net.addLink(h3, s3, 1, 4, bw=1000, delay='1ms', loss=0)
	net.addLink(h7, s7, 1, 3, bw=1000, delay='1ms', loss=0)
	net.addLink(h6, s6, 1, 5, bw=1000, delay='1ms', loss=0)
	net.addLink(h5, s5, 1, 4, bw=1000, delay='1ms', loss=0)
	net.addLink(h4, s4, 1, 4, bw=1000, delay='1ms', loss=0)
	net.build()
	net.start()
	makeTerm(net['h7'],cmd='iperf -s -u')
	makeTerm(net['h5'],cmd='iperf -s -u')
	makeTerm(net['h1'],cmd='iperf -c 10.0.0.7 -u -t 10 -i 1')
	makeTerm(net['h2'],cmd='iperf -c 10.0.0.5 -u -t 10 -i 1')
	# serverbw = net.iperf( [net['h1'], net['h7']], l4Type='UDP', udpBw='10M',seconds=30 )
	# info( serverbw, '\n' )
	CLI(net)
	net.stop()

if __name__ == '__main__':
	setLogLevel( 'info' )
	topology()

