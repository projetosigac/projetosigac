/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_NumericEditBox.c
 DESCRIPTION       : NumericEditBox Widget wrapper: 
                     SCADE Display NumericEditBox imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_NumericEditBox_mem.h"
#include "NumericEditBox.h"
#include "sgl.h"
#include "stdio.h"

void wrapper_NumericEditBox_reset(wrapper_NumericEditBox_mem* mem)
{
    NumericEditBox_reset(&(mem->SSctx));
}

void wrapper_NumericEditBox(SGLbool MouseInside, 
							SGLbool MousePressed, 
							SGLlong MouseButton, 
							SGLbool KeyPressed, 
							SGLlong KeyCode, 
							SGLlong KeyModifier, 
							SGLfloat Value, 
							SGLbool SetValue, 
							SGLfloat MinValue, 
							SGLfloat MaxValue, 
							SGLfloat IncrValueCoarse, 
							SGLfloat IncrValueFine, 
							SGLbool NewCursorIndex, 
							SGLlong CursorIndex, 
							SGLbool LeadingZeros, 
							SGLlong DisplaySign, 
							SGLlong NbDigitsIntPart, 
							SGLlong NbDigitsFractionalPart, 
							SGLbyte (*DisplayedString)[255], 
							SGLbool (*ChangeEmit), 
							SGLfloat (*ValueChange), 
							SGLbool (*CursorVisible),
							SGLlong (*CursorPos), 	
							SGLbool (*EditMode),
							wrapper_NumericEditBox_mem* mem)
{
    inC_NumericEditBox SSinputs;

	SSinputs.MouseInside = MouseInside;
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseButton = MouseButton;
	SSinputs.KeyPressed = KeyPressed;
	SSinputs.KeyCode = KeyCode;
	SSinputs.KeyModifier = KeyModifier;
	SSinputs.Value = Value;
	SSinputs.SetValue = SetValue;
	SSinputs.MinValue = MinValue;
	SSinputs.MaxValue = MaxValue;
	SSinputs.IncrValueCoarse = IncrValueCoarse;
	SSinputs.IncrValueFine = IncrValueFine;
	SSinputs.NewCursorIndex = NewCursorIndex;
	SSinputs.CursorIndex = CursorIndex;
	SSinputs.LeadingZeros = LeadingZeros;
	SSinputs.DisplaySign = DisplaySign;
	SSinputs.NbDigitsIntPart = NbDigitsIntPart;
	SSinputs.NbDigitsFractionalPart = NbDigitsFractionalPart;

	NumericEditBox(&SSinputs, &(mem->SSctx));
	
	kcg_copy_array_char_255(DisplayedString,mem->SSctx.DisplayedString);
	*ChangeEmit = mem->SSctx.ChangeEmit;
	*ValueChange = mem->SSctx.ValueChange;
	*CursorVisible = mem->SSctx.CursorVisible;
	*CursorPos = mem->SSctx.CursorPos;
	*EditMode = mem->SSctx.EditMode;
}
