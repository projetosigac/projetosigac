/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "GraphTimed.h"

#ifndef KCG_USER_DEFINED_INIT
void GraphTimed_init(outC_GraphTimed *outC)
{
  outC->rem_PauseInput = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  outC->pre_Memory_1_Util_int = 0;
  outC->_L10_1 = 0;
  outC->VisiblePoints_out = 0;
  outC->Offset = 0;
  outC->CurrentCycle = 0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void GraphTimed_reset(outC_GraphTimed *outC)
{
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* GraphTimed */
void GraphTimed(inC_GraphTimed *inC, outC_GraphTimed *outC)
{
  /* GraphTimed */ kcg_bool tmp;
  /* GraphTimed::_L31 */ kcg_int _L31;
  
  if (inC->Reset) {
    outC->init = kcg_true;
  }
  /* 1_fby_1_init_2 */ if (outC->init) {
    outC->init = kcg_false;
    _L31 = 0;
  }
  else {
    _L31 = outC->_L10_1;
  }
  /* 1 */ if (_L31 >= 32677) {
    outC->CurrentCycle = 0;
  }
  else {
    outC->CurrentCycle = _L31;
  }
  /* 1_fby_1_init_1 */ if (outC->init1) {
    _L31 = outC->CurrentCycle;
    outC->init1 = kcg_false;
    tmp = !inC->PauseInput;
  }
  else {
    _L31 = outC->pre_Memory_1_Util_int;
    tmp = !outC->rem_PauseInput;
  }
  /* 4 */ if (outC->CurrentCycle <= inC->NbVisiblePoints) {
    outC->Offset = - (inC->NbVisiblePoints - outC->CurrentCycle);
  }
  else /* 3 */ if (inC->PauseInput) {
    outC->Offset = outC->CurrentCycle - _L31 + inC->OffsetIn;
  }
  else {
    outC->Offset = inC->OffsetIn;
  }
  /* 6 */ if (outC->CurrentCycle < inC->NbVisiblePoints) {
    outC->VisiblePoints_out = outC->CurrentCycle + 1;
  }
  else {
    outC->VisiblePoints_out = inC->NbVisiblePoints;
  }
  if (tmp & inC->PauseInput) {
    outC->pre_Memory_1_Util_int = outC->CurrentCycle;
  }
  else {
    outC->pre_Memory_1_Util_int = _L31;
  }
  /* 1_ck_CyclicCounter */ if (BHVR_AsynchronousACK) {
    outC->_L10_1 = 1 + outC->CurrentCycle;
  }
  else {
    outC->_L10_1 = outC->CurrentCycle;
  }
  outC->rem_PauseInput = inC->PauseInput;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** GraphTimed.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

