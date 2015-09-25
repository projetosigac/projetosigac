/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/thais/projetosigac/UA/UTI-availability/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-24T10:15:33
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
  outC->_L60 = inC->AllocateBed5;
  outC->Allocate_12 = outC->_L60;
  outC->_L62 = inC->AllocateBed8;
  outC->Allocate_11 = outC->_L62;
  outC->_L61 = inC->AllocateBed7;
  outC->Allocate_9 = outC->_L61;
  outC->_L59 = inC->AllocateBed6;
  outC->Allocate_7 = outC->_L59;
  outC->_L58 = inC->AllocateBed4;
  outC->Allocate_6 = outC->_L58;
  outC->_L57 = inC->AllocateBed3;
  outC->Allocate_5 = outC->_L57;
  outC->_L55 = inC->AllocateBed2;
  outC->Allocate_4 = outC->_L55;
  outC->_L56 = inC->AllocateBed1;
  outC->Allocate_1 = outC->_L56;
  if (outC->init) {
    outC->_L2_1_1 = kcg_false;
  }
  else {
    outC->_L2_1_1 = outC->_L4_1_1;
  }
  outC->_L54 = inC->ActivateBed1;
  outC->Activate_1 = outC->_L54;
  outC->_L1_1 = outC->Activate_1;
  outC->Input_1_1 = outC->_L1_1;
  outC->_L1_1_1 = outC->Input_1_1;
  outC->_L3_1_1 = !outC->_L2_1_1;
  if (outC->_L1_1_1) {
    outC->_L4_1_1 = outC->_L3_1_1;
  }
  else {
    outC->_L4_1_1 = outC->_L2_1_1;
  }
  outC->Output_1_1 = outC->_L4_1_1;
  outC->_L3_1 = outC->Output_1_1;
  outC->_L17_1 = !outC->_L3_1;
  outC->_L6_1 = BLACK;
  if (outC->init) {
    outC->_L2_2_1 = kcg_false;
  }
  else {
    outC->_L2_2_1 = outC->_L4_2_1;
  }
  outC->_L2_1 = outC->Allocate_1;
  outC->Input_2_1 = outC->_L2_1;
  outC->_L1_2_1 = outC->Input_2_1;
  outC->_L3_2_1 = !outC->_L2_2_1;
  if (outC->_L1_2_1) {
    outC->_L4_2_1 = outC->_L3_2_1;
  }
  else {
    outC->_L4_2_1 = outC->_L2_2_1;
  }
  outC->Output_2_1 = outC->_L4_2_1;
  outC->_L4_1 = outC->Output_2_1;
  outC->_L5_1 = outC->_L3_1 & outC->_L4_1;
  outC->_L7_1 = RED;
  outC->_L8_1 = GREEN;
  if (outC->_L5_1) {
    outC->_L10_1 = outC->_L7_1;
  }
  else {
    outC->_L10_1 = outC->_L8_1;
  }
  if (outC->_L17_1) {
    outC->_L9_1 = outC->_L6_1;
  }
  else {
    outC->_L9_1 = outC->_L10_1;
  }
  outC->BedColor_1 = outC->_L9_1;
  outC->_L3 = outC->BedColor_1;
  outC->_L15_1 = 1;
  outC->_L14_1 = 0;
  if (outC->_L5_1) {
    outC->_L16_1 = outC->_L15_1;
  }
  else {
    outC->_L16_1 = outC->_L14_1;
  }
  outC->BedAllocated_1 = outC->_L16_1;
  outC->_L2 = outC->BedAllocated_1;
  if (outC->init) {
    outC->_L2_1_4 = kcg_false;
  }
  else {
    outC->_L2_1_4 = outC->_L4_1_4;
  }
  outC->_L45 = inC->ActivateBed2;
  outC->Activate_4 = outC->_L45;
  outC->_L1_4 = outC->Activate_4;
  outC->Input_1_4 = outC->_L1_4;
  outC->_L1_1_4 = outC->Input_1_4;
  outC->_L3_1_4 = !outC->_L2_1_4;
  if (outC->_L1_1_4) {
    outC->_L4_1_4 = outC->_L3_1_4;
  }
  else {
    outC->_L4_1_4 = outC->_L2_1_4;
  }
  outC->Output_1_4 = outC->_L4_1_4;
  outC->_L3_4 = outC->Output_1_4;
  outC->_L17_4 = !outC->_L3_4;
  outC->_L6_4 = BLACK;
  if (outC->init) {
    outC->_L2_2_4 = kcg_false;
  }
  else {
    outC->_L2_2_4 = outC->_L4_2_4;
  }
  outC->_L2_4 = outC->Allocate_4;
  outC->Input_2_4 = outC->_L2_4;
  outC->_L1_2_4 = outC->Input_2_4;
  outC->_L3_2_4 = !outC->_L2_2_4;
  if (outC->_L1_2_4) {
    outC->_L4_2_4 = outC->_L3_2_4;
  }
  else {
    outC->_L4_2_4 = outC->_L2_2_4;
  }
  outC->Output_2_4 = outC->_L4_2_4;
  outC->_L4_4 = outC->Output_2_4;
  outC->_L5_4 = outC->_L3_4 & outC->_L4_4;
  outC->_L7_4 = RED;
  outC->_L8_4 = GREEN;
  if (outC->_L5_4) {
    outC->_L10_4 = outC->_L7_4;
  }
  else {
    outC->_L10_4 = outC->_L8_4;
  }
  if (outC->_L17_4) {
    outC->_L9_4 = outC->_L6_4;
  }
  else {
    outC->_L9_4 = outC->_L10_4;
  }
  outC->BedColor_4 = outC->_L9_4;
  outC->_L12 = outC->BedColor_4;
  outC->_L15_4 = 1;
  outC->_L14_4 = 0;
  if (outC->_L5_4) {
    outC->_L16_4 = outC->_L15_4;
  }
  else {
    outC->_L16_4 = outC->_L14_4;
  }
  outC->BedAllocated_4 = outC->_L16_4;
  outC->_L11 = outC->BedAllocated_4;
  if (outC->init) {
    outC->_L2_1_5 = kcg_false;
  }
  else {
    outC->_L2_1_5 = outC->_L4_1_5;
  }
  outC->_L46 = inC->ActivateBed3;
  outC->Activate_5 = outC->_L46;
  outC->_L1_5 = outC->Activate_5;
  outC->Input_1_5 = outC->_L1_5;
  outC->_L1_1_5 = outC->Input_1_5;
  outC->_L3_1_5 = !outC->_L2_1_5;
  if (outC->_L1_1_5) {
    outC->_L4_1_5 = outC->_L3_1_5;
  }
  else {
    outC->_L4_1_5 = outC->_L2_1_5;
  }
  outC->Output_1_5 = outC->_L4_1_5;
  outC->_L3_5 = outC->Output_1_5;
  outC->_L17_5 = !outC->_L3_5;
  outC->_L6_5 = BLACK;
  if (outC->init) {
    outC->_L2_2_5 = kcg_false;
  }
  else {
    outC->_L2_2_5 = outC->_L4_2_5;
  }
  outC->_L2_5 = outC->Allocate_5;
  outC->Input_2_5 = outC->_L2_5;
  outC->_L1_2_5 = outC->Input_2_5;
  outC->_L3_2_5 = !outC->_L2_2_5;
  if (outC->_L1_2_5) {
    outC->_L4_2_5 = outC->_L3_2_5;
  }
  else {
    outC->_L4_2_5 = outC->_L2_2_5;
  }
  outC->Output_2_5 = outC->_L4_2_5;
  outC->_L4_5 = outC->Output_2_5;
  outC->_L5_5 = outC->_L3_5 & outC->_L4_5;
  outC->_L7_5 = RED;
  outC->_L8_5 = GREEN;
  if (outC->_L5_5) {
    outC->_L10_5 = outC->_L7_5;
  }
  else {
    outC->_L10_5 = outC->_L8_5;
  }
  if (outC->_L17_5) {
    outC->_L9_5 = outC->_L6_5;
  }
  else {
    outC->_L9_5 = outC->_L10_5;
  }
  outC->BedColor_5 = outC->_L9_5;
  outC->_L15 = outC->BedColor_5;
  outC->_L15_5 = 1;
  outC->_L14_5 = 0;
  if (outC->_L5_5) {
    outC->_L16_5 = outC->_L15_5;
  }
  else {
    outC->_L16_5 = outC->_L14_5;
  }
  outC->BedAllocated_5 = outC->_L16_5;
  outC->_L14 = outC->BedAllocated_5;
  if (outC->init) {
    outC->_L2_1_6 = kcg_false;
  }
  else {
    outC->_L2_1_6 = outC->_L4_1_6;
  }
  outC->_L47 = inC->ActivateBed4;
  outC->Activate_6 = outC->_L47;
  outC->_L1_6 = outC->Activate_6;
  outC->Input_1_6 = outC->_L1_6;
  outC->_L1_1_6 = outC->Input_1_6;
  outC->_L3_1_6 = !outC->_L2_1_6;
  if (outC->_L1_1_6) {
    outC->_L4_1_6 = outC->_L3_1_6;
  }
  else {
    outC->_L4_1_6 = outC->_L2_1_6;
  }
  outC->Output_1_6 = outC->_L4_1_6;
  outC->_L3_6 = outC->Output_1_6;
  outC->_L17_6 = !outC->_L3_6;
  outC->_L6_6 = BLACK;
  if (outC->init) {
    outC->_L2_2_6 = kcg_false;
  }
  else {
    outC->_L2_2_6 = outC->_L4_2_6;
  }
  outC->_L2_6 = outC->Allocate_6;
  outC->Input_2_6 = outC->_L2_6;
  outC->_L1_2_6 = outC->Input_2_6;
  outC->_L3_2_6 = !outC->_L2_2_6;
  if (outC->_L1_2_6) {
    outC->_L4_2_6 = outC->_L3_2_6;
  }
  else {
    outC->_L4_2_6 = outC->_L2_2_6;
  }
  outC->Output_2_6 = outC->_L4_2_6;
  outC->_L4_6 = outC->Output_2_6;
  outC->_L5_6 = outC->_L3_6 & outC->_L4_6;
  outC->_L7_6 = RED;
  outC->_L8_6 = GREEN;
  if (outC->_L5_6) {
    outC->_L10_6 = outC->_L7_6;
  }
  else {
    outC->_L10_6 = outC->_L8_6;
  }
  if (outC->_L17_6) {
    outC->_L9_6 = outC->_L6_6;
  }
  else {
    outC->_L9_6 = outC->_L10_6;
  }
  outC->BedColor_6 = outC->_L9_6;
  outC->_L18 = outC->BedColor_6;
  outC->_L15_6 = 1;
  outC->_L14_6 = 0;
  if (outC->_L5_6) {
    outC->_L16_6 = outC->_L15_6;
  }
  else {
    outC->_L16_6 = outC->_L14_6;
  }
  outC->BedAllocated_6 = outC->_L16_6;
  outC->_L17 = outC->BedAllocated_6;
  if (outC->init) {
    outC->_L2_1_7 = kcg_false;
  }
  else {
    outC->_L2_1_7 = outC->_L4_1_7;
  }
  outC->_L49 = inC->ActivateBed6;
  outC->Activate_7 = outC->_L49;
  outC->_L1_7 = outC->Activate_7;
  outC->Input_1_7 = outC->_L1_7;
  outC->_L1_1_7 = outC->Input_1_7;
  outC->_L3_1_7 = !outC->_L2_1_7;
  if (outC->_L1_1_7) {
    outC->_L4_1_7 = outC->_L3_1_7;
  }
  else {
    outC->_L4_1_7 = outC->_L2_1_7;
  }
  outC->Output_1_7 = outC->_L4_1_7;
  outC->_L3_7 = outC->Output_1_7;
  outC->_L17_7 = !outC->_L3_7;
  outC->_L6_7 = BLACK;
  if (outC->init) {
    outC->_L2_2_7 = kcg_false;
  }
  else {
    outC->_L2_2_7 = outC->_L4_2_7;
  }
  outC->_L2_7 = outC->Allocate_7;
  outC->Input_2_7 = outC->_L2_7;
  outC->_L1_2_7 = outC->Input_2_7;
  outC->_L3_2_7 = !outC->_L2_2_7;
  if (outC->_L1_2_7) {
    outC->_L4_2_7 = outC->_L3_2_7;
  }
  else {
    outC->_L4_2_7 = outC->_L2_2_7;
  }
  outC->Output_2_7 = outC->_L4_2_7;
  outC->_L4_7 = outC->Output_2_7;
  outC->_L5_7 = outC->_L3_7 & outC->_L4_7;
  outC->_L7_7 = RED;
  outC->_L8_7 = GREEN;
  if (outC->_L5_7) {
    outC->_L10_7 = outC->_L7_7;
  }
  else {
    outC->_L10_7 = outC->_L8_7;
  }
  if (outC->_L17_7) {
    outC->_L9_7 = outC->_L6_7;
  }
  else {
    outC->_L9_7 = outC->_L10_7;
  }
  outC->BedColor_7 = outC->_L9_7;
  outC->_L21 = outC->BedColor_7;
  outC->_L15_7 = 1;
  outC->_L14_7 = 0;
  if (outC->_L5_7) {
    outC->_L16_7 = outC->_L15_7;
  }
  else {
    outC->_L16_7 = outC->_L14_7;
  }
  outC->BedAllocated_7 = outC->_L16_7;
  outC->_L20 = outC->BedAllocated_7;
  if (outC->init) {
    outC->_L2_1_9 = kcg_false;
  }
  else {
    outC->_L2_1_9 = outC->_L4_1_9;
  }
  outC->_L50 = inC->ActivateBed7;
  outC->Activate_9 = outC->_L50;
  outC->_L1_9 = outC->Activate_9;
  outC->Input_1_9 = outC->_L1_9;
  outC->_L1_1_9 = outC->Input_1_9;
  outC->_L3_1_9 = !outC->_L2_1_9;
  if (outC->_L1_1_9) {
    outC->_L4_1_9 = outC->_L3_1_9;
  }
  else {
    outC->_L4_1_9 = outC->_L2_1_9;
  }
  outC->Output_1_9 = outC->_L4_1_9;
  outC->_L3_9 = outC->Output_1_9;
  outC->_L17_9 = !outC->_L3_9;
  outC->_L6_9 = BLACK;
  if (outC->init) {
    outC->_L2_2_9 = kcg_false;
  }
  else {
    outC->_L2_2_9 = outC->_L4_2_9;
  }
  outC->_L2_9 = outC->Allocate_9;
  outC->Input_2_9 = outC->_L2_9;
  outC->_L1_2_9 = outC->Input_2_9;
  outC->_L3_2_9 = !outC->_L2_2_9;
  if (outC->_L1_2_9) {
    outC->_L4_2_9 = outC->_L3_2_9;
  }
  else {
    outC->_L4_2_9 = outC->_L2_2_9;
  }
  outC->Output_2_9 = outC->_L4_2_9;
  outC->_L4_9 = outC->Output_2_9;
  outC->_L5_9 = outC->_L3_9 & outC->_L4_9;
  outC->_L7_9 = RED;
  outC->_L8_9 = GREEN;
  if (outC->_L5_9) {
    outC->_L10_9 = outC->_L7_9;
  }
  else {
    outC->_L10_9 = outC->_L8_9;
  }
  if (outC->_L17_9) {
    outC->_L9_9 = outC->_L6_9;
  }
  else {
    outC->_L9_9 = outC->_L10_9;
  }
  outC->BedColor_9 = outC->_L9_9;
  outC->_L27 = outC->BedColor_9;
  outC->_L15_9 = 1;
  outC->_L14_9 = 0;
  if (outC->_L5_9) {
    outC->_L16_9 = outC->_L15_9;
  }
  else {
    outC->_L16_9 = outC->_L14_9;
  }
  outC->BedAllocated_9 = outC->_L16_9;
  outC->_L26 = outC->BedAllocated_9;
  if (outC->init) {
    outC->_L2_1_11 = kcg_false;
  }
  else {
    outC->_L2_1_11 = outC->_L4_1_11;
  }
  outC->_L51 = inC->ActivateBed8;
  outC->Activate_11 = outC->_L51;
  outC->_L1_11 = outC->Activate_11;
  outC->Input_1_11 = outC->_L1_11;
  outC->_L1_1_11 = outC->Input_1_11;
  outC->_L3_1_11 = !outC->_L2_1_11;
  if (outC->_L1_1_11) {
    outC->_L4_1_11 = outC->_L3_1_11;
  }
  else {
    outC->_L4_1_11 = outC->_L2_1_11;
  }
  outC->Output_1_11 = outC->_L4_1_11;
  outC->_L3_11 = outC->Output_1_11;
  outC->_L17_11 = !outC->_L3_11;
  outC->_L6_11 = BLACK;
  if (outC->init) {
    outC->_L2_2_11 = kcg_false;
  }
  else {
    outC->_L2_2_11 = outC->_L4_2_11;
  }
  outC->_L2_11 = outC->Allocate_11;
  outC->Input_2_11 = outC->_L2_11;
  outC->_L1_2_11 = outC->Input_2_11;
  outC->_L3_2_11 = !outC->_L2_2_11;
  if (outC->_L1_2_11) {
    outC->_L4_2_11 = outC->_L3_2_11;
  }
  else {
    outC->_L4_2_11 = outC->_L2_2_11;
  }
  outC->Output_2_11 = outC->_L4_2_11;
  outC->_L4_11 = outC->Output_2_11;
  outC->_L5_11 = outC->_L3_11 & outC->_L4_11;
  outC->_L7_11 = RED;
  outC->_L8_11 = GREEN;
  if (outC->_L5_11) {
    outC->_L10_11 = outC->_L7_11;
  }
  else {
    outC->_L10_11 = outC->_L8_11;
  }
  if (outC->_L17_11) {
    outC->_L9_11 = outC->_L6_11;
  }
  else {
    outC->_L9_11 = outC->_L10_11;
  }
  outC->BedColor_11 = outC->_L9_11;
  outC->_L33 = outC->BedColor_11;
  outC->_L15_11 = 1;
  outC->_L14_11 = 0;
  if (outC->_L5_11) {
    outC->_L16_11 = outC->_L15_11;
  }
  else {
    outC->_L16_11 = outC->_L14_11;
  }
  outC->BedAllocated_11 = outC->_L16_11;
  outC->_L32 = outC->BedAllocated_11;
  if (outC->init) {
    outC->_L2_1_12 = kcg_false;
  }
  else {
    outC->_L2_1_12 = outC->_L4_1_12;
  }
  outC->_L48 = inC->ActivateBed5;
  outC->Activate_12 = outC->_L48;
  outC->_L1_12 = outC->Activate_12;
  outC->Input_1_12 = outC->_L1_12;
  outC->_L1_1_12 = outC->Input_1_12;
  outC->_L3_1_12 = !outC->_L2_1_12;
  if (outC->_L1_1_12) {
    outC->_L4_1_12 = outC->_L3_1_12;
  }
  else {
    outC->_L4_1_12 = outC->_L2_1_12;
  }
  outC->Output_1_12 = outC->_L4_1_12;
  outC->_L3_12 = outC->Output_1_12;
  outC->_L17_12 = !outC->_L3_12;
  outC->_L6_12 = BLACK;
  if (outC->init) {
    outC->_L2_2_12 = kcg_false;
  }
  else {
    outC->_L2_2_12 = outC->_L4_2_12;
  }
  outC->_L2_12 = outC->Allocate_12;
  outC->Input_2_12 = outC->_L2_12;
  outC->_L1_2_12 = outC->Input_2_12;
  outC->_L3_2_12 = !outC->_L2_2_12;
  if (outC->_L1_2_12) {
    outC->_L4_2_12 = outC->_L3_2_12;
  }
  else {
    outC->_L4_2_12 = outC->_L2_2_12;
  }
  outC->Output_2_12 = outC->_L4_2_12;
  outC->_L4_12 = outC->Output_2_12;
  outC->_L5_12 = outC->_L3_12 & outC->_L4_12;
  outC->_L7_12 = RED;
  outC->_L8_12 = GREEN;
  if (outC->_L5_12) {
    outC->_L10_12 = outC->_L7_12;
  }
  else {
    outC->_L10_12 = outC->_L8_12;
  }
  if (outC->_L17_12) {
    outC->_L9_12 = outC->_L6_12;
  }
  else {
    outC->_L9_12 = outC->_L10_12;
  }
  outC->BedColor_12 = outC->_L9_12;
  outC->_L36 = outC->BedColor_12;
  outC->_L15_12 = 1;
  outC->_L14_12 = 0;
  if (outC->_L5_12) {
    outC->_L16_12 = outC->_L15_12;
  }
  else {
    outC->_L16_12 = outC->_L14_12;
  }
  outC->BedAllocated_12 = outC->_L16_12;
  outC->_L35 = outC->BedAllocated_12;
  outC->_L66 = outC->_L2 + outC->_L11 + outC->_L14 + outC->_L17 + outC->_L35 +
    outC->_L20 + outC->_L26 + outC->_L32;
  outC->_L72 = (kcg_real) outC->_L66;
  outC->_L12_1 = 1;
  outC->_L13_1 = 0;
  if (outC->_L3_1) {
    outC->_L11_1 = outC->_L12_1;
  }
  else {
    outC->_L11_1 = outC->_L13_1;
  }
  outC->BedActive_1 = outC->_L11_1;
  outC->_L1 = outC->BedActive_1;
  outC->_L12_4 = 1;
  outC->_L13_4 = 0;
  if (outC->_L3_4) {
    outC->_L11_4 = outC->_L12_4;
  }
  else {
    outC->_L11_4 = outC->_L13_4;
  }
  outC->BedActive_4 = outC->_L11_4;
  outC->_L10 = outC->BedActive_4;
  outC->_L12_5 = 1;
  outC->_L13_5 = 0;
  if (outC->_L3_5) {
    outC->_L11_5 = outC->_L12_5;
  }
  else {
    outC->_L11_5 = outC->_L13_5;
  }
  outC->BedActive_5 = outC->_L11_5;
  outC->_L13 = outC->BedActive_5;
  outC->_L12_6 = 1;
  outC->_L13_6 = 0;
  if (outC->_L3_6) {
    outC->_L11_6 = outC->_L12_6;
  }
  else {
    outC->_L11_6 = outC->_L13_6;
  }
  outC->BedActive_6 = outC->_L11_6;
  outC->_L16 = outC->BedActive_6;
  outC->_L12_12 = 1;
  outC->_L13_12 = 0;
  if (outC->_L3_12) {
    outC->_L11_12 = outC->_L12_12;
  }
  else {
    outC->_L11_12 = outC->_L13_12;
  }
  outC->BedActive_12 = outC->_L11_12;
  outC->_L34 = outC->BedActive_12;
  outC->_L12_7 = 1;
  outC->_L13_7 = 0;
  if (outC->_L3_7) {
    outC->_L11_7 = outC->_L12_7;
  }
  else {
    outC->_L11_7 = outC->_L13_7;
  }
  outC->BedActive_7 = outC->_L11_7;
  outC->_L19 = outC->BedActive_7;
  outC->_L12_9 = 1;
  outC->_L13_9 = 0;
  if (outC->_L3_9) {
    outC->_L11_9 = outC->_L12_9;
  }
  else {
    outC->_L11_9 = outC->_L13_9;
  }
  outC->BedActive_9 = outC->_L11_9;
  outC->_L25 = outC->BedActive_9;
  outC->_L12_11 = 1;
  outC->_L13_11 = 0;
  if (outC->_L3_11) {
    outC->_L11_11 = outC->_L12_11;
  }
  else {
    outC->_L11_11 = outC->_L13_11;
  }
  outC->BedActive_11 = outC->_L11_11;
  outC->_L31 = outC->BedActive_11;
  outC->_L52 = outC->_L1 + outC->_L10 + outC->_L13 + outC->_L16 + outC->_L34 +
    outC->_L19 + outC->_L25 + outC->_L31;
  outC->_L67 = outC->_L52 - outC->_L66;
  outC->_L71 = (kcg_real) outC->_L67;
  outC->_L70 = (kcg_real) outC->_L52;
  outC->_L69 = kcg_true;
  outC->LayerVisible = outC->_L69;
  outC->_L68 = kcg_true;
  outC->EmitToCDS = outC->_L68;
  outC->BedColor8 = outC->_L33;
  outC->BedColor7 = outC->_L27;
  outC->BedColor6 = outC->_L21;
  outC->BedColor5 = outC->_L36;
  outC->BedColor4 = outC->_L18;
  outC->BedColor3 = outC->_L15;
  outC->BedColor2 = outC->_L12;
  outC->FreeBedsCount = outC->_L71;
  outC->BedColor1 = outC->_L3;
  outC->AllocatedBedsCount = outC->_L72;
  outC->ActiveBedsCount = outC->_L70;
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** UTI.c
** Generation date: 2015-09-24T10:15:33
*************************************************************$ */

