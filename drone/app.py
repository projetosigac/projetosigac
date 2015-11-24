from flask import *

from drone_control import DroneController

app = Flask(__name__)
controller = DroneController()

@app.route('/')
def home():
    return 'Raspberry pi server'

@app.route('/send')
def send():
    latitude = request.args.get('lat')
    longitude = request.args.get('lng')

    controller.start_drone_mission(latitude, longitude)

    return 'Drone sent to lat=%s long=%s' %(latitude, longitude)

@app.route('/busy')
def busy():
    return 'Yes' if controller.drone_busy() else 'No'

@app.route('/release')
def release():
    # TODO(andresnds): Release package

    return 'Drone released the package'

if __name__ == '__main__':
    app.run()
