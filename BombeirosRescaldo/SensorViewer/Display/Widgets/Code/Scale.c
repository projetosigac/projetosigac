/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "Scale.h"

#ifndef KCG_USER_DEFINED_INIT
void Scale_init(outC_Scale *outC)
{
  kcg_int i;
  
  outC->RunTimeMode = kcg_true;
  for (i = 0; i < 120; i++) {
    outC->SmallVisible[i] = kcg_true;
  }
  outC->Fractional = 0;
  outC->Integral = 0;
  for (i = 0; i < 60; i++) {
    outC->LargeVisible[i] = kcg_true;
    outC->ValuesNb[i] = 0.0;
  }
  for (i = 0; i < 120; i++) {
    outC->PosSmallPx[i] = 0.0;
  }
  for (i = 0; i < 60; i++) {
    outC->PosLargePx[i] = 0.0;
  }
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Scale_reset(outC_Scale *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Scale */
void Scale(inC_Scale *inC, outC_Scale *outC)
{
  /* Scale */ array_real_8 tmp1;
  /* Scale */ array_bool_8 tmp;
  kcg_int i;
  /* Scale */ kcg_real powered_exp;
  /* Math::Max::Ma_Output */ kcg_real Ma_Output_1_5;
  /* Math::RoundFloor::RF_Input */ kcg_real RF_Input_1_5;
  /* Math::RoundFloor::_L33 */ kcg_int _L33_2;
  /* Scale::IfBlock1 */ kcg_bool IfBlock1_clock;
  /* Scale::range */ kcg_real range;
  /* Scale::increment_nb */ kcg_real increment_nb;
  /* Scale::fontLengthPx */ kcg_real fontLengthPx;
  /* Scale::NormalisedRange */ kcg_real NormalisedRange;
  /* Scale::_L27 */ array_real_60 _L27;
  /* Scale::_L85 */ kcg_real _L85;
  /* Scale::_L88 */ kcg_real _L88;
  /* Scale::_L95 */ array_real_8 _L95;
  /* Scale::_L103 */ kcg_int _L103;
  /* Scale::_L128 */ kcg_bool _L128;
  
  outC->RunTimeMode = kcg_true;
  tmp1[0] = 0.02;
  tmp1[1] = 0.05;
  tmp1[2] = 0.1;
  tmp1[3] = 0.2;
  tmp1[4] = 0.5;
  tmp1[5] = 1.0;
  tmp1[6] = 2.0;
  tmp1[7] = 5.0;
  /* 1 */ if (inC->Range >= 0.000001) {
    range = inC->Range;
  }
  else {
    range = 0.000001;
  }
  _L85 = inC->Value - range / 2.0;
  IfBlock1_clock = inC->DistLargeGrad > 0.0;
  NormalisedRange = /* 1 */ wid_LogR(range);
  i = (kcg_int) NormalisedRange;
  /* 1 */ if (NormalisedRange >= 0.0) {
    _L33_2 = i;
  }
  else /* 2 */ if ((kcg_real) i == NormalisedRange) {
    _L33_2 = i;
  }
  else {
    _L33_2 = (kcg_int) (NormalisedRange - 1.0);
  }
  NormalisedRange = range / /* 1 */ wid_PowerR(10.0, _L33_2);
  for (i = 0; i < 8; i++) {
    _L95[i] = NormalisedRange / tmp1[i];
  }
  /* 2 */ if (_L33_2 <= 0) {
    outC->Fractional = - _L33_2 + 1;
  }
  else {
    outC->Fractional = 0;
  }
  NormalisedRange = inC->Value + inC->Range / 2.0;
  /* 1 */ if (0. <= NormalisedRange) {
    _L88 = NormalisedRange;
  }
  else {
    _L88 = - NormalisedRange;
  }
  /* 1 */ if (0. <= _L85) {
    NormalisedRange = _L85;
  }
  else {
    NormalisedRange = - _L85;
  }
  /* 1 */ if (_L88 >= NormalisedRange) {
    fontLengthPx = _L88;
  }
  else {
    fontLengthPx = NormalisedRange;
  }
  NormalisedRange = /* 2 */ wid_LogR(fontLengthPx);
  _L33_2 = (kcg_int) NormalisedRange;
  /* 1 */ if (NormalisedRange >= 0.0) {
    _L103 = _L33_2;
  }
  else /* 2 */ if ((kcg_real) _L33_2 == NormalisedRange) {
    _L103 = _L33_2;
  }
  else {
    _L103 = (kcg_int) (NormalisedRange - 1.0);
  }
  /* 1 */ if (_L103 >= 0) {
    outC->Integral = _L103 + 1;
  }
  else {
    outC->Integral = 1;
  }
  /* 5 */ GetFontSize_Strings(inC->Font, &fontLengthPx, &_L88);
  /* 12 */ if (outC->Fractional <= 0) {
    _L33_2 = 0;
  }
  else {
    _L33_2 = outC->Fractional + 1;
  }
  NormalisedRange = inC->SizePx / ((kcg_real) (_L33_2 + outC->Integral + 1) *
      fontLengthPx);
  for (i = 0; i < 8; i++) {
    tmp[i] = _L95[i] <= NormalisedRange;
  }
  /* 1 */ for (i = 0; i < 8; i++) {
    _L103 = i + 1;
    /* 1 */ if (tmp[i]) {
      break;
    }
  }
  if ((0 <= _L103 - 1) & (_L103 - 1 < 8)) {
    _L88 = _L95[_L103 - 1];
  }
  else {
    _L88 = 2.0;
  }
  _L128 = inC->NumberOfSmallGradPerLargeGrad > 0;
  /* ck__L128 */ if (_L128) {
    fontLengthPx = 1.0 / (kcg_real) inC->NumberOfSmallGradPerLargeGrad;
  }
  else {
    fontLengthPx = 1.0;
  }
  /* ck_IfBlock1 */ if (IfBlock1_clock) {
    increment_nb = inC->DistLargeGrad;
    NormalisedRange = inC->SizePx * inC->DistLargeGrad / range;
  }
  else {
    increment_nb = range / _L88;
    NormalisedRange = inC->SizePx / _L88;
  }
  _L88 = increment_nb * fontLengthPx;
  /* 1 */ if (_L88 >= 0.001) {
    Ma_Output_1_5 = _L88;
  }
  else {
    Ma_Output_1_5 = 0.001;
  }
  _L88 = _L85 / Ma_Output_1_5;
  _L33_2 = (kcg_int) _L88;
  /* 3 */ if (inC->NumberOfSmallGradPerLargeGrad == 0) {
    RF_Input_1_5 = 10.0;
  }
  else {
    /* 1 */ if (_L88 >= 0.0) {
      powered_exp = (kcg_real) _L33_2;
    }
    else /* 2 */ if ((kcg_real) _L33_2 == _L88) {
      powered_exp = (kcg_real) _L33_2;
    }
    else {
      powered_exp = (kcg_real) (kcg_int) (_L88 - 1.0);
    }
    RF_Input_1_5 = _L85 - powered_exp * Ma_Output_1_5;
  }
  _L88 = RF_Input_1_5 * (inC->SizePx / range);
  /* 10 */ if (inC->NumberOfSmallGradPerLargeGrad == 0) {
    powered_exp = 0.0;
  }
  else {
    powered_exp = NormalisedRange * fontLengthPx;
  }
  /* 1 */ if (increment_nb >= 0.001) {
    Ma_Output_1_5 = increment_nb;
  }
  else {
    Ma_Output_1_5 = 0.001;
  }
  RF_Input_1_5 = _L85 / Ma_Output_1_5;
  _L103 = (kcg_int) RF_Input_1_5;
  /* 1 */ if (RF_Input_1_5 >= 0.0) {
    fontLengthPx = (kcg_real) _L103;
  }
  else /* 2 */ if ((kcg_real) _L103 == RF_Input_1_5) {
    fontLengthPx = (kcg_real) _L103;
  }
  else {
    fontLengthPx = (kcg_real) (kcg_int) (RF_Input_1_5 - 1.0);
  }
  RF_Input_1_5 = _L85 - fontLengthPx * Ma_Output_1_5 + 0.0;
  fontLengthPx = RF_Input_1_5 * (inC->SizePx / range);
  Ma_Output_1_5 = _L85 - RF_Input_1_5;
  for (i = 0; i < 60; i++) {
    _L27[i] = (kcg_real) i;
  }
  for (i = 0; i < 60; i++) {
    outC->ValuesNb[i] = Ma_Output_1_5 + _L27[i] * increment_nb;
    outC->PosLargePx[i] = _L27[i] * NormalisedRange - fontLengthPx;
  }
  for (i = 0; i < 120; i++) {
    outC->PosSmallPx[i] = (kcg_real) i * powered_exp - _L88;
  }
  for (i = 0; i < 60; i++) {
    outC->LargeVisible[i] = (inC->SizePx >= outC->PosLargePx[i]) &
      (outC->PosLargePx[i] >= 0.0);
  }
  for (i = 0; i < 120; i++) {
    outC->SmallVisible[i] = (inC->SizePx >= outC->PosSmallPx[i]) &
      (outC->PosSmallPx[i] >= 0.0);
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Scale.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

