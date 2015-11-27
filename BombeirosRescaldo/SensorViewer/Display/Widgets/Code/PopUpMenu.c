/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "PopUpMenu.h"

#ifndef KCG_USER_DEFINED_INIT
void PopUpMenu_init(outC_PopUpMenu *outC)
{
  outC->Visible = kcg_true;
  outC->SelectedItemEmit = kcg_true;
  outC->init = kcg_true;
  outC->SelectedItemValue = 0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void PopUpMenu_reset(outC_PopUpMenu *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* PopUpMenu */
void PopUpMenu(inC_PopUpMenu *inC, outC_PopUpMenu *outC)
{
  kcg_int i;
  /* PopUpMenu */ kcg_bool tmp;
  /* PopUpMenu::ClosingCondition::else */ kcg_bool else_clock_ClosingCondition;
  /* PopUpMenu::ClosingCondition */ kcg_bool ClosingCondition_clock;
  /* PopUpMenu::_L40 */ kcg_int _L40;
  /* PopUpMenu::_L46 */ kcg_bool _L46;
  
  /* last_init_ck_Visible */ if (outC->init) {
    _L46 = kcg_false;
  }
  else {
    _L46 = outC->Visible;
  }
  /* 1 */ for (i = 0; i < 16; i++) {
    ClosingCondition_clock = inC->MouseInsideItem[i];
    _L40 = i + 1;
    /* 1 */ if (inC->MouseInsideItem[i]) {
      break;
    }
  }
  else_clock_ClosingCondition = _L46 & inC->MouseEvent & ClosingCondition_clock;
  ClosingCondition_clock = inC->ClosingCondition == CLOSING_COND_ON_SELECTION;
  /* 1 */ if (else_clock_ClosingCondition) {
    outC->SelectedItemValue = _L40;
  }
  else /* last_init_ck_SelectedItemValue */ if (outC->init) {
    outC->SelectedItemValue = - 1;
  }
  /* 4_fby_1_init_1 */ if (outC->init) {
    outC->init = kcg_false;
    tmp = kcg_false;
  }
  else {
    tmp = outC->SelectedItemEmit;
  }
  outC->SelectedItemEmit = else_clock_ClosingCondition |
    (!BHVR_AsynchronousACK & tmp);
  /* ck_ClosingCondition */ if (ClosingCondition_clock) {
    tmp = !(outC->SelectedItemEmit | (!inC->PopUpVisible &
          inC->SetPopUpVisible));
  }
  else {
    else_clock_ClosingCondition = inC->ClosingCondition ==
      CLOSING_COND_ON_USER_REQUEST;
    /* ck_anon_activ */ if (else_clock_ClosingCondition) {
      tmp = !(!inC->PopUpVisible & inC->SetPopUpVisible);
    }
    else {
      tmp = !(outC->SelectedItemEmit | (!inC->PopUpVisible &
            inC->SetPopUpVisible) | (!inC->MouseInside & inC->MouseEvent &
            _L46) | (inC->KeyPressed & (inC->KeyCode == KEY_ABORT_Pointer)));
    }
  }
  outC->Visible = (inC->PopUpVisible & inC->SetPopUpVisible) | (tmp & _L46);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** PopUpMenu.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

