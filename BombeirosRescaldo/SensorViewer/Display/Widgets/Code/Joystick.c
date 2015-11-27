/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "Joystick.h"

#ifndef KCG_USER_DEFINED_INIT
void Joystick_init(outC_Joystick *outC)
{
  outC->Active = kcg_true;
  outC->init = kcg_true;
  outC->SM1_state_nxt = SSM_st_Pressed_SM1;
  outC->PosY = 0.0;
  outC->PosX = 0.0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Joystick_reset(outC_Joystick *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Joystick */
void Joystick(inC_Joystick *inC, outC_Joystick *outC)
{
  /* Joystick */ kcg_real tmp1;
  /* Joystick */ kcg_real tmp;
  /* Util::Limiter::InfBound */ kcg_real InfBound_3;
  /* Joystick::SM1::Pressed::IfBlock1 */ kcg_bool IfBlock1_clock_SM1_Pressed;
  /* Joystick::SM1::Pressed::IfBlock1::else::_L7 */ kcg_bool _L7_SM1_Pressed_IfBlock1;
  /* Joystick::SM1::Pressed::IfBlock1::else::_L8 */ kcg_real _L8_SM1_Pressed_IfBlock1;
  /* Joystick::SM1::Pressed::IfBlock1::else::_L9 */ kcg_real _L9_SM1_Pressed_IfBlock1;
  /* Joystick::SM1::Pressed::IfBlock1::then::_L10 */ kcg_real _L10_SM1_Pressed_IfBlock1;
  /* Joystick::SM1::Pressed::IfBlock1::then::_L13 */ kcg_bool _L13_SM1_Pressed_IfBlock1;
  /* Joystick::SM1 */ _1_SSM_ST_SM1 SM1_state_sel;
  /* Joystick::SM1 */ _1_SSM_ST_SM1 SM1_state_act;
  
  /* init_SM1 */ if (outC->init) {
    SM1_state_sel = SSM_st_Idle_SM1;
  }
  else {
    SM1_state_sel = outC->SM1_state_nxt;
  }
  /* sel_SM1 */ switch (SM1_state_sel) {
    case SSM_st_Pressed_SM1 :
      if (inC->Released) {
        SM1_state_act = SSM_st_Idle_SM1;
      }
      else {
        SM1_state_act = SSM_st_Pressed_SM1;
      }
      break;
    case SSM_st_Idle_SM1 :
      if (inC->Pressed) {
        SM1_state_act = SSM_st_Pressed_SM1;
      }
      else {
        SM1_state_act = SSM_st_Idle_SM1;
      }
      break;
    
  }
  /* act_SM1 */ switch (SM1_state_act) {
    case SSM_st_Pressed_SM1 :
      outC->Active = kcg_true;
      IfBlock1_clock_SM1_Pressed = !inC->Snap;
      /* ck_IfBlock1 */ if (IfBlock1_clock_SM1_Pressed) {
        _L10_SM1_Pressed_IfBlock1 = /* 2 */
          wid_SqrtR(inC->inX * inC->inX + inC->inY * inC->inY);
        _L13_SM1_Pressed_IfBlock1 = _L10_SM1_Pressed_IfBlock1 > 1.0;
        /* ck__L13 */ if (_L13_SM1_Pressed_IfBlock1) {
          outC->PosX = inC->inX / _L10_SM1_Pressed_IfBlock1;
          outC->PosY = inC->inY / _L10_SM1_Pressed_IfBlock1;
        }
        else {
          outC->PosX = inC->inX;
          outC->PosY = inC->inY;
        }
      }
      else {
        /* 1 */ if (0. <= inC->inX) {
          tmp1 = inC->inX;
        }
        else {
          tmp1 = - inC->inX;
        }
        /* 1 */ if (0. <= inC->inY) {
          tmp = inC->inY;
        }
        else {
          tmp = - inC->inY;
        }
        _L7_SM1_Pressed_IfBlock1 = tmp1 > tmp;
        InfBound_3 = - 1.0;
        /* 6 */ if (_L7_SM1_Pressed_IfBlock1) {
          _L8_SM1_Pressed_IfBlock1 = inC->inX;
          _L9_SM1_Pressed_IfBlock1 = 0.0;
        }
        else {
          _L8_SM1_Pressed_IfBlock1 = 0.0;
          _L9_SM1_Pressed_IfBlock1 = inC->inY;
        }
        /* 2 */ if (_L8_SM1_Pressed_IfBlock1 > 1.0) {
          outC->PosX = 1.0;
        }
        else /* 1 */ if (_L8_SM1_Pressed_IfBlock1 > InfBound_3) {
          outC->PosX = _L8_SM1_Pressed_IfBlock1;
        }
        else {
          outC->PosX = InfBound_3;
        }
        /* 2 */ if (_L9_SM1_Pressed_IfBlock1 > 1.0) {
          outC->PosY = 1.0;
        }
        else /* 1 */ if (_L9_SM1_Pressed_IfBlock1 > InfBound_3) {
          outC->PosY = _L9_SM1_Pressed_IfBlock1;
        }
        else {
          outC->PosY = InfBound_3;
        }
      }
      outC->SM1_state_nxt = SSM_st_Pressed_SM1;
      break;
    case SSM_st_Idle_SM1 :
      outC->Active = kcg_false;
      /* 7 */ if (inC->ReturnToCenter) {
        outC->PosX = 0.0;
        outC->PosY = 0.0;
      }
      else /* last_init_ck_PosY */ if (outC->init) {
        outC->PosX = 0.0;
        outC->PosY = 0.0;
      }
      outC->SM1_state_nxt = SSM_st_Idle_SM1;
      break;
    
  }
  outC->init = kcg_false;
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Joystick.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

