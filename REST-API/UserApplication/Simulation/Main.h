/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/ita/ces-65/REST-API/UserApplication/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-23T18:39:21
*************************************************************$ */
#ifndef _Main_H_
#define _Main_H_

#include "kcg_types.h"
#include "kcg_imported_functions.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_bool /* Main::GETSignalFromButton */ GETSignalFromButton;
  Path /* Main::RequestPath */ RequestPath;
  kcg_bool /* Main::Input3 */ Input3;
  kcg_bool /* Main::Input4 */ Input4;
  String /* Main::txtID */ txtID;
  kcg_bool /* Main::txtIDNotify */ txtIDNotify;
  kcg_int /* Main::txtIDLength */ txtIDLength;
} inC_Main;

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* Main::ReqLayerVisible */ ReqLayerVisible;
  kcg_bool /* Main::ReqLayerActive */ ReqLayerActive;
  kcg_bool /* Main::EmitToCDS */ EmitToCDS;
  kcg_int /* Main::ResultSize */ ResultSize;
  String /* Main::ResultName */ ResultName;
  String /* Main::ResultID */ ResultID;
  String /* Main::ResultSex */ ResultSex;
  String /* Main::ResultState */ ResultState;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  String /* ViewString::_L5 */ _L5_4;
  String /* ViewString::_L5 */ _L5_3;
  String /* ViewString::_L5 */ _L5_1;
  String /* GetValueFromTxtWidget::_L11 */ _L11_1;
  kcg_int /* GetValueFromTxtWidget::_L12 */ _L12_1;
  String /* ViewString::_L5 */ _L5_ViewString;
  kcg_bool /* InitDF::_L2 */ _L2_InitDF;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ------------------ clocks of observable data -------------------- */
  kcg_bool /* Main::GETRequestor */ GETRequestor_clock;
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  String /* ConcatString::_L1 */ _L1_ConcatString_4;
  array_char_10 /* ConcatString::_L2 */ _L2_ConcatString_4;
  array_char_522 /* ConcatString::_L3 */ _L3_ConcatString_4;
  array_char_512 /* ConcatString::_L4 */ _L4_ConcatString_4;
  String /* ConcatString::_L6 */ _L6_ConcatString_4;
  array_char_512 /* ConcatString::ResultString */ ResultString_ConcatString_4;
  String /* ConcatString::StringName */ StringName_ConcatString_4;
  String /* ConcatString::StringValue */ StringValue_ConcatString_4;
  String /* ViewString::_L3 */ _L3_4;
  String /* ViewString::_L2 */ _L2_4;
  kcg_bool /* ViewString::_L1 */ _L1_4;
  String /* ViewString::_L4 */ _L4_4;
  array_char_512 /* ViewString::_L6 */ _L6_4;
  array_char_512 /* ViewString::Result */ Result_4;
  String /* ViewString::BaseString */ BaseString_4;
  String /* ViewString::ValueString */ ValueString_4;
  kcg_bool /* ViewString::Button */ Button_4;
  String /* ConcatString::_L1 */ _L1_ConcatString_3;
  array_char_10 /* ConcatString::_L2 */ _L2_ConcatString_3;
  array_char_522 /* ConcatString::_L3 */ _L3_ConcatString_3;
  array_char_512 /* ConcatString::_L4 */ _L4_ConcatString_3;
  String /* ConcatString::_L6 */ _L6_ConcatString_3;
  array_char_512 /* ConcatString::ResultString */ ResultString_ConcatString_3;
  String /* ConcatString::StringName */ StringName_ConcatString_3;
  String /* ConcatString::StringValue */ StringValue_ConcatString_3;
  String /* ViewString::_L3 */ _L3_3;
  String /* ViewString::_L2 */ _L2_3;
  kcg_bool /* ViewString::_L1 */ _L1_3;
  String /* ViewString::_L4 */ _L4_3;
  array_char_512 /* ViewString::_L6 */ _L6_3;
  array_char_512 /* ViewString::Result */ Result_3;
  String /* ViewString::BaseString */ BaseString_3;
  String /* ViewString::ValueString */ ValueString_3;
  kcg_bool /* ViewString::Button */ Button_3;
  String /* ConcatString::_L1 */ _L1_ConcatString_1;
  array_char_10 /* ConcatString::_L2 */ _L2_ConcatString_1;
  array_char_522 /* ConcatString::_L3 */ _L3_ConcatString_1;
  array_char_512 /* ConcatString::_L4 */ _L4_ConcatString_1;
  String /* ConcatString::_L6 */ _L6_ConcatString_1;
  array_char_512 /* ConcatString::ResultString */ ResultString_ConcatString_1;
  String /* ConcatString::StringName */ StringName_ConcatString_1;
  String /* ConcatString::StringValue */ StringValue_ConcatString_1;
  String /* ViewString::_L3 */ _L3_1;
  String /* ViewString::_L2 */ _L2_1;
  kcg_bool /* ViewString::_L1 */ _L1_1;
  String /* ViewString::_L4 */ _L4_1;
  array_char_512 /* ViewString::_L6 */ _L6_1;
  array_char_512 /* ViewString::Result */ Result_1;
  String /* ViewString::BaseString */ BaseString_1;
  String /* ViewString::ValueString */ ValueString_1;
  kcg_bool /* ViewString::Button */ Button_1;
  String /* GetValueFromTxtWidget::_L7 */ _L7_1;
  kcg_bool /* GetValueFromTxtWidget::_L8 */ _L8_1;
  kcg_int /* GetValueFromTxtWidget::_L9 */ _L9_1;
  kcg_int /* GetValueFromTxtWidget::_L13 */ _L13_1;
  String /* GetValueFromTxtWidget::_L14 */ _L14_1;
  kcg_int /* GetValueFromTxtWidget::WidgetStringLength */ WidgetStringLength_1;
  String /* GetValueFromTxtWidget::WidgetString */ WidgetString_1;
  kcg_int /* GetValueFromTxtWidget::EvtStringLength */ EvtStringLength_1;
  kcg_bool /* GetValueFromTxtWidget::Notify */ Notify_1;
  String /* GetValueFromTxtWidget::EvtString */ EvtString_1;
  String /* ConcatString::_L1 */ _L1_ConcatString_ViewString;
  array_char_10 /* ConcatString::_L2 */ _L2_ConcatString_ViewString;
  array_char_522 /* ConcatString::_L3 */ _L3_ConcatString_ViewString;
  array_char_512 /* ConcatString::_L4 */ _L4_ConcatString_ViewString;
  String /* ConcatString::_L6 */ _L6_ConcatString_ViewString;
  array_char_512 /* ConcatString::ResultString */ ResultString_ConcatString_ViewString;
  String /* ConcatString::StringName */ StringName_ConcatString_ViewString;
  String /* ConcatString::StringValue */ StringValue_ConcatString_ViewString;
  String /* ViewString::_L3 */ _L3_ViewString;
  String /* ViewString::_L2 */ _L2_ViewString;
  kcg_bool /* ViewString::_L1 */ _L1_ViewString;
  String /* ViewString::_L4 */ _L4_ViewString;
  array_char_512 /* ViewString::_L6 */ _L6_ViewString;
  array_char_512 /* ViewString::Result */ Result_ViewString;
  String /* ViewString::BaseString */ BaseString_ViewString;
  String /* ViewString::ValueString */ ValueString_ViewString;
  kcg_bool /* ViewString::Button */ Button_ViewString;
  kcg_bool /* InitDF::_L1 */ _L1_InitDF;
  kcg_bool /* InitDF::ReqLayerActive */ ReqLayerActive_InitDF;
  kcg_bool /* InitDF::ReqLayerVisible */ ReqLayerVisible_InitDF;
  String /* Main::GETRequestor::then::_L17 */ _L17_GETRequestor;
  String /* Main::GETRequestor::then::_L12 */ _L12_GETRequestor;
  String /* Main::GETRequestor::then::_L11 */ _L11_GETRequestor;
  String /* Main::GETRequestor::then::_L10 */ _L10_GETRequestor;
  String /* Main::GETRequestor::then::_L9 */ _L9_GETRequestor;
  String /* Main::GETRequestor::then::_L8 */ _L8_GETRequestor;
  String /* Main::Name */ Name;
  String /* Main::Comment */ Comment;
  String /* Main::State */ State;
  String /* Main::ID */ ID;
  String /* Main::Sex */ Sex;
  String /* Main::VictimIDString */ VictimIDString;
  kcg_int /* Main::VictimIDSize */ VictimIDSize;
  kcg_bool /* Main::_L6 */ _L6;
  kcg_bool /* Main::_L5 */ _L5;
  kcg_bool /* Main::_L7 */ _L7;
  kcg_int /* Main::_L8 */ _L8;
  String /* Main::_L16 */ _L16;
  kcg_bool /* Main::_L19 */ _L19;
  array_char_512 /* Main::_L31 */ _L31;
  String /* Main::_L32 */ _L32;
  kcg_int /* Main::_L34 */ _L34;
  String /* Main::_L33 */ _L33;
  String /* Main::_L35 */ _L35;
  kcg_bool /* Main::_L36 */ _L36;
  kcg_int /* Main::_L37 */ _L37;
  array_char_512 /* Main::_L39 */ _L39;
  String /* Main::_L38 */ _L38;
  String /* Main::_L42 */ _L42;
  array_char_512 /* Main::_L48 */ _L48;
  String /* Main::_L47 */ _L47;
  String /* Main::_L51 */ _L51;
  array_char_512 /* Main::_L49 */ _L49;
  String /* Main::_L52 */ _L52;
  String /* Main::_L53 */ _L53;
} outC_Main;

/* ===========  node initialization and cycle functions  =========== */
/* Main */
extern void Main(inC_Main *inC, outC_Main *outC);

extern void Main_reset(outC_Main *outC);

#endif /* _Main_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** Main.h
** Generation date: 2015-09-23T18:39:21
*************************************************************$ */

