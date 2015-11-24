import time
import thread
import threading
import cv2

from api import libardrone

class DroneController ( object ):
  def __init__(self):
    self.drone = libardrone.ARDrone()
    self.lock = threading.Lock()
    self.mission_picture = self.cam = None

  def __move_drone(self, forward, side):
    if forward > 0:
      self.drone.move_forward()
    elif forward < 0:
      self.drone.move_backward()
    if forward != 0:
      time.sleep(2 * abs(forward))
      self.drone.hover()

    if side > 0:
      self.drone.move_right()
    elif side < 0:
      self.drone.move_left()
    if side != 0:
      time.sleep(2 * abs(side));
      self.drone.hover()

  def __drone_mission_sync(self, lat, lng):
    if not self.lock.acquire(False):
      return

    try:
      forward = 1 if lat > 0 else -1
      side = 1 if lng > 0 else -1

      self.drone.takeoff()
      time.sleep(5)

      self.__move_drone(forward, side)
      self.mission_picture = self.take_picture()
      self.__move_drone(-forward, -side)

      self.drone.land()
      time.sleep(5)
    finally:
      self.lock.release()

  def __init_cam(self, debug=False):
    if self.cam != None:
      if self.cam.isOpened():
        return True
      else:
        self.cam.release()
        self.cam = None

    self.cam = cv2.VideoCapture('tcp://192.168.1.1:5555')
    if not self.cam.isOpened() and debug:
      self.cam.release()
      self.cam = cv2.VideoCapture(0)
    if not self.cam.isOpened():
      self.cam.release()
      self.cam = None
      return False
    return True

  def take_picture(self, max_retries=5, debug=False):
    try_count = 0
    while ++try_count <= max_retries and self.__init_cam(debug):
      running, frame = self.cam.read()
      if not running:
        self.cam.release()
        continue  # retry

      s, img = cv2.imencode('.jpg', frame)
      if s: return img.tostring()
    return None

  def get_mission_picture(self):
    return self.mission_picture

  def start_drone_mission(self, lat, lng):
    thread.start_new_thread(self.__drone_mission_sync, (lat, lng))

  def drone_busy(self):
    if not self.lock.acquire(False):
      return True
    self.lock.release()
    return False
