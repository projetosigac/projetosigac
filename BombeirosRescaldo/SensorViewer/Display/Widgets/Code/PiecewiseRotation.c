/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -target_dir ../Code/Generated -target C -O 3 -name_length 128 -significance_length 127 -user_config imported_user_macros.h -node CheckButton,AlphaNumKeypad,NumKeypad,PushButton,ScrollList,Slider,TextEditBox,ToggleButton,MultilineEditBox,PopUpPanel,ScrollBar,NumericEditBox,RadioBox,PopUpMenu,ComboBox,VirtualKeyboard,Scale,PiecewiseTranslation,PiecewiseRotation,Curve,RollingDigits,Animations,GestureDrag,GestureFlick,GesturePinchExpandRotate,GesturePressHold,GestureTap,Joystick,Signals,InfiniteKnob,Knob,RotarySwitch,GraphTimed ../Widgets/Suite/Common/Pointer.xscade ../Widgets/Suite/Common/Util.xscade ../Widgets/Suite/Common/Strings.xscade ../Widgets/Suite/Common/liba661widgets.xscade ../Widgets/Suite/Common/Math.xscade ../Widgets/Suite/Common/Angles.xscade ../Widgets/Suite/CheckButton/CheckButton.xscade ../Widgets/Suite/AlphaNumKeypad/AlphaNumKeypad.xscade ../Widgets/Suite/Animations/Animations.xscade ../Widgets/Suite/GestureDrag/GestureDrag.xscade ../Widgets/Suite/GestureFlick/GestureFlick.xscade ../Widgets/Suite/GesturePinchExpandRotate/GesturePinchExpandRotate.xscade ../Widgets/Suite/GesturePressHold/GesturePressHold.xscade ../Widgets/Suite/GestureTap/GestureTap.xscade ../Widgets/Suite/InfiniteKnob/InfiniteKnob.xscade ../Widgets/Suite/Knob/Knob.xscade ../Widgets/Suite/Joystick/Joystick.xscade ../Widgets/Suite/NumKeypad/NumKeypad.xscade ../Widgets/Suite/PushButton/PushButton.xscade ../Widgets/Suite/ScrollList/ScrollList.xscade ../Widgets/Suite/Slider/Slider.xscade ../Widgets/Suite/TextEditBox/TextEditBox.xscade ../Widgets/Suite/ToggleButton/ToggleButton.xscade ../Widgets/Suite/MultilineEditBox/MultilineEditBox.xscade ../Widgets/Suite/Scale/Scale.xscade ../Widgets/Suite/PopUpPanel/PopUpPanel.xscade ../Widgets/Suite/ScrollBar/ScrollBar.xscade ../Widgets/Suite/NumericEditBox/NumericEditBox.xscade ../Widgets/Suite/RadioBox/RadioBox.xscade ../Widgets/Suite/PopUpMenu/PopUpMenu.xscade ../Widgets/Suite/ComboBox/ComboBox.xscade ../Widgets/Suite/VirtualKeyboard/VirtualKeyboard.xscade ../Widgets/Suite/PiecewiseRotation/PiecewiseRotation.xscade ../Widgets/Suite/PiecewiseTranslation/PiecewiseTranslation.xscade ../Widgets/Suite/RollingDigits/RollingDigits.xscade ../Widgets/Suite/Signals/Signals.xscade ../Widgets/Suite/Curve/Curve.xscade ../Widgets/Suite/GraphTimed/GraphTimed.xscade ../Widgets/Suite/RotarySwitch/RotarySwitch.xscade
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

#include "wid_kcg_consts.h"
#include "wid_kcg_sensors.h"
#include "PiecewiseRotation.h"

#ifndef KCG_USER_DEFINED_INIT
void PiecewiseRotation_init(outC_PiecewiseRotation *outC)
{
  outC->angle = 0.0;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void PiecewiseRotation_reset(outC_PiecewiseRotation *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/* PiecewiseRotation */
void PiecewiseRotation(inC_PiecewiseRotation *inC, outC_PiecewiseRotation *outC)
{
  /* PiecewiseRotation */ kcg_real tmp5;
  /* PiecewiseRotation */ array_bool_15 tmp4;
  kcg_int i;
  /* PiecewiseRotation */ kcg_real tmp3;
  /* PiecewiseRotation */ kcg_real tmp2;
  /* PiecewiseRotation */ kcg_real tmp1;
  /* PiecewiseRotation */ kcg_real tmp;
  /* PiecewiseRotation::Interpolate::x2 */ kcg_real x2_4;
  /* PiecewiseRotation::Interpolate::x1 */ kcg_real x1_4;
  /* PiecewiseRotation::Interpolate::v2 */ kcg_real v2_4;
  /* PiecewiseRotation::Interpolate::v1 */ kcg_real v1_4;
  /* PiecewiseRotation::Interpolate::IfBlock1 */ kcg_bool IfBlock1_clock_4;
  /* PiecewiseRotation::Interpolate::IfBlock1 */ kcg_bool IfBlock1_clock_1;
  /* PiecewiseRotation::Interpolate::IfBlock1 */ kcg_bool IfBlock1_clock_3;
  /* PiecewiseRotation::IfBlock1::else */ kcg_bool else_clock_IfBlock1;
  /* PiecewiseRotation::IfBlock1::else::else::index */ kcg_int index_IfBlock1;
  /* PiecewiseRotation::IfBlock1::else::else::_L10 */ kcg_real _L10_IfBlock1;
  /* PiecewiseRotation::IfBlock1::else::else::_L11 */ kcg_real _L11_IfBlock1;
  /* PiecewiseRotation::IfBlock1::else::else::_L12 */ kcg_real _L12_IfBlock1;
  /* PiecewiseRotation::IfBlock1::else::else::_L19 */ kcg_int _L19_IfBlock1;
  /* PiecewiseRotation::IfBlock1 */ kcg_bool IfBlock1_clock;
  
  IfBlock1_clock = inC->v < inC->v_list[0];
  /* ck_IfBlock1 */ if (IfBlock1_clock) {
    /* 1 */ if (0. <= inC->v_list[0]) {
      tmp1 = inC->v_list[0];
    }
    else {
      tmp1 = - inC->v_list[0];
    }
    IfBlock1_clock_1 = inC->v_list[1] - inC->v_list[0] <= 0.0001 * tmp1;
    /* 1 */ if (inC->saturate_low) {
      outC->angle = inC->angle_list[0];
    }
    else /* 1_ck_IfBlock1 */ if (IfBlock1_clock_1) {
      outC->angle = inC->angle_list[0];
    }
    else {
      outC->angle = inC->angle_list[0] + (inC->angle_list[1] -
          inC->angle_list[0]) * (inC->v - inC->v_list[0]) / (inC->v_list[1] -
          inC->v_list[0]);
    }
  }
  else {
    if ((0 <= inC->size) & (inC->size < 16)) {
      tmp5 = inC->v_list[inC->size];
    }
    else {
      tmp5 = inC->v - 1.0;
    }
    else_clock_IfBlock1 = inC->v > tmp5;
    /* ck_anon_activ */ if (else_clock_IfBlock1) {
      if ((0 <= inC->size) & (inC->size < 16)) {
        x2_4 = inC->angle_list[inC->size];
        v2_4 = inC->v_list[inC->size];
      }
      else {
        x2_4 = inC->angle_list[15];
        v2_4 = inC->v_list[15];
      }
      if ((0 <= inC->size - 1) & (inC->size - 1 < 16)) {
        v1_4 = inC->v_list[inC->size - 1];
        x1_4 = inC->angle_list[inC->size - 1];
      }
      else {
        v1_4 = inC->v_list[14];
        x1_4 = inC->angle_list[14];
      }
      /* 1 */ if (0. <= v1_4) {
        tmp2 = v1_4;
      }
      else {
        tmp2 = - v1_4;
      }
      IfBlock1_clock_4 = v2_4 - v1_4 <= 0.0001 * tmp2;
      /* 3 */ if (inC->saturate_high) {
        outC->angle = x2_4;
      }
      else /* 4_ck_IfBlock1 */ if (IfBlock1_clock_4) {
        outC->angle = x1_4;
      }
      else {
        outC->angle = x1_4 + (x2_4 - x1_4) * (inC->v - v1_4) / (v2_4 - v1_4);
      }
    }
    else {
      for (i = 0; i < 15; i++) {
        tmp4[i] = (inC->v_list[i + 1] >= inC->v) & (inC->v >= inC->v_list[i +
            0]);
      }
      /* 1 */ for (i = 0; i < 15; i++) {
        index_IfBlock1 = i + 1;
        /* 1 */ if (tmp4[i]) {
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
        _L12_IfBlock1 = inC->angle_list[_L19_IfBlock1];
      }
      else {
        _L10_IfBlock1 = 0.0;
        _L12_IfBlock1 = 0.0;
      }
      /* 1 */ if (0. <= _L10_IfBlock1) {
        tmp3 = _L10_IfBlock1;
      }
      else {
        tmp3 = - _L10_IfBlock1;
      }
      IfBlock1_clock_3 = _L11_IfBlock1 - _L10_IfBlock1 <= 0.0001 * tmp3;
      /* 3_ck_IfBlock1 */ if (IfBlock1_clock_3) {
        outC->angle = _L12_IfBlock1;
      }
      else {
        if ((0 <= index_IfBlock1) & (index_IfBlock1 < 16)) {
          tmp = inC->angle_list[index_IfBlock1];
        }
        else {
          tmp = 0.0;
        }
        outC->angle = _L12_IfBlock1 + (tmp - _L12_IfBlock1) * (inC->v -
            _L10_IfBlock1) / (_L11_IfBlock1 - _L10_IfBlock1);
      }
    }
  }
}

/* $**************** KCG Version 6.4 (build i21) ****************
** PiecewiseRotation.c
** Generation date: 2014-11-28T14:01:13
*************************************************************$ */

