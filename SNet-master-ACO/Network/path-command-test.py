import socket

client = socket.socket()
client.connect(('127.0.0.1', 6111))
client.send(b'Path:1,2,3')
client.close()
