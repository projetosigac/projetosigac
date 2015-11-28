"""
Use this script to test server.py and the SensorsGraphs Scade application, if you don't have an Arduino.
"""

import httplib
import sys
import urllib
from math import cos, exp, pi, sin
from time import time

pi2   = 2 * pi

def send(n):
    conn = None
    headers = {"Content-type": "application/x-www-form-urlencoded", "Accept": "text/plain"}
    try:
        conn = httplib.HTTPConnection("127.0.0.1:5000")
        for idx in xrange(n):
            if idx % 100 == 0:
                print idx
            t = int(time() * 1000) # ms
            t1 = t % 1000

            bpm = 72 + 2 * sin(pi2 * t / 10000) + 0.3 * sin(pi2 * t / 120)
            params = urllib.urlencode({
                "temperature": 39 + 2 * sin(pi2 * t / 40000) + 0.3 * sin(pi2 * t / 120),
                "heart_beat": -10 * cos(pi2 * t1 / 30) * exp(-4.5 * t1 / 1000),
                "bpm": bpm,
            })
            conn.request("POST", "/", params, headers)
            conn.getresponse()
    finally:
        conn and conn.close()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print "Usage: send.py NUM"
    send(int(sys.argv[1]))