#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
provides access to/from the data provided by the AR.Drone.
parts of code from Bastian Venthur, Jean-Baptiste Passot, Florian Lacrampe.
"""

# < imports >--------------------------------------------------------------------------------------

import logging
import multiprocessing
import select
import socket
import threading

import arDefs
import arNavData
import arVideo

# < variáveis globais >----------------------------------------------------------------------------

# logging level
w_logLvl = logging.ERROR

# < class ARDroneNetworkProcess >------------------------------------------------------------------

class ARDroneNetworkProcess ( multiprocessing.Process ):

    """
    ARDrone Network Process.

    collects data from the video and navdata port, converts the data and sends it to the IPCThread.
    """

    # ---------------------------------------------------------------------------------------------
    # ARDroneNetworkProcess::__init__
    # ---------------------------------------------------------------------------------------------
    def __init__ ( self, fo_nav_pipe, fo_vid_pipe, fo_com_pipe ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDroneNetworkProcess::__init__" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # init super class
        super ( ARDroneNetworkProcess, self ).__init__ ()

        self._nav_pipe = fo_nav_pipe
        self._vid_pipe = fo_vid_pipe
        self._com_pipe = fo_com_pipe

        # sherlock logger
        # l_log.debug ( "<<" )
                
    # ---------------------------------------------------------------------------------------------
    # ARDroneNetworkProcess::run
    # ---------------------------------------------------------------------------------------------
    def run ( self ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDroneNetworkProcess::run" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # create video socket
        l_vid_socket = socket.socket ( socket.AF_INET, socket.SOCK_DGRAM )
        # assert ( l_vid_socket )
        
        # config socket
        l_vid_socket.setblocking ( 0 )
        l_vid_socket.bind (( "", arDefs.ARDRONE_VIDEO_PORT ))
        l_vid_socket.sendto ( "\x01\x00\x00\x00", ( arDefs.ARDRONE_IP_ADDRESS, arDefs.ARDRONE_VIDEO_PORT ))

        # create navData socket
        l_nav_socket = socket.socket ( socket.AF_INET, socket.SOCK_DGRAM )
        # assert ( l_nav_socket )

        # config socket
        l_nav_socket.setblocking ( 0 )
        l_nav_socket.bind (( "", arDefs.ARDRONE_NAVDATA_PORT ))
        l_nav_socket.sendto ( "\x01\x00\x00\x00", ( arDefs.ARDRONE_IP_ADDRESS, arDefs.ARDRONE_NAVDATA_PORT ))

        lv_stopping = False

        while ( not lv_stopping ):

            l_inputReady, l_outputReady, l_exceptReady = select.select ( [ l_nav_socket, l_vid_socket, self._com_pipe ], [], [] )

            for lo_srce in l_inputReady:

                # video socket ? 
                if ( l_vid_socket == lo_srce ):

                    while ( True ):
                        try:
                            # receive video data
                            l_data = l_vid_socket.recv ( 65535 )

                        except IOError:
                            # we consumed every packet from the socket and continue with the last one
                            break

                    # decode video data
                    l_w, l_h, l_image, l_t = arVideo.read_picture ( l_data )

                    # send over pipe
                    self._vid_pipe.send ( l_image )

                # navdata socket ?
                elif ( l_nav_socket == lo_srce ):

                    while ( True ):
                        try:
                            # receive navdata
                            lo_data = l_nav_socket.recv ( 65535 )

                        except IOError:
                            # we consumed every packet from the socket and continue with the last one
                            break

                    # decode navdata
                    l_navdata, lv_has_information = arNavData.decode_navdata ( lo_data )
                    # l_log.debug ( "l_navdata: " + str ( l_navdata ))

                    #if ( lv_has_information ):
                        #self._drone.set_navdata ( l_navdata )
                   
                    # send over pipe
                    self._nav_pipe.send ( l_navdata )

                # command pipe ?
                elif ( self._com_pipe == lo_srce ):

                    # receive command
                    _ = self._com_pipe.recv ()

                    lv_stopping = True

                    break

        # close sockets
        l_vid_socket.close ()
        l_nav_socket.close ()

        # sherlock logger
        # l_log.debug ( "<<" )

# < class ARDroneNetworkProcess >------------------------------------------------------------------

class ARDrone2NetworkProcess ( threading.Thread ):

    """
    ARDrone Network Process.

    collects data from the video and navdata port, converts the data and sends it to the IPCThread.
    """

    # ---------------------------------------------------------------------------------------------
    # ARDrone2NetworkProcess::__init__
    # ---------------------------------------------------------------------------------------------
    def __init__ ( self, fo_com_pipe, fv_is_ar_drone_2, fo_drone ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone2NetworkProcess::__init__" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # init super class
        super ( ARDrone2NetworkProcess, self ).__init__ ()

        self._drone = fo_drone
        self._com_pipe = fo_com_pipe
        self.v_is_ar_drone_2 = fv_is_ar_drone_2
       
        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone2NetworkProcess::run
    # ---------------------------------------------------------------------------------------------
    def run ( self ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone2NetworkProcess::run" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # -----------------------------------------------------------------------------------------
        # ARDrone2NetworkProcess::run::_connect
        # -----------------------------------------------------------------------------------------
        def _connect ():

            # sherlock logger
            # l_log = logging.getLogger ( "ARDrone2NetworkProcess::run::_connect" )
            # l_log.setLevel ( w_logLvl )
            # l_log.debug ( ">>" )

            # l_log.warn ( "Connection to AR.Drone on way ..." )
            
            l_nav_socket = socket.socket ( socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP )
            l_nav_socket.setblocking ( 0 )
            l_nav_socket.bind (( "", arDefs.ARDRONE_NAVDATA_PORT ))
            l_nav_socket.sendto ( "\x01\x00\x00\x00", ( arDefs.ARDRONE_IP_ADDRESS, arDefs.ARDRONE_NAVDATA_PORT ))

            l_control_socket = socket.socket ( socket.AF_INET, socket.SOCK_STREAM )
            l_control_socket.connect (( arDefs.ARDRONE_IP_ADDRESS, arDefs.ARDRONE_CONTROL_PORT ))
            l_control_socket.setblocking ( 0 )

            # l_log.warn ( "Connection ok" )

            # sherlock logger
            # l_log.debug ( "<<" )

            return l_nav_socket, l_control_socket

        # -----------------------------------------------------------------------------------------
        # ARDrone2NetworkProcess::run::_disconnect
        # -----------------------------------------------------------------------------------------
        def _disconnect ( nav_socket, control_socket ):

            # sherlock logger
            # l_log = logging.getLogger ( "ARDrone2NetworkProcess::run::_disconnect" )
            # l_log.setLevel ( w_logLvl )
            # l_log.debug ( ">>" )

            # l_log.warn ( "Deconnection AR.Drone" )

            # close sockets
            nav_socket.close ()

            control_socket.close ()

            # sherlock logger
            # l_log.debug ( "<<" )

        # -----------------------------------------------------------------------------------------
        # run
        # -----------------------------------------------------------------------------------------
        l_nav_socket, l_control_socket = _connect ()

        lv_stopping = False
        li_connection_lost = 1
        lv_reconnection_needed = False

        while ( not lv_stopping ):

            if ( lv_reconnection_needed ):

                _disconnect ( l_nav_socket, l_control_socket )

                l_nav_socket, l_control_socket = _connect ()
                lv_reconnection_needed = False

            l_inputReady, l_outputReady, l_exceptReady = select.select ( [ l_nav_socket, self._com_pipe, l_control_socket ], [], [], 1. )

            if ( 0 == len ( l_inputReady )):

                li_connection_lost += 1
                lv_reconnection_needed = True

            for lo_srce in l_inputReady:

                if ( l_nav_socket == lo_srce ):

                    while ( True ):

                        try:
                            lo_data = l_nav_socket.recv ( 500 )

                        except IOError:
                            # we consumed every packet from the socket and continue with the last one
                            break

                    l_navdata, lv_has_information = arNavData.decode_navdata ( lo_data )

                    if ( lv_has_information ):
                        self._drone.set_navdata ( l_navdata )

                elif ( self._com_pipe == lo_srce ):

                    _ = self._com_pipe.recv ()

                    lv_stopping = True

                    break

                elif ( l_control_socket == lo_srce ):

                    lv_reconnection_needed = False

                    while ( not lv_reconnection_needed ):
                        try:
                            data = l_control_socket.recv ( 65536 )

                            if ( 0 == len ( data )):

                                # l_log.warning ( "Received an empty packet on control socket" )

                                lv_reconnection_needed = True

                            else:

                                # l_log.warning ( "Control Socket says : %s", data )
                                pass

                        except IOError:
                            break

        _disconnect ( l_nav_socket, l_control_socket )

        # sherlock logger
        # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# the bootstrap process
# -------------------------------------------------------------------------------------------------
if ( "__main__" == __name__ ):

    pass
    
# < the end >-------------------------------------------------------------------------------------- #
