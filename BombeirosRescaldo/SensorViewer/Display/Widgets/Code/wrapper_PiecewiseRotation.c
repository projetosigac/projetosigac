/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_PiecewiseRotation.c
 DESCRIPTION       : PiecewiseRotation Widget wrapper: 
                     SCADE Display PiecewiseRotation imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "PiecewiseRotation.h"
#include "sgl.h"

void wrapper_PiecewiseRotation(SGLlong size,
						array_real_16 v_list,
						array_real_16 angle_list,
						SGLbool saturate_low, 
						SGLbool saturate_high, 
						SGLfloat v,
						SGLfloat *angle)
{
	static inC_PiecewiseRotation SSinputs;
	static outC_PiecewiseRotation SSoutputs;
	
	SSinputs.size = size;
	kcg_copy_array_real_16(SSinputs.v_list,v_list);
	kcg_copy_array_real_16(SSinputs.angle_list,angle_list);
	SSinputs.saturate_low = saturate_low;
	SSinputs.saturate_high = saturate_high;
	SSinputs.v=v;
	
	PiecewiseRotation(&SSinputs, &SSoutputs);
	
	*angle = 	SSoutputs.angle;
}
