/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/thais/projetosigac/UA/UTICounts/KCG\kcg_s2c_config.txt
** Generation date: 2015-09-24T10:17:46
*************************************************************$ */
#ifndef _UTICounts_H_
#define _UTICounts_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_real /* UTICounts::availableInput */ availableInput;
  kcg_real /* UTICounts::occupiedInput */ occupiedInput;
  kcg_real /* UTICounts::totalInput */ totalInput;
} inC_UTICounts;

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* UTICounts::EmitToCDS */ EmitToCDS;
  kcg_bool /* UTICounts::LayerVisible */ LayerVisible;
  kcg_real /* UTICounts::availableOutput */ availableOutput;
  kcg_real /* UTICounts::occupiedOutput */ occupiedOutput;
  kcg_real /* UTICounts::totalOutput */ totalOutput;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------  no initialization variables  ----------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_UTICounts;

/* ===========  node initialization and cycle functions  =========== */
/* UTICounts */
extern void UTICounts(inC_UTICounts *inC, outC_UTICounts *outC);

extern void UTICounts_reset(outC_UTICounts *outC);

#endif /* _UTICounts_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** UTICounts.h
** Generation date: 2015-09-24T10:17:46
*************************************************************$ */

