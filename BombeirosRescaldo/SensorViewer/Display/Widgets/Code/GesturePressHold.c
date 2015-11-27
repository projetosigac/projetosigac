/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "GesturePressHold.h"

#ifndef KCG_USER_DEFINED_INIT
void GesturePressHold_init(outC_GesturePressHold *outC)
{
  outC->HoldBegin = kcg_true;
  outC->Holding = kcg_true;
  outC->HoldEnd = kcg_true;
  outC->_L149 = kcg_true;
  outC->_L181 = kcg_true;
  outC->rem_RE_Input_2 = kcg_true;
  outC->rem__L186 = kcg_true;
  outC->rem_HoldEnd = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  outC->PosBeginY = 0.0;
  outC->PosBeginX = 0.0;
  outC->_L10_1 = 0;
  outC->PosOutY = 0.0;
  outC->PosOutX = 0.0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void GesturePressHold_reset(outC_GesturePressHold *outC)
{
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* GesturePressHold */
void GesturePressHold(inC_GesturePressHold *inC, outC_GesturePressHold *outC)
{
  /* GesturePressHold */ kcg_real tmp7;
  /* GesturePressHold */ kcg_real tmp6;
  /* GesturePressHold */ kcg_real tmp5;
  /* GesturePressHold */ kcg_bool tmp4;
  /* GesturePressHold */ kcg_bool tmp3;
  /* GesturePressHold */ kcg_bool tmp2;
  /* GesturePressHold */ kcg_bool tmp1;
  /* GesturePressHold */ kcg_bool tmp;
  /* GesturePressHold::_L186 */ kcg_bool _L186;
  /* GesturePressHold::_L188 */ kcg_bool _L188;
  
  tmp3 = inC->MousePressed & inC->MouseInside;
  if (tmp3) {
    outC->PosBeginX = inC->PosXPx;
    outC->PosBeginY = inC->PosYPx;
    outC->init = kcg_true;
  }
  else /* last_init_ck_PosBeginY */ if (outC->init1) {
    outC->PosBeginX = inC->PosXPx;
    outC->PosBeginY = inC->PosYPx;
  }
  tmp6 = inC->PosXPx - outC->PosBeginX;
  tmp5 = inC->PosYPx - outC->PosBeginY;
  /* 1 */ if (0. <= tmp6) {
    tmp7 = tmp6;
  }
  else {
    tmp7 = - tmp6;
  }
  /* 1 */ if (0. <= tmp5) {
    tmp6 = tmp5;
  }
  else {
    tmp6 = - tmp5;
  }
  /* 1 */ if (outC->init1) {
    _L186 = kcg_false;
    tmp4 = kcg_true;
  }
  else {
    _L186 = outC->_L181;
    tmp4 = kcg_false;
  }
  outC->_L181 = tmp3 | (!((tmp7 + tmp6 > inC->PosTolerance) |
        inC->MouseReleased) & _L186);
  /* 1_fby_1_init_2 */ if (outC->init) {
    outC->_L10_1 = 1 + 0;
  }
  else {
    outC->_L10_1 = 1 + outC->_L10_1;
  }
  /* 1 */ if (tmp4) {
    tmp5 = 0.0;
  }
  else {
    tmp5 = inC->DelayHold;
  }
  /* 1 */ if (tmp5 / inC->CyclePeriod < (kcg_real) outC->_L10_1) {
    outC->_L149 = kcg_true;
  }
  else /* 1_fby_1_init_1 */ if (outC->init) {
    outC->_L149 = kcg_false;
  }
  outC->init = kcg_false;
  _L186 = outC->_L181 & outC->_L149;
  /* 3_fby_1_init_1 */ if (outC->init1) {
    tmp4 = !_L186;
    tmp3 = kcg_false;
  }
  else {
    tmp4 = !outC->rem__L186;
    tmp3 = outC->Holding;
  }
  _L188 = tmp4 & _L186;
  outC->Holding = _L188 | (!inC->MouseReleased & tmp3);
  /* ck_Holding */ if (outC->Holding) {
    outC->PosOutX = inC->PosXPx;
    outC->PosOutY = inC->PosYPx;
  }
  else /* last_init_ck_PosOutY */ if (outC->init1) {
    outC->PosOutX = inC->PosXPx;
    outC->PosOutY = inC->PosYPx;
  }
  tmp4 = !outC->Holding;
  tmp3 = !BHVR_AsynchronousACK;
  /* 4_fby_1_init_1 */ if (outC->init1) {
    tmp1 = kcg_false;
    tmp2 = !tmp4;
    outC->init1 = kcg_false;
    tmp = kcg_false;
  }
  else {
    tmp2 = !outC->rem_RE_Input_2;
    tmp1 = outC->rem_HoldEnd;
    tmp = outC->HoldBegin;
  }
  outC->HoldEnd = (tmp2 & tmp4) | (tmp3 & tmp1);
  outC->HoldBegin = _L188 | (tmp3 & tmp);
  outC->rem_HoldEnd = outC->HoldEnd;
  outC->rem__L186 = _L186;
  outC->rem_RE_Input_2 = tmp4;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** GesturePressHold.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

