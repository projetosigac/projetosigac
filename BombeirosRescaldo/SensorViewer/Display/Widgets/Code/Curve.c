/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "Curve.h"

#ifndef KCG_USER_DEFINED_INIT
void Curve_init(outC_Curve *outC)
{
  kcg_int i;
  
  outC->init = kcg_true;
  for (i = 0; i < 1000; i++) {
    outC->Buffer[i] = 0.0;
  }
  outC->count_1 = 0;
  outC->SpecificValue = 0.0;
  for (i = 0; i < 100; i++) {
    outC->Data[i] = 0.0;
  }
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Curve_reset(outC_Curve *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Curve */
void Curve(inC_Curve *inC, outC_Curve *outC)
{
  /* Curve::Clock::a */ kcg_int a_1;
  /* Curve::_L2 */ array_real_1000 _L2;
  /* Curve::_L12 */ kcg_int _L12;
  kcg_int i;
  
  _L12 = MaxBuffer_Curve - NbData_Curve - inC->Offset;
  /* 1_fby_1_init_1 */ if (outC->init) {
    for (i = 0; i < 1000; i++) {
      _L2[i] = inC->InitValue;
    }
    outC->init = kcg_false;
    a_1 = 0;
  }
  else {
    kcg_copy_array_real_1000(&_L2, &outC->Buffer);
    a_1 = outC->count_1;
  }
  /* 1 */ if (((a_1 + 1 >= inC->SkipCycles + 1) & BHVR_AsynchronousACK) |
    inC->Reset) {
    outC->count_1 = 0;
  }
  else /* 2 */ if (BHVR_AsynchronousACK) {
    outC->count_1 = a_1 + 1;
  }
  else {
    outC->count_1 = a_1;
  }
  /* 2 */ if (((outC->count_1 == 0) & BHVR_AsynchronousACK) | inC->Reset) {
    /* 1 */ if (inC->Reset) {
      for (i = 0; i < 999; i++) {
        (&outC->Buffer[0])[i] = inC->InitValue;
      }
    }
    else {
      kcg_copy_array_real_999(&outC->Buffer[0], (array_real_999 *) &_L2[1]);
    }
    (&outC->Buffer[999])[0] = inC->Value;
  }
  else {
    kcg_copy_array_real_1000(&outC->Buffer, &_L2);
  }
  if ((0 <= MaxBuffer_Curve - 1 - inC->SpecificIndex) & (MaxBuffer_Curve - 1 -
      inC->SpecificIndex < 1000)) {
    outC->SpecificValue = outC->Buffer[MaxBuffer_Curve - 1 -
      inC->SpecificIndex];
  }
  else {
    outC->SpecificValue = outC->Buffer[999];
  }
  /* 1 */ for (i = 0; i < 100; i++) {
    if ((0 <= _L12 + i - 1) & (_L12 + i - 1 < 1000)) {
      outC->Data[i] = outC->Buffer[_L12 + i - 1];
    }
    else {
      outC->Data[i] = outC->Buffer[0];
    }
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Curve.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

