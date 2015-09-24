#ifndef ENVIAR_SCSIM_MAPPING
#define ENVIAR_SCSIM_MAPPING

#include "SmuTypes.h"
#include "Enviar_type.h"

void _SCSIM_Mapping_Create();
static ControlUtils _SCSIM_BoolEntity_Control_Utils;
#include "Enviar.h"
void _SCSIM_Mapping_Enviar();

void* _SCSIM_Get_Enviar_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize);

extern ControlUtils _SCSIM_SSM_TR_Espera_Enviar_1_SM1_Utils;
extern ControlUtils _SCSIM_SSM_st_Espera_Enviar_SM1_Utils;
extern ControlUtils _SCSIM_SSM_TR_Enviando_1_SM1_Utils;
extern ControlUtils _SCSIM_SSM_st_Enviando_SM1_Utils;
static int _SCSIM_ClockActive_SSM_st_Enviando_SM1(void*);

#endif /*ENVIAR_SCSIM_MAPPING */
