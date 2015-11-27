/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:14
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "AlphaNumKeypad.h"

#ifndef KCG_USER_DEFINED_INIT
void AlphaNumKeypad_init(outC_AlphaNumKeypad *outC)
{
  kcg_int i;
  
  outC->ValueChangeEmit = kcg_true;
  outC->TimeOut = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  outC->_L182 = ' ';
  outC->_L10_1 = 0;
  outC->pre_Memory_1_Util_int = 0;
  for (i = 0; i < 13; i++) {
    outC->init_1[i] = kcg_true;
    outC->rem_RE_Input_1[i] = kcg_true;
  }
  for (i = 0; i < 255; i++) {
    outC->ValueChange[i] = ' ';
  }
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void AlphaNumKeypad_reset(outC_AlphaNumKeypad *outC)
{
  kcg_int i;
  
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  for (i = 0; i < 13; i++) {
    outC->init_1[i] = kcg_true;
  }
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* AlphaNumKeypad */
void AlphaNumKeypad(inC_AlphaNumKeypad *inC, outC_AlphaNumKeypad *outC)
{
  /* AlphaNumKeypad */ array_bool_13 tmp2;
  /* AlphaNumKeypad */ kcg_char tmp1;
  /* AlphaNumKeypad */ kcg_real tmp;
  /* AlphaNumKeypad_::InternalKeyCode::_L7 */ kcg_int _L7_1;
  /* AlphaNumKeypad_::InternalKeyCode::_L1 */ kcg_bool _L1_1;
  /* AlphaNumKeypad::TimeOut */ kcg_bool last_TimeOut;
  /* AlphaNumKeypad::KeyCode */ kcg_int KeyCode;
  /* AlphaNumKeypad::last_non_zero_keycode */ kcg_int last_non_zero_keycode;
  /* AlphaNumKeypad::_L137 */ kcg_bool _L137;
  /* AlphaNumKeypad::_L143 */ array_char_255 _L143;
  /* AlphaNumKeypad::_L163 */ kcg_bool _L163;
  /* AlphaNumKeypad::_L168 */ kcg_char _L168;
  /* AlphaNumKeypad::_L183 */ kcg_char _L183;
  /* AlphaNumKeypad::_L185 */ array_char_255 _L185;
  
  for (_L7_1 = 0; _L7_1 < 13; _L7_1++) {
    /* fby_1_init_1 */ if (outC->init_1[_L7_1]) {
      _L1_1 = !inC->KeyArray[_L7_1];
    }
    else {
      _L1_1 = !outC->rem_RE_Input_1[_L7_1];
    }
    tmp2[_L7_1] = _L1_1 & inC->KeyArray[_L7_1];
    outC->rem_RE_Input_1[_L7_1] = inC->KeyArray[_L7_1];
    outC->init_1[_L7_1] = kcg_false;
  }
  /* 1 */ for (_L7_1 = 0; _L7_1 < 13; _L7_1++) {
    _L1_1 = tmp2[_L7_1];
    last_non_zero_keycode = _L7_1 + 1;
    /* 1 */ if (tmp2[_L7_1]) {
      break;
    }
  }
  _L7_1 = - 1;
  /* 1 */ if (_L1_1) {
    KeyCode = last_non_zero_keycode - 1;
  }
  else {
    KeyCode = _L7_1;
  }
  _L1_1 = KeyCode >= 0;
  _L137 = (_L1_1 & (KeyCode <= 9)) | (KeyCode == 10);
  /* 4 */ if (outC->init1) {
    last_TimeOut = kcg_false;
    kcg_copy_array_char_255(&_L185, &inC->LabelString);
    last_non_zero_keycode = KeyCode;
    _L183 = ' ';
    outC->init1 = kcg_false;
    tmp = 0.0;
  }
  else {
    /* 4 */ if (inC->SetLabelString) {
      kcg_copy_array_char_255(&_L185, &inC->LabelString);
    }
    else /* 2 */ if (inC->Reset) {
      kcg_copy_array_char_255(&_L185, (array_char_255 *) &NullString);
    }
    else {
      kcg_copy_array_char_255(&_L185, &outC->ValueChange);
    }
    last_non_zero_keycode = outC->pre_Memory_1_Util_int;
    last_TimeOut = outC->TimeOut;
    _L183 = outC->_L182;
    tmp = 1000.0;
  }
  _L163 = (KeyCode == 12) | ((KeyCode == last_non_zero_keycode) & (KeyCode >
        _L7_1) & (KeyCode != 11) & !last_TimeOut);
  /* ck__L144 */ if (_L163) {
    /* 2 */ RemoveCharAtEnd_NumKeypad(&_L185, &_L143);
  }
  else {
    kcg_copy_array_char_255(&_L143, &_L185);
  }
  /* 1 */ if ((KeyCode == last_non_zero_keycode) & (KeyCode > _L7_1) &
    !last_TimeOut) {
    tmp1 = _L183;
  }
  else {
    tmp1 = '.';
  }
  /* 1 */ switch (KeyCode) {
    case 0 :
      _L168 = '0';
      break;
    case 1 :
      _L168 = '1';
      break;
    case 2 :
      switch (tmp1) {
        case '2' :
          _L168 = 'a';
          break;
        case 'a' :
          _L168 = 'b';
          break;
        case 'b' :
          _L168 = 'c';
          break;
        case 'c' :
          _L168 = '2';
          break;
        
        default :
          _L168 = 'a';
      }
      break;
    case 3 :
      switch (tmp1) {
        case '3' :
          _L168 = 'd';
          break;
        case 'd' :
          _L168 = 'e';
          break;
        case 'e' :
          _L168 = 'f';
          break;
        case 'f' :
          _L168 = '3';
          break;
        
        default :
          _L168 = 'd';
      }
      break;
    case 4 :
      switch (tmp1) {
        case '4' :
          _L168 = 'g';
          break;
        case 'g' :
          _L168 = 'h';
          break;
        case 'h' :
          _L168 = 'i';
          break;
        case 'i' :
          _L168 = '4';
          break;
        
        default :
          _L168 = 'g';
      }
      break;
    case 5 :
      switch (tmp1) {
        case '5' :
          _L168 = 'j';
          break;
        case 'j' :
          _L168 = 'k';
          break;
        case 'k' :
          _L168 = 'l';
          break;
        case 'l' :
          _L168 = '5';
          break;
        
        default :
          _L168 = 'j';
      }
      break;
    case 6 :
      switch (tmp1) {
        case '6' :
          _L168 = 'm';
          break;
        case 'm' :
          _L168 = 'n';
          break;
        case 'n' :
          _L168 = 'o';
          break;
        case 'o' :
          _L168 = '6';
          break;
        
        default :
          _L168 = 'm';
      }
      break;
    case 7 :
      switch (tmp1) {
        case '7' :
          _L168 = 'p';
          break;
        case 'p' :
          _L168 = 'q';
          break;
        case 'q' :
          _L168 = 'r';
          break;
        case 'r' :
          _L168 = 's';
          break;
        case 's' :
          _L168 = '7';
          break;
        
        default :
          _L168 = 'p';
      }
      break;
    case 8 :
      switch (tmp1) {
        case '8' :
          _L168 = 't';
          break;
        case 't' :
          _L168 = 'u';
          break;
        case 'u' :
          _L168 = 'v';
          break;
        case 'v' :
          _L168 = '8';
          break;
        
        default :
          _L168 = 't';
      }
      break;
    case 9 :
      switch (tmp1) {
        case '9' :
          _L168 = 'w';
          break;
        case 'w' :
          _L168 = 'x';
          break;
        case 'x' :
          _L168 = 'y';
          break;
        case 'y' :
          _L168 = 'z';
          break;
        case 'z' :
          _L168 = '9';
          break;
        
        default :
          _L168 = 'w';
      }
      break;
    case 10 :
      _L168 = ' ';
      break;
    
    default :
      _L168 = ' ';
  }
  outC->ValueChangeEmit = KeyCode == 11;
  _L163 = (KeyCode >= 2) & (KeyCode <= 9);
  /* 3 */ if (_L137) {
    tmp1 = /* 1 */ SetCharacterCase(_L168, inC->CapsLock);
    /* 2 */ AddCharAtEnd_NumKeypad(&_L143, tmp1, &outC->ValueChange);
    outC->_L182 = _L168;
  }
  else {
    kcg_copy_array_char_255(&outC->ValueChange, &_L143);
    outC->_L182 = _L183;
  }
  if (_L163) {
    outC->init = kcg_true;
  }
  /* 1_fby_1_init_2 */ if (outC->init) {
    outC->_L10_1 = 1 + 0;
  }
  else {
    outC->_L10_1 = 1 + outC->_L10_1;
  }
  /* 1 */ if (tmp / inC->CyclePeriod < (kcg_real) outC->_L10_1) {
    outC->TimeOut = kcg_true;
  }
  else /* 1_fby_1_init_1 */ if (outC->init) {
    outC->TimeOut = kcg_false;
  }
  outC->init = kcg_false;
  if (_L1_1) {
    outC->pre_Memory_1_Util_int = KeyCode;
  }
  else {
    outC->pre_Memory_1_Util_int = last_non_zero_keycode;
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** AlphaNumKeypad.c
** Generation date: 2014-11-28T14:01:14
*************************************************************$ */

