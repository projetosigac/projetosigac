/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_PushButton.c
 DESCRIPTION       : PushButton Widget wrapper: 
                     SCADE Display PushButton imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_PushButton_mem.h"
#include "PushButton.h"
#include "sgl.h"

void wrapper_PushButton_reset(wrapper_PushButton_mem* mem)
{
    PushButton_reset(&(mem->SSctx));
}

void wrapper_PushButton(SGLlong EmitCondition, 
						SGLbool MouseInside, 
						SGLbool MousePressed, 
						SGLbool MouseReleased, 
						SGLlong MouseButton, 
						SGLbool (*Selection), 
						SGLbool (*ButtonPressed), 
						wrapper_PushButton_mem* mem)
{
    inC_PushButton SSinputs;
	
	SSinputs.EmitCondition = EmitCondition;
	SSinputs.MouseInside = MouseInside;
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseReleased = MouseReleased;
	SSinputs.MouseButton = MouseButton;
	
	PushButton(&SSinputs, &(mem->SSctx));
	
	*Selection = 	mem->SSctx.Selection;
	*ButtonPressed = 	mem->SSctx.ButtonPressed;
}
