#include "UTI_interface.h"
const int  rt_version = Srtv62;

const char* _SCSIM_CheckSum = "3bb3bc8348e06484aa5a497a6a03cec0";
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
inC_UTI inputs_ctx;
static inC_UTI inputs_ctx_restore;
static inC_UTI inputs_ctx_execute;
outC_UTI outputs_ctx;
static outC_UTI outputs_ctx_restore;

/* separate_io: inputs instanciation */

/* separate_io: outputs instanciation */

static void _SCSIM_RestoreInterface(void) {
	inputs_ctx.AllocateBed1 = inputs_ctx_restore.AllocateBed1;
	inputs_ctx.ActivateBed2 = inputs_ctx_restore.ActivateBed2;
	inputs_ctx.ActivateBed3 = inputs_ctx_restore.ActivateBed3;
	inputs_ctx.ActivateBed4 = inputs_ctx_restore.ActivateBed4;
	inputs_ctx.ActivateBed5 = inputs_ctx_restore.ActivateBed5;
	inputs_ctx.ActivateBed6 = inputs_ctx_restore.ActivateBed6;
	inputs_ctx.ActivateBed7 = inputs_ctx_restore.ActivateBed7;
	inputs_ctx.ActivateBed8 = inputs_ctx_restore.ActivateBed8;
	inputs_ctx.ActivateBed1 = inputs_ctx_restore.ActivateBed1;
	inputs_ctx.AllocateBed2 = inputs_ctx_restore.AllocateBed2;
	inputs_ctx.AllocateBed4 = inputs_ctx_restore.AllocateBed4;
	inputs_ctx.AllocateBed3 = inputs_ctx_restore.AllocateBed3;
	inputs_ctx.AllocateBed6 = inputs_ctx_restore.AllocateBed6;
	inputs_ctx.AllocateBed5 = inputs_ctx_restore.AllocateBed5;
	inputs_ctx.AllocateBed7 = inputs_ctx_restore.AllocateBed7;
	inputs_ctx.AllocateBed8 = inputs_ctx_restore.AllocateBed8;
	outputs_ctx = outputs_ctx_restore;

	/* separate_io: outputs restore */
}

static void _SCSIM_ExecuteInterface(void) {
	pSimulator->m_pfnAcquireValueMutex(pSimulator);
	inputs_ctx_execute.AllocateBed1 = inputs_ctx.AllocateBed1;
	inputs_ctx_execute.ActivateBed2 = inputs_ctx.ActivateBed2;
	inputs_ctx_execute.ActivateBed3 = inputs_ctx.ActivateBed3;
	inputs_ctx_execute.ActivateBed4 = inputs_ctx.ActivateBed4;
	inputs_ctx_execute.ActivateBed5 = inputs_ctx.ActivateBed5;
	inputs_ctx_execute.ActivateBed6 = inputs_ctx.ActivateBed6;
	inputs_ctx_execute.ActivateBed7 = inputs_ctx.ActivateBed7;
	inputs_ctx_execute.ActivateBed8 = inputs_ctx.ActivateBed8;
	inputs_ctx_execute.ActivateBed1 = inputs_ctx.ActivateBed1;
	inputs_ctx_execute.AllocateBed2 = inputs_ctx.AllocateBed2;
	inputs_ctx_execute.AllocateBed4 = inputs_ctx.AllocateBed4;
	inputs_ctx_execute.AllocateBed3 = inputs_ctx.AllocateBed3;
	inputs_ctx_execute.AllocateBed6 = inputs_ctx.AllocateBed6;
	inputs_ctx_execute.AllocateBed5 = inputs_ctx.AllocateBed5;
	inputs_ctx_execute.AllocateBed7 = inputs_ctx.AllocateBed7;
	inputs_ctx_execute.AllocateBed8 = inputs_ctx.AllocateBed8;
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
	UTI_reset(&outputs_ctx);
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
	UTI(&inputs_ctx_execute, &outputs_ctx);
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
	nSize += sizeof(inC_UTI);

/* separate_io: add (not in ctx) inputs size */

/* separate_io: add (not in ctx) outputs size */
	nSize += sizeof(outC_UTI);
#ifdef EXTENDED_SIM
	nSize += ExtendedGetDumpSize();
#endif /* EXTENDED_SIM */
	return nSize;
}

void SsmGatherDumpData(char * pData) {
	char* pCurrent = pData;
	memcpy(pCurrent, &inputs_ctx, sizeof(inC_UTI));
	pCurrent += sizeof(inC_UTI);

	/* separate_io: dump (not in ctx) inputs */

	/* separate_io: dump (not in ctx) outputs */
	memcpy(pCurrent, &outputs_ctx, sizeof(outC_UTI));
	pCurrent += sizeof(outC_UTI);
#ifdef EXTENDED_SIM
	ExtendedGatherDumpData(pCurrent);
#endif /* EXTENDED_SIM */
}

void SsmRestoreDumpData(const char * pData) {
	const char* pCurrent = pData;
	memcpy(&inputs_ctx, pCurrent, sizeof(inC_UTI));
	pCurrent += sizeof(inC_UTI);

	/* separate_io: restore (not in ctx) inputs */

	/* separate_io: restore (not in ctx) outputs */
	memcpy(&outputs_ctx, pCurrent, sizeof(outC_UTI));
	pCurrent += sizeof(outC_UTI);
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

