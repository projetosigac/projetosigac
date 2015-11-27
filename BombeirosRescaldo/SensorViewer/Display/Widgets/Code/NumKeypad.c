/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "NumKeypad.h"

#ifndef KCG_USER_DEFINED_INIT
void NumKeypad_init(outC_NumKeypad *outC)
{
  kcg_int i;
  
  outC->ValueChangeEmit = kcg_true;
  outC->init = kcg_true;
  for (i = 0; i < 14; i++) {
    outC->init_1[i] = kcg_true;
    outC->rem_RE_Input_1[i] = kcg_true;
  }
  for (i = 0; i < 255; i++) {
    outC->DisplayedString[i] = ' ';
  }
  outC->ValueChange = 0.0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void NumKeypad_reset(outC_NumKeypad *outC)
{
  kcg_int i;
  
  outC->init = kcg_true;
  for (i = 0; i < 14; i++) {
    outC->init_1[i] = kcg_true;
  }
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* NumKeypad */
void NumKeypad(inC_NumKeypad *inC, outC_NumKeypad *outC)
{
  /* NumKeypad */ array_bool_14 tmp3;
  /* NumKeypad */ kcg_bool tmp2;
  kcg_int i;
  /* NumKeypad */ kcg_char tmp1;
  /* NumKeypad */ kcg_bool tmp;
  /* NumKeypad_::InternalKeyCode::_L4 */ kcg_int _L4_1;
  /* NumKeypad_::InternalKeyCode::_L1 */ kcg_bool _L1_1;
  /* NumKeypad::KeyCode */ kcg_int KeyCode;
  /* NumKeypad::_L139 */ array_char_255 _L139;
  /* NumKeypad::_L143 */ array_char_255 _L143;
  /* NumKeypad::_L169 */ kcg_bool _L169;
  
  tmp2 = kcg_false;
  for (i = 0; i < 14; i++) {
    /* fby_1_init_1 */ if (outC->init_1[i]) {
      _L1_1 = !inC->KeyArray[i];
    }
    else {
      _L1_1 = !outC->rem_RE_Input_1[i];
    }
    tmp3[i] = _L1_1 & inC->KeyArray[i];
    outC->rem_RE_Input_1[i] = inC->KeyArray[i];
    outC->init_1[i] = kcg_false;
  }
  /* 1 */ for (i = 0; i < 14; i++) {
    _L1_1 = tmp3[i];
    _L4_1 = i + 1;
    /* 1 */ if (tmp3[i]) {
      break;
    }
  }
  /* 1 */ if (_L1_1) {
    KeyCode = _L4_1 - 1;
  }
  else {
    KeyCode = - 1;
  }
  _L1_1 = KeyCode == 12;
  /* 1_fby_1_init_1 */ if (outC->init) {
    kcg_copy_array_char_254(&_L143[0], (array_char_254 *) &NullString[1]);
    (&_L143[254])[0] = '0';
    outC->init = kcg_false;
    tmp = kcg_false;
  }
  else {
    /* 2 */ if (inC->Reset) {
      kcg_copy_array_char_255(&_L143, (array_char_255 *) &NullString);
    }
    else {
      kcg_copy_array_char_255(&_L143, &outC->DisplayedString);
    }
    tmp = outC->ValueChangeEmit;
  }
  /* 1 */ for (i = 0; i < 255; i++) {
    tmp2 = tmp2 | (_L143[i] == '.');
  }
  _L169 = ((KeyCode >= 0) & (KeyCode <= 9)) | ((KeyCode == 10) & !tmp2);
  /* ck__L169 */ if (_L169) {
    switch (KeyCode) {
      case 0 :
        tmp1 = '0';
        break;
      case 1 :
        tmp1 = '1';
        break;
      case 2 :
        tmp1 = '2';
        break;
      case 3 :
        tmp1 = '3';
        break;
      case 4 :
        tmp1 = '4';
        break;
      case 5 :
        tmp1 = '5';
        break;
      case 6 :
        tmp1 = '6';
        break;
      case 7 :
        tmp1 = '7';
        break;
      case 8 :
        tmp1 = '8';
        break;
      case 9 :
        tmp1 = '9';
        break;
      case 10 :
        tmp1 = '.';
        break;
      
      default :
        tmp1 = ' ';
    }
    /* 1 */ AddCharAtEnd_NumKeypad(&_L143, tmp1, &_L139);
  }
  else {
    kcg_copy_array_char_255(&_L139, &_L143);
  }
  /* ck__L144 */ if (_L1_1) {
    /* 1 */ RemoveCharAtEnd_NumKeypad(&_L139, &_L143);
  }
  else {
    kcg_copy_array_char_255(&_L143, &_L139);
  }
  /* 1 */ if (KeyCode == 13) {
    /* 2 */ if (_L143[0] == '-') {
      kcg_copy_array_char_254(
        &outC->DisplayedString[0],
        (array_char_254 *) &_L143[1]);
      (&outC->DisplayedString[254])[0] = NullString[0];
    }
    else {
      (&outC->DisplayedString[0])[0] = '-';
      kcg_copy_array_char_254(
        &outC->DisplayedString[1],
        (array_char_254 *) &_L143[0]);
    }
  }
  else {
    kcg_copy_array_char_255(&outC->DisplayedString, &_L143);
  }
  outC->ValueChange = /* 1 */ Float_of_string_Strings(&outC->DisplayedString);
  outC->ValueChangeEmit = (KeyCode == 11) | (!BHVR_AsynchronousACK & tmp);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** NumKeypad.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

