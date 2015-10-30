#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
video decoding for the AR.Drone.
parts of code from Bastian Venthur, Jean-Baptiste Passot, Florian Lacrampe.
"""

# < imports >--------------------------------------------------------------------------------------

import array
import cProfile
import datetime
import logging
import struct
import sys

try:

    import psyco

except ImportError:
    pass
    # print "Please install psyco for better video decoding performance."

import bitReader as bitReader

# < variáveis globais >----------------------------------------------------------------------------

# logging level
w_logLvl = logging.ERROR

# from zig-zag back to normal
wa_ZIG_ZAG_POSITIONS = array.array ( 'B',
                                     (  0,  1,  8, 16,  9,  2,  3, 10,
                                       17, 24, 32, 25, 18, 11,  4,  5,
                                       12, 19, 26, 33, 40, 48, 41, 34,
                                       27, 20, 13,  6,  7, 14, 21, 28,
                                       35, 42, 49, 56, 57, 50, 43, 36,
                                       29, 22, 15, 23, 30, 37, 44, 51,
                                       58, 59, 52, 45, 38, 31, 39, 46,
                                       53, 60, 61, 54, 47, 55, 62, 63 ))

# inverse quantization
wa_IQUANT_TAB = array.array ( 'B',
                              (  3,  5,  7,  9, 11, 13, 15, 17,
                                 5,  7,  9, 11, 13, 15, 17, 19,
                                 7,  9, 11, 13, 15, 17, 19, 21,
                                 9, 11, 13, 15, 17, 19, 21, 23,
                                11, 13, 15, 17, 19, 21, 23, 25,
                                13, 15, 17, 19, 21, 23, 25, 27,
                                15, 17, 19, 21, 23, 25, 27, 29,
                                17, 19, 21, 23, 25, 27, 29, 31 ))

# upscaling the 8x8 b- and r-blocks to 16x16
wa_SCALE_TAB = array.array ( 'B',
                             (  0,  0,  1,  1,  2,  2,  3,  3,
                                0,  0,  1,  1,  2,  2,  3,  3,
                                8,  8,  9,  9, 10, 10, 11, 11,
                                8,  8,  9,  9, 10, 10, 11, 11,
                               16, 16, 17, 17, 18, 18, 19, 19,
                               16, 16, 17, 17, 18, 18, 19, 19,
                               24, 24, 25, 25, 26, 26, 27, 27,
                               24, 24, 25, 25, 26, 26, 27, 27,

                                4,  4,  5,  5,  6,  6,  7,  7,
                                4,  4,  5,  5,  6,  6,  7,  7,
                               12, 12, 13, 13, 14, 14, 15, 15,
                               12, 12, 13, 13, 14, 14, 15, 15,
                               20, 20, 21, 21, 22, 22, 23, 23,
                               20, 20, 21, 21, 22, 22, 23, 23,
                               28, 28, 29, 29, 30, 30, 31, 31,
                               28, 28, 29, 29, 30, 30, 31, 31,

                               32, 32, 33, 33, 34, 34, 35, 35,
                               32, 32, 33, 33, 34, 34, 35, 35,
                               40, 40, 41, 41, 42, 42, 43, 43,
                               40, 40, 41, 41, 42, 42, 43, 43,
                               48, 48, 49, 49, 50, 50, 51, 51,
                               48, 48, 49, 49, 50, 50, 51, 51,
                               56, 56, 57, 57, 58, 58, 59, 59,
                               56, 56, 57, 57, 58, 58, 59, 59,

                               36, 36, 37, 37, 38, 38, 39, 39,
                               36, 36, 37, 37, 38, 38, 39, 39,
                               44, 44, 45, 45, 46, 46, 47, 47,
                               44, 44, 45, 45, 46, 46, 47, 47,
                               52, 52, 53, 53, 54, 54, 55, 55,
                               52, 52, 53, 53, 54, 54, 55, 55,
                               60, 60, 61, 61, 62, 62, 63, 63,
                               60, 60, 61, 61, 62, 62, 63, 63 ))

# count leading zeros look up table
wa_CLZLUT = array.array ( 'B',
                          ( 8, 7, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4,
                            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ))

# map pixels from four 8x8 blocks to one 16x16
wa_MB_TO_GOB_MAP = array.array ( 'B',
                                 [   0,   1,   2,   3,   4,   5,   6,   7,
                                    16,  17,  18,  19,  20,  21,  22,  23,
                                    32,  33,  34,  35,  36,  37,  38,  39,
                                    48,  49,  50,  51,  52,  53,  54,  55,
                                    64,  65,  66,  67,  68,  69,  70,  71,
                                    80,  81,  82,  83,  84,  85,  86,  87,
                                    96,  97,  98,  99, 100, 101, 102, 103,
                                   112, 113, 114, 115, 116, 117, 118, 119,
                                     8,   9,  10,  11,  12,  13,  14,  15,
                                    24,  25,  26,  27,  28,  29,  30,  31,
                                    40,  41,  42,  43,  44,  45,  46,  47,
                                    56,  57,  58,  59,  60,  61,  62,  63,
                                    72,  73,  74,  75,  76,  77,  78,  79,
                                    88,  89,  90,  91,  92,  93,  94,  95,
                                   104, 105, 106, 107, 108, 109, 110, 111,
                                   120, 121, 122, 123, 124, 125, 126, 127,
                                   128, 129, 130, 131, 132, 133, 134, 135,
                                   144, 145, 146, 147, 148, 149, 150, 151,
                                   160, 161, 162, 163, 164, 165, 166, 167,
                                   176, 177, 178, 179, 180, 181, 182, 183,
                                   192, 193, 194, 195, 196, 197, 198, 199,
                                   208, 209, 210, 211, 212, 213, 214, 215,
                                   224, 225, 226, 227, 228, 229, 230, 231,
                                   240, 241, 242, 243, 244, 245, 246, 247,
                                   136, 137, 138, 139, 140, 141, 142, 143,
                                   152, 153, 154, 155, 156, 157, 158, 159,
                                   168, 169, 170, 171, 172, 173, 174, 175,
                                   184, 185, 186, 187, 188, 189, 190, 191,
                                   200, 201, 202, 203, 204, 205, 206, 207,
                                   216, 217, 218, 219, 220, 221, 222, 223,
                                   232, 233, 234, 235, 236, 237, 238, 239,
                                   248, 249, 250, 251, 252, 253, 254, 255 ] )

wa_MB_ROW_MAP = array.array ( 'B', [ i / 16 for i in wa_MB_TO_GOB_MAP ] )
wa_MB_COL_MAP = array.array ( 'B', [ i % 16 for i in wa_MB_TO_GOB_MAP ] )

# an array of zeros. It is much faster to take the zeros from here than to
# generate a new list when needed.
wa_ZEROS = array.array ( 'i', [ 0 for i in xrange ( 256 ) ] )

# constants needed for the inverse discrete cosine transform.
wi_FIX_0_298631336 =  2446
wi_FIX_0_390180644 =  3196
wi_FIX_0_541196100 =  4433
wi_FIX_0_765366865 =  6270
wi_FIX_0_899976223 =  7373
wi_FIX_1_175875602 =  9633
wi_FIX_1_501321110 = 12299
wi_FIX_1_847759065 = 15137
wi_FIX_1_961570560 = 16069
wi_FIX_2_053119869 = 16819
wi_FIX_2_562915447 = 20995
wi_FIX_3_072711026 = 25172

wi_CONST_BITS = 13
wi_PASS1_BITS = 1

wi_F1 = wi_CONST_BITS - wi_PASS1_BITS - 1
wi_F2 = wi_CONST_BITS - wi_PASS1_BITS
wi_F3 = wi_CONST_BITS + wi_PASS1_BITS + 3

# tuning parameter for get_block
wi_TRIES = 16
wi_MASK  =  2 ** ( wi_TRIES * 32 ) - 1
wi_SHIFT = 32  * ( wi_TRIES -  1 )

# -------------------------------------------------------------------------------------------------
# _first_half
# -------------------------------------------------------------------------------------------------
def _first_half ( f_data ):

    """
    helper function used to precompute the zero values in a 12 bit datum.
    """

    # sherlock logger
    # l_log = logging.getLogger ( "_first_half" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # f_data has to be 12 bits wide
    li_stream_len = 0

    # count the zeros
    li_zero_count = wa_CLZLUT [ f_data >> 4 ] ;

    f_data = ( f_data << ( li_zero_count + 1 )) & 0b111111111111  # 0xfff
    li_stream_len += li_zero_count + 1

    # get number of remaining bits to read
    li_to_read = 0 if li_zero_count <= 1 else li_zero_count - 1
    li_additional = f_data >> ( 12 - li_to_read )

    f_data = ( f_data << li_to_read ) & 0b111111111111  # 0xfff
    li_stream_len += li_to_read

    # add as many zeros to out_list as indicated by li_additional bits
    # if li_zero_count is 0, tmp = 0 else the 1 merged with li_additional bits
    li_tmp = 0 if ( 0 == li_zero_count ) else (( 1 << li_to_read ) | li_additional )

    # sherlock logger
    # l_log.debug ( "<<" )

    return [ li_stream_len, li_tmp ]

# -------------------------------------------------------------------------------------------------
# _second_half
# -------------------------------------------------------------------------------------------------
def _second_half ( f_data ):

    """
    helper function to precompute the nonzeror values in a 15 bit datum.
    """

    # sherlock logger
    # l_log = logging.getLogger ( "_second_half" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # f_data has to be 15 bits wide
    li_stream_len = 0
    li_zero_count = wa_CLZLUT [ f_data >> 7 ]

    f_data = ( f_data << ( li_zero_count + 1 )) & 0b111111111111111  # 0x7fff
    li_stream_len += li_zero_count + 1

    # 01 == EOB
    lv_eob = False

    if li_zero_count == 1:

        lv_eob = True

        # sherlock logger
        # l_log.debug ( "<< (E01)" )

        return [ li_stream_len, None, lv_eob ]

    # get number of remaining bits to read
    li_to_read = 0 if li_zero_count == 0 else li_zero_count - 1
    li_additional = f_data >> ( 15 - li_to_read )

    f_data = ( f_data << li_to_read ) & 0b111111111111111  # 0x7fff
    li_stream_len += li_to_read

    li_tmp = ( 1 << li_to_read ) | li_additional

    # get one more bit for the sign
    li_tmp = -li_tmp if f_data >> ( 15 - 1 ) else li_tmp
    li_tmp = int ( li_tmp )

    li_stream_len += 1

    # sherlock logger
    # l_log.debug ( "<<" )

    return [ li_stream_len, li_tmp, lv_eob ]

# precompute all 12 and 15 bit values for the entropy decoding process
wai_FH = [ _first_half ( li_i ) for li_i in xrange ( 2 ** 12 ) ]
wai_SH = [ _second_half ( li_i ) for li_i in xrange ( 2 ** 15 ) ]

# -------------------------------------------------------------------------------------------------
# get_block
# -------------------------------------------------------------------------------------------------
def get_block ( f_bitreader, fv_has_coeff ):

    """
    read a 8x8 block from the data stream.

    takes care of the huffman-, RLE, zig-zag and idct and returns a list of 64 ints.
    """

    # sherlock logger
    # l_log = logging.getLogger ( "get_block" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # read the first 10 bits in a 16 bit datum
    la_out_list = wa_ZEROS [ 0:64 ]
    la_out_list [ 0 ] = int ( f_bitreader.read ( 10 )) * wa_IQUANT_TAB [ 0 ]

    if ( not fv_has_coeff ):

        # sherlock logger
        # l_log.debug ( "<< (E01)" )

        return inverse_dct ( la_out_list )

    li_i = 1

    while ( True ):

        _ = f_bitreader.read ( 32 * wi_TRIES, False )

        li_stream_len = 0

        #######################################################################
        for li_j in xrange ( wi_TRIES ):

            l_data = ( _ << li_stream_len ) & wi_MASK
            l_data >>= wi_SHIFT

            li_l, li_tmp = wai_FH [ l_data >> 20 ]
            li_stream_len += li_l

            l_data = ( l_data << li_l ) & 0xffffffff
            li_i += li_tmp

            li_l, li_tmp, lv_eob = wai_SH [ l_data >> 17 ]
            li_stream_len += li_l

            if ( lv_eob ):

                f_bitreader.read ( li_stream_len )

                # sherlock logger
                # l_log.debug ( "<< (E02)" )

                return inverse_dct ( la_out_list )

            li_j = wa_ZIG_ZAG_POSITIONS [ li_i ]

            la_out_list [ li_j ] = li_tmp * wa_IQUANT_TAB [ li_j ]

            li_i += 1
        #######################################################################

        f_bitreader.read ( li_stream_len )

    # sherlock logger
    # l_log.debug ( "<<" )

    return inverse_dct ( la_out_list )

# -------------------------------------------------------------------------------------------------
# get_gob
# -------------------------------------------------------------------------------------------------
def get_gob ( f_bitreader, f_picture, f_slicenr, f_width ):

    """
    read a group of blocks.

    does not return data, the picture parameter is modified in place instead.
    """

    # sherlock logger
    # l_log = logging.getLogger ( "get_gob" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    # the first gob has a special header
    if ( f_slicenr > 0 ):

        f_bitreader.align ()

        li_gobsc = f_bitreader.read ( 22 )

        if ( 0b0000000000000000111111 == li_gobsc ):

            print "weeeee"

            # sherlock logger
            # l_log.debug ( "<< (E01)" )

            return False

        elif ( not ( li_gobsc & 0b0000000000000000100000 ) or  # 0x20
                   ( li_gobsc & 0b1111111111111111000000 )):   # 0x3fffc0

            print "Got wrong GOBSC, aborting.", bin ( li_gobsc )

            # sherlock logger
            # l_log.debug ( "<< (E02)" )

            return False

        _ = f_bitreader.read ( 5 )

    li_offset = f_slicenr * 16 * f_width

    for li_i in xrange ( f_width / 16 ):
        get_mb ( f_bitreader, f_picture, f_width, li_offset + 16 * li_i )

    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# get_mb
# -------------------------------------------------------------------------------------------------
def get_mb ( f_bitreader, f_picture, f_width, f_offset ):

    """
    get macro block.

    does not return data but modifies the picture parameter in place.
    """

    # sherlock logger
    # l_log = logging.getLogger ( "get_mb" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    li_mbc = f_bitreader.read ( 1 )

    if ( 0 == li_mbc ):

        li_mbdesc = f_bitreader.read ( 8 )
        # assert ( li_mbdesc >> 7 & 1 )

        if ( li_mbdesc >> 6 & 1 ):
            li_mbdiff = f_bitreader.read ( 2 )

        li_y = get_block ( f_bitreader, li_mbdesc & 1 )

        li_y.extend ( get_block ( f_bitreader, li_mbdesc >> 1 & 1 ))
        li_y.extend ( get_block ( f_bitreader, li_mbdesc >> 2 & 1 ))
        li_y.extend ( get_block ( f_bitreader, li_mbdesc >> 3 & 1 ))

        la_cb = get_block ( f_bitreader, li_mbdesc >> 4 & 1 )
        la_cr = get_block ( f_bitreader, li_mbdesc >> 5 & 1 )

        # ycbcr to rgb
        for li_i in xrange ( 256 ):

            li_j = wa_SCALE_TAB [ li_i ]

            li_Y = li_y [ li_i ] - 16
            li_B = la_cb [ li_j ] - 128
            li_R = la_cr [ li_j ] - 128

            li_r = ( 298 * li_Y + 409 *              li_R + 128 ) >> 8
            li_g = ( 298 * li_Y - 100 * li_B - 208 * li_R + 128 ) >> 8
            li_b = ( 298 * li_Y + 516 * li_B + 128 )              >> 8

            li_r =   0 if ( li_r <   0 ) else li_r
            li_r = 255 if ( li_r > 255 ) else li_r

            li_g =   0 if ( li_g <   0 ) else li_g
            li_g = 255 if ( li_g > 255 ) else li_g

            li_b =   0 if ( li_b <   0 ) else li_b
            li_b = 255 if ( li_b > 255 ) else li_b

            # re-order the pixels
            li_row = wa_MB_ROW_MAP [ li_i ]
            li_col = wa_MB_COL_MAP [ li_i ]

            f_picture [ f_offset + li_row * f_width + li_col ] = ''.join ((chr ( li_r ), chr ( li_g ), chr ( li_b )))

    else:
        print "mbc was not zero"

    # sherlock logger
    # l_log.debug ( "<<" )

# -------------------------------------------------------------------------------------------------
# get_pheader
# -------------------------------------------------------------------------------------------------
def get_pheader ( f_bitreader ):

    """
    read the picture header.

    returns the width and height of the image.
    """

    # sherlock logger
    # l_log = logging.getLogger ( "get_pheader" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    f_bitreader.align ()

    li_psc = f_bitreader.read ( 22 )
    # assert ( 0b0000000000000000100000 == li_psc )

    li_pformat = f_bitreader.read ( 2 )
    # assert ( 0b00 != li_pformat )

    if ( 1 == li_pformat ):
        # CIF
        li_width, li_height = 88, 72

    else:
        # VGA
        li_width, li_height = 160, 120

    li_presolution = f_bitreader.read ( 3 )
    # assert ( 0b000 != li_presolution )

    # double resolution presolution - 1 times
    li_width  = li_width  << ( li_presolution - 1 )
    li_height = li_height << ( li_presolution - 1 )

    # l_log.debug ( "width: %d / height: %d" % ( li_width, li_height ))

    li_ptype  = f_bitreader.read (  3 )
    li_pquant = f_bitreader.read (  5 )
    li_pframe = f_bitreader.read ( 32 )

    # sherlock logger
    # l_log.debug ( "<<" )

    return li_width, li_height

# -------------------------------------------------------------------------------------------------
# inverse_dct
# -------------------------------------------------------------------------------------------------
def inverse_dct ( f_block ):

    """
    inverse discrete cosine transform.
    """

    # sherlock logger
    # l_log = logging.getLogger ( "inverse_dct" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    la_workspace = wa_ZEROS [ 0:64 ]
    la_data = wa_ZEROS [ 0:64 ]

    for li_pointer in xrange ( 8 ):

        if (( 0 == f_block [ li_pointer +  8 ] ) and ( 0 == f_block [ li_pointer + 16 ] ) and
            ( 0 == f_block [ li_pointer + 24 ] ) and ( 0 == f_block [ li_pointer + 32 ] ) and
            ( 0 == f_block [ li_pointer + 40 ] ) and ( 0 == f_block [ li_pointer + 48 ] ) and
            ( 0 == f_block [ li_pointer + 56 ] )):

            li_dcval = f_block [ li_pointer ] << wi_PASS1_BITS

            for li_i in xrange ( 8 ):
                la_workspace [ li_pointer + li_i * 8 ] = li_dcval

            continue

        li_z2 = f_block [ li_pointer + 16 ]
        li_z3 = f_block [ li_pointer + 48 ]

        li_z1 = ( li_z2 + li_z3 ) * wi_FIX_0_541196100

        li_tmp2 = li_z1 + li_z3 * -wi_FIX_1_847759065
        li_tmp3 = li_z1 + li_z2 *  wi_FIX_0_765366865

        li_z2 = f_block [ li_pointer ]
        li_z3 = f_block [ li_pointer + 32 ]

        li_tmp0 = ( li_z2 + li_z3 ) << wi_CONST_BITS
        li_tmp1 = ( li_z2 - li_z3 ) << wi_CONST_BITS

        li_tmp10 = li_tmp0 + li_tmp3
        li_tmp13 = li_tmp0 - li_tmp3
        li_tmp11 = li_tmp1 + li_tmp2
        li_tmp12 = li_tmp1 - li_tmp2

        li_tmp0 = f_block [ li_pointer + 56 ]
        li_tmp1 = f_block [ li_pointer + 40 ]
        li_tmp2 = f_block [ li_pointer + 24 ]
        li_tmp3 = f_block [ li_pointer +  8 ]

        li_z1 = li_tmp0 + li_tmp3
        li_z2 = li_tmp1 + li_tmp2
        li_z3 = li_tmp0 + li_tmp2
        li_z4 = li_tmp1 + li_tmp3

        li_z5 = ( li_z3 + li_z4 ) * wi_FIX_1_175875602

        li_tmp0 *= wi_FIX_0_298631336
        li_tmp1 *= wi_FIX_2_053119869
        li_tmp2 *= wi_FIX_3_072711026
        li_tmp3 *= wi_FIX_1_501321110

        li_z1 *= -wi_FIX_0_899976223
        li_z2 *= -wi_FIX_2_562915447
        li_z3 *= -wi_FIX_1_961570560
        li_z4 *= -wi_FIX_0_390180644

        li_z3 += li_z5
        li_z4 += li_z5

        li_tmp0 += li_z1 + li_z3
        li_tmp1 += li_z2 + li_z4
        li_tmp2 += li_z2 + li_z3
        li_tmp3 += li_z1 + li_z4

        la_workspace [ li_pointer + 0  ] = (( li_tmp10 + li_tmp3 + ( 1 << wi_F1 )) >> wi_F2 )
        la_workspace [ li_pointer + 56 ] = (( li_tmp10 - li_tmp3 + ( 1 << wi_F1 )) >> wi_F2 )
        la_workspace [ li_pointer + 8  ] = (( li_tmp11 + li_tmp2 + ( 1 << wi_F1 )) >> wi_F2 )
        la_workspace [ li_pointer + 48 ] = (( li_tmp11 - li_tmp2 + ( 1 << wi_F1 )) >> wi_F2 )
        la_workspace [ li_pointer + 16 ] = (( li_tmp12 + li_tmp1 + ( 1 << wi_F1 )) >> wi_F2 )
        la_workspace [ li_pointer + 40 ] = (( li_tmp12 - li_tmp1 + ( 1 << wi_F1 )) >> wi_F2 )
        la_workspace [ li_pointer + 24 ] = (( li_tmp13 + li_tmp0 + ( 1 << wi_F1 )) >> wi_F2 )
        la_workspace [ li_pointer + 32 ] = (( li_tmp13 - li_tmp0 + ( 1 << wi_F1 )) >> wi_F2 )

    for li_pointer in xrange ( 0, 64, 8 ):

        li_z2 = la_workspace [ li_pointer + 2 ]
        li_z3 = la_workspace [ li_pointer + 6 ]

        li_z1 = ( li_z2 + li_z3 ) * wi_FIX_0_541196100

        li_tmp2 = li_z1 + li_z3 * -wi_FIX_1_847759065
        li_tmp3 = li_z1 + li_z2 *  wi_FIX_0_765366865

        li_tmp0 = ( la_workspace [ li_pointer ] + la_workspace [ li_pointer + 4 ] ) << wi_CONST_BITS
        li_tmp1 = ( la_workspace [ li_pointer ] - la_workspace [ li_pointer + 4 ] ) << wi_CONST_BITS

        li_tmp10 = li_tmp0 + li_tmp3
        li_tmp13 = li_tmp0 - li_tmp3
        li_tmp11 = li_tmp1 + li_tmp2
        li_tmp12 = li_tmp1 - li_tmp2

        li_tmp0 = la_workspace [ li_pointer + 7 ]
        li_tmp1 = la_workspace [ li_pointer + 5 ]
        li_tmp2 = la_workspace [ li_pointer + 3 ]
        li_tmp3 = la_workspace [ li_pointer + 1 ]

        li_z1 = li_tmp0 + li_tmp3
        li_z2 = li_tmp1 + li_tmp2
        li_z3 = li_tmp0 + li_tmp2
        li_z4 = li_tmp1 + li_tmp3

        li_z5 = ( li_z3 + li_z4 ) * wi_FIX_1_175875602

        li_tmp0 *= wi_FIX_0_298631336
        li_tmp1 *= wi_FIX_2_053119869
        li_tmp2 *= wi_FIX_3_072711026
        li_tmp3 *= wi_FIX_1_501321110

        li_z1 *= -wi_FIX_0_899976223
        li_z2 *= -wi_FIX_2_562915447
        li_z3 *= -wi_FIX_1_961570560
        li_z4 *= -wi_FIX_0_390180644

        li_z3 += li_z5
        li_z4 += li_z5

        li_tmp0 += li_z1 + li_z3
        li_tmp1 += li_z2 + li_z4
        li_tmp2 += li_z2 + li_z3
        li_tmp3 += li_z1 + li_z4

        la_data [ li_pointer + 0 ] = ( li_tmp10 + li_tmp3 ) >> wi_F3
        la_data [ li_pointer + 7 ] = ( li_tmp10 - li_tmp3 ) >> wi_F3
        la_data [ li_pointer + 1 ] = ( li_tmp11 + li_tmp2 ) >> wi_F3
        la_data [ li_pointer + 6 ] = ( li_tmp11 - li_tmp2 ) >> wi_F3
        la_data [ li_pointer + 2 ] = ( li_tmp12 + li_tmp1 ) >> wi_F3
        la_data [ li_pointer + 5 ] = ( li_tmp12 - li_tmp1 ) >> wi_F3
        la_data [ li_pointer + 3 ] = ( li_tmp13 + li_tmp0 ) >> wi_F3
        la_data [ li_pointer + 4 ] = ( li_tmp13 - li_tmp0 ) >> wi_F3

    # sherlock logger
    # l_log.debug ( "<<" )

    return la_data

# -------------------------------------------------------------------------------------------------
# read_picture
# -------------------------------------------------------------------------------------------------
def read_picture ( f_data ):

    """
    convert an AR.Drone image packet to rgb-string.

    @param  f_data : image packet.

    @return width, height, image and time to decode the image.
    """

    # sherlock logger
    # l_log = logging.getLogger ( "read_picture" )
    # l_log.setLevel ( w_logLvl )
    # l_log.debug ( ">>" )

    f_bitreader = bitReader.bitReader ( f_data )

    ll_ti = datetime.datetime.now ()

    li_width, li_height = get_pheader ( f_bitreader )

    li_slices = li_height / 16
    li_blocks = li_width / 16

    lai_image = [ 0 for li_i in xrange ( li_width * li_height ) ]

    for li_i in xrange ( 0, li_slices ):
        get_gob ( f_bitreader, lai_image, li_i, li_width )

    f_bitreader.align ()

    li_eos = f_bitreader.read ( 22 )
    # assert ( 0b0000000000000000111111 == li_eos )

    ll_tf = datetime.datetime.now ()

    # sherlock logger
    # l_log.debug ( "<<" )

    return li_width, li_height, ''.join ( lai_image ), ( ll_tf - ll_ti ).microseconds / 1000000.

# -------------------------------------------------------------------------------------------------
# 
# -------------------------------------------------------------------------------------------------
try:

    psyco.bind ( bitReader )
    psyco.bind ( get_block )
    psyco.bind ( get_gob )
    psyco.bind ( get_mb )
    psyco.bind ( inverse_dct )
    psyco.bind ( read_picture )

except NameError:
    pass
    # print "Unable to bind video decoding methods with psyco. Proceeding anyways, but video decoding will be slow!"

# -------------------------------------------------------------------------------------------------
# main
# -------------------------------------------------------------------------------------------------
def main ():

    l_fh = open ( "framewireshark.raw", 'r' )
    # l_fh = open ( "videoframe.raw", 'r' )

    l_data = l_fh.read ()

    l_fh.close ()

    li_runs = 20
    li_t = 0

    for li_i in xrange ( li_runs ):

        li_width, li_height, lai_image, li_ti = read_picture ( l_data )
        #show_image ( lai_image, li_width, li_height )
        li_t += li_ti

    print
    print "avg time:\t", li_t / li_runs, "sec"
    print "avg fps.:\t", 1 / ( li_t / li_runs ), "fps"

    if ( "image" in sys.argv ):

        import pygame

        pygame.init ()

        li_W, li_H = 320, 240

        l_screen = pygame.display.set_mode (( li_W, li_H ))
        l_surface = pygame.image.fromstring ( lai_image, ( li_width, li_height ), "RGB" )

        screen.blit ( l_surface, ( 0, 0 ))

        pygame.display.flip ()

        raw_input ()

# -------------------------------------------------------------------------------------------------
# the bootstrap process
# -------------------------------------------------------------------------------------------------
if ( "__main__" == __name__ ):

    if ( "profile" in sys.argv ):
        cProfile.run ( "main ()" )

    else:
        main ()
            
# < the end >-------------------------------------------------------------------------------------- #
            