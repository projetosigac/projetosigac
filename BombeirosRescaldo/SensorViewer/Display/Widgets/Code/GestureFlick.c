/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:14
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "GestureFlick.h"

#ifndef KCG_USER_DEFINED_INIT
void GestureFlick_init(outC_GestureFlick *outC)
{
  outC->EventFlick = kcg_true;
  outC->_L198 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  outC->YBegin = 0.0;
  outC->XBegin = 0.0;
  outC->pre_Memory_2_Util_real = 0.0;
  outC->pre_Memory_1_Util_real = 0.0;
  outC->_L10_1 = 0;
  outC->_2__L10_1 = 0;
  outC->Velocity = 0.0;
  outC->Direction = 0.0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void GestureFlick_reset(outC_GestureFlick *outC)
{
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* GestureFlick */
void GestureFlick(inC_GestureFlick *inC, outC_GestureFlick *outC)
{
  /* GestureFlick */ kcg_real tmp;
  /* Util::CyclicCounter::_L9 */ kcg_int _L9_1;
  /* Math::SafeDiv */ kcg_bool ck_every_2;
  /* GestureFlick::norm */ kcg_real norm;
  /* GestureFlick::_L210 */ kcg_int _L210;
  /* GestureFlick::_L214 */ kcg_real _L214;
  /* GestureFlick::_L227 */ kcg_real _L227;
  /* GestureFlick::_L228 */ kcg_bool _L228;
  
  _L228 = inC->MousePressed & inC->MouseInside;
  if (_L228) {
    outC->init = kcg_true;
    outC->XBegin = inC->PosXPx;
    outC->YBegin = inC->PosYPx;
  }
  else /* last_init_ck_YBegin */ if (outC->init1) {
    outC->XBegin = 0.0;
    outC->YBegin = 0.0;
  }
  /* 1_fby_1_init_2 */ if (outC->init) {
    _L9_1 = 0;
    outC->_2__L10_1 = 1 + 0;
  }
  else {
    _L9_1 = outC->_L10_1;
    outC->_2__L10_1 = 1 + outC->_2__L10_1;
  }
  /* 1 */ if (_L9_1 >= (kcg_int) (2.0 * inC->TimeTolerance / inC->CycleTime)) {
    _L210 = 0;
  }
  else {
    _L210 = _L9_1;
  }
  _L214 = (kcg_real) _L210 * inC->CycleTime;
  norm = /* 1_SqrtR */
    wid_SqrtR(
      (outC->XBegin - inC->PosXPx) * (outC->XBegin - inC->PosXPx) +
      (outC->YBegin - inC->PosYPx) * (outC->YBegin - inC->PosYPx));
  _L228 = norm > 1.0;
  /* ck__L228 */ if (_L228) {
    tmp = /* 1_Atan2R */
      wid_Atan2R(inC->PosYPx - outC->YBegin, inC->PosXPx - outC->XBegin) *
      (360.0 / 6.2831853);
  }
  else {
    tmp = 0.0 * (360.0 / 6.2831853);
  }
  /* 6 */ if (tmp < - 135.0) {
    _L227 = 180.0;
  }
  else /* 7 */ if (tmp < - 45.0) {
    _L227 = 270.0;
  }
  else /* 8 */ if (tmp < 45.0) {
    _L227 = 0.0;
  }
  else /* 9 */ if (tmp < 135.0) {
    _L227 = 90.0;
  }
  else {
    _L227 = 180.0;
  }
  /* 1_fby_1_init_1 */ if (outC->init1) {
    ck_every_2 = kcg_true;
    _L228 = kcg_false;
  }
  else {
    ck_every_2 = kcg_false;
    _L228 = outC->EventFlick;
  }
  /* 1 */ if (ck_every_2) {
    tmp = 0.0;
  }
  else {
    tmp = inC->TimeTolerance;
  }
  /* 1 */ if (tmp / inC->CycleTime < (kcg_real) outC->_2__L10_1) {
    outC->_L198 = kcg_true;
  }
  else /* 1_fby_1_init_1 */ if (outC->init) {
    outC->_L198 = kcg_false;
  }
  outC->init = kcg_false;
  outC->EventFlick = (!outC->_L198 & inC->MouseReleased & (norm >=
        inC->PosTolerance)) | (!BHVR_AsynchronousACK & _L228);
  ck_every_2 = (_L214 > 1.0e-10) | (_L214 < - 1.0e-10);
  /* 2_ck_SafeDiv */ if (ck_every_2) {
    tmp = norm / _L214;
  }
  else {
    tmp = norm;
  }
  /* 1 */ if (outC->init1) {
    outC->Velocity = tmp;
    outC->init1 = kcg_false;
    outC->Direction = _L227;
  }
  else {
    outC->Velocity = outC->pre_Memory_2_Util_real;
    outC->Direction = outC->pre_Memory_1_Util_real;
  }
  if (outC->EventFlick) {
    outC->pre_Memory_2_Util_real = tmp;
    outC->pre_Memory_1_Util_real = _L227;
  }
  else {
    outC->pre_Memory_2_Util_real = outC->Velocity;
    outC->pre_Memory_1_Util_real = outC->Direction;
  }
  /* 1_ck_CyclicCounter */ if (BHVR_AsynchronousACK) {
    outC->_L10_1 = 1 + _L210;
  }
  else {
    outC->_L10_1 = _L210;
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** GestureFlick.c
** Generation date: 2014-11-28T14:01:14
*************************************************************$ */

