#include <stdlib.h>
#include <stddef.h>
#include "NewSmuTypes.h"
#include "kcg_types.h"
#include "REST-API_newtype.h"

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
 ** array_char_512 
 ****************************************************************/

struct SimTypeVTable* pSimarray_char_512VTable;

int array_char_512_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimarray_char_512VTable != NULL
        && pSimarray_char_512VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimarray_char_512VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_char_to_string, 512, sizeof(kcg_char), pfnStrAppend, pData);
}

int string_to_array_char_512(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimarray_char_512VTable != NULL
        && pSimarray_char_512VTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimarray_char_512VTable, pValue, endptr);
    }
    return pConverter->m_pfnCharArrayFromString(str, pValue, string_to_kcg_char, 512, sizeof(kcg_char), endptr);
}

int is_array_char_512_double_convertion_allowed()
{
    if (pSimarray_char_512VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_char_512VTable);
    }
    return 0;
}

int compare_array_char_512(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimarray_char_512VTable != NULL
        && pSimarray_char_512VTable->m_version >= Scv612
        && pSimarray_char_512VTable->m_pfnCompare != NULL)
        return pSimarray_char_512VTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnArrayComparison(pStatus, pValue1, pValue2, 
                compare_kcg_char, 512, sizeof(kcg_char), pData);
}

int array_char_512_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_char_512VTable != NULL) {
        return  VTable_to_double(pValue, pSimarray_char_512VTable, nRetValue);
    }
    return 0;
}

int get_array_char_512_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 512; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_char_signature(pfnStrAppend, pData);
    }
    return 1;
}

int set_array_char_512_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 512; i++)
        set_kcg_char_default_value(&((kcg_char*)pValue)[i]);
    return 1;
}

int check_array_char_512_string(const char* str, const char** endptr)
{
    return string_to_array_char_512(str, NULL, endptr);
}

TypeUtils _Type_array_char_512_Utils = {
    array_char_512_to_string,
    check_array_char_512_string,
    string_to_array_char_512,
    is_array_char_512_double_convertion_allowed,
    array_char_512_to_double,
    compare_array_char_512,
    get_array_char_512_signature,
    set_array_char_512_default_value,
    sizeof(array_char_512)
};

/****************************************************************
 ** array_char_256 
 ****************************************************************/

struct SimTypeVTable* pSimarray_char_256VTable;

int array_char_256_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimarray_char_256VTable != NULL
        && pSimarray_char_256VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimarray_char_256VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_char_to_string, 256, sizeof(kcg_char), pfnStrAppend, pData);
}

int string_to_array_char_256(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimarray_char_256VTable != NULL
        && pSimarray_char_256VTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimarray_char_256VTable, pValue, endptr);
    }
    return pConverter->m_pfnCharArrayFromString(str, pValue, string_to_kcg_char, 256, sizeof(kcg_char), endptr);
}

int is_array_char_256_double_convertion_allowed()
{
    if (pSimarray_char_256VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_char_256VTable);
    }
    return 0;
}

int compare_array_char_256(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimarray_char_256VTable != NULL
        && pSimarray_char_256VTable->m_version >= Scv612
        && pSimarray_char_256VTable->m_pfnCompare != NULL)
        return pSimarray_char_256VTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnArrayComparison(pStatus, pValue1, pValue2, 
                compare_kcg_char, 256, sizeof(kcg_char), pData);
}

int array_char_256_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_char_256VTable != NULL) {
        return  VTable_to_double(pValue, pSimarray_char_256VTable, nRetValue);
    }
    return 0;
}

int get_array_char_256_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 256; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_char_signature(pfnStrAppend, pData);
    }
    return 1;
}

int set_array_char_256_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 256; i++)
        set_kcg_char_default_value(&((kcg_char*)pValue)[i]);
    return 1;
}

int check_array_char_256_string(const char* str, const char** endptr)
{
    return string_to_array_char_256(str, NULL, endptr);
}

TypeUtils _Type_array_char_256_Utils = {
    array_char_256_to_string,
    check_array_char_256_string,
    string_to_array_char_256,
    is_array_char_256_double_convertion_allowed,
    array_char_256_to_double,
    compare_array_char_256,
    get_array_char_256_signature,
    set_array_char_256_default_value,
    sizeof(array_char_256)
};

/****************************************************************
 ** array_char_10 
 ****************************************************************/

struct SimTypeVTable* pSimarray_char_10VTable;

int array_char_10_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimarray_char_10VTable != NULL
        && pSimarray_char_10VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimarray_char_10VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_char_to_string, 10, sizeof(kcg_char), pfnStrAppend, pData);
}

int string_to_array_char_10(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimarray_char_10VTable != NULL
        && pSimarray_char_10VTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimarray_char_10VTable, pValue, endptr);
    }
    return pConverter->m_pfnCharArrayFromString(str, pValue, string_to_kcg_char, 10, sizeof(kcg_char), endptr);
}

int is_array_char_10_double_convertion_allowed()
{
    if (pSimarray_char_10VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_char_10VTable);
    }
    return 0;
}

int compare_array_char_10(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimarray_char_10VTable != NULL
        && pSimarray_char_10VTable->m_version >= Scv612
        && pSimarray_char_10VTable->m_pfnCompare != NULL)
        return pSimarray_char_10VTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnArrayComparison(pStatus, pValue1, pValue2, 
                compare_kcg_char, 10, sizeof(kcg_char), pData);
}

int array_char_10_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_char_10VTable != NULL) {
        return  VTable_to_double(pValue, pSimarray_char_10VTable, nRetValue);
    }
    return 0;
}

int get_array_char_10_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 10; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_char_signature(pfnStrAppend, pData);
    }
    return 1;
}

int set_array_char_10_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 10; i++)
        set_kcg_char_default_value(&((kcg_char*)pValue)[i]);
    return 1;
}

int check_array_char_10_string(const char* str, const char** endptr)
{
    return string_to_array_char_10(str, NULL, endptr);
}

TypeUtils _Type_array_char_10_Utils = {
    array_char_10_to_string,
    check_array_char_10_string,
    string_to_array_char_10,
    is_array_char_10_double_convertion_allowed,
    array_char_10_to_double,
    compare_array_char_10,
    get_array_char_10_signature,
    set_array_char_10_default_value,
    sizeof(array_char_10)
};

/****************************************************************
 ** array_char_522 
 ****************************************************************/

struct SimTypeVTable* pSimarray_char_522VTable;

int array_char_522_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimarray_char_522VTable != NULL
        && pSimarray_char_522VTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimarray_char_522VTable->m_pfnToType(SptString, pValue), pData);
    }
    return pConverter->m_pfnArrayToString(pValue, kcg_char_to_string, 522, sizeof(kcg_char), pfnStrAppend, pData);
}

int string_to_array_char_522(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimarray_char_522VTable != NULL
        && pSimarray_char_522VTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimarray_char_522VTable, pValue, endptr);
    }
    return pConverter->m_pfnCharArrayFromString(str, pValue, string_to_kcg_char, 522, sizeof(kcg_char), endptr);
}

int is_array_char_522_double_convertion_allowed()
{
    if (pSimarray_char_522VTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimarray_char_522VTable);
    }
    return 0;
}

int compare_array_char_522(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimarray_char_522VTable != NULL
        && pSimarray_char_522VTable->m_version >= Scv612
        && pSimarray_char_522VTable->m_pfnCompare != NULL)
        return pSimarray_char_522VTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return pConverter->m_pfnArrayComparison(pStatus, pValue1, pValue2, 
                compare_kcg_char, 522, sizeof(kcg_char), pData);
}

int array_char_522_to_double(const void *pValue, double *nRetValue)
{
    if (pSimarray_char_522VTable != NULL) {
        return  VTable_to_double(pValue, pSimarray_char_522VTable, nRetValue);
    }
    return 0;
}

int get_array_char_522_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    int i;
    pfnStrAppend("(", pData);
    for (i = 0; i < 522; i++) {
        if(i > 0)
            pfnStrAppend(",", pData);
        get_kcg_char_signature(pfnStrAppend, pData);
    }
    return 1;
}

int set_array_char_522_default_value(void *pValue)
{
    int i;
    for (i = 0; i < 522; i++)
        set_kcg_char_default_value(&((kcg_char*)pValue)[i]);
    return 1;
}

int check_array_char_522_string(const char* str, const char** endptr)
{
    return string_to_array_char_522(str, NULL, endptr);
}

TypeUtils _Type_array_char_522_Utils = {
    array_char_522_to_string,
    check_array_char_522_string,
    string_to_array_char_522,
    is_array_char_522_double_convertion_allowed,
    array_char_522_to_double,
    compare_array_char_522,
    get_array_char_522_signature,
    set_array_char_522_default_value,
    sizeof(array_char_522)
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
    return array_char_512_to_string(pValue, pfnStrAppend, pData);
}

int string_to_String(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimStringVTable != NULL
        && pSimStringVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimStringVTable, pValue, endptr);
    }
    return string_to_array_char_512(str, pValue, endptr);
}

int is_String_double_convertion_allowed()
{
    if (pSimStringVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimStringVTable);
    }
    return is_array_char_512_double_convertion_allowed();
}

int compare_String(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimStringVTable != NULL
        && pSimStringVTable->m_version >= Scv612
        && pSimStringVTable->m_pfnCompare != NULL)
        return pSimStringVTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return compare_array_char_512(pStatus, pValue1, pValue2, pData);
}

int String_to_double(const void *pValue, double *nRetValue)
{
    if (pSimStringVTable != NULL) {
        return  VTable_to_double(pValue, pSimStringVTable, nRetValue);
    }
    return array_char_512_to_double(pValue, nRetValue);
}

int get_String_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    return get_array_char_512_signature(pfnStrAppend, pData);
}

int set_String_default_value(void *pValue)
{
    return set_array_char_512_default_value(pValue);
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
 ** Path 
 ****************************************************************/

struct SimTypeVTable* pSimPathVTable;

int Path_to_string(const void* pValue, int (*pfnStrAppend)(const char *str, void *pData), void *pData)
{
    if (pSimPathVTable != NULL
        && pSimPathVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
        return pfnStrAppend(*(char**)pSimPathVTable->m_pfnToType(SptString, pValue), pData);
    }
    return array_char_256_to_string(pValue, pfnStrAppend, pData);
}

int string_to_Path(const char* str, void* pValue, const char** endptr)
{
    skip_whitespace(str);
    if (pSimPathVTable != NULL
        && pSimPathVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
        return string_to_VTable(str, pSimPathVTable, pValue, endptr);
    }
    return string_to_array_char_256(str, pValue, endptr);
}

int is_Path_double_convertion_allowed()
{
    if (pSimPathVTable != NULL) {
        return is_VTable_double_convertion_allowed(pSimPathVTable);
    }
    return is_array_char_256_double_convertion_allowed();
}

int compare_Path(int *pStatus, const void* pValue1, const void* pValue2, void *pData)
{
    if (pSimPathVTable != NULL
        && pSimPathVTable->m_version >= Scv612
        && pSimPathVTable->m_pfnCompare != NULL)
        return pSimPathVTable->m_pfnCompare(pStatus, pValue1, pValue2);
    return compare_array_char_256(pStatus, pValue1, pValue2, pData);
}

int Path_to_double(const void *pValue, double *nRetValue)
{
    if (pSimPathVTable != NULL) {
        return  VTable_to_double(pValue, pSimPathVTable, nRetValue);
    }
    return array_char_256_to_double(pValue, nRetValue);
}

int get_Path_signature(int (*pfnStrAppend)(const char* str, void *pData), void *pData)
{
    return get_array_char_256_signature(pfnStrAppend, pData);
}

int set_Path_default_value(void *pValue)
{
    return set_array_char_256_default_value(pValue);
}

int check_Path_string(const char* str, const char** endptr)
{
    return string_to_Path(str, NULL, endptr);
}

TypeUtils _Type_Path_Utils = {
    Path_to_string,
    check_Path_string,
    string_to_Path,
    is_Path_double_convertion_allowed,
    Path_to_double,
    compare_Path,
    get_Path_signature,
    set_Path_default_value,
    sizeof(Path)
};

