import threading
from drone_api import libardrone

class Drone(object):

  def __init__(self):
    self.drone = libardrone.ARDrone()
    self.lock = threading.Lock()


  def move_drone(self, lat, long):
    self.lock.acquire()

    self.drone.takeoff()
    time.sleep(3)

    self.drone.move_up()
    time.sleep(3)
    self.drone.move_right()
    time.sleep(4)
    self.drone.move_forward()
    time.sleep(2)

    self.drone.hover()
    time.sleep(5)

    self.drone.move_backward()
    time.sleep(2)
    self.drone.move_left()
    time.sleep(4)
    self.drone.land()

    self.lock.release()
