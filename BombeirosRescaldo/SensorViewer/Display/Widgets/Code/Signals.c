/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "Signals.h"

#ifndef KCG_USER_DEFINED_INIT
void Signals_init(outC_Signals *outC)
{
  outC->IsRealTime = kcg_true;
  outC->init1 = kcg_true;
  outC->init = kcg_true;
  outC->_L27 = 0;
  outC->_L10_1 = 0;
  outC->Value = 0.0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Signals_reset(outC_Signals *outC)
{
  outC->init1 = kcg_true;
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Signals */
void Signals(inC_Signals *inC, outC_Signals *outC)
{
  /* Signals */ kcg_real tmp;
  /* Math::Max::Ma_Output */ kcg_real Ma_Output_1_1;
  /* Math::RoundFloor::_L33 */ kcg_int _L33_1_1;
  /* Math::RoundFloor::RF_Input */ kcg_real RF_Input_1_1;
  /* Signals */ kcg_int op_call;
  /* Signals::IfBlock1::then::_L9 */ kcg_real _L9_IfBlock1;
  /* Signals::IfBlock1::else */ kcg_bool _1_else_clock_IfBlock1;
  /* Signals::IfBlock1::else::else::then::_L7 */ kcg_real _L7_IfBlock1;
  /* Signals::IfBlock1::else::else::then::TimeWithOffset */ kcg_real TimeWithOffset_IfBlock1;
  /* Signals::IfBlock1::else::else */ kcg_bool else_clock_IfBlock1;
  /* Signals::IfBlock1 */ kcg_bool IfBlock1_clock;
  /* Signals::Amplitude */ kcg_real Amplitude;
  /* Signals::localPeriodCycles */ kcg_int localPeriodCycles;
  /* Signals::TimeInPeriod */ kcg_real TimeInPeriod;
  /* Signals::_L17 */ kcg_real _L17;
  
  Amplitude = inC->Max - inC->Min;
  /* 1 */ if (inC->PeriodCycles > 1) {
    localPeriodCycles = inC->PeriodCycles;
  }
  else {
    localPeriodCycles = 100;
  }
  _L17 = (kcg_real) localPeriodCycles;
  /* ck_Signals */ if (BHVR_AsynchronousACK) {
    /* 1_fby_1_init_2 */ if (outC->init) {
      _L33_1_1 = 0;
    }
    else {
      _L33_1_1 = outC->_L10_1;
    }
    /* 1 */ if (_L33_1_1 >= localPeriodCycles) {
      op_call = 0;
    }
    else {
      op_call = _L33_1_1;
    }
    outC->_L27 = op_call;
    outC->init = kcg_false;
    outC->_L10_1 = 1 + op_call;
  }
  else if (outC->init1) {
    outC->_L27 = 0;
  }
  TimeInPeriod = (kcg_real) outC->_L27 / _L17;
  /* 1 */ if (outC->init1) {
    outC->init1 = kcg_false;
    outC->IsRealTime = kcg_false;
  }
  else {
    outC->IsRealTime = kcg_true;
  }
  IfBlock1_clock = inC->Kind == 1;
  /* ck_IfBlock1 */ if (IfBlock1_clock) {
    _L9_IfBlock1 = Amplitude / 2.;
    outC->Value = /* 2 */ wid_SinR(TimeInPeriod * TAU_Signals_) * _L9_IfBlock1 +
      (_L9_IfBlock1 + inC->Min);
  }
  else {
    _1_else_clock_IfBlock1 = inC->Kind == 2;
    /* ck_anon_activ */ if (_1_else_clock_IfBlock1) {
      /* 3 */ if (TimeInPeriod < inC->DutyCycle) {
        outC->Value = inC->Max;
      }
      else {
        outC->Value = inC->Min;
      }
    }
    else {
      else_clock_IfBlock1 = inC->Kind == 3;
      /* ck_anon_activ */ if (else_clock_IfBlock1) {
        _L7_IfBlock1 = (inC->Offset - inC->Min) / Amplitude * 0.5 +
          TimeInPeriod;
        /* 1 */ if (1.0 >= 0.001) {
          Ma_Output_1_1 = 1.0;
        }
        else {
          Ma_Output_1_1 = 0.001;
        }
        RF_Input_1_1 = _L7_IfBlock1 / Ma_Output_1_1;
        _L33_1_1 = (kcg_int) RF_Input_1_1;
        /* 1 */ if (RF_Input_1_1 >= 0.0) {
          tmp = (kcg_real) _L33_1_1;
        }
        else /* 2 */ if ((kcg_real) _L33_1_1 == RF_Input_1_1) {
          tmp = (kcg_real) _L33_1_1;
        }
        else {
          tmp = (kcg_real) (kcg_int) (RF_Input_1_1 - 1.0);
        }
        TimeWithOffset_IfBlock1 = _L7_IfBlock1 - tmp * Ma_Output_1_1;
        /* 4 */ if (TimeWithOffset_IfBlock1 >= 0.5) {
          outC->Value = Amplitude * - (TimeWithOffset_IfBlock1 - 0.5) * 2.0 +
            inC->Max;
        }
        else {
          outC->Value = Amplitude * TimeWithOffset_IfBlock1 * 2.0 + inC->Min;
        }
      }
      else {
        outC->Value = (Amplitude * TimeInPeriod + inC->Min) * (_L17 / (kcg_real)
              (localPeriodCycles - 1));
      }
    }
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Signals.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

