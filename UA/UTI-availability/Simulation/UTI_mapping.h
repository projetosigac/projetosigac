#ifndef UTI_SCSIM_MAPPING
#define UTI_SCSIM_MAPPING

#include "SmuTypes.h"
#include "UTI_type.h"

void _SCSIM_Mapping_Create();
static ControlUtils _SCSIM_BoolEntity_Control_Utils;
#include "UTI.h"
void _SCSIM_Mapping_UTI();

void* _SCSIM_Get_UTI_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize);


#endif /*UTI_SCSIM_MAPPING */
