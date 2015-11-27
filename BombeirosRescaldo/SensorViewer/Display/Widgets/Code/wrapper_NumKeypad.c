/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_NumKeypad.c
 DESCRIPTION       : NumKeypad Widget wrapper: 
                     SCADE Display NumKeypad imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_NumKeypad_mem.h"
#include "NumKeypad.h"
#include "sgl.h"

void wrapper_NumKeypad_reset(wrapper_NumKeypad_mem* mem)
{
    NumKeypad_reset(&(mem->SSctx));
}

void wrapper_NumKeypad( SGLbool Reset,
						SGLbool KeyArray[14],
						SGLbool (*ValueChangeEmit),
						SGLfloat (*ValueChange),
						SGLbyte (*DisplayedString)[255],
						wrapper_NumKeypad_mem* mem)
{
	inC_NumKeypad SSinputs;
	
	SSinputs.Reset = Reset;
	kcg_copy_array_bool_14(SSinputs.KeyArray,KeyArray);
	
	NumKeypad(&SSinputs, &(mem->SSctx));
	
	*ValueChangeEmit = 	mem->SSctx.ValueChangeEmit;
	*ValueChange = 	mem->SSctx.ValueChange;
	kcg_copy_array_char_255(DisplayedString,mem->SSctx.DisplayedString);

}
