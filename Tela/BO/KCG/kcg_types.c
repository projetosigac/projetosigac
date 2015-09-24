/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/Goku/Desktop/scade/BO/BO/BO/KCG\kcg_s2c_config.txt
** Generation date: 2015-09-23T22:28:15
*************************************************************$ */

#include "kcg_types.h"

kcg_bool kcg_comp_array_char_1000(
  array_char_1000 *kcg_c1,
  array_char_1000 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_int kcg_ci;
  
  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 1000; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}

kcg_bool kcg_comp_array_char_20(array_char_20 *kcg_c1, array_char_20 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_int kcg_ci;
  
  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 20; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}

kcg_bool kcg_comp_array_char_5(array_char_5 *kcg_c1, array_char_5 *kcg_c2)
{
  kcg_bool kcg_equ;
  kcg_int kcg_ci;
  
  kcg_equ = kcg_true;
  for (kcg_ci = 0; kcg_ci < 5; kcg_ci++) {
    kcg_equ = kcg_equ & ((*kcg_c1)[kcg_ci] == (*kcg_c2)[kcg_ci]);
  }
  return kcg_equ;
}

kcg_bool kcg_comp_struct__273(struct__273 *kcg_c1, struct__273 *kcg_c2)
{
  kcg_bool kcg_equ;
  
  kcg_equ = kcg_true;
  kcg_equ = kcg_equ & kcg_comp_array_char_20(&kcg_c1->rg, &kcg_c2->rg);
  kcg_equ = kcg_equ & kcg_comp_array_char_20(
      &kcg_c1->hora_fim_atend,
      &kcg_c2->hora_fim_atend);
  kcg_equ = kcg_equ & kcg_comp_array_char_20(
      &kcg_c1->dt_fim_atend,
      &kcg_c2->dt_fim_atend);
  kcg_equ = kcg_equ & kcg_comp_array_char_20(
      &kcg_c1->hora_ini_atend,
      &kcg_c2->hora_ini_atend);
  kcg_equ = kcg_equ & kcg_comp_array_char_20(
      &kcg_c1->dt_ini_atend,
      &kcg_c2->dt_ini_atend);
  kcg_equ = kcg_equ & kcg_comp_array_char_20(
      &kcg_c1->hora_fato,
      &kcg_c2->hora_fato);
  kcg_equ = kcg_equ & kcg_comp_array_char_20(
      &kcg_c1->dt_fato,
      &kcg_c2->dt_fato);
  kcg_equ = kcg_equ & kcg_comp_array_char_1000(
      &kcg_c1->description,
      &kcg_c2->description);
  return kcg_equ;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** kcg_types.c
** Generation date: 2015-09-23T22:28:15
*************************************************************$ */

