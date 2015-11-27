/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "NumericEditBox.h"

#ifndef KCG_USER_DEFINED_INIT
void NumericEditBox_init(outC_NumericEditBox *outC)
{
  kcg_int i;
  
  outC->ChangeEmit = kcg_true;
  outC->CursorVisible = kcg_true;
  outC->EditMode = kcg_true;
  outC->EditBoxCursorVisibility_SM_reset_act_1 = kcg_true;
  outC->_L28_NumericEditBox_SM_Edit = kcg_true;
  outC->MouseWheel = kcg_true;
  outC->L_ChangeEmit = kcg_true;
  outC->rem_LeadingZeros = kcg_true;
  outC->rem_MousePressed = kcg_true;
  outC->init3 = kcg_true;
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  outC->rem_DisplaySign = 0;
  outC->rem_NbDigitsIntPart = 0;
  outC->rem_NbDigitsFractionalPart = 0;
  outC->L_ValueChange = 0.0;
  outC->MouseWheelValue = 0.0;
  outC->NumericEditBox_SM_state_nxt = SSM_st_NoEdit_NumericEditBox_SM;
  outC->times_1_1 = 0;
  outC->times_2_1 = 0;
  outC->EditBoxCursorVisibility_SM_state_nxt_1 =
    SSM_st_CursorVisible_EditBoxCursorVisibility_SM;
  outC->CursorPos = 0;
  outC->ValueChange = 0.0;
  for (i = 0; i < 255; i++) {
    outC->SavedString[i] = ' ';
    outC->DisplayedString[i] = ' ';
  }
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void NumericEditBox_reset(outC_NumericEditBox *outC)
{
  outC->init3 = kcg_true;
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* NumericEditBox */
void NumericEditBox(inC_NumericEditBox *inC, outC_NumericEditBox *outC)
{
  /* NumericEditBox */ kcg_bool tmp9;
  /* NumericEditBox */ kcg_int tmp8;
  /* NumericEditBox */ kcg_int tmp7;
  /* NumericEditBox */ kcg_int tmp6;
  /* NumericEditBox */ kcg_real tmp5;
  /* NumericEditBox */ kcg_bool tmp4;
  /* NumericEditBox */ kcg_bool tmp3;
  /* NumericEditBox */ array_char_255 tmp2;
  /* NumericEditBox */ kcg_bool tmp1;
  /* NumericEditBox */ kcg_bool tmp;
  /* Pointer::EditBoxCursorVisibility::EditBoxCursorVisibility_SM */ SSM_ST_EditBoxCursorVisibility_SM EditBoxCursorVisibility_SM_state_act_1;
  /* Pointer::EditBoxCursorVisibility::EditBoxCursorVisibility_SM */ SSM_ST_EditBoxCursorVisibility_SM EditBoxCursorVisibility_SM_state_sel_1;
  kcg_int times_2_1;
  kcg_int times_1_1;
  /* NumericEditBox */ array_char_255 _11_op_call;
  /* NumericEditBox */ kcg_bool op_call;
  /* NumericEditBox */ kcg_int _10_op_call;
  /* NumericEditBox::NumericEditBox_SM::NoEdit::IfBlock1 */ kcg_bool IfBlock1_clock_NumericEditBox_SM_NoEdit;
  /* NumericEditBox::NumericEditBox_SM::NoEdit::IfBlock1::else::else */ kcg_bool _17_else_clock_NumericEditBox_SM_NoEdit_IfBlock1;
  /* NumericEditBox::NumericEditBox_SM::NoEdit::IfBlock1::else::else::else */ kcg_bool else_clock_NumericEditBox_SM_NoEdit_IfBlock1;
  /* NumericEditBox::NumericEditBox_SM::NoEdit::IfBlock1::else */ kcg_bool _18_else_clock_NumericEditBox_SM_NoEdit_IfBlock1;
  /* NumericEditBox::NumericEditBox_SM::Edit::_L32 */ kcg_bool _L32_NumericEditBox_SM_Edit;
  /* NumericEditBox::NumericEditBox_SM::Edit::IfBlock1 */ kcg_bool IfBlock1_clock_NumericEditBox_SM_Edit;
  /* NumericEditBox::NumericEditBox_SM::Edit::IfBlock1::else::else */ kcg_bool _15_else_clock_NumericEditBox_SM_Edit_IfBlock1;
  /* NumericEditBox::NumericEditBox_SM::Edit::IfBlock1::else::else::else::else */ kcg_bool _13_else_clock_NumericEditBox_SM_Edit_IfBlock1;
  /* NumericEditBox::NumericEditBox_SM::Edit::IfBlock1::else::else::else::else::else::else */ kcg_bool else_clock_NumericEditBox_SM_Edit_IfBlock1;
  /* NumericEditBox::NumericEditBox_SM::Edit::IfBlock1::else::else::else::else::else */ kcg_bool _12_else_clock_NumericEditBox_SM_Edit_IfBlock1;
  /* NumericEditBox::NumericEditBox_SM::Edit::IfBlock1::else::else::else */ kcg_bool _14_else_clock_NumericEditBox_SM_Edit_IfBlock1;
  /* NumericEditBox::NumericEditBox_SM::Edit::IfBlock1::else */ kcg_bool _16_else_clock_NumericEditBox_SM_Edit_IfBlock1;
  /* NumericEditBox::CursorPos */ kcg_int last_CursorPos;
  /* NumericEditBox::NumericEditBox_SM */ SSM_ST_NumericEditBox_SM NumericEditBox_SM_state_sel;
  /* NumericEditBox::NumericEditBox_SM */ SSM_ST_NumericEditBox_SM NumericEditBox_SM_state_act;
  /* NumericEditBox::NumericEditBox_SM */ kcg_bool NumericEditBox_SM_reset_act;
  /* NumericEditBox::NumericEditBox_SM */ SSM_TR_NumericEditBox_SM NumericEditBox_SM_fired_strong;
  /* NumericEditBox::_L147 */ array_char_255 _L147;
  /* NumericEditBox::_L163 */ kcg_real _L163;
  /* NumericEditBox::_L170 */ kcg_real _L170;
  /* NumericEditBox::_L179 */ array_char_255 _L179;
  /* NumericEditBox::_L180 */ kcg_bool _L180;
  /* NumericEditBox::_L192 */ kcg_bool _L192;
  /* NumericEditBox::_L204 */ kcg_bool _L204;
  
  /* last_init_ck_MouseWheelValue */ if (outC->init3) {
    _L180 = kcg_false;
    NumericEditBox_SM_state_sel = SSM_st_NoEdit_NumericEditBox_SM;
    NumericEditBox_SM_reset_act = !inC->MousePressed;
    kcg_copy_array_char_255(&_L147, (array_char_255 *) &NullString);
    kcg_copy_array_char_255(&_L179, (array_char_255 *) &NullString);
    last_CursorPos = - 1;
    tmp9 = inC->LeadingZeros;
    tmp8 = inC->DisplaySign;
    tmp7 = inC->NbDigitsIntPart;
    tmp6 = inC->NbDigitsFractionalPart;
    _L192 = kcg_false;
    _L204 = kcg_true;
    _L170 = inC->Value;
    tmp5 = inC->Value;
  }
  else {
    _L180 = outC->L_ChangeEmit;
    NumericEditBox_SM_state_sel = outC->NumericEditBox_SM_state_nxt;
    NumericEditBox_SM_reset_act = !outC->rem_MousePressed;
    kcg_copy_array_char_255(&_L147, &outC->DisplayedString);
    kcg_copy_array_char_255(&_L179, &outC->SavedString);
    last_CursorPos = outC->CursorPos;
    tmp9 = outC->rem_LeadingZeros;
    tmp8 = outC->rem_DisplaySign;
    tmp7 = outC->rem_NbDigitsIntPart;
    tmp6 = outC->rem_NbDigitsFractionalPart;
    _L204 = inC->SetValue;
    _L192 = outC->MouseWheel;
    _L170 = outC->L_ValueChange;
    tmp5 = outC->MouseWheelValue;
  }
  tmp1 = NumericEditBox_SM_reset_act & inC->MousePressed & ((inC->MouseButton ==
        CLICKBUTTON_Pointer) | (inC->MouseButton == TABLET_BUTTON_Pointer)) &
    inC->MouseInside;
  /* sel_NumericEditBox_SM */ switch (NumericEditBox_SM_state_sel) {
    case SSM_st_Edit_NumericEditBox_SM :
      NumericEditBox_SM_reset_act = kcg_false;
      NumericEditBox_SM_state_act = SSM_st_Edit_NumericEditBox_SM;
      NumericEditBox_SM_fired_strong = SSM_TR_no_trans_NumericEditBox_SM;
      break;
    case SSM_st_NoEdit_NumericEditBox_SM :
      NumericEditBox_SM_reset_act = tmp1;
      if (tmp1) {
        NumericEditBox_SM_state_act = SSM_st_Edit_NumericEditBox_SM;
        NumericEditBox_SM_fired_strong = SSM_TR_NoEdit_1_NumericEditBox_SM;
      }
      else {
        NumericEditBox_SM_state_act = SSM_st_NoEdit_NumericEditBox_SM;
        NumericEditBox_SM_fired_strong = SSM_TR_no_trans_NumericEditBox_SM;
      }
      break;
    
  }
  /* act_NumericEditBox_SM */ switch (NumericEditBox_SM_state_act) {
    case SSM_st_Edit_NumericEditBox_SM :
      if (NumericEditBox_SM_reset_act) {
        outC->init2 = kcg_true;
        outC->init = kcg_true;
        outC->init1 = kcg_true;
      }
      _L32_NumericEditBox_SM_Edit = inC->KeyPressed & (inC->KeyCode !=
          KEY_VALID_Pointer);
      outC->EditMode = kcg_true;
      /* ck__L32 */ if (_L32_NumericEditBox_SM_Edit) {
        /* 1 */
        Edit_Strings(
          kcg_true,
          &_L147,
          inC->KeyCode,
          last_CursorPos,
          MAX_STRING_LENGTH,
          &_10_op_call,
          &tmp2,
          &op_call);
      }
      /* fby_1_init_2 */ if (outC->init2) {
        IfBlock1_clock_NumericEditBox_SM_Edit = kcg_true;
        EditBoxCursorVisibility_SM_state_sel_1 =
          SSM_st_CursorVisible_EditBoxCursorVisibility_SM;
        tmp3 = kcg_false;
        tmp1 = kcg_false;
      }
      else {
        IfBlock1_clock_NumericEditBox_SM_Edit = kcg_false;
        EditBoxCursorVisibility_SM_state_sel_1 =
          outC->EditBoxCursorVisibility_SM_state_nxt_1;
        tmp3 = outC->EditBoxCursorVisibility_SM_reset_act_1;
        tmp1 = outC->_L28_NumericEditBox_SM_Edit;
      }
      /* 10 */ if (tmp1) {
        outC->CursorPos = inC->CursorIndex;
      }
      else /* ck__L32 */ if (_L32_NumericEditBox_SM_Edit) {
        outC->CursorPos = _10_op_call;
      }
      else {
        outC->CursorPos = last_CursorPos;
      }
      /* ck_IfBlock1 */ if (IfBlock1_clock_NumericEditBox_SM_Edit) {
        outC->L_ChangeEmit = kcg_false;
        tmp4 = kcg_false;
        outC->MouseWheel = kcg_false;
        kcg_copy_array_char_255(&outC->SavedString, &_L147);
        outC->MouseWheelValue = tmp5;
      }
      else {
        _16_else_clock_NumericEditBox_SM_Edit_IfBlock1 = (inC->KeyPressed &
            (inC->KeyCode == KEY_VALID_Pointer)) | (inC->MousePressed &
            !inC->MouseInside);
        kcg_copy_array_char_255(&outC->SavedString, &_L179);
        /* ck_anon_activ */ if (_16_else_clock_NumericEditBox_SM_Edit_IfBlock1) {
          outC->L_ChangeEmit = kcg_true;
          tmp4 = kcg_false;
          outC->MouseWheel = kcg_false;
          outC->MouseWheelValue = tmp5;
        }
        else {
          outC->L_ChangeEmit = kcg_false;
          _15_else_clock_NumericEditBox_SM_Edit_IfBlock1 = inC->KeyPressed &
            (inC->KeyCode == KEY_ABORT_Pointer);
          /* ck_anon_activ */ if (_15_else_clock_NumericEditBox_SM_Edit_IfBlock1) {
            tmp4 = kcg_true;
            outC->MouseWheel = kcg_false;
            outC->MouseWheelValue = tmp5;
          }
          else {
            tmp4 = kcg_false;
            _14_else_clock_NumericEditBox_SM_Edit_IfBlock1 =
              (inC->MouseButton == UPWHEEL_Pointer) & (inC->KeyModifier ==
                KEY_SHIFT_Pointer);
            /* ck_anon_activ */ if (_14_else_clock_NumericEditBox_SM_Edit_IfBlock1) {
              outC->MouseWheel = kcg_true;
              outC->MouseWheelValue = _L170 + inC->IncrValueFine;
            }
            else {
              _13_else_clock_NumericEditBox_SM_Edit_IfBlock1 =
                (inC->MouseButton == DOWNWHEEL_Pointer) & (inC->KeyModifier ==
                  KEY_SHIFT_Pointer);
              /* ck_anon_activ */ if (_13_else_clock_NumericEditBox_SM_Edit_IfBlock1) {
                outC->MouseWheel = kcg_true;
                outC->MouseWheelValue = _L170 - inC->IncrValueFine;
              }
              else {
                _12_else_clock_NumericEditBox_SM_Edit_IfBlock1 =
                  inC->MouseButton == UPWHEEL_Pointer;
                /* ck_anon_activ */ if (_12_else_clock_NumericEditBox_SM_Edit_IfBlock1) {
                  outC->MouseWheel = kcg_true;
                  outC->MouseWheelValue = _L170 + inC->IncrValueCoarse;
                }
                else {
                  else_clock_NumericEditBox_SM_Edit_IfBlock1 =
                    inC->MouseButton == DOWNWHEEL_Pointer;
                  /* ck_anon_activ */ if (else_clock_NumericEditBox_SM_Edit_IfBlock1) {
                    outC->MouseWheel = kcg_true;
                    outC->MouseWheelValue = _L170 - inC->IncrValueCoarse;
                  }
                  else {
                    outC->MouseWheel = kcg_false;
                    outC->MouseWheelValue = tmp5;
                  }
                }
              }
            }
          }
        }
      }
      tmp = NumericEditBox_SM_fired_strong != SSM_TR_no_trans_NumericEditBox_SM;
      /* strong_fired_Edit */ if (tmp) {
        outC->NumericEditBox_SM_state_nxt = SSM_st_Edit_NumericEditBox_SM;
      }
      else if ((inC->KeyCode == KEY_VALID_Pointer) | (inC->KeyCode ==
          KEY_ABORT_Pointer) | (inC->MousePressed & !inC->MouseInside)) {
        outC->NumericEditBox_SM_state_nxt = SSM_st_NoEdit_NumericEditBox_SM;
      }
      else {
        outC->NumericEditBox_SM_state_nxt = SSM_st_Edit_NumericEditBox_SM;
      }
      outC->_L28_NumericEditBox_SM_Edit = inC->NewCursorIndex;
      /* 1_sel_EditBoxCursorVisibility_SM */ switch (EditBoxCursorVisibility_SM_state_sel_1) {
        case SSM_st_CursorHidden_EditBoxCursorVisibility_SM :
          if (tmp3) {
            outC->init = kcg_true;
          }
          /* 1_2 */ if (outC->init) {
            times_2_1 = BLINKING_PERIOD_Pointer;
          }
          else {
            times_2_1 = outC->times_2_1;
          }
          if (times_2_1 < 0) {
            outC->times_2_1 = times_2_1;
          }
          else {
            outC->times_2_1 = times_2_1 - 1;
          }
          outC->EditBoxCursorVisibility_SM_reset_act_1 = outC->times_2_1 == 0;
          if (outC->EditBoxCursorVisibility_SM_reset_act_1) {
            EditBoxCursorVisibility_SM_state_act_1 =
              SSM_st_CursorVisible_EditBoxCursorVisibility_SM;
          }
          else {
            EditBoxCursorVisibility_SM_state_act_1 =
              SSM_st_CursorHidden_EditBoxCursorVisibility_SM;
          }
          outC->init = kcg_false;
          break;
        case SSM_st_CursorVisible_EditBoxCursorVisibility_SM :
          if (tmp3) {
            outC->init1 = kcg_true;
          }
          /* 1_1 */ if (outC->init1) {
            times_1_1 = BLINKING_PERIOD_Pointer;
          }
          else {
            times_1_1 = outC->times_1_1;
          }
          if (times_1_1 < 0) {
            outC->times_1_1 = times_1_1;
          }
          else {
            outC->times_1_1 = times_1_1 - 1;
          }
          outC->EditBoxCursorVisibility_SM_reset_act_1 = outC->times_1_1 == 0;
          if (outC->EditBoxCursorVisibility_SM_reset_act_1) {
            EditBoxCursorVisibility_SM_state_act_1 =
              SSM_st_CursorHidden_EditBoxCursorVisibility_SM;
          }
          else {
            EditBoxCursorVisibility_SM_state_act_1 =
              SSM_st_CursorVisible_EditBoxCursorVisibility_SM;
          }
          outC->init1 = kcg_false;
          break;
        
      }
      /* 1_act_EditBoxCursorVisibility_SM */ switch (EditBoxCursorVisibility_SM_state_act_1) {
        case SSM_st_CursorHidden_EditBoxCursorVisibility_SM :
          outC->CursorVisible = kcg_false;
          outC->EditBoxCursorVisibility_SM_state_nxt_1 =
            SSM_st_CursorHidden_EditBoxCursorVisibility_SM;
          break;
        case SSM_st_CursorVisible_EditBoxCursorVisibility_SM :
          outC->CursorVisible = kcg_true;
          outC->EditBoxCursorVisibility_SM_state_nxt_1 =
            SSM_st_CursorVisible_EditBoxCursorVisibility_SM;
          break;
        
      }
      outC->init2 = kcg_false;
      break;
    case SSM_st_NoEdit_NumericEditBox_SM :
      IfBlock1_clock_NumericEditBox_SM_NoEdit = inC->MouseInside &
        (inC->MouseButton == UPWHEEL_Pointer) & (inC->KeyModifier ==
          KEY_SHIFT_Pointer);
      /* ck_IfBlock1 */ if (IfBlock1_clock_NumericEditBox_SM_NoEdit) {
        outC->MouseWheel = kcg_true;
        outC->MouseWheelValue = _L170 + inC->IncrValueFine;
      }
      else {
        _18_else_clock_NumericEditBox_SM_NoEdit_IfBlock1 = inC->MouseInside &
          (inC->MouseButton == DOWNWHEEL_Pointer) & (inC->KeyModifier ==
            KEY_SHIFT_Pointer);
        /* ck_anon_activ */ if (_18_else_clock_NumericEditBox_SM_NoEdit_IfBlock1) {
          outC->MouseWheel = kcg_true;
          outC->MouseWheelValue = _L170 - inC->IncrValueFine;
        }
        else {
          _17_else_clock_NumericEditBox_SM_NoEdit_IfBlock1 = inC->MouseInside &
            (inC->MouseButton == UPWHEEL_Pointer);
          /* ck_anon_activ */ if (_17_else_clock_NumericEditBox_SM_NoEdit_IfBlock1) {
            outC->MouseWheel = kcg_true;
            outC->MouseWheelValue = _L170 + inC->IncrValueCoarse;
          }
          else {
            else_clock_NumericEditBox_SM_NoEdit_IfBlock1 = inC->MouseInside &
              (inC->MouseButton == DOWNWHEEL_Pointer);
            /* ck_anon_activ */ if (else_clock_NumericEditBox_SM_NoEdit_IfBlock1) {
              outC->MouseWheel = kcg_true;
              outC->MouseWheelValue = _L170 - inC->IncrValueCoarse;
            }
            else {
              outC->MouseWheel = kcg_false;
              outC->MouseWheelValue = tmp5;
            }
          }
        }
      }
      outC->L_ChangeEmit = inC->MouseInside & outC->MouseWheel;
      outC->EditMode = kcg_false;
      tmp4 = kcg_false;
      outC->CursorVisible = kcg_false;
      outC->CursorPos = - 1;
      kcg_copy_array_char_255(&outC->SavedString, &_L179);
      outC->NumericEditBox_SM_state_nxt = SSM_st_NoEdit_NumericEditBox_SM;
      break;
    
  }
  NumericEditBox_SM_reset_act = !outC->EditMode & ((tmp9 != inC->LeadingZeros) |
      (tmp8 != inC->DisplaySign) | (tmp7 != inC->NbDigitsIntPart) | (tmp6 !=
        inC->NbDigitsFractionalPart));
  tmp1 = NumericEditBox_SM_reset_act | _L204 | _L180 | _L192;
  /* ck__L171 */ if (tmp1) {
    /* 7 */ if (NumericEditBox_SM_reset_act | _L180 | _L192) {
      tmp5 = _L170;
    }
    else /* 2 */ if (inC->Value > inC->MaxValue) {
      tmp5 = inC->MaxValue;
    }
    else /* 1 */ if (inC->Value > inC->MinValue) {
      tmp5 = inC->Value;
    }
    else {
      tmp5 = inC->MinValue;
    }
    /* 1 */
    FormatNumValue_Strings(
      tmp5,
      inC->LeadingZeros,
      inC->DisplaySign,
      inC->NbDigitsIntPart,
      inC->NbDigitsFractionalPart,
      &_11_op_call);
  }
  /* 3 */ if (tmp4) {
    kcg_copy_array_char_255(&outC->DisplayedString, &_L179);
  }
  else {
    /* act_NumericEditBox_SM */ switch (NumericEditBox_SM_state_act) {
      case SSM_st_NoEdit_NumericEditBox_SM :
        tmp3 = kcg_false;
        break;
      case SSM_st_Edit_NumericEditBox_SM :
        /* ck__L32 */ if (_L32_NumericEditBox_SM_Edit) {
          tmp3 = op_call;
        }
        else {
          tmp3 = kcg_false;
        }
        break;
      
    }
    /* 8 */ if (tmp3) {
      /* act_NumericEditBox_SM */ switch (NumericEditBox_SM_state_act) {
        case SSM_st_NoEdit_NumericEditBox_SM :
          kcg_copy_array_char_255(
            &outC->DisplayedString,
            (array_char_255 *) &NullString);
          break;
        case SSM_st_Edit_NumericEditBox_SM :
          /* ck__L32 */ if (_L32_NumericEditBox_SM_Edit) {
            kcg_copy_array_char_255(&outC->DisplayedString, &tmp2);
          }
          else {
            kcg_copy_array_char_255(
              &outC->DisplayedString,
              (array_char_255 *) &NullString);
          }
          break;
        
      }
    }
    else /* 2 */ if (tmp1) {
      kcg_copy_array_char_255(&outC->DisplayedString, &_11_op_call);
    }
    else {
      kcg_copy_array_char_255(&outC->DisplayedString, &_L147);
    }
  }
  /* ck_L_ChangeEmit */ if (outC->L_ChangeEmit) {
    /* act_NumericEditBox_SM */ switch (NumericEditBox_SM_state_act) {
      case SSM_st_NoEdit_NumericEditBox_SM :
        kcg_copy_array_char_255(&tmp2, (array_char_255 *) &NullString);
        break;
      case SSM_st_Edit_NumericEditBox_SM :
        /* ck_IfBlock1 */ if (IfBlock1_clock_NumericEditBox_SM_Edit) {
          kcg_copy_array_char_255(&tmp2, (array_char_255 *) &NullString);
        }
        else /* ck_anon_activ */ if (_16_else_clock_NumericEditBox_SM_Edit_IfBlock1) {
          kcg_copy_array_char_255(&tmp2, &outC->DisplayedString);
        }
        else {
          kcg_copy_array_char_255(&tmp2, (array_char_255 *) &NullString);
        }
        break;
      
    }
    tmp5 = /* 2 */ Float_of_string_Strings(&tmp2);
  }
  /* 5 */ if (_L204) {
    _L163 = inC->Value;
  }
  else /* 9 */ if (outC->MouseWheel) {
    _L163 = outC->MouseWheelValue;
  }
  else /* ck_L_ChangeEmit */ if (outC->L_ChangeEmit) {
    _L163 = tmp5;
  }
  else {
    _L163 = _L170;
  }
  /* 12 */ if (inC->MinValue > inC->MaxValue) {
    outC->L_ValueChange = _L170;
  }
  else /* 2 */ if (_L163 > inC->MaxValue) {
    outC->L_ValueChange = inC->MaxValue;
  }
  else /* 1 */ if (_L163 > inC->MinValue) {
    outC->L_ValueChange = _L163;
  }
  else {
    outC->L_ValueChange = inC->MinValue;
  }
  /* 11 */ if (_L204 | outC->L_ChangeEmit) {
    outC->ValueChange = outC->L_ValueChange;
  }
  else /* last_init_ck_ValueChange */ if (outC->init3) {
    outC->ValueChange = inC->Value;
  }
  /* 1_fby_1_init_1 */ if (outC->init3) {
    outC->init3 = kcg_false;
    tmp = kcg_false;
  }
  else {
    tmp = outC->ChangeEmit;
  }
  outC->ChangeEmit = outC->L_ChangeEmit | (!BHVR_AsynchronousACK & tmp);
  outC->rem_MousePressed = inC->MousePressed;
  outC->rem_LeadingZeros = inC->LeadingZeros;
  outC->rem_DisplaySign = inC->DisplaySign;
  outC->rem_NbDigitsIntPart = inC->NbDigitsIntPart;
  outC->rem_NbDigitsFractionalPart = inC->NbDigitsFractionalPart;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** NumericEditBox.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

