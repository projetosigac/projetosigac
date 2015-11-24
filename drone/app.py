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
