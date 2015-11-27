/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_ComboBox.c
 DESCRIPTION       : ComboBox Widget wrapper: 
                     SCADE Display ComboBox imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_ComboBox_mem.h"
#include "ComboBox.h"
#include "sgl.h"

void wrapper_ComboBox_reset(wrapper_ComboBox_mem* mem)
{
    ComboBox_reset(&(mem->SSctx));
}

void wrapper_ComboBox(SGLbool Enable, 
						SGLbool ToggleEmit, 
						SGLbool ToggleState, 
						SGLbool ScrollListSelected, 
						SGLbool AbortKey, 
						SGLbool OpenCenter,
						SGLbool (*ScrollListVisible), 
						SGLbool (*SetToggleBack), 
						wrapper_ComboBox_mem* mem)
{
    inC_ComboBox SSinputs;
	
	SSinputs.Enable = Enable;
	SSinputs.ToggleEmit = ToggleEmit;
	SSinputs.ToggleState = ToggleState;
	SSinputs.ScrollListSelected = ScrollListSelected;
	SSinputs.AbortKey = AbortKey;
	SSinputs.OpenCenter = OpenCenter;
	
	ComboBox(&SSinputs, &(mem->SSctx));
	
	*ScrollListVisible = 	mem->SSctx.ScrollListVisible;
	*SetToggleBack = 	mem->SSctx.SetToggleBack;
}
