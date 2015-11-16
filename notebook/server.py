"""
A server to receive data through a POST endpoint, then to write it to a file that will be read by a Scade application.
Run this script next to the Scade executable, or change the filename path.

Current sensor types:
 - temperature
 - heart_beat
 - bpm
 
Run `pip install -r requirements.txt` to install dependencies.
"""
import sys
from flask import Flask, request

app = Flask(__name__)
filename = "values.data"

@app.route("/", methods=["POST"])
def handler():
    try:
        temperature = float(request.form["temperature"])
        heart_beat = float(request.form["heart_beat"])
        bpm = float(request.form["bpm"])

        with open(filename, "w") as f:
            f.write("%.1f %.1f %.1f" % (temperature, heart_beat, bpm))

        return "OK"
    except Exception as e:
        print e
        return "Bad Request", 400

@app.errorhandler(500)
def server_error(e):
    print e
    return "Internal Server Error", 500

if __name__ == "__main__":
    app.run()
