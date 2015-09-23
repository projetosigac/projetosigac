#ifndef MAIN_SCSIM_MAPPING
#define MAIN_SCSIM_MAPPING

#include "SmuTypes.h"
#include "Main_type.h"

void _SCSIM_Mapping_Create();
static ControlUtils _SCSIM_BoolEntity_Control_Utils;
#include "Main.h"
void _SCSIM_Mapping_Main();

void* _SCSIM_Get_Main_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize);


#endif /*MAIN_SCSIM_MAPPING */
