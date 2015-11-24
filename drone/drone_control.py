import time
import thread
import threading
import cv2

from api import libardrone

class DroneController ( object ):
  def __init__(self):
    self.drone = libardrone.ARDrone()
    self.drone_lock = threading.Lock()
    self.mission_picture = self.cam = None
    self.cam_lock = threading.RLock()

  def __move_drone(self, forward, side):
    if forward != 0:
      if forward > 0:
        self.drone.move_forward()
      else:
        self.drone.move_backward()
      time.sleep(2 * abs(forward))
      self.drone.hover()

    if side != 0:
      if side > 0:
        self.drone.move_right()
      else:
        self.drone.move_left()
      time.sleep(2 * abs(side));
      self.drone.hover()

  def __drone_mission_sync(self, lat, lng):
    if not self.drone_lock.acquire(False):
      return

    try:
      forward = 0 if lat == 0 else 1 if lat > 0 else -1
      side = 0 if lng == 0 else 1 if lng > 0 else -1

      self.drone.takeoff()
      time.sleep(5)

      self.__move_drone(forward, side)
      self.mission_picture = self.take_picture()
      self.__move_drone(-forward, -side)

      self.drone.land()
      time.sleep(5)
    finally:
      self.drone_lock.release()

  def __init_cam(self, debug=False):
    self.cam_lock.acquire()
    try:
      if self.cam != None:
        if self.cam.isOpened():
          return True
        else:
          self.cam.release()
          self.cam = None

      self.cam = cv2.VideoCapture('tcp://192.168.1.1:5555')
      if not self.cam.isOpened() and debug:
        self.cam.release()
        self.cam = cv2.VideoCapture(0)  # from webcam
      if not self.cam.isOpened():
        self.cam.release()
        self.cam = None
        return False
      return True
    finally:
      self.cam_lock.release()

  def take_picture(self, max_retries=5, debug=False):
    self.cam_lock.acquire()
    try:
      try_count = 0
      while ++try_count <= max_retries and self.__init_cam(debug):
        running, frame = self.cam.read()
        if not running:
          self.cam.release()
          continue  # retry

        s, img = cv2.imencode('.jpg', frame)
        if s: return img.tostring()
      return None
    finally:
      self.cam_lock.release()

  def get_mission_picture(self):
    return self.mission_picture

  def start_drone_mission(self, lat, lng):
    if self.drone_busy():
      return False
    thread.start_new_thread(self.__drone_mission_sync, (lat, lng))
    return True

  def drone_busy(self):
    if not self.drone_lock.acquire(False):
      return True
    self.drone_lock.release()
    return False
