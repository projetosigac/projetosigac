/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/thais/projetosigac/UA/UTI-availability/KCG\kcg_s2c_config.txt
** Generation date: 2015-09-24T10:15:00
*************************************************************$ */
#ifndef _UTI_H_
#define _UTI_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_bool /* UTI::AllocateBed1 */ AllocateBed1;
  kcg_bool /* UTI::ActivateBed2 */ ActivateBed2;
  kcg_bool /* UTI::ActivateBed3 */ ActivateBed3;
  kcg_bool /* UTI::ActivateBed4 */ ActivateBed4;
  kcg_bool /* UTI::ActivateBed5 */ ActivateBed5;
  kcg_bool /* UTI::ActivateBed6 */ ActivateBed6;
  kcg_bool /* UTI::ActivateBed7 */ ActivateBed7;
  kcg_bool /* UTI::ActivateBed8 */ ActivateBed8;
  kcg_bool /* UTI::ActivateBed1 */ ActivateBed1;
  kcg_bool /* UTI::AllocateBed2 */ AllocateBed2;
  kcg_bool /* UTI::AllocateBed4 */ AllocateBed4;
  kcg_bool /* UTI::AllocateBed3 */ AllocateBed3;
  kcg_bool /* UTI::AllocateBed6 */ AllocateBed6;
  kcg_bool /* UTI::AllocateBed5 */ AllocateBed5;
  kcg_bool /* UTI::AllocateBed7 */ AllocateBed7;
  kcg_bool /* UTI::AllocateBed8 */ AllocateBed8;
} inC_UTI;

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_real /* UTI::ActiveBedsCount */ ActiveBedsCount;
  kcg_real /* UTI::AllocatedBedsCount */ AllocatedBedsCount;
  kcg_int /* UTI::BedColor1 */ BedColor1;
  kcg_real /* UTI::FreeBedsCount */ FreeBedsCount;
  kcg_int /* UTI::BedColor2 */ BedColor2;
  kcg_int /* UTI::BedColor3 */ BedColor3;
  kcg_int /* UTI::BedColor4 */ BedColor4;
  kcg_int /* UTI::BedColor5 */ BedColor5;
  kcg_int /* UTI::BedColor6 */ BedColor6;
  kcg_int /* UTI::BedColor7 */ BedColor7;
  kcg_int /* UTI::BedColor8 */ BedColor8;
  kcg_bool /* UTI::EmitToCDS */ EmitToCDS;
  kcg_bool /* UTI::LayerVisible */ LayerVisible;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_bool /* Toggle::_L4 */ _L4_2_12;
  kcg_bool /* Toggle::_L4 */ _L4_1_12;
  kcg_bool /* Toggle::_L4 */ _L4_2_11;
  kcg_bool /* Toggle::_L4 */ _L4_1_11;
  kcg_bool /* Toggle::_L4 */ _L4_2_9;
  kcg_bool /* Toggle::_L4 */ _L4_1_9;
  kcg_bool /* Toggle::_L4 */ _L4_2_7;
  kcg_bool /* Toggle::_L4 */ _L4_1_7;
  kcg_bool /* Toggle::_L4 */ _L4_2_6;
  kcg_bool /* Toggle::_L4 */ _L4_1_6;
  kcg_bool /* Toggle::_L4 */ _L4_2_5;
  kcg_bool /* Toggle::_L4 */ _L4_1_5;
  kcg_bool /* Toggle::_L4 */ _L4_2_4;
  kcg_bool /* Toggle::_L4 */ _L4_1_4;
  kcg_bool /* Toggle::_L4 */ _L4_2_1;
  kcg_bool /* Toggle::_L4 */ _L4_1_1;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} outC_UTI;

/* ===========  node initialization and cycle functions  =========== */
/* UTI */
extern void UTI(inC_UTI *inC, outC_UTI *outC);

extern void UTI_reset(outC_UTI *outC);

#endif /* _UTI_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** UTI.h
** Generation date: 2015-09-24T10:15:00
*************************************************************$ */

