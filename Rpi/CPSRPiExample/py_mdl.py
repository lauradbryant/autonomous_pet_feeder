'''
Python 'plant model' mockup example - runs on the laptop
Must be changed to use the correct IP address.
'''
import socket
import sys
import struct
import time
import random

SERVER = '192.168.137.1'    # IP address of THIS server
SERVER_PORT = 26000

serv_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = (SERVER,SERVER_PORT)
serv_sock.bind(server_address)
serv_sock.settimeout(2.0)

TARGET = '192.168.137.147'    # IP address of THAT client
TARGET_PORT = 25000
client_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
client_address = ('0.0.0.0',0)
client_sock.bind(client_address)

target = (TARGET,TARGET_PORT)
start = None 

while True:
    try:
        value = random.random()
        data = struct.pack('d',value)
        client_sock.sendto(data,target)
        print ('%f -> %s' % (value,str(target)), file=sys.stderr)
        # print ('waiting to receive',file=sys.stderr)
        data, client = serv_sock.recvfrom(4096)
        assert len(data) == 8
        value, = struct.unpack('d',data)
        print ('%s -> %f' % (str(client),value), file=sys.stderr)
    except Exception as e:
        print(e)
        continue
        