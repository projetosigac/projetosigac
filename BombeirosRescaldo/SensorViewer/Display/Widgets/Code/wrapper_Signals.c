/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_Signals.c
 DESCRIPTION       : Signals Widget wrapper: 
                     SCADE Display Signals imported function  
 VERSION           : $Revision: 13764 $
 MODIFICATION DATE : $Date: 2014-05-27 14:50:00 +0200 (mar., 27 mai 2014) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_Signals_mem.h"
#include "Signals.h"
#include "sgl.h"

void wrapper_Signals_reset(wrapper_Signals_mem* mem)
{
    Signals_reset(&(mem->SSctx));
}

void wrapper_Signals(   SGLlong Kind,
						SGLfloat DutyCycle,
						SGLfloat Offset, 
						SGLfloat Min, 
						SGLfloat Max, 
						SGLlong PeriodCycles,
						SGLfloat (*Value), 
						SGLbool (*IsRealTime), 
						wrapper_Signals_mem* mem)
{
    inC_Signals SSinputs;
	
	SSinputs.Kind = Kind;
	SSinputs.DutyCycle = DutyCycle;
	SSinputs.Offset = Offset;
	SSinputs.Min = Min;
	SSinputs.Max = Max;
	SSinputs.PeriodCycles = PeriodCycles;
	
	Signals(&SSinputs, &(mem->SSctx));
	
	*Value = 	mem->SSctx.Value;
	*IsRealTime = 	mem->SSctx.IsRealTime;
}
