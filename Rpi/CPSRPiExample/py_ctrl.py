'''
Python 'controller model' mockup example - runs on the RPi
Must be changed to use the correct IP address.
'''
import socket
import sys
import struct
import time

SERVER_HOST = '192.168.137.147'     # IP address of THIS server
SERVER_PORT = 25000

# HOST = 'localhost'
# PORT = 25000

TARGET = '192.168.137.1'            # IP address of THAT client
TARGET_PORT = 26000
target = (TARGET,TARGET_PORT)

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = (SERVER_HOST,SERVER_PORT)
sock.bind(server_address)

start = None 

while True:
    try:
        # print ('waiting to receive',file=sys.stderr)
        data, client = sock.recvfrom(4096)
        now = time.time()
        if not start: start = now
        assert len(data) == 8
        value, = struct.unpack('d',data)
        at = now - start
        print ('[%f]: %f @ %s' % (at,value,str(client)), file=sys.stderr)
        value *= -0.1
        print ('%f -> %s' % (value,str(target)), file=sys.stderr)
        data = struct.pack('d',value)
        sock.sendto(data,target) # client
        time.sleep(1.0)
    except Exception as e:
        print(e)
        sock.close()
        break
        