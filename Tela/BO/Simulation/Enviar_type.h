#ifndef ENVIAR_TYPES_CONVERTION
#define ENVIAR_TYPES_CONVERTION

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
extern TypeUtils _SCSIM_array_char_1000_Utils;
extern TypeUtils _SCSIM_array_char_20_Utils;
extern TypeUtils _SCSIM_struct__273_Utils;
extern TypeUtils _SCSIM_array_char_5_Utils;
extern TypeUtils _SCSIM_Name_Utils;
extern TypeUtils _SCSIM_String_Utils;
extern TypeUtils _SCSIM_BigText_Utils;
extern TypeUtils _SCSIM_Boletim_Utils;

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
 ** array_char_1000
 ****************************************************************/
extern const char * array_char_1000_to_string(const void* pValue);
extern int check_array_char_1000_string(const char* strValue);
extern int string_to_array_char_1000(const char* strValue, void* pValue);
int is_array_char_1000_allow_double_convertion();
extern const char * get_array_char_1000_signature();
extern int compare_array_char_1000_type(int*, const char*, const void*);
#define array_char_1000_filter_size 1000
extern FilterUtils get_array_char_1000_filter_utils(const char* strFilter, void* pValue);
#define array_char_1000_filter_values 0
/****************************************************************
 ** array_char_20
 ****************************************************************/
extern const char * array_char_20_to_string(const void* pValue);
extern int check_array_char_20_string(const char* strValue);
extern int string_to_array_char_20(const char* strValue, void* pValue);
int is_array_char_20_allow_double_convertion();
extern const char * get_array_char_20_signature();
extern int compare_array_char_20_type(int*, const char*, const void*);
#define array_char_20_filter_size 20
extern FilterUtils get_array_char_20_filter_utils(const char* strFilter, void* pValue);
#define array_char_20_filter_values 0
/****************************************************************
 ** struct__273
 ****************************************************************/
extern const char * struct__273_to_string(const void* pValue);
extern int check_struct__273_string(const char* strValue);
extern int string_to_struct__273(const char* strValue, void* pValue);
int is_struct__273_allow_double_convertion();
extern const char * get_struct__273_signature();
extern int compare_struct__273_type(int*, const char*, const void*);
#define struct__273_filter_size 8
extern FilterUtils get_struct__273_filter_utils(const char* strFilter, void* pValue);
extern const char * struct__273_filter_values[8];
/****************************************************************
 ** array_char_5
 ****************************************************************/
extern const char * array_char_5_to_string(const void* pValue);
extern int check_array_char_5_string(const char* strValue);
extern int string_to_array_char_5(const char* strValue, void* pValue);
int is_array_char_5_allow_double_convertion();
extern const char * get_array_char_5_signature();
extern int compare_array_char_5_type(int*, const char*, const void*);
#define array_char_5_filter_size 5
extern FilterUtils get_array_char_5_filter_utils(const char* strFilter, void* pValue);
#define array_char_5_filter_values 0
/****************************************************************
 ** Name
 ****************************************************************/
extern const char * Name_to_string(const void* pValue);
extern int check_Name_string(const char* strValue);
extern int string_to_Name(const char* strValue, void* pValue);
int is_Name_allow_double_convertion();
extern int Name_to_double(double * nValue, const void*);
#define get_Name_signature get_array_char_5_signature
#define compare_Name_type compare_array_char_5_type
#define Name_filter_size array_char_5_filter_size
#define get_Name_filter_utils get_array_char_5_filter_utils
#define Name_filter_values array_char_5_filter_values
/****************************************************************
 ** String
 ****************************************************************/
extern const char * String_to_string(const void* pValue);
extern int check_String_string(const char* strValue);
extern int string_to_String(const char* strValue, void* pValue);
int is_String_allow_double_convertion();
extern int String_to_double(double * nValue, const void*);
#define get_String_signature get_array_char_20_signature
#define compare_String_type compare_array_char_20_type
#define String_filter_size array_char_20_filter_size
#define get_String_filter_utils get_array_char_20_filter_utils
#define String_filter_values array_char_20_filter_values
/****************************************************************
 ** BigText
 ****************************************************************/
extern const char * BigText_to_string(const void* pValue);
extern int check_BigText_string(const char* strValue);
extern int string_to_BigText(const char* strValue, void* pValue);
int is_BigText_allow_double_convertion();
extern int BigText_to_double(double * nValue, const void*);
#define get_BigText_signature get_array_char_1000_signature
#define compare_BigText_type compare_array_char_1000_type
#define BigText_filter_size array_char_1000_filter_size
#define get_BigText_filter_utils get_array_char_1000_filter_utils
#define BigText_filter_values array_char_1000_filter_values
/****************************************************************
 ** Boletim
 ****************************************************************/
extern const char * Boletim_to_string(const void* pValue);
extern int check_Boletim_string(const char* strValue);
extern int string_to_Boletim(const char* strValue, void* pValue);
int is_Boletim_allow_double_convertion();
extern int Boletim_to_double(double * nValue, const void*);
#define get_Boletim_signature get_struct__273_signature
#define compare_Boletim_type compare_struct__273_type
#define Boletim_filter_size struct__273_filter_size
#define get_Boletim_filter_utils get_struct__273_filter_utils
#define Boletim_filter_values struct__273_filter_values

#endif /*ENVIAR_TYPES_CONVERTION */
