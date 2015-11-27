/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_InfiniteKnob.c
 DESCRIPTION       : InfiniteKnob Widget wrapper: 
                     SCADE Display InfiniteKnob imported function  
 VERSION           : $Revision: 14875 $
 MODIFICATION DATE : $Date: 2014-09-30 14:04:42 +0200 (mar., 30 sept. 2014) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_InfiniteKnob_mem.h"
#include "InfiniteKnob.h"
#include "sgl.h"

void wrapper_InfiniteKnob_reset(wrapper_InfiniteKnob_mem* mem)
{
	InfiniteKnob_reset(&(mem->SSctx));
}

void wrapper_InfiniteKnob(SGLbool Enabled,
                        SGLbool MousePressed,
                        SGLbool MouseReleased,
                        SGLbool InsideButton,
                        SGLfloat AngleIn,
                        SGLfloat ValuePerRevolution,
                        SGLlong *KnobState,
                        SGLlong *State,
                        SGLfloat *AngleKnob,
                        SGLfloat *Value,
                        wrapper_InfiniteKnob_mem* mem)
{
	inC_InfiniteKnob SSinputs;
	
	
	SSinputs.Enabled = Enabled;
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseReleased = MouseReleased;
	SSinputs.InsideButton = InsideButton;
	SSinputs.AngleIn = AngleIn;
	SSinputs.ValuePerRevolution = ValuePerRevolution;
	
	InfiniteKnob(&SSinputs, &(mem->SSctx));
	
	*KnobState = mem->SSctx.KnobState;
	*State = mem->SSctx.State;
	*AngleKnob = mem->SSctx.AngleKnob;
	*Value = mem->SSctx.Value;
}
