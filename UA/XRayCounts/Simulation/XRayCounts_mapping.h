#ifndef XRAYCOUNTS_SCSIM_MAPPING
#define XRAYCOUNTS_SCSIM_MAPPING

#include "SmuTypes.h"
#include "XRayCounts_type.h"

void _SCSIM_Mapping_Create();
static ControlUtils _SCSIM_BoolEntity_Control_Utils;
#include "XRayCounts.h"
void _SCSIM_Mapping_XRayCounts();

void* _SCSIM_Get_XRayCounts_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize);


#endif /*XRAYCOUNTS_SCSIM_MAPPING */
