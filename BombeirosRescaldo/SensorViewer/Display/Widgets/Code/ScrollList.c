/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "ScrollList.h"

#ifndef KCG_USER_DEFINED_INIT
void ScrollList_init(outC_ScrollList *outC)
{
  kcg_int i1;
  kcg_int i;
  
  outC->SelectedItemEmit = kcg_true;
  outC->DragingLift = kcg_true;
  outC->init = kcg_true;
  outC->Offset = 0;
  for (i = 0; i < 9; i++) {
    outC->init_1[i] = kcg_true;
    outC->_1_init_1[i] = kcg_true;
    outC->_L4_1_IfBlock1[i] = kcg_true;
    outC->_L5_1_IfBlock1[i] = kcg_true;
    outC->rem_MousePressed_1[i] = kcg_true;
    outC->SelectedTable[i] = kcg_true;
    outC->EnableTable[i] = kcg_true;
    for (i1 = 0; i1 < 255; i1++) {
      outC->LocalLabelStringArray[i][i1] = ' ';
    }
  }
  outC->SelectedItemValue = 0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ScrollList_reset(outC_ScrollList *outC)
{
  kcg_int i;
  
  outC->init = kcg_true;
  for (i = 0; i < 9; i++) {
    outC->init_1[i] = kcg_true;
    outC->_1_init_1[i] = kcg_true;
  }
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* ScrollList */
void ScrollList(inC_ScrollList *inC, outC_ScrollList *outC)
{
  /* ScrollList */ kcg_real tmp2;
  /* ScrollList::BuildStringTable::_L7 */ kcg_int _L7_1;
  /* ScrollList */ array_bool_9 tmp;
  /* Pointer::MouseClicked::RisingEdge_Pressed */ kcg_bool RisingEdge_Pressed_1;
  /* Pointer::MouseClicked::IfBlock1 */ kcg_bool IfBlock1_clock_1;
  /* Pointer::MouseClicked */ kcg_bool tmp_11;
  /* Pointer::MouseClicked */ kcg_bool tmp_1;
  kcg_int i;
  /* ScrollList::IfBlock1 */ kcg_bool IfBlock1_clock;
  /* ScrollList::InitialSelectedItem */ kcg_int InitialSelectedItem;
  /* ScrollList::_L58 */ kcg_bool _L58;
  /* ScrollList::_L155 */ kcg_real _L155;
  /* ScrollList::_L178 */ kcg_bool _L178;
  /* ScrollList::_L174 */ kcg_int _L174;
  
  _L58 = kcg_false;
  _L178 = (inC->SelectedItem >= 0) & (inC->SelectedItem < inC->NumberOfItems);
  /* 13 */ if (_L178) {
    InitialSelectedItem = inC->SelectedItem;
  }
  else {
    InitialSelectedItem = 0;
  }
  i = inC->NumberOfItems - inC->NumberOfDisplayedItems;
  /* 1 */ if (outC->init) {
    _L7_1 = 0;
    IfBlock1_clock = kcg_false;
    tmp_1 = kcg_true;
  }
  else {
    _L7_1 = outC->Offset;
    IfBlock1_clock = outC->DragingLift;
    tmp_1 = inC->SetSelectedItem;
  }
  outC->DragingLift = !inC->ReleasedLift & (inC->ClickedLift | IfBlock1_clock);
  _L155 = (kcg_real) i;
  /* 14 */ if (i <= 0) {
    tmp2 = 1.0;
  }
  else {
    tmp2 = _L155;
  }
  IfBlock1_clock = inC->PositionClicked > 1.0 - 1.0 / (tmp2 + 1.0);
  /* ck_IfBlock1 */ if (IfBlock1_clock) {
  }
  else {
    tmp_11 = inC->PositionClicked < 1.0 / (tmp2 + 1.0);
  }
  /* 5 */ if (tmp_1) {
    /* 6 */ if (InitialSelectedItem >= inC->NumberOfDisplayedItems) {
      /* 9 */ if (InitialSelectedItem > i) {
        outC->Offset = i;
      }
      else {
        outC->Offset = InitialSelectedItem;
      }
    }
    else {
      outC->Offset = 0;
    }
  }
  else /* 8 */ if (outC->DragingLift) {
    /* ck_IfBlock1 */ if (IfBlock1_clock) {
      tmp2 = 0.0;
    }
    else /* ck_anon_activ */ if (tmp_11) {
      tmp2 = 1.0;
    }
    else {
      tmp2 = 1.0 - inC->PositionClicked;
    }
    outC->Offset = (kcg_int) (tmp2 * _L155);
  }
  else /* 2 */ if (inC->ClickedDown & (_L7_1 < i)) {
    outC->Offset = 1 + _L7_1;
  }
  else /* 3 */ if (inC->ClickedUp & (_L7_1 > 0)) {
    outC->Offset = _L7_1 - 1;
  }
  else {
    outC->Offset = _L7_1;
  }
  for (i = 0; i < 9; i++) {
    _L7_1 = i + outC->Offset;
    if ((0 <= _L7_1) & (_L7_1 < 16)) {
      kcg_copy_array_char_255(
        &outC->LocalLabelStringArray[i],
        &inC->LabelStringArray[_L7_1]);
      outC->EnableTable[i] = inC->EnableArray[_L7_1];
    }
    else {
      kcg_copy_array_char_255(
        &outC->LocalLabelStringArray[i],
        (array_char_255 *) &EMPTY_STRING_ScrollList);
      outC->EnableTable[i] = kcg_true;
    }
    IfBlock1_clock_1 = inC->EmitCondition == ON_RELEASED_Pointer;
    /* 1_fby_1_init_1 */ if (outC->_1_init_1[i]) {
      IfBlock1_clock = !inC->MousePressed;
    }
    else {
      IfBlock1_clock = !outC->rem_MousePressed_1[i];
    }
    RisingEdge_Pressed_1 = IfBlock1_clock & inC->MousePressed;
    outC->rem_MousePressed_1[i] = inC->MousePressed;
    outC->_1_init_1[i] = kcg_false;
    /* ck_IfBlock1 */ if (IfBlock1_clock_1) {
      /* 1_fby_1_init_1 */ if (outC->init_1[i]) {
        tmp_11 = kcg_false;
        tmp_1 = kcg_true;
      }
      else {
        tmp_1 = !outC->_L4_1_IfBlock1[i];
        tmp_11 = outC->_L5_1_IfBlock1[i];
      }
      outC->_L5_1_IfBlock1[i] = (RisingEdge_Pressed_1 & ((inC->MouseButton ==
              CLICKBUTTON_Pointer) | (inC->MouseButton ==
              TABLET_BUTTON_Pointer)) & inC->MouseInside[i]) | (tmp_1 & tmp_11);
      outC->_L4_1_IfBlock1[i] = inC->MouseReleased;
      tmp[i] = outC->_L5_1_IfBlock1[i] & inC->MouseInside[i] &
        outC->_L4_1_IfBlock1[i];
      outC->init_1[i] = kcg_false;
    }
    else {
      tmp[i] = RisingEdge_Pressed_1 & ((inC->MouseButton ==
            CLICKBUTTON_Pointer) | (inC->MouseButton ==
            TABLET_BUTTON_Pointer)) & inC->MouseInside[i];
    }
  }
  for (i = 0; i < 9; i++) {
    IfBlock1_clock = tmp[i] & outC->EnableTable[i];
    _L58 = IfBlock1_clock | _L58;
    _L7_1 = i + 1;
    if (IfBlock1_clock) {
      break;
    }
  }
  /* 12 */ if (_L58) {
    _L174 = outC->Offset + (_L7_1 - 1);
  }
  else /* last_init_ck_LocalSelectedItem */ if (outC->init) {
    _L174 = InitialSelectedItem;
  }
  else {
    _L174 = outC->SelectedItemValue;
  }
  /* 11 */ if (inC->SetSelectedItem) {
    /* 10 */ if (_L178) {
      outC->SelectedItemValue = inC->SelectedItem;
    }
    else {
      outC->SelectedItemValue = _L174;
    }
  }
  else {
    outC->SelectedItemValue = _L174;
  }
  for (i = 0; i < 9; i++) {
    outC->SelectedTable[i] = i == outC->SelectedItemValue - outC->Offset;
  }
  /* 1_fby_1_init_1 */ if (outC->init) {
    outC->init = kcg_false;
    tmp_1 = kcg_false;
  }
  else {
    tmp_1 = outC->SelectedItemEmit;
  }
  outC->SelectedItemEmit = _L58 | (!BHVR_AsynchronousACK & tmp_1);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** ScrollList.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

