import zmq
import time
import sys
import base64
from base64 import decodestring
import numpy as np
import cv2 
port = "5500"


context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind("tcp://*:%s" % port)


while True:
    #  Wait for next request from client
    message = socket.recv()
    print ("Received request: ",  len(message))
    """
    with open("foo.png","wb") as f:
        f.write(decodestring(message))
        print(decodestring(message))
    """
    img = base64.b64decode(message)
    npimg = np.fromstring(img, dtype=np.uint8)
    source = cv2.imdecode(npimg, 1)
    cv2.imshow("Stream", source)
    if(cv2.waitKey(1) =='q'):
        break

    socket.send_string("World from %s" % port)