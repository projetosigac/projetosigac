#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
python library for the AR.Drone 1.0 (1.11.5) and 2.0 (2.2.9).
parts of code from Bastian Venthur, Jean-Baptiste Passot, Florian Lacrampe.

tested with Python 2.7.3 and AR.Drone vanilla firmware 1.11.5.
"""

# < imports >--------------------------------------------------------------------------------------

import logging
import multiprocessing
import sys
import threading
import time

import arATCmds
import arNetwork
import arIPCThread

# < variáveis globais >----------------------------------------------------------------------------

# logging level
w_logLvl = logging.ERROR

# < class ARDrone >--------------------------------------------------------------------------------

class ARDrone ( object ):

    """
    ARDrone class.

    instanciate this class to control AR.Drone and receive decoded video and navdata.
    """

    # ---------------------------------------------------------------------------------------------
    # ARDrone::__init__
    # ---------------------------------------------------------------------------------------------
    def __init__ ( self ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::__init__" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.seq_nr = 1
        self.timer_t = 0.2

        self.com_watchdog_timer = threading.Timer ( self.timer_t, self.commwdg )
        self.lock = threading.Lock ()

        self.speed = 0.2

        self.at ( arATCmds.at_config, "general:navdata_demo", "TRUE" )

        self.vid_pipe, vid_pipe_other = multiprocessing.Pipe ()
        self.nav_pipe, nav_pipe_other = multiprocessing.Pipe ()
        self.com_pipe, com_pipe_other = multiprocessing.Pipe ()

        self.network_process = arNetwork.ARDroneNetworkProcess ( nav_pipe_other, vid_pipe_other, com_pipe_other )
        self.network_process.start ()

        self.ipc_thread = arIPCThread.IPCThread ( self )
        self.ipc_thread.start ()

        self.image = None

        self.navdata = {}

        self.time = 0

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::apply_command
    # ---------------------------------------------------------------------------------------------
    def apply_command ( self, f_command ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::apply_command" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        las_available_commands = [ "emergency", "hover", "land",
                                   "move_backward", "move_down", "move_forward",
                                   "move_left", "move_right", "move_up",
                                   "takeoff", "turn_left", "turn_right", ]

        # validade command
        if ( f_command not in las_available_commands ):

            # sherlock logger
            # l_log.error ( "Command %s not recognized !" % f_command )

            # sherlock logger
            # l_log.debug ( "<< (E01)" )

            return

        if ( "hover" != f_command ):
            self.last_command_is_hovering = False

        if ( "emergency" == f_command ):
            self.reset ()

        elif (( "hover" == f_command ) and ( not self.last_command_is_hovering )):

            self.hover ()
            self.last_command_is_hovering = True

        elif ( "land" == f_command ):

            self.land ()
            self.last_command_is_hovering = True

        elif ( "move_backward" == f_command ):
            self.move_backward ()

        elif ( "move_forward" == f_command ):
            self.move_forward ()

        elif ( "move_down" == f_command ):
            self.move_down ()

        elif ( "move_up" == f_command ):
            self.move_up ()

        elif ( "move_left" == f_command ):
            self.move_left ()

        elif ( "move_right" == f_command ):
            self.move_right ()

        elif ( "takeoff" == f_command ):

            self.takeoff ()
            self.last_command_is_hovering = True

        elif ( "turn_left" == f_command ):
            self.turn_left ()

        elif ( "turn_right" == f_command ):
            self.turn_right ()

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::at
    # ---------------------------------------------------------------------------------------------
    def at ( self, f_cmd, *args, **kwargs ):

        """
        wrapper for the low level at commands.

        this method takes care that the sequence number is increased after each at command and the
        watchdog timer is started to make sure the drone receives a command at least every second.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::at" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.lock.acquire ()
        self.com_watchdog_timer.cancel ()

        f_cmd ( self.seq_nr, *args, **kwargs )

        self.seq_nr += 1

        self.com_watchdog_timer = threading.Timer ( self.timer_t, self.commwdg )
        self.com_watchdog_timer.start ()

        self.lock.release ()

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::commwdg
    # ---------------------------------------------------------------------------------------------
    def commwdg ( self ):

        """
        communication watchdog signal.

        this needs to be send regulary to keep the communication with the drone alive.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::commwdg" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_comwdg )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::event_boom
    # ---------------------------------------------------------------------------------------------
    def event_boom ( self ):

        """
        boom event
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::event_boom" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # animation to play
        li_anim = arDefs.ARDRONE_LED_ANIMATION_DOUBLE_MISSILE
        
        # frequence in HZ of the animation
        lf_freq = 2.

        # total duration in seconds of the animation
        lf_secs = 4

        # play LED animation
        self.at ( arATCmds.at_led, li_anim, lf_freq, lf_secs )

        # animation to play
        li_anim = arDefs.ARDRONE_ANIMATION_THETA_30_DEG
        
        # total duration in seconds of the animation
        lf_secs = 1000

        # play motion animation
        self.at ( arATCmds.at_anim, li_anim, lf_secs )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::event_thetamixed
    # ---------------------------------------------------------------------------------------------
    def event_thetamixed ( self ):

        """
        make the drone execute thetamixed !
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::event_thetamixed" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # animation to play
        li_anim = arDefs.ARDRONE_LED_ANIMATION_DOUBLE_MISSILE
        
        # frequence in HZ of the animation
        lf_freq = 2.

        # total duration in seconds of the animation
        lf_secs = 4

        # play LED animation
        self.at ( arATCmds.at_led, li_anim, lf_freq, lf_secs )

        # animation to play
        li_anim = arDefs.ARDRONE_ANIMATION_THETA_MIXED
        
        # total duration in seconds of the animation
        lf_secs = 5000

        # play motion animation
        self.at ( arATCmds.at_anim, li_anim, lf_secs )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::event_turnarround
    # ---------------------------------------------------------------------------------------------
    def event_turnarround ( self ):

        """
        make the drone turnarround.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::event_turnarround" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # animation to play
        li_anim = arDefs.ARDRONE_LED_ANIMATION_DOUBLE_MISSILE
        
        # frequence in HZ of the animation
        lf_freq = 2.

        # total duration in seconds of the animation
        lf_secs = 4

        # play LED animation
        self.at ( arATCmds.at_led, li_anim, lf_freq, lf_secs )

        # animation to play
        li_anim = arDefs.ARDRONE_ANIMATION_TURNAROUND
        
        # total duration in seconds of the animation
        lf_secs = 5000

        # play motion animation
        self.at ( arATCmds.at_anim, li_anim, lf_secs )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::event_yawdance
    # ---------------------------------------------------------------------------------------------
    def event_yawdance ( self ):

        """
        make the drone execute yawdance YEAH !
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::event_yawdance" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # animation to play
        li_anim = arDefs.ARDRONE_LED_ANIMATION_DOUBLE_MISSILE
        
        # frequence in HZ of the animation
        lf_freq = 2.

        # total duration in seconds of the animation
        lf_secs = 4

        # play LED animation
        self.at ( arATCmds.at_led, li_anim, lf_freq, lf_secs )

        # animation to play
        li_anim = arDefs.ARDRONE_ANIMATION_YAW_DANCE
        
        # total duration in seconds of the animation
        lf_secs = 5000

        # play motion animation
        self.at ( arATCmds.at_anim, li_anim, lf_secs )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::event_yawshake
    # ---------------------------------------------------------------------------------------------
    def event_yawshake ( self ):

        """
        Make the drone execute yawshake YEAH !
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::event_yawshake" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # animation to play
        li_anim = arDefs.ARDRONE_LED_ANIMATION_DOUBLE_MISSILE
        
        # frequence in HZ of the animation
        lf_freq = 2.

        # total duration in seconds of the animation
        lf_secs = 4

        # play LED animation
        self.at ( arATCmds.at_led, li_anim, lf_freq, lf_secs )

        # animation to play
        li_anim = arDefs.ARDRONE_ANIMATION_YAW_SHAKE
        
        # total duration in seconds of the animation
        lf_secs = 2000

        # play motion animation
        self.at ( arATCmds.at_anim, li_anim, lf_secs )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::get_image
    # ---------------------------------------------------------------------------------------------
    def get_image ( self ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::get_image" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        _im = np.copy ( self.image )

        # sherlock logger
        # l_log.debug ( "<<" )

        return _im

    # ---------------------------------------------------------------------------------------------
    # ARDrone::get_navdata
    # ---------------------------------------------------------------------------------------------
    def get_navdata ( self ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::get_navdata" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( "><" )

        return self.navdata

    # ---------------------------------------------------------------------------------------------
    # ARDrone::halt
    # ---------------------------------------------------------------------------------------------
    def halt ( self ):

        """
        shutdown the drone.

        does not land or halt the actual drone, but the communication with the drone. Should call
        it at the end of application to close all sockets, pipes, processes and threads related
        with this object.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::halt" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.lock.acquire ()

        self.com_watchdog_timer.cancel ()
        self.com_pipe.send ( "die!" )

        self.network_process.terminate ()  # 2.0 ?
        self.network_process.join ()

        self.ipc_thread.stop ()  # 2.0 ?
        self.ipc_thread.join ()  # 2.0 ?

        self.lock.release ()

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::hover
    # ---------------------------------------------------------------------------------------------
    def hover ( self ):

        """
        make the drone hover.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::hover" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_pcmd, False, 0, 0, 0, 0 )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::land
    # ---------------------------------------------------------------------------------------------
    def land ( self ):

        """
        make the drone land.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::land" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_ref, False )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::move
    # ---------------------------------------------------------------------------------------------
    def move ( self, ff_lr, ff_fb, ff_vv, ff_va ):

        """
        makes the drone move (translate/rotate).

        @param lr : left-right tilt: float [-1..1] negative: left      / positive: right
        @param rb : front-back tilt: float [-1..1] negative: forwards  / positive: backwards
        @param vv : vertical speed:  float [-1..1] negative: go down   / positive: rise
        @param va : angular speed:   float [-1..1] negative: spin left / positive: spin right
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::move" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # validate inputs
        # assert ( 1. >= ff_lr >= -1. ) 
        # assert ( 1. >= ff_fb >= -1. ) 
        # assert ( 1. >= ff_vv >= -1. ) 
        # assert ( 1. >= ff_va >= -1. ) 

        # move drone
        self.at ( arATCmds.at_pcmd, True, float ( ff_lr ), float ( ff_fb ), float ( ff_vv ), float ( ff_va ))

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::move_backward
    # ---------------------------------------------------------------------------------------------
    def move_backward ( self ):

        """
        make the drone move backwards.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::move_backward" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_pcmd, True, 0, self.speed, 0, 0 )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::move_down
    # ---------------------------------------------------------------------------------------------
    def move_down ( self ):

        """
        make the drone decent downwards.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::move_down" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_pcmd, True, 0, 0, -self.speed, 0 )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::move_forward
    # ---------------------------------------------------------------------------------------------
    def move_forward ( self ):

        """
        make the drone move forward.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::move_forward" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_pcmd, True, 0, -self.speed, 0, 0 )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::move_left
    # ---------------------------------------------------------------------------------------------
    def move_left ( self ):

        """
        make the drone move left.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::move_left" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_pcmd, True, -self.speed, 0, 0, 0 )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::move_right
    # ---------------------------------------------------------------------------------------------
    def move_right ( self ):

        """
        make the drone move right.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::move_right" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_pcmd, True, self.speed, 0, 0, 0 )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::move_up
    # ---------------------------------------------------------------------------------------------
    def move_up ( self ):

        """
        make the drone rise upwards.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::move_up" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_pcmd, True, 0, 0, self.speed, 0 )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::reset
    # ---------------------------------------------------------------------------------------------
    def reset ( self ):

        """
        toggle the drone's emergency state.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::reset" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_ftrim )

        time.sleep ( 0.1 )
        self.at ( arATCmds.at_ref, False, True )

        time.sleep ( 0.1 )
        self.at ( arATCmds.at_ref, False, False )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::set_image
    # ---------------------------------------------------------------------------------------------
    def set_image ( self, fo_image ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::set_image" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        if ( f_image.shape == self.image_shape ):
            self.image = fo_image

        self.image = fo_image

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::set_navdata
    # ---------------------------------------------------------------------------------------------
    def set_navdata ( self, fo_navdata ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::set_navdata" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.navdata = fo_navdata

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::set_speed
    # ---------------------------------------------------------------------------------------------
    def set_speed ( self, ff_speed ):

        """
        set the drone's speed.

        valid values are floats from [0..1]
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::set_speed" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # validate input
        # assert ( 1. >= ff_speed >= 0. ) 

        # set speed
        self.speed = float ( ff_speed )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::takeoff
    # ---------------------------------------------------------------------------------------------
    def takeoff ( self ):

        """
        make the drone takeoff.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::takeoff" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # calibrate drone
        self.at ( arATCmds.at_ftrim )

        # set maximum altitude 
        self.at ( arATCmds.at_config, "control:altitude_max", "20000" )

        # take-off 
        self.at ( arATCmds.at_ref, True )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::trim
    # ---------------------------------------------------------------------------------------------
    def trim ( self ):

        """
        flat trim the drone.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::trim" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_ftrim )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::turn_left
    # ---------------------------------------------------------------------------------------------
    def turn_left ( self ):

        """
        make the drone rotate left.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::turn_left" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_pcmd, True, 0, 0, 0, -self.speed )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone::turn_right
    # ---------------------------------------------------------------------------------------------
    def turn_right ( self ):

        """
        make the drone rotate right.
        """

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone::turn_right" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_pcmd, True, 0, 0, 0, self.speed )

        # sherlock logger
        # l_log.debug ( "<<" )

# < class ARDrone2 >-------------------------------------------------------------------------------

class ARDrone2 ( ARDrone ):

    """
    ARDrone2 class

    instanciate this class to control your drone and receive decoded video and navdata.
    """

    # ---------------------------------------------------------------------------------------------
    # ARDrone2::__init__
    # ---------------------------------------------------------------------------------------------
    def __init__ ( self, is_ar_drone_2 = True, hd = False ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone2::__init__" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # init super class
        ARDrone.__init__ ( self )

        self.seq_nr = 1
        self.timer_t = 0.2

        self.com_watchdog_timer = threading.Timer ( self.timer_t, self.commwdg )
        self.lock = threading.Lock ()

        self.speed = 0.2

        self.image_shape = ( 720, 1080, 1 )

        time.sleep ( 0.2 )

        self.config_ids_string = [ arDefs.SESSION_ID, arDefs.USER_ID, arDefs.APP_ID ]
        self.configure_multisession ( arDefs.SESSION_ID, arDefs.USER_ID, arDefs.APP_ID, self.config_ids_string )

        self.set_session_id ( self.config_ids_string, arDefs.SESSION_ID )
        time.sleep ( 0.2 )

        self.set_profile_id ( self.config_ids_string, arDefs.USER_ID )
        time.sleep ( 0.2 )

        self.set_app_id ( self.config_ids_string, arDefs.APP_ID )
        time.sleep ( 0.2 )

        self.set_video_bitrate_control_mode ( self.config_ids_string, "1" )
        time.sleep ( 0.2 )

        self.set_video_bitrate ( self.config_ids_string, "500" )
        time.sleep ( 0.2 )

        self.set_max_bitrate ( self.config_ids_string, "500" )
        time.sleep ( 0.2 )

        self.set_fps ( self.config_ids_string, "30" )
        time.sleep ( 0.2 )

        self.set_video_codec ( self.config_ids_string, 0x80 )

        self.last_command_is_hovering = True
        self.com_pipe, com_pipe_other = multiprocessing.Pipe ()

        self.navdata = {}
        self.navdata [ 0 ] = { "ctrl_state":0, "battery":0, "theta":0, "phi":0, "psi":0, "altitude":0, "vx":0, "vy":0, "vz":0, "num_frames":0 }

        self.network_process = arNetwork.ARDrone2NetworkProcess ( com_pipe_other, is_ar_drone_2, self )
        self.network_process.start ()

        self.image = np.zeros ( self.image_shape, np.uint8 )
        self.time = 0

        self.last_command_is_hovering = True
        time.sleep ( 1.0 )

        self.at ( arATCmds.at_config_ids, self.config_ids_string )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone2::configure_multisession
    # ---------------------------------------------------------------------------------------------
    def configure_multisession ( self, f_session_id, f_user_id, f_app_id, f_config_ids_string ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone2::configure_multisession" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_config, "custom:session_id", f_session_id )
        self.at ( arATCmds.at_config, "custom:profile_id", f_user_id )
        self.at ( arATCmds.at_config, "custom:application_id", f_app_id )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone2::set_app_id
    # ---------------------------------------------------------------------------------------------
    def set_app_id ( self, f_config_ids_string, f_app_id ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone2::set_app_id" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_config_ids, f_config_ids_string )
        self.at ( arATCmds.at_config, "custom:application_id", f_app_id )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone2::set_fps
    # ---------------------------------------------------------------------------------------------
    def set_fps ( self, f_config_ids_string, f_fps ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone2::set_fps" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_config_ids, f_config_ids_string )
        self.at ( arATCmds.at_config, "video:codec_fps", f_fps )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone2::set_max_bitrate
    # ---------------------------------------------------------------------------------------------
    def set_max_bitrate ( self, f_config_ids_string, f_max_bitrate ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone2::set_max_bitrate" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_config_ids, f_config_ids_string )
        self.at ( arATCmds.at_config, "video:max_bitrate", f_max_bitrate )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone2::set_profile_id
    # ---------------------------------------------------------------------------------------------
    def set_profile_id ( self, f_config_ids_string, f_profile_id ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone2::set_profile_id" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_config_ids, f_config_ids_string )
        self.at ( arATCmds.at_config, "custom:profile_id", f_profile_id )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone2::set_session_id
    # ---------------------------------------------------------------------------------------------
    def set_session_id ( self, f_config_ids_string, f_session_id ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone2::set_session_id" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_config_ids, f_config_ids_string )
        self.at ( arATCmds.at_config, "custom:session_id", f_session_id )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone2::set_video_bitrate
    # ---------------------------------------------------------------------------------------------
    def set_video_bitrate ( self, f_config_ids_string, f_bitrate ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone2::set_video_bitrate" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_config_ids, f_config_ids_string )
        self.at ( arATCmds.at_config, "video:bitrate", f_bitrate )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone2::set_video_bitrate_control_mode
    # ---------------------------------------------------------------------------------------------
    def set_video_bitrate_control_mode ( self, f_config_ids_string, f_mode ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone2::set_video_bitrate_control_mode" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_config_ids, f_config_ids_string )
        self.at ( arATCmds.at_config, "video:bitrate_control_mode", f_mode )

        # sherlock logger
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # ARDrone2::set_video_codec
    # ---------------------------------------------------------------------------------------------
    def set_video_codec ( self, f_config_ids_string, f_codec ):

        # sherlock logger
        # l_log = logging.getLogger ( "ARDrone2::set_video_codec" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self.at ( arATCmds.at_config_ids, f_config_ids_string )
        self.at ( arATCmds.at_config, "video:video_codec", f_codec )

        # sherlock logger
        # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# the bootstrap process
# -------------------------------------------------------------------------------------------------
if ( "__main__" == __name__ ):

    import termios
    import fcntl
    import os

    l_fd = sys.stdin.fileno ()

    l_old_term = termios.tcgetattr ( l_fd )
    l_new_attr = termios.tcgetattr ( l_fd )
    l_new_attr [ 3 ] = l_new_attr [ 3 ] & ~termios.ICANON & ~termios.ECHO

    termios.tcsetattr ( l_fd, termios.TCSANOW, l_new_attr )

    l_old_flags = fcntl.fcntl ( l_fd, fcntl.F_GETFL )
    fcntl.fcntl ( l_fd, fcntl.F_SETFL, l_old_flags | os.O_NONBLOCK )

    lo_drone = ARDrone ()
    # assert ( lo_drone )

    try:
        while ( True ):
            try:

                lc_c = sys.stdin.read ( 1 )
                lc_c = lc_c.lower ()
                print "Got character", lc_c

                # left ?
                if ( 'a' == lc_c ):
                    lo_drone.move_left ()

                # right ?
                elif ( 'd' == lc_c ):
                    lo_drone.move_right ()

                # forward ?
                elif ( 'w' == lc_c ):
                    lo_drone.move_forward ()

                # backward ?
                elif ( 's' == lc_c ):
                    lo_drone.move_backward ()

                # land ?
                elif ( ' ' == lc_c ):
                    lo_drone.land ()

                # takeoff ?
                elif ( '\n' == lc_c ):
                    lo_drone.takeoff ()

                # turn left ?
                elif ( 'q' == lc_c ):
                    lo_drone.turn_left ()

                # turn right ?
                elif ( 'e' == lc_c ):
                    lo_drone.turn_right ()

                # move up ?
                elif ( '1' == lc_c ):
                    lo_drone.move_up ()

                # hover ?
                elif ( '2' == lc_c ):
                    lo_drone.hover ()

                # move down ?
                elif ( '3' == lc_c ):
                    lo_drone.move_down ()

                # reset ?
                elif ( 't' == lc_c ):
                    lo_drone.reset ()

                # hover ?
                elif ( 'x' == lc_c ):
                    lo_drone.hover ()

                # trim ?
                elif ( 'y' == lc_c ):
                    lo_drone.trim ()

            except IOError:

                pass

    finally:

        termios.tcsetattr ( l_fd, termios.TCSAFLUSH, l_old_term )
        fcntl.fcntl ( l_fd, fcntl.F_SETFL, l_old_flags )

        lo_drone.halt ()

# < the end >-------------------------------------------------------------------------------------- #
