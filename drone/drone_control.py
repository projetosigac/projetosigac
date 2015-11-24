import time
import thread
import threading

from api import libardrone

class DroneController ( object ):
  def __init__(self):
    self.drone = libardrone.ARDrone()
    self.lock = threading.Lock()
    self.image = None

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
      # take picture, setting self.image
      self.__move_drone(-forward, -side)

      self.drone.land()
      time.sleep(5)
    finally:
      self.lock.release()

  def get_image(self):
    return self.image

  def start_drone_mission(self, lat, lng):
    thread.start_new_thread(self.__drone_mission_sync, (lat, lng))

  def drone_busy(self):
    if not self.lock.acquire(False):
      return True
    self.lock.release()
    return False
