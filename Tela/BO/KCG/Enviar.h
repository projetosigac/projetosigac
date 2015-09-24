/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/Goku/Desktop/scade/BO/BO/BO/KCG\kcg_s2c_config.txt
** Generation date: 2015-09-23T22:28:15
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
  /* ----------------- no clocks of observable data ------------------ */
} outC_Enviar;

/* ===========  node initialization and cycle functions  =========== */
/* Enviar */
extern void Enviar(inC_Enviar *inC, outC_Enviar *outC);

extern void Enviar_reset(outC_Enviar *outC);

#endif /* _Enviar_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** Enviar.h
** Generation date: 2015-09-23T22:28:15
*************************************************************$ */

