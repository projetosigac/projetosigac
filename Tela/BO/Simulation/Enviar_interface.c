#include "Enviar_interface.h"
const int  rt_version = Srtv62;

const char* _SCSIM_CheckSum = "88f7b7cea0c5f3255dfda6f2a2803bfa";
const char* _SCSIM_SmuTypesCheckSum = "28e18c1b393c1cd143584174bcc1ba87";

/*******************************
 * Validity
 *******************************/
int valid(void * pHandle) {
	return 1;
}
int notvalid(void * pHandle) {
	return 0;
}

/*******************************
 * Simulation context
 *******************************/
inC_Enviar inputs_ctx;
static inC_Enviar inputs_ctx_restore;
static inC_Enviar inputs_ctx_execute;
outC_Enviar outputs_ctx;
static outC_Enviar outputs_ctx_restore;

/* separate_io: inputs instanciation */

/* separate_io: outputs instanciation */

static void _SCSIM_RestoreInterface(void) {
	inputs_ctx.enviar = inputs_ctx_restore.enviar;
	inputs_ctx.sinal_completo = inputs_ctx_restore.sinal_completo;
	kcg_copy_array_char_20(&(inputs_ctx.rg), &(inputs_ctx_restore.rg));
	kcg_copy_array_char_20(&(inputs_ctx.hora_fim_atend), &(inputs_ctx_restore.hora_fim_atend));
	kcg_copy_array_char_20(&(inputs_ctx.hora_ini_atend), &(inputs_ctx_restore.hora_ini_atend));
	kcg_copy_array_char_20(&(inputs_ctx.dt_fim_atend), &(inputs_ctx_restore.dt_fim_atend));
	kcg_copy_array_char_20(&(inputs_ctx.dt_ini_atend), &(inputs_ctx_restore.dt_ini_atend));
	kcg_copy_array_char_20(&(inputs_ctx.hora_fato), &(inputs_ctx_restore.hora_fato));
	kcg_copy_array_char_20(&(inputs_ctx.dt_fato), &(inputs_ctx_restore.dt_fato));
	kcg_copy_array_char_1000(&(inputs_ctx.description), &(inputs_ctx_restore.description));
	outputs_ctx = outputs_ctx_restore;

	/* separate_io: outputs restore */
}

static void _SCSIM_ExecuteInterface(void) {
	pSimulator->m_pfnAcquireValueMutex(pSimulator);
	inputs_ctx_execute.enviar = inputs_ctx.enviar;
	inputs_ctx_execute.sinal_completo = inputs_ctx.sinal_completo;
	kcg_copy_array_char_20(&(inputs_ctx_execute.rg), &(inputs_ctx.rg));
	kcg_copy_array_char_20(&(inputs_ctx_execute.hora_fim_atend), &(inputs_ctx.hora_fim_atend));
	kcg_copy_array_char_20(&(inputs_ctx_execute.hora_ini_atend), &(inputs_ctx.hora_ini_atend));
	kcg_copy_array_char_20(&(inputs_ctx_execute.dt_fim_atend), &(inputs_ctx.dt_fim_atend));
	kcg_copy_array_char_20(&(inputs_ctx_execute.dt_ini_atend), &(inputs_ctx.dt_ini_atend));
	kcg_copy_array_char_20(&(inputs_ctx_execute.hora_fato), &(inputs_ctx.hora_fato));
	kcg_copy_array_char_20(&(inputs_ctx_execute.dt_fato), &(inputs_ctx.dt_fato));
	kcg_copy_array_char_1000(&(inputs_ctx_execute.description), &(inputs_ctx.description));
	pSimulator->m_pfnReleaseValueMutex(pSimulator);
}

extern void _SCSIM_Mapping_Create();

/*******************************
 * Cyclic function encapsulation
 *******************************/
void SimInit(void) {
	/* Context initialization */
	_SCSIM_Mapping_Create();
	_SCSIM_RestoreInterface();
#ifdef EXTENDED_SIM
	BeforeSimInit();
#endif /* EXTENDED_SIM */
	Enviar_reset(&outputs_ctx);
#ifdef EXTENDED_SIM
	AfterSimInit();
#endif /* EXTENDED_SIM */
}

#ifdef EXTENDED_SIM
int GraphicalInputsConnected = 1;
#endif /* EXTENDED_SIM */
int SimStep(void) {
#ifdef EXTENDED_SIM
	if (GraphicalInputsConnected)
		BeforeSimStep();
#endif /* EXTENDED_SIM */
	_SCSIM_ExecuteInterface();
	Enviar(&inputs_ctx_execute, &outputs_ctx);
#ifdef EXTENDED_SIM
	AfterSimStep();
#endif /* EXTENDED_SIM */
	return 1;
}

void SimStop(void) {
#ifdef EXTENDED_SIM
	ExtendedSimStop();
#endif /* EXTENDED_SIM */
}

int SsmGetDumpSize(void) {
	int nSize = 0;
	nSize += sizeof(inC_Enviar);

/* separate_io: add (not in ctx) inputs size */

/* separate_io: add (not in ctx) outputs size */
	nSize += sizeof(outC_Enviar);
#ifdef EXTENDED_SIM
	nSize += ExtendedGetDumpSize();
#endif /* EXTENDED_SIM */
	return nSize;
}

void SsmGatherDumpData(char * pData) {
	char* pCurrent = pData;
	memcpy(pCurrent, &inputs_ctx, sizeof(inC_Enviar));
	pCurrent += sizeof(inC_Enviar);

	/* separate_io: dump (not in ctx) inputs */

	/* separate_io: dump (not in ctx) outputs */
	memcpy(pCurrent, &outputs_ctx, sizeof(outC_Enviar));
	pCurrent += sizeof(outC_Enviar);
#ifdef EXTENDED_SIM
	ExtendedGatherDumpData(pCurrent);
#endif /* EXTENDED_SIM */
}

void SsmRestoreDumpData(const char * pData) {
	const char* pCurrent = pData;
	memcpy(&inputs_ctx, pCurrent, sizeof(inC_Enviar));
	pCurrent += sizeof(inC_Enviar);

	/* separate_io: restore (not in ctx) inputs */

	/* separate_io: restore (not in ctx) outputs */
	memcpy(&outputs_ctx, pCurrent, sizeof(outC_Enviar));
	pCurrent += sizeof(outC_Enviar);
#ifdef EXTENDED_SIM
	ExtendedRestoreDumpData(pCurrent);
#endif /* EXTENDED_SIM */
}

const char * SsmGetCheckSum() {
	return _SCSIM_CheckSum;
}

const char * SsmGetSmuTypesCheckSum() {
	return _SCSIM_SmuTypesCheckSum;
}

void SsmUpdateValues(void) {
#ifdef EXTENDED_SIM
	UpdateValues();
#endif /* EXTENDED_SIM */
}

void SsmConnectExternalInputs(int bConnect) {
#ifdef EXTENDED_SIM
	GraphicalInputsConnected = bConnect;
#endif /* EXTENDED_SIM */
}

