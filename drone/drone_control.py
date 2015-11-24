import time
import thread
import threading
import cv2

from api import libardrone

class DroneController ( object ):
  def __init__(self, debug=False):
    self.debug = debug
    self.drone = libardrone.ARDrone()
    self.drone_lock = threading.Lock()

    self.mission_picture = self.cam = None
    self.cam_lock = threading.RLock()

    self.is_running = True
    self.grabber_thread = threading.Thread(target=self.__grab_frames)
    self.grabber_thread.start()

  def shutdown(self):
    if self.drone != None:
      self.drone_lock.acquire()
      self.drone.land()
      self.drone.halt()
      self.drone = None
      self.drone_lock.release()

    if self.cam != None:
      self.cam.release()
      self.cam = None

    self.is_running = False
    self.grabber_thread.join()

    cv2.destroyAllWindows()

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

  def __init_cam(self):
    self.cam_lock.acquire()
    try:
      if self.cam != None:
        if self.cam.isOpened():
          return True
        else:
          self.cam.release()
          self.cam = None

      self.cam = cv2.VideoCapture('tcp://192.168.1.1:5555')
      if not self.cam.isOpened() and self.debug:
        self.cam.release()
        self.cam = cv2.VideoCapture(0)  # from webcam
      if not self.cam.isOpened():
        self.cam.release()
        self.cam = None
        return False
      return True
    finally:
      self.cam_lock.release()

  def __grab_frames(self, fps=25):
    start_time = time.time()
    grab_count = 0
    while self.is_running:
      time.sleep(1)
      target_grabs = (time.time() - start_time) * fps
      if not self.cam or not self.cam.isOpened():
        grab_count = target_grabs
        continue

      self.cam_lock.acquire()
      try:
        while grab_count < target_grabs:
          grab_count += 1
          self.cam.grab()
      finally:
        self.cam_lock.release()

  def take_picture(self, max_retries=5):
    self.cam_lock.acquire()
    try:
      try_count = 0
      while try_count <= max_retries and self.__init_cam():
        try_count += 1
        running, frame = self.cam.read()
        if not running:
          self.cam.release()
          continue  # retry

        s, img = cv2.imencode('.jpg', frame)
        if s:
          if self.debug: print 'Picture taken from camera'
          return img.tostring()
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
