/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "PiecewiseTranslation.h"

#ifndef KCG_USER_DEFINED_INIT
void PiecewiseTranslation_init(outC_PiecewiseTranslation *outC)
{
  outC->y = 0.0;
  outC->x = 0.0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void PiecewiseTranslation_reset(outC_PiecewiseTranslation *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* PiecewiseTranslation */
void PiecewiseTranslation(
  inC_PiecewiseTranslation *inC,
  outC_PiecewiseTranslation *outC)
{
  /* PiecewiseTranslation */ kcg_real tmp6;
  /* PiecewiseTranslation */ array_bool_15 tmp5;
  kcg_int i;
  /* PiecewiseTranslation */ kcg_real tmp4;
  /* PiecewiseTranslation */ kcg_real tmp3;
  /* PiecewiseTranslation */ kcg_real tmp2;
  /* PiecewiseTranslation */ kcg_real tmp1;
  /* PiecewiseTranslation */ kcg_real tmp;
  /* PiecewiseTranslation::IfBlock1 */ kcg_bool IfBlock1_clock;
  /* PiecewiseTranslation::IfBlock1::else::else::_L19 */ kcg_int _L19_IfBlock1;
  /* PiecewiseTranslation::IfBlock1::else::else::_L15 */ kcg_real _L15_IfBlock1;
  /* PiecewiseTranslation::IfBlock1::else::else::_L12 */ kcg_real _L12_IfBlock1;
  /* PiecewiseTranslation::IfBlock1::else::else::_L11 */ kcg_real _L11_IfBlock1;
  /* PiecewiseTranslation::IfBlock1::else::else::_L10 */ kcg_real _L10_IfBlock1;
  /* PiecewiseTranslation::IfBlock1::else::else::index */ kcg_int index_IfBlock1;
  /* PiecewiseTranslation::IfBlock1::else */ kcg_bool else_clock_IfBlock1;
  /* PiecewiseTranslation::Interpolate::IfBlock1 */ kcg_bool IfBlock1_clock_3;
  /* PiecewiseTranslation::Interpolate::IfBlock1 */ kcg_bool IfBlock1_clock_1;
  /* PiecewiseTranslation::Interpolate::x1 */ kcg_real x1_6;
  /* PiecewiseTranslation::Interpolate::x2 */ kcg_real x2_6;
  /* PiecewiseTranslation::Interpolate::IfBlock1 */ kcg_bool IfBlock1_clock_5;
  /* PiecewiseTranslation::Interpolate::v1 */ kcg_real v1_5;
  /* PiecewiseTranslation::Interpolate::v2 */ kcg_real v2_5;
  /* PiecewiseTranslation::Interpolate::x1 */ kcg_real x1_5;
  /* PiecewiseTranslation::Interpolate::x2 */ kcg_real x2_5;
  
  IfBlock1_clock = inC->v < inC->v_list[0];
  /* ck_IfBlock1 */ if (IfBlock1_clock) {
    /* 1 */ if (0. <= inC->v_list[0]) {
      tmp2 = inC->v_list[0];
    }
    else {
      tmp2 = - inC->v_list[0];
    }
    IfBlock1_clock_1 = inC->v_list[1] - inC->v_list[0] <= 0.0001 * tmp2;
    /* 3 */ if (inC->saturate_low) {
      outC->x = inC->x_list[0];
      outC->y = inC->y_list[0];
    }
    else /* 1_ck_IfBlock1 */ if (IfBlock1_clock_1) {
      outC->x = inC->x_list[0];
      outC->y = inC->y_list[0];
    }
    else {
      outC->x = inC->x_list[0] + (inC->x_list[1] - inC->x_list[0]) * (inC->v -
          inC->v_list[0]) / (inC->v_list[1] - inC->v_list[0]);
      outC->y = inC->y_list[0] + (inC->y_list[1] - inC->y_list[0]) * (inC->v -
          inC->v_list[0]) / (inC->v_list[1] - inC->v_list[0]);
    }
  }
  else {
    if ((0 <= inC->size) & (inC->size < 16)) {
      tmp6 = inC->v_list[inC->size];
    }
    else {
      tmp6 = inC->v - 1.0;
    }
    else_clock_IfBlock1 = inC->v > tmp6;
    /* ck_anon_activ */ if (else_clock_IfBlock1) {
      if ((0 <= inC->size - 1) & (inC->size - 1 < 16)) {
        v1_5 = inC->v_list[inC->size - 1];
        x1_5 = inC->x_list[inC->size - 1];
        x1_6 = inC->y_list[inC->size - 1];
      }
      else {
        v1_5 = inC->v_list[14];
        x1_5 = inC->x_list[14];
        x1_6 = inC->y_list[14];
      }
      /* 1 */ if (0. <= v1_5) {
        tmp3 = v1_5;
      }
      else {
        tmp3 = - v1_5;
      }
      if ((0 <= inC->size) & (inC->size < 16)) {
        x2_5 = inC->x_list[inC->size];
        v2_5 = inC->v_list[inC->size];
        x2_6 = inC->y_list[inC->size];
      }
      else {
        x2_5 = inC->x_list[15];
        v2_5 = inC->v_list[15];
        x2_6 = inC->y_list[15];
      }
      IfBlock1_clock_5 = v2_5 - v1_5 <= 0.0001 * tmp3;
      /* 7 */ if (inC->saturate_high) {
        outC->x = x2_5;
        outC->y = x2_6;
      }
      else /* 5_ck_IfBlock1 */ if (IfBlock1_clock_5) {
        outC->x = x1_5;
        outC->y = x1_6;
      }
      else {
        outC->x = x1_5 + (x2_5 - x1_5) * (inC->v - v1_5) / (v2_5 - v1_5);
        outC->y = x1_6 + (x2_6 - x1_6) * (inC->v - v1_5) / (v2_5 - v1_5);
      }
    }
    else {
      for (i = 0; i < 15; i++) {
        tmp5[i] = (inC->v_list[i + 1] >= inC->v) & (inC->v >= inC->v_list[i +
            0]);
      }
      /* 1 */ for (i = 0; i < 15; i++) {
        index_IfBlock1 = i + 1;
        /* 1 */ if (tmp5[i]) {
          break;
        }
      }
      if ((0 <= index_IfBlock1) & (index_IfBlock1 < 16)) {
        _L11_IfBlock1 = inC->v_list[index_IfBlock1];
      }
      else {
        _L11_IfBlock1 = 0.0;
      }
      _L19_IfBlock1 = index_IfBlock1 - 1;
      if ((0 <= _L19_IfBlock1) & (_L19_IfBlock1 < 16)) {
        _L10_IfBlock1 = inC->v_list[_L19_IfBlock1];
        _L12_IfBlock1 = inC->x_list[_L19_IfBlock1];
        _L15_IfBlock1 = inC->y_list[_L19_IfBlock1];
      }
      else {
        _L10_IfBlock1 = 0.0;
        _L12_IfBlock1 = 0.0;
        _L15_IfBlock1 = 0.0;
      }
      /* 1 */ if (0. <= _L10_IfBlock1) {
        tmp4 = _L10_IfBlock1;
      }
      else {
        tmp4 = - _L10_IfBlock1;
      }
      IfBlock1_clock_3 = _L11_IfBlock1 - _L10_IfBlock1 <= 0.0001 * tmp4;
      /* 3_ck_IfBlock1 */ if (IfBlock1_clock_3) {
        outC->x = _L12_IfBlock1;
        outC->y = _L15_IfBlock1;
      }
      else {
        if ((0 <= index_IfBlock1) & (index_IfBlock1 < 16)) {
          tmp1 = inC->x_list[index_IfBlock1];
          tmp = inC->y_list[index_IfBlock1];
        }
        else {
          tmp1 = 0.0;
          tmp = 0.0;
        }
        outC->x = _L12_IfBlock1 + (tmp1 - _L12_IfBlock1) * (inC->v -
            _L10_IfBlock1) / (_L11_IfBlock1 - _L10_IfBlock1);
        outC->y = _L15_IfBlock1 + (tmp - _L15_IfBlock1) * (inC->v -
            _L10_IfBlock1) / (_L11_IfBlock1 - _L10_IfBlock1);
      }
    }
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** PiecewiseTranslation.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

