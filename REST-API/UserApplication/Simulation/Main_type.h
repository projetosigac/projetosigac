#ifndef MAIN_TYPES_CONVERTION
#define MAIN_TYPES_CONVERTION

/****************************************************************
 ** Boolean entity activation
 ****************************************************************/
extern int _SCSIM_BoolEntity_is_active(void* pValue);

/****************************************************************
 ** Type utils declarations
 ****************************************************************/
extern TypeUtils _SCSIM_kcg_real_Utils;
extern TypeUtils _SCSIM_kcg_bool_Utils;
extern TypeUtils _SCSIM_kcg_char_Utils;
extern TypeUtils _SCSIM_kcg_int_Utils;
extern TypeUtils _SCSIM_array_char_512_Utils;
extern TypeUtils _SCSIM_array_char_256_Utils;
extern TypeUtils _SCSIM_array_char_10_Utils;
extern TypeUtils _SCSIM_array_char_522_Utils;
extern TypeUtils _SCSIM_String_Utils;
extern TypeUtils _SCSIM_Path_Utils;

/****************************************************************
 ** kcg_real
 ****************************************************************/
extern const char * kcg_real_to_string(const void* pValue);
extern int check_kcg_real_string(const char* strValue);
extern int string_to_kcg_real(const char* strValue, void* pValue);
int is_kcg_real_allow_double_convertion();
extern int kcg_real_to_double(double * nValue, const void*);
extern const char * get_kcg_real_signature();
extern int compare_kcg_real_type(int*, const char*, const void*);
#define kcg_real_filter_size 0
#define get_kcg_real_filter_utils 0
#define kcg_real_filter_values 0
/****************************************************************
 ** kcg_bool
 ****************************************************************/
extern const char * kcg_bool_to_string(const void* pValue);
extern int check_kcg_bool_string(const char* strValue);
extern int string_to_kcg_bool(const char* strValue, void* pValue);
int is_kcg_bool_allow_double_convertion();
extern int kcg_bool_to_double(double * nValue, const void*);
extern const char * get_kcg_bool_signature();
extern int compare_kcg_bool_type(int*, const char*, const void*);
#define kcg_bool_filter_size 0
#define get_kcg_bool_filter_utils 0
#define kcg_bool_filter_values 0
/****************************************************************
 ** kcg_char
 ****************************************************************/
extern const char * kcg_char_to_string(const void* pValue);
extern int check_kcg_char_string(const char* strValue);
extern int string_to_kcg_char(const char* strValue, void* pValue);
int is_kcg_char_allow_double_convertion();
extern int kcg_char_to_double(double * nValue, const void*);
extern const char * get_kcg_char_signature();
extern int compare_kcg_char_type(int*, const char*, const void*);
#define kcg_char_filter_size 0
#define get_kcg_char_filter_utils 0
#define kcg_char_filter_values 0
/****************************************************************
 ** kcg_int
 ****************************************************************/
extern const char * kcg_int_to_string(const void* pValue);
extern int check_kcg_int_string(const char* strValue);
extern int string_to_kcg_int(const char* strValue, void* pValue);
int is_kcg_int_allow_double_convertion();
extern int kcg_int_to_double(double * nValue, const void*);
extern const char * get_kcg_int_signature();
extern int compare_kcg_int_type(int*, const char*, const void*);
#define kcg_int_filter_size 0
#define get_kcg_int_filter_utils 0
#define kcg_int_filter_values 0
/****************************************************************
 ** array_char_512
 ****************************************************************/
extern const char * array_char_512_to_string(const void* pValue);
extern int check_array_char_512_string(const char* strValue);
extern int string_to_array_char_512(const char* strValue, void* pValue);
int is_array_char_512_allow_double_convertion();
extern const char * get_array_char_512_signature();
extern int compare_array_char_512_type(int*, const char*, const void*);
#define array_char_512_filter_size 512
extern FilterUtils get_array_char_512_filter_utils(const char* strFilter, void* pValue);
#define array_char_512_filter_values 0
/****************************************************************
 ** array_char_256
 ****************************************************************/
extern const char * array_char_256_to_string(const void* pValue);
extern int check_array_char_256_string(const char* strValue);
extern int string_to_array_char_256(const char* strValue, void* pValue);
int is_array_char_256_allow_double_convertion();
extern const char * get_array_char_256_signature();
extern int compare_array_char_256_type(int*, const char*, const void*);
#define array_char_256_filter_size 256
extern FilterUtils get_array_char_256_filter_utils(const char* strFilter, void* pValue);
#define array_char_256_filter_values 0
/****************************************************************
 ** array_char_10
 ****************************************************************/
extern const char * array_char_10_to_string(const void* pValue);
extern int check_array_char_10_string(const char* strValue);
extern int string_to_array_char_10(const char* strValue, void* pValue);
int is_array_char_10_allow_double_convertion();
extern const char * get_array_char_10_signature();
extern int compare_array_char_10_type(int*, const char*, const void*);
#define array_char_10_filter_size 10
extern FilterUtils get_array_char_10_filter_utils(const char* strFilter, void* pValue);
#define array_char_10_filter_values 0
/****************************************************************
 ** array_char_522
 ****************************************************************/
extern const char * array_char_522_to_string(const void* pValue);
extern int check_array_char_522_string(const char* strValue);
extern int string_to_array_char_522(const char* strValue, void* pValue);
int is_array_char_522_allow_double_convertion();
extern const char * get_array_char_522_signature();
extern int compare_array_char_522_type(int*, const char*, const void*);
#define array_char_522_filter_size 522
extern FilterUtils get_array_char_522_filter_utils(const char* strFilter, void* pValue);
#define array_char_522_filter_values 0
/****************************************************************
 ** String
 ****************************************************************/
extern const char * String_to_string(const void* pValue);
extern int check_String_string(const char* strValue);
extern int string_to_String(const char* strValue, void* pValue);
int is_String_allow_double_convertion();
extern int String_to_double(double * nValue, const void*);
#define get_String_signature get_array_char_512_signature
#define compare_String_type compare_array_char_512_type
#define String_filter_size array_char_512_filter_size
#define get_String_filter_utils get_array_char_512_filter_utils
#define String_filter_values array_char_512_filter_values
/****************************************************************
 ** Path
 ****************************************************************/
extern const char * Path_to_string(const void* pValue);
extern int check_Path_string(const char* strValue);
extern int string_to_Path(const char* strValue, void* pValue);
int is_Path_allow_double_convertion();
extern int Path_to_double(double * nValue, const void*);
#define get_Path_signature get_array_char_256_signature
#define compare_Path_type compare_array_char_256_type
#define Path_filter_size array_char_256_filter_size
#define get_Path_filter_utils get_array_char_256_filter_utils
#define Path_filter_values array_char_256_filter_values

#endif /*MAIN_TYPES_CONVERTION */
