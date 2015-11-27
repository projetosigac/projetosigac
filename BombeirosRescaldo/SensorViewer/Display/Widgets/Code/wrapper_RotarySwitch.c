/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_RotarySwitch.c
 DESCRIPTION       : RotarySwitch Widget wrapper: 
                     SCADE Display RotarySwitch imported function  
 VERSION           : $Revision: 14985 $
 MODIFICATION DATE : $Date: 2014-10-06 16:30:22 +0200 (lun., 06 oct. 2014) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_RotarySwitch_mem.h"
#include "RotarySwitch.h"
#include "sgl.h"

void wrapper_RotarySwitch_reset(wrapper_RotarySwitch_mem* mem)
{
    RotarySwitch_reset(&(mem->SSctx));
}

void wrapper_RotarySwitch(SGLbool Enabled, 
					SGLlong NbOfStates, 
					SGLbool InsideKnob, 
					SGLbool MousePressed, 
					SGLbool MouseReleased, 
					SGLfloat AngleArea, 
					SGLbool Inside,
					array_bool_8 (*BarsVisible),
					array_real_8 (*BarsAngle),
					SGLlong (*State),
					SGLfloat (*AngleKnob),
					SGLlong (*KnobState),
					SGLlong (*Value),
					wrapper_RotarySwitch_mem* mem)
{
    inC_RotarySwitch SSinputs;

	SSinputs.Enabled = Enabled;
	SSinputs.NbOfStates = NbOfStates;
	SSinputs.InsideKnob = InsideKnob;
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseReleased = MouseReleased;
	SSinputs.AngleArea = AngleArea;
	SSinputs.Inside = Inside;
	
	RotarySwitch(&SSinputs, &(mem->SSctx));
	
	kcg_copy_array_bool_8(BarsVisible,mem->SSctx.BarsVisible);
	kcg_copy_array_real_8(BarsAngle,mem->SSctx.BarsAngle);
	*State = mem->SSctx.State;
	*AngleKnob = mem->SSctx.AngleKnob;
	*KnobState = mem->SSctx.KnobState;
	*Value = mem->SSctx.Value;
}
