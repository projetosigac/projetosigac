/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_GraphTimed.c
 DESCRIPTION       : GraphTimed Widget wrapper: 
                     SCADE Display GraphTimed imported function  
 VERSION           : $Revision: 15609 $
 MODIFICATION DATE : $Date: 2014-11-28 11:25:03 +0100 (ven., 28 nov. 2014) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_GraphTimed_mem.h"
#include "GraphTimed.h"
#include "sgl.h"

void wrapper_GraphTimed_reset(wrapper_GraphTimed_mem* mem)
{
    GraphTimed_reset(&(mem->SSctx));
}

void wrapper_GraphTimed(SGLbool Reset,
                        SGLlong NbVisiblePoints,
                        SGLbool PauseInput,
                        SGLlong OffsetIn,
                        SGLlong (*CurrentCycle),
                        SGLlong (*Offset),
                        SGLlong (*VisiblePoints_out),
                        wrapper_GraphTimed_mem* mem)
{
	inC_GraphTimed SSinputs;
	
	SSinputs.Reset = Reset;
	SSinputs.NbVisiblePoints = NbVisiblePoints;
	SSinputs.PauseInput = PauseInput;
	SSinputs.OffsetIn = OffsetIn;
	
	GraphTimed(&SSinputs, &(mem->SSctx));
	
	*CurrentCycle = mem->SSctx.CurrentCycle;
	*Offset = mem->SSctx.Offset;
	*VisiblePoints_out = mem->SSctx.VisiblePoints_out;
}
