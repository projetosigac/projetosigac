/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_GestureDrag.c
 DESCRIPTION       : GestureDrag Widget wrapper: 
                     SCADE Display GestureDrag imported function  
 VERSION           : $Revision: 13759 $
 MODIFICATION DATE : $Date: 2014-05-27 11:48:03 +0200 (mar., 27 mai 2014) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_GestureDrag_mem.h"
#include "GestureDrag.h"
#include "sgl.h"

void wrapper_GestureDrag_reset(wrapper_GestureDrag_mem* mem)
{
	GestureDrag_reset(&(mem->SSctx));
}

void wrapper_GestureDrag(SGLbool MousePressed,
                        SGLbool MouseReleased,
                        SGLbool MouseInside,
                        SGLfloat PosXPx,
                        SGLfloat PosYPx,
                        SGLfloat PosTolerance,
                        SGLbool *Dragging,
                        SGLfloat *PosStartX,
                        SGLfloat *PosStartY,
                        SGLfloat *DisplacementX,
                        SGLfloat *DisplacementY,
                        wrapper_GestureDrag_mem* mem)
{
	inC_GestureDrag SSinputs;
	
	
	SSinputs.MousePressed = MousePressed;
	SSinputs.MouseReleased = MouseReleased;
	SSinputs.MouseInside = MouseInside;
	SSinputs.PosXPx = PosXPx;
	SSinputs.PosYPx = PosYPx;
	SSinputs.PosTolerance = PosTolerance;
	
	GestureDrag(&SSinputs, &(mem->SSctx));
	
	*Dragging = mem->SSctx.Dragging;
	*PosStartX = mem->SSctx.PosStartX;
	*PosStartY = mem->SSctx.PosStartY;
	*DisplacementX = mem->SSctx.DisplacementX;
	*DisplacementY = mem->SSctx.DisplacementY;
}
