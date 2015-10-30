#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
python library for the AR.Drone 1.0 and 2.0.
parts of code from Bastian Venthur, Jean-Baptiste Passot, Florian Lacrampe.

low level AT commands.
"""

# < imports >--------------------------------------------------------------------------------------

import logging
import socket
import struct

import arDefs

# < variáveis globais >----------------------------------------------------------------------------

# logging level
w_logLvl = logging.ERROR

# -------------------------------------------------------------------------------------------------
# at
# -------------------------------------------------------------------------------------------------
def at ( fs_command, fi_seq, f_params ):

    """
    fs_command : the command (str).
    fi_seq     : the sequence number (int).
    f_params   : a list of elements which can be either int, float or string (lst).
    """

    # sherlock logger
    # l_log = logging.getLogger ( "at" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # init string
    ls_param_str = ""

    # scan item list
    for l_item in f_params:

        if ( type ( l_item ) == int ):
            ls_param_str += ",%d" % l_item

        elif ( type ( l_item ) == float ):
            ls_param_str += ",%d" % f2i ( l_item )

        elif ( type ( l_item ) == str ):
            ls_param_str += ',"' + l_item + '"'

    # build message
    ls_msg = "AT*%s=%i%s\r" % ( fs_command, fi_seq, ls_param_str )
    # l_log.debug ( ls_msg )

    # create socket
    l_sock = socket.socket ( socket.AF_INET, socket.SOCK_DGRAM )

    # send message
    l_sock.sendto ( ls_msg, ( arDefs.ARDRONE_IP_ADDRESS, arDefs.ARDRONE_COMMAND_PORT ))

    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# at_aflight
# -------------------------------------------------------------------------------------------------
def at_aflight ( fi_seq, fi_flag ):

    """
    makes the drone fly autonomously.

    @param  fi_seq  : sequence number (int).
    @param  fi_flag : 1: start flight, 0: stop flight (int).
    """

    # sherlock logger
    # l_log = logging.getLogger ( "at_aflight" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # send command
    at ( "AFLIGHT", fi_seq, [ fi_flag ] )

    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# at_anim
# -------------------------------------------------------------------------------------------------
def at_anim ( fi_seq, fi_anim, fi_secs ):

    """
    makes the drone execute a predetermined sequence of movements (animation).

    @param  fi_seq  : sequence number (int).
    @param  fi_anim : animation to play (int).
    @param  fi_secs : total duration in seconds of the animation (int).
    """

    # sherlock logger
    # l_log = logging.getLogger ( "at_anim" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # validate inputs
    # assert ( 8 >= fi_anim >= 0 )

    # send command
    at ( "ANIM", fi_seq, [ fi_anim, fi_secs ] )

    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# at_comwdg
# -------------------------------------------------------------------------------------------------
def at_comwdg ( fi_seq ):

    """
    reset communication watchdog.

    @param  fi_seq : sequence number (int).
    """

    # sherlock logger
    # l_log = logging.getLogger ( "at_comwdg" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # FIXME: no sequence number
    at ( "COMWDG", fi_seq, [] )

    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# at_config
# -------------------------------------------------------------------------------------------------
def at_config ( fi_seq, fs_option, fs_value ):

    """
    set configuration parameters of the drone.

    @param  fi_seq    : sequence number (int).
    @param  fs_option : the name of the option to set, between double quotes (byte with hex.value 22h).
    @param  fs_value  : the option value, between double quotes.
    """

    # sherlock logger
    # l_log = logging.getLogger ( "at_config" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # send command
    at ( "CONFIG", fi_seq, [ str ( fs_option ), str ( fs_value ) ] )

    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# at_config_ids
# -------------------------------------------------------------------------------------------------
def at_config_ids ( fi_seq, fs_session_id, fs_user_id, fs_application_id ):

    """
    identifiers for the next AT*CONFIG command.

    @param  fi_seq            : sequence number (int).
    @param  fs_session_id     : current session id (str).
    @param  fs_user_id        : current user id (str).
    @param  fs_application_id : current application id (str).
    """
    
    # sherlock logger
    # l_log = logging.getLogger ( "at_config_ids" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # send command
    at ( "CONFIG_IDS", fi_seq, [ fs_session_id, fs_user_id, fs_application_id ] )
            
    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# at_ctrl (??)
# -------------------------------------------------------------------------------------------------
def at_ctrl ( fi_seq, fi_num ):

    """
    ask the parrot to drop its configuration file.

    @param  fi_seq : sequence number (int).
    """

    # sherlock logger
    # l_log = logging.getLogger ( "at_ctrl" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # send command
    at ( "CTRL", fi_seq, [ fi_num, 0 ] )

    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# at_ftrim
# -------------------------------------------------------------------------------------------------
def at_ftrim ( fi_seq ):

    """
    tell the drone it's lying horizontally. Sets a reference of the horizontal plane for the drone
    internal control system.

    fi_seq : sequence number (int).
    """

    # sherlock logger
    # l_log = logging.getLogger ( "at_ftrim" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # send command
    at ( "FTRIM", fi_seq, [] )

    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# at_led
# -------------------------------------------------------------------------------------------------
def at_led ( fi_seq, fi_anim, ff_f, fi_secs ):

    """
    control the drones LED. Sets the drone control loop PID coefficients.

    @param  fi_seq  : sequence number (int).
    @param  fi_anim : animation to play (int).
    @param  ff_f    : frequence in HZ of the animation (float).
    @param  fi_secs : total duration in seconds of the animation (int).

    animation is played (duration × frequence) times.
    """

    # sherlock logger
    # l_log = logging.getLogger ( "at_led" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # validate inputs
    # assert ( 20 >= fi_anim >= 0 )

    # send command
    at ( "LED", fi_seq, [ fi_anim, float ( ff_f ), fi_secs ] )

    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# at_pcmd
# -------------------------------------------------------------------------------------------------
def at_pcmd ( fi_seq, fv_progressive, ff_lr, ff_fb, ff_vv, ff_va ):

    """
    makes the drone move (translate/rotate).

    fi_seq         : sequence number (int).
    fv_progressive : True: enable use of progressive commands, False: disable (i.e. enable hovering mode) (bool).
    ff_lr          : left-right tilt (roll):  [-1..1] negative: left      / positive: right (float).
    ff_rb          : front-back tilt (pitch): [-1..1] negative: forwards  / positive: backwards (float).
    ff_vv          : vertical speed (gaz):    [-1..1] negative: go down   / positive: rise (float).
    ff_va          : angular speed (yaw):     [-1..1] negative: spin left / positive: spin right (float).

    the left-right tilt (aka. "drone roll" or phi angle) argument is a percentage of the maximum
    inclination as configured here.  A negative value makes the drone tilt to its left, thus
    flying leftward.  A positive value makes the drone tilt to its right, thus flying rightward.

    the front-back tilt (aka. "drone pitch" or theta angle) argument is a percentage of the maximum
    inclination as configured here.  A negative value makes the drone lower its nose, thus flying
    frontward.  A positive value makes the drone raise its nose, thus flying backward.

    the drone translation speed in the horizontal plane depends on the environment and cannot be
    determined.  With roll or pitch values set to 0, the drone will stay horizontal but continue
    sliding in the air because of its inertia.  Only the air resistance will then make it stop.

    the vertical speed (aka. "gaz") argument is a percentage of the maximum vertical speed as
    defined here.  A positive value makes the drone rise in the air.  A negative value makes it
    go down.

    the angular speed argument is a percentage of the maximum angular speed as defined here.
    A positive value makes the drone spin right; a negative value makes it spin left.

    the above float values are a percentage of the maximum speed.
    """

    # sherlock logger
    # l_log = logging.getLogger ( "at_pcmd" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # validate inputs
    # assert ( 1. >= ff_lr >= -1. )
    # assert ( 1. >= ff_fb >= -1. )
    # assert ( 1. >= ff_vv >= -1. )
    # assert ( 1. >= ff_va >= -1. )

    # convert bool to int
    li_p = 1 if fv_progressive else 0

    # send command
    at ( "PCMD", fi_seq, [ li_p, float ( ff_lr ), float ( ff_fb ), float ( ff_vv ), float ( ff_va ) ] )

    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# at_pwm (??)
# -------------------------------------------------------------------------------------------------
def at_pwm ( fi_seq, f_m1, f_m2, f_m3, f_m4 ):

    """
    sends control values directly to the engines, overriding control loops.

    @param  fi_seq : sequence number (int).
    @param  f_m1   : front left command.
    @param  f_m2   : fright right command.
    @param  f_m3   : back right command.
    @param  f_m4   : back left command.
    """

    # sherlock logger
    # l_log = logging.getLogger ( "at_pwm" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( "><" )

    # FIXME: what type do mx have ?
    raise NotImplementedError ()

# -------------------------------------------------------------------------------------------------
# at_ref
# -------------------------------------------------------------------------------------------------
def at_ref ( fi_seq, fv_takeoff, fv_emergency=False ):

    """
    basic behaviour of the drone: take-off/landing, emergency stop/reset.

    @param  fi_seq       : sequence number (int).
    @param  fv_takeoff   : True: takeoff / False: Land (bool).
    @param  fv_emergency : True: turn off the engines (bool).
    """

    # sherlock logger
    # l_log = logging.getLogger ( "at_ref" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # bits 18, 20, 22, 24 and 28 should be set to 1
    li_p = 0b10001010101000000000000000000    # 0x11540000

    # take-off ?
    if ( fv_takeoff ):

        # takeoff/land (aka. "start bit")
        li_p += 0b1000000000    # 0x200

    # emergency ?
    if ( fv_emergency ):

        # emergency (aka. "select bit")
        li_p += 0b0100000000    # 0x100

    # send command
    at ( "REF", fi_seq, [ li_p ] )

    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# at_zap (??)
# -------------------------------------------------------------------------------------------------
def at_zap ( fi_seq, fi_stream ):

    """
    selects which video stream to send on the video UDP port.

    @param  fi_seq    : sequence number (int).
    @param  fi_stream : video stream to broadcast (int).

    ZAP_CHANNEL_HORI [0]                  : Broadcast video from the front camera
    ZAP_CHANNEL_LARGE_VERT_SMALL_HORI [1] : Broadcast video from the belly camera, with the front camera picture encrusted in the top-left corner
    ZAP_CHANNEL_VERT [2]                  : Broadcast video from the belly camera, showing the ground
    ZAP_CHANNEL_LARGE_HORI_SMALL_VERT [3] : Broadcast video from the front camera, with the belly camera encrusted in the top-left corner
    ZAP_CHANNEL_NEXT [4]                  : Switch to the next possible camera combination
    """

    # sherlock logger
    # l_log = logging.getLogger ( "at_zap" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # validate inputs
    # assert ( 4 >= fi_stream >= 0 )

    # FIXME: improve parameters to select the modes directly
    at ( "ZAP", fi_seq, [ fi_stream ] )

    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# f2i
# -------------------------------------------------------------------------------------------------
def f2i ( ff_f ):

    """
    interpret IEEE-754 floating-point value as signed integer.

    @param  ff_f : floating point value (float).
    """

    # sherlock logger
    # l_log = logging.getLogger ( "f2i" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( "><" )

    return struct.unpack ( "i", struct.pack ( "f", ff_f )) [ 0 ]

# -------------------------------------------------------------------------------------------------
# i2f
# -------------------------------------------------------------------------------------------------
def i2f ( fi_i ):
        
    """
    converts a IEEE-754 32bit signed int representation of a float back to a float.

    @param  fi_i : signed integer value (int).

    OBS: the reverse fails... maybe just normal float rounding issues ?
    >>> i2f ( -1085485875 ) --> -0.800000011920929, but should be -0.8
    """
    
    # sherlock logger
    # l_log = logging.getLogger ( "i2f" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( "><" )

    return struct.unpack ( "f", struct.pack ( "i", fi_i )) [ 0 ]

# -------------------------------------------------------------------------------------------------
# the bootstrap process
# -------------------------------------------------------------------------------------------------
if ( "__main__" == __name__ ):

    pass

# < the end >-------------------------------------------------------------------------------------- #
