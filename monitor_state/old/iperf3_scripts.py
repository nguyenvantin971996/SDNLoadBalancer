import sys
import re
import os
from sys import argv
import statistics
import pickle
P = 10
time_duration = 100
bw = 1
tm = [1,2,3,4,5,6,7]
for src in tm:
    fileClient = open("clients/client_{0}.sh".format(str(src)), 'w')
    outputstring_a1 = ''' #!/bin/bash \necho Generating traffic...\n'''
    fileClient.write(outputstring_a1)
    for dst in tm:
        if src!=dst:
            temp1 = ''
            temp1 += 'iperf -c '
            temp1 += '10.0.0.{0} '.format(str(dst))
            # temp1 += '-p {0}00{1} '.format(str(src),str(dst))
            temp1 += '-u -b '+str(format(bw))+'M'
            temp1 += ' -t '+str(time_duration)
            temp1 += ' -i 1 -P '+str(P)
            temp1 += ' &\n'
            fileClient.write(temp1)
    fileClient.close()
for dst in tm:
    fileServer = open("servers/server_{0}.sh".format(str(dst)), 'w') 
    # outputstring_a2 = ''' #!/bin/bash \necho Initializing server listening...\n'''
    # fileServer.write(outputstring_a2)
    for src in tm:
        if dst != src:
            temp2 = ''
            temp2 += 'iperf -s -u '
            # temp2 += '-p {0}00{1} '.format(str(src),str(dst))
            temp2 += '&\n'
            fileServer.write(temp2)
    fileServer.close() 