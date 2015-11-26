import time
import thread
import threading
import cv2

from api import libardrone
from drone_camera import DroneCamera

class DroneController ( object ):
  def __init__(self, debug=False):
    self.debug = debug
    self.drone = libardrone.ARDrone()
    self.drone_lock = threading.Lock()
    self.mission_picture = None
    self.cam = DroneCamera(debug)

  def shutdown(self):
    if self.drone != None:
      self.drone_lock.acquire()
      self.drone.land()
      self.drone.halt()
      self.drone = None
      self.drone_lock.release()
    self.cam.shutdown()

  def __move_drone(self, forward, side):
    if forward != 0:
      if forward > 0:
        self.drone.move_forward()
        if self.debug: print 'Drone moving forward'
      else:
        self.drone.move_backward()
        if self.debug: print 'Drone moving backward'
      time.sleep(5 * abs(forward))
      self.drone.hover()
      if self.debug: print 'Drone stopped'

    if side != 0:
      if side > 0:
        self.drone.move_right()
        if self.debug: print 'Drone moving right'
      else:
        self.drone.move_left()
        if self.debug: print 'Drone moving left'
      time.sleep(5 * abs(side));
      self.drone.hover()
      if self.debug: print 'Drone stopped'

  def __drone_mission_sync(self, lat, lng):
    if not self.drone_lock.acquire(False):
      return

    try:
      forward = 0 if lat == 0 else 1 if lat > 0 else -1
      side = 0 if lng == 0 else 1 if lng > 0 else -1

      self.drone.takeoff()
      if self.debug: print 'Drone taking off!'
      time.sleep(5)

      self.__move_drone(forward, side)
      self.mission_picture = self.take_picture()
      self.__move_drone(-forward, -side)

      self.drone.land()
      if self.debug: print 'Drone landing!'
      time.sleep(5)

      if self.debug: print 'Mission accomplished'
    finally:
      self.drone_lock.release()

  def take_picture(self, max_retries=5):
    return self.cam.snapshot()

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
