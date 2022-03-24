import socket

client = socket.socket()
client.connect(('127.0.0.1', 6111))
client.send(b'Paths:1,2,5;1,2,3,5')
client.close()
