/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_ToggleButton.c
 DESCRIPTION       : ToggleButton Widget wrapper: 
                     SCADE Display ToggleButton imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_ToggleButton_mem.h"
#include "ToggleButton.h"
#include "sgl.h"

void wrapper_ToggleButton_reset(wrapper_ToggleButton_mem* mem)
{
    ToggleButton_reset(&(mem->SSctx));
}

void wrapper_ToggleButton(SGLlong EmitCondition, 
						SGLbool MouseInside, 
						SGLbool MousePressed, 
						SGLbool MouseReleased, 
						SGLlong MouseButton, 
						SGLbool ToggleState, 
						SGLbool SetToggleState, 
						SGLbool (*StateChangeEmit), 
						SGLbool (*StateChangeValue), 
						wrapper_ToggleButton_mem* mem)
{
    inC_ToggleButton SSinputs;
	
	SSinputs.EmitCondition = EmitCondition;
	SSinputs.MouseInside = MouseInside;
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseReleased = MouseReleased;
	SSinputs.MouseButton = MouseButton;
	SSinputs.ToggleState = ToggleState;
	SSinputs.SetToggleState = SetToggleState;
	
	ToggleButton(&SSinputs, &(mem->SSctx));
	
	*StateChangeEmit = 	mem->SSctx.StateChangeEmit;
	*StateChangeValue = 	mem->SSctx.StateChangeValue;
}
