/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_AlphaNumKeypad.c
 DESCRIPTION       : AlphaNumKeypad Widget wrapper: 
                     SCADE Display AlphaNumKeypad imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_AlphaNumKeypad_mem.h"
#include "AlphaNumKeypad.h"
#include "sgl.h"

void wrapper_AlphaNumKeypad_reset(wrapper_AlphaNumKeypad_mem* mem)
{
	AlphaNumKeypad_reset(&(mem->SSctx));
}

void wrapper_AlphaNumKeypad( SGLbool Reset,
                             SGLbyte LabelString[255],
                             SGLbool SetLabelString,
                             SGLbool KeyArray[13],
                             SGLbool CapsLock,
                             SGLfloat CyclePeriod,
                             SGLbool (*ValueChangeEmit),
                             SGLbyte (*ValueChange)[255],
                             SGLbool (*TimeOut),
                             wrapper_AlphaNumKeypad_mem* mem)
{
	inC_AlphaNumKeypad SSinputs;
	
	
	SSinputs.Reset = Reset;
	SSinputs.SetLabelString = SetLabelString;
	kcg_copy_array_char_255(SSinputs.LabelString,LabelString);
	kcg_copy_array_bool_13(SSinputs.KeyArray,KeyArray);
	SSinputs.CapsLock= CapsLock;
	SSinputs.CyclePeriod= CyclePeriod;
	
	AlphaNumKeypad(&SSinputs, &(mem->SSctx));
	
	*ValueChangeEmit = mem->SSctx.ValueChangeEmit;
	kcg_copy_array_char_255(ValueChange,mem->SSctx.ValueChange);
	*TimeOut = mem->SSctx.TimeOut;
}
