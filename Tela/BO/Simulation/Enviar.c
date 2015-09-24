/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/Goku/Desktop/scade/BO/BO/BO/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-24T00:58:59
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Enviar.h"

void Enviar_reset(outC_Enviar *outC)
{
  outC->init = kcg_true;
}

/* Enviar */
void Enviar(inC_Enviar *inC, outC_Enviar *outC)
{
  /* Enviar::SM1 */ SSM_TR_SM1 _3_SM1_fired;
  /* Enviar::SM1 */ kcg_bool _2_SM1_reset_nxt;
  /* Enviar::SM1 */ SSM_ST_SM1 _1_SM1_state_nxt;
  /* Enviar::SM1 */ SSM_TR_SM1 SM1_fired;
  /* Enviar::SM1 */ kcg_bool SM1_reset_nxt;
  /* Enviar::SM1 */ SSM_ST_SM1 SM1_state_nxt;
  /* Enviar::SM1::Enviando */ kcg_bool br_1_guard_SM1_Enviando;
  /* Enviar::SM1 */ SSM_ST_SM1 _4_SM1_state_nxt;
  /* Enviar::SM1 */ kcg_bool _5_SM1_reset_nxt;
  /* Enviar::SM1 */ SSM_TR_SM1 _6_SM1_fired;
  /* Enviar::SM1 */ SSM_ST_SM1 _7_SM1_state_nxt;
  /* Enviar::SM1 */ kcg_bool _8_SM1_reset_nxt;
  /* Enviar::SM1 */ SSM_TR_SM1 _9_SM1_fired;
  /* Enviar::SM1 */ SSM_TR_SM1 _12_SM1_fired_strong;
  /* Enviar::SM1 */ kcg_bool _11_SM1_reset_act;
  /* Enviar::SM1 */ SSM_ST_SM1 _10_SM1_state_act;
  /* Enviar::SM1::Espera_Enviar */ kcg_bool br_1_guard_SM1_Espera_Enviar;
  /* Enviar::SM1 */ SSM_TR_SM1 SM1_fired_strong;
  /* Enviar::SM1 */ kcg_bool SM1_reset_act;
  /* Enviar::SM1 */ SSM_ST_SM1 SM1_state_act;
  /* Enviar::SM1 */ kcg_bool SM1_reset_sel;
  /* Enviar::SM1 */ kcg_bool SM1_reset_prv;
  
  kcg_copy_Name(&outC->_L34, (Name *) &TEXTO_BTN_ENVIAR);
  kcg_copy_Name(&outC->TextBtnEnviar, &outC->_L34);
  outC->_L35 = STR_SIZE;
  outC->StringSize = outC->_L35;
  outC->_L33 = kcg_true;
  outC->Emit2CDS = outC->_L33;
  if (outC->init) {
    outC->_L31 = kcg_true;
  }
  else {
    outC->_L31 = outC->_L32;
  }
  outC->_L32 = kcg_false;
  outC->Layer1Visible = outC->_L31;
  outC->Layer1Active = outC->_L31;
  outC->_L2 = inC->enviar;
  outC->enviar_ativo = outC->_L2;
  outC->_L25 = outC->enviar_ativo;
  outC->saida_pronta = outC->_L25;
  kcg_copy_BigText(&outC->_L21, &inC->description);
  kcg_copy_String(&outC->_L24, &inC->dt_fato);
  kcg_copy_String(&outC->_L22, &inC->hora_fato);
  kcg_copy_String(&outC->_L16, &inC->dt_ini_atend);
  kcg_copy_String(&outC->_L23, &inC->hora_ini_atend);
  kcg_copy_String(&outC->_L17, &inC->dt_fim_atend);
  kcg_copy_String(&outC->_L19, &inC->hora_fim_atend);
  kcg_copy_String(&outC->_L18, &inC->rg);
  kcg_copy_BigText(&outC->_L20.description, &outC->_L21);
  kcg_copy_String(&outC->_L20.dt_fato, &outC->_L24);
  kcg_copy_String(&outC->_L20.hora_fato, &outC->_L22);
  kcg_copy_String(&outC->_L20.dt_ini_atend, &outC->_L16);
  kcg_copy_String(&outC->_L20.hora_ini_atend, &outC->_L23);
  kcg_copy_String(&outC->_L20.dt_fim_atend, &outC->_L17);
  kcg_copy_String(&outC->_L20.hora_fim_atend, &outC->_L19);
  kcg_copy_String(&outC->_L20.rg, &outC->_L18);
  kcg_copy_Boletim(&outC->BO_saida, &outC->_L20);
  outC->_L3 = inC->sinal_completo;
  outC->envio_completo = outC->_L3;
  if (outC->init) {
    outC->SM1_state_sel = SSM_st_Espera_Enviar_SM1;
  }
  else {
    outC->SM1_state_sel = outC->SM1_state_nxt;
  }
  switch (outC->SM1_state_sel) {
    case SSM_st_Espera_Enviar_SM1 :
      br_1_guard_SM1_Espera_Enviar = outC->enviar_ativo;
      if (br_1_guard_SM1_Espera_Enviar) {
        _10_SM1_state_act = SSM_st_Enviando_SM1;
      }
      else {
        _10_SM1_state_act = SSM_st_Espera_Enviar_SM1;
      }
      outC->SM1_state_act = _10_SM1_state_act;
      if (br_1_guard_SM1_Espera_Enviar) {
        _12_SM1_fired_strong = SSM_TR_Espera_Enviar_1_SM1;
      }
      else {
        _12_SM1_fired_strong = SSM_TR_no_trans_SM1;
      }
      outC->SM1_fired_strong = _12_SM1_fired_strong;
      break;
    case SSM_st_Enviando_SM1 :
      SM1_state_act = SSM_st_Enviando_SM1;
      outC->SM1_state_act = SM1_state_act;
      SM1_fired_strong = SSM_TR_no_trans_SM1;
      outC->SM1_fired_strong = SM1_fired_strong;
      break;
    
  }
  switch (outC->SM1_state_act) {
    case SSM_st_Espera_Enviar_SM1 :
      _3_SM1_fired = outC->SM1_fired_strong;
      _2_SM1_reset_nxt = kcg_false;
      _1_SM1_state_nxt = SSM_st_Espera_Enviar_SM1;
      outC->SM1_fired = _3_SM1_fired;
      break;
    case SSM_st_Enviando_SM1 :
      outC->Enviando_weakb_clock_SM1 = outC->SM1_fired_strong !=
        SSM_TR_no_trans_SM1;
      if (outC->Enviando_weakb_clock_SM1) {
        _9_SM1_fired = outC->SM1_fired_strong;
        _8_SM1_reset_nxt = kcg_false;
        _7_SM1_state_nxt = SSM_st_Enviando_SM1;
        SM1_fired = _9_SM1_fired;
        SM1_reset_nxt = _8_SM1_reset_nxt;
        SM1_state_nxt = _7_SM1_state_nxt;
      }
      else {
        br_1_guard_SM1_Enviando = outC->envio_completo;
        if (br_1_guard_SM1_Enviando) {
          _6_SM1_fired = SSM_TR_Enviando_1_SM1;
        }
        else {
          _6_SM1_fired = SSM_TR_no_trans_SM1;
        }
        _5_SM1_reset_nxt = br_1_guard_SM1_Enviando;
        if (br_1_guard_SM1_Enviando) {
          _4_SM1_state_nxt = SSM_st_Espera_Enviar_SM1;
        }
        else {
          _4_SM1_state_nxt = SSM_st_Enviando_SM1;
        }
        SM1_fired = _6_SM1_fired;
        SM1_reset_nxt = _5_SM1_reset_nxt;
        SM1_state_nxt = _4_SM1_state_nxt;
      }
      outC->SM1_fired = SM1_fired;
      break;
    
  }
  if (outC->init) {
    SM1_reset_sel = kcg_false;
  }
  else {
    SM1_reset_sel = outC->SM1_reset_nxt;
  }
  switch (outC->SM1_state_act) {
    case SSM_st_Espera_Enviar_SM1 :
      outC->SM1_reset_nxt = _2_SM1_reset_nxt;
      outC->SM1_state_nxt = _1_SM1_state_nxt;
      break;
    case SSM_st_Enviando_SM1 :
      outC->SM1_reset_nxt = SM1_reset_nxt;
      outC->SM1_state_nxt = SM1_state_nxt;
      break;
    
  }
  switch (outC->SM1_state_sel) {
    case SSM_st_Espera_Enviar_SM1 :
      _11_SM1_reset_act = br_1_guard_SM1_Espera_Enviar;
      break;
    case SSM_st_Enviando_SM1 :
      SM1_reset_act = kcg_false;
      break;
    
  }
  if (outC->init) {
    SM1_reset_prv = kcg_false;
  }
  else {
    SM1_reset_prv = outC->SM1_reset_act;
  }
  switch (outC->SM1_state_sel) {
    case SSM_st_Espera_Enviar_SM1 :
      outC->SM1_reset_act = _11_SM1_reset_act;
      break;
    case SSM_st_Enviando_SM1 :
      outC->SM1_reset_act = SM1_reset_act;
      break;
    
  }
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** Enviar.c
** Generation date: 2015-09-24T00:58:59
*************************************************************$ */

