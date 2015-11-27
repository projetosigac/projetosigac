/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_MultilineEditBox.c
 DESCRIPTION       : MultilineEditBox Widget wrapper: 
                     SCADE Display MultilineEditBox imported function  
 VERSION           : $Revision: 15686 $
 MODIFICATION DATE : $Date: 2014-12-04 15:43:31 +0100 (jeu., 04 déc. 2014) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_MultilineEditBox_mem.h"
#include "MultilineEditBox.h"
#include "sgl.h"

void wrapper_MultilineEditBox_reset(wrapper_MultilineEditBox_mem* mem)
{
	MultilineEditBox_reset(&(mem->SSctx));
}

void wrapper_MultilineEditBox(SGLbool MouseInside, 
							  SGLbool MousePressed, 
							  SGLlong MouseButton, 
							  SGLbool KeyPressed, 
							  SGLlong KeyCode,  
							  SGLlong KeyModifiers, 
							  SGLbyte LabelString[255], 
							  SGLbool LabelStringReceived, 
							  SGLlong MaxStringLength, 
							  SGLbool ClickedUp, 
							  SGLbool ClickedDown, 
							  SGLfloat TextBoxVerticalSize, 
							  SGLfloat CursorPosY, 
							  SGLfloat LineSize, 
							  SGLlong NbLines,
							  SGLbool NewCursorIndex, 
							  SGLlong CursorIndex, 
							  SGLbool ReleasedLift,
							  SGLbool ClickedLift, 
							  SGLfloat PositionLift, 
							  SGLbyte (*StringChangeValue)[255], 
							  SGLbool (*CursorVisible), 
							  SGLbyte (*DisplayedString)[255], 
							  SGLfloat (*EditBoxDisplacement), 
							  SGLbool (*EditMode), 
							  SGLlong (*IndexInString), 
							  SGLbool (*RunTimeMode),
							  wrapper_MultilineEditBox_mem* mem)
{
	inC_MultilineEditBox SSinputs;
	
	SSinputs.MouseInside = MouseInside;
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseButton = MouseButton;
	SSinputs.KeyPressed = KeyPressed;
	SSinputs.KeyCode = KeyCode;
	SSinputs.KeyModifiers = KeyModifiers;
	kcg_copy_array_char_255(SSinputs.LabelString,LabelString);
	SSinputs.LabelStringReceived = LabelStringReceived;
	SSinputs.MaxStringLength = MaxStringLength;
	SSinputs.ClickedUp = ClickedUp;
	SSinputs.ClickedDown = ClickedDown;
	SSinputs.TextBoxVerticalSize = TextBoxVerticalSize;
	SSinputs.CursorPosY = CursorPosY;
	SSinputs.LineSize = LineSize;
	SSinputs.NbLines = NbLines;
	SSinputs.NewCursorIndex = NewCursorIndex;
	SSinputs.CursorIndex = CursorIndex;
	SSinputs.ReleasedLift = ReleasedLift;
	SSinputs.ClickedLift = ClickedLift;
	SSinputs.PositionLift = PositionLift;

	MultilineEditBox(&SSinputs, &(mem->SSctx));
	
	kcg_copy_array_char_255(StringChangeValue,mem->SSctx.StringChangeValue);
	*CursorVisible = 	mem->SSctx.CursorVisible;
	kcg_copy_array_char_255(DisplayedString,mem->SSctx.DisplayedString);
	*EditBoxDisplacement = 	mem->SSctx.EditBoxDisplacement;
	*EditMode = 	mem->SSctx.EditMode;
	*IndexInString = 	mem->SSctx.IndexInString;
	*RunTimeMode=mem->SSctx.RunTimeMode;
}
