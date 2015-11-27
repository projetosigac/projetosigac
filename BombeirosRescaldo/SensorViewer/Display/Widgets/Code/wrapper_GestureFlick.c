/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_GestureFlick.c
 DESCRIPTION       : GestureFlick Widget wrapper: 
                     SCADE Display GestureFlick imported function  
 VERSION           : $Revision: 13759 $
 MODIFICATION DATE : $Date: 2014-05-27 11:48:03 +0200 (mar., 27 mai 2014) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_GestureFlick_mem.h"
#include "GestureFlick.h"
#include "sgl.h"

void wrapper_GestureFlick_reset(wrapper_GestureFlick_mem* mem)
{
	GestureFlick_reset(&(mem->SSctx));
}

void wrapper_GestureFlick(SGLbool MousePressed,
                        SGLbool MouseReleased,
                        SGLbool MouseInside,
                        SGLfloat PosXPx,
                        SGLfloat PosYPx,
                        SGLfloat PosTolerance,
                        SGLfloat TimeTolerance,
                        SGLfloat CycleTime,
                        SGLbool *EventFlick,
                        SGLfloat *Direction,
                        SGLfloat *Velocity,
                        wrapper_GestureFlick_mem* mem)
{
	inC_GestureFlick SSinputs;
	
	
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseReleased = MouseReleased;
	SSinputs.MouseInside = MouseInside;
	SSinputs.PosXPx = PosXPx;
	SSinputs.PosYPx = PosYPx;
	SSinputs.PosTolerance = PosTolerance;
	SSinputs.TimeTolerance = TimeTolerance;
	SSinputs.CycleTime = CycleTime;
	
	GestureFlick(&SSinputs, &(mem->SSctx));
	
	*EventFlick = mem->SSctx.EventFlick;
	*Direction = mem->SSctx.Direction;
	*Velocity = mem->SSctx.Velocity;
}
