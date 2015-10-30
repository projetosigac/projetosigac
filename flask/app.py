from flask import Flask
from flask import request
app = Flask(__name__)

@app.route('/')
def home():
    return 'Raspberry pi server'

@app.route('/send')
def send():
    latitude = request.args.get('lat')
    longitude = request.args.get('long')

    # TODO(andresnds): Send drone

    return 'Drone sent to lat=%s long=%s' %(latitude, longitude)

@app.route('/release')
def release():
    # TODO(andresnds): Release package

    return 'Drone released the package'

if __name__ == '__main__':
    app.run()
