/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_Slider.c
 DESCRIPTION       : Slider Widget wrapper: 
                     SCADE Display Slider imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_Slider_mem.h"
#include "Slider.h"
#include "sgl.h"

void wrapper_Slider_reset(wrapper_Slider_mem* mem)
{
    Slider_reset(&(mem->SSctx));
}

void wrapper_Slider(SGLfloat MinValue, 
					SGLfloat MaxValue, 
					SGLfloat Value,
					SGLbool SetValue,
					SGLlong Orientation, 
					SGLfloat ValueDelta, 
					SGLbool MousePressed, 
					SGLbool MouseReleased, 
					SGLlong MouseButton, 
					SGLbool MouseInside, 
					SGLfloat ClickedValueX, 
					SGLfloat ClickedValueY, 
					SGLfloat (*ValueChange), 
					SGLbool (*ValueChangeEmit), 
					wrapper_Slider_mem* mem)
{
	inC_Slider SSinputs;
	
	SSinputs.MinValue = MinValue;
	SSinputs.MaxValue = MaxValue;
	SSinputs.Value = Value;
	SSinputs.SetValue = SetValue;
	SSinputs.Orientation = Orientation;
	SSinputs.ValueDelta = ValueDelta;
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseReleased = MouseReleased;
	SSinputs.MouseButton = MouseButton;
	SSinputs.MouseInside = MouseInside;
	SSinputs.ClickedValueX = ClickedValueX;
	SSinputs.ClickedValueY = ClickedValueY;
	
	Slider(&SSinputs, &(mem->SSctx));
	
	*ValueChange = 	mem->SSctx.OutValue;
	*ValueChangeEmit = 	mem->SSctx.OutValueEmit;
}
