/*+ FILE DESCRIPTION -------------------------------------------------------
 DESCRIPTION       : Boolean Followed-By, for direct use in scade display 
 VERSION           : $Revision: 11406 $
 MODIFICATION DATE : $Date: 2013-07-23 10:57:23 +0200 (Tue, 23 Jul 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies.
---------------------------------------------------------------------------- +*/

#include "sgl.h"

#ifndef _Delay_H_
#define _Delay_H_

typedef struct {
	unsigned char b;
} Delay_mem;

typedef struct{
	unsigned char b;
} RS_FlipFlop_mem;

#endif /* _Delay_H_ */



void Delay_reset(Delay_mem* mem)
{
	mem->b=0;
}

void Delay(SGLbool val, SGLbool *result, Delay_mem* mem)
{
	*result=mem->b;
	mem->b=val;
}

void identity_int(SGLlong val,SGLlong *result){*result=val;}
void identity_real(SGLfloat val,SGLfloat *result){*result=val;}
void identity_bool(SGLbool val,SGLbool *result){*result=val;}

void GetCycleDuration(SGLlong *period_ms){
	*period_ms = 33;
}

void RS_FlipFlop_reset(RS_FlipFlop_mem* mem)
{
	mem->b=0;
}
void RS_FlipFlop(SGLbool set, SGLbool reset, SGLbool *state, RS_FlipFlop_mem* mem){
	*state= set || (mem->b && (!reset));
	mem->b= *state;
}


#include <math.h>

SGLfloat wid_PowerR(SGLfloat P_Input,SGLlong Power){
	if(P_Input <= 0) return 1.0;
	return pow(P_Input,(SGLfloat) Power);
}

SGLfloat wid_CosR(SGLfloat Input){
	return cos(Input);
}
SGLfloat wid_SinR(SGLfloat Input){
	return sin(Input);
}
SGLfloat wid_aTanR(SGLfloat Input){
	return atan(Input);
}

SGLfloat wid_Atan2R(SGLfloat y, SGLfloat x){
	return (SGLfloat) atan2f((float) y,(float) x);
}

SGLfloat wid_SqrtR(SGLfloat v){
	return (SGLfloat) sqrtf((float) v);
}

SGLfloat wid_LogR(SGLfloat Input1){
	if(Input1<0.000001) {
		/*out of range*/
		return -6.0;
	}
	return log10(Input1);
}

