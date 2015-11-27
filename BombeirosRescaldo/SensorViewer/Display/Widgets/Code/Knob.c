/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "Knob.h"

#ifndef KCG_USER_DEFINED_INIT
void Knob_init(outC_Knob *outC)
{
  outC->init = kcg_true;
  outC->init1 = kcg_true;
  outC->behavior_state_nxt_IfBlock = SSM_st_StBy_IfBlock_behavior;
  outC->Value = 0.0;
  outC->KnobState = 0;
  outC->AngleKnob = 0.0;
  outC->State = 0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Knob_reset(outC_Knob *outC)
{
  outC->init = kcg_true;
  outC->init1 = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Knob */
void Knob(inC_Knob *inC, outC_Knob *outC)
{
  /* Knob */ kcg_real tmp4;
  /* Knob */ kcg_real tmp3;
  /* Knob */ kcg_real tmp2;
  /* Knob */ kcg_bool tmp1;
  /* Knob */ kcg_real tmp;
  /* Knob::AngleKnob */ kcg_real last_AngleKnob;
  /* Knob::Value */ kcg_real last_Value;
  /* Knob::IfBlock::then::behavior */ SSM_ST_behavior_IfBlock behavior_state_sel_IfBlock;
  /* Knob::IfBlock::then::behavior */ SSM_ST_behavior_IfBlock behavior_state_act_IfBlock;
  /* Angles::Diff::Output1 */ kcg_real Output1_1_1;
  /* Math::FractionalPart::val_in */ kcg_real val_in_1_1_1_1;
  /* Math::FractionalPart::_L51 */ kcg_real _L51_1_1_1_1;
  /* Math::FractionalPart::_L45 */ kcg_real _L45_1_1_1_1;
  /* Math::RoundFloor::_L33 */ kcg_int _L33_1_1_1_1_1;
  /* Angles::Diff::Output1 */ kcg_real Output1_2_1;
  /* Math::FractionalPart::val_in */ kcg_real val_in_1_1_2_1;
  /* Math::FractionalPart::_L45 */ kcg_real _L45_1_1_2_1;
  /* Math::RoundFloor::_L33 */ kcg_int _L33_1_1_1_2_1;
  /* Angles::InRange0_359::Input1 */ kcg_real Input1_2_1;
  /* Math::RoundFloor::RF_Input */ kcg_real RF_Input_1_1_2_1;
  /* Math::RoundFloor::_L33 */ kcg_int _L33_1_1_2_1;
  /* Math::Max::Ma_Output */ kcg_real Ma_Output_1_1_2_1;
  /* Knob_::ConvertAngle::IfBlock1::else */ kcg_bool else_clock_1_IfBlock1;
  /* Knob_::ConvertAngle::IfBlock1::else::else::_L15 */ kcg_real _L15_1_IfBlock1;
  /* Knob_::ConvertAngle::IfBlock1 */ kcg_bool IfBlock1_clock_1;
  
  /* last_init_ck_AngleKnob */ if (outC->init) {
    last_AngleKnob = inC->AngleMin;
  }
  else {
    last_AngleKnob = outC->AngleKnob;
  }
  /* ck_Enabled */ if (inC->Enabled) {
    /* init_behavior */ if (outC->init1) {
      behavior_state_sel_IfBlock = SSM_st_StBy_IfBlock_behavior;
    }
    else {
      behavior_state_sel_IfBlock = outC->behavior_state_nxt_IfBlock;
    }
    /* sel_behavior */ switch (behavior_state_sel_IfBlock) {
      case SSM_st_StBy_IfBlock_behavior :
        if (inC->MousePressed & inC->Inside) {
          behavior_state_act_IfBlock = SSM_st_Change_IfBlock_behavior;
        }
        else {
          behavior_state_act_IfBlock = SSM_st_StBy_IfBlock_behavior;
        }
        break;
      case SSM_st_Change_IfBlock_behavior :
        if (inC->MouseReleased) {
          behavior_state_act_IfBlock = SSM_st_StBy_IfBlock_behavior;
        }
        else {
          behavior_state_act_IfBlock = SSM_st_Change_IfBlock_behavior;
        }
        break;
      
    }
    IfBlock1_clock_1 = inC->AngleMin == inC->AngleMax;
    /* 1_ck_IfBlock1 */ if (IfBlock1_clock_1) {
    }
    else {
      else_clock_1_IfBlock1 = inC->AngleMin < inC->AngleMax;
      /* 1_ck_anon_activ */ if (else_clock_1_IfBlock1) {
        /* 5 */ if (inC->AngleMouse >= inC->AngleMax) {
          Input1_2_1 = inC->AngleMouse - 360.0;
        }
        else /* 6 */ if (inC->AngleMouse <= inC->AngleMin) {
          Input1_2_1 = inC->AngleMouse;
        }
        else /* 7 */ if (inC->AngleMouse >= (inC->AngleMin + inC->AngleMax) /
          2.0) {
          Input1_2_1 = inC->AngleMax - 360.0;
        }
        else {
          Input1_2_1 = inC->AngleMin;
        }
        /* 1 */ if (360.0 >= 0.001) {
          Ma_Output_1_1_2_1 = 360.0;
        }
        else {
          Ma_Output_1_1_2_1 = 0.001;
        }
        RF_Input_1_1_2_1 = Input1_2_1 / Ma_Output_1_1_2_1;
        _L33_1_1_2_1 = (kcg_int) RF_Input_1_1_2_1;
      }
      else {
        val_in_1_1_1_1 = inC->AngleMouse - inC->AngleMax + 180.0;
        /* 1 */ if (360.0 >= 0.001) {
          _L51_1_1_1_1 = 360.0;
        }
        else {
          _L51_1_1_1_1 = 0.001;
        }
        _L45_1_1_1_1 = val_in_1_1_1_1 / _L51_1_1_1_1;
        _L33_1_1_1_1_1 = (kcg_int) _L45_1_1_1_1;
        /* 1 */ if (_L45_1_1_1_1 >= 0.0) {
          tmp4 = (kcg_real) _L33_1_1_1_1_1;
        }
        else /* 2 */ if ((kcg_real) _L33_1_1_1_1_1 == _L45_1_1_1_1) {
          tmp4 = (kcg_real) _L33_1_1_1_1_1;
        }
        else {
          tmp4 = (kcg_real) (kcg_int) (_L45_1_1_1_1 - 1.0);
        }
        Output1_1_1 = val_in_1_1_1_1 - tmp4 * _L51_1_1_1_1 - 180.0;
        val_in_1_1_2_1 = inC->AngleMouse - inC->AngleMin + 180.0;
        _L45_1_1_2_1 = val_in_1_1_2_1 / _L51_1_1_1_1;
        _L33_1_1_1_2_1 = (kcg_int) _L45_1_1_2_1;
        /* 1 */ if (_L45_1_1_2_1 >= 0.0) {
          tmp3 = (kcg_real) _L33_1_1_1_2_1;
        }
        else /* 2 */ if ((kcg_real) _L33_1_1_1_2_1 == _L45_1_1_2_1) {
          tmp3 = (kcg_real) _L33_1_1_1_2_1;
        }
        else {
          tmp3 = (kcg_real) (kcg_int) (_L45_1_1_2_1 - 1.0);
        }
        Output1_2_1 = val_in_1_1_2_1 - tmp3 * _L51_1_1_1_1 - 180.0;
        /* 14 */ if ((inC->AngleMouse >= inC->AngleMax) & (inC->AngleMouse <=
            inC->AngleMin)) {
          _L15_1_IfBlock1 = inC->AngleMouse;
        }
        else {
          /* 1 */ if (0. <= Output1_1_1) {
            tmp2 = Output1_1_1;
          }
          else {
            tmp2 = - Output1_1_1;
          }
          /* 1 */ if (0. <= Output1_2_1) {
            tmp = Output1_2_1;
          }
          else {
            tmp = - Output1_2_1;
          }
          /* 15 */ if (tmp2 < tmp) {
            _L15_1_IfBlock1 = inC->AngleMax;
          }
          else {
            _L15_1_IfBlock1 = inC->AngleMin;
          }
        }
      }
    }
    /* act_behavior */ switch (behavior_state_act_IfBlock) {
      case SSM_st_Change_IfBlock_behavior :
        outC->State = 2;
        tmp1 = kcg_true;
        /* 1_ck_IfBlock1 */ if (IfBlock1_clock_1) {
          outC->AngleKnob = inC->AngleMin;
        }
        else /* 1_ck_anon_activ */ if (else_clock_1_IfBlock1) {
          /* 1 */ if (RF_Input_1_1_2_1 >= 0.0) {
            last_Value = (kcg_real) _L33_1_1_2_1;
          }
          else /* 2 */ if ((kcg_real) _L33_1_1_2_1 == RF_Input_1_1_2_1) {
            last_Value = (kcg_real) _L33_1_1_2_1;
          }
          else {
            last_Value = (kcg_real) (kcg_int) (RF_Input_1_1_2_1 - 1.0);
          }
          outC->AngleKnob = Input1_2_1 - last_Value * Ma_Output_1_1_2_1;
        }
        else {
          outC->AngleKnob = _L15_1_IfBlock1;
        }
        break;
      case SSM_st_StBy_IfBlock_behavior :
        outC->State = 1;
        tmp1 = kcg_false;
        outC->AngleKnob = last_AngleKnob;
        break;
      
    }
    /* 4 */ if (inC->InsideKnob | tmp1) {
      outC->KnobState = 2;
    }
    else {
      outC->KnobState = 1;
    }
  }
  else {
    /* last_init_ck_State */ if (outC->init) {
      outC->State = 1;
    }
    outC->AngleKnob = last_AngleKnob;
    outC->KnobState = 1;
  }
  /* last_init_ck_Value */ if (outC->init) {
    outC->init = kcg_false;
    last_Value = inC->Min;
  }
  else {
    last_Value = outC->Value;
  }
  /* ck_Enabled */ if (inC->Enabled) {
    outC->init1 = kcg_false;
    /* act_behavior */ switch (behavior_state_act_IfBlock) {
      case SSM_st_StBy_IfBlock_behavior :
        outC->Value = last_Value;
        outC->behavior_state_nxt_IfBlock = SSM_st_StBy_IfBlock_behavior;
        break;
      case SSM_st_Change_IfBlock_behavior :
        /* 1_ck_IfBlock1 */ if (IfBlock1_clock_1) {
          tmp = 0.0;
        }
        else /* 1_ck_anon_activ */ if (else_clock_1_IfBlock1) {
          tmp = (- Input1_2_1 + inC->AngleMin) / (inC->AngleMin -
              inC->AngleMax + 360.0);
        }
        else {
          tmp = (- _L15_1_IfBlock1 + inC->AngleMin) / (inC->AngleMin -
              inC->AngleMax);
        }
        outC->Value = tmp * (inC->Max - inC->Min) + inC->Min;
        outC->behavior_state_nxt_IfBlock = SSM_st_Change_IfBlock_behavior;
        break;
      
    }
  }
  else {
    outC->Value = last_Value;
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Knob.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

