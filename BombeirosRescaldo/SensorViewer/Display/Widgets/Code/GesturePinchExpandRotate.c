/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:14
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "GesturePinchExpandRotate.h"

#ifndef KCG_USER_DEFINED_INIT
void GesturePinchExpandRotate_init(outC_GesturePinchExpandRotate *outC)
{
  outC->Rotating = kcg_true;
  outC->Zooming = kcg_true;
  outC->Output1_2_1 = kcg_true;
  outC->Output1_1_1 = kcg_true;
  outC->_L197 = kcg_true;
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  outC->PosBeginY2 = 0.0;
  outC->PosBeginX2 = 0.0;
  outC->PosBeginY1 = 0.0;
  outC->PosBeginX1 = 0.0;
  outC->_L10_1_1 = 0;
  outC->_L10_2_1 = 0;
  outC->RotateAngle = 0.0;
  outC->ZoomFactor = 0.0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void GesturePinchExpandRotate_reset(outC_GesturePinchExpandRotate *outC)
{
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* GesturePinchExpandRotate */
void GesturePinchExpandRotate(
  inC_GesturePinchExpandRotate *inC,
  outC_GesturePinchExpandRotate *outC)
{
  /* GesturePinchExpandRotate */ kcg_real tmp4;
  /* GesturePinchExpandRotate */ kcg_bool tmp3;
  /* GesturePinchExpandRotate */ kcg_real tmp2;
  /* GesturePinchExpandRotate */ kcg_bool tmp1;
  /* GesturePinchExpandRotate */ kcg_bool tmp;
  /* Util::FlipFlopS::_L3 */ kcg_bool _L3_4;
  /* Math::RoundFloor::_L33 */ kcg_int _L33_1_1_1;
  /* Math::FractionalPart::_L45 */ kcg_real _L45_1_1;
  /* GesturePinchExpandRotate::NormBegin */ kcg_real NormBegin;
  /* GesturePinchExpandRotate::_L194 */ kcg_bool _L194;
  
  tmp = inC->MousePressed1 & inC->MouseInside1;
  /* 6_fby_1_init_1 */ if (outC->init2) {
    NormBegin = 0.0;
    tmp3 = kcg_false;
    tmp1 = kcg_false;
  }
  else {
    NormBegin = inC->TimeOutDelay;
    tmp3 = outC->_L197;
    tmp1 = outC->Rotating;
  }
  tmp4 = NormBegin / inC->CyclePeriod;
  if (tmp) {
    outC->init1 = kcg_true;
  }
  /* 1_1_fby_1_init_2 */ if (outC->init1) {
    outC->_L10_1_1 = 1 + 0;
  }
  else {
    outC->_L10_1_1 = 1 + outC->_L10_1_1;
  }
  /* 1 */ if (tmp4 < (kcg_real) outC->_L10_1_1) {
    outC->Output1_1_1 = kcg_true;
  }
  else /* 1_1_fby_1_init_1 */ if (outC->init1) {
    outC->Output1_1_1 = kcg_false;
  }
  outC->init1 = kcg_false;
  _L3_4 = inC->MousePressed2 & inC->MouseInside2;
  if (_L3_4) {
    outC->init = kcg_true;
  }
  /* 1_2_fby_1_init_2 */ if (outC->init) {
    outC->_L10_2_1 = 1 + 0;
  }
  else {
    outC->_L10_2_1 = 1 + outC->_L10_2_1;
  }
  /* 1 */ if (tmp4 < (kcg_real) outC->_L10_2_1) {
    outC->Output1_2_1 = kcg_true;
  }
  else /* 1_2_fby_1_init_1 */ if (outC->init) {
    outC->Output1_2_1 = kcg_false;
  }
  outC->init = kcg_false;
  _L194 = (!outC->Output1_1_1 & _L3_4) | (tmp & !outC->Output1_2_1);
  /* ck__L194 */ if (_L194) {
    outC->PosBeginX1 = inC->PosX1;
    outC->PosBeginY1 = inC->PosY1;
    outC->PosBeginX2 = inC->PosX2;
    outC->PosBeginY2 = inC->PosY2;
  }
  else /* last_init_ck_PosBeginY2 */ if (outC->init2) {
    outC->PosBeginX1 = inC->PosX1;
    outC->PosBeginY1 = inC->PosY1;
    outC->PosBeginX2 = inC->PosX1;
    outC->PosBeginY2 = inC->PosY1;
  }
  NormBegin = /* 1_SqrtR */
    wid_SqrtR(
      (outC->PosBeginX2 - outC->PosBeginX1) * (outC->PosBeginX2 -
        outC->PosBeginX1) + (outC->PosBeginY2 - outC->PosBeginY1) *
      (outC->PosBeginY2 - outC->PosBeginY1));
  /* 1 */ if (NormBegin < 1.0) {
    tmp4 = 1.0;
  }
  else {
    tmp4 = NormBegin;
  }
  outC->ZoomFactor = /* 2_SqrtR */
    wid_SqrtR(
      (inC->PosX2 - inC->PosX1) * (inC->PosX2 - inC->PosX1) + (inC->PosY2 -
        inC->PosY1) * (inC->PosY2 - inC->PosY1)) / tmp4;
  NormBegin = (/* 3_Atan2R */
      wid_Atan2R(inC->PosY2 - inC->PosY1, inC->PosX2 - inC->PosX1) -
      /* 1_Atan2R */
      wid_Atan2R(
        outC->PosBeginY2 - outC->PosBeginY1,
        outC->PosBeginX2 - outC->PosBeginX1)) * (360.0 / 6.2831853);
  _L3_4 = !(inC->MouseReleased1 | inC->MouseReleased2);
  outC->_L197 = _L194 | (_L3_4 & tmp3);
  /* 1 */ if (360.0 >= 0.001) {
    tmp4 = 360.0;
  }
  else {
    tmp4 = 0.001;
  }
  _L45_1_1 = NormBegin / tmp4;
  _L33_1_1_1 = (kcg_int) _L45_1_1;
  /* 1 */ if (_L45_1_1 >= 0.0) {
    tmp2 = (kcg_real) _L33_1_1_1;
  }
  else /* 2 */ if ((kcg_real) _L33_1_1_1 == _L45_1_1) {
    tmp2 = (kcg_real) _L33_1_1_1;
  }
  else {
    tmp2 = (kcg_real) (kcg_int) (_L45_1_1 - 1.0);
  }
  outC->RotateAngle = NormBegin - tmp2 * tmp4;
  outC->Rotating = (outC->_L197 & ((outC->RotateAngle > inC->MinimalRotation) &
        (outC->RotateAngle < 360.0 - inC->MinimalRotation))) | (_L3_4 & tmp1);
  /* 5_fby_1_init_1 */ if (outC->init2) {
    outC->init2 = kcg_false;
    tmp = kcg_false;
  }
  else {
    tmp = outC->Zooming;
  }
  outC->Zooming = (outC->_L197 & ((outC->ZoomFactor > inC->MinimalTranslation) |
        (outC->ZoomFactor < 1.0 / inC->MinimalTranslation))) | (_L3_4 & tmp);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** GesturePinchExpandRotate.c
** Generation date: 2014-11-28T14:01:14
*************************************************************$ */

