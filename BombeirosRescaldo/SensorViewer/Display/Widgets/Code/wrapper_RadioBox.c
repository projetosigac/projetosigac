/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_RadioBox.c
 DESCRIPTION       : RadioBox Widget wrapper: 
                     SCADE Display RadioBox imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_RadioBox_mem.h"
#include "RadioBox.h"
#include "sgl.h"

void wrapper_RadioBox_reset(wrapper_RadioBox_mem* mem)
{
    RadioBox_reset(&(mem->SSctx));
}

void wrapper_RadioBox(SGLlong NumberOfItems, 
                      SGLbool StateChangeEmitTable[16], 
                      SGLlong SelectedItem,
                      SGLbool SetSelectedItem,
                      SGLbool (*SelectedTable)[16], 
                      SGLbool (*SelectedItemEmit), 
                      SGLlong (*SelectedItemValue), 
                      wrapper_RadioBox_mem* mem)
{
	inC_RadioBox SSinputs;
	
	SSinputs.NumberOfItems = NumberOfItems;
	kcg_copy_array_bool_16(SSinputs.StateChangeEmitTable,StateChangeEmitTable);
	SSinputs.SelectedItem = SelectedItem;
	SSinputs.SetSelectedItem = SetSelectedItem;
	
	RadioBox(&SSinputs, &(mem->SSctx));
	
	kcg_copy_array_bool_16(SelectedTable,mem->SSctx.SelectedTable);
	*SelectedItemEmit = 	mem->SSctx.SelectedItemEmit;
	*SelectedItemValue = 	mem->SSctx.SelectedItemValue;

}
