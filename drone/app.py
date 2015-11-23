from flask import Flask
from flask import request
import time
import threading

import autonomous

app = Flask(__name__)
drone = autonomous.Drone()

@app.route('/')
def home():
    return 'Raspberry pi server'

@app.route('/send')
def send():
    latitude = request.args.get('lat')
    longitude = request.args.get('long')

    t = threading.Thread(target=drone.move_drone,
                         args=[latitude, longitude])
    t.start()

    return 'Drone sent to lat=%s long=%s' %(latitude, longitude)

@app.route('/release')
def release():
    # TODO(andresnds): Release package

    return 'Drone released the package'

if __name__ == '__main__':
    app.run()
