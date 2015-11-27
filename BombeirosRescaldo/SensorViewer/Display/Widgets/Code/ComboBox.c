/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "ComboBox.h"

#ifndef KCG_USER_DEFINED_INIT
void ComboBox_init(outC_ComboBox *outC)
{
  outC->ScrollListVisible = kcg_true;
  outC->SetToggleBack = kcg_true;
  outC->_L151 = kcg_true;
  outC->rem__L152 = kcg_true;
  outC->rem_ScrollListSelected = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ComboBox_reset(outC_ComboBox *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* ComboBox */
void ComboBox(inC_ComboBox *inC, outC_ComboBox *outC)
{
  /* ComboBox */ kcg_bool tmp1;
  /* ComboBox */ kcg_bool tmp;
  /* ComboBox::_L152 */ kcg_bool _L152;
  
  /* 1_fby_1_init_1 */ if (outC->init) {
    _L152 = kcg_false;
    tmp = kcg_false;
    tmp1 = kcg_false;
  }
  else {
    tmp1 = outC->rem_ScrollListSelected;
    tmp = outC->_L151;
    _L152 = outC->ScrollListVisible;
  }
  outC->ScrollListVisible = !((inC->ToggleEmit & !inC->ToggleState &
        !inC->OpenCenter) | inC->AbortKey | !inC->Enable | tmp1) & (tmp |
      _L152);
  outC->_L151 = inC->ToggleEmit & inC->ToggleState;
  _L152 = !outC->ScrollListVisible;
  /* 1_fby_1_init_1 */ if (outC->init) {
    outC->init = kcg_false;
    tmp = !_L152;
  }
  else {
    tmp = !outC->rem__L152;
  }
  outC->SetToggleBack = tmp & _L152;
  outC->rem_ScrollListSelected = inC->ScrollListSelected;
  outC->rem__L152 = _L152;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** ComboBox.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

