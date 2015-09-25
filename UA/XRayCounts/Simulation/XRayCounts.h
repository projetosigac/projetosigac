/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/thais/projetosigac/UA/XRayCounts/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-18T22:02:22
*************************************************************$ */
#ifndef _XRayCounts_H_
#define _XRayCounts_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_real /* XRayCounts::availableInput */ availableInput;
  kcg_real /* XRayCounts::occupiedInput */ occupiedInput;
  kcg_real /* XRayCounts::totalInput */ totalInput;
} inC_XRayCounts;

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* XRayCounts::EmitToCDS */ EmitToCDS;
  kcg_bool /* XRayCounts::LayerVisible */ LayerVisible;
  kcg_real /* XRayCounts::availableOutput */ availableOutput;
  kcg_real /* XRayCounts::occupiedOutput */ occupiedOutput;
  kcg_real /* XRayCounts::totalOutput */ totalOutput;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_real /* XRayCounts::_L1 */ _L1;
  kcg_real /* XRayCounts::_L2 */ _L2;
  kcg_real /* XRayCounts::_L3 */ _L3;
  kcg_bool /* XRayCounts::_L4 */ _L4;
} outC_XRayCounts;

/* ===========  node initialization and cycle functions  =========== */
/* XRayCounts */
extern void XRayCounts(inC_XRayCounts *inC, outC_XRayCounts *outC);

extern void XRayCounts_reset(outC_XRayCounts *outC);

#endif /* _XRayCounts_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** XRayCounts.h
** Generation date: 2015-09-18T22:02:22
*************************************************************$ */

