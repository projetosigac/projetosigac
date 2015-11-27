/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "InfiniteKnob.h"

#ifndef KCG_USER_DEFINED_INIT
void InfiniteKnob_init(outC_InfiniteKnob *outC)
{
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  outC->localAngleIn = 0.0;
  outC->localRevolutions = 0;
  outC->_L16_IfBlock_SM1_rotate = 0.0;
  outC->_L15_IfBlock_SM1_rotate = 0;
  outC->SM1_state_nxt_IfBlock = SSM_st_StBy_IfBlock_SM1;
  outC->Value = 0.0;
  outC->AngleKnob = 0.0;
  outC->State = 0;
  outC->KnobState = 0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void InfiniteKnob_reset(outC_InfiniteKnob *outC)
{
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* InfiniteKnob */
void InfiniteKnob(inC_InfiniteKnob *inC, outC_InfiniteKnob *outC)
{
  /* InfiniteKnob */ kcg_bool tmp3;
  /* InfiniteKnob */ kcg_int tmp2;
  /* InfiniteKnob */ kcg_int tmp1;
  /* InfiniteKnob */ kcg_real tmp;
  /* Math::InRangeOutIn::IRIO_Input */ kcg_real IRIO_Input_2_1;
  /* InfiniteKnob::IfBlock::then::SM1 */ kcg_bool SM1_reset_act_IfBlock;
  /* InfiniteKnob::IfBlock::then::SM1 */ SSM_ST_SM1_IfBlock SM1_state_act_IfBlock;
  /* InfiniteKnob::IfBlock::then::SM1 */ SSM_ST_SM1_IfBlock SM1_state_sel_IfBlock;
  /* InfiniteKnob::localAngleIn */ kcg_real last_localAngleIn;
  /* InfiniteKnob::localRevolutions */ kcg_int last_localRevolutions;
  /* InfiniteKnob::Value */ kcg_real last_Value;
  
  /* last_init_ck_localAngleIn */ if (outC->init1) {
    last_Value = 90.0;
    last_localAngleIn = 90.;
  }
  else {
    last_Value = outC->AngleKnob;
    last_localAngleIn = outC->localAngleIn;
  }
  /* ck_Enabled */ if (inC->Enabled) {
    /* init_SM1 */ if (outC->init2) {
      SM1_state_sel_IfBlock = SSM_st_StBy_IfBlock_SM1;
    }
    else {
      SM1_state_sel_IfBlock = outC->SM1_state_nxt_IfBlock;
    }
    /* sel_SM1 */ switch (SM1_state_sel_IfBlock) {
      case SSM_st_rotate_IfBlock_SM1 :
        if (inC->MouseReleased) {
          SM1_state_act_IfBlock = SSM_st_StBy_IfBlock_SM1;
        }
        else {
          SM1_state_act_IfBlock = SSM_st_rotate_IfBlock_SM1;
        }
        SM1_reset_act_IfBlock = inC->MouseReleased;
        break;
      case SSM_st_StBy_IfBlock_SM1 :
        SM1_reset_act_IfBlock = inC->MousePressed & inC->InsideButton;
        if (SM1_reset_act_IfBlock) {
          SM1_state_act_IfBlock = SSM_st_rotate_IfBlock_SM1;
        }
        else {
          SM1_state_act_IfBlock = SSM_st_StBy_IfBlock_SM1;
        }
        break;
      
    }
    /* act_SM1 */ switch (SM1_state_act_IfBlock) {
      case SSM_st_rotate_IfBlock_SM1 :
        tmp3 = kcg_true;
        outC->State = 2;
        if (SM1_reset_act_IfBlock) {
          outC->init = kcg_true;
        }
        /* 1_fby_1_init_1 */ if (outC->init) {
          IRIO_Input_2_1 = last_localAngleIn;
        }
        else {
          IRIO_Input_2_1 = outC->_L16_IfBlock_SM1_rotate;
        }
        outC->_L16_IfBlock_SM1_rotate = inC->AngleIn;
        outC->AngleKnob = outC->_L16_IfBlock_SM1_rotate;
        break;
      case SSM_st_StBy_IfBlock_SM1 :
        tmp3 = kcg_false;
        outC->State = 1;
        outC->AngleKnob = last_Value;
        break;
      
    }
    /* 1 */ if (tmp3 | inC->InsideButton) {
      outC->KnobState = 2;
    }
    else {
      outC->KnobState = 1;
    }
  }
  else {
    outC->KnobState = 1;
    /* last_init_ck_State */ if (outC->init1) {
      outC->State = 1;
    }
    outC->AngleKnob = last_Value;
  }
  /* last_init_ck_localRevolutions */ if (outC->init1) {
    outC->init1 = kcg_false;
    last_Value = 0.0;
    last_localRevolutions = 0;
  }
  else {
    last_Value = outC->Value;
    last_localRevolutions = outC->localRevolutions;
  }
  /* ck_Enabled */ if (inC->Enabled) {
    /* act_SM1 */ switch (SM1_state_act_IfBlock) {
      case SSM_st_StBy_IfBlock_SM1 :
        outC->Value = last_Value;
        outC->localRevolutions = last_localRevolutions;
        outC->localAngleIn = last_localAngleIn;
        outC->SM1_state_nxt_IfBlock = SSM_st_StBy_IfBlock_SM1;
        break;
      case SSM_st_rotate_IfBlock_SM1 :
        /* 1 */ if ((180. >= outC->_L16_IfBlock_SM1_rotate) &
          (outC->_L16_IfBlock_SM1_rotate > 90.) & ((90. >= IRIO_Input_2_1) &
            (IRIO_Input_2_1 > 0.))) {
          tmp2 = - 1;
        }
        else /* 2 */ if ((90. >= outC->_L16_IfBlock_SM1_rotate) &
          (outC->_L16_IfBlock_SM1_rotate > 0.) & ((180. >= IRIO_Input_2_1) &
            (IRIO_Input_2_1 > 90.))) {
          tmp2 = 1;
        }
        else {
          tmp2 = 0;
        }
        /* 1_fby_1_init_2 */ if (outC->init) {
          outC->init = kcg_false;
          tmp1 = last_localRevolutions;
        }
        else {
          tmp1 = outC->_L15_IfBlock_SM1_rotate;
        }
        outC->_L15_IfBlock_SM1_rotate = tmp2 + tmp1;
        /* 1 */ if (outC->_L16_IfBlock_SM1_rotate <= 90.) {
          tmp = 90. - outC->_L16_IfBlock_SM1_rotate;
        }
        else {
          tmp = 450. - outC->_L16_IfBlock_SM1_rotate;
        }
        outC->Value = inC->ValuePerRevolution * tmp / 360. +
          inC->ValuePerRevolution * (kcg_real) outC->_L15_IfBlock_SM1_rotate;
        outC->localRevolutions = outC->_L15_IfBlock_SM1_rotate;
        outC->localAngleIn = outC->_L16_IfBlock_SM1_rotate;
        outC->SM1_state_nxt_IfBlock = SSM_st_rotate_IfBlock_SM1;
        break;
      
    }
    outC->init2 = kcg_false;
  }
  else {
    outC->Value = last_Value;
    outC->localRevolutions = last_localRevolutions;
    outC->localAngleIn = last_localAngleIn;
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** InfiniteKnob.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

