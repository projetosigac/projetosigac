/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_CheckButton.c
 DESCRIPTION       : CheckButton Widget wrapper: 
                     SCADE Display CheckButton imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_CheckButton_mem.h"
#include "CheckButton.h"
#include "sgl.h"

void wrapper_CheckButton_reset(wrapper_CheckButton_mem* mem)
{
    CheckButton_reset(&(mem->SSctx));
}

void wrapper_CheckButton(SGLbool CheckButtonState,
						SGLbool SetCheckButtonState,
						SGLlong EmitCondition, 
						SGLbool MousePressed, 
						SGLbool MouseReleased, 
						SGLlong MouseButton, 
						SGLbool MouseInside, 
						SGLbool (*StateChangeValue), 
						SGLbool (*StateChangeValueEmit), 
						wrapper_CheckButton_mem* mem)
{
    inC_CheckButton SSinputs;
	
	SSinputs.EmitCondition = EmitCondition;
	SSinputs.MouseInside = MouseInside;
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseReleased = MouseReleased;
	SSinputs.MouseButton = MouseButton;
	SSinputs.CheckButtonState = CheckButtonState;
	SSinputs.SetCheckButtonState = SetCheckButtonState;
	
	CheckButton(&SSinputs, &(mem->SSctx));
	
	*StateChangeValue = 	mem->SSctx.StateChangeValue;
	*StateChangeValueEmit = 	mem->SSctx.StateChangeValueEmit;
}
