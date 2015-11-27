/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : wrapper_GesturePinchExpandRotate.c
 DESCRIPTION       : GesturePinchExpandRotate Widget wrapper: 
                     SCADE Display GesturePinchExpandRotate imported function  
 VERSION           : $Revision: 13759 $
 MODIFICATION DATE : $Date: 2014-05-27 11:48:03 +0200 (mar., 27 mai 2014) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wrapper_GesturePinchExpandRotate_mem.h"
#include "GesturePinchExpandRotate.h"
#include "sgl.h"

void wrapper_GesturePinchExpandRotate_reset(wrapper_GesturePinchExpandRotate_mem* mem)
{
	GesturePinchExpandRotate_reset(&(mem->SSctx));
}

void wrapper_GesturePinchExpandRotate(SGLbool MousePressed1,
                        SGLbool MouseInside1,
                        SGLbool MouseReleased1,
                        SGLbool MousePressed2,
                        SGLbool MouseReleased2,
                        SGLbool MouseInside2,
                        SGLfloat PosX1,
                        SGLfloat PosY1,
                        SGLfloat PosX2,
                        SGLfloat PosY2,
                        SGLfloat MinimalTranslation,
                        SGLfloat MinimalRotation,
                        SGLfloat CyclePeriod,
                        SGLfloat TimeOutDelay,
                        SGLbool *Rotating,
                        SGLbool *Zooming,
                        SGLfloat *ZoomFactor,
                        SGLfloat *RotateAngle,
                        wrapper_GesturePinchExpandRotate_mem* mem)
{
	inC_GesturePinchExpandRotate SSinputs;
	
	
	SSinputs.MousePressed1 = MousePressed1;
	SSinputs.MouseInside1 = MouseInside1;
	SSinputs.MouseReleased1 = MouseReleased1;
	SSinputs.MousePressed2 = MousePressed2;
	SSinputs.MouseReleased2 = MouseReleased2;
	SSinputs.MouseInside2 = MouseInside2;
	SSinputs.PosX1 = PosX1;
	SSinputs.PosY1 = PosY1;
	SSinputs.PosX2 = PosX2;
	SSinputs.PosY2 = PosY2;
	SSinputs.MinimalTranslation = MinimalTranslation;
	SSinputs.MinimalRotation = MinimalRotation;
	SSinputs.CyclePeriod = CyclePeriod;
	SSinputs.TimeOutDelay = TimeOutDelay;
	
	GesturePinchExpandRotate(&SSinputs, &(mem->SSctx));
	
	*Rotating = mem->SSctx.Rotating;
	*Zooming = mem->SSctx.Zooming;
	*ZoomFactor = mem->SSctx.ZoomFactor;
	*RotateAngle = mem->SSctx.RotateAngle;
}
