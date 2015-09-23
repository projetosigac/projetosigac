/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config C:/ita/ces-65/REST-API/UserApplication/Simulation\kcg_s2c_config.txt
** Generation date: 2015-09-23T18:39:21
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

typedef kcg_char array_char_512[512];

/* String */
typedef array_char_512 String;

typedef kcg_char array_char_256[256];

/* Path */
typedef array_char_256 Path;

typedef kcg_char array_char_10[10];

typedef kcg_char array_char_522[522];

#ifndef kcg_copy_array_char_512
#define kcg_copy_array_char_512(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_char_512)))
#endif /* kcg_copy_array_char_512 */

#ifndef kcg_copy_array_char_256
#define kcg_copy_array_char_256(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_char_256)))
#endif /* kcg_copy_array_char_256 */

#ifndef kcg_copy_array_char_10
#define kcg_copy_array_char_10(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_char_10)))
#endif /* kcg_copy_array_char_10 */

#ifndef kcg_copy_array_char_522
#define kcg_copy_array_char_522(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_char_522)))
#endif /* kcg_copy_array_char_522 */

#ifndef kcg_comp_array_char_512
extern kcg_bool kcg_comp_array_char_512(
  array_char_512 *kcg_c1,
  array_char_512 *kcg_c2);
#endif /* kcg_comp_array_char_512 */

#ifndef kcg_comp_array_char_256
extern kcg_bool kcg_comp_array_char_256(
  array_char_256 *kcg_c1,
  array_char_256 *kcg_c2);
#endif /* kcg_comp_array_char_256 */

#ifndef kcg_comp_array_char_10
extern kcg_bool kcg_comp_array_char_10(
  array_char_10 *kcg_c1,
  array_char_10 *kcg_c2);
#endif /* kcg_comp_array_char_10 */

#ifndef kcg_comp_array_char_522
extern kcg_bool kcg_comp_array_char_522(
  array_char_522 *kcg_c1,
  array_char_522 *kcg_c2);
#endif /* kcg_comp_array_char_522 */

#define kcg_comp_Path kcg_comp_array_char_256

#define kcg_copy_Path kcg_copy_array_char_256

#define kcg_comp_String kcg_comp_array_char_512

#define kcg_copy_String kcg_copy_array_char_512

#endif /* _KCG_TYPES_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** kcg_types.h
** Generation date: 2015-09-23T18:39:21
*************************************************************$ */

