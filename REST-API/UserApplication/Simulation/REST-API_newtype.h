#ifndef REST-API_TYPES_CONVERTION
#define REST-API_TYPES_CONVERTION

#include "NewSmuTypes.h"

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
 ** array_char_512 
 ****************************************************************/
extern int array_char_512_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_array_char_512_string(const char *str, const char** endptr);
extern int string_to_array_char_512(const char *str, void* pValue, const char** endptr);
extern int is_array_char_512_allow_double_convertion();
extern int array_char_512_to_double(const void* pValue, double *nValue);
extern int get_array_char_512_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_array_char_512(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_array_char_512_default_value(void *pValue);
extern TypeUtils _Type_array_char_512_Utils;

/****************************************************************
 ** array_char_256 
 ****************************************************************/
extern int array_char_256_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_array_char_256_string(const char *str, const char** endptr);
extern int string_to_array_char_256(const char *str, void* pValue, const char** endptr);
extern int is_array_char_256_allow_double_convertion();
extern int array_char_256_to_double(const void* pValue, double *nValue);
extern int get_array_char_256_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_array_char_256(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_array_char_256_default_value(void *pValue);
extern TypeUtils _Type_array_char_256_Utils;

/****************************************************************
 ** array_char_10 
 ****************************************************************/
extern int array_char_10_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_array_char_10_string(const char *str, const char** endptr);
extern int string_to_array_char_10(const char *str, void* pValue, const char** endptr);
extern int is_array_char_10_allow_double_convertion();
extern int array_char_10_to_double(const void* pValue, double *nValue);
extern int get_array_char_10_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_array_char_10(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_array_char_10_default_value(void *pValue);
extern TypeUtils _Type_array_char_10_Utils;

/****************************************************************
 ** array_char_522 
 ****************************************************************/
extern int array_char_522_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_array_char_522_string(const char *str, const char** endptr);
extern int string_to_array_char_522(const char *str, void* pValue, const char** endptr);
extern int is_array_char_522_allow_double_convertion();
extern int array_char_522_to_double(const void* pValue, double *nValue);
extern int get_array_char_522_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_array_char_522(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_array_char_522_default_value(void *pValue);
extern TypeUtils _Type_array_char_522_Utils;

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
 ** Path 
 ****************************************************************/
extern int Path_to_string(const void *pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int check_Path_string(const char *str, const char** endptr);
extern int string_to_Path(const char *str, void* pValue, const char** endptr);
extern int is_Path_allow_double_convertion();
extern int Path_to_double(const void* pValue, double *nValue);
extern int get_Path_signature(int (*pfnStrAppend)(const char *str, void *pData), void *pData);
extern int compare_Path(int *nStatus, const void *pValue1, const void *pValue2, void *pData);
extern int set_Path_default_value(void *pValue);
extern TypeUtils _Type_Path_Utils;


#endif /*REST-API_TYPES_CONVERTION */
