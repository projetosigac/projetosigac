/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/Goku/Desktop/scade/BO/BO/BO/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-24T00:58:59
*************************************************************$ */
#ifndef _Enviar_H_
#define _Enviar_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_bool /* Enviar::enviar */ enviar;
  kcg_bool /* Enviar::sinal_completo */ sinal_completo;
  String /* Enviar::rg */ rg;
  String /* Enviar::hora_fim_atend */ hora_fim_atend;
  String /* Enviar::hora_ini_atend */ hora_ini_atend;
  String /* Enviar::dt_fim_atend */ dt_fim_atend;
  String /* Enviar::dt_ini_atend */ dt_ini_atend;
  String /* Enviar::hora_fato */ hora_fato;
  String /* Enviar::dt_fato */ dt_fato;
  BigText /* Enviar::description */ description;
} inC_Enviar;

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  Boletim /* Enviar::BO_saida */ BO_saida;
  kcg_bool /* Enviar::saida_pronta */ saida_pronta;
  kcg_bool /* Enviar::Layer1Visible */ Layer1Visible;
  kcg_bool /* Enviar::Layer1Active */ Layer1Active;
  kcg_bool /* Enviar::Emit2CDS */ Emit2CDS;
  Name /* Enviar::TextBtnEnviar */ TextBtnEnviar;
  kcg_int /* Enviar::StringSize */ StringSize;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  SSM_ST_SM1 /* Enviar::SM1 */ SM1_state_nxt;
  kcg_bool /* Enviar::SM1 */ SM1_reset_act;
  kcg_bool /* Enviar::SM1 */ SM1_reset_nxt;
  kcg_bool /* Enviar::_L32 */ _L32;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ------------------ clocks of observable data -------------------- */
  SSM_ST_SM1 /* Enviar::SM1 */ SM1_state_act;
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_bool /* Enviar::SM1::Enviando */ Enviando_weakb_clock_SM1;
  SSM_ST_SM1 /* Enviar::SM1 */ SM1_state_sel;
  SSM_TR_SM1 /* Enviar::SM1 */ SM1_fired_strong;
  SSM_TR_SM1 /* Enviar::SM1 */ SM1_fired;
  kcg_bool /* Enviar::envio_completo */ envio_completo;
  kcg_bool /* Enviar::enviar_ativo */ enviar_ativo;
  kcg_bool /* Enviar::_L2 */ _L2;
  kcg_bool /* Enviar::_L3 */ _L3;
  String /* Enviar::_L24 */ _L24;
  String /* Enviar::_L23 */ _L23;
  String /* Enviar::_L22 */ _L22;
  BigText /* Enviar::_L21 */ _L21;
  struct__273 /* Enviar::_L20 */ _L20;
  String /* Enviar::_L19 */ _L19;
  String /* Enviar::_L18 */ _L18;
  String /* Enviar::_L17 */ _L17;
  String /* Enviar::_L16 */ _L16;
  kcg_bool /* Enviar::_L25 */ _L25;
  kcg_bool /* Enviar::_L31 */ _L31;
  kcg_bool /* Enviar::_L33 */ _L33;
  kcg_int /* Enviar::_L35 */ _L35;
  Name /* Enviar::_L34 */ _L34;
} outC_Enviar;

/* ===========  node initialization and cycle functions  =========== */
/* Enviar */
extern void Enviar(inC_Enviar *inC, outC_Enviar *outC);

extern void Enviar_reset(outC_Enviar *outC);

#endif /* _Enviar_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** Enviar.h
** Generation date: 2015-09-24T00:58:59
*************************************************************$ */

