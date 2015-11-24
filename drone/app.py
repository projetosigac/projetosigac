from flask import *

from util import *
from drone_control import DroneController

app = Flask(__name__)
controller = DroneController()

@app.route('/')
def home():
    return 'Raspberry pi server'

@app.route('/send')
def send():
    latitude = float_or(request.args.get('lat'), 0.0)
    longitude = float_or(request.args.get('lng'), 0.0)

    if controller.start_drone_mission(latitude, longitude):
        return 'Drone sent to lat=%s long=%s' %(latitude, longitude)
    else:
        return 'Drone busy! Try again later'

@app.route('/mission-photo')
def mission_pic():
    pic = controller.get_mission_picture()
    if not pic:
        return send_file('drone.jpg')
    return Response(pic, mimetype='image/jpeg')

@app.route('/live-photo')
def live_pic():
    pic = controller.take_picture(debug=app.debug)
    if not pic:
        return send_file('drone.jpg')
    return Response(pic, mimetype='image/jpeg')

@app.route('/busy')
def busy():
    return 'Yes' if controller.drone_busy() else 'No'

@app.route('/release')
def release():
    # TODO(andresnds): Release package

    return 'Drone released the package'

if __name__ == '__main__':
    app.run()
