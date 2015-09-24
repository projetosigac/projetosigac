#include <stdlib.h>
#include <stddef.h>
#include "NewSmuTypes.h"
#include "kcg_types.h"
#include "BO_newtype.h"

#define skip_whitespace(str) while(*str == ' ' || *str == '\t') str++

/****************************************************************
 ** utility functions 
 ****************************************************************/

static int string_to_VTable(const char* str, const struct SimTypeVTable* pVTable, void* pValue, const char** endptr)
{
    int nRet;
    if (pVTable != NULL && pVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        nRet = pVTable->m_pfnFromType(SptString, (const void*)&str, pValue);
        if (nRet != 0)
            *endptr = str+strlen(str); /* TODO */
        return nRet;
    };
    return 0;
}

static int is_VTable_double_convertion_allowed(const struct SimTypeVTable* pVTable)
{
    if (pVTable != NULL) {
        int nConvertionAllowed = 0;
        nConvertionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
        nConvertionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
        nConvertionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
        nConvertionAllowed |= pVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
        return nConvertionAllowed;
    }
    return 1;
}

int VTable_to_double(const void *pValue, const struct SimTypeVTable* pVTable, double *nRetValue)
{
    if (pVTable != NULL) {
        if (pVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
            *nRetValue = (double)(*(long*)pVTable->m_pfnToType(SptLong, pValue));
        else if (pVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
            *nRetValue = (double)(*(int*)pVTable->m_pfnToType(SptShort, pValue));
        else if (pVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
            *nRetValue = (*(double*)pVTable->m_pfnToType(SptDouble, pValue));
        else if (pVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
            *nRetValue = (double)(*(float*)pVTable->m_pfnToType(SptFloat, pValue));
        else
            return 0;
    }
    return 1;
}

static int get_enum_signature(const EnumValUtils *pEnumVals, int nSize, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("E", pData);
    for(i=0; i<nSize; i++) {
        pfnStrAppend("|", pData);
        pfnStrAppend(pEnumVals[i].m_name, pData);
    }
    return 1;
}

static int get_structure_signature(const FieldUtils *pFields, int nSize, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for(i=0; i<nSize; i++) {
        if (i > 0)
            pfnStrAppend(",", pData);
        pfnStrAppend(pFields[i].m_name, pData);
    }
    pfnStrAppend(")", pData);
    return 1;
}

/****************************************************************
 ** SSM_ST_SM1 
 ****************************************************************/

struct SimTypeVTable* pSimSSM_ST_SM1VTable;

static EnumValUtils SSM_ST_SM1_values[] = {
    { "Espera_Enviar", SSM_st_Espera_Enviar_SM1},
    { "Espera_Enviar", SSM_st_Espera_Enviar_SM1},
    { "Enviando", SSM_st_Enviando_SM1},
    { "Enviando", SSM_st_Enviando_SM1},
};

int SSM_ST_SM1_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimSSM_ST_SM1VTable != NULL
        && pSimSSM_ST_SM1VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimSSM_ST_SM1VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(SSM_ST_SM1*)pValue, SSM_ST_SM1_values, 4, pfnStrAppend, pData);
}

int string_to_SSM_ST_SM1(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimSSM_ST_SM1VTable != NULL
        && pSimSSM_ST_SM1VTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimSSM_ST_SM1VTable, pValue, endptr);
    }
    {
        int nTemp = 0;
        int nRet = pConverter->m_pfnStringToEnum(str, &nTemp, SSM_ST_SM1_values, 4, endptr);
        if (pValue != NULL && nRet != 0)
            *(SSM_ST_SM1*)pValue = nTemp;
        return nRet;
    }
}

int is_SSM_ST_SM1_double_convertion_allowed()
{
    if (pSimSSM_ST_SM1VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimSSM_ST_SM1VTable);
    }
    return 1;
}

int compare_SSM_ST_SM1(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimSSM_ST_SM1VTable != NULL
        && pSimSSM_ST_SM1VTable->m_version >= Scv612
        && pSimSSM_ST_SM1VTable->m_pfnCompare != NULL)
        return pSimSSM_ST_SM1VTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnEnumComparison(pStatus, *(SSM_ST_SM1*)pValue1, *(SSM_ST_SM1*)pValue2, SSM_ST_SM1_values, 4, pData);
}

int SSM_ST_SM1_to_double(const void *pValue, double *nRetValue)
{
    if (pSimSSM_ST_SM1VTable != NULL) {
        return  VTable_to_double(pValue, pSimSSM_ST_SM1VTable, nRetValue);
    }
    *nRetValue = (double)*((SSM_ST_SM1*)pValue);
    return 1;
}

int get_SSM_ST_SM1_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    return get_enum_signature(SSM_ST_SM1_values, 4, pfnStrAppend, pData);
}

int set_SSM_ST_SM1_default_value(void *pValue)
{
    *(SSM_ST_SM1*)pValue = SSM_st_Espera_Enviar_SM1;
    return 1;
}

int check_SSM_ST_SM1_string(const char* str, const char** endptr)
{
    return string_to_SSM_ST_SM1(str, NULL, endptr);
}

TypeUtils _Type_SSM_ST_SM1_Utils = {
    SSM_ST_SM1_to_string,
    check_SSM_ST_SM1_string,
    string_to_SSM_ST_SM1,
    is_SSM_ST_SM1_double_convertion_allowed,
    SSM_ST_SM1_to_double,
    compare_SSM_ST_SM1,
    get_SSM_ST_SM1_signature,
    set_SSM_ST_SM1_default_value,
    sizeof(SSM_ST_SM1)
};

/****************************************************************
 ** SSM_TR_SM1 
 ****************************************************************/

struct SimTypeVTable* pSimSSM_TR_SM1VTable;

static EnumValUtils SSM_TR_SM1_values[] = {
    { "SSM_TR_SM1_no_trans", 0},
    { "SSM_TR_SM1_no_trans", 0},
    { "Espera_Enviar:<1>", SSM_TR_Espera_Enviar_1_SM1},
    { "Espera_Enviar:<1>", SSM_TR_Espera_Enviar_1_SM1},
    { "Enviando:<1>", SSM_TR_Enviando_1_SM1},
    { "Enviando:<1>", SSM_TR_Enviando_1_SM1},
};

int SSM_TR_SM1_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimSSM_TR_SM1VTable != NULL
        && pSimSSM_TR_SM1VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimSSM_TR_SM1VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnEnumToString(*(SSM_TR_SM1*)pValue, SSM_TR_SM1_values, 6, pfnStrAppend, pData);
}

int string_to_SSM_TR_SM1(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimSSM_TR_SM1VTable != NULL
        && pSimSSM_TR_SM1VTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimSSM_TR_SM1VTable, pValue, endptr);
    }
    {
        int nTemp = 0;
        int nRet = pConverter->m_pfnStringToEnum(str, &nTemp, SSM_TR_SM1_values, 6, endptr);
        if (pValue != NULL && nRet != 0)
            *(SSM_TR_SM1*)pValue = nTemp;
        return nRet;
    }
}

int is_SSM_TR_SM1_double_convertion_allowed()
{
    if (pSimSSM_TR_SM1VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimSSM_TR_SM1VTable);
    }
    return 1;
}

int compare_SSM_TR_SM1(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimSSM_TR_SM1VTable != NULL
        && pSimSSM_TR_SM1VTable->m_version >= Scv612
        && pSimSSM_TR_SM1VTable->m_pfnCompare != NULL)
        return pSimSSM_TR_SM1VTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnEnumComparison(pStatus, *(SSM_TR_SM1*)pValue1, *(SSM_TR_SM1*)pValue2, SSM_TR_SM1_values, 6, pData);
}

int SSM_TR_SM1_to_double(const void *pValue, double *nRetValue)
{
    if (pSimSSM_TR_SM1VTable != NULL) {
        return  VTable_to_double(pValue, pSimSSM_TR_SM1VTable, nRetValue);
    }
    *nRetValue = (double)*((SSM_TR_SM1*)pValue);
    return 1;
}

int get_SSM_TR_SM1_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    return get_enum_signature(SSM_TR_SM1_values, 6, pfnStrAppend, pData);
}

int set_SSM_TR_SM1_default_value(void *pValue)
{
    *(SSM_TR_SM1*)pValue = 0;
    return 1;
}

int check_SSM_TR_SM1_string(const char* str, const char** endptr)
{
    return string_to_SSM_TR_SM1(str, NULL, endptr);
}

TypeUtils _Type_SSM_TR_SM1_Utils = {
    SSM_TR_SM1_to_string,
    check_SSM_TR_SM1_string,
    string_to_SSM_TR_SM1,
    is_SSM_TR_SM1_double_convertion_allowed,
    SSM_TR_SM1_to_double,
    compare_SSM_TR_SM1,
    get_SSM_TR_SM1_signature,
    set_SSM_TR_SM1_default_value,
    sizeof(SSM_TR_SM1)
};

/****************************************************************
 ** kcg_real 
 ****************************************************************/

struct SimTypeVTable* pSimDoubleVTable;

int kcg_real_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimDoubleVTable != NULL
        && pSimDoubleVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimDoubleVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnRealToString((double)(*(const kcg_real*)pValue), pfnStrAppend, pData);
}

int string_to_kcg_real(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimDoubleVTable != NULL
        && pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimDoubleVTable, pValue, endptr);
    }
    {
        double nTemp = 0;
        int nRet = pConverter->m_pfnStringToReal(str, &nTemp, endptr);
        if (nRet != 0 && pValue != NULL)
            *(kcg_real*)pValue = (kcg_real)nTemp;
        return nRet;
    }
}

int is_kcg_real_double_convertion_allowed()
{
    if (pSimDoubleVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimDoubleVTable);
    }
    return 1;
}

int compare_kcg_real(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimDoubleVTable != NULL
        && pSimDoubleVTable->m_version >= Scv612
        && pSimDoubleVTable->m_pfnCompare != NULL)
        return pSimDoubleVTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnRealComparison(pStatus, (double)*(kcg_real*)pValue1, (double)*(kcg_real*)pValue2, pData);
}

int kcg_real_to_double(const void *pValue, double *nRetValue)
{
    if (pSimDoubleVTable != NULL) {
        return  VTable_to_double(pValue, pSimDoubleVTable, nRetValue);
    }
    *nRetValue = (double)*((kcg_real*)pValue);
    return 1;
}

int get_kcg_real_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    return pfnStrAppend("R", pData);
}

int set_kcg_real_default_value(void *pValue)
{
    *(kcg_real*)pValue = 0.0;
    return 1;
}

int check_kcg_real_string(const char* str, const char** endptr)
{
    return string_to_kcg_real(str, NULL, endptr);
}

TypeUtils _Type_kcg_real_Utils = {
    kcg_real_to_string,
    check_kcg_real_string,
    string_to_kcg_real,
    is_kcg_real_double_convertion_allowed,
    kcg_real_to_double,
    compare_kcg_real,
    get_kcg_real_signature,
    set_kcg_real_default_value,
    sizeof(kcg_real)
};

/****************************************************************
 ** kcg_bool 
 ****************************************************************/

struct SimTypeVTable* pSimBoolVTable;

int kcg_bool_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimBoolVTable != NULL
        && pSimBoolVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimBoolVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnBoolToString((*(const kcg_bool*)pValue) == kcg_true ? 1 : 0, pfnStrAppend, pData);
}

int string_to_kcg_bool(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimBoolVTable != NULL
        && pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimBoolVTable, pValue, endptr);
    }
    {
        int nTemp = 0;
        int nRet = pConverter->m_pfnStringToBool(str, &nTemp, endptr);
        if (nRet != 0 && pValue != NULL)
            *(kcg_bool*)pValue = nTemp == 1 ? kcg_true : kcg_false;
        return nRet;
    }
}

int is_kcg_bool_double_convertion_allowed()
{
    if (pSimBoolVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimBoolVTable);
    }
    return 1;
}

int compare_kcg_bool(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimBoolVTable != NULL
        && pSimBoolVTable->m_version >= Scv612
        && pSimBoolVTable->m_pfnCompare != NULL)
        return pSimBoolVTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnBoolComparison(pStatus, (int)*(kcg_bool*)pValue1, (int)*(kcg_bool*)pValue2, pData);
}

int kcg_bool_to_double(const void *pValue, double *nRetValue)
{
    if (pSimBoolVTable != NULL) {
        return  VTable_to_double(pValue, pSimBoolVTable, nRetValue);
    }
    *nRetValue = *((kcg_bool*)pValue) == kcg_true ? 1.0 : 0.0;
    return 1;
}

int get_kcg_bool_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    return pfnStrAppend("B", pData);
}

int set_kcg_bool_default_value(void *pValue)
{
    *(kcg_bool*)pValue = kcg_false;
    return 1;
}

int check_kcg_bool_string(const char* str, const char** endptr)
{
    return string_to_kcg_bool(str, NULL, endptr);
}

TypeUtils _Type_kcg_bool_Utils = {
    kcg_bool_to_string,
    check_kcg_bool_string,
    string_to_kcg_bool,
    is_kcg_bool_double_convertion_allowed,
    kcg_bool_to_double,
    compare_kcg_bool,
    get_kcg_bool_signature,
    set_kcg_bool_default_value,
    sizeof(kcg_bool)
};

/****************************************************************
 ** kcg_char 
 ****************************************************************/

struct SimTypeVTable* pSimCharVTable;

int kcg_char_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimCharVTable != NULL
        && pSimCharVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimCharVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnCharToString((char)(*(const kcg_char*)pValue), pfnStrAppend, pData);
}

int string_to_kcg_char(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimCharVTable != NULL
        && pSimCharVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimCharVTable, pValue, endptr);
    }
    {
        char nTemp = 0;
        int nRet = pConverter->m_pfnStringToChar(str, &nTemp, endptr);
        if (nRet != 0 && pValue != NULL)
            *(kcg_char*)pValue = (kcg_char)nTemp;
        return nRet;
    }
}

int is_kcg_char_double_convertion_allowed()
{
    if (pSimCharVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimCharVTable);
    }
    return 1;
}

int compare_kcg_char(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimCharVTable != NULL
        && pSimCharVTable->m_version >= Scv612
        && pSimCharVTable->m_pfnCompare != NULL)
        return pSimCharVTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnCharComparison(pStatus, (char)*(kcg_char*)pValue1, (char)*(kcg_char*)pValue2, pData);
}

int kcg_char_to_double(const void *pValue, double *nRetValue)
{
    if (pSimCharVTable != NULL) {
        return  VTable_to_double(pValue, pSimCharVTable, nRetValue);
    }
    *nRetValue = (double)*((kcg_char*)pValue);
    return 1;
}

int get_kcg_char_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    return pfnStrAppend("C", pData);
}

int set_kcg_char_default_value(void *pValue)
{
    *(kcg_char*)pValue = 0;
    return 1;
}

int check_kcg_char_string(const char* str, const char** endptr)
{
    return string_to_kcg_char(str, NULL, endptr);
}

TypeUtils _Type_kcg_char_Utils = {
    kcg_char_to_string,
    check_kcg_char_string,
    string_to_kcg_char,
    is_kcg_char_double_convertion_allowed,
    kcg_char_to_double,
    compare_kcg_char,
    get_kcg_char_signature,
    set_kcg_char_default_value,
    sizeof(kcg_char)
};

/****************************************************************
 ** kcg_int 
 ****************************************************************/

struct SimTypeVTable* pSimLongVTable;

int kcg_int_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimLongVTable != NULL
        && pSimLongVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimLongVTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnIntToString(*(const int*)pValue, pfnStrAppend, pData);
}

int string_to_kcg_int(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimLongVTable != NULL
        && pSimLongVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimLongVTable, pValue, endptr);
    }
    {
        int nTemp = 0;
        int nRet = pConverter->m_pfnStringToInt(str, &nTemp, endptr);
        if (nRet != 0 && pValue != NULL)
            *(kcg_int*)pValue = (kcg_int)nTemp;
        return nRet;
    }
}

int is_kcg_int_double_convertion_allowed()
{
    if (pSimLongVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimLongVTable);
    }
    return 1;
}

int compare_kcg_int(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimLongVTable != NULL
        && pSimLongVTable->m_version >= Scv612
        && pSimLongVTable->m_pfnCompare != NULL)
        return pSimLongVTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnIntComparison(pStatus, (int)*(kcg_int*)pValue1, (int)*(kcg_int*)pValue2, pData);
}

int kcg_int_to_double(const void *pValue, double *nRetValue)
{
    if (pSimLongVTable != NULL) {
        return  VTable_to_double(pValue, pSimLongVTable, nRetValue);
    }
    *nRetValue = (double)*((kcg_int*)pValue);
    return 1;
}

int get_kcg_int_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    return pfnStrAppend("I", pData);
}

int set_kcg_int_default_value(void *pValue)
{
    *(kcg_int*)pValue = 0;
    return 1;
}

int check_kcg_int_string(const char* str, const char** endptr)
{
    return string_to_kcg_int(str, NULL, endptr);
}

TypeUtils _Type_kcg_int_Utils = {
    kcg_int_to_string,
    check_kcg_int_string,
    string_to_kcg_int,
    is_kcg_int_double_convertion_allowed,
    kcg_int_to_double,
    compare_kcg_int,
    get_kcg_int_signature,
    set_kcg_int_default_value,
    sizeof(kcg_int)
};

/****************************************************************
 ** array_char_1000 
 ****************************************************************/

struct SimTypeVTable* pSimarray_char_1000VTable;

int array_char_1000_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimarray_char_1000VTable != NULL
        && pSimarray_char_1000VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimarray_char_1000VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_char_to_string, 1000, sizeof(kcg_char), pfnStrAppend, pData);
}

int string_to_array_char_1000(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimarray_char_1000VTable != NULL
        && pSimarray_char_1000VTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimarray_char_1000VTable, pValue, endptr);
    }
    return pConverter->m_pfnCharArrayFromString(str, pValue, string_to_kcg_char, 1000, sizeof(kcg_char), endptr);
}

int is_array_char_1000_double_convertion_allowed()
{
    if (pSimarray_char_1000VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_char_1000VTable);
    }
    return 0;
}

int compare_array_char_1000(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimarray_char_1000VTable != NULL
        && pSimarray_char_1000VTable->m_version >= Scv612
        && pSimarray_char_1000VTable->m_pfnCompare != NULL)
        return pSimarray_char_1000VTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnArrayComparison(pStatus, pValue1, pValue2, 
                compare_kcg_char, 1000, sizeof(kcg_char), pData);
}

int array_char_1000_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_char_1000VTable != NULL) {
        return  VTable_to_double(pValue, pSimarray_char_1000VTable, nRetValue);
    }
    return 0;
}

int get_array_char_1000_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 1000; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_char_signature(pfnStrAppend, pData);
    }
    return 1;
}

int set_array_char_1000_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 1000; i++)
        set_kcg_char_default_value(&((kcg_char*)pValue)[i]);
    return 1;
}

int check_array_char_1000_string(const char* str, const char** endptr)
{
    return string_to_array_char_1000(str, NULL, endptr);
}

TypeUtils _Type_array_char_1000_Utils = {
    array_char_1000_to_string,
    check_array_char_1000_string,
    string_to_array_char_1000,
    is_array_char_1000_double_convertion_allowed,
    array_char_1000_to_double,
    compare_array_char_1000,
    get_array_char_1000_signature,
    set_array_char_1000_default_value,
    sizeof(array_char_1000)
};

/****************************************************************
 ** array_char_20 
 ****************************************************************/

struct SimTypeVTable* pSimarray_char_20VTable;

int array_char_20_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimarray_char_20VTable != NULL
        && pSimarray_char_20VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimarray_char_20VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_char_to_string, 20, sizeof(kcg_char), pfnStrAppend, pData);
}

int string_to_array_char_20(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimarray_char_20VTable != NULL
        && pSimarray_char_20VTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimarray_char_20VTable, pValue, endptr);
    }
    return pConverter->m_pfnCharArrayFromString(str, pValue, string_to_kcg_char, 20, sizeof(kcg_char), endptr);
}

int is_array_char_20_double_convertion_allowed()
{
    if (pSimarray_char_20VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_char_20VTable);
    }
    return 0;
}

int compare_array_char_20(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimarray_char_20VTable != NULL
        && pSimarray_char_20VTable->m_version >= Scv612
        && pSimarray_char_20VTable->m_pfnCompare != NULL)
        return pSimarray_char_20VTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnArrayComparison(pStatus, pValue1, pValue2, 
                compare_kcg_char, 20, sizeof(kcg_char), pData);
}

int array_char_20_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_char_20VTable != NULL) {
        return  VTable_to_double(pValue, pSimarray_char_20VTable, nRetValue);
    }
    return 0;
}

int get_array_char_20_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 20; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_char_signature(pfnStrAppend, pData);
    }
    return 1;
}

int set_array_char_20_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 20; i++)
        set_kcg_char_default_value(&((kcg_char*)pValue)[i]);
    return 1;
}

int check_array_char_20_string(const char* str, const char** endptr)
{
    return string_to_array_char_20(str, NULL, endptr);
}

TypeUtils _Type_array_char_20_Utils = {
    array_char_20_to_string,
    check_array_char_20_string,
    string_to_array_char_20,
    is_array_char_20_double_convertion_allowed,
    array_char_20_to_double,
    compare_array_char_20,
    get_array_char_20_signature,
    set_array_char_20_default_value,
    sizeof(array_char_20)
};

/****************************************************************
 ** struct__273 
 ****************************************************************/

struct SimTypeVTable* pSimstruct__273VTable;

static FieldUtils struct__273_fields[] = {
    {"description", offsetof(struct__273,description), &_Type_array_char_1000_Utils},
    {"dt_fato", offsetof(struct__273,dt_fato), &_Type_array_char_20_Utils},
    {"hora_fato", offsetof(struct__273,hora_fato), &_Type_array_char_20_Utils},
    {"dt_ini_atend", offsetof(struct__273,dt_ini_atend), &_Type_array_char_20_Utils},
    {"hora_ini_atend", offsetof(struct__273,hora_ini_atend), &_Type_array_char_20_Utils},
    {"dt_fim_atend", offsetof(struct__273,dt_fim_atend), &_Type_array_char_20_Utils},
    {"hora_fim_atend", offsetof(struct__273,hora_fim_atend), &_Type_array_char_20_Utils},
    {"rg", offsetof(struct__273,rg), &_Type_array_char_20_Utils},
};

int struct__273_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimstruct__273VTable != NULL
        && pSimstruct__273VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimstruct__273VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnStructureToString(pValue, struct__273_fields, 8, pfnStrAppend, pData);
}

int string_to_struct__273(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimstruct__273VTable != NULL
        && pSimstruct__273VTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimstruct__273VTable, pValue, endptr);
    }
    return pConverter->m_pfnStringToStructure(str, pValue, struct__273_fields, 8, endptr);
}

int is_struct__273_double_convertion_allowed()
{
    if (pSimstruct__273VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimstruct__273VTable);
    }
    return 0;
}

int compare_struct__273(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimstruct__273VTable != NULL
        && pSimstruct__273VTable->m_version >= Scv612
        && pSimstruct__273VTable->m_pfnCompare != NULL)
        return pSimstruct__273VTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnStructureComparison(pStatus, pValue1, pValue2, struct__273_fields, 8, pData);
}

int struct__273_to_double(const void *pValue, double *nRetValue)
{
    if (pSimstruct__273VTable != NULL) {
        return  VTable_to_double(pValue, pSimstruct__273VTable, nRetValue);
    }
    return 0;
}

int get_struct__273_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    return get_structure_signature(struct__273_fields, 8, pfnStrAppend, pData);
}

int set_struct__273_default_value(void *pValue)
{
    set_array_char_1000_default_value(&(((struct__273*)pValue)->description));
    set_array_char_20_default_value(&(((struct__273*)pValue)->dt_fato));
    set_array_char_20_default_value(&(((struct__273*)pValue)->hora_fato));
    set_array_char_20_default_value(&(((struct__273*)pValue)->dt_ini_atend));
    set_array_char_20_default_value(&(((struct__273*)pValue)->hora_ini_atend));
    set_array_char_20_default_value(&(((struct__273*)pValue)->dt_fim_atend));
    set_array_char_20_default_value(&(((struct__273*)pValue)->hora_fim_atend));
    set_array_char_20_default_value(&(((struct__273*)pValue)->rg));
    return 1;
}

int check_struct__273_string(const char* str, const char** endptr)
{
    return string_to_struct__273(str, NULL, endptr);
}

TypeUtils _Type_struct__273_Utils = {
    struct__273_to_string,
    check_struct__273_string,
    string_to_struct__273,
    is_struct__273_double_convertion_allowed,
    struct__273_to_double,
    compare_struct__273,
    get_struct__273_signature,
    set_struct__273_default_value,
    sizeof(struct__273)
};

/****************************************************************
 ** array_char_5 
 ****************************************************************/

struct SimTypeVTable* pSimarray_char_5VTable;

int array_char_5_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimarray_char_5VTable != NULL
        && pSimarray_char_5VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimarray_char_5VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_char_to_string, 5, sizeof(kcg_char), pfnStrAppend, pData);
}

int string_to_array_char_5(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimarray_char_5VTable != NULL
        && pSimarray_char_5VTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimarray_char_5VTable, pValue, endptr);
    }
    return pConverter->m_pfnCharArrayFromString(str, pValue, string_to_kcg_char, 5, sizeof(kcg_char), endptr);
}

int is_array_char_5_double_convertion_allowed()
{
    if (pSimarray_char_5VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_char_5VTable);
    }
    return 0;
}

int compare_array_char_5(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimarray_char_5VTable != NULL
        && pSimarray_char_5VTable->m_version >= Scv612
        && pSimarray_char_5VTable->m_pfnCompare != NULL)
        return pSimarray_char_5VTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnArrayComparison(pStatus, pValue1, pValue2, 
                compare_kcg_char, 5, sizeof(kcg_char), pData);
}

int array_char_5_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_char_5VTable != NULL) {
        return  VTable_to_double(pValue, pSimarray_char_5VTable, nRetValue);
    }
    return 0;
}

int get_array_char_5_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 5; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_char_signature(pfnStrAppend, pData);
    }
    return 1;
}

int set_array_char_5_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 5; i++)
        set_kcg_char_default_value(&((kcg_char*)pValue)[i]);
    return 1;
}

int check_array_char_5_string(const char* str, const char** endptr)
{
    return string_to_array_char_5(str, NULL, endptr);
}

TypeUtils _Type_array_char_5_Utils = {
    array_char_5_to_string,
    check_array_char_5_string,
    string_to_array_char_5,
    is_array_char_5_double_convertion_allowed,
    array_char_5_to_double,
    compare_array_char_5,
    get_array_char_5_signature,
    set_array_char_5_default_value,
    sizeof(array_char_5)
};

/****************************************************************
 ** Name 
 ****************************************************************/

struct SimTypeVTable* pSimNameVTable;

int Name_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimNameVTable != NULL
        && pSimNameVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimNameVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array_char_5_to_string(pValue, pfnStrAppend, pData);
}

int string_to_Name(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimNameVTable != NULL
        && pSimNameVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimNameVTable, pValue, endptr);
    }
    return string_to_array_char_5(str, pValue, endptr);
}

int is_Name_double_convertion_allowed()
{
    if (pSimNameVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimNameVTable);
    }
    return is_array_char_5_double_convertion_allowed();
}

int compare_Name(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimNameVTable != NULL
        && pSimNameVTable->m_version >= Scv612
        && pSimNameVTable->m_pfnCompare != NULL)
        return pSimNameVTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return compare_array_char_5(pStatus, pValue1, pValue2, pData);
}

int Name_to_double(const void *pValue, double *nRetValue)
{
    if (pSimNameVTable != NULL) {
        return  VTable_to_double(pValue, pSimNameVTable, nRetValue);
    }
    return array_char_5_to_double(pValue, nRetValue);
}

int get_Name_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    return get_array_char_5_signature(pfnStrAppend, pData);
}

int set_Name_default_value(void *pValue)
{
    return set_array_char_5_default_value(pValue);
}

int check_Name_string(const char* str, const char** endptr)
{
    return string_to_Name(str, NULL, endptr);
}

TypeUtils _Type_Name_Utils = {
    Name_to_string,
    check_Name_string,
    string_to_Name,
    is_Name_double_convertion_allowed,
    Name_to_double,
    compare_Name,
    get_Name_signature,
    set_Name_default_value,
    sizeof(Name)
};

/****************************************************************
 ** String 
 ****************************************************************/

struct SimTypeVTable* pSimStringVTable;

int String_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimStringVTable != NULL
        && pSimStringVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimStringVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array_char_20_to_string(pValue, pfnStrAppend, pData);
}

int string_to_String(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimStringVTable != NULL
        && pSimStringVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimStringVTable, pValue, endptr);
    }
    return string_to_array_char_20(str, pValue, endptr);
}

int is_String_double_convertion_allowed()
{
    if (pSimStringVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimStringVTable);
    }
    return is_array_char_20_double_convertion_allowed();
}

int compare_String(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimStringVTable != NULL
        && pSimStringVTable->m_version >= Scv612
        && pSimStringVTable->m_pfnCompare != NULL)
        return pSimStringVTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return compare_array_char_20(pStatus, pValue1, pValue2, pData);
}

int String_to_double(const void *pValue, double *nRetValue)
{
    if (pSimStringVTable != NULL) {
        return  VTable_to_double(pValue, pSimStringVTable, nRetValue);
    }
    return array_char_20_to_double(pValue, nRetValue);
}

int get_String_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    return get_array_char_20_signature(pfnStrAppend, pData);
}

int set_String_default_value(void *pValue)
{
    return set_array_char_20_default_value(pValue);
}

int check_String_string(const char* str, const char** endptr)
{
    return string_to_String(str, NULL, endptr);
}

TypeUtils _Type_String_Utils = {
    String_to_string,
    check_String_string,
    string_to_String,
    is_String_double_convertion_allowed,
    String_to_double,
    compare_String,
    get_String_signature,
    set_String_default_value,
    sizeof(String)
};

/****************************************************************
 ** BigText 
 ****************************************************************/

struct SimTypeVTable* pSimBigTextVTable;

int BigText_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimBigTextVTable != NULL
        && pSimBigTextVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimBigTextVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array_char_1000_to_string(pValue, pfnStrAppend, pData);
}

int string_to_BigText(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimBigTextVTable != NULL
        && pSimBigTextVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimBigTextVTable, pValue, endptr);
    }
    return string_to_array_char_1000(str, pValue, endptr);
}

int is_BigText_double_convertion_allowed()
{
    if (pSimBigTextVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimBigTextVTable);
    }
    return is_array_char_1000_double_convertion_allowed();
}

int compare_BigText(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimBigTextVTable != NULL
        && pSimBigTextVTable->m_version >= Scv612
        && pSimBigTextVTable->m_pfnCompare != NULL)
        return pSimBigTextVTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return compare_array_char_1000(pStatus, pValue1, pValue2, pData);
}

int BigText_to_double(const void *pValue, double *nRetValue)
{
    if (pSimBigTextVTable != NULL) {
        return  VTable_to_double(pValue, pSimBigTextVTable, nRetValue);
    }
    return array_char_1000_to_double(pValue, nRetValue);
}

int get_BigText_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    return get_array_char_1000_signature(pfnStrAppend, pData);
}

int set_BigText_default_value(void *pValue)
{
    return set_array_char_1000_default_value(pValue);
}

int check_BigText_string(const char* str, const char** endptr)
{
    return string_to_BigText(str, NULL, endptr);
}

TypeUtils _Type_BigText_Utils = {
    BigText_to_string,
    check_BigText_string,
    string_to_BigText,
    is_BigText_double_convertion_allowed,
    BigText_to_double,
    compare_BigText,
    get_BigText_signature,
    set_BigText_default_value,
    sizeof(BigText)
};

/****************************************************************
 ** Boletim 
 ****************************************************************/

struct SimTypeVTable* pSimBoletimVTable;

int Boletim_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimBoletimVTable != NULL
        && pSimBoletimVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimBoletimVTable->m_pfnToType(SptString, pValue), pData);
    }
    return struct__273_to_string(pValue, pfnStrAppend, pData);
}

int string_to_Boletim(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimBoletimVTable != NULL
        && pSimBoletimVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimBoletimVTable, pValue, endptr);
    }
    return string_to_struct__273(str, pValue, endptr);
}

int is_Boletim_double_convertion_allowed()
{
    if (pSimBoletimVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimBoletimVTable);
    }
    return is_struct__273_double_convertion_allowed();
}

int compare_Boletim(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimBoletimVTable != NULL
        && pSimBoletimVTable->m_version >= Scv612
        && pSimBoletimVTable->m_pfnCompare != NULL)
        return pSimBoletimVTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return compare_struct__273(pStatus, pValue1, pValue2, pData);
}

int Boletim_to_double(const void *pValue, double *nRetValue)
{
    if (pSimBoletimVTable != NULL) {
        return  VTable_to_double(pValue, pSimBoletimVTable, nRetValue);
    }
    return struct__273_to_double(pValue, nRetValue);
}

int get_Boletim_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    return get_struct__273_signature(pfnStrAppend, pData);
}

int set_Boletim_default_value(void *pValue)
{
    return set_struct__273_default_value(pValue);
}

int check_Boletim_string(const char* str, const char** endptr)
{
    return string_to_Boletim(str, NULL, endptr);
}

TypeUtils _Type_Boletim_Utils = {
    Boletim_to_string,
    check_Boletim_string,
    string_to_Boletim,
    is_Boletim_double_convertion_allowed,
    Boletim_to_double,
    compare_Boletim,
    get_Boletim_signature,
    set_Boletim_default_value,
    sizeof(Boletim)
};

