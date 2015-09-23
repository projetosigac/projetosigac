/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/Marrcio/Copy/EstudosRemote/ITA/Cunha/SI-GAC/BombeirosRescaldo/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-23T19:20:53
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Main.h"

void Main_reset(outC_Main *outC)
{
  outC->init = kcg_true;
}

/* Main */
void Main(outC_Main *outC)
{
  if (outC->init) {
    outC->_L1_1 = kcg_true;
  }
  else {
    outC->_L1_1 = outC->_L2_1;
  }
  outC->ReqLayerActive_1 = outC->_L1_1;
  outC->_L2 = outC->ReqLayerActive_1;
  outC->_L3 = kcg_true;
  outC->EmitToCDS = outC->_L3;
  outC->ReqLayerActive = outC->_L2;
  outC->ReqLayerVisible_1 = outC->_L1_1;
  outC->_L1 = outC->ReqLayerVisible_1;
  outC->ReqLayerVisible = outC->_L1;
  outC->_L2_1 = kcg_false;
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** Main.c
** Generation date: 2015-09-23T19:20:53
*************************************************************$ */

