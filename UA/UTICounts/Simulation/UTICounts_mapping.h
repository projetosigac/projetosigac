#ifndef UTICOUNTS_SCSIM_MAPPING
#define UTICOUNTS_SCSIM_MAPPING

#include "SmuTypes.h"
#include "UTICounts_type.h"

void _SCSIM_Mapping_Create();
static ControlUtils _SCSIM_BoolEntity_Control_Utils;
#include "UTICounts.h"
void _SCSIM_Mapping_UTICounts();

void* _SCSIM_Get_UTICounts_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize);


#endif /*UTICOUNTS_SCSIM_MAPPING */
