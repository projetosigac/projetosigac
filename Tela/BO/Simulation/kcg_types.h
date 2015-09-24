/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/Users/Goku/Desktop/scade/BO/BO/BO/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-24T00:58:59
*************************************************************$ */
#ifndef _KCG_TYPES_H_
#define _KCG_TYPES_H_

#define KCG_MAPW_CPY

#include "./user_macros.h"

#ifndef kcg_int
#define kcg_int kcg_int
typedef int kcg_int;
#endif /* kcg_int */

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef unsigned char kcg_bool;
#endif /* kcg_bool */

#ifndef kcg_real
#define kcg_real kcg_real
typedef double kcg_real;
#endif /* kcg_real */

#ifndef kcg_char
#define kcg_char kcg_char
typedef unsigned char kcg_char;
#endif /* kcg_char */

#ifndef kcg_false
#define kcg_false ((kcg_bool) 0)
#endif /* kcg_false */

#ifndef kcg_true
#define kcg_true ((kcg_bool) 1)
#endif /* kcg_true */

#ifndef kcg_assign
#include "kcg_assign.h"
#endif /* kcg_assign */

#ifndef kcg_assign_struct
#define kcg_assign_struct kcg_assign
#endif /* kcg_assign_struct */

#ifndef kcg_assign_array
#define kcg_assign_array kcg_assign
#endif /* kcg_assign_array */

/* Enviar::SM1 */
typedef enum {
  SSM_TR_no_trans_SM1,
  SSM_TR_Espera_Enviar_1_SM1,
  SSM_TR_Enviando_1_SM1
} SSM_TR_SM1;
/* Enviar::SM1 */
typedef enum { SSM_st_Espera_Enviar_SM1, SSM_st_Enviando_SM1 } SSM_ST_SM1;
typedef kcg_char array_char_1000[1000];

/* BigText */
typedef array_char_1000 BigText;

typedef kcg_char array_char_20[20];

/* String */
typedef array_char_20 String;

typedef struct {
  BigText description;
  String dt_fato;
  String hora_fato;
  String dt_ini_atend;
  String hora_ini_atend;
  String dt_fim_atend;
  String hora_fim_atend;
  String rg;
} struct__273;

/* Boletim */
typedef struct__273 Boletim;

typedef kcg_char array_char_5[5];

/* Name */
typedef array_char_5 Name;

#ifndef kcg_copy_struct__273
#define kcg_copy_struct__273(kcg_C1, kcg_C2) (kcg_assign_struct((kcg_C1), (kcg_C2), sizeof (struct__273)))
#endif /* kcg_copy_struct__273 */

#ifndef kcg_copy_array_char_1000
#define kcg_copy_array_char_1000(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_char_1000)))
#endif /* kcg_copy_array_char_1000 */

#ifndef kcg_copy_array_char_20
#define kcg_copy_array_char_20(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_char_20)))
#endif /* kcg_copy_array_char_20 */

#ifndef kcg_copy_array_char_5
#define kcg_copy_array_char_5(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_char_5)))
#endif /* kcg_copy_array_char_5 */

#ifndef kcg_comp_struct__273
extern kcg_bool kcg_comp_struct__273(struct__273 *kcg_c1, struct__273 *kcg_c2);
#endif /* kcg_comp_struct__273 */

#ifndef kcg_comp_array_char_1000
extern kcg_bool kcg_comp_array_char_1000(
  array_char_1000 *kcg_c1,
  array_char_1000 *kcg_c2);
#endif /* kcg_comp_array_char_1000 */

#ifndef kcg_comp_array_char_20
extern kcg_bool kcg_comp_array_char_20(
  array_char_20 *kcg_c1,
  array_char_20 *kcg_c2);
#endif /* kcg_comp_array_char_20 */

#ifndef kcg_comp_array_char_5
extern kcg_bool kcg_comp_array_char_5(
  array_char_5 *kcg_c1,
  array_char_5 *kcg_c2);
#endif /* kcg_comp_array_char_5 */

#define kcg_comp_Boletim kcg_comp_struct__273

#define kcg_copy_Boletim kcg_copy_struct__273

#define kcg_comp_BigText kcg_comp_array_char_1000

#define kcg_copy_BigText kcg_copy_array_char_1000

#define kcg_comp_String kcg_comp_array_char_20

#define kcg_copy_String kcg_copy_array_char_20

#define kcg_comp_Name kcg_comp_array_char_5

#define kcg_copy_Name kcg_copy_array_char_5

#endif /* _KCG_TYPES_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** kcg_types.h
** Generation date: 2015-09-24T00:58:59
*************************************************************$ */

