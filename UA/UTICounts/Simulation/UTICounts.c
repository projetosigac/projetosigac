/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/thais/projetosigac/UA/UTICounts/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-18T21:55:10
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
  outC->_L4 = kcg_true;
  outC->LayerVisible = outC->_L4;
  outC->EmitToCDS = outC->_L4;
  outC->_L3 = inC->totalInput;
  outC->totalOutput = outC->_L3;
  outC->_L2 = inC->occupiedInput;
  outC->occupiedOutput = outC->_L2;
  outC->_L1 = inC->availableInput;
  outC->availableOutput = outC->_L1;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** UTICounts.c
** Generation date: 2015-09-18T21:55:10
*************************************************************$ */

