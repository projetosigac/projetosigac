/* SurgeryCounts_newmapping.c */

#include <stddef.h>

#include "NewSmuTypes.h"
#include "SmuMapping.h"
#include "SurgeryCounts_newtype.h"
#include "SurgeryCounts_newmapping.h"

/* iterators */

/* clock active helper functions */

/* forward declarations */
#define MAP_DECL(ident, nb) static const MappingEntry ident##_entries[nb]; static const MappingScope ident
MAP_DECL(scope_1, 12);
MAP_DECL(scope_0, 1);

/* SurgeryCounts/ SurgeryCounts */
static const MappingEntry scope_1_entries[12] = {
  /* 0 */ { MAP_OUTPUT, "EmitToCDS", NULL, sizeof(kcg_bool), (int)&outputs_ctx.EmitToCDS, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_OUTPUT, "LayerVisible", NULL, sizeof(kcg_bool), (int)&outputs_ctx.LayerVisible, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_real), (int)&outputs_ctx._L1, &_Type_kcg_real_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_real), (int)&outputs_ctx._L2, &_Type_kcg_real_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_real), (int)&outputs_ctx._L3, &_Type_kcg_real_Utils, NULL, NULL, NULL},
  /* 5 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L4, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 6 */ { MAP_INPUT, "availableInput", NULL, sizeof(kcg_real), (int)&inputs_ctx.availableInput, &_Type_kcg_real_Utils, NULL, NULL, NULL},
  /* 7 */ { MAP_OUTPUT, "availableOutput", NULL, sizeof(kcg_real), (int)&outputs_ctx.availableOutput, &_Type_kcg_real_Utils, NULL, NULL, NULL},
  /* 8 */ { MAP_INPUT, "occupiedInput", NULL, sizeof(kcg_real), (int)&inputs_ctx.occupiedInput, &_Type_kcg_real_Utils, NULL, NULL, NULL},
  /* 9 */ { MAP_OUTPUT, "occupiedOutput", NULL, sizeof(kcg_real), (int)&outputs_ctx.occupiedOutput, &_Type_kcg_real_Utils, NULL, NULL, NULL},
  /* 10 */ { MAP_INPUT, "totalInput", NULL, sizeof(kcg_real), (int)&inputs_ctx.totalInput, &_Type_kcg_real_Utils, NULL, NULL, NULL},
  /* 11 */ { MAP_OUTPUT, "totalOutput", NULL, sizeof(kcg_real), (int)&outputs_ctx.totalOutput, &_Type_kcg_real_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_1 = {
  "SurgeryCounts/ SurgeryCounts",
  scope_1_entries, 12,
};

/*  */
static const MappingEntry scope_0_entries[1] = {
  /* 0 */ { MAP_ROOT, "SurgeryCounts", NULL, 0, 0, NULL, NULL, NULL, &scope_1}
};
static const MappingScope scope_0 = {
  "",
  scope_0_entries, 1,
};

const MappingScope* pTop = &scope_0;

