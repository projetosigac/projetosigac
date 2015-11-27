/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_ScrollBar.c
 DESCRIPTION       : ScrollBar Widget wrapper: 
                     SCADE Display ScrollBar imported function  
 VERSION           : $Revision: 11210 $
 MODIFICATION DATE : $Date: 2013-06-19 15:40:22 +0200 (mer., 19 juin 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_ScrollBar_mem.h"
#include "ScrollBar.h"
#include "sgl.h"

void wrapper_ScrollBar_reset(wrapper_ScrollBar_mem* mem)
{
    ScrollBar_reset(&(mem->SSctx));
}

void wrapper_ScrollBar(SGLfloat TickCoarse, 
					   SGLfloat TickFine, 
					   SGLfloat InitValue, 
					   SGLfloat MaxValue, 
					   SGLbool UpClicked, 
					   SGLbool DownClicked, 
					   SGLbool PgUpClicked, 
					   SGLbool PgDownClicked, 
					   SGLbool ResetValue,
					   SGLfloat MouseValue,
					   SGLbool MousePressed, 
					   SGLbool MouseReleased, 
					   SGLfloat (*Value), 
					   wrapper_ScrollBar_mem* mem)
{
    inC_ScrollBar SSinputs;
	
	SSinputs.TickCoarse = TickCoarse;
	SSinputs.TickFine = TickFine;
	SSinputs.InitValue = InitValue;
	SSinputs.MaxValue = MaxValue;
	SSinputs.UpClicked = UpClicked;
	SSinputs.DownClicked = DownClicked;
	SSinputs.PgUpClicked = PgUpClicked;
	SSinputs.PgDownClicked = PgDownClicked;
	SSinputs.ResetValue = ResetValue;
	SSinputs.MouseValue = MouseValue;
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseReleased = MouseReleased;
	
	ScrollBar(&SSinputs, &(mem->SSctx));
	
	*Value = 	mem->SSctx.Value;
}
