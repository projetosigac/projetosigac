"""
A server to receive data through a POST endpoint,
then to send it to the browser through a Server Side Event (SSE).

It will be used to show sensor data collected by the Arduino
in the browser running in the Raspberry Pi.

Current data types:
 - temperature
 - heartbeat

If you would like to test this server (without the Arduino),
you can run the following snippet:

import requests
from time import sleep, time

def send():
    for i in range(10):
        print requests.put(
            "http://localhost:5000/stream/temperature",
            data = {
                "time": int(time() * 1000),
                "value": 30 - i*(i - 9)/(4.5*4.5)*10 # This is a parabola looking down
            }
        )
        sleep(1.0)

send()

"""

import gevent

from gevent.pywsgi import WSGIServer
from gevent.queue import Queue
from gevent import monkey
monkey.patch_all()

import json
import time

from datetime import datetime
from flask import abort, Flask, json, Response, render_template, request
from math import cos, exp, pi, sin

app = Flask(__name__)

data = {
    "temperature": Queue(),
    "heartbeat": Queue(),
}

def event(sensor):
    """
    The Server Side Event (SSE) handler.
    It sends the data from the 'sensor' queue.
    """
    while True:
        yield "data: %s\n\n" % json.dumps(data[sensor].get())

@app.route("/")
def index():
    """
    Only html from this site.
    It shows the graphs for the sensors.
    """
    return render_template("index.html")

@app.route("/stream/<sensor>", methods=["GET", "PUT"])
def stream(sensor):
    """
    If GET, returns the SSE for the requested 'sensor'.

    If POST, puts new data {time, value} into the queue.
    """
    if sensor not in data.keys():
        return "Bad Request", 400
    if request.method == "GET":
        return Response(event(sensor), mimetype="text/event-stream")
    else:
        try:
            time = float(request.form["time"])
            value = float(request.form["value"])

            data[sensor].put({"time": time, "value": value})
            return "OK"
        except Exception as e:
            print e
            return "Bad Request", 400

@app.errorhandler(500)
def server_error(e):
    print e
    return "Internal Server Error", 500

if __name__ == "__main__":
    WSGIServer(('', 5000), app).serve_forever()

