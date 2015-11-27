/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:14
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "Animations.h"

#ifndef KCG_USER_DEFINED_INIT
void Animations_init(outC_Animations *outC)
{
  outC->End = kcg_true;
  outC->init4 = kcg_true;
  outC->init3 = kcg_true;
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  outC->Progress = 0.0;
  outC->SM1_state_nxt = SSM_st_Wait_SM1;
  outC->_L13_SM1_Backward = 0;
  outC->_L1_SM1_Forward = 0;
  outC->_L10_1 = 0;
  outC->_L10_4 = 0;
  outC->Opacity = 0;
  outC->ValueReal = 0.0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Animations_reset(outC_Animations *outC)
{
  outC->init4 = kcg_true;
  outC->init3 = kcg_true;
  outC->init2 = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Animations */
void Animations(inC_Animations *inC, outC_Animations *outC)
{
  /* Util::CyclicCounter::_L9 */ kcg_int _L9_4;
  /* Math::RoundFloor::_L33 */ kcg_int _L33_1_1;
  /* Math::RoundFloor::RF_Input */ kcg_real RF_Input_1_1;
  /* Animations */ kcg_int _1_op_call;
  /* Animations */ kcg_int op_call;
  /* Animations::Laws::else */ kcg_bool _3_else_clock_Laws;
  /* Animations::Laws::else::else::else */ kcg_bool else_clock_Laws;
  /* Animations::Laws::else::else */ kcg_bool _2_else_clock_Laws;
  /* Animations::SM1::Forward::_L5 */ kcg_real _L5_SM1_Forward;
  /* Animations::SM1::Forward::_L4 */ kcg_real _L4_SM1_Forward;
  /* Animations::Laws */ kcg_bool Laws_clock;
  /* Animations::SM1 */ SSM_ST_SM1 SM1_state_sel;
  /* Animations::SM1 */ SSM_ST_SM1 SM1_state_act;
  /* Animations::SM1 */ SSM_TR_SM1 SM1_fired_strong;
  /* Animations::Val */ kcg_real Val;
  
  /* init_SM1 */ if (outC->init4) {
    SM1_state_sel = SSM_st_Wait_SM1;
  }
  else {
    SM1_state_sel = outC->SM1_state_nxt;
  }
  /* sel_SM1 */ switch (SM1_state_sel) {
    case SSM_st_Backward_SM1 :
      SM1_state_act = SSM_st_Backward_SM1;
      _3_else_clock_Laws = kcg_false;
      SM1_fired_strong = SSM_TR_no_trans_SM1;
      break;
    case SSM_st_Forward_SM1 :
      SM1_state_act = SSM_st_Forward_SM1;
      _3_else_clock_Laws = kcg_false;
      SM1_fired_strong = SSM_TR_no_trans_SM1;
      break;
    case SSM_st_Wait_SM1 :
      if (inC->StartForward) {
        SM1_state_act = SSM_st_Forward_SM1;
        _3_else_clock_Laws = kcg_true;
        SM1_fired_strong = SSM_TR_Wait_1_SM1;
      }
      else {
        _3_else_clock_Laws = inC->StartBackward;
        if (inC->StartBackward) {
          SM1_state_act = SSM_st_Backward_SM1;
          SM1_fired_strong = SSM_TR_Wait_2_SM1;
        }
        else {
          SM1_state_act = SSM_st_Wait_SM1;
          SM1_fired_strong = SSM_TR_no_trans_SM1;
        }
      }
      break;
    
  }
  /* act_SM1 */ switch (SM1_state_act) {
    case SSM_st_Backward_SM1 :
      RF_Input_1_1 = (kcg_real) inC->TimeLength / (kcg_real) inC->CycleDuration;
      if (_3_else_clock_Laws) {
        outC->init = kcg_true;
        outC->init2 = kcg_true;
      }
      /* ck__L22 */ if (BHVR_AsynchronousACK) {
        /* 4_fby_1_init_2 */ if (outC->init) {
          _L9_4 = 0;
        }
        else {
          _L9_4 = outC->_L10_4;
        }
        /* 1 */ if (_L9_4 >= (kcg_int) RF_Input_1_1 + 2) {
          _1_op_call = 0;
        }
        else {
          _1_op_call = _L9_4;
        }
        outC->_L13_SM1_Backward = _1_op_call;
        outC->init = kcg_false;
        /* 4_ck_CyclicCounter */ if (BHVR_AsynchronousACK) {
          outC->_L10_4 = 1 + _1_op_call;
        }
        else {
          outC->_L10_4 = _1_op_call;
        }
      }
      else if (outC->init2) {
        outC->_L13_SM1_Backward = 0;
      }
      Val = 1.0 - (kcg_real) outC->_L13_SM1_Backward / RF_Input_1_1;
      /* 2 */ if (Val > 1.0) {
        outC->Progress = 1.0;
      }
      else /* 1 */ if (Val > 0.0) {
        outC->Progress = Val;
      }
      else {
        outC->Progress = 0.0;
      }
      Laws_clock = outC->Progress <= 0.0;
      else_clock_Laws = SM1_fired_strong != SSM_TR_no_trans_SM1;
      /* strong_fired_Backward */ if (else_clock_Laws) {
        outC->End = kcg_false;
        outC->SM1_state_nxt = SSM_st_Backward_SM1;
      }
      else if (Laws_clock) {
        outC->End = kcg_true;
        outC->SM1_state_nxt = SSM_st_Wait_SM1;
      }
      else {
        outC->End = kcg_false;
        outC->SM1_state_nxt = SSM_st_Backward_SM1;
      }
      outC->init2 = kcg_false;
      break;
    case SSM_st_Forward_SM1 :
      if (_3_else_clock_Laws) {
        outC->init1 = kcg_true;
        outC->init3 = kcg_true;
      }
      _L5_SM1_Forward = (kcg_real) inC->TimeLength / (kcg_real)
          inC->CycleDuration;
      /* ck__L10 */ if (BHVR_AsynchronousACK) {
        /* 1_fby_1_init_2 */ if (outC->init1) {
          _L33_1_1 = 0;
        }
        else {
          _L33_1_1 = outC->_L10_1;
        }
        /* 1 */ if (_L33_1_1 >= (kcg_int) _L5_SM1_Forward + 2) {
          op_call = 0;
        }
        else {
          op_call = _L33_1_1;
        }
        outC->_L1_SM1_Forward = op_call;
        outC->init1 = kcg_false;
        /* 1_ck_CyclicCounter */ if (BHVR_AsynchronousACK) {
          outC->_L10_1 = 1 + op_call;
        }
        else {
          outC->_L10_1 = op_call;
        }
      }
      else if (outC->init3) {
        outC->_L1_SM1_Forward = 0;
      }
      _L4_SM1_Forward = (kcg_real) outC->_L1_SM1_Forward / _L5_SM1_Forward;
      /* 2 */ if (_L4_SM1_Forward > 1.0) {
        outC->Progress = 1.0;
      }
      else /* 1 */ if (_L4_SM1_Forward > 0.0) {
        outC->Progress = _L4_SM1_Forward;
      }
      else {
        outC->Progress = 0.0;
      }
      Laws_clock = outC->Progress >= 1.0;
      _2_else_clock_Laws = SM1_fired_strong != SSM_TR_no_trans_SM1;
      /* strong_fired_Forward */ if (_2_else_clock_Laws) {
        outC->End = kcg_false;
        outC->SM1_state_nxt = SSM_st_Forward_SM1;
      }
      else if (Laws_clock) {
        outC->End = kcg_true;
        outC->SM1_state_nxt = SSM_st_Wait_SM1;
      }
      else {
        outC->End = kcg_false;
        outC->SM1_state_nxt = SSM_st_Forward_SM1;
      }
      outC->init3 = kcg_false;
      break;
    case SSM_st_Wait_SM1 :
      outC->End = kcg_false;
      /* last_init_ck_Progress */ if (outC->init4) {
        outC->Progress = 0.0;
      }
      outC->SM1_state_nxt = SSM_st_Wait_SM1;
      break;
    
  }
  outC->init4 = kcg_false;
  Laws_clock = inC->Law == 1;
  /* ck_Laws */ if (Laws_clock) {
    Val = outC->Progress;
  }
  else {
    _3_else_clock_Laws = inC->Law == 2;
    /* ck_anon_activ */ if (_3_else_clock_Laws) {
      Val = - outC->Progress * outC->Progress + 2.0 * outC->Progress;
    }
    else {
      _2_else_clock_Laws = inC->Law == 3;
      /* ck_anon_activ */ if (_2_else_clock_Laws) {
        Val = - 2.4 * (outC->Progress * outC->Progress * outC->Progress) + 2.3 *
          (outC->Progress * outC->Progress) + 1.1 * outC->Progress;
      }
      else {
        else_clock_Laws = inC->Law == 4;
        /* ck_anon_activ */ if (else_clock_Laws) {
          Val = - 6.0 * outC->Progress * outC->Progress * outC->Progress + 9.0 *
            outC->Progress * outC->Progress - 2.0 * outC->Progress;
        }
        else {
          Val = - 2.0 * outC->Progress * outC->Progress * outC->Progress + 3.0 *
            outC->Progress * outC->Progress;
        }
      }
    }
  }
  /* 2 */ if (inC->InverseResult) {
    outC->ValueReal = 1.0 - Val;
  }
  else {
    outC->ValueReal = Val;
  }
  /* 2 */ if (outC->ValueReal > 1.0) {
    RF_Input_1_1 = 255.0 * 1.0 + 0.5;
  }
  else /* 1 */ if (outC->ValueReal > 0.0) {
    RF_Input_1_1 = 255.0 * outC->ValueReal + 0.5;
  }
  else {
    RF_Input_1_1 = 255.0 * 0.0 + 0.5;
  }
  _L33_1_1 = (kcg_int) RF_Input_1_1;
  /* 1 */ if (RF_Input_1_1 >= 0.0) {
    outC->Opacity = _L33_1_1;
  }
  else /* 2 */ if ((kcg_real) _L33_1_1 == RF_Input_1_1) {
    outC->Opacity = _L33_1_1;
  }
  else {
    outC->Opacity = (kcg_int) (RF_Input_1_1 - 1.0);
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Animations.c
** Generation date: 2014-11-28T14:01:14
*************************************************************$ */

