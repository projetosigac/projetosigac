#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Inter Process Communication Thread.
parts of code from Bastian Venthur, Jean-Baptiste Passot, Florian Lacrampe.
"""

# < imports >--------------------------------------------------------------------------------------

import logging
import select
import threading

# < variáveis globais >----------------------------------------------------------------------------

# logging level
w_logLvl = logging.ERROR

# < class IPCThread >------------------------------------------------------------------------------

class IPCThread ( threading.Thread ):

    """
    Inter Process Communication Thread.
 
    collects the data from the ARDroneNetworkProcess and forwards it to the ARDrone.
    """

    # ---------------------------------------------------------------------------------------------
    # IPCThread::__init__
    # ---------------------------------------------------------------------------------------------
    def __init__ ( self, fo_drone ):

        # sherlock logger
        # l_log = logging.getLogger ( "__init__" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # validate inputs
        # assert ( fo_drone )

        # init super class 
        super ( IPCThread, self ).__init__ ()

        self._drone = fo_drone
        self._stopping = False

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # IPCThread::run
    # ---------------------------------------------------------------------------------------------
    def run ( self ):

        # sherlock logger
        # l_log = logging.getLogger ( "IPCThread::run" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        while ( not self._stopping ):

            l_inputReady, l_outputReady, l_exceptReady = select.select ( [ self._drone.vid_pipe, self._drone.nav_pipe ], [], [], 1. )

            for lo_pipe in l_inputReady:

                # video pipe ?
                if ( self._drone.vid_pipe == lo_pipe ):

                    while ( self._drone.vid_pipe.poll ()):
                        lo_image = self._drone.vid_pipe.recv ()

                    self._drone.image = lo_image

                # navdata pipe ?
                elif ( self._drone.nav_pipe == lo_pipe ):

                    while ( self._drone.nav_pipe.poll ()):
                        lo_navdata = self._drone.nav_pipe.recv ()

                    # l_log.debug ( "navdata (A): " + str ( self._drone.navdata ))
                    self._drone.navdata = lo_navdata
                    # l_log.debug ( "navdata (D): " + str ( self._drone.navdata ))

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # IPCThread::stop
    # ---------------------------------------------------------------------------------------------
    def stop ( self ):

        """
        stop the IPCThread activity.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "IPCThread::stop" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( "><" )

        self._stopping = True

# -------------------------------------------------------------------------------------------------
# the bootstrap process
# -------------------------------------------------------------------------------------------------
if ( "__main__" == __name__ ):

    pass
        
# < the end >-------------------------------------------------------------------------------------- #
