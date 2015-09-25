#include "SurgeryCounts_mapping.h"
#include "SurgeryCounts_interface.h"
#include "kcg_sensors.h"

/****************************************************************
 ** Boolean entity activation
 ****************************************************************/
static ControlUtils _SCSIM_BoolEntity_Control_Utils = {_SCSIM_BoolEntity_is_active};
/****************************************************************
 ** Mapping creation function
 ****************************************************************/
void _SCSIM_Mapping_Create() {
	_SCSIM_Mapping_SurgeryCounts();
	pSimulator->m_pfnFinalizeMapping(pSimulator);
}

/****************************************************************
 ** SurgeryCounts/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_SurgeryCounts() {
	pSimulator->m_pfnSetRoot(pSimulator, "SurgeryCounts/", &outputs_ctx, _SCSIM_Get_SurgeryCounts_Handle);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_real_Utils, 1, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_real_Utils, 2, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_real_Utils, 3, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 4, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "EmitToCDS", &_SCSIM_kcg_bool_Utils, 5, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "LayerVisible", &_SCSIM_kcg_bool_Utils, 6, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "availableOutput", &_SCSIM_kcg_real_Utils, 7, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "occupiedOutput", &_SCSIM_kcg_real_Utils, 8, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "totalOutput", &_SCSIM_kcg_real_Utils, 9, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "availableInput", &_SCSIM_kcg_real_Utils, 10, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "occupiedInput", &_SCSIM_kcg_real_Utils, 11, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "totalInput", &_SCSIM_kcg_real_Utils, 12, valid, 0, 0);
}

void* _SCSIM_Get_SurgeryCounts_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	switch (nHandleIdent) {
		case 1:
			return &(outputs_ctx._L1);
		case 2:
			return &(outputs_ctx._L2);
		case 3:
			return &(outputs_ctx._L3);
		case 4:
			return &(outputs_ctx._L4);
		case 5:
			return &(outputs_ctx.EmitToCDS);
		case 6:
			return &(outputs_ctx.LayerVisible);
		case 7:
			return &(outputs_ctx.availableOutput);
		case 8:
			return &(outputs_ctx.occupiedOutput);
		case 9:
			return &(outputs_ctx.totalOutput);
		case 10:
			return &(inputs_ctx.availableInput);
		case 11:
			return &(inputs_ctx.occupiedInput);
		case 12:
			return &(inputs_ctx.totalInput);
		default:
			break;
	}
	return 0;
}

