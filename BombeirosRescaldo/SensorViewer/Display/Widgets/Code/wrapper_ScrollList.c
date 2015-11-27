/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_ScrollList.c
 DESCRIPTION       : ScrollList Widget wrapper: 
                     SCADE Display ScrollList imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_ScrollList_mem.h"
#include "ScrollList.h"
#include "sgl.h"

void wrapper_ScrollList_reset(wrapper_ScrollList_mem* mem)
{
    ScrollList_reset(&(mem->SSctx));
}

void wrapper_ScrollList(SGLbool MousePressed, 
					SGLbool MouseReleased, 
					SGLlong MouseButton, 
					array_bool_9 MouseInside, 
					SGLbool ClickedUp, 
					SGLbool ClickedDown, 
					SGLlong NumberOfItems, 
					SGLlong NumberOfDisplayedItems, 
					array_char_255_16 LabelStringArray, 
					SGLlong SelectedItem, 
					SGLbool SetSelectedItem, 
					array_bool_16 EnableArray, 
					SGLlong EmitCondition, 
					SGLbool ClickedLift, 
					SGLbool ReleasedLift, 
					SGLfloat PositionClicked, 
					SGLlong (*SelectedItemValue),
					SGLbool (*SelectedItemEmit),
					array_char_255_9 (*LocalLabelStringArray),
					array_bool_9 (*EnableTable),
					array_bool_9 (*SelectedTable),
					SGLlong (*Offset),
					wrapper_ScrollList_mem* mem)
{
    inC_ScrollList SSinputs;

	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseReleased = MouseReleased;
	SSinputs.MouseButton = MouseButton;
	kcg_copy_array_bool_9(SSinputs.MouseInside,MouseInside);
	SSinputs.ClickedUp = ClickedUp;
	SSinputs.ClickedDown = ClickedDown;
	SSinputs.NumberOfItems = NumberOfItems;
	SSinputs.NumberOfDisplayedItems = NumberOfDisplayedItems;
	kcg_copy_array_char_255_16(SSinputs.LabelStringArray,LabelStringArray);
	SSinputs.SetSelectedItem = SetSelectedItem;
	SSinputs.SelectedItem = SelectedItem;
	kcg_copy_array_bool_16(SSinputs.EnableArray,EnableArray);
	SSinputs.EmitCondition = EmitCondition;
	SSinputs.ClickedLift = ClickedLift;
	SSinputs.ReleasedLift = ReleasedLift;
	SSinputs.PositionClicked = PositionClicked;
	
	ScrollList(&SSinputs, &(mem->SSctx));
	
	*SelectedItemValue = mem->SSctx.SelectedItemValue;
	*SelectedItemEmit = mem->SSctx.SelectedItemEmit;
	kcg_copy_array_char_255_9(LocalLabelStringArray,mem->SSctx.LocalLabelStringArray);
	kcg_copy_array_bool_9(EnableTable,mem->SSctx.EnableTable);
	kcg_copy_array_bool_9(SelectedTable,mem->SSctx.SelectedTable);
	*Offset = mem->SSctx.Offset;
}
