/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "RadioBox.h"

#ifndef KCG_USER_DEFINED_INIT
void RadioBox_init(outC_RadioBox *outC)
{
  kcg_int i;
  
  outC->SelectedItemEmit = kcg_true;
  outC->init = kcg_true;
  outC->SelectedItemValue = 0;
  for (i = 0; i < 16; i++) {
    outC->SelectedTable[i] = kcg_true;
  }
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void RadioBox_reset(outC_RadioBox *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* RadioBox */
void RadioBox(inC_RadioBox *inC, outC_RadioBox *outC)
{
  /* RadioBox */ kcg_bool tmp;
  /* RadioBox::NewSelection */ array_bool_16 NewSelection;
  /* RadioBox::ForceItem */ kcg_bool ForceItem;
  /* RadioBox::ItemToBeForced */ kcg_int ItemToBeForced;
  /* RadioBox::_L167 */ array_bool_16 _L167;
  /* RadioBox::_L169 */ kcg_bool _L169;
  /* RadioBox::_L178 */ kcg_int _L178;
  /* RadioBox::_L196 */ kcg_int _L196;
  kcg_int i;
  
  _L169 = kcg_false;
  /* 3 */ if (outC->init) {
    _L167[0] = kcg_false;
    _L167[1] = kcg_false;
    _L167[2] = kcg_false;
    _L167[3] = kcg_false;
    _L167[4] = kcg_false;
    _L167[5] = kcg_false;
    _L167[6] = kcg_false;
    _L167[7] = kcg_false;
    _L167[8] = kcg_false;
    _L167[9] = kcg_false;
    _L167[10] = kcg_false;
    _L167[11] = kcg_false;
    _L167[12] = kcg_false;
    _L167[13] = kcg_false;
    _L167[14] = kcg_false;
    _L167[15] = kcg_false;
    tmp = kcg_true;
  }
  else {
    kcg_copy_array_bool_16(&_L167, &outC->SelectedTable);
    tmp = kcg_false;
  }
  for (i = 0; i < 16; i++) {
    NewSelection[i] = inC->StateChangeEmitTable[i] & !_L167[i];
    _L196 = i + 1;
    if (!(i < inC->NumberOfItems)) {
      break;
    }
  }
#ifdef KCG_MAPW_CPY
  
  for (i = _L196; i < 16; i++) {
    NewSelection[i] = kcg_false;
  }
#endif /* KCG_MAPW_CPY */
  
  for (i = 0; i < 16; i++) {
    _L169 = _L169 | NewSelection[i];
  }
  ForceItem = inC->SetSelectedItem | tmp;
  _L196 = - 1;
  /* 5 */ if ((inC->SelectedItem >= 0) & (inC->SelectedItem <
      inC->NumberOfItems)) {
    ItemToBeForced = inC->SelectedItem;
  }
  else {
    ItemToBeForced = _L196;
  }
  /* 1 */ if (_L169) {
    kcg_copy_array_bool_16(&outC->SelectedTable, &NewSelection);
  }
  else /* 4 */ if (ForceItem) {
    for (i = 0; i < 16; i++) {
      outC->SelectedTable[i] = kcg_false;
    }
    if ((0 <= ItemToBeForced) & (ItemToBeForced < 16)) {
      outC->SelectedTable[ItemToBeForced] = kcg_true;
    }
  }
  else {
    kcg_copy_array_bool_16(&outC->SelectedTable, &_L167);
  }
  for (i = 0; i < 16; i++) {
    _L178 = i + 1;
    if (NewSelection[i]) {
      break;
    }
  }
  /* 2 */ if (_L169) {
    outC->SelectedItemValue = _L178 - 1;
  }
  else /* 3 */ if (ForceItem) {
    outC->SelectedItemValue = ItemToBeForced;
  }
  else /* last_init_ck_SelectedItemValue */ if (outC->init) {
    outC->SelectedItemValue = _L196;
  }
  /* 1_fby_1_init_1 */ if (outC->init) {
    outC->init = kcg_false;
    tmp = kcg_false;
  }
  else {
    tmp = outC->SelectedItemEmit;
  }
  outC->SelectedItemEmit = _L169 | (!BHVR_AsynchronousACK & tmp);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** RadioBox.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

