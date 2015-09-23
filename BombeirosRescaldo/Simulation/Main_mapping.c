#include "Main_mapping.h"
#include "Main_interface.h"
#include "kcg_sensors.h"

/****************************************************************
 ** Boolean entity activation
 ****************************************************************/
static ControlUtils _SCSIM_BoolEntity_Control_Utils = {_SCSIM_BoolEntity_is_active};
/****************************************************************
 ** Mapping creation function
 ****************************************************************/
void _SCSIM_Mapping_Create() {
	_SCSIM_Mapping_Main();
	pSimulator->m_pfnFinalizeMapping(pSimulator);
}

/****************************************************************
 ** Main/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_Main() {
	pSimulator->m_pfnSetRoot(pSimulator, "Main/", &outputs_ctx, _SCSIM_Get_Main_Handle);
	/*<< Inlined InitDF*/
	pSimulator->m_pfnPushInstance(pSimulator, "InitDF", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ReqLayerVisible", &_SCSIM_kcg_bool_Utils, 1, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ReqLayerActive", &_SCSIM_kcg_bool_Utils, 2, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 3, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 4, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 5, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 6, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 7, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ReqLayerVisible", &_SCSIM_kcg_bool_Utils, 8, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ReqLayerActive", &_SCSIM_kcg_bool_Utils, 9, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "EmitToCDS", &_SCSIM_kcg_bool_Utils, 10, valid, 0, 0);
}

void* _SCSIM_Get_Main_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	switch (nHandleIdent) {
		case 1:
			return &(outputs_ctx.ReqLayerVisible_1);
		case 2:
			return &(outputs_ctx.ReqLayerActive_1);
		case 3:
			return &(outputs_ctx._L2_1);
		case 4:
			return &(outputs_ctx._L1_1);
		case 5:
			return &(outputs_ctx._L1);
		case 6:
			return &(outputs_ctx._L2);
		case 7:
			return &(outputs_ctx._L3);
		case 8:
			return &(outputs_ctx.ReqLayerVisible);
		case 9:
			return &(outputs_ctx.ReqLayerActive);
		case 10:
			return &(outputs_ctx.EmitToCDS);
		default:
			break;
	}
	return 0;
}

