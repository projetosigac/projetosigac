#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
given a stream of data, it allows to read it bitwise.
parts of code from Bastian Venthur, Jean-Baptiste Passot, Florian Lacrampe.
"""

# < imports >--------------------------------------------------------------------------------------

import logging
import struct

# < variáveis globais >----------------------------------------------------------------------------

# logging level
w_logLvl = logging.ERROR

# < class bitReader >------------------------------------------------------------------------------

class bitReader ( object ):

    """
    bitReader class. 
    
    given a stream of data, it allows to read it bitwise.
    """

    # ---------------------------------------------------------------------------------------------
    # bitReader::__init__
    # ---------------------------------------------------------------------------------------------
    def __init__ ( self, f_packet ):

        # sherlock logger  
        # l_log = logging.getLogger ( "bitReader::__init__" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        self._s_packet = f_packet
        self._i_offset = 0
        self._i_bits_left = 0
        self._i_chunk = 0
        self._i_read_bits = 0

        # sherlock logger 
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # bitReader::align
    # ---------------------------------------------------------------------------------------------
    def align ( self ):
        
        """
        byte align the data stream.
        """

        # sherlock logger  
        # l_log = logging.getLogger ( "bitReader::align" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        li_shift = ( 8 - self._i_read_bits ) % 8

        self.read ( li_shift )

        # sherlock logger 
        # l_log.debug ( "<<" )

    # ---------------------------------------------------------------------------------------------
    # bitReader::read
    # ---------------------------------------------------------------------------------------------
    def read ( self, fi_nbits, fv_consume=True ):

        """
        read fi_nbits and return the integer value of the read bits.

        if fv_consume is False, it behaves like a 'peek' method (i.e. it reads the bits but does not consume them).
        """

        # sherlock logger  
        # l_log = logging.getLogger ( "bitReader::read" )
        # l_log.setLevel ( w_logLvl )
        # l_log.debug ( ">>" )

        # read enough bits into chunk so we have at least fi_nbits available
        while ( fi_nbits > self._i_bits_left ):

            try:
                self._i_chunk = ( self._i_chunk << 32 ) | struct.unpack_from ( "<I", self._s_packet, self._i_offset ) [ 0 ]

            except struct.error:
                self._i_chunk <<= 32

            self._i_offset += 4
            self._i_bits_left += 32

        # get the first fi_nbits bits from chunk (and remove them from chunk)
        li_shift = self._i_bits_left - fi_nbits
        li_res = self._i_chunk >> li_shift

        if ( fv_consume ):

            self._i_chunk -= li_res << li_shift
            self._i_bits_left -= fi_nbits
            self._i_read_bits += fi_nbits

        # sherlock logger 
        # l_log.debug ( "<<" )

        return li_res

# -------------------------------------------------------------------------------------------------
# the bootstrap process
# -------------------------------------------------------------------------------------------------
if ( "__main__" == __name__ ):

    pass
    
# < the end >-------------------------------------------------------------------------------------- #
