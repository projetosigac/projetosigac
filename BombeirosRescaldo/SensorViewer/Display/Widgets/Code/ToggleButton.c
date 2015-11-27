/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "ToggleButton.h"

#ifndef KCG_USER_DEFINED_INIT
void ToggleButton_init(outC_ToggleButton *outC)
{
  outC->StateChangeEmit = kcg_true;
  outC->StateChangeValue = kcg_true;
  outC->_L4_1_IfBlock1 = kcg_true;
  outC->IsSet_1_1 = kcg_true;
  outC->rem_MousePressed = kcg_true;
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ToggleButton_reset(outC_ToggleButton *outC)
{
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* ToggleButton */
void ToggleButton(inC_ToggleButton *inC, outC_ToggleButton *outC)
{
  /* ToggleButton */ kcg_bool tmp2;
  /* ToggleButton */ kcg_bool tmp1;
  /* ToggleButton */ kcg_bool tmp;
  /* Pointer::MouseClicked::IfBlock1 */ kcg_bool IfBlock1_clock_1;
  /* Util::RisingEdge::RE_Output */ kcg_bool RE_Output_1_1;
  /* ToggleButton::MouseClicked */ kcg_bool MouseClicked;
  
  IfBlock1_clock_1 = inC->EmitCondition == ON_RELEASED_Pointer;
  /* 1_fby_1_init_1 */ if (outC->init2) {
    tmp1 = !inC->MousePressed;
    outC->init2 = kcg_false;
    tmp = kcg_false;
  }
  else {
    tmp1 = !outC->rem_MousePressed;
    tmp = outC->StateChangeEmit;
  }
  RE_Output_1_1 = tmp1 & inC->MousePressed;
  /* 1_ck_IfBlock1 */ if (IfBlock1_clock_1) {
    /* 1_1_fby_1_init_1 */ if (outC->init) {
      tmp1 = kcg_false;
      tmp2 = kcg_true;
    }
    else {
      tmp2 = !outC->_L4_1_IfBlock1;
      tmp1 = outC->IsSet_1_1;
    }
    outC->IsSet_1_1 = (RE_Output_1_1 & ((inC->MouseButton ==
            CLICKBUTTON_Pointer) | (inC->MouseButton ==
            TABLET_BUTTON_Pointer)) & inC->MouseInside) | (tmp2 & tmp1);
    outC->_L4_1_IfBlock1 = inC->MouseReleased;
    MouseClicked = outC->IsSet_1_1 & inC->MouseInside & outC->_L4_1_IfBlock1;
    outC->init = kcg_false;
  }
  else {
    MouseClicked = RE_Output_1_1 & ((inC->MouseButton == CLICKBUTTON_Pointer) |
        (inC->MouseButton == TABLET_BUTTON_Pointer)) & inC->MouseInside;
  }
  outC->StateChangeEmit = MouseClicked | (!BHVR_AsynchronousACK & tmp);
  if (inC->SetToggleState) {
    outC->init1 = kcg_true;
  }
  /* 1 */ if (outC->init1) {
    outC->init1 = kcg_false;
    tmp1 = inC->ToggleState;
  }
  else {
    tmp1 = outC->StateChangeValue;
  }
  outC->StateChangeValue = MouseClicked ^ tmp1;
  outC->rem_MousePressed = inC->MousePressed;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** ToggleButton.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

