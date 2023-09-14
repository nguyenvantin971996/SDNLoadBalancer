import socket

client = socket.socket()
client.connect(('127.0.0.1', 6111))
client.send(b'Islands#1,2,10,6;7,5,3,9,4,8')
client.close()
