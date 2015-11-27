/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_Curve.c
 DESCRIPTION       : Curve Widget wrapper: 
                     SCADE Display Curve imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_Curve_mem.h"
#include "Curve.h"
#include "sgl.h"

void wrapper_Curve_reset(wrapper_Curve_mem* mem)
{
    Curve_reset(&(mem->SSctx));
}

void wrapper_Curve(SGLfloat InitValue, 
					   SGLbool Reset, 
					   SGLfloat Value,
					   SGLlong SpecificIndex, 
					   SGLlong Offset, 
					   SGLlong SkipCycles,
					   array_real_100 (*Data),
					   SGLfloat (*SpecificValue),
					   wrapper_Curve_mem* mem)
{
    inC_Curve SSinputs;
	
	SSinputs.InitValue = InitValue;
	SSinputs.Reset = Reset;
	SSinputs.Value = Value;
	SSinputs.SpecificIndex = SpecificIndex;
	SSinputs.Offset = Offset;
	SSinputs.SkipCycles = SkipCycles;
	
	Curve(&SSinputs, &(mem->SSctx));
	
	kcg_copy_array_real_100(Data,mem->SSctx.Data);
	*SpecificValue = mem->SSctx.SpecificValue;
}
