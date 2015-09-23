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
	pSimulator->m_pfnPushInstance(pSimulator, "InitDF", "", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ReqLayerVisible", &_SCSIM_kcg_bool_Utils, 1, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ReqLayerActive", &_SCSIM_kcg_bool_Utils, 2, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_kcg_bool_Utils, 3, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 4, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined ViewString*/
	pSimulator->m_pfnPushInstance(pSimulator, "ViewString", "", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Result", &_SCSIM_array_char_512_Utils, 5, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Button", &_SCSIM_kcg_bool_Utils, 6, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "ValueString", &_SCSIM_String_Utils, 7, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "BaseString", &_SCSIM_String_Utils, 8, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_String_Utils, 9, valid, 0, 0);
	/*<< Inlined ConcatString*/
	pSimulator->m_pfnPushInstance(pSimulator, "ConcatString", "", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ResultString", &_SCSIM_array_char_512_Utils, 10, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "StringValue", &_SCSIM_String_Utils, 11, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "StringName", &_SCSIM_String_Utils, 12, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_String_Utils, 13, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_array_char_10_Utils, 14, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_array_char_522_Utils, 15, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_array_char_512_Utils, 16, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_String_Utils, 17, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_String_Utils, 18, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_String_Utils, 19, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 20, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_String_Utils, 21, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_array_char_512_Utils, 22, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined GetValueFromTxtWidget*/
	pSimulator->m_pfnPushInstance(pSimulator, "GetValueFromTxtWidget", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "WidgetString", &_SCSIM_String_Utils, 23, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "WidgetStringLength", &_SCSIM_kcg_int_Utils, 24, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "EvtString", &_SCSIM_String_Utils, 25, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Notify", &_SCSIM_kcg_bool_Utils, 26, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "EvtStringLength", &_SCSIM_kcg_int_Utils, 27, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_String_Utils, 28, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_kcg_int_Utils, 29, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_String_Utils, 30, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_kcg_bool_Utils, 31, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_kcg_int_Utils, 32, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L13", &_SCSIM_kcg_int_Utils, 33, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L14", &_SCSIM_String_Utils, 34, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined ViewString*/
	pSimulator->m_pfnPushInstance(pSimulator, "ViewString", "1", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Result", &_SCSIM_array_char_512_Utils, 35, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Button", &_SCSIM_kcg_bool_Utils, 36, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "ValueString", &_SCSIM_String_Utils, 37, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "BaseString", &_SCSIM_String_Utils, 38, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_String_Utils, 39, valid, 0, 0);
	/*<< Inlined ConcatString*/
	pSimulator->m_pfnPushInstance(pSimulator, "ConcatString", "", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ResultString", &_SCSIM_array_char_512_Utils, 40, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "StringValue", &_SCSIM_String_Utils, 41, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "StringName", &_SCSIM_String_Utils, 42, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_String_Utils, 43, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_array_char_10_Utils, 44, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_array_char_522_Utils, 45, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_array_char_512_Utils, 46, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_String_Utils, 47, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_String_Utils, 48, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_String_Utils, 49, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 50, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_String_Utils, 51, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_array_char_512_Utils, 52, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined ViewString*/
	pSimulator->m_pfnPushInstance(pSimulator, "ViewString", "3", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Result", &_SCSIM_array_char_512_Utils, 53, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Button", &_SCSIM_kcg_bool_Utils, 54, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "ValueString", &_SCSIM_String_Utils, 55, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "BaseString", &_SCSIM_String_Utils, 56, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_String_Utils, 57, valid, 0, 0);
	/*<< Inlined ConcatString*/
	pSimulator->m_pfnPushInstance(pSimulator, "ConcatString", "", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ResultString", &_SCSIM_array_char_512_Utils, 58, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "StringValue", &_SCSIM_String_Utils, 59, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "StringName", &_SCSIM_String_Utils, 60, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_String_Utils, 61, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_array_char_10_Utils, 62, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_array_char_522_Utils, 63, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_array_char_512_Utils, 64, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_String_Utils, 65, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_String_Utils, 66, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_String_Utils, 67, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 68, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_String_Utils, 69, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_array_char_512_Utils, 70, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	/*<< Inlined ViewString*/
	pSimulator->m_pfnPushInstance(pSimulator, "ViewString", "4", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "Result", &_SCSIM_array_char_512_Utils, 71, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Button", &_SCSIM_kcg_bool_Utils, 72, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "ValueString", &_SCSIM_String_Utils, 73, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "BaseString", &_SCSIM_String_Utils, 74, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_String_Utils, 75, valid, 0, 0);
	/*<< Inlined ConcatString*/
	pSimulator->m_pfnPushInstance(pSimulator, "ConcatString", "", 0, 0, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ResultString", &_SCSIM_array_char_512_Utils, 76, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "StringValue", &_SCSIM_String_Utils, 77, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "StringName", &_SCSIM_String_Utils, 78, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_String_Utils, 79, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_array_char_10_Utils, 80, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_array_char_522_Utils, 81, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_array_char_512_Utils, 82, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_String_Utils, 83, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnAddLocal(pSimulator, "_L3", &_SCSIM_String_Utils, 84, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L2", &_SCSIM_String_Utils, 85, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L1", &_SCSIM_kcg_bool_Utils, 86, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L4", &_SCSIM_String_Utils, 87, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_array_char_512_Utils, 88, valid, 0, 0);
	pSimulator->m_pfnPopInstance(pSimulator);
	/*>>*/
	pSimulator->m_pfnPushActivateIf(pSimulator, "GETRequestor");
	pSimulator->m_pfnPushBranch(pSimulator, "else", &_SCSIM_89_Utils, 89);
	pSimulator->m_pfnPopBranch(pSimulator);
	pSimulator->m_pfnPushBranch(pSimulator, "then", &_SCSIM_90_Utils, 90);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_String_Utils, 91, valid, 90, &_SCSIM_ClockActive_kcg_true);
	pSimulator->m_pfnAddLocal(pSimulator, "_L9", &_SCSIM_String_Utils, 92, valid, 90, &_SCSIM_ClockActive_kcg_true);
	pSimulator->m_pfnAddLocal(pSimulator, "_L10", &_SCSIM_String_Utils, 93, valid, 90, &_SCSIM_ClockActive_kcg_true);
	pSimulator->m_pfnAddLocal(pSimulator, "_L11", &_SCSIM_String_Utils, 94, valid, 90, &_SCSIM_ClockActive_kcg_true);
	pSimulator->m_pfnAddLocal(pSimulator, "_L12", &_SCSIM_String_Utils, 95, valid, 90, &_SCSIM_ClockActive_kcg_true);
	pSimulator->m_pfnAddLocal(pSimulator, "_L17", &_SCSIM_String_Utils, 96, valid, 90, &_SCSIM_ClockActive_kcg_true);
	pSimulator->m_pfnPopBranch(pSimulator);
	pSimulator->m_pfnPopActivateIf(pSimulator);
	pSimulator->m_pfnAddLocal(pSimulator, "Name", &_SCSIM_String_Utils, 97, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "Comment", &_SCSIM_String_Utils, 98, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "State", &_SCSIM_String_Utils, 99, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "ID", &_SCSIM_String_Utils, 100, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "Sex", &_SCSIM_String_Utils, 101, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "VictimIDString", &_SCSIM_String_Utils, 102, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "VictimIDSize", &_SCSIM_kcg_int_Utils, 103, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L6", &_SCSIM_kcg_bool_Utils, 104, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L5", &_SCSIM_kcg_bool_Utils, 105, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L7", &_SCSIM_kcg_bool_Utils, 106, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L8", &_SCSIM_kcg_int_Utils, 107, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L16", &_SCSIM_String_Utils, 108, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L19", &_SCSIM_kcg_bool_Utils, 109, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L31", &_SCSIM_array_char_512_Utils, 110, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L32", &_SCSIM_String_Utils, 111, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L34", &_SCSIM_kcg_int_Utils, 112, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L33", &_SCSIM_String_Utils, 113, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L35", &_SCSIM_String_Utils, 114, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L36", &_SCSIM_kcg_bool_Utils, 115, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L37", &_SCSIM_kcg_int_Utils, 116, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L39", &_SCSIM_array_char_512_Utils, 117, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L38", &_SCSIM_String_Utils, 118, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L42", &_SCSIM_String_Utils, 119, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L48", &_SCSIM_array_char_512_Utils, 120, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L47", &_SCSIM_String_Utils, 121, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L51", &_SCSIM_String_Utils, 122, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L49", &_SCSIM_array_char_512_Utils, 123, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L52", &_SCSIM_String_Utils, 124, valid, 0, 0);
	pSimulator->m_pfnAddLocal(pSimulator, "_L53", &_SCSIM_String_Utils, 125, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ReqLayerVisible", &_SCSIM_kcg_bool_Utils, 126, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ReqLayerActive", &_SCSIM_kcg_bool_Utils, 127, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "EmitToCDS", &_SCSIM_kcg_bool_Utils, 128, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ResultSize", &_SCSIM_kcg_int_Utils, 129, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ResultName", &_SCSIM_String_Utils, 130, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ResultID", &_SCSIM_String_Utils, 131, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ResultSex", &_SCSIM_String_Utils, 132, valid, 0, 0);
	pSimulator->m_pfnAddOutput(pSimulator, "ResultState", &_SCSIM_String_Utils, 133, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "GETSignalFromButton", &_SCSIM_kcg_bool_Utils, 134, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "RequestPath", &_SCSIM_Path_Utils, 135, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input3", &_SCSIM_kcg_bool_Utils, 136, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "Input4", &_SCSIM_kcg_bool_Utils, 137, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "txtID", &_SCSIM_String_Utils, 138, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "txtIDNotify", &_SCSIM_kcg_bool_Utils, 139, valid, 0, 0);
	pSimulator->m_pfnAddInput(pSimulator, "txtIDLength", &_SCSIM_kcg_int_Utils, 140, valid, 0, 0);
}

void* _SCSIM_Get_Main_Handle(void* pInstance, int nHandleIdent, int* pIteratorFilter, int nSize) {
	switch (nHandleIdent) {
		case 1:
			return &(outputs_ctx.ReqLayerVisible_InitDF);
		case 2:
			return &(outputs_ctx.ReqLayerActive_InitDF);
		case 3:
			return &(outputs_ctx._L2_InitDF);
		case 4:
			return &(outputs_ctx._L1_InitDF);
		case 5:
			return &(outputs_ctx.Result_ViewString);
		case 6:
			return &(outputs_ctx.Button_ViewString);
		case 7:
			return &(outputs_ctx.ValueString_ViewString);
		case 8:
			return &(outputs_ctx.BaseString_ViewString);
		case 9:
			return &(outputs_ctx._L5_ViewString);
		case 10:
			return &(outputs_ctx.ResultString_ConcatString_ViewString);
		case 11:
			return &(outputs_ctx.StringValue_ConcatString_ViewString);
		case 12:
			return &(outputs_ctx.StringName_ConcatString_ViewString);
		case 13:
			return &(outputs_ctx._L1_ConcatString_ViewString);
		case 14:
			return &(outputs_ctx._L2_ConcatString_ViewString);
		case 15:
			return &(outputs_ctx._L3_ConcatString_ViewString);
		case 16:
			return &(outputs_ctx._L4_ConcatString_ViewString);
		case 17:
			return &(outputs_ctx._L6_ConcatString_ViewString);
		case 18:
			return &(outputs_ctx._L3_ViewString);
		case 19:
			return &(outputs_ctx._L2_ViewString);
		case 20:
			return &(outputs_ctx._L1_ViewString);
		case 21:
			return &(outputs_ctx._L4_ViewString);
		case 22:
			return &(outputs_ctx._L6_ViewString);
		case 23:
			return &(outputs_ctx.WidgetString_1);
		case 24:
			return &(outputs_ctx.WidgetStringLength_1);
		case 25:
			return &(outputs_ctx.EvtString_1);
		case 26:
			return &(outputs_ctx.Notify_1);
		case 27:
			return &(outputs_ctx.EvtStringLength_1);
		case 28:
			return &(outputs_ctx._L11_1);
		case 29:
			return &(outputs_ctx._L12_1);
		case 30:
			return &(outputs_ctx._L7_1);
		case 31:
			return &(outputs_ctx._L8_1);
		case 32:
			return &(outputs_ctx._L9_1);
		case 33:
			return &(outputs_ctx._L13_1);
		case 34:
			return &(outputs_ctx._L14_1);
		case 35:
			return &(outputs_ctx.Result_1);
		case 36:
			return &(outputs_ctx.Button_1);
		case 37:
			return &(outputs_ctx.ValueString_1);
		case 38:
			return &(outputs_ctx.BaseString_1);
		case 39:
			return &(outputs_ctx._L5_1);
		case 40:
			return &(outputs_ctx.ResultString_ConcatString_1);
		case 41:
			return &(outputs_ctx.StringValue_ConcatString_1);
		case 42:
			return &(outputs_ctx.StringName_ConcatString_1);
		case 43:
			return &(outputs_ctx._L1_ConcatString_1);
		case 44:
			return &(outputs_ctx._L2_ConcatString_1);
		case 45:
			return &(outputs_ctx._L3_ConcatString_1);
		case 46:
			return &(outputs_ctx._L4_ConcatString_1);
		case 47:
			return &(outputs_ctx._L6_ConcatString_1);
		case 48:
			return &(outputs_ctx._L3_1);
		case 49:
			return &(outputs_ctx._L2_1);
		case 50:
			return &(outputs_ctx._L1_1);
		case 51:
			return &(outputs_ctx._L4_1);
		case 52:
			return &(outputs_ctx._L6_1);
		case 53:
			return &(outputs_ctx.Result_3);
		case 54:
			return &(outputs_ctx.Button_3);
		case 55:
			return &(outputs_ctx.ValueString_3);
		case 56:
			return &(outputs_ctx.BaseString_3);
		case 57:
			return &(outputs_ctx._L5_3);
		case 58:
			return &(outputs_ctx.ResultString_ConcatString_3);
		case 59:
			return &(outputs_ctx.StringValue_ConcatString_3);
		case 60:
			return &(outputs_ctx.StringName_ConcatString_3);
		case 61:
			return &(outputs_ctx._L1_ConcatString_3);
		case 62:
			return &(outputs_ctx._L2_ConcatString_3);
		case 63:
			return &(outputs_ctx._L3_ConcatString_3);
		case 64:
			return &(outputs_ctx._L4_ConcatString_3);
		case 65:
			return &(outputs_ctx._L6_ConcatString_3);
		case 66:
			return &(outputs_ctx._L3_3);
		case 67:
			return &(outputs_ctx._L2_3);
		case 68:
			return &(outputs_ctx._L1_3);
		case 69:
			return &(outputs_ctx._L4_3);
		case 70:
			return &(outputs_ctx._L6_3);
		case 71:
			return &(outputs_ctx.Result_4);
		case 72:
			return &(outputs_ctx.Button_4);
		case 73:
			return &(outputs_ctx.ValueString_4);
		case 74:
			return &(outputs_ctx.BaseString_4);
		case 75:
			return &(outputs_ctx._L5_4);
		case 76:
			return &(outputs_ctx.ResultString_ConcatString_4);
		case 77:
			return &(outputs_ctx.StringValue_ConcatString_4);
		case 78:
			return &(outputs_ctx.StringName_ConcatString_4);
		case 79:
			return &(outputs_ctx._L1_ConcatString_4);
		case 80:
			return &(outputs_ctx._L2_ConcatString_4);
		case 81:
			return &(outputs_ctx._L3_ConcatString_4);
		case 82:
			return &(outputs_ctx._L4_ConcatString_4);
		case 83:
			return &(outputs_ctx._L6_ConcatString_4);
		case 84:
			return &(outputs_ctx._L3_4);
		case 85:
			return &(outputs_ctx._L2_4);
		case 86:
			return &(outputs_ctx._L1_4);
		case 87:
			return &(outputs_ctx._L4_4);
		case 88:
			return &(outputs_ctx._L6_4);
		case 89:
			return &(outputs_ctx.GETRequestor_clock);
		case 90:
			return &(outputs_ctx.GETRequestor_clock);
		case 91:
			return &(outputs_ctx._L8_GETRequestor);
		case 92:
			return &(outputs_ctx._L9_GETRequestor);
		case 93:
			return &(outputs_ctx._L10_GETRequestor);
		case 94:
			return &(outputs_ctx._L11_GETRequestor);
		case 95:
			return &(outputs_ctx._L12_GETRequestor);
		case 96:
			return &(outputs_ctx._L17_GETRequestor);
		case 97:
			return &(outputs_ctx.Name);
		case 98:
			return &(outputs_ctx.Comment);
		case 99:
			return &(outputs_ctx.State);
		case 100:
			return &(outputs_ctx.ID);
		case 101:
			return &(outputs_ctx.Sex);
		case 102:
			return &(outputs_ctx.VictimIDString);
		case 103:
			return &(outputs_ctx.VictimIDSize);
		case 104:
			return &(outputs_ctx._L6);
		case 105:
			return &(outputs_ctx._L5);
		case 106:
			return &(outputs_ctx._L7);
		case 107:
			return &(outputs_ctx._L8);
		case 108:
			return &(outputs_ctx._L16);
		case 109:
			return &(outputs_ctx._L19);
		case 110:
			return &(outputs_ctx._L31);
		case 111:
			return &(outputs_ctx._L32);
		case 112:
			return &(outputs_ctx._L34);
		case 113:
			return &(outputs_ctx._L33);
		case 114:
			return &(outputs_ctx._L35);
		case 115:
			return &(outputs_ctx._L36);
		case 116:
			return &(outputs_ctx._L37);
		case 117:
			return &(outputs_ctx._L39);
		case 118:
			return &(outputs_ctx._L38);
		case 119:
			return &(outputs_ctx._L42);
		case 120:
			return &(outputs_ctx._L48);
		case 121:
			return &(outputs_ctx._L47);
		case 122:
			return &(outputs_ctx._L51);
		case 123:
			return &(outputs_ctx._L49);
		case 124:
			return &(outputs_ctx._L52);
		case 125:
			return &(outputs_ctx._L53);
		case 126:
			return &(outputs_ctx.ReqLayerVisible);
		case 127:
			return &(outputs_ctx.ReqLayerActive);
		case 128:
			return &(outputs_ctx.EmitToCDS);
		case 129:
			return &(outputs_ctx.ResultSize);
		case 130:
			return &(outputs_ctx.ResultName);
		case 131:
			return &(outputs_ctx.ResultID);
		case 132:
			return &(outputs_ctx.ResultSex);
		case 133:
			return &(outputs_ctx.ResultState);
		case 134:
			return &(inputs_ctx.GETSignalFromButton);
		case 135:
			return &(inputs_ctx.RequestPath);
		case 136:
			return &(inputs_ctx.Input3);
		case 137:
			return &(inputs_ctx.Input4);
		case 138:
			return &(inputs_ctx.txtID);
		case 139:
			return &(inputs_ctx.txtIDNotify);
		case 140:
			return &(inputs_ctx.txtIDLength);
		default:
			break;
	}
	return 0;
}

static int Is89Active(void * pHandle) {
	return *((kcg_bool*)pHandle) != kcg_false  ? 0 : 1;
}
ControlUtils _SCSIM_89_Utils = {Is89Active};

static int Is90Active(void * pHandle) {
	return *((kcg_bool*)pHandle) != kcg_false  ? 1 : 0;
}
ControlUtils _SCSIM_90_Utils = {Is90Active};

static int _SCSIM_ClockActive_kcg_true(void* clock) {
return *(kcg_bool*)clock == kcg_true ? 1 : 0;
}
