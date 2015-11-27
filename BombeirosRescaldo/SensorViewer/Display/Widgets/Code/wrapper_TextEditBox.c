/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_TextEditBox.c
 DESCRIPTION       : TextEditBox Widget wrapper: 
                     SCADE Display TextEditBox imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_TextEditBox_mem.h"
#include "TextEditBox.h"
#include "sgl.h"

void wrapper_TextEditBox_reset(wrapper_TextEditBox_mem* mem)
{
    TextEditBox_reset(&(mem->SSctx));
}

void wrapper_TextEditBox(SGLbool MouseInside, 
						 SGLbool MousePressed, 
						 SGLlong MouseButton, 
						 SGLbool KeyPressed, 
						 SGLlong KeyCode, 
						 SGLbyte LabelString[255], 
						 SGLbool LabelStringReceived, 
						 SGLlong MaxStringLength, 
						 SGLbool NewCursorIndex, 
						 SGLlong CursorIndex, 
						 SGLbool (*StringChangeEmit), 
						 SGLbyte (*StringChangeValue)[255], 
						 SGLbool (*CursorVisible), 
						 SGLlong (*IndexInString), 
						 SGLbool (*EditMode), 
						 SGLbyte (*DisplayedString)[255], 
						 SGLbool (*RuntimeMode), 
						 wrapper_TextEditBox_mem* mem)
{
    inC_TextEditBox SSinputs;
	
	SSinputs.MouseInside = MouseInside;
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseButton = MouseButton;
	SSinputs.KeyPressed = KeyPressed;
	SSinputs.KeyCode = KeyCode;
	kcg_copy_array_char_255(SSinputs.LabelString,LabelString);
	SSinputs.LabelStringReceived = LabelStringReceived;
	SSinputs.MaxStringLength = MaxStringLength;
	SSinputs.NewCursorIndex = NewCursorIndex;
	SSinputs.CursorIndex = CursorIndex;

	TextEditBox(&SSinputs, &(mem->SSctx));
	
	*StringChangeEmit = 	mem->SSctx.StringChangeEmit;
	kcg_copy_array_char_255(StringChangeValue,mem->SSctx.StringChangeValue);
	*CursorVisible = 	mem->SSctx.CursorVisible;
	*IndexInString = 	mem->SSctx.IndexInString;
	*EditMode = 	mem->SSctx.EditMode;
	kcg_copy_array_char_255(DisplayedString,mem->SSctx.DisplayedString);
	*RuntimeMode = 	mem->SSctx.RuntimeMode;
}
