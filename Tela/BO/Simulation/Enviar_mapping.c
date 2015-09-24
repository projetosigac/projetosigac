#include "Enviar_mapping.h"
#include "Enviar_interface.h"
#include "kcg_sensors.h"

/****************************************************************
 ** Boolean entity activation
 ****************************************************************/
static ControlUtils _SCSIM_BoolEntity_Control_Utils = {_SCSIM_BoolEntity_is_active};
/****************************************************************
 ** Mapping creation function
 ****************************************************************/
void _SCSIM_Mapping_Create() {
	_SCSIM_Mapping_Enviar();
	pSimulator->m_pfnFinalizeMapping(pSimulator);
}

/****************************************************************
 ** Enviar/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Enviar() {
	pSimulator->m_pfnSetRoot(pSimulator, "Enviar/", &outputs_ctx, _SCSIM_Get_Enviar_Handle);
	pSimulator->m_pfnAddLocal(pSimulator, "_L32", &_SCSIM_kcg_bool_Utils, 1, valid, 0, 0);
	pSimulator->m_pfnPushStateMachine(pSimulator, "SM1");
	pSimulator->m_pfnPushState(pSimulator, "Espera_Enviar", &_SCSIM_SSM_st_Espera_Enviar_SM1_Utils, 2);
	pSimulator->m_pfnPushStrongTransition(pSimulator, "1", &_SCSIM_SSM_TR_Espera_Enviar_1_SM1_Utils, 3);
	pSimulator->m_pfnPopStrongTransition(pSimulator);
	pSimulator->m_pfnPopState(pSimulator);
	pSimulator->m_pfnPushState(pSimulator, "Enviando", &_SCSIM_SSM_st_Enviando_SM1_Utils, 2);
	pSimulator->m_pfnAddLocal(pSimulator, "_L_kcg_clock", &_SCSIM_kcg_bool_Utils, 4, valid, 2, &_SCSIM_ClockActive_SSM_st_Enviando_SM1);
	pSimulator->m_pfnPushWeakTransition(pSimulator, "1", &_SCSIM_SSM_TR_Enviando_1_SM1_Utils, 5);
	pSimulator->m_pfnPopWeakTransition(pSimulator);
	pSimulator->m_pfnPopState(pSimulator);
	pSimulator->m_pfnPopStateMachine(pSimulator);
	pSimulator->m_pfnAddLocal(pSimulator, "envio_completo", &_SCSIM_kcg_bool_Utils, 6, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "enviar_ativo", &_SCSIM_kcg_bool_Utils, 7, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 8, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 9, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L24", &_SCSIM_String_Utils, 10, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L23", &_SCSIM_String_Utils, 11, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L22", &_SCSIM_String_Utils, 12, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L21", &_SCSIM_BigText_Utils, 13, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L20", &_SCSIM_struct__273_Utils, 14, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L19", &_SCSIM_String_Utils, 15, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L18", &_SCSIM_String_Utils, 16, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_String_Utils, 17, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_String_Utils, 18, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L25", &_SCSIM_kcg_bool_Utils, 19, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L31", &_SCSIM_kcg_bool_Utils, 20, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L33", &_SCSIM_kcg_bool_Utils, 21, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L35", &_SCSIM_kcg_int_Utils, 22, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L34", &_SCSIM_Name_Utils, 23, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BO_saida", &_SCSIM_Boletim_Utils, 24, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "saida_pronta", &_SCSIM_kcg_bool_Utils, 25, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Layer1Visible", &_SCSIM_kcg_bool_Utils, 26, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Layer1Active", &_SCSIM_kcg_bool_Utils, 27, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Emit2CDS", &_SCSIM_kcg_bool_Utils, 28, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "TextBtnEnviar", &_SCSIM_Name_Utils, 29, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "StringSize", &_SCSIM_kcg_int_Utils, 30, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "enviar", &_SCSIM_kcg_bool_Utils, 31, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "sinal_completo", &_SCSIM_kcg_bool_Utils, 32, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "rg", &_SCSIM_String_Utils, 33, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "hora_fim_atend", &_SCSIM_String_Utils, 34, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "hora_ini_atend", &_SCSIM_String_Utils, 35, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "dt_fim_atend", &_SCSIM_String_Utils, 36, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "dt_ini_atend", &_SCSIM_String_Utils, 37, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "hora_fato", &_SCSIM_String_Utils, 38, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "dt_fato", &_SCSIM_String_Utils, 39, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "description", &_SCSIM_BigText_Utils, 40, valid, 0, 0);
}

void* _SCSIM_Get_Enviar_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	switch (nHandleIdent) {
		case 1:
			return &(outputs_ctx._L32);
		case 2:
			return &(outputs_ctx.SM1_state_act);
		case 3:
			return &(outputs_ctx.SM1_fired_strong);
		case 4:
			return &(outputs_ctx.Enviando_weakb_clock_SM1);
		case 5:
			return &(outputs_ctx.SM1_fired);
		case 6:
			return &(outputs_ctx.envio_completo);
		case 7:
			return &(outputs_ctx.enviar_ativo);
		case 8:
			return &(outputs_ctx._L2);
		case 9:
			return &(outputs_ctx._L3);
		case 10:
			return &(outputs_ctx._L24);
		case 11:
			return &(outputs_ctx._L23);
		case 12:
			return &(outputs_ctx._L22);
		case 13:
			return &(outputs_ctx._L21);
		case 14:
			return &(outputs_ctx._L20);
		case 15:
			return &(outputs_ctx._L19);
		case 16:
			return &(outputs_ctx._L18);
		case 17:
			return &(outputs_ctx._L17);
		case 18:
			return &(outputs_ctx._L16);
		case 19:
			return &(outputs_ctx._L25);
		case 20:
			return &(outputs_ctx._L31);
		case 21:
			return &(outputs_ctx._L33);
		case 22:
			return &(outputs_ctx._L35);
		case 23:
			return &(outputs_ctx._L34);
		case 24:
			return &(outputs_ctx.BO_saida);
		case 25:
			return &(outputs_ctx.saida_pronta);
		case 26:
			return &(outputs_ctx.Layer1Visible);
		case 27:
			return &(outputs_ctx.Layer1Active);
		case 28:
			return &(outputs_ctx.Emit2CDS);
		case 29:
			return &(outputs_ctx.TextBtnEnviar);
		case 30:
			return &(outputs_ctx.StringSize);
		case 31:
			return &(inputs_ctx.enviar);
		case 32:
			return &(inputs_ctx.sinal_completo);
		case 33:
			return &(inputs_ctx.rg);
		case 34:
			return &(inputs_ctx.hora_fim_atend);
		case 35:
			return &(inputs_ctx.hora_ini_atend);
		case 36:
			return &(inputs_ctx.dt_fim_atend);
		case 37:
			return &(inputs_ctx.dt_ini_atend);
		case 38:
			return &(inputs_ctx.hora_fato);
		case 39:
			return &(inputs_ctx.dt_fato);
		case 40:
			return &(inputs_ctx.description);
		default:
			break;
	}
	return 0;
}

static int IsSSM_TR_Espera_Enviar_1_SM1Active(void * pHandle) {
	return *((SSM_TR_SM1*)pHandle) == SSM_TR_Espera_Enviar_1_SM1 ? 1 : 0;
}
ControlUtils _SCSIM_SSM_TR_Espera_Enviar_1_SM1_Utils = {IsSSM_TR_Espera_Enviar_1_SM1Active};

static int IsSSM_st_Espera_Enviar_SM1Active(void * pHandle) {
	return *((SSM_ST_SM1*)pHandle) == SSM_st_Espera_Enviar_SM1 ? 1 : 0;
}
ControlUtils _SCSIM_SSM_st_Espera_Enviar_SM1_Utils = {IsSSM_st_Espera_Enviar_SM1Active};

static int IsSSM_TR_Enviando_1_SM1Active(void * pHandle) {
	return *((SSM_TR_SM1*)pHandle) == SSM_TR_Enviando_1_SM1 ? 1 : 0;
}
ControlUtils _SCSIM_SSM_TR_Enviando_1_SM1_Utils = {IsSSM_TR_Enviando_1_SM1Active};

static int IsSSM_st_Enviando_SM1Active(void * pHandle) {
	return *((SSM_ST_SM1*)pHandle) == SSM_st_Enviando_SM1 ? 1 : 0;
}
ControlUtils _SCSIM_SSM_st_Enviando_SM1_Utils = {IsSSM_st_Enviando_SM1Active};

static int _SCSIM_ClockActive_SSM_st_Enviando_SM1(void* clock) {
return *(kcg_bool*)clock == SSM_st_Enviando_SM1 ? 1 : 0;
}
