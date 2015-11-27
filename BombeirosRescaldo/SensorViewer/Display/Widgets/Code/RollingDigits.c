/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "RollingDigits.h"

#ifndef KCG_USER_DEFINED_INIT
void RollingDigits_init(outC_RollingDigits *outC)
{
  kcg_int i;
  
  for (i = 0; i < 16; i++) {
    outC->TextRoll[i] = 0.0;
    outC->PosRoll[i] = 0.0;
  }
  outC->NbDigitsRolling = 0;
  for (i = 0; i < 6; i++) {
    outC->Char2[i][0] = ' ';
    outC->Char1[i][0] = ' ';
    outC->Pos2[i] = 0.0;
    outC->Pos1[i] = 0.0;
  }
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void RollingDigits_reset(outC_RollingDigits *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* RollingDigits */
void RollingDigits(inC_RollingDigits *inC, outC_RollingDigits *outC)
{
  /* RollingDigits */ kcg_real tmp3;
  /* RollingDigits */ array_int_6 tmp;
  /* RollingDigits */ kcg_bool acc;
  kcg_int i;
  /* RollingDigits_::OneFallingDigit::_L7 */ kcg_int _L7_1_1;
  /* RollingDigits_::OneFallingDigit::IfBlock1 */ kcg_bool IfBlock1_clock_1_1;
  /* RollingDigits_::OneFallingDigit::IfBlock1::else::then */ kcg_bool _2_then_clock_1_1_IfBlock1;
  /* RollingDigits_::OneFallingDigit::IfBlock1::else::else */ kcg_bool _1_else_clock_1_1_IfBlock1;
  /* RollingDigits_::OneFallingDigit::IfBlock1::else */ kcg_bool else_clock_1_1_IfBlock1;
  /* RollingDigits_::OneFallingDigit::IfBlock1::then */ kcg_bool then_clock_1_1_IfBlock1;
  /* RollingDigits_::FallingPart::_L8 */ kcg_real _L8_1;
  kcg_bool noname_1;
  /* RollingDigits_::GetDigits::_L1 */ kcg_int _L1_1_1;
  /* RollingDigits_::GetDigits::digits */ array_int_6 digits_1_1;
  /* RollingDigits_::RoundRemainHalf::round */ kcg_int round_1_1;
  /* Math::RoundFloor::RF_Input */ kcg_real RF_Input_1_1;
  /* RollingDigits_::FallingPart */ kcg_bool powered_exp_1;
  /* RollingDigits_::RollingPart::_L7 */ array_real_16 _L7_1;
  
  (&tmp[0])[0] = 0;
  tmp3 = inC->Mult * (kcg_real) (kcg_int) (inC->Value / inC->Mult);
  _L8_1 = inC->FontSize * ((inC->Value - tmp3) / inC->Mult);
  RF_Input_1_1 = (kcg_real) NbRollingLines_RollingDigits_ / 2.0;
  /* 1 */ for (i = 0; i < 16; i++) {
    _L7_1[i] = RF_Input_1_1 - (kcg_real) i;
  }
  /* 1 */ for (i = 0; i < 16; i++) {
    outC->PosRoll[i] = _L7_1[i] * inC->FontSize - _L8_1;
    outC->TextRoll[i] = tmp3 + _L7_1[i] * inC->Mult;
  }
  RF_Input_1_1 = /* 1_1 */ wid_LogR(inC->Mult);
  round_1_1 = (kcg_int) RF_Input_1_1;
  powered_exp_1 = inC->Value < 0.0;
  /* 1 */ if (RF_Input_1_1 >= 0.0) {
    outC->NbDigitsRolling = round_1_1 + 1;
  }
  else /* 2 */ if ((kcg_real) round_1_1 == RF_Input_1_1) {
    outC->NbDigitsRolling = round_1_1 + 1;
  }
  else {
    outC->NbDigitsRolling = (kcg_int) (RF_Input_1_1 - 1.0) + 1;
  }
  _L8_1 = /* 1_1 */ wid_PowerR(10.0, outC->NbDigitsRolling);
  /* 1 */ if (powered_exp_1) {
    tmp3 = - inC->Value;
  }
  else {
    tmp3 = inC->Value;
  }
  RF_Input_1_1 = tmp3 / _L8_1;
  round_1_1 = (kcg_int) (RF_Input_1_1 + 0.5);
  _L1_1_1 = round_1_1;
  /* 1_1 */ for (i = 0; i < 6; i++) {
    _L7_1_1 = _L1_1_1;
    _L1_1_1 = _L7_1_1 / 10;
    digits_1_1[i] = _L7_1_1 % 10;
  }
  tmp3 = (RF_Input_1_1 - (kcg_real) round_1_1) / (inC->Mult / _L8_1 * 10.0);
  kcg_copy_array_int_5(&tmp[1], (array_int_5 *) &digits_1_1[0]);
  noname_1 = RF_Input_1_1 >= 0.5;
  /* 1 */ for (i = 0; i < 6; i++) {
    acc = noname_1;
    IfBlock1_clock_1_1 = tmp3 > 0.0;
    /* ck_IfBlock1 */ if (IfBlock1_clock_1_1) {
      then_clock_1_1_IfBlock1 = (tmp[i] == 0) & acc;
      /* ck_anon_activ */ if (then_clock_1_1_IfBlock1) {
        noname_1 = kcg_true;
        _L8_1 = 0.0;
        RF_Input_1_1 = 10.0 * inC->FontSize * (- tmp3 - 0.1);
      }
      else {
        noname_1 = kcg_false;
        _L8_1 = 0.0;
        RF_Input_1_1 = inC->FontSize * 10.0 * 20.0;
      }
    }
    else {
      else_clock_1_1_IfBlock1 = tmp3 > - 0.1;
      /* ck_anon_activ */ if (else_clock_1_1_IfBlock1) {
        _2_then_clock_1_1_IfBlock1 = (tmp[i] == 0) & acc;
        /* ck_anon_activ */ if (_2_then_clock_1_1_IfBlock1) {
          noname_1 = kcg_true;
          _L8_1 = 10.0 * inC->FontSize * - tmp3;
          RF_Input_1_1 = 10.0 * inC->FontSize * (- tmp3 - 0.1);
        }
        else {
          noname_1 = kcg_false;
          _L8_1 = 0.0;
          RF_Input_1_1 = inC->FontSize * 10.0 * 20.0;
        }
      }
      else {
        _1_else_clock_1_1_IfBlock1 = (tmp[i] == 0) & acc;
        /* ck_anon_activ */ if (_1_else_clock_1_1_IfBlock1) {
          noname_1 = kcg_true;
          _L8_1 = 10.0 * inC->FontSize * - tmp3;
          RF_Input_1_1 = 0.0;
        }
        else {
          noname_1 = kcg_false;
          _L8_1 = 0.0;
          RF_Input_1_1 = - inC->FontSize * 10.0 * 20.0;
        }
      }
    }
    /* 4 */ if (powered_exp_1) {
      outC->Pos1[i] = - _L8_1;
      outC->Pos2[i] = - RF_Input_1_1;
    }
    else {
      outC->Pos1[i] = _L8_1;
      outC->Pos2[i] = RF_Input_1_1;
    }
    _L7_1_1 = digits_1_1[i] - 1;
    if (digits_1_1[i] == - 2) {
      outC->Char1[i][0] = '8';
    }
    else if (digits_1_1[i] == - 1) {
      outC->Char1[i][0] = '9';
    }
    else if (digits_1_1[i] == 0) {
      outC->Char1[i][0] = '0';
    }
    else if (digits_1_1[i] == 1) {
      outC->Char1[i][0] = '1';
    }
    else if (digits_1_1[i] == 2) {
      outC->Char1[i][0] = '2';
    }
    else if (digits_1_1[i] == 3) {
      outC->Char1[i][0] = '3';
    }
    else if (digits_1_1[i] == 4) {
      outC->Char1[i][0] = '4';
    }
    else if (digits_1_1[i] == 5) {
      outC->Char1[i][0] = '5';
    }
    else if (digits_1_1[i] == 6) {
      outC->Char1[i][0] = '6';
    }
    else if (digits_1_1[i] == 7) {
      outC->Char1[i][0] = '7';
    }
    else if (digits_1_1[i] == 8) {
      outC->Char1[i][0] = '8';
    }
    else if (digits_1_1[i] == 9) {
      outC->Char1[i][0] = '9';
    }
    else {
      outC->Char1[i][0] = '0';
    }
    if (_L7_1_1 == - 2) {
      outC->Char2[i][0] = '8';
    }
    else if (_L7_1_1 == - 1) {
      outC->Char2[i][0] = '9';
    }
    else if (_L7_1_1 == 0) {
      outC->Char2[i][0] = '0';
    }
    else if (_L7_1_1 == 1) {
      outC->Char2[i][0] = '1';
    }
    else if (_L7_1_1 == 2) {
      outC->Char2[i][0] = '2';
    }
    else if (_L7_1_1 == 3) {
      outC->Char2[i][0] = '3';
    }
    else if (_L7_1_1 == 4) {
      outC->Char2[i][0] = '4';
    }
    else if (_L7_1_1 == 5) {
      outC->Char2[i][0] = '5';
    }
    else if (_L7_1_1 == 6) {
      outC->Char2[i][0] = '6';
    }
    else if (_L7_1_1 == 7) {
      outC->Char2[i][0] = '7';
    }
    else if (_L7_1_1 == 8) {
      outC->Char2[i][0] = '8';
    }
    else if (_L7_1_1 == 9) {
      outC->Char2[i][0] = '9';
    }
    else {
      outC->Char2[i][0] = '0';
    }
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** RollingDigits.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

