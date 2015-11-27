/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_Joystick.c
 DESCRIPTION       : Joystick Widget wrapper: 
                     SCADE Display Joystick imported function  
 VERSION           : $Revision: 13759 $
 MODIFICATION DATE : $Date: 2014-05-27 11:48:03 +0200 (mar., 27 mai 2014) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_Joystick_mem.h"
#include "Joystick.h"
#include "sgl.h"

void wrapper_Joystick_reset(wrapper_Joystick_mem* mem)
{
	Joystick_reset(&(mem->SSctx));
}

void wrapper_Joystick(SGLbool Pressed,
                        SGLbool Released,
                        SGLfloat inX,
                        SGLfloat inY,
                        SGLbool Snap,
                        SGLbool ReturnToCenter,
                        SGLfloat *PosX,
                        SGLfloat *PosY,
                        SGLbool *Active,
                        wrapper_Joystick_mem* mem)
{
	inC_Joystick SSinputs;
	
	
	SSinputs.Pressed = Pressed;
	SSinputs.Released = Released;
	SSinputs.inX = inX;
	SSinputs.inY = inY;
	SSinputs.Snap = Snap;
	SSinputs.ReturnToCenter = ReturnToCenter;
	
	Joystick(&SSinputs, &(mem->SSctx));
	
	*PosX = mem->SSctx.PosX;
	*PosY = mem->SSctx.PosY;
	*Active = mem->SSctx.Active;
}
