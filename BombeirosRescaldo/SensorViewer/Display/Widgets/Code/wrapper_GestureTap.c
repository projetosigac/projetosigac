/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_GestureTap.c
 DESCRIPTION       : GestureTap Widget wrapper: 
                     SCADE Display GestureTap imported function  
 VERSION           : $Revision: 13759 $
 MODIFICATION DATE : $Date: 2014-05-27 11:48:03 +0200 (mar., 27 mai 2014) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_GestureTap_mem.h"
#include "GestureTap.h"
#include "sgl.h"

void wrapper_GestureTap_reset(wrapper_GestureTap_mem* mem)
{
	GestureTap_reset(&(mem->SSctx));
}

void wrapper_GestureTap(SGLbool MousePressed,
                        SGLbool MouseReleased,
                        SGLbool MouseInside,
                        SGLfloat PosXPx,
                        SGLfloat PosYPx,
                        SGLfloat PosTolerance,
                        SGLfloat CyclePeriod,
                        SGLfloat TimeOut1Tap,
                        SGLfloat TimeOut2Tap,
                        SGLbool *EventTap,
                        SGLbool *EventDoubleTap,
                        wrapper_GestureTap_mem* mem)
{
	inC_GestureTap SSinputs;
	
	
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseReleased = MouseReleased;
	SSinputs.MouseInside = MouseInside;
	SSinputs.PosXPx = PosXPx;
	SSinputs.PosYPx = PosYPx;
	SSinputs.PosTolerance = PosTolerance;
	SSinputs.CyclePeriod = CyclePeriod;
	SSinputs.TimeOut1Tap = TimeOut1Tap;
	SSinputs.TimeOut2Tap = TimeOut2Tap;
	
	GestureTap(&SSinputs, &(mem->SSctx));
	
	*EventTap = mem->SSctx.EventTap;
	*EventDoubleTap = mem->SSctx.EventDoubleTap;
}
