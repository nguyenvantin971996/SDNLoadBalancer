# Using readlines()
file1 = open('wires.txt','r')
Lines = file1.readlines()

count = 0
# Strips the newline character
for line in Lines:
    if(line.strip()[0]=="="):
        count += 1
file1.close()
f1 = open("wires.txt","a")
if(count==3):
    f1.truncate(0)
for i in range(6):
    stt = ",".join(["tin", "bao", "quan"])
    stt= stt+"\n"
    f1.write(stt)
stt_0 = "=" + ",".join(["1", "6", "7"]) + "\n"
f1.write(stt_0)
f1.close()