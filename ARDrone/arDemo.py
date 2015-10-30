#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
demo app for the AR.Drone.

this application allows to control the drone and see the drone's video stream.
"""

import socket
import libARDrone
import os, os.path
import time
import sys
import json
import pygame

SRV_ADDR = "/tmp/socket"

PRE_LAUNCH = 'PRE LAUNCH'
LAUNCHED = 'LAUNCHED'

scade_socket = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)

# -------------------------------------------------------------------------------------------------
# main
# -------------------------------------------------------------------------------------------------
def main():

    # Make sure the socket does not already exist
    try:
        os.unlink(SRV_ADDR)
    except OSError:
        if os.path.exists(SRV_ADDR):
            raise

    # Create a UDS socket
    scade_socket.bind(SRV_ADDR)

    # Listen for incoming connections
    scade_socket.listen(5)

    if 'DEBUG' not in locals() and 'DEBUG' not in globals():
        drone = libARDrone.ARDrone()
        drone.reset()

    drone_status = PRE_LAUNCH
    picture_retry = False
    picture_counter = 0
    rocket_launch = 0
    rocket_destroy = 0
    take_picture = 0
    download_pic = 0
    running = True
    # connection, client_address = scade_socket.accept()

    while running:
        try:
            connection, client_address = scade_socket.accept()
            # print >>sys.stderr, 'connection from', client_address
            data = connection.recv(128)
            # print >>sys.stderr, 'received "%s"' % data
            if data:
                data = json.loads(data)
                if 'RocketLaunch' in data.keys():
                    rocket_launch = data['RocketLaunch']
                    rocket_destroy = data['RocketDestroy']
                elif 'TakePicture' in data.keys():
                    take_picture = data['TakePicture']
                    download_pic = data['DownloadPic']

                if rocket_destroy and drone_status == LAUNCHED:
                    print '--- Rocket Destroyed ---'
                    running = False
                elif rocket_launch and drone_status == PRE_LAUNCH:
                    print '--- Lauching ARDrone ---'
                    if 'DEBUG' not in locals() and 'DEBUG' not in globals():
                        drone.takeoff()
                    drone_status = LAUNCHED
                elif picture_retry or take_picture:
                    try:
                        surface = pygame.image.fromstring(drone.image, {320, 240}, 'RGB')
                        pygame.image.save(surface, '/home/pi/drone_images/img/image.jpeg')
                        picture_retry = False
                        picture_counter += 1
                        print '--- Picture taken ---'
                    except:
                        print '.'
                        picture_retry = True

            else:
                print >>sys.stderr, 'no more data from', client_address
        except KeyboardInterrupt:
            print '--- Finishing application ---'
            running = False
        finally:
            # Clean up the connection
            connection.close()

        if 'DEBUG' not in locals() and 'DEBUG' not in globals():
            bat = drone.navdata.get( 0, dict ()).get( "battery", 0 )
            # print "bat: ", bat

    print "Shutting down...",

    if 'DEBUG' not in locals() and 'DEBUG' not in globals():
        drone.land()
        drone.halt()

    print "Ok."

# -------------------------------------------------------------------------------------------------
# the bootstrap process
# -------------------------------------------------------------------------------------------------
if ( "__main__" == __name__ ):

    main()

# < THE END >-------------------------------------------------------------------------------------- #
