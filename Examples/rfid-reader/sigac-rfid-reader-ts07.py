#!/usr/bin/python
# -*- coding: utf8 -*-
import RPi.GPIO as GPIO
import MFRC522
import requests
import json
import signal
import subprocess
import sys
import time


if len(sys.argv) != 2:
    DISPATCHER = 'console'
else:
    DISPATCHER = sys.argv[1]
    if DISPATCHER not in ['web', 'console']:
        print 'Action "%s" not supported yet.' % DISPATCHER
        exit()

CONTINUE_READING = True
RFID_TAGS = set()

# Capture SIGINT for cleanup when the script is aborted
def end_read(signal,frame):
    global CONTINUE_READING
    print
    print "Ctrl + C captured. The script will terminate."
    CONTINUE_READING = False
    GPIO.cleanup()


def initialize():
    # Hook the SIGINT
    signal.signal(signal.SIGINT, end_read)

    print "SIGAC RFID reading module. "
    print

    modprobe = subprocess.call(['sudo', 'modprobe', 'spi-bcm2708'])
    if modprobe == 0:
        print 'Kernel module loaded!'
    else:
        print 'Error loading kernel module.'

    # Welcome message
    print
    print "To read a tag, scan it with the sensor."
    print "To stop reading, press Ctrl + C."
    print

initialize()

RFIDReader = MFRC522.MFRC522()

def blink(times):
    sleep_time = 0.15
    gpio_led_pin = 13
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(gpio_led_pin, GPIO.OUT)

    for x in xrange(times):
        GPIO.output(gpio_led_pin, True)
        time.sleep(sleep_time)
        GPIO.output(gpio_led_pin, False)
        time.sleep(sleep_time)

def send_tag_information(tag_uid):
    if DISPATCHER == 'console':
        print 'The tag value is: ', tag_uid
        blink(2)
    elif DISPATCHER == 'web':
        # URL = 'http://sigac.herokuapp.com/tag/'
	URL = 'http://192.168.0.102:1880/tag'
	try:
        	response = requests.post(URL, data=json.dumps({'tag': tag_uid}))
		if response.status_code == 200:
        	    	blink(1)
        	elif response.status_code >= 400:
            		blink(2)
       	 	else:
            		blink(3)
	except requests.exceptions.RequestException:
		blink(4)
		print 'Exception raised on request.'
    else:
        print 'Action not supported yet.'

def convert_uid_to_hex(uid):
    return ''.join(map(lambda x: str(hex(x))[2:], uid[0:4]))

# This loop keeps checking for chips.
while CONTINUE_READING:

    # Scan for cards.
    (status,TagType) = RFIDReader.MFRC522_Request(RFIDReader.PICC_REQIDL)

    if status == RFIDReader.MI_OK:
        print "Card detected. Reading..."

    # Get the UID of the card.
    (status,uid) = RFIDReader.MFRC522_Anticoll()

    # Convert the tag UID to hex and test if that tag has already been
    # saved.
    hex_uid = convert_uid_to_hex(uid)
    if hex_uid in RFID_TAGS:
        continue

    # RFID_TAGS.add(hex_uid)

    # If we have the UID, continue.
    if status == RFIDReader.MI_OK:
        # Handle the tag information.
        send_tag_information(hex_uid)
