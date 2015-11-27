/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "ScrollBar.h"

#ifndef KCG_USER_DEFINED_INIT
void ScrollBar_init(outC_ScrollBar *outC)
{
  outC->SliderClicked = kcg_true;
  outC->init = kcg_true;
  outC->Value = 0.0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ScrollBar_reset(outC_ScrollBar *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* ScrollBar */
void ScrollBar(inC_ScrollBar *inC, outC_ScrollBar *outC)
{
  /* ScrollBar */ kcg_bool tmp;
  /* ScrollBar::Value */ kcg_real last_Value;
  /* ScrollBar::LocalValue */ kcg_real LocalValue;
  
  /* last_init_ck_Value */ if (outC->init) {
    tmp = kcg_false;
    outC->init = kcg_false;
    last_Value = inC->InitValue;
  }
  else {
    tmp = outC->SliderClicked;
    last_Value = outC->Value;
  }
  outC->SliderClicked = inC->MousePressed | (!inC->MouseReleased & tmp);
  /* ck_SliderClicked */ if (outC->SliderClicked) {
    LocalValue = inC->MaxValue * inC->MouseValue;
  }
  else /* ck_anon_activ */ if (inC->DownClicked) {
    LocalValue = last_Value - inC->TickFine;
  }
  else /* ck_anon_activ */ if (inC->PgUpClicked) {
    LocalValue = last_Value + inC->TickCoarse;
  }
  else /* ck_anon_activ */ if (inC->PgDownClicked) {
    LocalValue = last_Value - inC->TickCoarse;
  }
  else /* ck_anon_activ */ if (inC->ResetValue) {
    LocalValue = inC->InitValue;
  }
  else /* ck_anon_activ */ if (inC->UpClicked) {
    LocalValue = last_Value + inC->TickFine;
  }
  else {
    LocalValue = last_Value;
  }
  /* 2 */ if (LocalValue > inC->MaxValue) {
    outC->Value = inC->MaxValue;
  }
  else /* 1 */ if (LocalValue > 0.0) {
    outC->Value = LocalValue;
  }
  else {
    outC->Value = 0.0;
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** ScrollBar.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

