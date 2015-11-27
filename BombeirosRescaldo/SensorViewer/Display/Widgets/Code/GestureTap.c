/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "GestureTap.h"

#ifndef KCG_USER_DEFINED_INIT
void GestureTap_init(outC_GestureTap *outC)
{
  outC->EventTap = kcg_true;
  outC->EventDoubleTap = kcg_true;
  outC->_L149 = kcg_true;
  outC->_L167 = kcg_true;
  outC->rem_MouseReleased = kcg_true;
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  outC->PosBeginY = 0.0;
  outC->PosBeginX = 0.0;
  outC->_L10_2 = 0;
  outC->_L10_1 = 0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void GestureTap_reset(outC_GestureTap *outC)
{
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* GestureTap */
void GestureTap(inC_GestureTap *inC, outC_GestureTap *outC)
{
  /* GestureTap */ kcg_real tmp3;
  /* GestureTap */ kcg_real tmp2;
  /* GestureTap */ kcg_real tmp1;
  /* GestureTap */ kcg_bool tmp;
  /* Util::FlipFlopS::_L3 */ kcg_bool _L3_2;
  /* GestureTap::_L165 */ kcg_bool _L165;
  /* GestureTap::_L180 */ kcg_bool _L180;
  
  tmp = inC->MousePressed & inC->MouseInside;
  if (tmp) {
    outC->PosBeginX = inC->PosXPx;
    outC->PosBeginY = inC->PosYPx;
    outC->init = kcg_true;
  }
  else /* last_init_ck_PosBeginY */ if (outC->init2) {
    outC->PosBeginX = inC->PosXPx;
    outC->PosBeginY = inC->PosYPx;
  }
  tmp1 = inC->PosXPx - outC->PosBeginX;
  tmp3 = inC->PosYPx - outC->PosBeginY;
  /* 1_fby_1_init_2 */ if (outC->init) {
    outC->_L10_1 = 1 + 0;
  }
  else {
    outC->_L10_1 = 1 + outC->_L10_1;
  }
  /* 1 */ if (0. <= tmp1) {
    tmp2 = tmp1;
  }
  else {
    tmp2 = - tmp1;
  }
  /* 1 */ if (0. <= tmp3) {
    tmp1 = tmp3;
  }
  else {
    tmp1 = - tmp3;
  }
  /* 3_fby_1_init_1 */ if (outC->init2) {
    _L3_2 = kcg_true;
    _L165 = kcg_false;
    _L180 = kcg_false;
    outC->init2 = kcg_false;
    tmp = kcg_false;
  }
  else {
    _L3_2 = kcg_false;
    _L165 = outC->rem_MouseReleased;
    _L180 = outC->EventTap;
    tmp = outC->EventDoubleTap;
  }
  /* 1 */ if ((tmp2 + tmp1 > inC->PosTolerance) | _L3_2 | _L165) {
    tmp3 = 0.0;
  }
  else {
    tmp3 = inC->TimeOut1Tap;
  }
  /* 1 */ if (tmp3 / inC->CyclePeriod < (kcg_real) outC->_L10_1) {
    outC->_L149 = kcg_true;
  }
  else /* 1_fby_1_init_1 */ if (outC->init) {
    outC->_L149 = kcg_false;
  }
  outC->init = kcg_false;
  _L165 = !outC->_L149 & inC->MouseReleased;
  if (_L180) {
    outC->init1 = kcg_true;
  }
  /* 2_fby_1_init_2 */ if (outC->init1) {
    outC->_L10_2 = 1 + 0;
  }
  else {
    outC->_L10_2 = 1 + outC->_L10_2;
  }
  /* 2 */ if (_L3_2) {
    tmp1 = 0.0;
  }
  else {
    tmp1 = inC->TimeOut2Tap;
  }
  /* 1 */ if (tmp1 / inC->CyclePeriod < (kcg_real) outC->_L10_2) {
    outC->_L167 = kcg_true;
  }
  else /* 2_fby_1_init_1 */ if (outC->init1) {
    outC->_L167 = kcg_false;
  }
  outC->init1 = kcg_false;
  _L3_2 = !BHVR_AsynchronousACK;
  outC->EventDoubleTap = (!outC->_L167 & _L165) | (_L3_2 & tmp);
  outC->EventTap = _L165 | (_L3_2 & _L180);
  outC->rem_MouseReleased = inC->MouseReleased;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** GestureTap.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

