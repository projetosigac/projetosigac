#!/usr/bin/env python
# -*- coding: utf8 -*-
import RPi.GPIO as GPIO
import MFRC522
import requests
import json
import signal


CONTINUE_READING = True


# Capture SIGINT for cleanup when the script is aborted.
def sigint_callback(signal, frame):
    global CONTINUE_READING
    print
    print "Ctrl + C captured. The script will terminate."
    CONTINUE_READING = False
    GPIO.cleanup()


def initialize():
    # Hook the SIGINT.
    signal.signal(signal.SIGINT, sigint_callback)

    # Welcome message.
    print "SIGAC RFID reading module. "
    print
    print "To read a tag, scan it with the sensor."
    print "To stop reading, press Ctrl + C."
    print


initialize()


RFIDReader = MFRC522.MFRC522()


def send_tag_information(tag_uid, dispatcher='console'):
    """ Send the tag information according to the dispatcher.

    TODO: Talk to TS07 to determine the format and how to send the information
    to them.
    """
    if dispatcher == 'console':
        print 'The tag value is: ', tag_uid
    elif dispatcher == 'web':
        URL = 'http://sigac.herokuapp.com/tag/'
        response = requests.post(URL, data=json.dumps({'tag': tag_uid}))
    else:
        print 'Action not supported yet.'


# This loop keeps checking for chips.
while CONTINUE_READING:

    # Scan for cards.
    (status,TagType) = RFIDReader.MFRC522_Request(RFIDReader.PICC_REQIDL)

    if status == RFIDReader.MI_OK:
        print "Card detected. Reading..."

    # Get the UID of the card.
    (status,uid) = RFIDReader.MFRC522_Anticoll()

    # If we have the UID, continue.
    if status == RFIDReader.MI_OK:
        # Handle the tag information.
        send_tag_information(uid[0:4])
