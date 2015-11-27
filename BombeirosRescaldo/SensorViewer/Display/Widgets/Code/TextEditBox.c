/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "TextEditBox.h"

#ifndef KCG_USER_DEFINED_INIT
void TextEditBox_init(outC_TextEditBox *outC)
{
  kcg_int i;
  
  outC->StringChangeEmit = kcg_true;
  outC->CursorVisible = kcg_true;
  outC->EditMode = kcg_true;
  outC->RuntimeMode = kcg_true;
  outC->EditBoxCursorVisibility_SM_reset_act_1 = kcg_true;
  outC->_L27_TextEditBox_SM_Edit = kcg_true;
  outC->rem_MousePressed = kcg_true;
  outC->init3 = kcg_true;
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  outC->TextEditBox_SM_state_nxt = SSM_st_NoEdit_TextEditBox_SM;
  outC->times_1_1 = 0;
  outC->times_2_1 = 0;
  outC->EditBoxCursorVisibility_SM_state_nxt_1 =
    SSM_st_CursorVisible_EditBoxCursorVisibility_SM;
  outC->IndexInString = 0;
  for (i = 0; i < 255; i++) {
    outC->SavedString[i] = ' ';
    outC->pre_Memory_1_Util_array_char_255[i] = ' ';
    outC->DisplayedString[i] = ' ';
    outC->StringChangeValue[i] = ' ';
  }
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void TextEditBox_reset(outC_TextEditBox *outC)
{
  outC->init3 = kcg_true;
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* TextEditBox */
void TextEditBox(inC_TextEditBox *inC, outC_TextEditBox *outC)
{
  /* TextEditBox */ kcg_int tmp2;
  /* TextEditBox */ kcg_bool tmp1;
  /* TextEditBox */ kcg_bool tmp;
  /* Pointer::EditBoxCursorVisibility::EditBoxCursorVisibility_SM */ kcg_bool EditBoxCursorVisibility_SM_reset_prv_1;
  /* Pointer::EditBoxCursorVisibility::EditBoxCursorVisibility_SM */ SSM_ST_EditBoxCursorVisibility_SM EditBoxCursorVisibility_SM_state_act_1;
  /* Pointer::EditBoxCursorVisibility::EditBoxCursorVisibility_SM */ SSM_ST_EditBoxCursorVisibility_SM EditBoxCursorVisibility_SM_state_sel_1;
  kcg_int times_2_1;
  kcg_int times_1_1;
  /* TextEditBox */ kcg_bool op_call;
  /* TextEditBox */ array_char_255 _3_op_call;
  /* TextEditBox */ kcg_int _4_op_call;
  /* TextEditBox::TextEditBox_SM::Edit::_L31 */ kcg_bool _L31_TextEditBox_SM_Edit;
  /* TextEditBox::TextEditBox_SM::Edit::IfBlock1 */ kcg_bool IfBlock1_clock_TextEditBox_SM_Edit;
  /* TextEditBox::TextEditBox_SM::Edit */ kcg_bool Edit_weakb_clock_TextEditBox_SM;
  /* TextEditBox::TextEditBox_SM::Edit::IfBlock1::else::else */ kcg_bool else_clock_TextEditBox_SM_Edit_IfBlock1;
  /* TextEditBox::TextEditBox_SM::Edit::IfBlock1::else */ kcg_bool _5_else_clock_TextEditBox_SM_Edit_IfBlock1;
  /* TextEditBox::IndexInString */ kcg_int last_IndexInString;
  /* TextEditBox::TextEditBox_SM */ SSM_ST_TextEditBox_SM TextEditBox_SM_state_sel;
  /* TextEditBox::TextEditBox_SM */ SSM_ST_TextEditBox_SM TextEditBox_SM_state_act;
  /* TextEditBox::TextEditBox_SM */ kcg_bool TextEditBox_SM_reset_act;
  /* TextEditBox::TextEditBox_SM */ SSM_TR_TextEditBox_SM TextEditBox_SM_fired_strong;
  kcg_int default_IndexInString;
  /* TextEditBox::_L147 */ array_char_255 _L147;
  /* TextEditBox::_L150 */ array_char_255 _L150;
  
  outC->RuntimeMode = kcg_true;
  /* last_init_ck_DisplayedString */ if (outC->init3) {
    TextEditBox_SM_state_sel = SSM_st_NoEdit_TextEditBox_SM;
    TextEditBox_SM_reset_act = !inC->MousePressed;
    kcg_copy_array_char_255(&_L147, (array_char_255 *) &NullString);
  }
  else {
    TextEditBox_SM_state_sel = outC->TextEditBox_SM_state_nxt;
    TextEditBox_SM_reset_act = !outC->rem_MousePressed;
    kcg_copy_array_char_255(&_L147, &outC->DisplayedString);
  }
  tmp1 = TextEditBox_SM_reset_act & inC->MousePressed & ((inC->MouseButton ==
        CLICKBUTTON_Pointer) | (inC->MouseButton == TABLET_BUTTON_Pointer)) &
    inC->MouseInside;
  default_IndexInString = - 1;
  /* last_init_ck_SavedString */ if (outC->init3) {
    last_IndexInString = default_IndexInString;
    kcg_copy_array_char_255(&_L150, (array_char_255 *) &NullString);
  }
  else {
    last_IndexInString = outC->IndexInString;
    kcg_copy_array_char_255(&_L150, &outC->SavedString);
  }
  /* sel_TextEditBox_SM */ switch (TextEditBox_SM_state_sel) {
    case SSM_st_Edit_TextEditBox_SM :
      TextEditBox_SM_state_act = SSM_st_Edit_TextEditBox_SM;
      TextEditBox_SM_reset_act = kcg_false;
      TextEditBox_SM_fired_strong = SSM_TR_no_trans_TextEditBox_SM;
      break;
    case SSM_st_NoEdit_TextEditBox_SM :
      TextEditBox_SM_reset_act = tmp1;
      if (tmp1) {
        TextEditBox_SM_state_act = SSM_st_Edit_TextEditBox_SM;
        TextEditBox_SM_fired_strong = SSM_TR_NoEdit_1_TextEditBox_SM;
      }
      else {
        TextEditBox_SM_state_act = SSM_st_NoEdit_TextEditBox_SM;
        TextEditBox_SM_fired_strong = SSM_TR_no_trans_TextEditBox_SM;
      }
      break;
    
  }
  /* act_TextEditBox_SM */ switch (TextEditBox_SM_state_act) {
    case SSM_st_Edit_TextEditBox_SM :
      _L31_TextEditBox_SM_Edit = inC->KeyPressed & (inC->KeyCode != 13);
      /* ck__L31 */ if (_L31_TextEditBox_SM_Edit) {
        /* 1 */ if (inC->MaxStringLength > MAX_STRING_LENGTH) {
          tmp2 = MAX_STRING_LENGTH;
        }
        else {
          tmp2 = inC->MaxStringLength;
        }
        /* 1 */
        Edit_Strings(
          kcg_false,
          &_L147,
          inC->KeyCode,
          last_IndexInString,
          tmp2,
          &_4_op_call,
          &_3_op_call,
          &op_call);
      }
      outC->EditMode = kcg_true;
      if (TextEditBox_SM_reset_act) {
        outC->init2 = kcg_true;
        outC->init = kcg_true;
        outC->init1 = kcg_true;
      }
      /* fby_1_init_1 */ if (outC->init2) {
        IfBlock1_clock_TextEditBox_SM_Edit = kcg_true;
        EditBoxCursorVisibility_SM_state_sel_1 =
          SSM_st_CursorVisible_EditBoxCursorVisibility_SM;
        EditBoxCursorVisibility_SM_reset_prv_1 = kcg_false;
        tmp = kcg_false;
      }
      else {
        IfBlock1_clock_TextEditBox_SM_Edit = kcg_false;
        EditBoxCursorVisibility_SM_state_sel_1 =
          outC->EditBoxCursorVisibility_SM_state_nxt_1;
        EditBoxCursorVisibility_SM_reset_prv_1 =
          outC->EditBoxCursorVisibility_SM_reset_act_1;
        tmp = outC->_L27_TextEditBox_SM_Edit;
      }
      /* 5 */ if (tmp) {
        outC->IndexInString = inC->CursorIndex;
      }
      else /* ck__L31 */ if (_L31_TextEditBox_SM_Edit) {
        outC->IndexInString = _4_op_call;
      }
      else {
        outC->IndexInString = last_IndexInString;
      }
      Edit_weakb_clock_TextEditBox_SM = TextEditBox_SM_fired_strong !=
        SSM_TR_no_trans_TextEditBox_SM;
      /* strong_fired_Edit */ if (Edit_weakb_clock_TextEditBox_SM) {
        outC->TextEditBox_SM_state_nxt = SSM_st_Edit_TextEditBox_SM;
      }
      else if ((inC->KeyCode == KEY_VALID_Pointer) | (inC->KeyCode ==
          KEY_ABORT_Pointer) | (inC->MousePressed & !inC->MouseInside)) {
        outC->TextEditBox_SM_state_nxt = SSM_st_NoEdit_TextEditBox_SM;
      }
      else {
        outC->TextEditBox_SM_state_nxt = SSM_st_Edit_TextEditBox_SM;
      }
      outC->_L27_TextEditBox_SM_Edit = inC->NewCursorIndex;
      /* ck_IfBlock1 */ if (IfBlock1_clock_TextEditBox_SM_Edit) {
        outC->StringChangeEmit = kcg_false;
        kcg_copy_array_char_255(&outC->SavedString, &_L147);
        tmp1 = kcg_false;
      }
      else {
        _5_else_clock_TextEditBox_SM_Edit_IfBlock1 = (inC->KeyPressed &
            (inC->KeyCode == KEY_VALID_Pointer)) | (inC->MousePressed &
            !inC->MouseInside);
        kcg_copy_array_char_255(&outC->SavedString, &_L150);
        /* ck_anon_activ */ if (_5_else_clock_TextEditBox_SM_Edit_IfBlock1) {
          outC->StringChangeEmit = kcg_true;
          tmp1 = kcg_false;
        }
        else {
          outC->StringChangeEmit = kcg_false;
          else_clock_TextEditBox_SM_Edit_IfBlock1 = inC->KeyPressed &
            (inC->KeyCode == KEY_ABORT_Pointer);
          /* ck_anon_activ */ if (else_clock_TextEditBox_SM_Edit_IfBlock1) {
            tmp1 = kcg_true;
          }
          else {
            tmp1 = kcg_false;
          }
        }
      }
      /* 1_sel_EditBoxCursorVisibility_SM */ switch (EditBoxCursorVisibility_SM_state_sel_1) {
        case SSM_st_CursorHidden_EditBoxCursorVisibility_SM :
          if (EditBoxCursorVisibility_SM_reset_prv_1) {
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
          if (EditBoxCursorVisibility_SM_reset_prv_1) {
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
    case SSM_st_NoEdit_TextEditBox_SM :
      outC->EditMode = kcg_false;
      outC->CursorVisible = kcg_false;
      outC->StringChangeEmit = kcg_false;
      outC->IndexInString = default_IndexInString;
      tmp1 = kcg_false;
      kcg_copy_array_char_255(&outC->SavedString, &_L150);
      outC->TextEditBox_SM_state_nxt = SSM_st_NoEdit_TextEditBox_SM;
      break;
    
  }
  /* 3 */ if (tmp1) {
    kcg_copy_array_char_255(&outC->DisplayedString, &_L150);
  }
  else {
    /* 2 */ if (outC->init3) {
      tmp = kcg_true;
    }
    else {
      tmp = kcg_false;
    }
    /* 2 */ if (tmp | inC->LabelStringReceived) {
      kcg_copy_array_char_255(&outC->DisplayedString, &inC->LabelString);
    }
    else {
      /* act_TextEditBox_SM */ switch (TextEditBox_SM_state_act) {
        case SSM_st_NoEdit_TextEditBox_SM :
          TextEditBox_SM_reset_act = kcg_false;
          break;
        case SSM_st_Edit_TextEditBox_SM :
          /* ck__L31 */ if (_L31_TextEditBox_SM_Edit) {
            TextEditBox_SM_reset_act = op_call;
          }
          else {
            TextEditBox_SM_reset_act = kcg_false;
          }
          break;
        
      }
      /* 4 */ if (TextEditBox_SM_reset_act) {
        /* act_TextEditBox_SM */ switch (TextEditBox_SM_state_act) {
          case SSM_st_NoEdit_TextEditBox_SM :
            kcg_copy_array_char_255(
              &outC->DisplayedString,
              (array_char_255 *) &NullString);
            break;
          case SSM_st_Edit_TextEditBox_SM :
            /* ck__L31 */ if (_L31_TextEditBox_SM_Edit) {
              kcg_copy_array_char_255(&outC->DisplayedString, &_3_op_call);
            }
            else {
              kcg_copy_array_char_255(
                &outC->DisplayedString,
                (array_char_255 *) &NullString);
            }
            break;
          
        }
      }
      else {
        kcg_copy_array_char_255(&outC->DisplayedString, &_L147);
      }
    }
  }
  /* 1 */ if (outC->init3) {
    outC->init3 = kcg_false;
    kcg_copy_array_char_255(&outC->StringChangeValue, &outC->DisplayedString);
  }
  else {
    kcg_copy_array_char_255(
      &outC->StringChangeValue,
      &outC->pre_Memory_1_Util_array_char_255);
  }
  if (outC->StringChangeEmit | inC->LabelStringReceived) {
    kcg_copy_array_char_255(
      &outC->pre_Memory_1_Util_array_char_255,
      &outC->DisplayedString);
  }
  else {
    kcg_copy_array_char_255(
      &outC->pre_Memory_1_Util_array_char_255,
      &outC->StringChangeValue);
  }
  outC->rem_MousePressed = inC->MousePressed;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** TextEditBox.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

