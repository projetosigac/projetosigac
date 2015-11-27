/*+ FILE DESCRIPTION -------------------------------------------------------
 DESCRIPTION       : Boolean Followed-By, for direct use in scade display 
 VERSION           : $Revision: 10833 $
 MODIFICATION DATE : $Date: 2013-05-20 17:59:53 +0200 (Mon, 20 May 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies.
---------------------------------------------------------------------------- +*/

#include "sgl.h"

#define NbVisiblePoints 100

extern void GraphNotTimed(
	SGLfloat Values1[NbVisiblePoints],
	SGLfloat Values2[NbVisiblePoints],
	SGLfloat Values3[NbVisiblePoints],
	SGLfloat Values4[NbVisiblePoints],
	SGLlong index,
	SGLfloat (*CrosslineValue1),
	SGLfloat (*CrosslineValue2),
	SGLfloat (*CrosslineValue3),
	SGLfloat (*CrosslineValue4)
);


void GraphNotTimed(
	SGLfloat Values1[NbVisiblePoints],
	SGLfloat Values2[NbVisiblePoints],
	SGLfloat Values3[NbVisiblePoints],
	SGLfloat Values4[NbVisiblePoints],
	SGLlong index,
	SGLfloat (*CrosslineValue1),
	SGLfloat (*CrosslineValue2),
	SGLfloat (*CrosslineValue3),
	SGLfloat (*CrosslineValue4)
){
	if(index<0 || index >=NbVisiblePoints){
		*CrosslineValue1=Values1[0];
		*CrosslineValue2=Values2[0];
		*CrosslineValue3=Values3[0];
		*CrosslineValue4=Values4[0];
	} else {
		*CrosslineValue1=Values1[index];
		*CrosslineValue2=Values2[index];
		*CrosslineValue3=Values3[index];
		*CrosslineValue4=Values4[index];
	}
	return;
}
