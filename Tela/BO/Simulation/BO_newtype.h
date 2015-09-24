#ifndef BO_TYPES_CONVERTION
#define BO_TYPES_CONVERTION

#include "NewSmuTypes.h"

/****************************************************************
 ** SSM_ST_SM1 
 ****************************************************************/
extern int SSM_ST_SM1_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_SSM_ST_SM1_string(const char *str, const char** endptr);
extern int string_to_SSM_ST_SM1(const char *str, void* pValue, const char** endptr);
extern int is_SSM_ST_SM1_allow_double_convertion();
extern int SSM_ST_SM1_to_double(const void* pValue, double *nValue);
extern int get_SSM_ST_SM1_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_SSM_ST_SM1(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_SSM_ST_SM1_default_value(void *pValue);
extern TypeUtils _Type_SSM_ST_SM1_Utils;

/****************************************************************
 ** SSM_TR_SM1 
 ****************************************************************/
extern int SSM_TR_SM1_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_SSM_TR_SM1_string(const char *str, const char** endptr);
extern int string_to_SSM_TR_SM1(const char *str, void* pValue, const char** endptr);
extern int is_SSM_TR_SM1_allow_double_convertion();
extern int SSM_TR_SM1_to_double(const void* pValue, double *nValue);
extern int get_SSM_TR_SM1_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_SSM_TR_SM1(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_SSM_TR_SM1_default_value(void *pValue);
extern TypeUtils _Type_SSM_TR_SM1_Utils;

/****************************************************************
 ** kcg_real 
 ****************************************************************/
extern int kcg_real_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_kcg_real_string(const char *str, const char** endptr);
extern int string_to_kcg_real(const char *str, void* pValue, const char** endptr);
extern int is_kcg_real_allow_double_convertion();
extern int kcg_real_to_double(const void* pValue, double *nValue);
extern int get_kcg_real_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_kcg_real(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_kcg_real_default_value(void *pValue);
extern TypeUtils _Type_kcg_real_Utils;

/****************************************************************
 ** kcg_bool 
 ****************************************************************/
extern int kcg_bool_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_kcg_bool_string(const char *str, const char** endptr);
extern int string_to_kcg_bool(const char *str, void* pValue, const char** endptr);
extern int is_kcg_bool_allow_double_convertion();
extern int kcg_bool_to_double(const void* pValue, double *nValue);
extern int get_kcg_bool_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_kcg_bool(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_kcg_bool_default_value(void *pValue);
extern TypeUtils _Type_kcg_bool_Utils;

/****************************************************************
 ** kcg_char 
 ****************************************************************/
extern int kcg_char_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_kcg_char_string(const char *str, const char** endptr);
extern int string_to_kcg_char(const char *str, void* pValue, const char** endptr);
extern int is_kcg_char_allow_double_convertion();
extern int kcg_char_to_double(const void* pValue, double *nValue);
extern int get_kcg_char_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_kcg_char(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_kcg_char_default_value(void *pValue);
extern TypeUtils _Type_kcg_char_Utils;

/****************************************************************
 ** kcg_int 
 ****************************************************************/
extern int kcg_int_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_kcg_int_string(const char *str, const char** endptr);
extern int string_to_kcg_int(const char *str, void* pValue, const char** endptr);
extern int is_kcg_int_allow_double_convertion();
extern int kcg_int_to_double(const void* pValue, double *nValue);
extern int get_kcg_int_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_kcg_int(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_kcg_int_default_value(void *pValue);
extern TypeUtils _Type_kcg_int_Utils;

/****************************************************************
 ** array_char_1000 
 ****************************************************************/
extern int array_char_1000_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_array_char_1000_string(const char *str, const char** endptr);
extern int string_to_array_char_1000(const char *str, void* pValue, const char** endptr);
extern int is_array_char_1000_allow_double_convertion();
extern int array_char_1000_to_double(const void* pValue, double *nValue);
extern int get_array_char_1000_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_array_char_1000(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_array_char_1000_default_value(void *pValue);
extern TypeUtils _Type_array_char_1000_Utils;

/****************************************************************
 ** array_char_20 
 ****************************************************************/
extern int array_char_20_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_array_char_20_string(const char *str, const char** endptr);
extern int string_to_array_char_20(const char *str, void* pValue, const char** endptr);
extern int is_array_char_20_allow_double_convertion();
extern int array_char_20_to_double(const void* pValue, double *nValue);
extern int get_array_char_20_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_array_char_20(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_array_char_20_default_value(void *pValue);
extern TypeUtils _Type_array_char_20_Utils;

/****************************************************************
 ** struct__273 
 ****************************************************************/
extern int struct__273_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_struct__273_string(const char *str, const char** endptr);
extern int string_to_struct__273(const char *str, void* pValue, const char** endptr);
extern int is_struct__273_allow_double_convertion();
extern int struct__273_to_double(const void* pValue, double *nValue);
extern int get_struct__273_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_struct__273(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_struct__273_default_value(void *pValue);
extern TypeUtils _Type_struct__273_Utils;

/****************************************************************
 ** array_char_5 
 ****************************************************************/
extern int array_char_5_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_array_char_5_string(const char *str, const char** endptr);
extern int string_to_array_char_5(const char *str, void* pValue, const char** endptr);
extern int is_array_char_5_allow_double_convertion();
extern int array_char_5_to_double(const void* pValue, double *nValue);
extern int get_array_char_5_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_array_char_5(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_array_char_5_default_value(void *pValue);
extern TypeUtils _Type_array_char_5_Utils;

/****************************************************************
 ** Name 
 ****************************************************************/
extern int Name_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_Name_string(const char *str, const char** endptr);
extern int string_to_Name(const char *str, void* pValue, const char** endptr);
extern int is_Name_allow_double_convertion();
extern int Name_to_double(const void* pValue, double *nValue);
extern int get_Name_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_Name(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_Name_default_value(void *pValue);
extern TypeUtils _Type_Name_Utils;

/****************************************************************
 ** String 
 ****************************************************************/
extern int String_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_String_string(const char *str, const char** endptr);
extern int string_to_String(const char *str, void* pValue, const char** endptr);
extern int is_String_allow_double_convertion();
extern int String_to_double(const void* pValue, double *nValue);
extern int get_String_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_String(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_String_default_value(void *pValue);
extern TypeUtils _Type_String_Utils;

/****************************************************************
 ** BigText 
 ****************************************************************/
extern int BigText_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_BigText_string(const char *str, const char** endptr);
extern int string_to_BigText(const char *str, void* pValue, const char** endptr);
extern int is_BigText_allow_double_convertion();
extern int BigText_to_double(const void* pValue, double *nValue);
extern int get_BigText_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_BigText(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_BigText_default_value(void *pValue);
extern TypeUtils _Type_BigText_Utils;

/****************************************************************
 ** Boletim 
 ****************************************************************/
extern int Boletim_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_Boletim_string(const char *str, const char** endptr);
extern int string_to_Boletim(const char *str, void* pValue, const char** endptr);
extern int is_Boletim_allow_double_convertion();
extern int Boletim_to_double(const void* pValue, double *nValue);
extern int get_Boletim_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_Boletim(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_Boletim_default_value(void *pValue);
extern TypeUtils _Type_Boletim_Utils;


#endif /*BO_TYPES_CONVERTION */
