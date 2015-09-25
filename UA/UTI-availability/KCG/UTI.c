/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/thais/projetosigac/UA/UTI-availability/KCG\kcg_s2c_config.txt
** Generation date: 2015-09-24T10:15:00
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "UTI.h"

void UTI_reset(outC_UTI *outC)
{
  outC->init = kcg_true;
}

/* UTI */
void UTI(inC_UTI *inC, outC_UTI *outC)
{
  /* Toggle::_L1 */ kcg_bool _L1_2_12;
  /* Toggle::_L2 */ kcg_bool _L2_2_12;
  /* Toggle::_L3 */ kcg_bool _L3_2_12;
  /* Toggle::Output */ kcg_bool Output_2_12;
  /* Toggle::Input */ kcg_bool Input_2_12;
  /* Toggle::_L1 */ kcg_bool _L1_1_12;
  /* Toggle::_L2 */ kcg_bool _L2_1_12;
  /* Toggle::_L3 */ kcg_bool _L3_1_12;
  /* Toggle::Output */ kcg_bool Output_1_12;
  /* Toggle::Input */ kcg_bool Input_1_12;
  /* Bed::_L1 */ kcg_bool _L1_12;
  /* Bed::_L2 */ kcg_bool _L2_12;
  /* Bed::_L3 */ kcg_bool _L3_12;
  /* Bed::_L4 */ kcg_bool _L4_12;
  /* Bed::_L5 */ kcg_bool _L5_12;
  /* Bed::_L6 */ kcg_int _L6_12;
  /* Bed::_L7 */ kcg_int _L7_12;
  /* Bed::_L8 */ kcg_int _L8_12;
  /* Bed::_L9 */ kcg_int _L9_12;
  /* Bed::_L10 */ kcg_int _L10_12;
  /* Bed::_L11 */ kcg_int _L11_12;
  /* Bed::_L12 */ kcg_int _L12_12;
  /* Bed::_L13 */ kcg_int _L13_12;
  /* Bed::_L16 */ kcg_int _L16_12;
  /* Bed::_L15 */ kcg_int _L15_12;
  /* Bed::_L14 */ kcg_int _L14_12;
  /* Bed::_L17 */ kcg_bool _L17_12;
  /* Bed::BedColor */ kcg_int BedColor_12;
  /* Bed::BedAllocated */ kcg_int BedAllocated_12;
  /* Bed::BedActive */ kcg_int BedActive_12;
  /* Bed::Allocate */ kcg_bool Allocate_12;
  /* Bed::Activate */ kcg_bool Activate_12;
  /* Toggle::_L1 */ kcg_bool _L1_2_11;
  /* Toggle::_L2 */ kcg_bool _L2_2_11;
  /* Toggle::_L3 */ kcg_bool _L3_2_11;
  /* Toggle::Output */ kcg_bool Output_2_11;
  /* Toggle::Input */ kcg_bool Input_2_11;
  /* Toggle::_L1 */ kcg_bool _L1_1_11;
  /* Toggle::_L2 */ kcg_bool _L2_1_11;
  /* Toggle::_L3 */ kcg_bool _L3_1_11;
  /* Toggle::Output */ kcg_bool Output_1_11;
  /* Toggle::Input */ kcg_bool Input_1_11;
  /* Bed::_L1 */ kcg_bool _L1_11;
  /* Bed::_L2 */ kcg_bool _L2_11;
  /* Bed::_L3 */ kcg_bool _L3_11;
  /* Bed::_L4 */ kcg_bool _L4_11;
  /* Bed::_L5 */ kcg_bool _L5_11;
  /* Bed::_L6 */ kcg_int _L6_11;
  /* Bed::_L7 */ kcg_int _L7_11;
  /* Bed::_L8 */ kcg_int _L8_11;
  /* Bed::_L9 */ kcg_int _L9_11;
  /* Bed::_L10 */ kcg_int _L10_11;
  /* Bed::_L11 */ kcg_int _L11_11;
  /* Bed::_L12 */ kcg_int _L12_11;
  /* Bed::_L13 */ kcg_int _L13_11;
  /* Bed::_L16 */ kcg_int _L16_11;
  /* Bed::_L15 */ kcg_int _L15_11;
  /* Bed::_L14 */ kcg_int _L14_11;
  /* Bed::_L17 */ kcg_bool _L17_11;
  /* Bed::BedColor */ kcg_int BedColor_11;
  /* Bed::BedAllocated */ kcg_int BedAllocated_11;
  /* Bed::BedActive */ kcg_int BedActive_11;
  /* Bed::Allocate */ kcg_bool Allocate_11;
  /* Bed::Activate */ kcg_bool Activate_11;
  /* Toggle::_L1 */ kcg_bool _L1_2_9;
  /* Toggle::_L2 */ kcg_bool _L2_2_9;
  /* Toggle::_L3 */ kcg_bool _L3_2_9;
  /* Toggle::Output */ kcg_bool Output_2_9;
  /* Toggle::Input */ kcg_bool Input_2_9;
  /* Toggle::_L1 */ kcg_bool _L1_1_9;
  /* Toggle::_L2 */ kcg_bool _L2_1_9;
  /* Toggle::_L3 */ kcg_bool _L3_1_9;
  /* Toggle::Output */ kcg_bool Output_1_9;
  /* Toggle::Input */ kcg_bool Input_1_9;
  /* Bed::_L1 */ kcg_bool _L1_9;
  /* Bed::_L2 */ kcg_bool _L2_9;
  /* Bed::_L3 */ kcg_bool _L3_9;
  /* Bed::_L4 */ kcg_bool _L4_9;
  /* Bed::_L5 */ kcg_bool _L5_9;
  /* Bed::_L6 */ kcg_int _L6_9;
  /* Bed::_L7 */ kcg_int _L7_9;
  /* Bed::_L8 */ kcg_int _L8_9;
  /* Bed::_L9 */ kcg_int _L9_9;
  /* Bed::_L10 */ kcg_int _L10_9;
  /* Bed::_L11 */ kcg_int _L11_9;
  /* Bed::_L12 */ kcg_int _L12_9;
  /* Bed::_L13 */ kcg_int _L13_9;
  /* Bed::_L16 */ kcg_int _L16_9;
  /* Bed::_L15 */ kcg_int _L15_9;
  /* Bed::_L14 */ kcg_int _L14_9;
  /* Bed::_L17 */ kcg_bool _L17_9;
  /* Bed::BedColor */ kcg_int BedColor_9;
  /* Bed::BedAllocated */ kcg_int BedAllocated_9;
  /* Bed::BedActive */ kcg_int BedActive_9;
  /* Bed::Allocate */ kcg_bool Allocate_9;
  /* Bed::Activate */ kcg_bool Activate_9;
  /* Toggle::_L1 */ kcg_bool _L1_2_7;
  /* Toggle::_L2 */ kcg_bool _L2_2_7;
  /* Toggle::_L3 */ kcg_bool _L3_2_7;
  /* Toggle::Output */ kcg_bool Output_2_7;
  /* Toggle::Input */ kcg_bool Input_2_7;
  /* Toggle::_L1 */ kcg_bool _L1_1_7;
  /* Toggle::_L2 */ kcg_bool _L2_1_7;
  /* Toggle::_L3 */ kcg_bool _L3_1_7;
  /* Toggle::Output */ kcg_bool Output_1_7;
  /* Toggle::Input */ kcg_bool Input_1_7;
  /* Bed::_L1 */ kcg_bool _L1_7;
  /* Bed::_L2 */ kcg_bool _L2_7;
  /* Bed::_L3 */ kcg_bool _L3_7;
  /* Bed::_L4 */ kcg_bool _L4_7;
  /* Bed::_L5 */ kcg_bool _L5_7;
  /* Bed::_L6 */ kcg_int _L6_7;
  /* Bed::_L7 */ kcg_int _L7_7;
  /* Bed::_L8 */ kcg_int _L8_7;
  /* Bed::_L9 */ kcg_int _L9_7;
  /* Bed::_L10 */ kcg_int _L10_7;
  /* Bed::_L11 */ kcg_int _L11_7;
  /* Bed::_L12 */ kcg_int _L12_7;
  /* Bed::_L13 */ kcg_int _L13_7;
  /* Bed::_L16 */ kcg_int _L16_7;
  /* Bed::_L15 */ kcg_int _L15_7;
  /* Bed::_L14 */ kcg_int _L14_7;
  /* Bed::_L17 */ kcg_bool _L17_7;
  /* Bed::BedColor */ kcg_int BedColor_7;
  /* Bed::BedAllocated */ kcg_int BedAllocated_7;
  /* Bed::BedActive */ kcg_int BedActive_7;
  /* Bed::Allocate */ kcg_bool Allocate_7;
  /* Bed::Activate */ kcg_bool Activate_7;
  /* Toggle::_L1 */ kcg_bool _L1_2_6;
  /* Toggle::_L2 */ kcg_bool _L2_2_6;
  /* Toggle::_L3 */ kcg_bool _L3_2_6;
  /* Toggle::Output */ kcg_bool Output_2_6;
  /* Toggle::Input */ kcg_bool Input_2_6;
  /* Toggle::_L1 */ kcg_bool _L1_1_6;
  /* Toggle::_L2 */ kcg_bool _L2_1_6;
  /* Toggle::_L3 */ kcg_bool _L3_1_6;
  /* Toggle::Output */ kcg_bool Output_1_6;
  /* Toggle::Input */ kcg_bool Input_1_6;
  /* Bed::_L1 */ kcg_bool _L1_6;
  /* Bed::_L2 */ kcg_bool _L2_6;
  /* Bed::_L3 */ kcg_bool _L3_6;
  /* Bed::_L4 */ kcg_bool _L4_6;
  /* Bed::_L5 */ kcg_bool _L5_6;
  /* Bed::_L6 */ kcg_int _L6_6;
  /* Bed::_L7 */ kcg_int _L7_6;
  /* Bed::_L8 */ kcg_int _L8_6;
  /* Bed::_L9 */ kcg_int _L9_6;
  /* Bed::_L10 */ kcg_int _L10_6;
  /* Bed::_L11 */ kcg_int _L11_6;
  /* Bed::_L12 */ kcg_int _L12_6;
  /* Bed::_L13 */ kcg_int _L13_6;
  /* Bed::_L16 */ kcg_int _L16_6;
  /* Bed::_L15 */ kcg_int _L15_6;
  /* Bed::_L14 */ kcg_int _L14_6;
  /* Bed::_L17 */ kcg_bool _L17_6;
  /* Bed::BedColor */ kcg_int BedColor_6;
  /* Bed::BedAllocated */ kcg_int BedAllocated_6;
  /* Bed::BedActive */ kcg_int BedActive_6;
  /* Bed::Allocate */ kcg_bool Allocate_6;
  /* Bed::Activate */ kcg_bool Activate_6;
  /* Toggle::_L1 */ kcg_bool _L1_2_5;
  /* Toggle::_L2 */ kcg_bool _L2_2_5;
  /* Toggle::_L3 */ kcg_bool _L3_2_5;
  /* Toggle::Output */ kcg_bool Output_2_5;
  /* Toggle::Input */ kcg_bool Input_2_5;
  /* Toggle::_L1 */ kcg_bool _L1_1_5;
  /* Toggle::_L2 */ kcg_bool _L2_1_5;
  /* Toggle::_L3 */ kcg_bool _L3_1_5;
  /* Toggle::Output */ kcg_bool Output_1_5;
  /* Toggle::Input */ kcg_bool Input_1_5;
  /* Bed::_L1 */ kcg_bool _L1_5;
  /* Bed::_L2 */ kcg_bool _L2_5;
  /* Bed::_L3 */ kcg_bool _L3_5;
  /* Bed::_L4 */ kcg_bool _L4_5;
  /* Bed::_L5 */ kcg_bool _L5_5;
  /* Bed::_L6 */ kcg_int _L6_5;
  /* Bed::_L7 */ kcg_int _L7_5;
  /* Bed::_L8 */ kcg_int _L8_5;
  /* Bed::_L9 */ kcg_int _L9_5;
  /* Bed::_L10 */ kcg_int _L10_5;
  /* Bed::_L11 */ kcg_int _L11_5;
  /* Bed::_L12 */ kcg_int _L12_5;
  /* Bed::_L13 */ kcg_int _L13_5;
  /* Bed::_L16 */ kcg_int _L16_5;
  /* Bed::_L15 */ kcg_int _L15_5;
  /* Bed::_L14 */ kcg_int _L14_5;
  /* Bed::_L17 */ kcg_bool _L17_5;
  /* Bed::BedColor */ kcg_int BedColor_5;
  /* Bed::BedAllocated */ kcg_int BedAllocated_5;
  /* Bed::BedActive */ kcg_int BedActive_5;
  /* Bed::Allocate */ kcg_bool Allocate_5;
  /* Bed::Activate */ kcg_bool Activate_5;
  /* Toggle::_L1 */ kcg_bool _L1_2_4;
  /* Toggle::_L2 */ kcg_bool _L2_2_4;
  /* Toggle::_L3 */ kcg_bool _L3_2_4;
  /* Toggle::Output */ kcg_bool Output_2_4;
  /* Toggle::Input */ kcg_bool Input_2_4;
  /* Toggle::_L1 */ kcg_bool _L1_1_4;
  /* Toggle::_L2 */ kcg_bool _L2_1_4;
  /* Toggle::_L3 */ kcg_bool _L3_1_4;
  /* Toggle::Output */ kcg_bool Output_1_4;
  /* Toggle::Input */ kcg_bool Input_1_4;
  /* Bed::_L1 */ kcg_bool _L1_4;
  /* Bed::_L2 */ kcg_bool _L2_4;
  /* Bed::_L3 */ kcg_bool _L3_4;
  /* Bed::_L4 */ kcg_bool _L4_4;
  /* Bed::_L5 */ kcg_bool _L5_4;
  /* Bed::_L6 */ kcg_int _L6_4;
  /* Bed::_L7 */ kcg_int _L7_4;
  /* Bed::_L8 */ kcg_int _L8_4;
  /* Bed::_L9 */ kcg_int _L9_4;
  /* Bed::_L10 */ kcg_int _L10_4;
  /* Bed::_L11 */ kcg_int _L11_4;
  /* Bed::_L12 */ kcg_int _L12_4;
  /* Bed::_L13 */ kcg_int _L13_4;
  /* Bed::_L16 */ kcg_int _L16_4;
  /* Bed::_L15 */ kcg_int _L15_4;
  /* Bed::_L14 */ kcg_int _L14_4;
  /* Bed::_L17 */ kcg_bool _L17_4;
  /* Bed::BedColor */ kcg_int BedColor_4;
  /* Bed::BedAllocated */ kcg_int BedAllocated_4;
  /* Bed::BedActive */ kcg_int BedActive_4;
  /* Bed::Allocate */ kcg_bool Allocate_4;
  /* Bed::Activate */ kcg_bool Activate_4;
  /* Toggle::_L1 */ kcg_bool _L1_2_1;
  /* Toggle::_L2 */ kcg_bool _L2_2_1;
  /* Toggle::_L3 */ kcg_bool _L3_2_1;
  /* Toggle::Output */ kcg_bool Output_2_1;
  /* Toggle::Input */ kcg_bool Input_2_1;
  /* Toggle::_L1 */ kcg_bool _L1_1_1;
  /* Toggle::_L2 */ kcg_bool _L2_1_1;
  /* Toggle::_L3 */ kcg_bool _L3_1_1;
  /* Toggle::Output */ kcg_bool Output_1_1;
  /* Toggle::Input */ kcg_bool Input_1_1;
  /* Bed::_L1 */ kcg_bool _L1_1;
  /* Bed::_L2 */ kcg_bool _L2_1;
  /* Bed::_L3 */ kcg_bool _L3_1;
  /* Bed::_L4 */ kcg_bool _L4_1;
  /* Bed::_L5 */ kcg_bool _L5_1;
  /* Bed::_L6 */ kcg_int _L6_1;
  /* Bed::_L7 */ kcg_int _L7_1;
  /* Bed::_L8 */ kcg_int _L8_1;
  /* Bed::_L9 */ kcg_int _L9_1;
  /* Bed::_L10 */ kcg_int _L10_1;
  /* Bed::_L11 */ kcg_int _L11_1;
  /* Bed::_L12 */ kcg_int _L12_1;
  /* Bed::_L13 */ kcg_int _L13_1;
  /* Bed::_L16 */ kcg_int _L16_1;
  /* Bed::_L15 */ kcg_int _L15_1;
  /* Bed::_L14 */ kcg_int _L14_1;
  /* Bed::_L17 */ kcg_bool _L17_1;
  /* Bed::BedColor */ kcg_int BedColor_1;
  /* Bed::BedAllocated */ kcg_int BedAllocated_1;
  /* Bed::BedActive */ kcg_int BedActive_1;
  /* Bed::Allocate */ kcg_bool Allocate_1;
  /* Bed::Activate */ kcg_bool Activate_1;
  /* UTI::_L3 */ kcg_int _L3;
  /* UTI::_L2 */ kcg_int _L2;
  /* UTI::_L1 */ kcg_int _L1;
  /* UTI::_L10 */ kcg_int _L10;
  /* UTI::_L11 */ kcg_int _L11;
  /* UTI::_L12 */ kcg_int _L12;
  /* UTI::_L13 */ kcg_int _L13;
  /* UTI::_L14 */ kcg_int _L14;
  /* UTI::_L15 */ kcg_int _L15;
  /* UTI::_L16 */ kcg_int _L16;
  /* UTI::_L17 */ kcg_int _L17;
  /* UTI::_L18 */ kcg_int _L18;
  /* UTI::_L19 */ kcg_int _L19;
  /* UTI::_L20 */ kcg_int _L20;
  /* UTI::_L21 */ kcg_int _L21;
  /* UTI::_L25 */ kcg_int _L25;
  /* UTI::_L26 */ kcg_int _L26;
  /* UTI::_L27 */ kcg_int _L27;
  /* UTI::_L31 */ kcg_int _L31;
  /* UTI::_L32 */ kcg_int _L32;
  /* UTI::_L33 */ kcg_int _L33;
  /* UTI::_L34 */ kcg_int _L34;
  /* UTI::_L35 */ kcg_int _L35;
  /* UTI::_L36 */ kcg_int _L36;
  /* UTI::_L45 */ kcg_bool _L45;
  /* UTI::_L46 */ kcg_bool _L46;
  /* UTI::_L47 */ kcg_bool _L47;
  /* UTI::_L48 */ kcg_bool _L48;
  /* UTI::_L49 */ kcg_bool _L49;
  /* UTI::_L50 */ kcg_bool _L50;
  /* UTI::_L51 */ kcg_bool _L51;
  /* UTI::_L52 */ kcg_int _L52;
  /* UTI::_L54 */ kcg_bool _L54;
  /* UTI::_L55 */ kcg_bool _L55;
  /* UTI::_L56 */ kcg_bool _L56;
  /* UTI::_L57 */ kcg_bool _L57;
  /* UTI::_L58 */ kcg_bool _L58;
  /* UTI::_L59 */ kcg_bool _L59;
  /* UTI::_L60 */ kcg_bool _L60;
  /* UTI::_L61 */ kcg_bool _L61;
  /* UTI::_L62 */ kcg_bool _L62;
  /* UTI::_L66 */ kcg_int _L66;
  /* UTI::_L67 */ kcg_int _L67;
  /* UTI::_L68 */ kcg_bool _L68;
  /* UTI::_L69 */ kcg_bool _L69;
  /* UTI::_L70 */ kcg_real _L70;
  /* UTI::_L71 */ kcg_real _L71;
  /* UTI::_L72 */ kcg_real _L72;
  
  _L60 = inC->AllocateBed5;
  Allocate_12 = _L60;
  _L62 = inC->AllocateBed8;
  Allocate_11 = _L62;
  _L61 = inC->AllocateBed7;
  Allocate_9 = _L61;
  _L59 = inC->AllocateBed6;
  Allocate_7 = _L59;
  _L58 = inC->AllocateBed4;
  Allocate_6 = _L58;
  _L57 = inC->AllocateBed3;
  Allocate_5 = _L57;
  _L55 = inC->AllocateBed2;
  Allocate_4 = _L55;
  _L56 = inC->AllocateBed1;
  Allocate_1 = _L56;
  if (outC->init) {
    _L2_1_1 = kcg_false;
  }
  else {
    _L2_1_1 = outC->_L4_1_1;
  }
  _L54 = inC->ActivateBed1;
  Activate_1 = _L54;
  _L1_1 = Activate_1;
  Input_1_1 = _L1_1;
  _L1_1_1 = Input_1_1;
  _L3_1_1 = !_L2_1_1;
  if (_L1_1_1) {
    outC->_L4_1_1 = _L3_1_1;
  }
  else {
    outC->_L4_1_1 = _L2_1_1;
  }
  Output_1_1 = outC->_L4_1_1;
  _L3_1 = Output_1_1;
  _L17_1 = !_L3_1;
  _L6_1 = BLACK;
  if (outC->init) {
    _L2_2_1 = kcg_false;
  }
  else {
    _L2_2_1 = outC->_L4_2_1;
  }
  _L2_1 = Allocate_1;
  Input_2_1 = _L2_1;
  _L1_2_1 = Input_2_1;
  _L3_2_1 = !_L2_2_1;
  if (_L1_2_1) {
    outC->_L4_2_1 = _L3_2_1;
  }
  else {
    outC->_L4_2_1 = _L2_2_1;
  }
  Output_2_1 = outC->_L4_2_1;
  _L4_1 = Output_2_1;
  _L5_1 = _L3_1 & _L4_1;
  _L7_1 = RED;
  _L8_1 = GREEN;
  if (_L5_1) {
    _L10_1 = _L7_1;
  }
  else {
    _L10_1 = _L8_1;
  }
  if (_L17_1) {
    _L9_1 = _L6_1;
  }
  else {
    _L9_1 = _L10_1;
  }
  BedColor_1 = _L9_1;
  _L3 = BedColor_1;
  _L15_1 = 1;
  _L14_1 = 0;
  if (_L5_1) {
    _L16_1 = _L15_1;
  }
  else {
    _L16_1 = _L14_1;
  }
  BedAllocated_1 = _L16_1;
  _L2 = BedAllocated_1;
  if (outC->init) {
    _L2_1_4 = kcg_false;
  }
  else {
    _L2_1_4 = outC->_L4_1_4;
  }
  _L45 = inC->ActivateBed2;
  Activate_4 = _L45;
  _L1_4 = Activate_4;
  Input_1_4 = _L1_4;
  _L1_1_4 = Input_1_4;
  _L3_1_4 = !_L2_1_4;
  if (_L1_1_4) {
    outC->_L4_1_4 = _L3_1_4;
  }
  else {
    outC->_L4_1_4 = _L2_1_4;
  }
  Output_1_4 = outC->_L4_1_4;
  _L3_4 = Output_1_4;
  _L17_4 = !_L3_4;
  _L6_4 = BLACK;
  if (outC->init) {
    _L2_2_4 = kcg_false;
  }
  else {
    _L2_2_4 = outC->_L4_2_4;
  }
  _L2_4 = Allocate_4;
  Input_2_4 = _L2_4;
  _L1_2_4 = Input_2_4;
  _L3_2_4 = !_L2_2_4;
  if (_L1_2_4) {
    outC->_L4_2_4 = _L3_2_4;
  }
  else {
    outC->_L4_2_4 = _L2_2_4;
  }
  Output_2_4 = outC->_L4_2_4;
  _L4_4 = Output_2_4;
  _L5_4 = _L3_4 & _L4_4;
  _L7_4 = RED;
  _L8_4 = GREEN;
  if (_L5_4) {
    _L10_4 = _L7_4;
  }
  else {
    _L10_4 = _L8_4;
  }
  if (_L17_4) {
    _L9_4 = _L6_4;
  }
  else {
    _L9_4 = _L10_4;
  }
  BedColor_4 = _L9_4;
  _L12 = BedColor_4;
  _L15_4 = 1;
  _L14_4 = 0;
  if (_L5_4) {
    _L16_4 = _L15_4;
  }
  else {
    _L16_4 = _L14_4;
  }
  BedAllocated_4 = _L16_4;
  _L11 = BedAllocated_4;
  if (outC->init) {
    _L2_1_5 = kcg_false;
  }
  else {
    _L2_1_5 = outC->_L4_1_5;
  }
  _L46 = inC->ActivateBed3;
  Activate_5 = _L46;
  _L1_5 = Activate_5;
  Input_1_5 = _L1_5;
  _L1_1_5 = Input_1_5;
  _L3_1_5 = !_L2_1_5;
  if (_L1_1_5) {
    outC->_L4_1_5 = _L3_1_5;
  }
  else {
    outC->_L4_1_5 = _L2_1_5;
  }
  Output_1_5 = outC->_L4_1_5;
  _L3_5 = Output_1_5;
  _L17_5 = !_L3_5;
  _L6_5 = BLACK;
  if (outC->init) {
    _L2_2_5 = kcg_false;
  }
  else {
    _L2_2_5 = outC->_L4_2_5;
  }
  _L2_5 = Allocate_5;
  Input_2_5 = _L2_5;
  _L1_2_5 = Input_2_5;
  _L3_2_5 = !_L2_2_5;
  if (_L1_2_5) {
    outC->_L4_2_5 = _L3_2_5;
  }
  else {
    outC->_L4_2_5 = _L2_2_5;
  }
  Output_2_5 = outC->_L4_2_5;
  _L4_5 = Output_2_5;
  _L5_5 = _L3_5 & _L4_5;
  _L7_5 = RED;
  _L8_5 = GREEN;
  if (_L5_5) {
    _L10_5 = _L7_5;
  }
  else {
    _L10_5 = _L8_5;
  }
  if (_L17_5) {
    _L9_5 = _L6_5;
  }
  else {
    _L9_5 = _L10_5;
  }
  BedColor_5 = _L9_5;
  _L15 = BedColor_5;
  _L15_5 = 1;
  _L14_5 = 0;
  if (_L5_5) {
    _L16_5 = _L15_5;
  }
  else {
    _L16_5 = _L14_5;
  }
  BedAllocated_5 = _L16_5;
  _L14 = BedAllocated_5;
  if (outC->init) {
    _L2_1_6 = kcg_false;
  }
  else {
    _L2_1_6 = outC->_L4_1_6;
  }
  _L47 = inC->ActivateBed4;
  Activate_6 = _L47;
  _L1_6 = Activate_6;
  Input_1_6 = _L1_6;
  _L1_1_6 = Input_1_6;
  _L3_1_6 = !_L2_1_6;
  if (_L1_1_6) {
    outC->_L4_1_6 = _L3_1_6;
  }
  else {
    outC->_L4_1_6 = _L2_1_6;
  }
  Output_1_6 = outC->_L4_1_6;
  _L3_6 = Output_1_6;
  _L17_6 = !_L3_6;
  _L6_6 = BLACK;
  if (outC->init) {
    _L2_2_6 = kcg_false;
  }
  else {
    _L2_2_6 = outC->_L4_2_6;
  }
  _L2_6 = Allocate_6;
  Input_2_6 = _L2_6;
  _L1_2_6 = Input_2_6;
  _L3_2_6 = !_L2_2_6;
  if (_L1_2_6) {
    outC->_L4_2_6 = _L3_2_6;
  }
  else {
    outC->_L4_2_6 = _L2_2_6;
  }
  Output_2_6 = outC->_L4_2_6;
  _L4_6 = Output_2_6;
  _L5_6 = _L3_6 & _L4_6;
  _L7_6 = RED;
  _L8_6 = GREEN;
  if (_L5_6) {
    _L10_6 = _L7_6;
  }
  else {
    _L10_6 = _L8_6;
  }
  if (_L17_6) {
    _L9_6 = _L6_6;
  }
  else {
    _L9_6 = _L10_6;
  }
  BedColor_6 = _L9_6;
  _L18 = BedColor_6;
  _L15_6 = 1;
  _L14_6 = 0;
  if (_L5_6) {
    _L16_6 = _L15_6;
  }
  else {
    _L16_6 = _L14_6;
  }
  BedAllocated_6 = _L16_6;
  _L17 = BedAllocated_6;
  if (outC->init) {
    _L2_1_7 = kcg_false;
  }
  else {
    _L2_1_7 = outC->_L4_1_7;
  }
  _L49 = inC->ActivateBed6;
  Activate_7 = _L49;
  _L1_7 = Activate_7;
  Input_1_7 = _L1_7;
  _L1_1_7 = Input_1_7;
  _L3_1_7 = !_L2_1_7;
  if (_L1_1_7) {
    outC->_L4_1_7 = _L3_1_7;
  }
  else {
    outC->_L4_1_7 = _L2_1_7;
  }
  Output_1_7 = outC->_L4_1_7;
  _L3_7 = Output_1_7;
  _L17_7 = !_L3_7;
  _L6_7 = BLACK;
  if (outC->init) {
    _L2_2_7 = kcg_false;
  }
  else {
    _L2_2_7 = outC->_L4_2_7;
  }
  _L2_7 = Allocate_7;
  Input_2_7 = _L2_7;
  _L1_2_7 = Input_2_7;
  _L3_2_7 = !_L2_2_7;
  if (_L1_2_7) {
    outC->_L4_2_7 = _L3_2_7;
  }
  else {
    outC->_L4_2_7 = _L2_2_7;
  }
  Output_2_7 = outC->_L4_2_7;
  _L4_7 = Output_2_7;
  _L5_7 = _L3_7 & _L4_7;
  _L7_7 = RED;
  _L8_7 = GREEN;
  if (_L5_7) {
    _L10_7 = _L7_7;
  }
  else {
    _L10_7 = _L8_7;
  }
  if (_L17_7) {
    _L9_7 = _L6_7;
  }
  else {
    _L9_7 = _L10_7;
  }
  BedColor_7 = _L9_7;
  _L21 = BedColor_7;
  _L15_7 = 1;
  _L14_7 = 0;
  if (_L5_7) {
    _L16_7 = _L15_7;
  }
  else {
    _L16_7 = _L14_7;
  }
  BedAllocated_7 = _L16_7;
  _L20 = BedAllocated_7;
  if (outC->init) {
    _L2_1_9 = kcg_false;
  }
  else {
    _L2_1_9 = outC->_L4_1_9;
  }
  _L50 = inC->ActivateBed7;
  Activate_9 = _L50;
  _L1_9 = Activate_9;
  Input_1_9 = _L1_9;
  _L1_1_9 = Input_1_9;
  _L3_1_9 = !_L2_1_9;
  if (_L1_1_9) {
    outC->_L4_1_9 = _L3_1_9;
  }
  else {
    outC->_L4_1_9 = _L2_1_9;
  }
  Output_1_9 = outC->_L4_1_9;
  _L3_9 = Output_1_9;
  _L17_9 = !_L3_9;
  _L6_9 = BLACK;
  if (outC->init) {
    _L2_2_9 = kcg_false;
  }
  else {
    _L2_2_9 = outC->_L4_2_9;
  }
  _L2_9 = Allocate_9;
  Input_2_9 = _L2_9;
  _L1_2_9 = Input_2_9;
  _L3_2_9 = !_L2_2_9;
  if (_L1_2_9) {
    outC->_L4_2_9 = _L3_2_9;
  }
  else {
    outC->_L4_2_9 = _L2_2_9;
  }
  Output_2_9 = outC->_L4_2_9;
  _L4_9 = Output_2_9;
  _L5_9 = _L3_9 & _L4_9;
  _L7_9 = RED;
  _L8_9 = GREEN;
  if (_L5_9) {
    _L10_9 = _L7_9;
  }
  else {
    _L10_9 = _L8_9;
  }
  if (_L17_9) {
    _L9_9 = _L6_9;
  }
  else {
    _L9_9 = _L10_9;
  }
  BedColor_9 = _L9_9;
  _L27 = BedColor_9;
  _L15_9 = 1;
  _L14_9 = 0;
  if (_L5_9) {
    _L16_9 = _L15_9;
  }
  else {
    _L16_9 = _L14_9;
  }
  BedAllocated_9 = _L16_9;
  _L26 = BedAllocated_9;
  if (outC->init) {
    _L2_1_11 = kcg_false;
  }
  else {
    _L2_1_11 = outC->_L4_1_11;
  }
  _L51 = inC->ActivateBed8;
  Activate_11 = _L51;
  _L1_11 = Activate_11;
  Input_1_11 = _L1_11;
  _L1_1_11 = Input_1_11;
  _L3_1_11 = !_L2_1_11;
  if (_L1_1_11) {
    outC->_L4_1_11 = _L3_1_11;
  }
  else {
    outC->_L4_1_11 = _L2_1_11;
  }
  Output_1_11 = outC->_L4_1_11;
  _L3_11 = Output_1_11;
  _L17_11 = !_L3_11;
  _L6_11 = BLACK;
  if (outC->init) {
    _L2_2_11 = kcg_false;
  }
  else {
    _L2_2_11 = outC->_L4_2_11;
  }
  _L2_11 = Allocate_11;
  Input_2_11 = _L2_11;
  _L1_2_11 = Input_2_11;
  _L3_2_11 = !_L2_2_11;
  if (_L1_2_11) {
    outC->_L4_2_11 = _L3_2_11;
  }
  else {
    outC->_L4_2_11 = _L2_2_11;
  }
  Output_2_11 = outC->_L4_2_11;
  _L4_11 = Output_2_11;
  _L5_11 = _L3_11 & _L4_11;
  _L7_11 = RED;
  _L8_11 = GREEN;
  if (_L5_11) {
    _L10_11 = _L7_11;
  }
  else {
    _L10_11 = _L8_11;
  }
  if (_L17_11) {
    _L9_11 = _L6_11;
  }
  else {
    _L9_11 = _L10_11;
  }
  BedColor_11 = _L9_11;
  _L33 = BedColor_11;
  _L15_11 = 1;
  _L14_11 = 0;
  if (_L5_11) {
    _L16_11 = _L15_11;
  }
  else {
    _L16_11 = _L14_11;
  }
  BedAllocated_11 = _L16_11;
  _L32 = BedAllocated_11;
  if (outC->init) {
    _L2_1_12 = kcg_false;
  }
  else {
    _L2_1_12 = outC->_L4_1_12;
  }
  _L48 = inC->ActivateBed5;
  Activate_12 = _L48;
  _L1_12 = Activate_12;
  Input_1_12 = _L1_12;
  _L1_1_12 = Input_1_12;
  _L3_1_12 = !_L2_1_12;
  if (_L1_1_12) {
    outC->_L4_1_12 = _L3_1_12;
  }
  else {
    outC->_L4_1_12 = _L2_1_12;
  }
  Output_1_12 = outC->_L4_1_12;
  _L3_12 = Output_1_12;
  _L17_12 = !_L3_12;
  _L6_12 = BLACK;
  if (outC->init) {
    _L2_2_12 = kcg_false;
  }
  else {
    _L2_2_12 = outC->_L4_2_12;
  }
  _L2_12 = Allocate_12;
  Input_2_12 = _L2_12;
  _L1_2_12 = Input_2_12;
  _L3_2_12 = !_L2_2_12;
  if (_L1_2_12) {
    outC->_L4_2_12 = _L3_2_12;
  }
  else {
    outC->_L4_2_12 = _L2_2_12;
  }
  Output_2_12 = outC->_L4_2_12;
  _L4_12 = Output_2_12;
  _L5_12 = _L3_12 & _L4_12;
  _L7_12 = RED;
  _L8_12 = GREEN;
  if (_L5_12) {
    _L10_12 = _L7_12;
  }
  else {
    _L10_12 = _L8_12;
  }
  if (_L17_12) {
    _L9_12 = _L6_12;
  }
  else {
    _L9_12 = _L10_12;
  }
  BedColor_12 = _L9_12;
  _L36 = BedColor_12;
  _L15_12 = 1;
  _L14_12 = 0;
  if (_L5_12) {
    _L16_12 = _L15_12;
  }
  else {
    _L16_12 = _L14_12;
  }
  BedAllocated_12 = _L16_12;
  _L35 = BedAllocated_12;
  _L66 = _L2 + _L11 + _L14 + _L17 + _L35 + _L20 + _L26 + _L32;
  _L72 = (kcg_real) _L66;
  _L12_1 = 1;
  _L13_1 = 0;
  if (_L3_1) {
    _L11_1 = _L12_1;
  }
  else {
    _L11_1 = _L13_1;
  }
  BedActive_1 = _L11_1;
  _L1 = BedActive_1;
  _L12_4 = 1;
  _L13_4 = 0;
  if (_L3_4) {
    _L11_4 = _L12_4;
  }
  else {
    _L11_4 = _L13_4;
  }
  BedActive_4 = _L11_4;
  _L10 = BedActive_4;
  _L12_5 = 1;
  _L13_5 = 0;
  if (_L3_5) {
    _L11_5 = _L12_5;
  }
  else {
    _L11_5 = _L13_5;
  }
  BedActive_5 = _L11_5;
  _L13 = BedActive_5;
  _L12_6 = 1;
  _L13_6 = 0;
  if (_L3_6) {
    _L11_6 = _L12_6;
  }
  else {
    _L11_6 = _L13_6;
  }
  BedActive_6 = _L11_6;
  _L16 = BedActive_6;
  _L12_12 = 1;
  _L13_12 = 0;
  if (_L3_12) {
    _L11_12 = _L12_12;
  }
  else {
    _L11_12 = _L13_12;
  }
  BedActive_12 = _L11_12;
  _L34 = BedActive_12;
  _L12_7 = 1;
  _L13_7 = 0;
  if (_L3_7) {
    _L11_7 = _L12_7;
  }
  else {
    _L11_7 = _L13_7;
  }
  BedActive_7 = _L11_7;
  _L19 = BedActive_7;
  _L12_9 = 1;
  _L13_9 = 0;
  if (_L3_9) {
    _L11_9 = _L12_9;
  }
  else {
    _L11_9 = _L13_9;
  }
  BedActive_9 = _L11_9;
  _L25 = BedActive_9;
  _L12_11 = 1;
  _L13_11 = 0;
  if (_L3_11) {
    _L11_11 = _L12_11;
  }
  else {
    _L11_11 = _L13_11;
  }
  BedActive_11 = _L11_11;
  _L31 = BedActive_11;
  _L52 = _L1 + _L10 + _L13 + _L16 + _L34 + _L19 + _L25 + _L31;
  _L67 = _L52 - _L66;
  _L71 = (kcg_real) _L67;
  _L70 = (kcg_real) _L52;
  _L69 = kcg_true;
  outC->LayerVisible = _L69;
  _L68 = kcg_true;
  outC->EmitToCDS = _L68;
  outC->BedColor8 = _L33;
  outC->BedColor7 = _L27;
  outC->BedColor6 = _L21;
  outC->BedColor5 = _L36;
  outC->BedColor4 = _L18;
  outC->BedColor3 = _L15;
  outC->BedColor2 = _L12;
  outC->FreeBedsCount = _L71;
  outC->BedColor1 = _L3;
  outC->AllocatedBedsCount = _L72;
  outC->ActiveBedsCount = _L70;
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** UTI.c
** Generation date: 2015-09-24T10:15:00
*************************************************************$ */

