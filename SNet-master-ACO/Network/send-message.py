import socket
import time

client = socket.socket()
client.connect(('127.0.0.1', 6111))
client.send(b'Message#Link s1-s6: 2 -> 6')
time.sleep(1)
client.send(b'Message#Route from h4 to h1: s1->s10->s7')
time.sleep(1)
client.send(b'Message#Pair transitions occured: 1')
time.sleep(3)
client.send(b'Message#Link s5-s4: 10 -> 14')
time.sleep(1)
client.send(b'Message#Route from h1 to h2: s7->s5->s3->s9')
time.sleep(1)
client.send(b'Message#Pair transitions occured: 0')
client.close()
