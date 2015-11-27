/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_Animations.c
 DESCRIPTION       : Animations Widget wrapper: 
                     SCADE Display Animations imported function  
 VERSION           : $Revision: 13759 $
 MODIFICATION DATE : $Date: 2014-05-27 11:48:03 +0200 (mar., 27 mai 2014) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_Animations_mem.h"
#include "Animations.h"
#include "sgl.h"

void wrapper_Animations_reset(wrapper_Animations_mem* mem)
{
	Animations_reset(&(mem->SSctx));
}

void wrapper_Animations(SGLbool StartForward,
                        SGLbool StartBackward,
                        SGLlong TimeLength,
                        SGLlong CycleDuration,
                        SGLlong Law,
                        SGLbool InverseResult,
                        SGLbool *End,
                        SGLfloat *ValueReal,
                        SGLlong *Opacity,
                        wrapper_Animations_mem* mem)
{
	inC_Animations SSinputs;
	
	
	SSinputs.StartForward = StartForward;
	SSinputs.StartBackward = StartBackward;
	SSinputs.TimeLength = TimeLength;
	SSinputs.CycleDuration = CycleDuration;
	SSinputs.Law = Law;
	SSinputs.InverseResult = InverseResult;
	Animations(&SSinputs, &(mem->SSctx));
	
	*End = mem->SSctx.End;
	*ValueReal = mem->SSctx.ValueReal;
	*Opacity = mem->SSctx.Opacity;
}
