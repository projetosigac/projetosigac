/* UTI-availability_newmapping.c */

#include <stddef.h>

#include "NewSmuTypes.h"
#include "SmuMapping.h"
#include "UTI-availability_newtype.h"
#include "UTI-availability_newmapping.h"

/* iterators */

/* clock active helper functions */

/* forward declarations */
#define MAP_DECL(ident, nb) static const MappingEntry ident##_entries[nb]; static const MappingScope ident
MAP_DECL(scope_25, 5);
MAP_DECL(scope_24, 5);
MAP_DECL(scope_23, 22);
MAP_DECL(scope_22, 5);
MAP_DECL(scope_21, 5);
MAP_DECL(scope_20, 22);
MAP_DECL(scope_19, 5);
MAP_DECL(scope_18, 5);
MAP_DECL(scope_17, 22);
MAP_DECL(scope_16, 5);
MAP_DECL(scope_15, 5);
MAP_DECL(scope_14, 22);
MAP_DECL(scope_13, 5);
MAP_DECL(scope_12, 5);
MAP_DECL(scope_11, 22);
MAP_DECL(scope_10, 5);
MAP_DECL(scope_9, 5);
MAP_DECL(scope_8, 22);
MAP_DECL(scope_7, 5);
MAP_DECL(scope_6, 5);
MAP_DECL(scope_5, 22);
MAP_DECL(scope_4, 5);
MAP_DECL(scope_3, 5);
MAP_DECL(scope_2, 22);
MAP_DECL(scope_1, 86);
MAP_DECL(scope_0, 1);

/* UTI/ UTIBed 12/Toggle 2/ */
static const MappingEntry scope_25_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_2_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_2_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_2_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_2_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_2_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_25 = {
  "UTI/ UTIBed 12/Toggle 2/",
  scope_25_entries, 5,
};

/* UTI/ UTIBed 12/Toggle 1/ */
static const MappingEntry scope_24_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_1_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_1_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_1_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_1_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_1_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_24 = {
  "UTI/ UTIBed 12/Toggle 1/",
  scope_24_entries, 5,
};

/* UTI/ UTIBed 12/ */
static const MappingEntry scope_23_entries[22] = {
  /* 0 */ { MAP_OUTPUT, "BedActive", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedActive_12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_OUTPUT, "BedAllocated", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedAllocated_12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_OUTPUT, "BedColor", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor_12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_EXPANDED, "Toggle 1", NULL, 0, 0, NULL, NULL, NULL, &scope_24},
  /* 4 */ { MAP_EXPANDED, "Toggle 2", NULL, 0, 0, NULL, NULL, NULL, &scope_25},
  /* 5 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 6 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_int), (int)&outputs_ctx._L10_12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 7 */ { MAP_LOCAL, "_L11", NULL, sizeof(kcg_int), (int)&outputs_ctx._L11_12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 8 */ { MAP_LOCAL, "_L12", NULL, sizeof(kcg_int), (int)&outputs_ctx._L12_12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 9 */ { MAP_LOCAL, "_L13", NULL, sizeof(kcg_int), (int)&outputs_ctx._L13_12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 10 */ { MAP_LOCAL, "_L14", NULL, sizeof(kcg_int), (int)&outputs_ctx._L14_12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 11 */ { MAP_LOCAL, "_L15", NULL, sizeof(kcg_int), (int)&outputs_ctx._L15_12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 12 */ { MAP_LOCAL, "_L16", NULL, sizeof(kcg_int), (int)&outputs_ctx._L16_12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 13 */ { MAP_LOCAL, "_L17", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L17_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 14 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 15 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 16 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 17 */ { MAP_LOCAL, "_L5", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L5_12, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 18 */ { MAP_LOCAL, "_L6", NULL, sizeof(kcg_int), (int)&outputs_ctx._L6_12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 19 */ { MAP_LOCAL, "_L7", NULL, sizeof(kcg_int), (int)&outputs_ctx._L7_12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 20 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_int), (int)&outputs_ctx._L8_12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 21 */ { MAP_LOCAL, "_L9", NULL, sizeof(kcg_int), (int)&outputs_ctx._L9_12, &_Type_kcg_int_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_23 = {
  "UTI/ UTIBed 12/",
  scope_23_entries, 22,
};

/* UTI/ UTIBed 11/Toggle 2/ */
static const MappingEntry scope_22_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_2_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_2_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_2_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_2_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_2_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_22 = {
  "UTI/ UTIBed 11/Toggle 2/",
  scope_22_entries, 5,
};

/* UTI/ UTIBed 11/Toggle 1/ */
static const MappingEntry scope_21_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_1_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_1_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_1_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_1_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_1_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_21 = {
  "UTI/ UTIBed 11/Toggle 1/",
  scope_21_entries, 5,
};

/* UTI/ UTIBed 11/ */
static const MappingEntry scope_20_entries[22] = {
  /* 0 */ { MAP_OUTPUT, "BedActive", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedActive_11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_OUTPUT, "BedAllocated", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedAllocated_11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_OUTPUT, "BedColor", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor_11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_EXPANDED, "Toggle 1", NULL, 0, 0, NULL, NULL, NULL, &scope_21},
  /* 4 */ { MAP_EXPANDED, "Toggle 2", NULL, 0, 0, NULL, NULL, NULL, &scope_22},
  /* 5 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 6 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_int), (int)&outputs_ctx._L10_11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 7 */ { MAP_LOCAL, "_L11", NULL, sizeof(kcg_int), (int)&outputs_ctx._L11_11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 8 */ { MAP_LOCAL, "_L12", NULL, sizeof(kcg_int), (int)&outputs_ctx._L12_11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 9 */ { MAP_LOCAL, "_L13", NULL, sizeof(kcg_int), (int)&outputs_ctx._L13_11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 10 */ { MAP_LOCAL, "_L14", NULL, sizeof(kcg_int), (int)&outputs_ctx._L14_11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 11 */ { MAP_LOCAL, "_L15", NULL, sizeof(kcg_int), (int)&outputs_ctx._L15_11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 12 */ { MAP_LOCAL, "_L16", NULL, sizeof(kcg_int), (int)&outputs_ctx._L16_11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 13 */ { MAP_LOCAL, "_L17", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L17_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 14 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 15 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 16 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 17 */ { MAP_LOCAL, "_L5", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L5_11, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 18 */ { MAP_LOCAL, "_L6", NULL, sizeof(kcg_int), (int)&outputs_ctx._L6_11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 19 */ { MAP_LOCAL, "_L7", NULL, sizeof(kcg_int), (int)&outputs_ctx._L7_11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 20 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_int), (int)&outputs_ctx._L8_11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 21 */ { MAP_LOCAL, "_L9", NULL, sizeof(kcg_int), (int)&outputs_ctx._L9_11, &_Type_kcg_int_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_20 = {
  "UTI/ UTIBed 11/",
  scope_20_entries, 22,
};

/* UTI/ UTIBed 9/Toggle 2/ */
static const MappingEntry scope_19_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_2_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_2_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_2_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_2_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_2_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_19 = {
  "UTI/ UTIBed 9/Toggle 2/",
  scope_19_entries, 5,
};

/* UTI/ UTIBed 9/Toggle 1/ */
static const MappingEntry scope_18_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_1_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_1_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_1_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_1_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_1_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_18 = {
  "UTI/ UTIBed 9/Toggle 1/",
  scope_18_entries, 5,
};

/* UTI/ UTIBed 9/ */
static const MappingEntry scope_17_entries[22] = {
  /* 0 */ { MAP_OUTPUT, "BedActive", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedActive_9, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_OUTPUT, "BedAllocated", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedAllocated_9, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_OUTPUT, "BedColor", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor_9, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_EXPANDED, "Toggle 1", NULL, 0, 0, NULL, NULL, NULL, &scope_18},
  /* 4 */ { MAP_EXPANDED, "Toggle 2", NULL, 0, 0, NULL, NULL, NULL, &scope_19},
  /* 5 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 6 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_int), (int)&outputs_ctx._L10_9, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 7 */ { MAP_LOCAL, "_L11", NULL, sizeof(kcg_int), (int)&outputs_ctx._L11_9, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 8 */ { MAP_LOCAL, "_L12", NULL, sizeof(kcg_int), (int)&outputs_ctx._L12_9, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 9 */ { MAP_LOCAL, "_L13", NULL, sizeof(kcg_int), (int)&outputs_ctx._L13_9, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 10 */ { MAP_LOCAL, "_L14", NULL, sizeof(kcg_int), (int)&outputs_ctx._L14_9, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 11 */ { MAP_LOCAL, "_L15", NULL, sizeof(kcg_int), (int)&outputs_ctx._L15_9, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 12 */ { MAP_LOCAL, "_L16", NULL, sizeof(kcg_int), (int)&outputs_ctx._L16_9, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 13 */ { MAP_LOCAL, "_L17", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L17_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 14 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 15 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 16 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 17 */ { MAP_LOCAL, "_L5", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L5_9, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 18 */ { MAP_LOCAL, "_L6", NULL, sizeof(kcg_int), (int)&outputs_ctx._L6_9, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 19 */ { MAP_LOCAL, "_L7", NULL, sizeof(kcg_int), (int)&outputs_ctx._L7_9, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 20 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_int), (int)&outputs_ctx._L8_9, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 21 */ { MAP_LOCAL, "_L9", NULL, sizeof(kcg_int), (int)&outputs_ctx._L9_9, &_Type_kcg_int_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_17 = {
  "UTI/ UTIBed 9/",
  scope_17_entries, 22,
};

/* UTI/ UTIBed 7/Toggle 2/ */
static const MappingEntry scope_16_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_2_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_2_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_2_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_2_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_2_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_16 = {
  "UTI/ UTIBed 7/Toggle 2/",
  scope_16_entries, 5,
};

/* UTI/ UTIBed 7/Toggle 1/ */
static const MappingEntry scope_15_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_1_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_1_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_1_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_1_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_1_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_15 = {
  "UTI/ UTIBed 7/Toggle 1/",
  scope_15_entries, 5,
};

/* UTI/ UTIBed 7/ */
static const MappingEntry scope_14_entries[22] = {
  /* 0 */ { MAP_OUTPUT, "BedActive", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedActive_7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_OUTPUT, "BedAllocated", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedAllocated_7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_OUTPUT, "BedColor", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor_7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_EXPANDED, "Toggle 1", NULL, 0, 0, NULL, NULL, NULL, &scope_15},
  /* 4 */ { MAP_EXPANDED, "Toggle 2", NULL, 0, 0, NULL, NULL, NULL, &scope_16},
  /* 5 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 6 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_int), (int)&outputs_ctx._L10_7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 7 */ { MAP_LOCAL, "_L11", NULL, sizeof(kcg_int), (int)&outputs_ctx._L11_7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 8 */ { MAP_LOCAL, "_L12", NULL, sizeof(kcg_int), (int)&outputs_ctx._L12_7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 9 */ { MAP_LOCAL, "_L13", NULL, sizeof(kcg_int), (int)&outputs_ctx._L13_7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 10 */ { MAP_LOCAL, "_L14", NULL, sizeof(kcg_int), (int)&outputs_ctx._L14_7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 11 */ { MAP_LOCAL, "_L15", NULL, sizeof(kcg_int), (int)&outputs_ctx._L15_7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 12 */ { MAP_LOCAL, "_L16", NULL, sizeof(kcg_int), (int)&outputs_ctx._L16_7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 13 */ { MAP_LOCAL, "_L17", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L17_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 14 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 15 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 16 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 17 */ { MAP_LOCAL, "_L5", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L5_7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 18 */ { MAP_LOCAL, "_L6", NULL, sizeof(kcg_int), (int)&outputs_ctx._L6_7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 19 */ { MAP_LOCAL, "_L7", NULL, sizeof(kcg_int), (int)&outputs_ctx._L7_7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 20 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_int), (int)&outputs_ctx._L8_7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 21 */ { MAP_LOCAL, "_L9", NULL, sizeof(kcg_int), (int)&outputs_ctx._L9_7, &_Type_kcg_int_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_14 = {
  "UTI/ UTIBed 7/",
  scope_14_entries, 22,
};

/* UTI/ UTIBed 6/Toggle 2/ */
static const MappingEntry scope_13_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_2_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_2_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_2_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_2_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_2_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_13 = {
  "UTI/ UTIBed 6/Toggle 2/",
  scope_13_entries, 5,
};

/* UTI/ UTIBed 6/Toggle 1/ */
static const MappingEntry scope_12_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_1_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_1_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_1_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_1_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_1_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_12 = {
  "UTI/ UTIBed 6/Toggle 1/",
  scope_12_entries, 5,
};

/* UTI/ UTIBed 6/ */
static const MappingEntry scope_11_entries[22] = {
  /* 0 */ { MAP_OUTPUT, "BedActive", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedActive_6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_OUTPUT, "BedAllocated", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedAllocated_6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_OUTPUT, "BedColor", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor_6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_EXPANDED, "Toggle 1", NULL, 0, 0, NULL, NULL, NULL, &scope_12},
  /* 4 */ { MAP_EXPANDED, "Toggle 2", NULL, 0, 0, NULL, NULL, NULL, &scope_13},
  /* 5 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 6 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_int), (int)&outputs_ctx._L10_6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 7 */ { MAP_LOCAL, "_L11", NULL, sizeof(kcg_int), (int)&outputs_ctx._L11_6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 8 */ { MAP_LOCAL, "_L12", NULL, sizeof(kcg_int), (int)&outputs_ctx._L12_6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 9 */ { MAP_LOCAL, "_L13", NULL, sizeof(kcg_int), (int)&outputs_ctx._L13_6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 10 */ { MAP_LOCAL, "_L14", NULL, sizeof(kcg_int), (int)&outputs_ctx._L14_6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 11 */ { MAP_LOCAL, "_L15", NULL, sizeof(kcg_int), (int)&outputs_ctx._L15_6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 12 */ { MAP_LOCAL, "_L16", NULL, sizeof(kcg_int), (int)&outputs_ctx._L16_6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 13 */ { MAP_LOCAL, "_L17", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L17_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 14 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 15 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 16 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 17 */ { MAP_LOCAL, "_L5", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L5_6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 18 */ { MAP_LOCAL, "_L6", NULL, sizeof(kcg_int), (int)&outputs_ctx._L6_6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 19 */ { MAP_LOCAL, "_L7", NULL, sizeof(kcg_int), (int)&outputs_ctx._L7_6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 20 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_int), (int)&outputs_ctx._L8_6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 21 */ { MAP_LOCAL, "_L9", NULL, sizeof(kcg_int), (int)&outputs_ctx._L9_6, &_Type_kcg_int_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_11 = {
  "UTI/ UTIBed 6/",
  scope_11_entries, 22,
};

/* UTI/ UTIBed 5/Toggle 2/ */
static const MappingEntry scope_10_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_2_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_2_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_2_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_2_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_2_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_10 = {
  "UTI/ UTIBed 5/Toggle 2/",
  scope_10_entries, 5,
};

/* UTI/ UTIBed 5/Toggle 1/ */
static const MappingEntry scope_9_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_1_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_1_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_1_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_1_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_1_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_9 = {
  "UTI/ UTIBed 5/Toggle 1/",
  scope_9_entries, 5,
};

/* UTI/ UTIBed 5/ */
static const MappingEntry scope_8_entries[22] = {
  /* 0 */ { MAP_OUTPUT, "BedActive", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedActive_5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_OUTPUT, "BedAllocated", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedAllocated_5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_OUTPUT, "BedColor", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor_5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_EXPANDED, "Toggle 1", NULL, 0, 0, NULL, NULL, NULL, &scope_9},
  /* 4 */ { MAP_EXPANDED, "Toggle 2", NULL, 0, 0, NULL, NULL, NULL, &scope_10},
  /* 5 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 6 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_int), (int)&outputs_ctx._L10_5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 7 */ { MAP_LOCAL, "_L11", NULL, sizeof(kcg_int), (int)&outputs_ctx._L11_5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 8 */ { MAP_LOCAL, "_L12", NULL, sizeof(kcg_int), (int)&outputs_ctx._L12_5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 9 */ { MAP_LOCAL, "_L13", NULL, sizeof(kcg_int), (int)&outputs_ctx._L13_5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 10 */ { MAP_LOCAL, "_L14", NULL, sizeof(kcg_int), (int)&outputs_ctx._L14_5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 11 */ { MAP_LOCAL, "_L15", NULL, sizeof(kcg_int), (int)&outputs_ctx._L15_5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 12 */ { MAP_LOCAL, "_L16", NULL, sizeof(kcg_int), (int)&outputs_ctx._L16_5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 13 */ { MAP_LOCAL, "_L17", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L17_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 14 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 15 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 16 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 17 */ { MAP_LOCAL, "_L5", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L5_5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 18 */ { MAP_LOCAL, "_L6", NULL, sizeof(kcg_int), (int)&outputs_ctx._L6_5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 19 */ { MAP_LOCAL, "_L7", NULL, sizeof(kcg_int), (int)&outputs_ctx._L7_5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 20 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_int), (int)&outputs_ctx._L8_5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 21 */ { MAP_LOCAL, "_L9", NULL, sizeof(kcg_int), (int)&outputs_ctx._L9_5, &_Type_kcg_int_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_8 = {
  "UTI/ UTIBed 5/",
  scope_8_entries, 22,
};

/* UTI/ UTIBed 4/Toggle 2/ */
static const MappingEntry scope_7_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_2_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_2_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_2_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_2_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_2_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_7 = {
  "UTI/ UTIBed 4/Toggle 2/",
  scope_7_entries, 5,
};

/* UTI/ UTIBed 4/Toggle 1/ */
static const MappingEntry scope_6_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_1_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_1_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_1_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_1_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_1_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_6 = {
  "UTI/ UTIBed 4/Toggle 1/",
  scope_6_entries, 5,
};

/* UTI/ UTIBed 4/ */
static const MappingEntry scope_5_entries[22] = {
  /* 0 */ { MAP_OUTPUT, "BedActive", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedActive_4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_OUTPUT, "BedAllocated", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedAllocated_4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_OUTPUT, "BedColor", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor_4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_EXPANDED, "Toggle 1", NULL, 0, 0, NULL, NULL, NULL, &scope_6},
  /* 4 */ { MAP_EXPANDED, "Toggle 2", NULL, 0, 0, NULL, NULL, NULL, &scope_7},
  /* 5 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 6 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_int), (int)&outputs_ctx._L10_4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 7 */ { MAP_LOCAL, "_L11", NULL, sizeof(kcg_int), (int)&outputs_ctx._L11_4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 8 */ { MAP_LOCAL, "_L12", NULL, sizeof(kcg_int), (int)&outputs_ctx._L12_4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 9 */ { MAP_LOCAL, "_L13", NULL, sizeof(kcg_int), (int)&outputs_ctx._L13_4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 10 */ { MAP_LOCAL, "_L14", NULL, sizeof(kcg_int), (int)&outputs_ctx._L14_4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 11 */ { MAP_LOCAL, "_L15", NULL, sizeof(kcg_int), (int)&outputs_ctx._L15_4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 12 */ { MAP_LOCAL, "_L16", NULL, sizeof(kcg_int), (int)&outputs_ctx._L16_4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 13 */ { MAP_LOCAL, "_L17", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L17_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 14 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 15 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 16 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 17 */ { MAP_LOCAL, "_L5", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L5_4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 18 */ { MAP_LOCAL, "_L6", NULL, sizeof(kcg_int), (int)&outputs_ctx._L6_4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 19 */ { MAP_LOCAL, "_L7", NULL, sizeof(kcg_int), (int)&outputs_ctx._L7_4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 20 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_int), (int)&outputs_ctx._L8_4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 21 */ { MAP_LOCAL, "_L9", NULL, sizeof(kcg_int), (int)&outputs_ctx._L9_4, &_Type_kcg_int_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_5 = {
  "UTI/ UTIBed 4/",
  scope_5_entries, 22,
};

/* UTI/ UTIBed 1/Toggle 2/ */
static const MappingEntry scope_4_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_2_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_2_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_2_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_2_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_2_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_4 = {
  "UTI/ UTIBed 1/Toggle 2/",
  scope_4_entries, 5,
};

/* UTI/ UTIBed 1/Toggle 1/ */
static const MappingEntry scope_3_entries[5] = {
  /* 0 */ { MAP_OUTPUT, "Output", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Output_1_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_1_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_1_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_1_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L4@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_1_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_3 = {
  "UTI/ UTIBed 1/Toggle 1/",
  scope_3_entries, 5,
};

/* UTI/ UTIBed 1/ */
static const MappingEntry scope_2_entries[22] = {
  /* 0 */ { MAP_OUTPUT, "BedActive", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedActive_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_OUTPUT, "BedAllocated", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedAllocated_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_OUTPUT, "BedColor", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_EXPANDED, "Toggle 1", NULL, 0, 0, NULL, NULL, NULL, &scope_3},
  /* 4 */ { MAP_EXPANDED, "Toggle 2", NULL, 0, 0, NULL, NULL, NULL, &scope_4},
  /* 5 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 6 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_int), (int)&outputs_ctx._L10_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 7 */ { MAP_LOCAL, "_L11", NULL, sizeof(kcg_int), (int)&outputs_ctx._L11_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 8 */ { MAP_LOCAL, "_L12", NULL, sizeof(kcg_int), (int)&outputs_ctx._L12_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 9 */ { MAP_LOCAL, "_L13", NULL, sizeof(kcg_int), (int)&outputs_ctx._L13_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 10 */ { MAP_LOCAL, "_L14", NULL, sizeof(kcg_int), (int)&outputs_ctx._L14_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 11 */ { MAP_LOCAL, "_L15", NULL, sizeof(kcg_int), (int)&outputs_ctx._L15_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 12 */ { MAP_LOCAL, "_L16", NULL, sizeof(kcg_int), (int)&outputs_ctx._L16_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 13 */ { MAP_LOCAL, "_L17", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L17_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 14 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 15 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 16 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 17 */ { MAP_LOCAL, "_L5", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L5_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 18 */ { MAP_LOCAL, "_L6", NULL, sizeof(kcg_int), (int)&outputs_ctx._L6_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 19 */ { MAP_LOCAL, "_L7", NULL, sizeof(kcg_int), (int)&outputs_ctx._L7_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 20 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_int), (int)&outputs_ctx._L8_1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 21 */ { MAP_LOCAL, "_L9", NULL, sizeof(kcg_int), (int)&outputs_ctx._L9_1, &_Type_kcg_int_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_2 = {
  "UTI/ UTIBed 1/",
  scope_2_entries, 22,
};

/* UTI/ UTI */
static const MappingEntry scope_1_entries[86] = {
  /* 0 */ { MAP_LOCAL, "@kcg0", NULL, sizeof(kcg_bool), (int)&outputs_ctx.init, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_INPUT, "ActivateBed1", NULL, sizeof(kcg_bool), (int)&inputs_ctx.ActivateBed1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_INPUT, "ActivateBed2", NULL, sizeof(kcg_bool), (int)&inputs_ctx.ActivateBed2, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_INPUT, "ActivateBed3", NULL, sizeof(kcg_bool), (int)&inputs_ctx.ActivateBed3, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_INPUT, "ActivateBed4", NULL, sizeof(kcg_bool), (int)&inputs_ctx.ActivateBed4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 5 */ { MAP_INPUT, "ActivateBed5", NULL, sizeof(kcg_bool), (int)&inputs_ctx.ActivateBed5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 6 */ { MAP_INPUT, "ActivateBed6", NULL, sizeof(kcg_bool), (int)&inputs_ctx.ActivateBed6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 7 */ { MAP_INPUT, "ActivateBed7", NULL, sizeof(kcg_bool), (int)&inputs_ctx.ActivateBed7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 8 */ { MAP_INPUT, "ActivateBed8", NULL, sizeof(kcg_bool), (int)&inputs_ctx.ActivateBed8, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 9 */ { MAP_OUTPUT, "ActiveBedsCount", NULL, sizeof(kcg_real), (int)&outputs_ctx.ActiveBedsCount, &_Type_kcg_real_Utils, NULL, NULL, NULL},
  /* 10 */ { MAP_INPUT, "AllocateBed1", NULL, sizeof(kcg_bool), (int)&inputs_ctx.AllocateBed1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 11 */ { MAP_INPUT, "AllocateBed2", NULL, sizeof(kcg_bool), (int)&inputs_ctx.AllocateBed2, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 12 */ { MAP_INPUT, "AllocateBed3", NULL, sizeof(kcg_bool), (int)&inputs_ctx.AllocateBed3, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 13 */ { MAP_INPUT, "AllocateBed4", NULL, sizeof(kcg_bool), (int)&inputs_ctx.AllocateBed4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 14 */ { MAP_INPUT, "AllocateBed5", NULL, sizeof(kcg_bool), (int)&inputs_ctx.AllocateBed5, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 15 */ { MAP_INPUT, "AllocateBed6", NULL, sizeof(kcg_bool), (int)&inputs_ctx.AllocateBed6, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 16 */ { MAP_INPUT, "AllocateBed7", NULL, sizeof(kcg_bool), (int)&inputs_ctx.AllocateBed7, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 17 */ { MAP_INPUT, "AllocateBed8", NULL, sizeof(kcg_bool), (int)&inputs_ctx.AllocateBed8, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 18 */ { MAP_OUTPUT, "AllocatedBedsCount", NULL, sizeof(kcg_real), (int)&outputs_ctx.AllocatedBedsCount, &_Type_kcg_real_Utils, NULL, NULL, NULL},
  /* 19 */ { MAP_EXPANDED, "Bed 1", NULL, 0, 0, NULL, NULL, NULL, &scope_2},
  /* 20 */ { MAP_EXPANDED, "Bed 11", NULL, 0, 0, NULL, NULL, NULL, &scope_20},
  /* 21 */ { MAP_EXPANDED, "Bed 12", NULL, 0, 0, NULL, NULL, NULL, &scope_23},
  /* 22 */ { MAP_EXPANDED, "Bed 4", NULL, 0, 0, NULL, NULL, NULL, &scope_5},
  /* 23 */ { MAP_EXPANDED, "Bed 5", NULL, 0, 0, NULL, NULL, NULL, &scope_8},
  /* 24 */ { MAP_EXPANDED, "Bed 6", NULL, 0, 0, NULL, NULL, NULL, &scope_11},
  /* 25 */ { MAP_EXPANDED, "Bed 7", NULL, 0, 0, NULL, NULL, NULL, &scope_14},
  /* 26 */ { MAP_EXPANDED, "Bed 9", NULL, 0, 0, NULL, NULL, NULL, &scope_17},
  /* 27 */ { MAP_OUTPUT, "BedColor1", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 28 */ { MAP_OUTPUT, "BedColor2", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor2, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 29 */ { MAP_OUTPUT, "BedColor3", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor3, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 30 */ { MAP_OUTPUT, "BedColor4", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor4, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 31 */ { MAP_OUTPUT, "BedColor5", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor5, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 32 */ { MAP_OUTPUT, "BedColor6", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor6, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 33 */ { MAP_OUTPUT, "BedColor7", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor7, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 34 */ { MAP_OUTPUT, "BedColor8", NULL, sizeof(kcg_int), (int)&outputs_ctx.BedColor8, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 35 */ { MAP_OUTPUT, "EmitToCDS", NULL, sizeof(kcg_bool), (int)&outputs_ctx.EmitToCDS, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 36 */ { MAP_OUTPUT, "FreeBedsCount", NULL, sizeof(kcg_real), (int)&outputs_ctx.FreeBedsCount, &_Type_kcg_real_Utils, NULL, NULL, NULL},
  /* 37 */ { MAP_OUTPUT, "LayerVisible", NULL, sizeof(kcg_bool), (int)&outputs_ctx.LayerVisible, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 38 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_int), (int)&outputs_ctx._L1, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 39 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_int), (int)&outputs_ctx._L10, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 40 */ { MAP_LOCAL, "_L11", NULL, sizeof(kcg_int), (int)&outputs_ctx._L11, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 41 */ { MAP_LOCAL, "_L12", NULL, sizeof(kcg_int), (int)&outputs_ctx._L12, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 42 */ { MAP_LOCAL, "_L13", NULL, sizeof(kcg_int), (int)&outputs_ctx._L13, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 43 */ { MAP_LOCAL, "_L14", NULL, sizeof(kcg_int), (int)&outputs_ctx._L14, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 44 */ { MAP_LOCAL, "_L15", NULL, sizeof(kcg_int), (int)&outputs_ctx._L15, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 45 */ { MAP_LOCAL, "_L16", NULL, sizeof(kcg_int), (int)&outputs_ctx._L16, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 46 */ { MAP_LOCAL, "_L17", NULL, sizeof(kcg_int), (int)&outputs_ctx._L17, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 47 */ { MAP_LOCAL, "_L18", NULL, sizeof(kcg_int), (int)&outputs_ctx._L18, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 48 */ { MAP_LOCAL, "_L19", NULL, sizeof(kcg_int), (int)&outputs_ctx._L19, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 49 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_int), (int)&outputs_ctx._L2, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 50 */ { MAP_LOCAL, "_L20", NULL, sizeof(kcg_int), (int)&outputs_ctx._L20, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 51 */ { MAP_LOCAL, "_L21", NULL, sizeof(kcg_int), (int)&outputs_ctx._L21, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 52 */ { MAP_LOCAL, "_L25", NULL, sizeof(kcg_int), (int)&outputs_ctx._L25, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 53 */ { MAP_LOCAL, "_L26", NULL, sizeof(kcg_int), (int)&outputs_ctx._L26, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 54 */ { MAP_LOCAL, "_L27", NULL, sizeof(kcg_int), (int)&outputs_ctx._L27, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 55 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_int), (int)&outputs_ctx._L3, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 56 */ { MAP_LOCAL, "_L31", NULL, sizeof(kcg_int), (int)&outputs_ctx._L31, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 57 */ { MAP_LOCAL, "_L32", NULL, sizeof(kcg_int), (int)&outputs_ctx._L32, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 58 */ { MAP_LOCAL, "_L33", NULL, sizeof(kcg_int), (int)&outputs_ctx._L33, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 59 */ { MAP_LOCAL, "_L34", NULL, sizeof(kcg_int), (int)&outputs_ctx._L34, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 60 */ { MAP_LOCAL, "_L35", NULL, sizeof(kcg_int), (int)&outputs_ctx._L35, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 61 */ { MAP_LOCAL, "_L36", NULL, sizeof(kcg_int), (int)&outputs_ctx._L36, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 62 */ { MAP_LOCAL, "_L45", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L45, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 63 */ { MAP_LOCAL, "_L46", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L46, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 64 */ { MAP_LOCAL, "_L47", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L47, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 65 */ { MAP_LOCAL, "_L48", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L48, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 66 */ { MAP_LOCAL, "_L49", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L49, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 67 */ { MAP_LOCAL, "_L50", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L50, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 68 */ { MAP_LOCAL, "_L51", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L51, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 69 */ { MAP_LOCAL, "_L52", NULL, sizeof(kcg_int), (int)&outputs_ctx._L52, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 70 */ { MAP_LOCAL, "_L54", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L54, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 71 */ { MAP_LOCAL, "_L55", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L55, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 72 */ { MAP_LOCAL, "_L56", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L56, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 73 */ { MAP_LOCAL, "_L57", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L57, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 74 */ { MAP_LOCAL, "_L58", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L58, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 75 */ { MAP_LOCAL, "_L59", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L59, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 76 */ { MAP_LOCAL, "_L60", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L60, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 77 */ { MAP_LOCAL, "_L61", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L61, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 78 */ { MAP_LOCAL, "_L62", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L62, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 79 */ { MAP_LOCAL, "_L66", NULL, sizeof(kcg_int), (int)&outputs_ctx._L66, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 80 */ { MAP_LOCAL, "_L67", NULL, sizeof(kcg_int), (int)&outputs_ctx._L67, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 81 */ { MAP_LOCAL, "_L68", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L68, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 82 */ { MAP_LOCAL, "_L69", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L69, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 83 */ { MAP_LOCAL, "_L70", NULL, sizeof(kcg_real), (int)&outputs_ctx._L70, &_Type_kcg_real_Utils, NULL, NULL, NULL},
  /* 84 */ { MAP_LOCAL, "_L71", NULL, sizeof(kcg_real), (int)&outputs_ctx._L71, &_Type_kcg_real_Utils, NULL, NULL, NULL},
  /* 85 */ { MAP_LOCAL, "_L72", NULL, sizeof(kcg_real), (int)&outputs_ctx._L72, &_Type_kcg_real_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_1 = {
  "UTI/ UTI",
  scope_1_entries, 86,
};

/*  */
static const MappingEntry scope_0_entries[1] = {
  /* 0 */ { MAP_ROOT, "UTI", NULL, 0, 0, NULL, NULL, NULL, &scope_1}
};
static const MappingScope scope_0 = {
  "",
  scope_0_entries, 1,
};

const MappingScope* pTop = &scope_0;

