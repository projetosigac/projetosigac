#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
python library for the AR.Drone 1.0 and 2.0.
parts of code from Bastian Venthur, Jean-Baptiste Passot, Florian Lacrampe.

tested with Python 2.7.3 and AR.Drone vanilla firmware 1.11.5.
"""

# < defines >--------------------------------------------------------------------------------------

# IP address
ARDRONE_IP_ADDRESS   = "192.168.1.1"

# ports
ARDRONE_NAVDATA_PORT = 5554
ARDRONE_VIDEO_PORT   = 5555
ARDRONE_COMMAND_PORT = 5556
ARDRONE_CONTROL_PORT = 5559

# LED constants
ARDRONE_LED_ANIMATION_BLINK_GREEN_RED              =  0
ARDRONE_LED_ANIMATION_BLINK_GREEN                  =  1
ARDRONE_LED_ANIMATION_BLINK_RED                    =  2
ARDRONE_LED_ANIMATION_BLINK_ORANGE                 =  3
ARDRONE_LED_ANIMATION_SNAKE_GREEN_RED              =  4
ARDRONE_LED_ANIMATION_FIRE                         =  5
ARDRONE_LED_ANIMATION_STANDARD                     =  6
ARDRONE_LED_ANIMATION_RED                          =  7
ARDRONE_LED_ANIMATION_GREEN                        =  8
ARDRONE_LED_ANIMATION_RED_SNAKE                    =  9
ARDRONE_LED_ANIMATION_BLANK                        = 10
ARDRONE_LED_ANIMATION_RIGHT_MISSILE                = 11
ARDRONE_LED_ANIMATION_LEFT_MISSILE                 = 12
ARDRONE_LED_ANIMATION_DOUBLE_MISSILE               = 13
ARDRONE_LED_ANIMATION_FRONT_LEFT_GREEN_OTHERS_RED  = 14
ARDRONE_LED_ANIMATION_FRONT_RIGHT_GREEN_OTHERS_RED = 15
ARDRONE_LED_ANIMATION_REAR_RIGHT_GREEN_OTHERS_RED  = 16
ARDRONE_LED_ANIMATION_REAR_LEFT_GREEN_OTHERS_RED   = 17
ARDRONE_LED_ANIMATION_LEFT_GREEN_RIGHT_RED         = 18
ARDRONE_LED_ANIMATION_LEFT_RED_RIGHT_GREEN         = 19
ARDRONE_LED_ANIMATION_BLINK_STANDARD               = 20

# animation constants
ARDRONE_ANIMATION_PHI_M30_DEG             =  0
ARDRONE_ANIMATION_PHI_30_DEG              =  1
ARDRONE_ANIMATION_THETA_M30_DEG           =  2
ARDRONE_ANIMATION_THETA_30_DEG            =  3
ARDRONE_ANIMATION_THETA_20DEG_YAW_200DEG  =  4
ARDRONE_ANIMATION_THETA_20DEG_YAW_M200DEG =  5
ARDRONE_ANIMATION_TURNAROUND              =  6
ARDRONE_ANIMATION_TURNAROUND_GODOWN       =  7
ARDRONE_ANIMATION_YAW_SHAKE               =  8
ARDRONE_ANIMATION_YAW_DANCE               =  9
ARDRONE_ANIMATION_PHI_DANCE               = 10
ARDRONE_ANIMATION_THETA_DANCE             = 11
ARDRONE_ANIMATION_VZ_DANCE                = 12
ARDRONE_ANIMATION_WAVE                    = 13
ARDRONE_ANIMATION_PHI_THETA_MIXED         = 14
ARDRONE_ANIMATION_DOUBLE_PHI_THETA_MIXED  = 15
ARDRONE_NB_ANIMATION_MAYDAY               = 16

# video channel
ZAP_CHANNEL_HORI                  = 0    # Broadcast video from the front camera
ZAP_CHANNEL_VERT                  = 1    # Broadcast video from the belly camera, showing the ground
ZAP_CHANNEL_LARGE_VERT_SMALL_HORI = 2    # Broadcast video from the belly camera, with the front camera picture encrusted in the top-left corner
ZAP_CHANNEL_LARGE_HORI_SMALL_VERT = 3    # Broadcast video from the front camera, with the belly camera encrusted in the top-left corner
ZAP_CHANNEL_NEXT                  = 4    # Switch to the next possible camera combination

# id
SESSION_ID = "19260423"
USER_ID    = "19610901"
APP_ID     = "19700212"

# possible value for video codec (2.0):
NULL_CODEC               = 0
UVLC_CODEC               = 0x20    # codec_type value is used for START_CODE
P264_CODEC               = 0x40
MP4_360P_CODEC           = 0x80
H264_360P_CODEC          = 0x81
MP4_360P_H264_720P_CODEC = 0x82
H264_720P_CODEC          = 0x83
MP4_360P_SLRS_CODEC      = 0x84
H264_360P_SLRS_CODEC     = 0x85
H264_720P_SLRS_CODEC     = 0x86
H264_AUTO_RESIZE_CODEC   = 0x87    # resolution is automatically adjusted according to bitrate
MP4_360P_H264_360P_CODEC = 0x88

# < the end >-------------------------------------------------------------------------------------- #
