/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "MultilineEditBox.h"

#ifndef KCG_USER_DEFINED_INIT
void MultilineEditBox_init(outC_MultilineEditBox *outC)
{
  kcg_int i;
  
  outC->CursorVisible = kcg_true;
  outC->EditMode = kcg_true;
  outC->RunTimeMode = kcg_true;
  outC->DragingLift = kcg_true;
  outC->_L28_MultilineEditBox_SM_Edit = kcg_true;
  outC->EditBoxCursorVisibility_SM_reset_act_1 = kcg_true;
  outC->rem_MousePressed = kcg_true;
  outC->init = kcg_true;
  outC->init1 = kcg_true;
  outC->init2 = kcg_true;
  outC->init3 = kcg_true;
  outC->EditBoxCursorVisibility_SM_state_nxt_1 =
    SSM_st_CursorVisible_EditBoxCursorVisibility_SM;
  outC->times_2_1 = 0;
  outC->times_1_1 = 0;
  outC->MultilineEditBox_SM_state_nxt = SSM_st_NoEdit_MultilineEditBox_SM;
  outC->IndexInString = 0;
  outC->EditBoxDisplacement = 0.0;
  for (i = 0; i < 255; i++) {
    outC->DisplayedString[i] = ' ';
    outC->StringChangeValue[i] = ' ';
  }
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void MultilineEditBox_reset(outC_MultilineEditBox *outC)
{
  outC->init = kcg_true;
  outC->init1 = kcg_true;
  outC->init2 = kcg_true;
  outC->init3 = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* MultilineEditBox */
void MultilineEditBox(inC_MultilineEditBox *inC, outC_MultilineEditBox *outC)
{
  /* MultilineEditBox */ kcg_int tmp3;
  /* MultilineEditBox */ kcg_bool tmp2;
  /* MultilineEditBox */ kcg_bool tmp1;
  /* MultilineEditBox */ kcg_bool tmp;
  /* MultilineEditBox::_L208 */ kcg_real _L208;
  /* MultilineEditBox::_L198 */ kcg_real _L198;
  /* MultilineEditBox::_L179 */ kcg_real _L179;
  /* MultilineEditBox::_L174 */ kcg_real _L174;
  /* MultilineEditBox::_L158 */ kcg_real _L158;
  /* MultilineEditBox::_L147 */ array_char_255 _L147;
  /* MultilineEditBox::MaxDisplacement */ kcg_real MaxDisplacement;
  /* MultilineEditBox::MultilineEditBox_SM */ SSM_TR_MultilineEditBox_SM MultilineEditBox_SM_fired_strong;
  /* MultilineEditBox::MultilineEditBox_SM */ kcg_bool MultilineEditBox_SM_reset_act;
  /* MultilineEditBox::MultilineEditBox_SM */ SSM_ST_MultilineEditBox_SM MultilineEditBox_SM_state_act;
  /* MultilineEditBox::MultilineEditBox_SM */ SSM_ST_MultilineEditBox_SM MultilineEditBox_SM_state_sel;
  /* MultilineEditBox::IndexInString */ kcg_int last_IndexInString;
  /* MultilineEditBox::MultilineEditBox_SM::Edit */ kcg_bool Edit_weakb_clock_MultilineEditBox_SM;
  /* MultilineEditBox::MultilineEditBox_SM::Edit::_L22 */ kcg_bool _L22_MultilineEditBox_SM_Edit;
  /* MultilineEditBox */ kcg_int _5_op_call;
  /* MultilineEditBox */ array_char_255 _4_op_call;
  /* MultilineEditBox */ kcg_bool op_call;
  kcg_int times_1_1;
  kcg_int times_2_1;
  /* Pointer::EditBoxCursorVisibility::EditBoxCursorVisibility_SM */ SSM_ST_EditBoxCursorVisibility_SM EditBoxCursorVisibility_SM_state_sel_1;
  /* Pointer::EditBoxCursorVisibility::EditBoxCursorVisibility_SM */ SSM_ST_EditBoxCursorVisibility_SM EditBoxCursorVisibility_SM_state_act_1;
  /* Pointer::EditBoxCursorVisibility::EditBoxCursorVisibility_SM */ kcg_bool EditBoxCursorVisibility_SM_reset_prv_1;
  
  outC->RunTimeMode = kcg_true;
  /* 1_fby_1_init_1 */ if (outC->init3) {
    kcg_copy_array_char_255(&_L147, (array_char_255 *) &NullString);
    MultilineEditBox_SM_state_sel = SSM_st_NoEdit_MultilineEditBox_SM;
    MultilineEditBox_SM_reset_act = !inC->MousePressed;
    last_IndexInString = - 1;
    tmp2 = kcg_true;
    outC->init3 = kcg_false;
    tmp = kcg_false;
    _L158 = 0.0;
  }
  else {
    kcg_copy_array_char_255(&_L147, &outC->StringChangeValue);
    MultilineEditBox_SM_state_sel = outC->MultilineEditBox_SM_state_nxt;
    MultilineEditBox_SM_reset_act = !outC->rem_MousePressed;
    last_IndexInString = outC->IndexInString;
    tmp2 = kcg_false;
    _L158 = outC->EditBoxDisplacement;
    tmp = outC->DragingLift;
  }
  tmp1 = MultilineEditBox_SM_reset_act & inC->MousePressed &
    ((inC->MouseButton == CLICKBUTTON_Pointer) | (inC->MouseButton ==
        TABLET_BUTTON_Pointer)) & inC->MouseInside;
  /* sel_MultilineEditBox_SM */ switch (MultilineEditBox_SM_state_sel) {
    case SSM_st_Edit_MultilineEditBox_SM :
      MultilineEditBox_SM_state_act = SSM_st_Edit_MultilineEditBox_SM;
      MultilineEditBox_SM_reset_act = kcg_false;
      MultilineEditBox_SM_fired_strong = SSM_TR_no_trans_MultilineEditBox_SM;
      break;
    case SSM_st_NoEdit_MultilineEditBox_SM :
      MultilineEditBox_SM_reset_act = tmp1;
      if (tmp1) {
        MultilineEditBox_SM_state_act = SSM_st_Edit_MultilineEditBox_SM;
        MultilineEditBox_SM_fired_strong = SSM_TR_NoEdit_1_MultilineEditBox_SM;
      }
      else {
        MultilineEditBox_SM_state_act = SSM_st_NoEdit_MultilineEditBox_SM;
        MultilineEditBox_SM_fired_strong = SSM_TR_no_trans_MultilineEditBox_SM;
      }
      break;
    
  }
  /* act_MultilineEditBox_SM */ switch (MultilineEditBox_SM_state_act) {
    case SSM_st_Edit_MultilineEditBox_SM :
      _L22_MultilineEditBox_SM_Edit = inC->KeyPressed;
      /* ck__L22 */ if (_L22_MultilineEditBox_SM_Edit) {
        /* 1 */ if (inC->MaxStringLength > MAX_STRING_LENGTH) {
          tmp3 = MAX_STRING_LENGTH;
        }
        else {
          tmp3 = inC->MaxStringLength;
        }
        /* 1 */
        Edit_Strings(
          kcg_false,
          &_L147,
          inC->KeyCode,
          last_IndexInString,
          tmp3,
          &_5_op_call,
          &_4_op_call,
          &op_call);
      }
      outC->EditMode = kcg_true;
      if (MultilineEditBox_SM_reset_act) {
        outC->init2 = kcg_true;
        outC->init = kcg_true;
        outC->init1 = kcg_true;
      }
      /* fby_1_init_1 */ if (outC->init2) {
        EditBoxCursorVisibility_SM_state_sel_1 =
          SSM_st_CursorVisible_EditBoxCursorVisibility_SM;
        EditBoxCursorVisibility_SM_reset_prv_1 = kcg_false;
        tmp1 = kcg_false;
      }
      else {
        EditBoxCursorVisibility_SM_state_sel_1 =
          outC->EditBoxCursorVisibility_SM_state_nxt_1;
        EditBoxCursorVisibility_SM_reset_prv_1 =
          outC->EditBoxCursorVisibility_SM_reset_act_1;
        tmp1 = outC->_L28_MultilineEditBox_SM_Edit;
      }
      /* 11 */ if (tmp1) {
        outC->IndexInString = inC->CursorIndex;
      }
      else /* ck__L22 */ if (_L22_MultilineEditBox_SM_Edit) {
        outC->IndexInString = _5_op_call;
      }
      else {
        outC->IndexInString = last_IndexInString;
      }
      Edit_weakb_clock_MultilineEditBox_SM = MultilineEditBox_SM_fired_strong !=
        SSM_TR_no_trans_MultilineEditBox_SM;
      /* strong_fired_Edit */ if (Edit_weakb_clock_MultilineEditBox_SM) {
        outC->MultilineEditBox_SM_state_nxt = SSM_st_Edit_MultilineEditBox_SM;
      }
      else if ((inC->KeyCode == KEY_ABORT_Pointer) | (inC->MousePressed &
          !inC->MouseInside & !inC->ClickedDown & !inC->ClickedUp) |
        inC->ClickedLift | inC->ClickedUp | inC->ClickedDown) {
        outC->MultilineEditBox_SM_state_nxt = SSM_st_NoEdit_MultilineEditBox_SM;
      }
      else {
        outC->MultilineEditBox_SM_state_nxt = SSM_st_Edit_MultilineEditBox_SM;
      }
      outC->_L28_MultilineEditBox_SM_Edit = inC->NewCursorIndex;
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
    case SSM_st_NoEdit_MultilineEditBox_SM :
      outC->EditMode = kcg_false;
      outC->CursorVisible = kcg_false;
      outC->IndexInString = - 1;
      outC->MultilineEditBox_SM_state_nxt = SSM_st_NoEdit_MultilineEditBox_SM;
      break;
    
  }
  /* 2 */ if (tmp2 | inC->LabelStringReceived) {
    kcg_copy_array_char_255(&outC->StringChangeValue, &inC->LabelString);
  }
  else {
    /* act_MultilineEditBox_SM */ switch (MultilineEditBox_SM_state_act) {
      case SSM_st_NoEdit_MultilineEditBox_SM :
        MultilineEditBox_SM_reset_act = kcg_false;
        break;
      case SSM_st_Edit_MultilineEditBox_SM :
        /* ck__L22 */ if (_L22_MultilineEditBox_SM_Edit) {
          MultilineEditBox_SM_reset_act = op_call;
        }
        else {
          MultilineEditBox_SM_reset_act = kcg_false;
        }
        break;
      
    }
    /* 4 */ if (MultilineEditBox_SM_reset_act) {
      /* act_MultilineEditBox_SM */ switch (MultilineEditBox_SM_state_act) {
        case SSM_st_NoEdit_MultilineEditBox_SM :
          kcg_copy_array_char_255(
            &outC->StringChangeValue,
            (array_char_255 *) &NullString);
          break;
        case SSM_st_Edit_MultilineEditBox_SM :
          /* ck__L22 */ if (_L22_MultilineEditBox_SM_Edit) {
            kcg_copy_array_char_255(&outC->StringChangeValue, &_4_op_call);
          }
          else {
            kcg_copy_array_char_255(
              &outC->StringChangeValue,
              (array_char_255 *) &NullString);
          }
          break;
        
      }
    }
    else {
      kcg_copy_array_char_255(&outC->StringChangeValue, &_L147);
    }
  }
  kcg_copy_array_char_255(&outC->DisplayedString, &outC->StringChangeValue);
  _L174 = - inC->TextBoxVerticalSize;
  _L198 = _L174 - inC->CursorPosY;
  outC->DragingLift = !inC->ReleasedLift & (inC->ClickedLift | tmp);
  MaxDisplacement = (kcg_real) inC->NbLines * inC->LineSize -
    inC->TextBoxVerticalSize;
  /* 1 */ if (_L198 >= 0.0) {
    _L208 = _L198 + inC->LineSize / 2.0;
  }
  else {
    _L208 = _L198 - inC->LineSize / 2.0;
  }
  _L179 = (kcg_real) (kcg_int) (_L208 / inC->LineSize) * inC->LineSize;
  /* 13 */ if (outC->DragingLift) {
    _L208 = inC->PositionLift * MaxDisplacement;
  }
  else /* 5 */ if (inC->ClickedUp) {
    _L208 = _L158 - inC->LineSize;
  }
  else /* 6 */ if (inC->ClickedDown) {
    _L208 = inC->LineSize + _L158;
  }
  else /* 7 */ if (outC->EditMode & (inC->CursorPosY < _L174)) {
    /* 10 */ if (_L198 - _L179 < 0.0) {
      _L208 = _L179;
    }
    else {
      _L208 = _L179 + inC->LineSize;
    }
  }
  else {
    _L208 = _L158;
  }
  /* 12 */ if (_L208 <= MaxDisplacement) {
    _L198 = _L208;
  }
  else {
    _L198 = MaxDisplacement;
  }
  /* 8 */ if (_L198 >= 0.0) {
    outC->EditBoxDisplacement = _L198;
  }
  else {
    outC->EditBoxDisplacement = 0.0;
  }
  outC->rem_MousePressed = inC->MousePressed;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** MultilineEditBox.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

