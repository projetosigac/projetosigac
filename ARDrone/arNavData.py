#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
decode a navdata packet.
parts of code from Bastian Venthur, Jean-Baptiste Passot, Florian Lacrampe.
"""

# < imports >--------------------------------------------------------------------------------------

import logging
import struct

# < variáveis globais >----------------------------------------------------------------------------

# logging level
w_logLvl = logging.ERROR

# -------------------------------------------------------------------------------------------------
# decode_navdata
# -------------------------------------------------------------------------------------------------
def decode_navdata ( fo_packet ):

    """
    decode a navdata packet.
    """

    # sherlock logger
    # l_log = logging.getLogger ( "decode_navdata" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    li_offset = 0

    _ = struct.unpack_from ( "IIII", fo_packet, li_offset )

    ld_drone_state = {}

    ld_drone_state [ "fly_mask" ]            = _ [ 1 ]       & 1  # FLY MASK : (0) ardrone is landed, (1) ardrone is flying
    ld_drone_state [ "video_mask" ]          = _ [ 1 ] >>  1 & 1  # VIDEO MASK : (0) video disable, (1) video enable
    ld_drone_state [ "vision_mask" ]         = _ [ 1 ] >>  2 & 1  # VISION MASK : (0) vision disable, (1) vision enable
    ld_drone_state [ "control_mask" ]        = _ [ 1 ] >>  3 & 1  # CONTROL ALGO (0) euler angles control, (1) angular speed control
    ld_drone_state [ "altitude_mask" ]       = _ [ 1 ] >>  4 & 1  # ALTITUDE CONTROL ALGO : (0) altitude control inactive (1) altitude control active
    ld_drone_state [ "user_feedback_start" ] = _ [ 1 ] >>  5 & 1  # USER feedback : Start button state
    ld_drone_state [ "command_mask" ]        = _ [ 1 ] >>  6 & 1  # Control command ACK : (0) None, (1) one received
    ld_drone_state [ "fw_file_mask" ]        = _ [ 1 ] >>  7 & 1  # Firmware file is good (1)
    ld_drone_state [ "fw_ver_mask" ]         = _ [ 1 ] >>  8 & 1  # Firmware update is newer (1)
    ld_drone_state [ "fw_upd_mask" ]         = _ [ 1 ] >>  9 & 1  # Firmware update is ongoing (1)
    ld_drone_state [ "navdata_demo_mask" ]   = _ [ 1 ] >> 10 & 1  # Navdata demo : (0) All navdata, (1) only navdata demo
    ld_drone_state [ "navdata_bootstrap" ]   = _ [ 1 ] >> 11 & 1  # Navdata bootstrap : (0) options sent in all or demo mode, (1) no navdata options sent
    ld_drone_state [ "motors_mask" ]         = _ [ 1 ] >> 12 & 1  # Motor status : (0) Ok, (1) Motors problem
    ld_drone_state [ "com_lost_mask" ]       = _ [ 1 ] >> 13 & 1  # Communication lost : (1) com problem, (0) Com is ok
    ld_drone_state [ "vbat_low" ]            = _ [ 1 ] >> 15 & 1  # VBat low : (1) too low, (0) Ok
    ld_drone_state [ "user_el" ]             = _ [ 1 ] >> 16 & 1  # User Emergency Landing : (1) User EL is ON, (0) User EL is OFF
    ld_drone_state [ "timer_elapsed" ]       = _ [ 1 ] >> 17 & 1  # Timer elapsed : (1) elapsed, (0) not elapsed
    ld_drone_state [ "angles_out_of_range" ] = _ [ 1 ] >> 19 & 1  # Angles : (0) Ok, (1) out of range
    ld_drone_state [ "ultrasound_mask" ]     = _ [ 1 ] >> 21 & 1  # Ultrasonic sensor : (0) Ok, (1) deaf
    ld_drone_state [ "cutout_mask" ]         = _ [ 1 ] >> 22 & 1  # Cutout system detection : (0) Not detected, (1) detected
    ld_drone_state [ "pic_version_mask" ]    = _ [ 1 ] >> 23 & 1  # PIC Version number OK : (0) a bad version number, (1) version number is OK
    ld_drone_state [ "atcodec_thread_on" ]   = _ [ 1 ] >> 24 & 1  # ATCodec thread ON : (0) thread OFF (1) thread ON
    ld_drone_state [ "navdata_thread_on" ]   = _ [ 1 ] >> 25 & 1  # Navdata thread ON : (0) thread OFF (1) thread ON
    ld_drone_state [ "video_thread_on" ]     = _ [ 1 ] >> 26 & 1  # Video thread ON : (0) thread OFF (1) thread ON
    ld_drone_state [ "acq_thread_on" ]       = _ [ 1 ] >> 27 & 1  # Acquisition thread ON : (0) thread OFF (1) thread ON
    ld_drone_state [ "ctrl_watchdog_mask" ]  = _ [ 1 ] >> 28 & 1  # CTRL watchdog : (1) delay in control execution (> 5ms), (0) control is well scheduled
    ld_drone_state [ "adc_watchdog_mask" ]   = _ [ 1 ] >> 29 & 1  # ADC Watchdog : (1) delay in uart2 dsr (> 5ms), (0) uart2 is good
    ld_drone_state [ "com_watchdog_mask" ]   = _ [ 1 ] >> 30 & 1  # Communication Watchdog : (1) com problem, (0) Com is ok
    ld_drone_state [ "emergency_mask" ]      = _ [ 1 ] >> 31 & 1  # Emergency landing : (0) no emergency, (1) emergency

    ld_data = {}

    ld_data [ "drone_state" ] = ld_drone_state
    ld_data [ "header" ]      = _ [ 0 ]
    ld_data [ "seq_nr" ]      = _ [ 2 ]
    ld_data [ "vision_flag" ] = _ [ 3 ]

    # l_log.debug ( "ld_data: " + str ( ld_data ))

    li_offset += struct.calcsize ( "IIII" )

    lv_has_flying_information = False

    while ( True ):

        try:

            # unpack 2 short ints
            lus_id_nr, lus_size = struct.unpack_from ( "HH", fo_packet, li_offset )

            # calculate new offset
            li_offset += struct.calcsize ( "HH" )

        except struct.error:

            break

        l_values = []

        for li_i in xrange ( lus_size - struct.calcsize ( "HH" )):

            l_values.append ( struct.unpack_from ( "c", fo_packet, li_offset ) [ 0 ] )

            li_offset += struct.calcsize ( "c" )

        # navdata_tag_t in navdata-common.h
        if ( 0 == lus_id_nr ):

            lv_has_flying_information = True

            l_values = struct.unpack_from ( "IIfffIfffI", "".join ( l_values ))
            l_values = dict ( zip ( [ "ctrl_state", "battery", "theta", "phi", "psi", "altitude", "vx", "vy", "vz", "num_frames" ], l_values ))

            # convert the millidegrees into degrees and round to int, as they are not so precise anyways
            for li_i in "theta", "phi", "psi":

                l_values [ li_i ] = int ( l_values [ li_i ] / 1000 )
                #l_values [ li_i ] /= 1000

        ld_data [ lus_id_nr ] = l_values
        # l_log.debug ( "ld_data: " + str ( ld_data ))

    # sherlock logger
    # l_log.debug ( "<<" )

    return ld_data, lv_has_flying_information

# -------------------------------------------------------------------------------------------------
# the bootstrap process
# -------------------------------------------------------------------------------------------------
if ( "__main__" == __name__ ):

    pass

# < the end >-------------------------------------------------------------------------------------- #
    