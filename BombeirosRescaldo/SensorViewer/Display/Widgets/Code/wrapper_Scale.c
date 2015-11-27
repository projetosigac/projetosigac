/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_Scale.c
 DESCRIPTION       : Scale Widget wrapper: 
                     SCADE Display Scale imported function  
 VERSION           : $Revision: 17214 $
 MODIFICATION DATE : $Date: 2015-05-29 18:16:53 +0200 (ven., 29 mai 2015) $
 COPYRIGHT (C)     : 2013 by Esterel Technologies. 
---------------------------------------------------------------------------- +*/

#include "Scale.h"
#include "sgl.h"

//~ #include <stdio.h>

void wrapper_Scale(SGLfloat SizePx,
                             SGLfloat Value,
                             SGLfloat Range,
                             SGLlong Font,
                             SGLfloat DistLargeGrad,
                             SGLlong NumberOfSmallGradPerLargeGrad,
                             array_real_60 (*PosLargePx),
                             array_real_120 (*PosSmallPx),
                             array_real_60 (*ValuesNb),
                             SGLlong (*Integral),
                             SGLlong (*Fractional),
                             array_bool_60 (*LargeVisible),
                             array_bool_120 (*SmallVisible),
                             SGLbool (*RunTimeMode))
{
	inC_Scale SSinputs;
	outC_Scale SSoutputs;
	
	SSinputs.SizePx = SizePx;
	SSinputs.Value = Value;
	SSinputs.Range = Range;
	SSinputs.Font = Font;
	SSinputs.DistLargeGrad = DistLargeGrad;
	SSinputs.NumberOfSmallGradPerLargeGrad = NumberOfSmallGradPerLargeGrad;
	
	Scale(&SSinputs, &SSoutputs);
	
	kcg_copy_array_real_60(PosLargePx,SSoutputs.PosLargePx);
	kcg_copy_array_real_120(PosSmallPx,SSoutputs.PosSmallPx);
	kcg_copy_array_real_60(ValuesNb,SSoutputs.ValuesNb);
	*Integral = SSoutputs.Integral;
	*Fractional = SSoutputs.Fractional;
	*RunTimeMode = SSoutputs.RunTimeMode;
	
	kcg_copy_array_bool_60(LargeVisible,SSoutputs.LargeVisible);
	kcg_copy_array_bool_120(SmallVisible,SSoutputs.SmallVisible);
}
