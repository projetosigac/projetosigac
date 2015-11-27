/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "Slider.h"

#ifndef KCG_USER_DEFINED_INIT
void Slider_init(outC_Slider *outC)
{
  outC->OutValueEmit = kcg_true;
  outC->SliderClicked = kcg_true;
  outC->init = kcg_true;
  outC->LocalOutValue = 0.0;
  outC->OutValue = 0.0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Slider_reset(outC_Slider *outC)
{
  outC->init = kcg_true;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* Slider */
void Slider(inC_Slider *inC, outC_Slider *outC)
{
  /* Slider */ kcg_real tmp5;
  /* Slider */ kcg_real tmp4;
  /* Slider */ kcg_real tmp3;
  /* Slider */ kcg_real tmp2;
  /* Slider */ kcg_real tmp1;
  /* Slider */ kcg_real tmp;
  /* Slider::IfBlock_SelectedValue::then */ kcg_bool then_clock_IfBlock_SelectedValue;
  /* Slider::IfBlock_SelectedValue::then::else::then::ValueToRound */ kcg_real _9_ValueToRound_IfBlock_SelectedValue;
  /* Slider::IfBlock_SelectedValue::then::else::else */ kcg_bool _7_else_clock_IfBlock_SelectedValue;
  /* Slider::IfBlock_SelectedValue::then::else::else::else::ValueToRound */ kcg_real _11_ValueToRound_IfBlock_SelectedValue;
  /* Slider::IfBlock_SelectedValue::then::else::else::then::ValueToRound */ kcg_real _10_ValueToRound_IfBlock_SelectedValue;
  /* Slider::IfBlock_SelectedValue::then::else */ kcg_bool _8_else_clock_IfBlock_SelectedValue;
  /* Slider::IfBlock_SelectedValue::then::then::ValueToRound */ kcg_real ValueToRound_IfBlock_SelectedValue;
  /* Slider::IfBlock_SelectedValue::else */ kcg_bool _6_else_clock_IfBlock_SelectedValue;
  /* Slider::IfBlock_SelectedValue::else::else */ kcg_bool else_clock_IfBlock_SelectedValue;
  /* Slider::inValueRounded */ kcg_real inValueRounded;
  /* Slider::lastOutValue */ kcg_real lastOutValue;
  /* Slider::WheelDelta */ kcg_real WheelDelta;
  /* Slider::_L53 */ kcg_bool _L53;
  
  /* 1_fby_1_init_1 */ if (outC->init) {
    _L53 = kcg_false;
  }
  else {
    _L53 = outC->SliderClicked;
  }
  outC->SliderClicked = (inC->MousePressed & (inC->MouseButton ==
        CLICKBUTTON_Pointer) & inC->MouseInside) | (!inC->MouseReleased & _L53);
  _L53 = inC->ValueDelta != 0.0;
  /* 12 */ if (_L53) {
    /* 1 */ if (inC->Value >= 0.0) {
      lastOutValue = inC->Value + inC->ValueDelta / 2.0;
    }
    else {
      lastOutValue = inC->Value - inC->ValueDelta / 2.0;
    }
    inValueRounded = (kcg_real) (kcg_int) (lastOutValue / inC->ValueDelta) *
      inC->ValueDelta;
    WheelDelta = inC->ValueDelta;
  }
  else {
    inValueRounded = inC->Value;
    WheelDelta = (inC->MaxValue - inC->MinValue) / 10.0;
  }
  /* fby_1_init_1 */ if (outC->init) {
    lastOutValue = inValueRounded;
  }
  else {
    lastOutValue = outC->OutValue;
  }
  /* ck_SliderClicked */ if (outC->SliderClicked) {
    then_clock_IfBlock_SelectedValue = inC->Orientation == 2;
    /* ck_anon_activ */ if (then_clock_IfBlock_SelectedValue) {
      ValueToRound_IfBlock_SelectedValue = (inC->MaxValue - inC->MinValue) *
        (1.0 - inC->ClickedValueX) + inC->MinValue;
      /* 16 */ if (inC->ValueDelta != 0.0) {
        /* 1 */ if (ValueToRound_IfBlock_SelectedValue >= 0.0) {
          tmp2 = ValueToRound_IfBlock_SelectedValue + inC->ValueDelta / 2.0;
        }
        else {
          tmp2 = ValueToRound_IfBlock_SelectedValue - inC->ValueDelta / 2.0;
        }
        outC->LocalOutValue = (kcg_real) (kcg_int) (tmp2 / inC->ValueDelta) *
          inC->ValueDelta;
      }
      else {
        outC->LocalOutValue = ValueToRound_IfBlock_SelectedValue;
      }
      outC->OutValueEmit = outC->LocalOutValue != lastOutValue;
    }
    else {
      _8_else_clock_IfBlock_SelectedValue = inC->Orientation == 3;
      /* ck_anon_activ */ if (_8_else_clock_IfBlock_SelectedValue) {
        _9_ValueToRound_IfBlock_SelectedValue = (inC->MaxValue -
            inC->MinValue) * inC->ClickedValueY + inC->MinValue;
        /* 17 */ if (inC->ValueDelta != 0.0) {
          /* 1 */ if (_9_ValueToRound_IfBlock_SelectedValue >= 0.0) {
            tmp3 = _9_ValueToRound_IfBlock_SelectedValue + inC->ValueDelta /
              2.0;
          }
          else {
            tmp3 = _9_ValueToRound_IfBlock_SelectedValue - inC->ValueDelta /
              2.0;
          }
          outC->LocalOutValue = (kcg_real) (kcg_int) (tmp3 / inC->ValueDelta) *
            inC->ValueDelta;
        }
        else {
          outC->LocalOutValue = _9_ValueToRound_IfBlock_SelectedValue;
        }
        outC->OutValueEmit = outC->LocalOutValue != lastOutValue;
      }
      else {
        _7_else_clock_IfBlock_SelectedValue = inC->Orientation == 4;
        /* ck_anon_activ */ if (_7_else_clock_IfBlock_SelectedValue) {
          _10_ValueToRound_IfBlock_SelectedValue = (inC->MaxValue -
              inC->MinValue) * (1.0 - inC->ClickedValueY) + inC->MinValue;
          /* 18 */ if (inC->ValueDelta != 0.0) {
            /* 1 */ if (_10_ValueToRound_IfBlock_SelectedValue >= 0.0) {
              tmp4 = _10_ValueToRound_IfBlock_SelectedValue + inC->ValueDelta /
                2.0;
            }
            else {
              tmp4 = _10_ValueToRound_IfBlock_SelectedValue - inC->ValueDelta /
                2.0;
            }
            outC->LocalOutValue = (kcg_real)
                (kcg_int) (tmp4 / inC->ValueDelta) * inC->ValueDelta;
          }
          else {
            outC->LocalOutValue = _10_ValueToRound_IfBlock_SelectedValue;
          }
          outC->OutValueEmit = outC->LocalOutValue != lastOutValue;
        }
        else {
          _11_ValueToRound_IfBlock_SelectedValue = (inC->MaxValue -
              inC->MinValue) * inC->ClickedValueX + inC->MinValue;
          /* 19 */ if (inC->ValueDelta != 0.0) {
            /* 1 */ if (_11_ValueToRound_IfBlock_SelectedValue >= 0.0) {
              tmp5 = _11_ValueToRound_IfBlock_SelectedValue + inC->ValueDelta /
                2.0;
            }
            else {
              tmp5 = _11_ValueToRound_IfBlock_SelectedValue - inC->ValueDelta /
                2.0;
            }
            outC->LocalOutValue = (kcg_real)
                (kcg_int) (tmp5 / inC->ValueDelta) * inC->ValueDelta;
          }
          else {
            outC->LocalOutValue = _11_ValueToRound_IfBlock_SelectedValue;
          }
          outC->OutValueEmit = outC->LocalOutValue != lastOutValue;
        }
      }
    }
  }
  else {
    _6_else_clock_IfBlock_SelectedValue = inC->SetValue & (inC->Value <=
        inC->MaxValue) & (inC->Value >= inC->MinValue);
    /* ck_anon_activ */ if (_6_else_clock_IfBlock_SelectedValue) {
      outC->OutValueEmit = kcg_false;
      outC->LocalOutValue = inValueRounded;
    }
    else {
      else_clock_IfBlock_SelectedValue = inC->MousePressed &
        (inC->MouseButton == UPWHEEL_Pointer) & inC->MouseInside;
      /* ck_anon_activ */ if (else_clock_IfBlock_SelectedValue) {
        outC->OutValueEmit = kcg_true;
        /* 13 */ if ((inC->Orientation == 4) | (inC->Orientation == 2)) {
          tmp1 = - WheelDelta;
        }
        else {
          tmp1 = WheelDelta;
        }
        outC->LocalOutValue = lastOutValue + tmp1;
      }
      else {
        _L53 = inC->MousePressed & (inC->MouseButton == DOWNWHEEL_Pointer) &
          inC->MouseInside;
        /* ck_anon_activ */ if (_L53) {
          outC->OutValueEmit = kcg_true;
          /* 14 */ if ((inC->Orientation == 4) | (inC->Orientation == 2)) {
            tmp = WheelDelta;
          }
          else {
            tmp = - WheelDelta;
          }
          outC->LocalOutValue = lastOutValue + tmp;
        }
        else {
          outC->OutValueEmit = kcg_false;
          /* last_init_ck_LocalOutValue */ if (outC->init) {
            outC->LocalOutValue = inValueRounded;
          }
        }
      }
    }
  }
  outC->init = kcg_false;
  /* 2 */ if (outC->LocalOutValue > inC->MaxValue) {
    outC->OutValue = inC->MaxValue;
  }
  else /* 1 */ if (outC->LocalOutValue > inC->MinValue) {
    outC->OutValue = outC->LocalOutValue;
  }
  else {
    outC->OutValue = inC->MinValue;
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** Slider.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

