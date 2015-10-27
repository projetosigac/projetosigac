#!/bin/env Python

""" Acts as a proxy between the arduino board and the web portal
 It listens for UDP packages at a given IP,Port, collect the data
 and from time to time uploads it to a given adress,route in a web
 server
"""

import time
import threading
import sys
from Queue import Queue
import socket
import urllib
import urllib2

LISTEN_IP   = "192.168.2.21"
LISTEN_PORT = 2000
UPLOAD_INTERVAL = 2 #seconds, float
UPLOAD_URL = "http://localhost:8000"

q = Queue()
run = threading.Event()
run.set()

def listener():
    '''Listener Thread function - listens to incoming UDP packages and
queues the information
See https://wiki.python.org/moin/UdpCommunication '''
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.bind((LISTEN_IP, LISTEN_PORT))
        sock.settimeout(1)
    except socket.error:
        print("Socket Error")
        raise
    while run.is_set():
        try:
            data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
            print "LISTENER:", data
            q.put(data)
        except socket.timeout:
            pass
            

def uploader():
    data_array = []
    while not q.empty():
        data_array.append(q.get())
    
    data = str({'data_array': data_array})
    req = urllib2.Request(UPLOAD_URL, data)
    response = urllib2.urlopen(req)
    response_body = response.read()

    with open('proxy_log.txt','a') as output_file:
        output_file.write(response_body)
    
    if run.is_set():
        threading.Timer(UPLOAD_INTERVAL,uploader).start()
    

if __name__ == "__main__":
    try:
        listener_thread = threading.Thread(target=listener)
        listener_thread.start()
        threading.Timer(UPLOAD_INTERVAL, uploader).start()
    except:
        print("Error in initialization, exiting")
        sys.exit(2)
    
    try:
        while True:
            pass
    except KeyboardInterrupt:
        print("Exiting by Keyboard Interrupt")
    
    run.clear()
    print("Waiting for listener thread to die...")
    listener_thread.join()
    print("Program exit")
