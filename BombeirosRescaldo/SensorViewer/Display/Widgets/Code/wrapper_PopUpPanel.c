/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_PopUpPanel.c
 DESCRIPTION       : PopUpPanel Widget wrapper: 
                     SCADE Display PopUpPanel imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_PopUpPanel_mem.h"
#include "PopUpPanel.h"
#include "sgl.h"

void wrapper_PopUpPanel_reset(wrapper_PopUpPanel_mem* mem)
{
    PopUpPanel_reset(&(mem->SSctx));
}

void wrapper_PopUpPanel(SGLbool PopUpVisible, 
						SGLbool SetPopUpVisible, 
						SGLbool MouseInside, 
						SGLbool MousePressed, 
						SGLlong ClosingCondition, 
						SGLbool (*Visibility), 
						wrapper_PopUpPanel_mem* mem)
{
    inC_PopUpPanel SSinputs;
	
	SSinputs.PopUpVisible = PopUpVisible;
	SSinputs.SetPopUpVisible = SetPopUpVisible;
	SSinputs.MouseInside = MouseInside;
	SSinputs.MousePressed = MousePressed;
	SSinputs.ClosingCondition = ClosingCondition;
	
	PopUpPanel(&SSinputs, &(mem->SSctx));
	
	*Visibility = 	mem->SSctx.Visibility;
}
