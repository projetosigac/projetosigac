/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "RotarySwitch.h"

#ifndef KCG_USER_DEFINED_INIT
void RotarySwitch_init(outC_RotarySwitch *outC)
{
  kcg_int i;
  
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  outC->behavior_state_nxt_IfBlock = _8_SSM_st_Change_IfBlock_behavior;
  outC->Value = 0;
  outC->KnobState = 0;
  outC->AngleKnob = 0.0;
  outC->State = 0;
  for (i = 0; i < 8; i++) {
    outC->BarsAngle[i] = 0.0;
    outC->BarsVisible[i] = kcg_true;
  }
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void RotarySwitch_reset(outC_RotarySwitch *outC)
{
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* RotarySwitch */
void RotarySwitch(inC_RotarySwitch *inC, outC_RotarySwitch *outC)
{
  /* RotarySwitch */ kcg_bool tmp;
  /* RotarySwitch::IfBlock::then::behavior */ _9_SSM_ST_behavior_IfBlock behavior_state_act_IfBlock;
  /* RotarySwitch::IfBlock::then::behavior */ _9_SSM_ST_behavior_IfBlock behavior_state_sel_IfBlock;
  /* RotarySwitch::IfBlock::then::behavior::Magnet::lValue */ kcg_int lValue_IfBlock_behavior_Magnet;
  /* RotarySwitch::Value */ kcg_int last_Value;
  /* RotarySwitch::AngleKnob */ kcg_real last_AngleKnob;
  /* RotarySwitch::State */ kcg_int last_State;
  /* RotarySwitch::NbOfStates_saturated */ kcg_int NbOfStates_saturated;
  
  /* 2 */ if (inC->NbOfStates > 8) {
    NbOfStates_saturated = 8;
  }
  else /* 1 */ if (inC->NbOfStates > 1) {
    NbOfStates_saturated = inC->NbOfStates;
  }
  else {
    NbOfStates_saturated = 1;
  }
  for (last_Value = 0; last_Value < 8; last_Value++) {
    outC->BarsVisible[last_Value] = last_Value < NbOfStates_saturated;
    outC->BarsAngle[last_Value] = (kcg_real) last_Value * 360.0 / (kcg_real)
        NbOfStates_saturated;
  }
  /* last_init_ck_Value */ if (outC->init) {
    last_State = 1;
    last_AngleKnob = 0.0;
    outC->init = kcg_false;
    last_Value = 1;
  }
  else {
    last_State = outC->State;
    last_AngleKnob = outC->AngleKnob;
    last_Value = outC->Value;
  }
  /* ck_Enabled */ if (inC->Enabled) {
    /* init_behavior */ if (outC->init1) {
      behavior_state_sel_IfBlock = _7_SSM_st_StBy_IfBlock_behavior;
    }
    else {
      behavior_state_sel_IfBlock = outC->behavior_state_nxt_IfBlock;
    }
    /* sel_behavior */ switch (behavior_state_sel_IfBlock) {
      case _8_SSM_st_Change_IfBlock_behavior :
        if (inC->MouseReleased) {
          behavior_state_act_IfBlock = SSM_st_Magnet_IfBlock_behavior;
        }
        else {
          behavior_state_act_IfBlock = _8_SSM_st_Change_IfBlock_behavior;
        }
        break;
      case _7_SSM_st_StBy_IfBlock_behavior :
        if (inC->MousePressed & inC->Inside) {
          behavior_state_act_IfBlock = _8_SSM_st_Change_IfBlock_behavior;
        }
        else {
          behavior_state_act_IfBlock = _7_SSM_st_StBy_IfBlock_behavior;
        }
        break;
      case SSM_st_Magnet_IfBlock_behavior :
        behavior_state_act_IfBlock = _7_SSM_st_StBy_IfBlock_behavior;
        break;
      
    }
    /* act_behavior */ switch (behavior_state_act_IfBlock) {
      case SSM_st_Magnet_IfBlock_behavior :
        outC->State = last_State;
        tmp = kcg_false;
        lValue_IfBlock_behavior_Magnet = (kcg_int)
            ((last_AngleKnob + 360.0 / ((kcg_real) NbOfStates_saturated *
                  2.0)) / (360.0 / (kcg_real) NbOfStates_saturated));
        outC->AngleKnob = (kcg_real) lValue_IfBlock_behavior_Magnet * 360.0 /
          (kcg_real) NbOfStates_saturated;
        /* 5 */ if (lValue_IfBlock_behavior_Magnet == NbOfStates_saturated) {
          outC->Value = 1;
        }
        else {
          outC->Value = lValue_IfBlock_behavior_Magnet + 1;
        }
        outC->behavior_state_nxt_IfBlock = SSM_st_Magnet_IfBlock_behavior;
        break;
      case _7_SSM_st_StBy_IfBlock_behavior :
        outC->State = 1;
        tmp = kcg_false;
        outC->AngleKnob = last_AngleKnob;
        outC->Value = last_Value;
        outC->behavior_state_nxt_IfBlock = _7_SSM_st_StBy_IfBlock_behavior;
        break;
      case _8_SSM_st_Change_IfBlock_behavior :
        outC->State = 2;
        tmp = kcg_true;
        outC->AngleKnob = inC->AngleArea;
        outC->Value = last_Value;
        outC->behavior_state_nxt_IfBlock = _8_SSM_st_Change_IfBlock_behavior;
        break;
      
    }
    /* 4 */ if (inC->InsideKnob | tmp) {
      outC->KnobState = 2;
    }
    else {
      outC->KnobState = 1;
    }
    outC->init1 = kcg_false;
  }
  else {
    outC->State = last_State;
    outC->AngleKnob = last_AngleKnob;
    outC->KnobState = 1;
    outC->Value = last_Value;
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** RotarySwitch.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

