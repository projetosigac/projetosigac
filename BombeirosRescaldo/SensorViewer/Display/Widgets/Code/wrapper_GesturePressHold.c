/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_GesturePressHold.c
 DESCRIPTION       : GesturePressHold Widget wrapper: 
                     SCADE Display GesturePressHold imported function  
 VERSION           : $Revision: 13759 $
 MODIFICATION DATE : $Date: 2014-05-27 11:48:03 +0200 (mar., 27 mai 2014) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_GesturePressHold_mem.h"
#include "GesturePressHold.h"
#include "sgl.h"

void wrapper_GesturePressHold_reset(wrapper_GesturePressHold_mem* mem)
{
	GesturePressHold_reset(&(mem->SSctx));
}

void wrapper_GesturePressHold(SGLbool MousePressed,
                        SGLbool MouseReleased,
                        SGLbool MouseInside,
                        SGLfloat PosXPx,
                        SGLfloat PosYPx,
                        SGLfloat PosTolerance,
                        SGLfloat CyclePeriod,
                        SGLfloat DelayHold,
                        SGLbool *HoldBegin,
                        SGLbool *Holding,
                        SGLbool *HoldEnd,
                        SGLfloat *PosOutX,
                        SGLfloat *PosOutY,
                        wrapper_GesturePressHold_mem* mem)
{
	inC_GesturePressHold SSinputs;
	
	
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseReleased = MouseReleased;
	SSinputs.MouseInside = MouseInside;
	SSinputs.PosXPx = PosXPx;
	SSinputs.PosYPx = PosYPx;
	SSinputs.PosTolerance = PosTolerance;
	SSinputs.CyclePeriod = CyclePeriod;
	SSinputs.DelayHold = DelayHold;
	
	GesturePressHold(&SSinputs, &(mem->SSctx));
	
	*HoldBegin = mem->SSctx.HoldBegin;
	*Holding = mem->SSctx.Holding;
	*HoldEnd = mem->SSctx.HoldEnd;
	*PosOutX = mem->SSctx.PosOutX;
	*PosOutY = mem->SSctx.PosOutY;
}
