import time
import threading
import cv2

class DroneCamera ( object ):
  def __init__(self, debug=False):
    self.debug = debug
    self.cam = None
    self.lock = threading.RLock()

    self.is_running = True
    self.grabber_thread = threading.Thread(target=self.__grab_frames)
    self.grabber_thread.start()

  def shutdown(self):
    self.lock.acquire()
    try:
      if self.cam != None:
        self.cam.release()
        self.cam = None
    finally:
      self.lock.release()

    self.is_running = False
    self.grabber_thread.join()

    cv2.destroyAllWindows()

  def __grab_frames(self, fps=25):
    start_time = time.time()
    grab_count = 0
    while self.is_running:
      time.sleep(1)
      target_grabs = (time.time() - start_time) * fps
      if not self.cam or not self.cam.isOpened():
        grab_count = target_grabs
        continue

      while grab_count < target_grabs:
        grab_count += 1
        self.lock.acquire()
        try:
          if self.cam and self.cam.isOpened():
            self.cam.grab()
        finally:
          self.lock.release()

  def __init_cam(self):
    self.lock.acquire()
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
      self.lock.release()

  def snapshot(self, max_retries=5):
    self.lock.acquire()
    try:
      try_count = 0
      while try_count < max_retries and self.__init_cam():
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
      self.lock.release()
