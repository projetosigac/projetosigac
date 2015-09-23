/* REST-API_newmapping.c */

#include <stddef.h>

#include "NewSmuTypes.h"
#include "SmuMapping.h"
#include "REST-API_newtype.h"
#include "REST-API_newmapping.h"

/* iterators */
static const MappingIterator iter_522;
static const MappingIterator iter_10;
static const MappingIterator iter_256;
static const MappingIterator iter_512;
static const MappingIterator iter_522 = { 522, NULL};
static const MappingIterator iter_10 = { 10, NULL};
static const MappingIterator iter_256 = { 256, NULL};
static const MappingIterator iter_512 = { 512, NULL};

/* clock active helper functions */
static int isActive_kcg_bool_kcg_false (void* pHandle) { return (*(kcg_bool*)pHandle == kcg_false); }
static int isActive_kcg_bool_kcg_true (void* pHandle) { return (*(kcg_bool*)pHandle == kcg_true); }

/* forward declarations */
#define MAP_DECL(ident, nb) static const MappingEntry ident##_entries[nb]; static const MappingScope ident
MAP_DECL(scope_22, 1);
MAP_DECL(scope_21, 1);
MAP_DECL(scope_20, 1);
MAP_DECL(scope_19, 1);
MAP_DECL(scope_14, 6);
MAP_DECL(scope_12, 3);
MAP_DECL(scope_11, 6);
MAP_DECL(scope_10, 8);
MAP_DECL(scope_9, 6);
MAP_DECL(scope_8, 8);
MAP_DECL(scope_7, 6);
MAP_DECL(scope_6, 8);
MAP_DECL(scope_5, 9);
MAP_DECL(scope_4, 6);
MAP_DECL(scope_3, 8);
MAP_DECL(scope_2, 4);
MAP_DECL(scope_1, 52);
MAP_DECL(scope_0, 1);

/* array_char_522 */
static const MappingEntry scope_22_entries[1] = {
  /* 0 */ { MAP_ARRAY, "", &iter_522, sizeof(kcg_char), 0, &_Type_kcg_char_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_22 = {
  "array_char_522",
  scope_22_entries, 1,
};

/* array_char_10 */
static const MappingEntry scope_21_entries[1] = {
  /* 0 */ { MAP_ARRAY, "", &iter_10, sizeof(kcg_char), 0, &_Type_kcg_char_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_21 = {
  "array_char_10",
  scope_21_entries, 1,
};

/* array_char_256 */
static const MappingEntry scope_20_entries[1] = {
  /* 0 */ { MAP_ARRAY, "", &iter_256, sizeof(kcg_char), 0, &_Type_kcg_char_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_20 = {
  "array_char_256",
  scope_20_entries, 1,
};

/* array_char_512 */
static const MappingEntry scope_19_entries[1] = {
  /* 0 */ { MAP_ARRAY, "", &iter_512, sizeof(kcg_char), 0, &_Type_kcg_char_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_19 = {
  "array_char_512",
  scope_19_entries, 1,
};

/* Main/ MainGETRequestor:then: */
static const MappingEntry scope_14_entries[6] = {
  /* 0 */ { MAP_LOCAL, "_L10", NULL, sizeof(String), (int)&outputs_ctx._L10_GETRequestor, &_Type_String_Utils, &scope_12_entries[0], isActive_kcg_bool_kcg_true, &scope_19},
  /* 1 */ { MAP_LOCAL, "_L11", NULL, sizeof(String), (int)&outputs_ctx._L11_GETRequestor, &_Type_String_Utils, &scope_12_entries[0], isActive_kcg_bool_kcg_true, &scope_19},
  /* 2 */ { MAP_LOCAL, "_L12", NULL, sizeof(String), (int)&outputs_ctx._L12_GETRequestor, &_Type_String_Utils, &scope_12_entries[0], isActive_kcg_bool_kcg_true, &scope_19},
  /* 3 */ { MAP_LOCAL, "_L17", NULL, sizeof(String), (int)&outputs_ctx._L17_GETRequestor, &_Type_String_Utils, &scope_12_entries[0], isActive_kcg_bool_kcg_true, &scope_19},
  /* 4 */ { MAP_LOCAL, "_L8", NULL, sizeof(String), (int)&outputs_ctx._L8_GETRequestor, &_Type_String_Utils, &scope_12_entries[0], isActive_kcg_bool_kcg_true, &scope_19},
  /* 5 */ { MAP_LOCAL, "_L9", NULL, sizeof(String), (int)&outputs_ctx._L9_GETRequestor, &_Type_String_Utils, &scope_12_entries[0], isActive_kcg_bool_kcg_true, &scope_19}
};
static const MappingScope scope_14 = {
  "Main/ MainGETRequestor:then:",
  scope_14_entries, 6,
};

/* Main/ MainGETRequestor: */
static const MappingEntry scope_12_entries[3] = {
  /* 0 */ { MAP_LOCAL, "@condition", NULL, sizeof(kcg_bool), (int)&outputs_ctx.GETRequestor_clock, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_ACTION, "else:", NULL, 0, 0, NULL, &scope_12_entries[0], isActive_kcg_bool_kcg_false, NULL},
  /* 2 */ { MAP_ACTION, "then:", NULL, 0, 0, NULL, &scope_12_entries[0], isActive_kcg_bool_kcg_true, &scope_14}
};
static const MappingScope scope_12 = {
  "Main/ MainGETRequestor:",
  scope_12_entries, 3,
};

/* Main/ MainViewString 4/ConcatString/ */
static const MappingEntry scope_11_entries[6] = {
  /* 0 */ { MAP_OUTPUT, "ResultString", NULL, sizeof(array_char_512), (int)&outputs_ctx.ResultString_ConcatString_4, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(String), (int)&outputs_ctx._L1_ConcatString_4, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(array_char_10), (int)&outputs_ctx._L2_ConcatString_4, &_Type_array_char_10_Utils, NULL, NULL, &scope_21},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(array_char_522), (int)&outputs_ctx._L3_ConcatString_4, &_Type_array_char_522_Utils, NULL, NULL, &scope_22},
  /* 4 */ { MAP_LOCAL, "_L4", NULL, sizeof(array_char_512), (int)&outputs_ctx._L4_ConcatString_4, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 5 */ { MAP_LOCAL, "_L6", NULL, sizeof(String), (int)&outputs_ctx._L6_ConcatString_4, &_Type_String_Utils, NULL, NULL, &scope_19}
};
static const MappingScope scope_11 = {
  "Main/ MainViewString 4/ConcatString/",
  scope_11_entries, 6,
};

/* Main/ MainViewString 4/ */
static const MappingEntry scope_10_entries[8] = {
  /* 0 */ { MAP_EXPANDED, "ConcatString", NULL, 0, 0, NULL, NULL, NULL, &scope_11},
  /* 1 */ { MAP_OUTPUT, "Result", NULL, sizeof(array_char_512), (int)&outputs_ctx.Result_4, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 2 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L2", NULL, sizeof(String), (int)&outputs_ctx._L2_4, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 4 */ { MAP_LOCAL, "_L3", NULL, sizeof(String), (int)&outputs_ctx._L3_4, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 5 */ { MAP_LOCAL, "_L4", NULL, sizeof(String), (int)&outputs_ctx._L4_4, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 6 */ { MAP_LOCAL, "_L5@mem", NULL, sizeof(String), (int)&outputs_ctx._L5_4, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 7 */ { MAP_LOCAL, "_L6", NULL, sizeof(array_char_512), (int)&outputs_ctx._L6_4, &_Type_array_char_512_Utils, NULL, NULL, &scope_19}
};
static const MappingScope scope_10 = {
  "Main/ MainViewString 4/",
  scope_10_entries, 8,
};

/* Main/ MainViewString 3/ConcatString/ */
static const MappingEntry scope_9_entries[6] = {
  /* 0 */ { MAP_OUTPUT, "ResultString", NULL, sizeof(array_char_512), (int)&outputs_ctx.ResultString_ConcatString_3, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(String), (int)&outputs_ctx._L1_ConcatString_3, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(array_char_10), (int)&outputs_ctx._L2_ConcatString_3, &_Type_array_char_10_Utils, NULL, NULL, &scope_21},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(array_char_522), (int)&outputs_ctx._L3_ConcatString_3, &_Type_array_char_522_Utils, NULL, NULL, &scope_22},
  /* 4 */ { MAP_LOCAL, "_L4", NULL, sizeof(array_char_512), (int)&outputs_ctx._L4_ConcatString_3, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 5 */ { MAP_LOCAL, "_L6", NULL, sizeof(String), (int)&outputs_ctx._L6_ConcatString_3, &_Type_String_Utils, NULL, NULL, &scope_19}
};
static const MappingScope scope_9 = {
  "Main/ MainViewString 3/ConcatString/",
  scope_9_entries, 6,
};

/* Main/ MainViewString 3/ */
static const MappingEntry scope_8_entries[8] = {
  /* 0 */ { MAP_EXPANDED, "ConcatString", NULL, 0, 0, NULL, NULL, NULL, &scope_9},
  /* 1 */ { MAP_OUTPUT, "Result", NULL, sizeof(array_char_512), (int)&outputs_ctx.Result_3, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 2 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_3, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L2", NULL, sizeof(String), (int)&outputs_ctx._L2_3, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 4 */ { MAP_LOCAL, "_L3", NULL, sizeof(String), (int)&outputs_ctx._L3_3, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 5 */ { MAP_LOCAL, "_L4", NULL, sizeof(String), (int)&outputs_ctx._L4_3, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 6 */ { MAP_LOCAL, "_L5@mem", NULL, sizeof(String), (int)&outputs_ctx._L5_3, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 7 */ { MAP_LOCAL, "_L6", NULL, sizeof(array_char_512), (int)&outputs_ctx._L6_3, &_Type_array_char_512_Utils, NULL, NULL, &scope_19}
};
static const MappingScope scope_8 = {
  "Main/ MainViewString 3/",
  scope_8_entries, 8,
};

/* Main/ MainViewString 1/ConcatString/ */
static const MappingEntry scope_7_entries[6] = {
  /* 0 */ { MAP_OUTPUT, "ResultString", NULL, sizeof(array_char_512), (int)&outputs_ctx.ResultString_ConcatString_1, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(String), (int)&outputs_ctx._L1_ConcatString_1, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(array_char_10), (int)&outputs_ctx._L2_ConcatString_1, &_Type_array_char_10_Utils, NULL, NULL, &scope_21},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(array_char_522), (int)&outputs_ctx._L3_ConcatString_1, &_Type_array_char_522_Utils, NULL, NULL, &scope_22},
  /* 4 */ { MAP_LOCAL, "_L4", NULL, sizeof(array_char_512), (int)&outputs_ctx._L4_ConcatString_1, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 5 */ { MAP_LOCAL, "_L6", NULL, sizeof(String), (int)&outputs_ctx._L6_ConcatString_1, &_Type_String_Utils, NULL, NULL, &scope_19}
};
static const MappingScope scope_7 = {
  "Main/ MainViewString 1/ConcatString/",
  scope_7_entries, 6,
};

/* Main/ MainViewString 1/ */
static const MappingEntry scope_6_entries[8] = {
  /* 0 */ { MAP_EXPANDED, "ConcatString", NULL, 0, 0, NULL, NULL, NULL, &scope_7},
  /* 1 */ { MAP_OUTPUT, "Result", NULL, sizeof(array_char_512), (int)&outputs_ctx.Result_1, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 2 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L2", NULL, sizeof(String), (int)&outputs_ctx._L2_1, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 4 */ { MAP_LOCAL, "_L3", NULL, sizeof(String), (int)&outputs_ctx._L3_1, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 5 */ { MAP_LOCAL, "_L4", NULL, sizeof(String), (int)&outputs_ctx._L4_1, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 6 */ { MAP_LOCAL, "_L5@mem", NULL, sizeof(String), (int)&outputs_ctx._L5_1, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 7 */ { MAP_LOCAL, "_L6", NULL, sizeof(array_char_512), (int)&outputs_ctx._L6_1, &_Type_array_char_512_Utils, NULL, NULL, &scope_19}
};
static const MappingScope scope_6 = {
  "Main/ MainViewString 1/",
  scope_6_entries, 8,
};

/* Main/ MainGetValueFromTxtWidget 1/ */
static const MappingEntry scope_5_entries[9] = {
  /* 0 */ { MAP_OUTPUT, "WidgetString", NULL, sizeof(String), (int)&outputs_ctx.WidgetString_1, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 1 */ { MAP_OUTPUT, "WidgetStringLength", NULL, sizeof(kcg_int), (int)&outputs_ctx.WidgetStringLength_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L11@mem", NULL, sizeof(String), (int)&outputs_ctx._L11_1, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 3 */ { MAP_LOCAL, "_L12@mem", NULL, sizeof(kcg_int), (int)&outputs_ctx._L12_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L13", NULL, sizeof(kcg_int), (int)&outputs_ctx._L13_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 5 */ { MAP_LOCAL, "_L14", NULL, sizeof(String), (int)&outputs_ctx._L14_1, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 6 */ { MAP_LOCAL, "_L7", NULL, sizeof(String), (int)&outputs_ctx._L7_1, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 7 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L8_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 8 */ { MAP_LOCAL, "_L9", NULL, sizeof(kcg_int), (int)&outputs_ctx._L9_1, &_Type_kcg_int_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_5 = {
  "Main/ MainGetValueFromTxtWidget 1/",
  scope_5_entries, 9,
};

/* Main/ MainViewString/ConcatString/ */
static const MappingEntry scope_4_entries[6] = {
  /* 0 */ { MAP_OUTPUT, "ResultString", NULL, sizeof(array_char_512), (int)&outputs_ctx.ResultString_ConcatString_ViewString, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(String), (int)&outputs_ctx._L1_ConcatString_ViewString, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(array_char_10), (int)&outputs_ctx._L2_ConcatString_ViewString, &_Type_array_char_10_Utils, NULL, NULL, &scope_21},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(array_char_522), (int)&outputs_ctx._L3_ConcatString_ViewString, &_Type_array_char_522_Utils, NULL, NULL, &scope_22},
  /* 4 */ { MAP_LOCAL, "_L4", NULL, sizeof(array_char_512), (int)&outputs_ctx._L4_ConcatString_ViewString, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 5 */ { MAP_LOCAL, "_L6", NULL, sizeof(String), (int)&outputs_ctx._L6_ConcatString_ViewString, &_Type_String_Utils, NULL, NULL, &scope_19}
};
static const MappingScope scope_4 = {
  "Main/ MainViewString/ConcatString/",
  scope_4_entries, 6,
};

/* Main/ MainViewString/ */
static const MappingEntry scope_3_entries[8] = {
  /* 0 */ { MAP_EXPANDED, "ConcatString", NULL, 0, 0, NULL, NULL, NULL, &scope_4},
  /* 1 */ { MAP_OUTPUT, "Result", NULL, sizeof(array_char_512), (int)&outputs_ctx.Result_ViewString, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 2 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_ViewString, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L2", NULL, sizeof(String), (int)&outputs_ctx._L2_ViewString, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 4 */ { MAP_LOCAL, "_L3", NULL, sizeof(String), (int)&outputs_ctx._L3_ViewString, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 5 */ { MAP_LOCAL, "_L4", NULL, sizeof(String), (int)&outputs_ctx._L4_ViewString, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 6 */ { MAP_LOCAL, "_L5@mem", NULL, sizeof(String), (int)&outputs_ctx._L5_ViewString, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 7 */ { MAP_LOCAL, "_L6", NULL, sizeof(array_char_512), (int)&outputs_ctx._L6_ViewString, &_Type_array_char_512_Utils, NULL, NULL, &scope_19}
};
static const MappingScope scope_3 = {
  "Main/ MainViewString/",
  scope_3_entries, 8,
};

/* Main/ MainInitDF/ */
static const MappingEntry scope_2_entries[4] = {
  /* 0 */ { MAP_OUTPUT, "ReqLayerActive", NULL, sizeof(kcg_bool), (int)&outputs_ctx.ReqLayerActive_InitDF, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_OUTPUT, "ReqLayerVisible", NULL, sizeof(kcg_bool), (int)&outputs_ctx.ReqLayerVisible_InitDF, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_InitDF, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L2@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_InitDF, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_2 = {
  "Main/ MainInitDF/",
  scope_2_entries, 4,
};

/* Main/ Main */
static const MappingEntry scope_1_entries[52] = {
  /* 0 */ { MAP_LOCAL, "@kcg0", NULL, sizeof(kcg_bool), (int)&outputs_ctx.init, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "Comment", NULL, sizeof(String), (int)&outputs_ctx.Comment, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 2 */ { MAP_OUTPUT, "EmitToCDS", NULL, sizeof(kcg_bool), (int)&outputs_ctx.EmitToCDS, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_IF, "GETRequestor:", NULL, 0, 0, NULL, NULL, NULL, &scope_12},
  /* 4 */ { MAP_INPUT, "GETSignalFromButton", NULL, sizeof(kcg_bool), (int)&inputs_ctx.GETSignalFromButton, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 5 */ { MAP_EXPANDED, "GetValueFromTxtWidget 1", NULL, 0, 0, NULL, NULL, NULL, &scope_5},
  /* 6 */ { MAP_LOCAL, "ID", NULL, sizeof(String), (int)&outputs_ctx.ID, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 7 */ { MAP_EXPANDED, "InitDF", NULL, 0, 0, NULL, NULL, NULL, &scope_2},
  /* 8 */ { MAP_INPUT, "Input3", NULL, sizeof(kcg_bool), (int)&inputs_ctx.Input3, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 9 */ { MAP_INPUT, "Input4", NULL, sizeof(kcg_bool), (int)&inputs_ctx.Input4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 10 */ { MAP_LOCAL, "Name", NULL, sizeof(String), (int)&outputs_ctx.Name, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 11 */ { MAP_OUTPUT, "ReqLayerActive", NULL, sizeof(kcg_bool), (int)&outputs_ctx.ReqLayerActive, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 12 */ { MAP_OUTPUT, "ReqLayerVisible", NULL, sizeof(kcg_bool), (int)&outputs_ctx.ReqLayerVisible, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 13 */ { MAP_INPUT, "RequestPath", NULL, sizeof(Path), (int)&inputs_ctx.RequestPath, &_Type_Path_Utils, NULL, NULL, &scope_20},
  /* 14 */ { MAP_OUTPUT, "ResultID", NULL, sizeof(String), (int)&outputs_ctx.ResultID, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 15 */ { MAP_OUTPUT, "ResultName", NULL, sizeof(String), (int)&outputs_ctx.ResultName, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 16 */ { MAP_OUTPUT, "ResultSex", NULL, sizeof(String), (int)&outputs_ctx.ResultSex, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 17 */ { MAP_OUTPUT, "ResultSize", NULL, sizeof(kcg_int), (int)&outputs_ctx.ResultSize, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 18 */ { MAP_OUTPUT, "ResultState", NULL, sizeof(String), (int)&outputs_ctx.ResultState, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 19 */ { MAP_LOCAL, "Sex", NULL, sizeof(String), (int)&outputs_ctx.Sex, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 20 */ { MAP_LOCAL, "State", NULL, sizeof(String), (int)&outputs_ctx.State, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 21 */ { MAP_LOCAL, "VictimIDSize", NULL, sizeof(kcg_int), (int)&outputs_ctx.VictimIDSize, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 22 */ { MAP_LOCAL, "VictimIDString", NULL, sizeof(String), (int)&outputs_ctx.VictimIDString, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 23 */ { MAP_EXPANDED, "ViewString", NULL, 0, 0, NULL, NULL, NULL, &scope_3},
  /* 24 */ { MAP_EXPANDED, "ViewString 1", NULL, 0, 0, NULL, NULL, NULL, &scope_6},
  /* 25 */ { MAP_EXPANDED, "ViewString 3", NULL, 0, 0, NULL, NULL, NULL, &scope_8},
  /* 26 */ { MAP_EXPANDED, "ViewString 4", NULL, 0, 0, NULL, NULL, NULL, &scope_10},
  /* 27 */ { MAP_LOCAL, "_L16", NULL, sizeof(String), (int)&outputs_ctx._L16, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 28 */ { MAP_LOCAL, "_L19", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L19, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 29 */ { MAP_LOCAL, "_L31", NULL, sizeof(array_char_512), (int)&outputs_ctx._L31, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 30 */ { MAP_LOCAL, "_L32", NULL, sizeof(String), (int)&outputs_ctx._L32, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 31 */ { MAP_LOCAL, "_L33", NULL, sizeof(String), (int)&outputs_ctx._L33, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 32 */ { MAP_LOCAL, "_L34", NULL, sizeof(kcg_int), (int)&outputs_ctx._L34, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 33 */ { MAP_LOCAL, "_L35", NULL, sizeof(String), (int)&outputs_ctx._L35, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 34 */ { MAP_LOCAL, "_L36", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L36, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 35 */ { MAP_LOCAL, "_L37", NULL, sizeof(kcg_int), (int)&outputs_ctx._L37, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 36 */ { MAP_LOCAL, "_L38", NULL, sizeof(String), (int)&outputs_ctx._L38, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 37 */ { MAP_LOCAL, "_L39", NULL, sizeof(array_char_512), (int)&outputs_ctx._L39, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 38 */ { MAP_LOCAL, "_L42", NULL, sizeof(String), (int)&outputs_ctx._L42, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 39 */ { MAP_LOCAL, "_L47", NULL, sizeof(String), (int)&outputs_ctx._L47, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 40 */ { MAP_LOCAL, "_L48", NULL, sizeof(array_char_512), (int)&outputs_ctx._L48, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 41 */ { MAP_LOCAL, "_L49", NULL, sizeof(array_char_512), (int)&outputs_ctx._L49, &_Type_array_char_512_Utils, NULL, NULL, &scope_19},
  /* 42 */ { MAP_LOCAL, "_L5", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 43 */ { MAP_LOCAL, "_L51", NULL, sizeof(String), (int)&outputs_ctx._L51, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 44 */ { MAP_LOCAL, "_L52", NULL, sizeof(String), (int)&outputs_ctx._L52, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 45 */ { MAP_LOCAL, "_L53", NULL, sizeof(String), (int)&outputs_ctx._L53, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 46 */ { MAP_LOCAL, "_L6", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 47 */ { MAP_LOCAL, "_L7", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 48 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_int), (int)&outputs_ctx._L8, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 49 */ { MAP_INPUT, "txtID", NULL, sizeof(String), (int)&inputs_ctx.txtID, &_Type_String_Utils, NULL, NULL, &scope_19},
  /* 50 */ { MAP_INPUT, "txtIDLength", NULL, sizeof(kcg_int), (int)&inputs_ctx.txtIDLength, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 51 */ { MAP_INPUT, "txtIDNotify", NULL, sizeof(kcg_bool), (int)&inputs_ctx.txtIDNotify, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_1 = {
  "Main/ Main",
  scope_1_entries, 52,
};

/*  */
static const MappingEntry scope_0_entries[1] = {
  /* 0 */ { MAP_ROOT, "Main", NULL, 0, 0, NULL, NULL, NULL, &scope_1}
};
static const MappingScope scope_0 = {
  "",
  scope_0_entries, 1,
};

const MappingScope* pTop = &scope_0;

