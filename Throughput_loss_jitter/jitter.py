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
fig = plt.figure(figsize=(16,12))
receiver_multipath = json.load(open('receiver_multipath.json', 'r'))
receiver_onepath = json.load(open('receiver_onepath.json', 'r'))
yAxis = []
for intervals in receiver_multipath["intervals"]:
    yAxis.append(intervals["sum"]["jitter_ms"])
yAxis_2 = []
for intervals in receiver_onepath["intervals"]:
    yAxis_2.append(intervals["sum"]["jitter_ms"])
avr_1 = round(sum(yAxis)/len(yAxis),2)
avr_2 = round(sum(yAxis_2)/len(yAxis_2),2)
plt.ylim(0-max(yAxis_2)*0.1,max(yAxis_2)*1.2)
plt.xlabel('Time in seconds')
plt.ylabel('Jitter of receiver in ms')
plt.plot(yAxis, label = "Multipath (Jitter = "+str(avr_1)+" ms)", linewidth = '4', color='red', marker = 'o',ms = 12)
plt.plot(yAxis_2, label = "Shortest Path (Jitter = "+str(avr_2)+" ms)", linewidth = '4', color='springgreen', marker = 'o',linestyle = 'dashed',ms = 12)
plt.legend(loc="upper right")
plt.grid()
_title = "Protocol: "+ receiver_multipath["start"]["test_start"]["protocol"]+", "
_title = _title + "num_streams: "+ str(receiver_multipath["start"]["test_start"]["num_streams"])+", "
_title = _title + "bytes: "+ str(receiver_multipath["start"]["test_start"]["bytes"]/(1024*1024))+" MBytes"
plt.suptitle(_title)
plt.savefig("compare_jitter_"+_title+".png",dpi=200)