/* BombeirosRescaldo_newmapping.c */

#include <stddef.h>

#include "NewSmuTypes.h"
#include "SmuMapping.h"
#include "BombeirosRescaldo_newtype.h"
#include "BombeirosRescaldo_newmapping.h"

/* iterators */

/* clock active helper functions */

/* forward declarations */
#define MAP_DECL(ident, nb) static const MappingEntry ident##_entries[nb]; static const MappingScope ident
MAP_DECL(scope_2, 4);
MAP_DECL(scope_1, 8);
MAP_DECL(scope_0, 1);

/* Main/ MainInitDF 1/ */
static const MappingEntry scope_2_entries[4] = {
  /* 0 */ { MAP_OUTPUT, "ReqLayerActive", NULL, sizeof(kcg_bool), (int)&outputs_ctx.ReqLayerActive_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_OUTPUT, "ReqLayerVisible", NULL, sizeof(kcg_bool), (int)&outputs_ctx.ReqLayerVisible_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_LOCAL, "_L2@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2_1, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_2 = {
  "Main/ MainInitDF 1/",
  scope_2_entries, 4,
};

/* Main/ Main */
static const MappingEntry scope_1_entries[8] = {
  /* 0 */ { MAP_LOCAL, "@kcg0", NULL, sizeof(kcg_bool), (int)&outputs_ctx.init, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_OUTPUT, "EmitToCDS", NULL, sizeof(kcg_bool), (int)&outputs_ctx.EmitToCDS, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 2 */ { MAP_EXPANDED, "InitDF 1", NULL, 0, 0, NULL, NULL, NULL, &scope_2},
  /* 3 */ { MAP_OUTPUT, "ReqLayerActive", NULL, sizeof(kcg_bool), (int)&outputs_ctx.ReqLayerActive, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_OUTPUT, "ReqLayerVisible", NULL, sizeof(kcg_bool), (int)&outputs_ctx.ReqLayerVisible, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 5 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L1, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 6 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 7 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_1 = {
  "Main/ Main",
  scope_1_entries, 8,
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

