/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_PopUpMenu.c
 DESCRIPTION       : PopUpMenu Widget wrapper: 
                     SCADE Display PopUpMenu imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_PopUpMenu_mem.h"
#include "PopUpMenu.h"
#include "sgl.h"

void wrapper_PopUpMenu_reset(wrapper_PopUpMenu_mem* mem)
{
    PopUpMenu_reset(&(mem->SSctx));
}

void wrapper_PopUpMenu(SGLbool PopUpVisible, 
					   SGLbool SetPopUpVisible, 
					   SGLlong ClosingCondition,
					   SGLbool MouseEvent, 
					   SGLbool MouseInside, 
					   array_bool_16 MouseInsideItem, 
					   SGLlong KeyCode, 
					   SGLbool KeyPressed, 
					   SGLbool (*Visible),
					   SGLbool (*SelectedItemEmit),
					   SGLlong (*SelectedItemValue),
					   wrapper_PopUpMenu_mem* mem)
{
    inC_PopUpMenu SSinputs;
	
	SSinputs.PopUpVisible = PopUpVisible;
	SSinputs.SetPopUpVisible = SetPopUpVisible;
	SSinputs.ClosingCondition = ClosingCondition;
	SSinputs.MouseEvent = MouseEvent;
	SSinputs.MouseInside = MouseInside;
	SSinputs.KeyCode = KeyCode;
	SSinputs.KeyPressed = KeyPressed;
	kcg_copy_array_bool_16(SSinputs.MouseInsideItem,MouseInsideItem);
	
	PopUpMenu(&SSinputs, &(mem->SSctx));
	
	*Visible = mem->SSctx.Visible;
	*SelectedItemEmit = mem->SSctx.SelectedItemEmit;
	*SelectedItemValue = mem->SSctx.SelectedItemValue;
}
