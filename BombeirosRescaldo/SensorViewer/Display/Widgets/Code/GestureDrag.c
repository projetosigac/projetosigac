/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:14
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "GestureDrag.h"

#ifndef KCG_USER_DEFINED_INIT
void GestureDrag_init(outC_GestureDrag *outC)
{
  outC->Dragging = kcg_true;
  outC->_L184 = kcg_true;
  outC->init = kcg_true;
  outC->DisplacementY = 0.0;
  outC->DisplacementX = 0.0;
  outC->PosStartY = 0.0;
  outC->PosStartX = 0.0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void GestureDrag_reset(outC_GestureDrag *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* GestureDrag */
void GestureDrag(inC_GestureDrag *inC, outC_GestureDrag *outC)
{
  /* GestureDrag */ kcg_bool tmp1;
  /* GestureDrag */ kcg_bool tmp;
  /* Util::FlipFlopS::_L3 */ kcg_bool _L3_1;
  /* GestureDrag::_L150 */ kcg_bool _L150;
  
  _L150 = inC->MousePressed & inC->MouseInside;
  /* ck__L150 */ if (_L150) {
    outC->PosStartX = inC->PosXPx;
    outC->PosStartY = inC->PosYPx;
  }
  else /* last_init_ck_PosStartY */ if (outC->init) {
    outC->PosStartX = 0.0;
    outC->PosStartY = 0.0;
  }
  outC->DisplacementX = inC->PosXPx - outC->PosStartX;
  outC->DisplacementY = inC->PosYPx - outC->PosStartY;
  _L3_1 = !inC->MouseReleased;
  /* 2_fby_1_init_1 */ if (outC->init) {
    tmp1 = kcg_false;
    outC->init = kcg_false;
    tmp = kcg_false;
  }
  else {
    tmp1 = outC->_L184;
    tmp = outC->Dragging;
  }
  outC->_L184 = _L150 | (_L3_1 & tmp1);
  outC->Dragging = (outC->_L184 & (/* 1_SqrtR */
        wid_SqrtR(
          (outC->PosStartX - inC->PosXPx) * (outC->PosStartX - inC->PosXPx) +
          (outC->PosStartY - inC->PosYPx) * (outC->PosStartY - inC->PosYPx)) >=
        inC->PosTolerance)) | (_L3_1 & tmp);
}

/* $**************** KCG Version 6.4 (build i21) ****************
** GestureDrag.c
** Generation date: 2014-11-28T14:01:14
*************************************************************$ */

