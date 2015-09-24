/* BO_newmapping.c */

#include <stddef.h>

#include "NewSmuTypes.h"
#include "SmuMapping.h"
#include "BO_newtype.h"
#include "BO_newmapping.h"

/* iterators */
static const MappingIterator iter_5;
static const MappingIterator iter_20;
static const MappingIterator iter_1000;
static const MappingIterator iter_5 = { 5, NULL};
static const MappingIterator iter_20 = { 20, NULL};
static const MappingIterator iter_1000 = { 1000, NULL};

/* clock active helper functions */

/* forward declarations */
#define MAP_DECL(ident, nb) static const MappingEntry ident##_entries[nb]; static const MappingScope ident
MAP_DECL(scope_16, 1);
MAP_DECL(scope_15, 8);
MAP_DECL(scope_14, 1);
MAP_DECL(scope_13, 1);
MAP_DECL(scope_8, 1);
MAP_DECL(scope_7, 2);
MAP_DECL(scope_6, 1);
MAP_DECL(scope_5, 1);
MAP_DECL(scope_2, 2);
MAP_DECL(scope_1, 38);
MAP_DECL(scope_0, 1);

/* array_char_5 */
static const MappingEntry scope_16_entries[1] = {
  /* 0 */ { MAP_ARRAY, "", &iter_5, sizeof(kcg_char), 0, &_Type_kcg_char_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_16 = {
  "array_char_5",
  scope_16_entries, 1,
};

/* struct__273 */
static const MappingEntry scope_15_entries[8] = {
  /* 0 */ { MAP_FIELD, ".description", NULL, sizeof(array_char_1000), offsetof(struct__273, description), &_Type_array_char_1000_Utils, NULL, NULL, &scope_13},
  /* 1 */ { MAP_FIELD, ".dt_fato", NULL, sizeof(array_char_20), offsetof(struct__273, dt_fato), &_Type_array_char_20_Utils, NULL, NULL, &scope_14},
  /* 2 */ { MAP_FIELD, ".dt_fim_atend", NULL, sizeof(array_char_20), offsetof(struct__273, dt_fim_atend), &_Type_array_char_20_Utils, NULL, NULL, &scope_14},
  /* 3 */ { MAP_FIELD, ".dt_ini_atend", NULL, sizeof(array_char_20), offsetof(struct__273, dt_ini_atend), &_Type_array_char_20_Utils, NULL, NULL, &scope_14},
  /* 4 */ { MAP_FIELD, ".hora_fato", NULL, sizeof(array_char_20), offsetof(struct__273, hora_fato), &_Type_array_char_20_Utils, NULL, NULL, &scope_14},
  /* 5 */ { MAP_FIELD, ".hora_fim_atend", NULL, sizeof(array_char_20), offsetof(struct__273, hora_fim_atend), &_Type_array_char_20_Utils, NULL, NULL, &scope_14},
  /* 6 */ { MAP_FIELD, ".hora_ini_atend", NULL, sizeof(array_char_20), offsetof(struct__273, hora_ini_atend), &_Type_array_char_20_Utils, NULL, NULL, &scope_14},
  /* 7 */ { MAP_FIELD, ".rg", NULL, sizeof(array_char_20), offsetof(struct__273, rg), &_Type_array_char_20_Utils, NULL, NULL, &scope_14}
};
static const MappingScope scope_15 = {
  "struct__273",
  scope_15_entries, 8,
};

/* array_char_20 */
static const MappingEntry scope_14_entries[1] = {
  /* 0 */ { MAP_ARRAY, "", &iter_20, sizeof(kcg_char), 0, &_Type_kcg_char_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_14 = {
  "array_char_20",
  scope_14_entries, 1,
};

/* array_char_1000 */
static const MappingEntry scope_13_entries[1] = {
  /* 0 */ { MAP_ARRAY, "", &iter_1000, sizeof(kcg_char), 0, &_Type_kcg_char_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_13 = {
  "array_char_1000",
  scope_13_entries, 1,
};

/* Enviar/ EnviarSM1:Enviando:<1 */
static const MappingEntry scope_8_entries[1] = {
  /* 0 */ { MAP_TRANSITION, ">:", NULL, 0, 0, NULL, NULL, NULL /* CLOCK SM1_fired */, NULL}
};
static const MappingScope scope_8 = {
  "Enviar/ EnviarSM1:Enviando:<1",
  scope_8_entries, 1,
};

/* Enviar/ EnviarSM1:Enviando: */
static const MappingEntry scope_7_entries[2] = {
  /* 0 */ { MAP_FORK, "<1", NULL, 0, 0, NULL, NULL, NULL, &scope_8},
  /* 1 */ { MAP_LOCAL, "@kcg1", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Enviando_weakb_clock_SM1, &_Type_kcg_bool_Utils, NULL, NULL /* CLOCK SM1_state_act */, NULL}
};
static const MappingScope scope_7 = {
  "Enviar/ EnviarSM1:Enviando:",
  scope_7_entries, 2,
};

/* Enviar/ EnviarSM1:Espera_Enviar:<1 */
static const MappingEntry scope_6_entries[1] = {
  /* 0 */ { MAP_TRANSITION, ">:", NULL, 0, 0, NULL, NULL, NULL /* CLOCK SM1_fired_strong */, NULL}
};
static const MappingScope scope_6 = {
  "Enviar/ EnviarSM1:Espera_Enviar:<1",
  scope_6_entries, 1,
};

/* Enviar/ EnviarSM1:Espera_Enviar: */
static const MappingEntry scope_5_entries[1] = {
  /* 0 */ { MAP_FORK, "<1", NULL, 0, 0, NULL, NULL, NULL, &scope_6}
};
static const MappingScope scope_5 = {
  "Enviar/ EnviarSM1:Espera_Enviar:",
  scope_5_entries, 1,
};

/* Enviar/ EnviarSM1: */
static const MappingEntry scope_2_entries[2] = {
  /* 0 */ { MAP_STATE, "Enviando:", NULL, 0, 0, NULL, NULL, NULL /* CLOCK SM1_state_act */, &scope_7},
  /* 1 */ { MAP_STATE, "Espera_Enviar:", NULL, 0, 0, NULL, NULL, NULL /* CLOCK SM1_state_act */, &scope_5}
};
static const MappingScope scope_2 = {
  "Enviar/ EnviarSM1:",
  scope_2_entries, 2,
};

/* Enviar/ Enviar */
static const MappingEntry scope_1_entries[38] = {
  /* 0 */ { MAP_LOCAL, "@kcg0", NULL, sizeof(kcg_bool), (int)&outputs_ctx.init, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 1 */ { MAP_OUTPUT, "BO_saida", NULL, sizeof(Boletim), (int)&outputs_ctx.BO_saida, &_Type_Boletim_Utils, NULL, NULL, &scope_15},
  /* 2 */ { MAP_OUTPUT, "Emit2CDS", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Emit2CDS, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 3 */ { MAP_OUTPUT, "Layer1Active", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Layer1Active, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 4 */ { MAP_OUTPUT, "Layer1Visible", NULL, sizeof(kcg_bool), (int)&outputs_ctx.Layer1Visible, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 5 */ { MAP_AUTOMATON, "SM1:", NULL, 0, 0, NULL, NULL, NULL, &scope_2},
  /* 6 */ { MAP_OUTPUT, "StringSize", NULL, sizeof(kcg_int), (int)&outputs_ctx.StringSize, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 7 */ { MAP_OUTPUT, "TextBtnEnviar", NULL, sizeof(Name), (int)&outputs_ctx.TextBtnEnviar, &_Type_Name_Utils, NULL, NULL, &scope_16},
  /* 8 */ { MAP_LOCAL, "_L16", NULL, sizeof(String), (int)&outputs_ctx._L16, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 9 */ { MAP_LOCAL, "_L17", NULL, sizeof(String), (int)&outputs_ctx._L17, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 10 */ { MAP_LOCAL, "_L18", NULL, sizeof(String), (int)&outputs_ctx._L18, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 11 */ { MAP_LOCAL, "_L19", NULL, sizeof(String), (int)&outputs_ctx._L19, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 12 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L2, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 13 */ { MAP_LOCAL, "_L20", NULL, sizeof(struct__273), (int)&outputs_ctx._L20, &_Type_struct__273_Utils, NULL, NULL, &scope_15},
  /* 14 */ { MAP_LOCAL, "_L21", NULL, sizeof(BigText), (int)&outputs_ctx._L21, &_Type_BigText_Utils, NULL, NULL, &scope_13},
  /* 15 */ { MAP_LOCAL, "_L22", NULL, sizeof(String), (int)&outputs_ctx._L22, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 16 */ { MAP_LOCAL, "_L23", NULL, sizeof(String), (int)&outputs_ctx._L23, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 17 */ { MAP_LOCAL, "_L24", NULL, sizeof(String), (int)&outputs_ctx._L24, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 18 */ { MAP_LOCAL, "_L25", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L25, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 19 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L3, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 20 */ { MAP_LOCAL, "_L31", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L31, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 21 */ { MAP_LOCAL, "_L32@mem", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L32, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 22 */ { MAP_LOCAL, "_L33", NULL, sizeof(kcg_bool), (int)&outputs_ctx._L33, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 23 */ { MAP_LOCAL, "_L34", NULL, sizeof(Name), (int)&outputs_ctx._L34, &_Type_Name_Utils, NULL, NULL, &scope_16},
  /* 24 */ { MAP_LOCAL, "_L35", NULL, sizeof(kcg_int), (int)&outputs_ctx._L35, &_Type_kcg_int_Utils, NULL, NULL, NULL},
  /* 25 */ { MAP_INPUT, "description", NULL, sizeof(BigText), (int)&inputs_ctx.description, &_Type_BigText_Utils, NULL, NULL, &scope_13},
  /* 26 */ { MAP_INPUT, "dt_fato", NULL, sizeof(String), (int)&inputs_ctx.dt_fato, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 27 */ { MAP_INPUT, "dt_fim_atend", NULL, sizeof(String), (int)&inputs_ctx.dt_fim_atend, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 28 */ { MAP_INPUT, "dt_ini_atend", NULL, sizeof(String), (int)&inputs_ctx.dt_ini_atend, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 29 */ { MAP_INPUT, "enviar", NULL, sizeof(kcg_bool), (int)&inputs_ctx.enviar, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 30 */ { MAP_LOCAL, "enviar_ativo", NULL, sizeof(kcg_bool), (int)&outputs_ctx.enviar_ativo, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 31 */ { MAP_LOCAL, "envio_completo", NULL, sizeof(kcg_bool), (int)&outputs_ctx.envio_completo, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 32 */ { MAP_INPUT, "hora_fato", NULL, sizeof(String), (int)&inputs_ctx.hora_fato, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 33 */ { MAP_INPUT, "hora_fim_atend", NULL, sizeof(String), (int)&inputs_ctx.hora_fim_atend, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 34 */ { MAP_INPUT, "hora_ini_atend", NULL, sizeof(String), (int)&inputs_ctx.hora_ini_atend, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 35 */ { MAP_INPUT, "rg", NULL, sizeof(String), (int)&inputs_ctx.rg, &_Type_String_Utils, NULL, NULL, &scope_14},
  /* 36 */ { MAP_OUTPUT, "saida_pronta", NULL, sizeof(kcg_bool), (int)&outputs_ctx.saida_pronta, &_Type_kcg_bool_Utils, NULL, NULL, NULL},
  /* 37 */ { MAP_INPUT, "sinal_completo", NULL, sizeof(kcg_bool), (int)&inputs_ctx.sinal_completo, &_Type_kcg_bool_Utils, NULL, NULL, NULL}
};
static const MappingScope scope_1 = {
  "Enviar/ Enviar",
  scope_1_entries, 38,
};

/*  */
static const MappingEntry scope_0_entries[1] = {
  /* 0 */ { MAP_ROOT, "Enviar", NULL, 0, 0, NULL, NULL, NULL, &scope_1}
};
static const MappingScope scope_0 = {
  "",
  scope_0_entries, 1,
};

const MappingScope* pTop = &scope_0;

