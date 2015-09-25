#ifndef SURGERYCOUNTS_SCSIM_MAPPING
#define SURGERYCOUNTS_SCSIM_MAPPING

#include "SmuTypes.h"
#include "SurgeryCounts_type.h"

void _SCSIM_Mapping_Create();
static ControlUtils _SCSIM_BoolEntity_Control_Utils;
#include "SurgeryCounts.h"
void _SCSIM_Mapping_SurgeryCounts();

void* _SCSIM_Get_SurgeryCounts_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize);


#endif /*SURGERYCOUNTS_SCSIM_MAPPING */
