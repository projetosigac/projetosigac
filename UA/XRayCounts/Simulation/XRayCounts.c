/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/thais/projetosigac/UA/XRayCounts/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-18T22:02:22
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "XRayCounts.h"

void XRayCounts_reset(outC_XRayCounts *outC)
{
}

/* XRayCounts */
void XRayCounts(inC_XRayCounts *inC, outC_XRayCounts *outC)
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
** XRayCounts.c
** Generation date: 2015-09-18T22:02:22
*************************************************************$ */

