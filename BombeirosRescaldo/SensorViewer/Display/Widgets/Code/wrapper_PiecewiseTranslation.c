/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_PiecewiseTranslation.c
 DESCRIPTION       : PiecewiseTranslation Widget wrapper: 
                     SCADE Display PiecewiseTranslation imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "PiecewiseTranslation.h"
#include "sgl.h"

void wrapper_PiecewiseTranslation(SGLlong size,
						array_real_16 v_list,
						array_real_16 x_list,
						array_real_16 y_list,
						SGLbool saturate_low, 
						SGLbool saturate_high, 
						SGLfloat v,
						SGLfloat *x,
						SGLfloat *y)
{
	static inC_PiecewiseTranslation SSinputs;
	static outC_PiecewiseTranslation SSoutputs;
	
	SSinputs.size = size;
	kcg_copy_array_real_16(SSinputs.v_list,v_list);
	kcg_copy_array_real_16(SSinputs.x_list,x_list);
	kcg_copy_array_real_16(SSinputs.y_list,y_list);
	SSinputs.saturate_low = saturate_low;
	SSinputs.saturate_high = saturate_high;
	SSinputs.v=v;
	
	PiecewiseTranslation(&SSinputs, &SSoutputs);
	
	*x = 	SSoutputs.x;
	*y = 	SSoutputs.y;
}
