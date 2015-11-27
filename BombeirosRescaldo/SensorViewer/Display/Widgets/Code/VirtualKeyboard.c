/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "VirtualKeyboard.h"

#ifndef KCG_USER_DEFINED_INIT
void VirtualKeyboard_init(outC_VirtualKeyboard *outC)
{
  kcg_int i1;
  kcg_int i;
  
  outC->KeyPressed = kcg_true;
  outC->rem__L232_SM1_running = kcg_true;
  outC->rem__L228_SM1_running = kcg_true;
  outC->rem__L227_SM1_running = kcg_true;
  outC->rem__L225_SM1_running = kcg_true;
  outC->rem__L193_SM1_running = kcg_true;
  outC->rem__L190_SM1_running = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  outC->SM1_state_nxt = SSM_st_running_SM1;
  for (i1 = 0; i1 < 30; i1++) {
    for (i = 0; i < 255; i++) {
      outC->_L191_SM1_running[i1][i] = ' ';
      outC->KeyLabels[i1][i] = ' ';
    }
  }
  outC->KeyChar = ' ';
  outC->KeyCode = 0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void VirtualKeyboard_reset(outC_VirtualKeyboard *outC)
{
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* VirtualKeyboard */
void VirtualKeyboard(inC_VirtualKeyboard *inC, outC_VirtualKeyboard *outC)
{
  /* VirtualKeyboard */ kcg_bool tmp8;
  /* VirtualKeyboard */ kcg_bool tmp7;
  /* VirtualKeyboard */ kcg_bool tmp6;
  /* VirtualKeyboard */ kcg_bool tmp5;
  /* VirtualKeyboard */ kcg_bool tmp4;
  /* VirtualKeyboard */ array_char_255_33 tmp3;
  /* VirtualKeyboard */ array_char_255 tmp2;
  /* VirtualKeyboard */ array_char_255 tmp1;
  /* VirtualKeyboard */ array_char_255 tmp;
  /* VirtualKeyboard_::InternalKeyCode::_L4 */ kcg_int _L4_2;
  /* VirtualKeyboard_::InternalKeyCode::_L1 */ kcg_bool _L1_2;
  /* VirtualKeyboard::SM1::running::_L232 */ kcg_bool _L232_SM1_running;
  /* VirtualKeyboard::SM1::running::_L228 */ kcg_bool _L228_SM1_running;
  /* VirtualKeyboard::SM1::running::_L224 */ kcg_bool _L224_SM1_running;
  /* VirtualKeyboard::SM1::running::_L205 */ kcg_int _L205_SM1_running;
  /* VirtualKeyboard::SM1::running::_L199 */ array_char_255 _L199_SM1_running;
  /* VirtualKeyboard::SM1::running::_L195 */ kcg_bool _L195_SM1_running;
  /* VirtualKeyboard::SM1::running::_L190 */ kcg_bool _L190_SM1_running;
  /* VirtualKeyboard::SM1::running::internalKeyCode */ kcg_int internalKeyCode_SM1_running;
  /* VirtualKeyboard::SM1::running */ kcg_bool running_weakb_clock_SM1;
  /* VirtualKeyboard::SM1 */ _4_SSM_ST_SM1 SM1_state_sel;
  /* VirtualKeyboard::SM1 */ _4_SSM_ST_SM1 SM1_state_act;
  /* VirtualKeyboard::SM1 */ kcg_bool SM1_reset_act;
  /* VirtualKeyboard::SM1 */ _6_SSM_TR_SM1 SM1_fired_strong;
  kcg_int i;
  
  /* init_SM1 */ if (outC->init1) {
    SM1_state_sel = SSM_st_wait_ACK_SM1;
  }
  else {
    SM1_state_sel = outC->SM1_state_nxt;
  }
  /* sel_SM1 */ switch (SM1_state_sel) {
    case SSM_st_wait_ACK_SM1 :
      SM1_reset_act = BHVR_AsynchronousACK;
      if (BHVR_AsynchronousACK) {
        SM1_state_act = SSM_st_running_SM1;
        SM1_fired_strong = SSM_TR_wait_ACK_1_SM1;
      }
      else {
        SM1_state_act = SSM_st_wait_ACK_SM1;
        SM1_fired_strong = _5_SSM_TR_no_trans_SM1;
      }
      break;
    case SSM_st_running_SM1 :
      SM1_state_act = SSM_st_running_SM1;
      SM1_reset_act = kcg_false;
      SM1_fired_strong = _5_SSM_TR_no_trans_SM1;
      break;
    
  }
  /* act_SM1 */ switch (SM1_state_act) {
    case SSM_st_wait_ACK_SM1 :
      /* last_init_ck_KeyLabels */ if (outC->init1) {
        outC->KeyPressed = kcg_false;
        outC->KeyCode = - 1;
        outC->KeyChar = NUL_char_Strings;
        for (i = 0; i < 30; i++) {
          kcg_copy_array_char_255(
            &outC->KeyLabels[i],
            (array_char_255 *) &NullString);
        }
      }
      outC->SM1_state_nxt = SSM_st_wait_ACK_SM1;
      break;
    case SSM_st_running_SM1 :
      /* 2 */ for (i = 0; i < 30; i++) {
        _L1_2 = inC->KeyArray[i];
        _L4_2 = i + 1;
        /* 2 */ if (inC->KeyArray[i]) {
          break;
        }
      }
      _L205_SM1_running = - 1;
      /* 5 */ if (inC->EnterClicked) {
        internalKeyCode_SM1_running = 30;
      }
      else /* 6 */ if (inC->SpaceClicked) {
        internalKeyCode_SM1_running = 31;
      }
      else /* 7 */ if (inC->BackspaceClicked) {
        internalKeyCode_SM1_running = 32;
      }
      else /* 1 */ if (_L1_2) {
        internalKeyCode_SM1_running = _L4_2 - 1;
      }
      else {
        internalKeyCode_SM1_running = _L205_SM1_running;
      }
      _L190_SM1_running = internalKeyCode_SM1_running > _L205_SM1_running;
      if (SM1_reset_act) {
        outC->init = kcg_true;
      }
      /* 2_fby_1_init_1 */ if (outC->init) {
        tmp8 = inC->NumLock;
      }
      else {
        tmp8 = outC->rem__L193_SM1_running;
      }
      _L195_SM1_running = tmp8 != inC->NumLock;
      _L232_SM1_running = !inC->CapsLock;
      /* 1_fby_1_init_1 */ if (outC->init) {
        tmp4 = kcg_false;
        tmp7 = kcg_false;
        tmp6 = !_L232_SM1_running;
        tmp5 = !inC->Shift;
      }
      else {
        tmp7 = outC->rem__L190_SM1_running;
        tmp6 = !outC->rem__L232_SM1_running;
        tmp5 = !outC->rem__L225_SM1_running;
        tmp4 = outC->rem__L227_SM1_running;
      }
      outC->rem__L227_SM1_running = !(tmp7 | _L195_SM1_running | (tmp6 &
            _L232_SM1_running)) & ((tmp5 & inC->Shift) | tmp4);
      _L228_SM1_running = inC->CapsLock | outC->rem__L227_SM1_running;
      /* 1 */ if (outC->init) {
        _L224_SM1_running = kcg_true;
      }
      else {
        _L224_SM1_running = (outC->rem__L228_SM1_running != _L228_SM1_running) |
          _L195_SM1_running;
      }
      /* ck__L224 */ if (_L224_SM1_running) {
        /* 2 */
        KeyLabels_VirtualKeyboard_(
          _L228_SM1_running,
          inC->NumLock,
          &outC->_L191_SM1_running);
      }
      else if (outC->init) {
        for (i = 0; i < 30; i++) {
          kcg_copy_array_char_255(
            &outC->_L191_SM1_running[i],
            (array_char_255 *) &NullString);
        }
      }
      outC->init = kcg_false;
      kcg_copy_array_char_255(&tmp2, (array_char_255 *) &NullString);
      tmp2[0] = CR_char_Strings;
      kcg_copy_array_char_255(&tmp1, (array_char_255 *) &NullString);
      tmp1[0] = ' ';
      kcg_copy_array_char_255(&tmp, (array_char_255 *) &NullString);
      tmp[0] = BackSpace_char_Strings;
      kcg_copy_array_char_255_30(&tmp3[0], &outC->_L191_SM1_running);
      kcg_copy_array_char_255(&(&tmp3[30])[0], &tmp2);
      kcg_copy_array_char_255(&(&tmp3[30])[1], &tmp1);
      kcg_copy_array_char_255(&(&tmp3[30])[2], &tmp);
      if ((0 <= internalKeyCode_SM1_running) & (internalKeyCode_SM1_running <
          33)) {
        kcg_copy_array_char_255(
          &_L199_SM1_running,
          &tmp3[internalKeyCode_SM1_running]);
      }
      else {
        kcg_copy_array_char_255(
          &_L199_SM1_running,
          (array_char_255 *) &NullString);
      }
      outC->KeyPressed = _L190_SM1_running;
      /* 1 */ if (_L190_SM1_running) {
        outC->KeyCode = /* 1 */
          char_to_KeyCode_VirtualKeyboard_(_L199_SM1_running[0]);
        outC->KeyChar = _L199_SM1_running[0];
      }
      else {
        outC->KeyCode = _L205_SM1_running;
        outC->KeyChar = NUL_char_Strings;
      }
      kcg_copy_array_char_255_30(&outC->KeyLabels, &outC->_L191_SM1_running);
      running_weakb_clock_SM1 = SM1_fired_strong != _5_SSM_TR_no_trans_SM1;
      /* strong_fired_running */ if (running_weakb_clock_SM1) {
        outC->SM1_state_nxt = SSM_st_running_SM1;
      }
      else if (_L190_SM1_running & !BHVR_AsynchronousACK) {
        outC->SM1_state_nxt = SSM_st_wait_ACK_SM1;
      }
      else {
        outC->SM1_state_nxt = SSM_st_running_SM1;
      }
      outC->rem__L190_SM1_running = _L190_SM1_running;
      outC->rem__L193_SM1_running = inC->NumLock;
      outC->rem__L225_SM1_running = inC->Shift;
      outC->rem__L228_SM1_running = _L228_SM1_running;
      outC->rem__L232_SM1_running = _L232_SM1_running;
      break;
    
  }
  outC->init1 = kcg_false;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** VirtualKeyboard.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

