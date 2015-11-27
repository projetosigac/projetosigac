/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_Knob.c
 DESCRIPTION       : Knob Widget wrapper: 
                     SCADE Display Knob imported function  
 VERSION           : $Revision: 14875 $
 MODIFICATION DATE : $Date: 2014-09-30 14:04:42 +0200 (mar., 30 sept. 2014) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_Knob_mem.h"
#include "Knob.h"
#include "sgl.h"

void wrapper_Knob_reset(wrapper_Knob_mem* mem)
{
	Knob_reset(&(mem->SSctx));
}

void wrapper_Knob(SGLbool Enabled,
                        SGLbool MousePressed,
                        SGLbool MouseReleased,
                        SGLfloat AngleMouse,
                        SGLbool Inside,
                        SGLbool InsideKnob,
                        SGLfloat AngleMin,
                        SGLfloat AngleMax,
                        SGLfloat Min,
                        SGLfloat Max,
                        SGLlong *State,
                        SGLfloat *AngleKnob,
                        SGLlong *KnobState,
                        SGLfloat *Value,
                        wrapper_Knob_mem* mem)
{
	inC_Knob SSinputs;
	
	SSinputs.Enabled = Enabled;
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseReleased = MouseReleased;
	SSinputs.AngleMouse = AngleMouse;
	SSinputs.Inside = Inside;
	SSinputs.InsideKnob = InsideKnob;
	SSinputs.AngleMin = AngleMin;
	SSinputs.AngleMax = AngleMax;
	SSinputs.Min = Min;
	SSinputs.Max = Max;
	
	Knob(&SSinputs, &(mem->SSctx));
	
	*State = mem->SSctx.State;
	*AngleKnob = mem->SSctx.AngleKnob;
	*KnobState = mem->SSctx.KnobState;
	*Value = mem->SSctx.Value;
}
