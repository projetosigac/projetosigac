/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/thais/projetosigac/UA/UTICounts/KCG\kcg_s2c_config.txt
** Generation date: 2015-09-24T10:17:46
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "UTICounts.h"

void UTICounts_reset(outC_UTICounts *outC)
{
}

/* UTICounts */
void UTICounts(inC_UTICounts *inC, outC_UTICounts *outC)
{
  /* UTICounts::_L1 */ kcg_real _L1;
  /* UTICounts::_L2 */ kcg_real _L2;
  /* UTICounts::_L3 */ kcg_real _L3;
  /* UTICounts::_L4 */ kcg_bool _L4;
  
  _L4 = kcg_true;
  outC->LayerVisible = _L4;
  outC->EmitToCDS = _L4;
  _L3 = inC->totalInput;
  outC->totalOutput = _L3;
  _L2 = inC->occupiedInput;
  outC->occupiedOutput = _L2;
  _L1 = inC->availableInput;
  outC->availableOutput = _L1;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** UTICounts.c
** Generation date: 2015-09-24T10:17:46
*************************************************************$ */

