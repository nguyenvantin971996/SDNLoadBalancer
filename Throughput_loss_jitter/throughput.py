import json
import matplotlib
import matplotlib.pyplot as plt
f2=open("receiver_multipath.json","w")
f2.truncate(0)
lines = []
with open('receiver_multipath.txt') as f1:
    for line in f1:
        lines.append(line)
f1.close
for line in lines[:-11]:
    f2.write(line)
f2.close()
f2=open("receiver_onepath.json","w")
f2.truncate(0)
lines = []
with open('receiver_onepath.txt') as f1:
    for line in f1:
        lines.append(line)
f1.close
for line in lines[:-11]:
    f2.write(line)
f2.close()
font = {'size'   : 14}
matplotlib.rc('font', **font)
width = 0.3
fig, axs = plt.subplots(2,figsize=(16,12))

sender_multipath = json.load(open('sender_multipath.json', 'r'))
sender_onepath = json.load(open('sender_onepath.json', 'r'))
yAxis_ = []
for intervals in sender_multipath["intervals"]:
    yAxis_.append(intervals["sum"]["bits_per_second"]/1000000)
yAxis_2_ = []
for intervals in sender_onepath["intervals"]:
    yAxis_2_.append(intervals["sum"]["bits_per_second"]/1000000)
avr_1_ = round(sum(yAxis_)/len(yAxis_),2)
avr_2_ = round(sum(yAxis_2_)/len(yAxis_2_),2)
axs[0].set_ylim(min(yAxis_)-0.5,max(yAxis_)+0.5)
axs[0].set_xlabel('Time in seconds')
axs[0].set_ylabel('Throughput of sender in Mbps')
axs[0].plot(yAxis_, label = "Multipath (Average = "+str(avr_1_)+" Mbps)", linewidth = '4', color='red', marker = 'o',ms = 12)
axs[0].plot(yAxis_2_, label = "Shortest Path (Average = "+str(avr_2_)+" Mbps)", linewidth = '4', color='springgreen', marker = 'o', linestyle = 'dashed',ms = 12)
axs[0].legend(loc="upper right")
axs[0].grid()

receiver_multipath = json.load(open('receiver_multipath.json', 'r'))
receiver_onepath = json.load(open('receiver_onepath.json', 'r'))
yAxis = []
for intervals in receiver_multipath["intervals"]:
    yAxis.append(intervals["sum"]["bits_per_second"]/1000000)
yAxis_2 = []
for intervals in receiver_onepath["intervals"]:
    yAxis_2.append(intervals["sum"]["bits_per_second"]/1000000)
avr_1 = round(sum(yAxis)/len(yAxis),2)
avr_2 = round(sum(yAxis_2)/len(yAxis_2),2)
axs[1].set_ylim(min(yAxis)-1,max(yAxis)+1)
axs[1].set_xlabel('Time in seconds')
axs[1].set_ylabel('Throughput of receiver in Mbps')
axs[1].plot(yAxis, label = "Multipath (Average = "+str(avr_1)+" Mbps)", linewidth = '4', color='red', marker = 'o',ms = 12)
axs[1].plot(yAxis_2, label = "Shortest Path (Average = "+str(avr_2)+" Mbps)", linewidth = '4', color='springgreen', marker = 'o',linestyle = 'dashed',ms = 12)
axs[1].legend(loc="upper right")
axs[1].grid()

num_packets = sender_multipath["end"]["sum"]["packets"]
_title = "Protocol: "+ receiver_multipath["start"]["test_start"]["protocol"]+", "
_title = _title + "num_streams: "+ str(receiver_multipath["start"]["test_start"]["num_streams"])+", "
_title = _title + "bytes: "+ str(receiver_multipath["start"]["test_start"]["bytes"]/(1024*1024))+" MBytes"
plt.suptitle(_title)
plt.savefig("compare_throughput_"+_title+".png",dpi=200)