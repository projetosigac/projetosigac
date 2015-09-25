#include "UTI_mapping.h"
#include "UTI_interface.h"
#include "kcg_sensors.h"

/****************************************************************
 ** Boolean entity activation
 ****************************************************************/
static ControlUtils _SCSIM_BoolEntity_Control_Utils = {_SCSIM_BoolEntity_is_active};
/****************************************************************
 ** Mapping creation function
 ****************************************************************/
void _SCSIM_Mapping_Create() {
	_SCSIM_Mapping_UTI();
	pSimulator->m_pfnFinalizeMapping(pSimulator);
}

/****************************************************************
 ** UTI/ mapping function
 ****************************************************************/
void _SCSIM_Mapping_UTI() {
	pSimulator->m_pfnSetRoot(pSimulator, "UTI/", &outputs_ctx, _SCSIM_Get_UTI_Handle);
	/*<< Inlined Bed*/
	pSimulator->m_pfnPushInstance(pSimulator, "Bed", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedActive", &_SCSIM_kcg_int_Utils, 1, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedAllocated", &_SCSIM_kcg_int_Utils, 2, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor", &_SCSIM_kcg_int_Utils, 3, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Activate", &_SCSIM_kcg_bool_Utils, 4, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Allocate", &_SCSIM_kcg_bool_Utils, 5, valid, 0, 0);
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 6, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 7, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 8, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 9, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 10, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 11, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "2", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 12, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 13, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 14, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 15, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 16, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 17, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 18, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 19, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 20, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 21, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_kcg_bool_Utils, 22, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_kcg_int_Utils, 23, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_kcg_int_Utils, 24, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_kcg_int_Utils, 25, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_kcg_int_Utils, 26, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L10", &_SCSIM_kcg_int_Utils, 27, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_kcg_int_Utils, 28, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_kcg_int_Utils, 29, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_kcg_int_Utils, 30, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_kcg_int_Utils, 31, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_kcg_int_Utils, 32, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_int_Utils, 33, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_kcg_bool_Utils, 34, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Bed*/
	pSimulator->m_pfnPushInstance(pSimulator, "Bed", "4", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedActive", &_SCSIM_kcg_int_Utils, 35, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedAllocated", &_SCSIM_kcg_int_Utils, 36, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor", &_SCSIM_kcg_int_Utils, 37, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Activate", &_SCSIM_kcg_bool_Utils, 38, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Allocate", &_SCSIM_kcg_bool_Utils, 39, valid, 0, 0);
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 40, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 41, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 42, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 43, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 44, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 45, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "2", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 46, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 47, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 48, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 49, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 50, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 51, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 52, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 53, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 54, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 55, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_kcg_bool_Utils, 56, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_kcg_int_Utils, 57, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_kcg_int_Utils, 58, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_kcg_int_Utils, 59, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_kcg_int_Utils, 60, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L10", &_SCSIM_kcg_int_Utils, 61, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_kcg_int_Utils, 62, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_kcg_int_Utils, 63, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_kcg_int_Utils, 64, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_kcg_int_Utils, 65, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_kcg_int_Utils, 66, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_int_Utils, 67, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_kcg_bool_Utils, 68, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Bed*/
	pSimulator->m_pfnPushInstance(pSimulator, "Bed", "5", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedActive", &_SCSIM_kcg_int_Utils, 69, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedAllocated", &_SCSIM_kcg_int_Utils, 70, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor", &_SCSIM_kcg_int_Utils, 71, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Activate", &_SCSIM_kcg_bool_Utils, 72, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Allocate", &_SCSIM_kcg_bool_Utils, 73, valid, 0, 0);
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 74, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 75, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 76, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 77, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 78, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 79, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "2", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 80, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 81, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 82, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 83, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 84, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 85, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 86, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 87, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 88, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 89, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_kcg_bool_Utils, 90, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_kcg_int_Utils, 91, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_kcg_int_Utils, 92, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_kcg_int_Utils, 93, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_kcg_int_Utils, 94, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L10", &_SCSIM_kcg_int_Utils, 95, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_kcg_int_Utils, 96, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_kcg_int_Utils, 97, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_kcg_int_Utils, 98, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_kcg_int_Utils, 99, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_kcg_int_Utils, 100, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_int_Utils, 101, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_kcg_bool_Utils, 102, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Bed*/
	pSimulator->m_pfnPushInstance(pSimulator, "Bed", "6", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedActive", &_SCSIM_kcg_int_Utils, 103, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedAllocated", &_SCSIM_kcg_int_Utils, 104, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor", &_SCSIM_kcg_int_Utils, 105, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Activate", &_SCSIM_kcg_bool_Utils, 106, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Allocate", &_SCSIM_kcg_bool_Utils, 107, valid, 0, 0);
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 108, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 109, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 110, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 111, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 112, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 113, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "2", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 114, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 115, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 116, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 117, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 118, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 119, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 120, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 121, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 122, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 123, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_kcg_bool_Utils, 124, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_kcg_int_Utils, 125, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_kcg_int_Utils, 126, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_kcg_int_Utils, 127, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_kcg_int_Utils, 128, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L10", &_SCSIM_kcg_int_Utils, 129, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_kcg_int_Utils, 130, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_kcg_int_Utils, 131, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_kcg_int_Utils, 132, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_kcg_int_Utils, 133, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_kcg_int_Utils, 134, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_int_Utils, 135, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_kcg_bool_Utils, 136, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Bed*/
	pSimulator->m_pfnPushInstance(pSimulator, "Bed", "7", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedActive", &_SCSIM_kcg_int_Utils, 137, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedAllocated", &_SCSIM_kcg_int_Utils, 138, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor", &_SCSIM_kcg_int_Utils, 139, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Activate", &_SCSIM_kcg_bool_Utils, 140, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Allocate", &_SCSIM_kcg_bool_Utils, 141, valid, 0, 0);
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 142, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 143, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 144, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 145, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 146, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 147, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "2", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 148, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 149, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 150, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 151, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 152, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 153, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 154, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 155, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 156, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 157, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_kcg_bool_Utils, 158, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_kcg_int_Utils, 159, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_kcg_int_Utils, 160, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_kcg_int_Utils, 161, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_kcg_int_Utils, 162, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L10", &_SCSIM_kcg_int_Utils, 163, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_kcg_int_Utils, 164, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_kcg_int_Utils, 165, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_kcg_int_Utils, 166, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_kcg_int_Utils, 167, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_kcg_int_Utils, 168, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_int_Utils, 169, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_kcg_bool_Utils, 170, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Bed*/
	pSimulator->m_pfnPushInstance(pSimulator, "Bed", "9", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedActive", &_SCSIM_kcg_int_Utils, 171, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedAllocated", &_SCSIM_kcg_int_Utils, 172, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor", &_SCSIM_kcg_int_Utils, 173, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Activate", &_SCSIM_kcg_bool_Utils, 174, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Allocate", &_SCSIM_kcg_bool_Utils, 175, valid, 0, 0);
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 176, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 177, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 178, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 179, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 180, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 181, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "2", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 182, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 183, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 184, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 185, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 186, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 187, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 188, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 189, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 190, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 191, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_kcg_bool_Utils, 192, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_kcg_int_Utils, 193, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_kcg_int_Utils, 194, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_kcg_int_Utils, 195, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_kcg_int_Utils, 196, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L10", &_SCSIM_kcg_int_Utils, 197, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_kcg_int_Utils, 198, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_kcg_int_Utils, 199, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_kcg_int_Utils, 200, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_kcg_int_Utils, 201, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_kcg_int_Utils, 202, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_int_Utils, 203, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_kcg_bool_Utils, 204, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Bed*/
	pSimulator->m_pfnPushInstance(pSimulator, "Bed", "11", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedActive", &_SCSIM_kcg_int_Utils, 205, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedAllocated", &_SCSIM_kcg_int_Utils, 206, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor", &_SCSIM_kcg_int_Utils, 207, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Activate", &_SCSIM_kcg_bool_Utils, 208, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Allocate", &_SCSIM_kcg_bool_Utils, 209, valid, 0, 0);
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 210, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 211, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 212, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 213, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 214, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 215, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "2", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 216, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 217, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 218, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 219, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 220, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 221, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 222, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 223, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 224, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 225, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_kcg_bool_Utils, 226, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_kcg_int_Utils, 227, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_kcg_int_Utils, 228, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_kcg_int_Utils, 229, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_kcg_int_Utils, 230, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L10", &_SCSIM_kcg_int_Utils, 231, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_kcg_int_Utils, 232, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_kcg_int_Utils, 233, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_kcg_int_Utils, 234, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_kcg_int_Utils, 235, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_kcg_int_Utils, 236, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_int_Utils, 237, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_kcg_bool_Utils, 238, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Bed*/
	pSimulator->m_pfnPushInstance(pSimulator, "Bed", "12", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedActive", &_SCSIM_kcg_int_Utils, 239, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedAllocated", &_SCSIM_kcg_int_Utils, 240, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor", &_SCSIM_kcg_int_Utils, 241, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Activate", &_SCSIM_kcg_bool_Utils, 242, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Allocate", &_SCSIM_kcg_bool_Utils, 243, valid, 0, 0);
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 244, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 245, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 246, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 247, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 248, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 249, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined Toggle*/
	pSimulator->m_pfnPushInstance(pSimulator, "Toggle", "2", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Output", &_SCSIM_kcg_bool_Utils, 250, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input", &_SCSIM_kcg_bool_Utils, 251, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 252, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 253, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 254, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 255, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 256, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 257, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_bool_Utils, 258, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_kcg_bool_Utils, 259, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_kcg_bool_Utils, 260, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_kcg_int_Utils, 261, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_kcg_int_Utils, 262, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_kcg_int_Utils, 263, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_kcg_int_Utils, 264, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L10", &_SCSIM_kcg_int_Utils, 265, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_kcg_int_Utils, 266, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_kcg_int_Utils, 267, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_kcg_int_Utils, 268, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_kcg_int_Utils, 269, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_kcg_int_Utils, 270, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_int_Utils, 271, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_kcg_bool_Utils, 272, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_kcg_int_Utils, 273, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_int_Utils, 274, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_int_Utils, 275, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L10", &_SCSIM_kcg_int_Utils, 276, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_kcg_int_Utils, 277, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_kcg_int_Utils, 278, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_kcg_int_Utils, 279, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_kcg_int_Utils, 280, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L15", &_SCSIM_kcg_int_Utils, 281, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_kcg_int_Utils, 282, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_kcg_int_Utils, 283, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L18", &_SCSIM_kcg_int_Utils, 284, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L19", &_SCSIM_kcg_int_Utils, 285, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L20", &_SCSIM_kcg_int_Utils, 286, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L21", &_SCSIM_kcg_int_Utils, 287, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L25", &_SCSIM_kcg_int_Utils, 288, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L26", &_SCSIM_kcg_int_Utils, 289, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L27", &_SCSIM_kcg_int_Utils, 290, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L31", &_SCSIM_kcg_int_Utils, 291, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L32", &_SCSIM_kcg_int_Utils, 292, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L33", &_SCSIM_kcg_int_Utils, 293, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L34", &_SCSIM_kcg_int_Utils, 294, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L35", &_SCSIM_kcg_int_Utils, 295, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L36", &_SCSIM_kcg_int_Utils, 296, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L45", &_SCSIM_kcg_bool_Utils, 297, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L46", &_SCSIM_kcg_bool_Utils, 298, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L47", &_SCSIM_kcg_bool_Utils, 299, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L48", &_SCSIM_kcg_bool_Utils, 300, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L49", &_SCSIM_kcg_bool_Utils, 301, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L50", &_SCSIM_kcg_bool_Utils, 302, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L51", &_SCSIM_kcg_bool_Utils, 303, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L52", &_SCSIM_kcg_int_Utils, 304, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L54", &_SCSIM_kcg_bool_Utils, 305, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L55", &_SCSIM_kcg_bool_Utils, 306, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L56", &_SCSIM_kcg_bool_Utils, 307, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L57", &_SCSIM_kcg_bool_Utils, 308, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L58", &_SCSIM_kcg_bool_Utils, 309, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L59", &_SCSIM_kcg_bool_Utils, 310, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L60", &_SCSIM_kcg_bool_Utils, 311, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L61", &_SCSIM_kcg_bool_Utils, 312, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L62", &_SCSIM_kcg_bool_Utils, 313, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L66", &_SCSIM_kcg_int_Utils, 314, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L67", &_SCSIM_kcg_int_Utils, 315, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L68", &_SCSIM_kcg_bool_Utils, 316, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L69", &_SCSIM_kcg_bool_Utils, 317, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L70", &_SCSIM_kcg_real_Utils, 318, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L71", &_SCSIM_kcg_real_Utils, 319, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L72", &_SCSIM_kcg_real_Utils, 320, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ActiveBedsCount", &_SCSIM_kcg_real_Utils, 321, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "AllocatedBedsCount", &_SCSIM_kcg_real_Utils, 322, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor1", &_SCSIM_kcg_int_Utils, 323, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "FreeBedsCount", &_SCSIM_kcg_real_Utils, 324, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor2", &_SCSIM_kcg_int_Utils, 325, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor3", &_SCSIM_kcg_int_Utils, 326, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor4", &_SCSIM_kcg_int_Utils, 327, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor5", &_SCSIM_kcg_int_Utils, 328, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor6", &_SCSIM_kcg_int_Utils, 329, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor7", &_SCSIM_kcg_int_Utils, 330, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "BedColor8", &_SCSIM_kcg_int_Utils, 331, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "EmitToCDS", &_SCSIM_kcg_bool_Utils, 332, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "LayerVisible", &_SCSIM_kcg_bool_Utils, 333, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "AllocateBed1", &_SCSIM_kcg_bool_Utils, 334, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "ActivateBed2", &_SCSIM_kcg_bool_Utils, 335, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "ActivateBed3", &_SCSIM_kcg_bool_Utils, 336, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "ActivateBed4", &_SCSIM_kcg_bool_Utils, 337, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "ActivateBed5", &_SCSIM_kcg_bool_Utils, 338, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "ActivateBed6", &_SCSIM_kcg_bool_Utils, 339, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "ActivateBed7", &_SCSIM_kcg_bool_Utils, 340, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "ActivateBed8", &_SCSIM_kcg_bool_Utils, 341, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "ActivateBed1", &_SCSIM_kcg_bool_Utils, 342, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "AllocateBed2", &_SCSIM_kcg_bool_Utils, 343, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "AllocateBed4", &_SCSIM_kcg_bool_Utils, 344, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "AllocateBed3", &_SCSIM_kcg_bool_Utils, 345, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "AllocateBed6", &_SCSIM_kcg_bool_Utils, 346, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "AllocateBed5", &_SCSIM_kcg_bool_Utils, 347, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "AllocateBed7", &_SCSIM_kcg_bool_Utils, 348, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "AllocateBed8", &_SCSIM_kcg_bool_Utils, 349, valid, 0, 0);
}

void* _SCSIM_Get_UTI_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	switch (nHandleIdent) {
		case 1:
			return &(outputs_ctx.BedActive_1);
		case 2:
			return &(outputs_ctx.BedAllocated_1);
		case 3:
			return &(outputs_ctx.BedColor_1);
		case 4:
			return &(outputs_ctx.Activate_1);
		case 5:
			return &(outputs_ctx.Allocate_1);
		case 6:
			return &(outputs_ctx.Output_1_1);
		case 7:
			return &(outputs_ctx.Input_1_1);
		case 8:
			return &(outputs_ctx._L4_1_1);
		case 9:
			return &(outputs_ctx._L1_1_1);
		case 10:
			return &(outputs_ctx._L2_1_1);
		case 11:
			return &(outputs_ctx._L3_1_1);
		case 12:
			return &(outputs_ctx.Output_2_1);
		case 13:
			return &(outputs_ctx.Input_2_1);
		case 14:
			return &(outputs_ctx._L4_2_1);
		case 15:
			return &(outputs_ctx._L1_2_1);
		case 16:
			return &(outputs_ctx._L2_2_1);
		case 17:
			return &(outputs_ctx._L3_2_1);
		case 18:
			return &(outputs_ctx._L1_1);
		case 19:
			return &(outputs_ctx._L2_1);
		case 20:
			return &(outputs_ctx._L3_1);
		case 21:
			return &(outputs_ctx._L4_1);
		case 22:
			return &(outputs_ctx._L5_1);
		case 23:
			return &(outputs_ctx._L6_1);
		case 24:
			return &(outputs_ctx._L7_1);
		case 25:
			return &(outputs_ctx._L8_1);
		case 26:
			return &(outputs_ctx._L9_1);
		case 27:
			return &(outputs_ctx._L10_1);
		case 28:
			return &(outputs_ctx._L11_1);
		case 29:
			return &(outputs_ctx._L12_1);
		case 30:
			return &(outputs_ctx._L13_1);
		case 31:
			return &(outputs_ctx._L16_1);
		case 32:
			return &(outputs_ctx._L15_1);
		case 33:
			return &(outputs_ctx._L14_1);
		case 34:
			return &(outputs_ctx._L17_1);
		case 35:
			return &(outputs_ctx.BedActive_4);
		case 36:
			return &(outputs_ctx.BedAllocated_4);
		case 37:
			return &(outputs_ctx.BedColor_4);
		case 38:
			return &(outputs_ctx.Activate_4);
		case 39:
			return &(outputs_ctx.Allocate_4);
		case 40:
			return &(outputs_ctx.Output_1_4);
		case 41:
			return &(outputs_ctx.Input_1_4);
		case 42:
			return &(outputs_ctx._L4_1_4);
		case 43:
			return &(outputs_ctx._L1_1_4);
		case 44:
			return &(outputs_ctx._L2_1_4);
		case 45:
			return &(outputs_ctx._L3_1_4);
		case 46:
			return &(outputs_ctx.Output_2_4);
		case 47:
			return &(outputs_ctx.Input_2_4);
		case 48:
			return &(outputs_ctx._L4_2_4);
		case 49:
			return &(outputs_ctx._L1_2_4);
		case 50:
			return &(outputs_ctx._L2_2_4);
		case 51:
			return &(outputs_ctx._L3_2_4);
		case 52:
			return &(outputs_ctx._L1_4);
		case 53:
			return &(outputs_ctx._L2_4);
		case 54:
			return &(outputs_ctx._L3_4);
		case 55:
			return &(outputs_ctx._L4_4);
		case 56:
			return &(outputs_ctx._L5_4);
		case 57:
			return &(outputs_ctx._L6_4);
		case 58:
			return &(outputs_ctx._L7_4);
		case 59:
			return &(outputs_ctx._L8_4);
		case 60:
			return &(outputs_ctx._L9_4);
		case 61:
			return &(outputs_ctx._L10_4);
		case 62:
			return &(outputs_ctx._L11_4);
		case 63:
			return &(outputs_ctx._L12_4);
		case 64:
			return &(outputs_ctx._L13_4);
		case 65:
			return &(outputs_ctx._L16_4);
		case 66:
			return &(outputs_ctx._L15_4);
		case 67:
			return &(outputs_ctx._L14_4);
		case 68:
			return &(outputs_ctx._L17_4);
		case 69:
			return &(outputs_ctx.BedActive_5);
		case 70:
			return &(outputs_ctx.BedAllocated_5);
		case 71:
			return &(outputs_ctx.BedColor_5);
		case 72:
			return &(outputs_ctx.Activate_5);
		case 73:
			return &(outputs_ctx.Allocate_5);
		case 74:
			return &(outputs_ctx.Output_1_5);
		case 75:
			return &(outputs_ctx.Input_1_5);
		case 76:
			return &(outputs_ctx._L4_1_5);
		case 77:
			return &(outputs_ctx._L1_1_5);
		case 78:
			return &(outputs_ctx._L2_1_5);
		case 79:
			return &(outputs_ctx._L3_1_5);
		case 80:
			return &(outputs_ctx.Output_2_5);
		case 81:
			return &(outputs_ctx.Input_2_5);
		case 82:
			return &(outputs_ctx._L4_2_5);
		case 83:
			return &(outputs_ctx._L1_2_5);
		case 84:
			return &(outputs_ctx._L2_2_5);
		case 85:
			return &(outputs_ctx._L3_2_5);
		case 86:
			return &(outputs_ctx._L1_5);
		case 87:
			return &(outputs_ctx._L2_5);
		case 88:
			return &(outputs_ctx._L3_5);
		case 89:
			return &(outputs_ctx._L4_5);
		case 90:
			return &(outputs_ctx._L5_5);
		case 91:
			return &(outputs_ctx._L6_5);
		case 92:
			return &(outputs_ctx._L7_5);
		case 93:
			return &(outputs_ctx._L8_5);
		case 94:
			return &(outputs_ctx._L9_5);
		case 95:
			return &(outputs_ctx._L10_5);
		case 96:
			return &(outputs_ctx._L11_5);
		case 97:
			return &(outputs_ctx._L12_5);
		case 98:
			return &(outputs_ctx._L13_5);
		case 99:
			return &(outputs_ctx._L16_5);
		case 100:
			return &(outputs_ctx._L15_5);
		case 101:
			return &(outputs_ctx._L14_5);
		case 102:
			return &(outputs_ctx._L17_5);
		case 103:
			return &(outputs_ctx.BedActive_6);
		case 104:
			return &(outputs_ctx.BedAllocated_6);
		case 105:
			return &(outputs_ctx.BedColor_6);
		case 106:
			return &(outputs_ctx.Activate_6);
		case 107:
			return &(outputs_ctx.Allocate_6);
		case 108:
			return &(outputs_ctx.Output_1_6);
		case 109:
			return &(outputs_ctx.Input_1_6);
		case 110:
			return &(outputs_ctx._L4_1_6);
		case 111:
			return &(outputs_ctx._L1_1_6);
		case 112:
			return &(outputs_ctx._L2_1_6);
		case 113:
			return &(outputs_ctx._L3_1_6);
		case 114:
			return &(outputs_ctx.Output_2_6);
		case 115:
			return &(outputs_ctx.Input_2_6);
		case 116:
			return &(outputs_ctx._L4_2_6);
		case 117:
			return &(outputs_ctx._L1_2_6);
		case 118:
			return &(outputs_ctx._L2_2_6);
		case 119:
			return &(outputs_ctx._L3_2_6);
		case 120:
			return &(outputs_ctx._L1_6);
		case 121:
			return &(outputs_ctx._L2_6);
		case 122:
			return &(outputs_ctx._L3_6);
		case 123:
			return &(outputs_ctx._L4_6);
		case 124:
			return &(outputs_ctx._L5_6);
		case 125:
			return &(outputs_ctx._L6_6);
		case 126:
			return &(outputs_ctx._L7_6);
		case 127:
			return &(outputs_ctx._L8_6);
		case 128:
			return &(outputs_ctx._L9_6);
		case 129:
			return &(outputs_ctx._L10_6);
		case 130:
			return &(outputs_ctx._L11_6);
		case 131:
			return &(outputs_ctx._L12_6);
		case 132:
			return &(outputs_ctx._L13_6);
		case 133:
			return &(outputs_ctx._L16_6);
		case 134:
			return &(outputs_ctx._L15_6);
		case 135:
			return &(outputs_ctx._L14_6);
		case 136:
			return &(outputs_ctx._L17_6);
		case 137:
			return &(outputs_ctx.BedActive_7);
		case 138:
			return &(outputs_ctx.BedAllocated_7);
		case 139:
			return &(outputs_ctx.BedColor_7);
		case 140:
			return &(outputs_ctx.Activate_7);
		case 141:
			return &(outputs_ctx.Allocate_7);
		case 142:
			return &(outputs_ctx.Output_1_7);
		case 143:
			return &(outputs_ctx.Input_1_7);
		case 144:
			return &(outputs_ctx._L4_1_7);
		case 145:
			return &(outputs_ctx._L1_1_7);
		case 146:
			return &(outputs_ctx._L2_1_7);
		case 147:
			return &(outputs_ctx._L3_1_7);
		case 148:
			return &(outputs_ctx.Output_2_7);
		case 149:
			return &(outputs_ctx.Input_2_7);
		case 150:
			return &(outputs_ctx._L4_2_7);
		case 151:
			return &(outputs_ctx._L1_2_7);
		case 152:
			return &(outputs_ctx._L2_2_7);
		case 153:
			return &(outputs_ctx._L3_2_7);
		case 154:
			return &(outputs_ctx._L1_7);
		case 155:
			return &(outputs_ctx._L2_7);
		case 156:
			return &(outputs_ctx._L3_7);
		case 157:
			return &(outputs_ctx._L4_7);
		case 158:
			return &(outputs_ctx._L5_7);
		case 159:
			return &(outputs_ctx._L6_7);
		case 160:
			return &(outputs_ctx._L7_7);
		case 161:
			return &(outputs_ctx._L8_7);
		case 162:
			return &(outputs_ctx._L9_7);
		case 163:
			return &(outputs_ctx._L10_7);
		case 164:
			return &(outputs_ctx._L11_7);
		case 165:
			return &(outputs_ctx._L12_7);
		case 166:
			return &(outputs_ctx._L13_7);
		case 167:
			return &(outputs_ctx._L16_7);
		case 168:
			return &(outputs_ctx._L15_7);
		case 169:
			return &(outputs_ctx._L14_7);
		case 170:
			return &(outputs_ctx._L17_7);
		case 171:
			return &(outputs_ctx.BedActive_9);
		case 172:
			return &(outputs_ctx.BedAllocated_9);
		case 173:
			return &(outputs_ctx.BedColor_9);
		case 174:
			return &(outputs_ctx.Activate_9);
		case 175:
			return &(outputs_ctx.Allocate_9);
		case 176:
			return &(outputs_ctx.Output_1_9);
		case 177:
			return &(outputs_ctx.Input_1_9);
		case 178:
			return &(outputs_ctx._L4_1_9);
		case 179:
			return &(outputs_ctx._L1_1_9);
		case 180:
			return &(outputs_ctx._L2_1_9);
		case 181:
			return &(outputs_ctx._L3_1_9);
		case 182:
			return &(outputs_ctx.Output_2_9);
		case 183:
			return &(outputs_ctx.Input_2_9);
		case 184:
			return &(outputs_ctx._L4_2_9);
		case 185:
			return &(outputs_ctx._L1_2_9);
		case 186:
			return &(outputs_ctx._L2_2_9);
		case 187:
			return &(outputs_ctx._L3_2_9);
		case 188:
			return &(outputs_ctx._L1_9);
		case 189:
			return &(outputs_ctx._L2_9);
		case 190:
			return &(outputs_ctx._L3_9);
		case 191:
			return &(outputs_ctx._L4_9);
		case 192:
			return &(outputs_ctx._L5_9);
		case 193:
			return &(outputs_ctx._L6_9);
		case 194:
			return &(outputs_ctx._L7_9);
		case 195:
			return &(outputs_ctx._L8_9);
		case 196:
			return &(outputs_ctx._L9_9);
		case 197:
			return &(outputs_ctx._L10_9);
		case 198:
			return &(outputs_ctx._L11_9);
		case 199:
			return &(outputs_ctx._L12_9);
		case 200:
			return &(outputs_ctx._L13_9);
		case 201:
			return &(outputs_ctx._L16_9);
		case 202:
			return &(outputs_ctx._L15_9);
		case 203:
			return &(outputs_ctx._L14_9);
		case 204:
			return &(outputs_ctx._L17_9);
		case 205:
			return &(outputs_ctx.BedActive_11);
		case 206:
			return &(outputs_ctx.BedAllocated_11);
		case 207:
			return &(outputs_ctx.BedColor_11);
		case 208:
			return &(outputs_ctx.Activate_11);
		case 209:
			return &(outputs_ctx.Allocate_11);
		case 210:
			return &(outputs_ctx.Output_1_11);
		case 211:
			return &(outputs_ctx.Input_1_11);
		case 212:
			return &(outputs_ctx._L4_1_11);
		case 213:
			return &(outputs_ctx._L1_1_11);
		case 214:
			return &(outputs_ctx._L2_1_11);
		case 215:
			return &(outputs_ctx._L3_1_11);
		case 216:
			return &(outputs_ctx.Output_2_11);
		case 217:
			return &(outputs_ctx.Input_2_11);
		case 218:
			return &(outputs_ctx._L4_2_11);
		case 219:
			return &(outputs_ctx._L1_2_11);
		case 220:
			return &(outputs_ctx._L2_2_11);
		case 221:
			return &(outputs_ctx._L3_2_11);
		case 222:
			return &(outputs_ctx._L1_11);
		case 223:
			return &(outputs_ctx._L2_11);
		case 224:
			return &(outputs_ctx._L3_11);
		case 225:
			return &(outputs_ctx._L4_11);
		case 226:
			return &(outputs_ctx._L5_11);
		case 227:
			return &(outputs_ctx._L6_11);
		case 228:
			return &(outputs_ctx._L7_11);
		case 229:
			return &(outputs_ctx._L8_11);
		case 230:
			return &(outputs_ctx._L9_11);
		case 231:
			return &(outputs_ctx._L10_11);
		case 232:
			return &(outputs_ctx._L11_11);
		case 233:
			return &(outputs_ctx._L12_11);
		case 234:
			return &(outputs_ctx._L13_11);
		case 235:
			return &(outputs_ctx._L16_11);
		case 236:
			return &(outputs_ctx._L15_11);
		case 237:
			return &(outputs_ctx._L14_11);
		case 238:
			return &(outputs_ctx._L17_11);
		case 239:
			return &(outputs_ctx.BedActive_12);
		case 240:
			return &(outputs_ctx.BedAllocated_12);
		case 241:
			return &(outputs_ctx.BedColor_12);
		case 242:
			return &(outputs_ctx.Activate_12);
		case 243:
			return &(outputs_ctx.Allocate_12);
		case 244:
			return &(outputs_ctx.Output_1_12);
		case 245:
			return &(outputs_ctx.Input_1_12);
		case 246:
			return &(outputs_ctx._L4_1_12);
		case 247:
			return &(outputs_ctx._L1_1_12);
		case 248:
			return &(outputs_ctx._L2_1_12);
		case 249:
			return &(outputs_ctx._L3_1_12);
		case 250:
			return &(outputs_ctx.Output_2_12);
		case 251:
			return &(outputs_ctx.Input_2_12);
		case 252:
			return &(outputs_ctx._L4_2_12);
		case 253:
			return &(outputs_ctx._L1_2_12);
		case 254:
			return &(outputs_ctx._L2_2_12);
		case 255:
			return &(outputs_ctx._L3_2_12);
		case 256:
			return &(outputs_ctx._L1_12);
		case 257:
			return &(outputs_ctx._L2_12);
		case 258:
			return &(outputs_ctx._L3_12);
		case 259:
			return &(outputs_ctx._L4_12);
		case 260:
			return &(outputs_ctx._L5_12);
		case 261:
			return &(outputs_ctx._L6_12);
		case 262:
			return &(outputs_ctx._L7_12);
		case 263:
			return &(outputs_ctx._L8_12);
		case 264:
			return &(outputs_ctx._L9_12);
		case 265:
			return &(outputs_ctx._L10_12);
		case 266:
			return &(outputs_ctx._L11_12);
		case 267:
			return &(outputs_ctx._L12_12);
		case 268:
			return &(outputs_ctx._L13_12);
		case 269:
			return &(outputs_ctx._L16_12);
		case 270:
			return &(outputs_ctx._L15_12);
		case 271:
			return &(outputs_ctx._L14_12);
		case 272:
			return &(outputs_ctx._L17_12);
		case 273:
			return &(outputs_ctx._L3);
		case 274:
			return &(outputs_ctx._L2);
		case 275:
			return &(outputs_ctx._L1);
		case 276:
			return &(outputs_ctx._L10);
		case 277:
			return &(outputs_ctx._L11);
		case 278:
			return &(outputs_ctx._L12);
		case 279:
			return &(outputs_ctx._L13);
		case 280:
			return &(outputs_ctx._L14);
		case 281:
			return &(outputs_ctx._L15);
		case 282:
			return &(outputs_ctx._L16);
		case 283:
			return &(outputs_ctx._L17);
		case 284:
			return &(outputs_ctx._L18);
		case 285:
			return &(outputs_ctx._L19);
		case 286:
			return &(outputs_ctx._L20);
		case 287:
			return &(outputs_ctx._L21);
		case 288:
			return &(outputs_ctx._L25);
		case 289:
			return &(outputs_ctx._L26);
		case 290:
			return &(outputs_ctx._L27);
		case 291:
			return &(outputs_ctx._L31);
		case 292:
			return &(outputs_ctx._L32);
		case 293:
			return &(outputs_ctx._L33);
		case 294:
			return &(outputs_ctx._L34);
		case 295:
			return &(outputs_ctx._L35);
		case 296:
			return &(outputs_ctx._L36);
		case 297:
			return &(outputs_ctx._L45);
		case 298:
			return &(outputs_ctx._L46);
		case 299:
			return &(outputs_ctx._L47);
		case 300:
			return &(outputs_ctx._L48);
		case 301:
			return &(outputs_ctx._L49);
		case 302:
			return &(outputs_ctx._L50);
		case 303:
			return &(outputs_ctx._L51);
		case 304:
			return &(outputs_ctx._L52);
		case 305:
			return &(outputs_ctx._L54);
		case 306:
			return &(outputs_ctx._L55);
		case 307:
			return &(outputs_ctx._L56);
		case 308:
			return &(outputs_ctx._L57);
		case 309:
			return &(outputs_ctx._L58);
		case 310:
			return &(outputs_ctx._L59);
		case 311:
			return &(outputs_ctx._L60);
		case 312:
			return &(outputs_ctx._L61);
		case 313:
			return &(outputs_ctx._L62);
		case 314:
			return &(outputs_ctx._L66);
		case 315:
			return &(outputs_ctx._L67);
		case 316:
			return &(outputs_ctx._L68);
		case 317:
			return &(outputs_ctx._L69);
		case 318:
			return &(outputs_ctx._L70);
		case 319:
			return &(outputs_ctx._L71);
		case 320:
			return &(outputs_ctx._L72);
		case 321:
			return &(outputs_ctx.ActiveBedsCount);
		case 322:
			return &(outputs_ctx.AllocatedBedsCount);
		case 323:
			return &(outputs_ctx.BedColor1);
		case 324:
			return &(outputs_ctx.FreeBedsCount);
		case 325:
			return &(outputs_ctx.BedColor2);
		case 326:
			return &(outputs_ctx.BedColor3);
		case 327:
			return &(outputs_ctx.BedColor4);
		case 328:
			return &(outputs_ctx.BedColor5);
		case 329:
			return &(outputs_ctx.BedColor6);
		case 330:
			return &(outputs_ctx.BedColor7);
		case 331:
			return &(outputs_ctx.BedColor8);
		case 332:
			return &(outputs_ctx.EmitToCDS);
		case 333:
			return &(outputs_ctx.LayerVisible);
		case 334:
			return &(inputs_ctx.AllocateBed1);
		case 335:
			return &(inputs_ctx.ActivateBed2);
		case 336:
			return &(inputs_ctx.ActivateBed3);
		case 337:
			return &(inputs_ctx.ActivateBed4);
		case 338:
			return &(inputs_ctx.ActivateBed5);
		case 339:
			return &(inputs_ctx.ActivateBed6);
		case 340:
			return &(inputs_ctx.ActivateBed7);
		case 341:
			return &(inputs_ctx.ActivateBed8);
		case 342:
			return &(inputs_ctx.ActivateBed1);
		case 343:
			return &(inputs_ctx.AllocateBed2);
		case 344:
			return &(inputs_ctx.AllocateBed4);
		case 345:
			return &(inputs_ctx.AllocateBed3);
		case 346:
			return &(inputs_ctx.AllocateBed6);
		case 347:
			return &(inputs_ctx.AllocateBed5);
		case 348:
			return &(inputs_ctx.AllocateBed7);
		case 349:
			return &(inputs_ctx.AllocateBed8);
		default:
			break;
	}
	return 0;
}

