 #!/bin/bash 
echo Generating traffic...
iperf -c 10.0.0.5 -u -b 1M -t 100 -i 1 -P 10 &
iperf -c 10.0.0.6 -u -b 1M -t 100 -i 1 -P 10 &
iperf -c 10.0.0.7 -u -b 1M -t 100 -i 1 -P 10 &
