/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/Marrcio/Copy/EstudosRemote/ITA/Cunha/SI-GAC/BombeirosRescaldo/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-23T19:20:53
*************************************************************$ */
#ifndef _Main_H_
#define _Main_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* Main::ReqLayerVisible */ ReqLayerVisible;
  kcg_bool /* Main::ReqLayerActive */ ReqLayerActive;
  kcg_bool /* Main::EmitToCDS */ EmitToCDS;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_bool /* InitDF::_L2 */ _L2_1;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_bool /* InitDF::_L1 */ _L1_1;
  kcg_bool /* InitDF::ReqLayerActive */ ReqLayerActive_1;
  kcg_bool /* InitDF::ReqLayerVisible */ ReqLayerVisible_1;
  kcg_bool /* Main::_L1 */ _L1;
  kcg_bool /* Main::_L2 */ _L2;
  kcg_bool /* Main::_L3 */ _L3;
} outC_Main;

/* ===========  node initialization and cycle functions  =========== */
/* Main */
extern void Main(outC_Main *outC);

extern void Main_reset(outC_Main *outC);

#endif /* _Main_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** Main.h
** Generation date: 2015-09-23T19:20:53
*************************************************************$ */

