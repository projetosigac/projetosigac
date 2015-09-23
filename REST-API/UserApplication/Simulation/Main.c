/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/ita/ces-65/REST-API/UserApplication/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-23T18:39:21
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Main.h"

void Main_reset(outC_Main *outC)
{
  outC->init = kcg_true;
}

/* Main */
void Main(inC_Main *inC, outC_Main *outC)
{
  /* Main::Name */ String Name5;
  /* Main::Comment */ String _4_Comment;
  /* Main::State */ String State3;
  /* Main::ID */ String ID2;
  /* Main::Sex */ String Sex1;
  /* Main::Name */ String Name;
  /* Main::Comment */ String Comment;
  /* Main::State */ String State;
  /* Main::ID */ String ID;
  /* Main::Sex */ String Sex;
  
  kcg_copy_String(&outC->_L51, (String *) &BASE_STATE);
  kcg_copy_String(&outC->BaseString_4, &outC->_L51);
  outC->GETRequestor_clock = inC->GETSignalFromButton;
  if (outC->GETRequestor_clock) {
  }
  else {
    kcg_copy_String(&State, (String *) &TESTE_STRING);
  }
  if (outC->init) {
    kcg_copy_String(&outC->_L14_1, (String *) &TESTE_STRING);
  }
  else {
    kcg_copy_String(&outC->_L14_1, &outC->_L11_1);
  }
  kcg_copy_String(&outC->WidgetString_1, &outC->_L14_1);
  kcg_copy_String(&outC->_L33, &outC->WidgetString_1);
  kcg_copy_String(&outC->VictimIDString, &outC->_L33);
  if (outC->GETRequestor_clock) {
    kcg_copy_String(&outC->_L17_GETRequestor, &outC->VictimIDString);
    /* 2 */
    Operator3(
      &outC->_L17_GETRequestor,
      &outC->_L8_GETRequestor,
      &outC->_L9_GETRequestor,
      &outC->_L10_GETRequestor,
      &outC->_L11_GETRequestor,
      &outC->_L12_GETRequestor);
    kcg_copy_String(&State3, &outC->_L11_GETRequestor);
    kcg_copy_String(&outC->State, &State3);
  }
  else {
    kcg_copy_String(&outC->State, &State);
  }
  kcg_copy_String(&outC->_L53, &outC->State);
  kcg_copy_String(&outC->ValueString_4, &outC->_L53);
  kcg_copy_String(&outC->_L47, (String *) &BASE_SEX);
  kcg_copy_String(&outC->BaseString_3, &outC->_L47);
  if (outC->GETRequestor_clock) {
    kcg_copy_String(&Sex1, &outC->_L10_GETRequestor);
    kcg_copy_String(&outC->Sex, &Sex1);
  }
  else {
    kcg_copy_String(&Sex, (String *) &TESTE_STRING);
    kcg_copy_String(&outC->Sex, &Sex);
  }
  kcg_copy_String(&outC->_L52, &outC->Sex);
  kcg_copy_String(&outC->ValueString_3, &outC->_L52);
  kcg_copy_String(&outC->_L38, (String *) &BASE_ID);
  kcg_copy_String(&outC->BaseString_1, &outC->_L38);
  if (outC->GETRequestor_clock) {
    kcg_copy_String(&ID2, &outC->_L9_GETRequestor);
    kcg_copy_String(&outC->ID, &ID2);
  }
  else {
    kcg_copy_String(&ID, (String *) &TESTE_STRING);
    kcg_copy_String(&outC->ID, &ID);
  }
  kcg_copy_String(&outC->_L42, &outC->ID);
  kcg_copy_String(&outC->ValueString_1, &outC->_L42);
  outC->_L37 = inC->txtIDLength;
  outC->EvtStringLength_1 = outC->_L37;
  outC->_L36 = inC->txtIDNotify;
  outC->Notify_1 = outC->_L36;
  kcg_copy_String(&outC->_L32, (String *) &BASE_NAME);
  kcg_copy_String(&outC->BaseString_ViewString, &outC->_L32);
  if (outC->GETRequestor_clock) {
    kcg_copy_String(&Name5, &outC->_L8_GETRequestor);
    kcg_copy_String(&outC->Name, &Name5);
  }
  else {
    kcg_copy_String(&Name, (String *) &TESTE_STRING);
    kcg_copy_String(&outC->Name, &Name);
  }
  kcg_copy_String(&outC->_L16, &outC->Name);
  kcg_copy_String(&outC->ValueString_ViewString, &outC->_L16);
  if (outC->init) {
    outC->_L1_InitDF = kcg_true;
  }
  else {
    outC->_L1_InitDF = outC->_L2_InitDF;
  }
  outC->ReqLayerActive_InitDF = outC->_L1_InitDF;
  outC->_L6 = outC->ReqLayerActive_InitDF;
  if (outC->init) {
    outC->_L13_1 = 0;
  }
  else {
    outC->_L13_1 = outC->_L12_1;
  }
  outC->WidgetStringLength_1 = outC->_L13_1;
  outC->_L34 = outC->WidgetStringLength_1;
  kcg_copy_String(&outC->_L3_4, &outC->BaseString_4);
  kcg_copy_String(&outC->StringName_ConcatString_4, &outC->_L3_4);
  kcg_copy_String(&outC->_L6_ConcatString_4, &outC->StringName_ConcatString_4);
  kcg_copy_array_char_10(
    &outC->_L2_ConcatString_4,
    (array_char_10 *) &outC->_L6_ConcatString_4[0]);
  if (outC->init) {
    kcg_copy_String(&outC->_L4_4, (String *) &TESTE_STRING);
  }
  else {
    kcg_copy_String(&outC->_L4_4, &outC->_L5_4);
  }
  kcg_copy_String(&outC->StringValue_ConcatString_4, &outC->_L4_4);
  kcg_copy_String(&outC->_L1_ConcatString_4, &outC->StringValue_ConcatString_4);
  kcg_copy_array_char_10(
    &outC->_L3_ConcatString_4[0],
    &outC->_L2_ConcatString_4);
  kcg_copy_String(&outC->_L3_ConcatString_4[10], &outC->_L1_ConcatString_4);
  kcg_copy_array_char_512(
    &outC->_L4_ConcatString_4,
    (array_char_512 *) &outC->_L3_ConcatString_4[0]);
  kcg_copy_array_char_512(
    &outC->ResultString_ConcatString_4,
    &outC->_L4_ConcatString_4);
  kcg_copy_array_char_512(&outC->_L6_4, &outC->ResultString_ConcatString_4);
  kcg_copy_array_char_512(&outC->Result_4, &outC->_L6_4);
  kcg_copy_array_char_512(&outC->_L49, &outC->Result_4);
  kcg_copy_String(&outC->ResultState, &outC->_L49);
  kcg_copy_String(&outC->_L3_3, &outC->BaseString_3);
  kcg_copy_String(&outC->StringName_ConcatString_3, &outC->_L3_3);
  kcg_copy_String(&outC->_L6_ConcatString_3, &outC->StringName_ConcatString_3);
  kcg_copy_array_char_10(
    &outC->_L2_ConcatString_3,
    (array_char_10 *) &outC->_L6_ConcatString_3[0]);
  if (outC->init) {
    kcg_copy_String(&outC->_L4_3, (String *) &TESTE_STRING);
  }
  else {
    kcg_copy_String(&outC->_L4_3, &outC->_L5_3);
  }
  kcg_copy_String(&outC->StringValue_ConcatString_3, &outC->_L4_3);
  kcg_copy_String(&outC->_L1_ConcatString_3, &outC->StringValue_ConcatString_3);
  kcg_copy_array_char_10(
    &outC->_L3_ConcatString_3[0],
    &outC->_L2_ConcatString_3);
  kcg_copy_String(&outC->_L3_ConcatString_3[10], &outC->_L1_ConcatString_3);
  kcg_copy_array_char_512(
    &outC->_L4_ConcatString_3,
    (array_char_512 *) &outC->_L3_ConcatString_3[0]);
  kcg_copy_array_char_512(
    &outC->ResultString_ConcatString_3,
    &outC->_L4_ConcatString_3);
  kcg_copy_array_char_512(&outC->_L6_3, &outC->ResultString_ConcatString_3);
  kcg_copy_array_char_512(&outC->Result_3, &outC->_L6_3);
  kcg_copy_array_char_512(&outC->_L48, &outC->Result_3);
  kcg_copy_String(&outC->ResultSex, &outC->_L48);
  kcg_copy_String(&outC->_L3_1, &outC->BaseString_1);
  kcg_copy_String(&outC->StringName_ConcatString_1, &outC->_L3_1);
  kcg_copy_String(&outC->_L6_ConcatString_1, &outC->StringName_ConcatString_1);
  kcg_copy_array_char_10(
    &outC->_L2_ConcatString_1,
    (array_char_10 *) &outC->_L6_ConcatString_1[0]);
  if (outC->init) {
    kcg_copy_String(&outC->_L4_1, (String *) &TESTE_STRING);
  }
  else {
    kcg_copy_String(&outC->_L4_1, &outC->_L5_1);
  }
  kcg_copy_String(&outC->StringValue_ConcatString_1, &outC->_L4_1);
  kcg_copy_String(&outC->_L1_ConcatString_1, &outC->StringValue_ConcatString_1);
  kcg_copy_array_char_10(
    &outC->_L3_ConcatString_1[0],
    &outC->_L2_ConcatString_1);
  kcg_copy_String(&outC->_L3_ConcatString_1[10], &outC->_L1_ConcatString_1);
  kcg_copy_array_char_512(
    &outC->_L4_ConcatString_1,
    (array_char_512 *) &outC->_L3_ConcatString_1[0]);
  kcg_copy_array_char_512(
    &outC->ResultString_ConcatString_1,
    &outC->_L4_ConcatString_1);
  kcg_copy_array_char_512(&outC->_L6_1, &outC->ResultString_ConcatString_1);
  kcg_copy_array_char_512(&outC->Result_1, &outC->_L6_1);
  kcg_copy_array_char_512(&outC->_L39, &outC->Result_1);
  kcg_copy_String(&outC->ResultID, &outC->_L39);
  outC->VictimIDSize = outC->_L34;
  kcg_copy_String(&outC->_L35, &inC->txtID);
  kcg_copy_String(&outC->_L3_ViewString, &outC->BaseString_ViewString);
  kcg_copy_String(
    &outC->StringName_ConcatString_ViewString,
    &outC->_L3_ViewString);
  kcg_copy_String(
    &outC->_L6_ConcatString_ViewString,
    &outC->StringName_ConcatString_ViewString);
  kcg_copy_array_char_10(
    &outC->_L2_ConcatString_ViewString,
    (array_char_10 *) &outC->_L6_ConcatString_ViewString[0]);
  if (outC->init) {
    kcg_copy_String(&outC->_L4_ViewString, (String *) &TESTE_STRING);
  }
  else {
    kcg_copy_String(&outC->_L4_ViewString, &outC->_L5_ViewString);
  }
  kcg_copy_String(
    &outC->StringValue_ConcatString_ViewString,
    &outC->_L4_ViewString);
  kcg_copy_String(
    &outC->_L1_ConcatString_ViewString,
    &outC->StringValue_ConcatString_ViewString);
  kcg_copy_array_char_10(
    &outC->_L3_ConcatString_ViewString[0],
    &outC->_L2_ConcatString_ViewString);
  kcg_copy_String(
    &outC->_L3_ConcatString_ViewString[10],
    &outC->_L1_ConcatString_ViewString);
  kcg_copy_array_char_512(
    &outC->_L4_ConcatString_ViewString,
    (array_char_512 *) &outC->_L3_ConcatString_ViewString[0]);
  kcg_copy_array_char_512(
    &outC->ResultString_ConcatString_ViewString,
    &outC->_L4_ConcatString_ViewString);
  kcg_copy_array_char_512(
    &outC->_L6_ViewString,
    &outC->ResultString_ConcatString_ViewString);
  kcg_copy_array_char_512(&outC->Result_ViewString, &outC->_L6_ViewString);
  kcg_copy_array_char_512(&outC->_L31, &outC->Result_ViewString);
  outC->_L19 = inC->GETSignalFromButton;
  kcg_copy_String(&outC->ResultName, &outC->_L31);
  outC->_L8 = MAX_STRING_SIZE;
  outC->ResultSize = outC->_L8;
  outC->_L7 = kcg_true;
  outC->EmitToCDS = outC->_L7;
  if (outC->GETRequestor_clock) {
    kcg_copy_String(&_4_Comment, &outC->_L12_GETRequestor);
    kcg_copy_String(&outC->Comment, &_4_Comment);
  }
  else {
    kcg_copy_String(&Comment, (String *) &TESTE_STRING);
    kcg_copy_String(&outC->Comment, &Comment);
  }
  outC->ReqLayerVisible_InitDF = outC->_L1_InitDF;
  outC->_L5 = outC->ReqLayerVisible_InitDF;
  outC->ReqLayerVisible = outC->_L5;
  outC->ReqLayerActive = outC->_L6;
  outC->_L2_InitDF = kcg_false;
  outC->Button_ViewString = outC->_L19;
  outC->_L1_ViewString = outC->Button_ViewString;
  kcg_copy_String(&outC->_L2_ViewString, &outC->ValueString_ViewString);
  if (outC->_L1_ViewString) {
    kcg_copy_String(&outC->_L5_ViewString, &outC->_L2_ViewString);
  }
  else {
    kcg_copy_String(&outC->_L5_ViewString, &outC->_L4_ViewString);
  }
  kcg_copy_String(&outC->EvtString_1, &outC->_L35);
  outC->_L8_1 = outC->Notify_1;
  outC->_L9_1 = outC->EvtStringLength_1;
  if (outC->_L8_1) {
    outC->_L12_1 = outC->_L9_1;
  }
  else {
    outC->_L12_1 = outC->_L13_1;
  }
  kcg_copy_String(&outC->_L7_1, &outC->EvtString_1);
  if (outC->_L8_1) {
    kcg_copy_String(&outC->_L11_1, &outC->_L7_1);
  }
  else {
    kcg_copy_String(&outC->_L11_1, &outC->_L14_1);
  }
  outC->Button_1 = outC->_L19;
  outC->_L1_1 = outC->Button_1;
  kcg_copy_String(&outC->_L2_1, &outC->ValueString_1);
  if (outC->_L1_1) {
    kcg_copy_String(&outC->_L5_1, &outC->_L2_1);
  }
  else {
    kcg_copy_String(&outC->_L5_1, &outC->_L4_1);
  }
  outC->Button_3 = outC->_L19;
  outC->_L1_3 = outC->Button_3;
  kcg_copy_String(&outC->_L2_3, &outC->ValueString_3);
  if (outC->_L1_3) {
    kcg_copy_String(&outC->_L5_3, &outC->_L2_3);
  }
  else {
    kcg_copy_String(&outC->_L5_3, &outC->_L4_3);
  }
  outC->Button_4 = outC->_L19;
  outC->_L1_4 = outC->Button_4;
  kcg_copy_String(&outC->_L2_4, &outC->ValueString_4);
  if (outC->_L1_4) {
    kcg_copy_String(&outC->_L5_4, &outC->_L2_4);
  }
  else {
    kcg_copy_String(&outC->_L5_4, &outC->_L4_4);
  }
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** Main.c
** Generation date: 2015-09-23T18:39:21
*************************************************************$ */

