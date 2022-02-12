import socket

client = socket.socket()
client.connect(('127.0.0.1', 6111))
client.send(b'Trees#1,10-10,6-1,2;7,5-7,4-7,8-5,3-3,9')
client.close()
