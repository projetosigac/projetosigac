/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_RollingDigits.c
 DESCRIPTION       : RollingDigits Widget wrapper: 
                     SCADE Display RollingDigits imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (Wed, 19 Jun 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "RollingDigits.h"
#include "sgl.h"

void wrapper_RollingDigits(SGLfloat Value,
					SGLfloat Mult,
					SGLfloat FontSize,
					array_real_6 (*Pos1)[6],
					array_real_6 (*Pos2)[6],
					array_char_1_6 (*Char1)[6][1],
					array_char_1_6 (*Char2)[6][1],
					SGLlong (*NbDigitsRolling),
					array_real_16 (*PosRoll)[16],
					array_real_16 (*TextRoll)[16]
){
	static inC_RollingDigits SSinputs;
	static outC_RollingDigits SSoutputs;
	
	SSinputs.Value = Value;
	SSinputs.Mult = Mult;
	SSinputs.FontSize = FontSize;
	
	RollingDigits(&SSinputs, &SSoutputs);
	
	kcg_copy_array_real_6(Pos1,SSoutputs.Pos1);
	kcg_copy_array_real_6(Pos2,SSoutputs.Pos2);
	kcg_copy_array_char_1_6(Char1,SSoutputs.Char1);
	kcg_copy_array_char_1_6(Char2,SSoutputs.Char2);
	*NbDigitsRolling = SSoutputs.NbDigitsRolling;
	kcg_copy_array_real_16(PosRoll,SSoutputs.PosRoll);
	kcg_copy_array_real_16(TextRoll,SSoutputs.TextRoll);
}
