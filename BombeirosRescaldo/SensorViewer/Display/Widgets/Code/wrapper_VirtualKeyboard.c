/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_VirtualKeyboard.c
 DESCRIPTION       : VirtualKeyboard Widget wrapper: 
                     SCADE Display VirtualKeyboard imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2013 by Esterel Technologies. 
---------------------------------------------------------------------------- +*/

#include "wrapper_VirtualKeyboard_mem.h"
#include "VirtualKeyboard.h"
#include "sgl.h"

void wrapper_VirtualKeyboard_reset(wrapper_VirtualKeyboard_mem* mem)
{
	VirtualKeyboard_reset(&(mem->SSctx));
}

void wrapper_VirtualKeyboard( SGLbool Shift,
                             SGLbool CapsLock,
                             SGLbool NumLock,
                             array_bool_30 KeyArray,
                             SGLbool EnterClicked,
                             SGLbool SpaceClicked,
                             SGLbool BackspaceClicked,
                             SGLlong (*KeyCode),
                             SGLbool (*KeyPressed),
                             SGLbyte (*KeyChar),
                             array_char_255_30 (*KeyLabels),
                             wrapper_VirtualKeyboard_mem* mem)
{
	inC_VirtualKeyboard SSinputs;
	
	SSinputs.Shift = Shift;
	
	SSinputs.CapsLock = CapsLock;
	SSinputs.NumLock = NumLock;
	kcg_copy_array_bool_30(SSinputs.KeyArray,KeyArray);
	SSinputs.EnterClicked = EnterClicked;
	SSinputs.SpaceClicked = SpaceClicked;
	SSinputs.BackspaceClicked = BackspaceClicked;
	
	VirtualKeyboard(&SSinputs, &(mem->SSctx));
	
	*KeyPressed = mem->SSctx.KeyPressed;
	*KeyCode = mem->SSctx.KeyCode;
	*KeyChar = mem->SSctx.KeyChar;
	kcg_copy_array_char_255_30(KeyLabels,mem->SSctx.KeyLabels);
	
}
