/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/thais/projetosigac/UA/SurgeryCounts/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-18T22:11:38
*************************************************************$ */
#ifndef _SurgeryCounts_H_
#define _SurgeryCounts_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_real /* SurgeryCounts::availableInput */ availableInput;
  kcg_real /* SurgeryCounts::occupiedInput */ occupiedInput;
  kcg_real /* SurgeryCounts::totalInput */ totalInput;
} inC_SurgeryCounts;

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* SurgeryCounts::EmitToCDS */ EmitToCDS;
  kcg_bool /* SurgeryCounts::LayerVisible */ LayerVisible;
  kcg_real /* SurgeryCounts::availableOutput */ availableOutput;
  kcg_real /* SurgeryCounts::occupiedOutput */ occupiedOutput;
  kcg_real /* SurgeryCounts::totalOutput */ totalOutput;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_real /* SurgeryCounts::_L1 */ _L1;
  kcg_real /* SurgeryCounts::_L2 */ _L2;
  kcg_real /* SurgeryCounts::_L3 */ _L3;
  kcg_bool /* SurgeryCounts::_L4 */ _L4;
} outC_SurgeryCounts;

/* ===========  node initialization and cycle functions  =========== */
/* SurgeryCounts */
extern void SurgeryCounts(inC_SurgeryCounts *inC, outC_SurgeryCounts *outC);

extern void SurgeryCounts_reset(outC_SurgeryCounts *outC);

#endif /* _SurgeryCounts_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** SurgeryCounts.h
** Generation date: 2015-09-18T22:11:38
*************************************************************$ */

