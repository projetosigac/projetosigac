/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/Goku/Desktop/scade/BO/BO/BO/KCG\kcg_s2c_config.txt
** Generation date: 2015-09-23T22:28:15
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
  /* Enviar::SM1::Enviando */ kcg_bool Enviando_weakb_clock_SM1;
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
  /* Enviar::SM1 */ SSM_ST_SM1 SM1_state_sel;
  /* Enviar::SM1 */ SSM_ST_SM1 _15_SM1_state_act;
  /* Enviar::SM1 */ kcg_bool SM1_reset_sel;
  /* Enviar::SM1 */ kcg_bool SM1_reset_prv;
  /* Enviar::SM1 */ SSM_TR_SM1 _14_SM1_fired_strong;
  /* Enviar::SM1 */ SSM_TR_SM1 _13_SM1_fired;
  /* Enviar::envio_completo */ kcg_bool envio_completo;
  /* Enviar::enviar_ativo */ kcg_bool enviar_ativo;
  /* Enviar::_L2 */ kcg_bool _L2;
  /* Enviar::_L3 */ kcg_bool _L3;
  /* Enviar::_L24 */ String _L24;
  /* Enviar::_L23 */ String _L23;
  /* Enviar::_L22 */ String _L22;
  /* Enviar::_L21 */ BigText _L21;
  /* Enviar::_L20 */ struct__273 _L20;
  /* Enviar::_L19 */ String _L19;
  /* Enviar::_L18 */ String _L18;
  /* Enviar::_L17 */ String _L17;
  /* Enviar::_L16 */ String _L16;
  /* Enviar::_L25 */ kcg_bool _L25;
  /* Enviar::_L31 */ kcg_bool _L31;
  /* Enviar::_L33 */ kcg_bool _L33;
  /* Enviar::_L35 */ kcg_int _L35;
  /* Enviar::_L34 */ Name _L34;
  
  kcg_copy_Name(&_L34, (Name *) &TEXTO_BTN_ENVIAR);
  kcg_copy_Name(&outC->TextBtnEnviar, &_L34);
  _L35 = STR_SIZE;
  outC->StringSize = _L35;
  _L33 = kcg_true;
  outC->Emit2CDS = _L33;
  if (outC->init) {
    _L31 = kcg_true;
  }
  else {
    _L31 = outC->_L32;
  }
  outC->_L32 = kcg_false;
  outC->Layer1Visible = _L31;
  outC->Layer1Active = _L31;
  _L2 = inC->enviar;
  enviar_ativo = _L2;
  _L25 = enviar_ativo;
  outC->saida_pronta = _L25;
  kcg_copy_BigText(&_L21, &inC->description);
  kcg_copy_String(&_L24, &inC->dt_fato);
  kcg_copy_String(&_L22, &inC->hora_fato);
  kcg_copy_String(&_L16, &inC->dt_ini_atend);
  kcg_copy_String(&_L23, &inC->hora_ini_atend);
  kcg_copy_String(&_L17, &inC->dt_fim_atend);
  kcg_copy_String(&_L19, &inC->hora_fim_atend);
  kcg_copy_String(&_L18, &inC->rg);
  kcg_copy_BigText(&_L20.description, &_L21);
  kcg_copy_String(&_L20.dt_fato, &_L24);
  kcg_copy_String(&_L20.hora_fato, &_L22);
  kcg_copy_String(&_L20.dt_ini_atend, &_L16);
  kcg_copy_String(&_L20.hora_ini_atend, &_L23);
  kcg_copy_String(&_L20.dt_fim_atend, &_L17);
  kcg_copy_String(&_L20.hora_fim_atend, &_L19);
  kcg_copy_String(&_L20.rg, &_L18);
  kcg_copy_Boletim(&outC->BO_saida, &_L20);
  _L3 = inC->sinal_completo;
  envio_completo = _L3;
  if (outC->init) {
    SM1_state_sel = SSM_st_Espera_Enviar_SM1;
  }
  else {
    SM1_state_sel = outC->SM1_state_nxt;
  }
  switch (SM1_state_sel) {
    case SSM_st_Espera_Enviar_SM1 :
      br_1_guard_SM1_Espera_Enviar = enviar_ativo;
      if (br_1_guard_SM1_Espera_Enviar) {
        _10_SM1_state_act = SSM_st_Enviando_SM1;
      }
      else {
        _10_SM1_state_act = SSM_st_Espera_Enviar_SM1;
      }
      _15_SM1_state_act = _10_SM1_state_act;
      if (br_1_guard_SM1_Espera_Enviar) {
        _12_SM1_fired_strong = SSM_TR_Espera_Enviar_1_SM1;
      }
      else {
        _12_SM1_fired_strong = SSM_TR_no_trans_SM1;
      }
      _14_SM1_fired_strong = _12_SM1_fired_strong;
      break;
    case SSM_st_Enviando_SM1 :
      SM1_state_act = SSM_st_Enviando_SM1;
      _15_SM1_state_act = SM1_state_act;
      SM1_fired_strong = SSM_TR_no_trans_SM1;
      _14_SM1_fired_strong = SM1_fired_strong;
      break;
    
  }
  switch (_15_SM1_state_act) {
    case SSM_st_Espera_Enviar_SM1 :
      _3_SM1_fired = _14_SM1_fired_strong;
      _2_SM1_reset_nxt = kcg_false;
      _1_SM1_state_nxt = SSM_st_Espera_Enviar_SM1;
      _13_SM1_fired = _3_SM1_fired;
      break;
    case SSM_st_Enviando_SM1 :
      Enviando_weakb_clock_SM1 = _14_SM1_fired_strong != SSM_TR_no_trans_SM1;
      if (Enviando_weakb_clock_SM1) {
        _9_SM1_fired = _14_SM1_fired_strong;
        _8_SM1_reset_nxt = kcg_false;
        _7_SM1_state_nxt = SSM_st_Enviando_SM1;
        SM1_fired = _9_SM1_fired;
        SM1_reset_nxt = _8_SM1_reset_nxt;
        SM1_state_nxt = _7_SM1_state_nxt;
      }
      else {
        br_1_guard_SM1_Enviando = envio_completo;
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
      _13_SM1_fired = SM1_fired;
      break;
    
  }
  if (outC->init) {
    SM1_reset_sel = kcg_false;
  }
  else {
    SM1_reset_sel = outC->SM1_reset_nxt;
  }
  switch (_15_SM1_state_act) {
    case SSM_st_Espera_Enviar_SM1 :
      outC->SM1_reset_nxt = _2_SM1_reset_nxt;
      outC->SM1_state_nxt = _1_SM1_state_nxt;
      break;
    case SSM_st_Enviando_SM1 :
      outC->SM1_reset_nxt = SM1_reset_nxt;
      outC->SM1_state_nxt = SM1_state_nxt;
      break;
    
  }
  switch (SM1_state_sel) {
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
  switch (SM1_state_sel) {
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
** Generation date: 2015-09-23T22:28:15
*************************************************************$ */

