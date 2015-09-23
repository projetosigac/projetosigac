
#include <stdlib.h>
#include "SmuTypes.h"
#include "kcg_types.h"
#include "Main_type.h"
#include "Main_mapping.h"

extern ScSimulator * pSimulator;

/****************************************************************
 ** Boolean entity activation
 ****************************************************************/
int _SCSIM_BoolEntity_is_active(void* pValue) {
	return *((kcg_bool*)pValue) == kcg_true ? 1 : 0;
}

/****************************************************************
 ** Type utils declarations
 ****************************************************************/
TypeUtils _SCSIM_kcg_real_Utils = {kcg_real_to_string,
	check_kcg_real_string,
	string_to_kcg_real,
	is_kcg_real_allow_double_convertion,
	kcg_real_to_double,
	compare_kcg_real_type,
	get_kcg_real_signature,
	get_kcg_real_filter_utils,
	kcg_real_filter_size,
	kcg_real_filter_values};
TypeUtils _SCSIM_kcg_bool_Utils = {kcg_bool_to_string,
	check_kcg_bool_string,
	string_to_kcg_bool,
	is_kcg_bool_allow_double_convertion,
	kcg_bool_to_double,
	compare_kcg_bool_type,
	get_kcg_bool_signature,
	get_kcg_bool_filter_utils,
	kcg_bool_filter_size,
	kcg_bool_filter_values};
TypeUtils _SCSIM_kcg_char_Utils = {kcg_char_to_string,
	check_kcg_char_string,
	string_to_kcg_char,
	is_kcg_char_allow_double_convertion,
	kcg_char_to_double,
	compare_kcg_char_type,
	get_kcg_char_signature,
	get_kcg_char_filter_utils,
	kcg_char_filter_size,
	kcg_char_filter_values};
TypeUtils _SCSIM_kcg_int_Utils = {kcg_int_to_string,
	check_kcg_int_string,
	string_to_kcg_int,
	is_kcg_int_allow_double_convertion,
	kcg_int_to_double,
	compare_kcg_int_type,
	get_kcg_int_signature,
	get_kcg_int_filter_utils,
	kcg_int_filter_size,
	kcg_int_filter_values};
TypeUtils _SCSIM_array_char_512_Utils = {array_char_512_to_string,
	check_array_char_512_string,
	string_to_array_char_512,
	is_array_char_512_allow_double_convertion,
	0,
	compare_array_char_512_type,
	get_array_char_512_signature,
	get_array_char_512_filter_utils,
	array_char_512_filter_size,
	array_char_512_filter_values};
TypeUtils _SCSIM_array_char_256_Utils = {array_char_256_to_string,
	check_array_char_256_string,
	string_to_array_char_256,
	is_array_char_256_allow_double_convertion,
	0,
	compare_array_char_256_type,
	get_array_char_256_signature,
	get_array_char_256_filter_utils,
	array_char_256_filter_size,
	array_char_256_filter_values};
TypeUtils _SCSIM_array_char_10_Utils = {array_char_10_to_string,
	check_array_char_10_string,
	string_to_array_char_10,
	is_array_char_10_allow_double_convertion,
	0,
	compare_array_char_10_type,
	get_array_char_10_signature,
	get_array_char_10_filter_utils,
	array_char_10_filter_size,
	array_char_10_filter_values};
TypeUtils _SCSIM_array_char_522_Utils = {array_char_522_to_string,
	check_array_char_522_string,
	string_to_array_char_522,
	is_array_char_522_allow_double_convertion,
	0,
	compare_array_char_522_type,
	get_array_char_522_signature,
	get_array_char_522_filter_utils,
	array_char_522_filter_size,
	array_char_522_filter_values};
TypeUtils _SCSIM_String_Utils = {String_to_string,
	check_String_string,
	string_to_String,
	is_String_allow_double_convertion,
	String_to_double,
	compare_String_type,
	get_String_signature,
	get_String_filter_utils,
	String_filter_size,
	String_filter_values};
TypeUtils _SCSIM_Path_Utils = {Path_to_string,
	check_Path_string,
	string_to_Path,
	is_Path_allow_double_convertion,
	Path_to_double,
	compare_Path_type,
	get_Path_signature,
	get_Path_filter_utils,
	Path_filter_size,
	Path_filter_values};

/****************************************************************
 ** kcg_real
 ****************************************************************/
struct SimTypeVTable* pSimDoubleVTable;
const char * kcg_real_to_string(const void* pValue) {
	if (pSimDoubleVTable != 0 && pSimDoubleVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
		double value = (double)(*(const kcg_real*)pValue);
		return *(char**)pSimDoubleVTable->m_pfnToType(SptString, &value);
	}
	return pSimulator->m_pfnRealToString((double)(*(const kcg_real*)pValue));
}

int string_to_kcg_real(const char* strValue, void* pValue) {
	double nTemp = 0;
	static double rTemp;
	int nResult;
	if (pSimDoubleVTable != 0 && pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		nResult = pSimDoubleVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*(kcg_real*)pValue = (kcg_real)rTemp;
		return nResult;
	}
	nResult = pSimulator->m_pfnStringToReal(strValue, &nTemp);
	if (nResult == 1)
		*(kcg_real*)pValue = (kcg_real)nTemp;
	return nResult;
}

int compare_kcg_real_type(int* pResult, const char* toCompare, const void* pValue) {
	static kcg_real rTemp;
	const kcg_real* pCurrent = (const kcg_real*)pValue;
	if (string_to_kcg_real(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

int is_kcg_real_allow_double_convertion() {
	if (pSimDoubleVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return 1;
}

int kcg_real_to_double(double * nValue, const void* pValue) {
	if (pSimDoubleVTable != 0) {
		double value = (double)(*(const kcg_real*)pValue);
		if (pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimDoubleVTable->m_pfnToType(SptDouble, &value));
		else if (pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimDoubleVTable->m_pfnToType(SptFloat, &value));
		else if (pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimDoubleVTable->m_pfnToType(SptLong, &value));
		else if (pSimDoubleVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimDoubleVTable->m_pfnToType(SptShort, &value));
		else
			return 0;
		return 1;
	}
	*nValue = (double)*((const kcg_real*)pValue);
	return 1;
}

const char * get_kcg_real_signature() {
	return "R";
}

int check_kcg_real_string(const char* strValue) {
	static kcg_real rTemp;
	return string_to_kcg_real(strValue, &rTemp);
}


/****************************************************************
 ** kcg_bool
 ****************************************************************/
struct SimTypeVTable* pSimBoolVTable;
const char * kcg_bool_to_string(const void* pValue) {
	if (pSimBoolVTable != 0 && pSimBoolVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
		SimBool value = (*((const kcg_bool*)pValue) == kcg_true)? SbTrue : SbFalse;
		return *(char**)pSimBoolVTable->m_pfnToType(SptString, &value);
	}
	return pSimulator->m_pfnBoolToString((*(const kcg_bool*)pValue) == kcg_true ? 1 : 0);
}

int string_to_kcg_bool(const char* strValue, void* pValue) {
	int nTemp = 0;
	static SimBool rTemp;
	int nResult;
	if (pSimBoolVTable != 0 && pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		nResult = pSimBoolVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*((kcg_bool*)pValue) = (rTemp == SbTrue)? kcg_true : kcg_false;
		return nResult;
	}
	nResult = pSimulator->m_pfnStringToBool(strValue, &nTemp);
	if (nResult == 1)
		*(kcg_bool*)pValue = nTemp == 1 ? kcg_true : kcg_false;
	return nResult;
}

int compare_kcg_bool_type(int* pResult, const char* toCompare, const void* pValue) {
	static kcg_bool rTemp;
	const kcg_bool* pCurrent = (const kcg_bool*)pValue;
	if (string_to_kcg_bool(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

int is_kcg_bool_allow_double_convertion() {
	if (pSimBoolVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return 1;
}

int kcg_bool_to_double(double * nValue, const void* pValue) {
	if (pSimBoolVTable != 0) {
		SimBool value = (*(const kcg_bool*)pValue == kcg_true)? SbTrue : SbFalse;
		if (pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimBoolVTable->m_pfnToType(SptDouble, &value));
		else if (pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimBoolVTable->m_pfnToType(SptFloat, &value));
		else if (pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimBoolVTable->m_pfnToType(SptLong, &value));
		else if (pSimBoolVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimBoolVTable->m_pfnToType(SptShort, &value));
		else
			return 0;
		return 1;
	}
	*nValue = *((const kcg_bool*)pValue) == kcg_true ? 1.0 : 0.0;
	return 1;
}

const char * get_kcg_bool_signature() {
	return "B";
}

int check_kcg_bool_string(const char* strValue) {
	static kcg_bool rTemp;
	return string_to_kcg_bool(strValue, &rTemp);
}


/****************************************************************
 ** kcg_char
 ****************************************************************/
struct SimTypeVTable* pSimCharVTable;
const char * kcg_char_to_string(const void* pValue) {
	if (pSimCharVTable != 0 && pSimCharVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
		char value = (char)(*(const kcg_char*)pValue);
		return *(char**)pSimCharVTable->m_pfnToType(SptString, &value);
	}
	return pSimulator->m_pfnCharToString((char)(*(const kcg_char*)pValue));
}

int string_to_kcg_char(const char* strValue, void* pValue) {
	char nTemp = 0;
	static char rTemp;
	int nResult;
	if (pSimCharVTable != 0 && pSimCharVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		nResult = pSimCharVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*(kcg_char*)pValue = (kcg_char)rTemp;
		return nResult;
	}
	nResult = pSimulator->m_pfnStringToChar(strValue, &nTemp);
	if (nResult == 1)
		*(kcg_char*)pValue = (kcg_char)nTemp;
	return nResult;
}

int compare_kcg_char_type(int* pResult, const char* toCompare, const void* pValue) {
	static kcg_char rTemp;
	const kcg_char* pCurrent = (const kcg_char*)pValue;
	if (string_to_kcg_char(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

int is_kcg_char_allow_double_convertion() {
	if (pSimCharVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimCharVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimCharVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimCharVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimCharVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return 1;
}

int kcg_char_to_double(double * nValue, const void* pValue) {
	if (pSimCharVTable != 0) {
		char value = (char)(*(const kcg_char*)pValue);
		if (pSimCharVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimCharVTable->m_pfnToType(SptDouble, &value));
		else if (pSimCharVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimCharVTable->m_pfnToType(SptFloat, &value));
		else if (pSimCharVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimCharVTable->m_pfnToType(SptLong, &value));
		else if (pSimCharVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimCharVTable->m_pfnToType(SptShort, &value));
		else
			return 0;
		return 1;
	}
	*nValue = (double)*((const kcg_char*)pValue);
	return 1;
}

const char * get_kcg_char_signature() {
	return "C";
}

int check_kcg_char_string(const char* strValue) {
	static kcg_char rTemp;
	return string_to_kcg_char(strValue, &rTemp);
}


/****************************************************************
 ** kcg_int
 ****************************************************************/
struct SimTypeVTable* pSimLongVTable;
const char * kcg_int_to_string(const void* pValue) {
	if (pSimLongVTable != 0 && pSimLongVTable->m_pfnGetConvInfo(SptString, SptNone) == 1) {
		long value = (long)(*(const kcg_int*)pValue);
		return *(char**)pSimLongVTable->m_pfnToType(SptString, &value);
	}
	return pSimulator->m_pfnIntToString(*(const int*)pValue);
}

int string_to_kcg_int(const char* strValue, void* pValue) {
	int nTemp = 0;
	static long rTemp;
	int nResult;
	if (pSimLongVTable != 0 && pSimLongVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		nResult = pSimLongVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			*(kcg_int*)pValue = (kcg_int)rTemp;
		return nResult;
	}
	nResult = pSimulator->m_pfnStringToInt(strValue, &nTemp);
	if (nResult == 1)
		*(kcg_int*)pValue = (kcg_int)nTemp;
	return nResult;
}

int compare_kcg_int_type(int* pResult, const char* toCompare, const void* pValue) {
	static kcg_int rTemp;
	const kcg_int* pCurrent = (const kcg_int*)pValue;
	if (string_to_kcg_int(toCompare, &rTemp) == 0)
		return 0;
	if (*pCurrent > rTemp)
		*pResult = 1;
	else if (*pCurrent < rTemp)
		*pResult = -1;
	else
		*pResult = 0;
	return 1;
}

int is_kcg_int_allow_double_convertion() {
	if (pSimLongVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimLongVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimLongVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimLongVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimLongVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return 1;
}

int kcg_int_to_double(double * nValue, const void* pValue) {
	if (pSimLongVTable != 0) {
		long value = (long)(*(const kcg_int*)pValue);
		if (pSimLongVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimLongVTable->m_pfnToType(SptDouble, &value));
		else if (pSimLongVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimLongVTable->m_pfnToType(SptFloat, &value));
		else if (pSimLongVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimLongVTable->m_pfnToType(SptLong, &value));
		else if (pSimLongVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimLongVTable->m_pfnToType(SptShort, &value));
		else
			return 0;
		return 1;
	}
	*nValue = (double)*((const kcg_int*)pValue);
	return 1;
}

const char * get_kcg_int_signature() {
	return "I";
}

int check_kcg_int_string(const char* strValue) {
	static kcg_int rTemp;
	return string_to_kcg_int(strValue, &rTemp);
}


/****************************************************************
 ** array_char_512
 ****************************************************************/
void* array_char_512_projection(void** pValues, int nIndex) {
	return &((*(array_char_512*)pValues)[nIndex]);
}

const char * array_char_512_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnCharArrayToString((const void**)pValue, kcg_char_to_string, 512, array_char_512_projection);
}

int compare_array_char_512_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_char_type , 512, array_char_512_projection);
}

int is_array_char_512_allow_double_convertion() {
	return 0;
}

int string_to_array_char_512(const char* strValue, void* pValue) {
	static array_char_512 rTemp;
	int nResult = pSimulator->m_pfnCharArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_char, 512, array_char_512_projection);
	if (nResult == 1)
		kcg_copy_array_char_512(&(*((array_char_512*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_char_512_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_char_signature, 512);
}

FilterUtils get_array_char_512_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_char_Utils, strFilter, (void**)pValue, 512, array_char_512_projection);
}

int check_array_char_512_string(const char* strValue) {
	static array_char_512 rTemp;
	return string_to_array_char_512(strValue, &rTemp);
}


/****************************************************************
 ** array_char_256
 ****************************************************************/
void* array_char_256_projection(void** pValues, int nIndex) {
	return &((*(array_char_256*)pValues)[nIndex]);
}

const char * array_char_256_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnCharArrayToString((const void**)pValue, kcg_char_to_string, 256, array_char_256_projection);
}

int compare_array_char_256_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_char_type , 256, array_char_256_projection);
}

int is_array_char_256_allow_double_convertion() {
	return 0;
}

int string_to_array_char_256(const char* strValue, void* pValue) {
	static array_char_256 rTemp;
	int nResult = pSimulator->m_pfnCharArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_char, 256, array_char_256_projection);
	if (nResult == 1)
		kcg_copy_array_char_256(&(*((array_char_256*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_char_256_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_char_signature, 256);
}

FilterUtils get_array_char_256_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_char_Utils, strFilter, (void**)pValue, 256, array_char_256_projection);
}

int check_array_char_256_string(const char* strValue) {
	static array_char_256 rTemp;
	return string_to_array_char_256(strValue, &rTemp);
}


/****************************************************************
 ** array_char_10
 ****************************************************************/
void* array_char_10_projection(void** pValues, int nIndex) {
	return &((*(array_char_10*)pValues)[nIndex]);
}

const char * array_char_10_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnCharArrayToString((const void**)pValue, kcg_char_to_string, 10, array_char_10_projection);
}

int compare_array_char_10_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_char_type , 10, array_char_10_projection);
}

int is_array_char_10_allow_double_convertion() {
	return 0;
}

int string_to_array_char_10(const char* strValue, void* pValue) {
	static array_char_10 rTemp;
	int nResult = pSimulator->m_pfnCharArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_char, 10, array_char_10_projection);
	if (nResult == 1)
		kcg_copy_array_char_10(&(*((array_char_10*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_char_10_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_char_signature, 10);
}

FilterUtils get_array_char_10_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_char_Utils, strFilter, (void**)pValue, 10, array_char_10_projection);
}

int check_array_char_10_string(const char* strValue) {
	static array_char_10 rTemp;
	return string_to_array_char_10(strValue, &rTemp);
}


/****************************************************************
 ** array_char_522
 ****************************************************************/
void* array_char_522_projection(void** pValues, int nIndex) {
	return &((*(array_char_522*)pValues)[nIndex]);
}

const char * array_char_522_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnCharArrayToString((const void**)pValue, kcg_char_to_string, 522, array_char_522_projection);
}

int compare_array_char_522_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_char_type , 522, array_char_522_projection);
}

int is_array_char_522_allow_double_convertion() {
	return 0;
}

int string_to_array_char_522(const char* strValue, void* pValue) {
	static array_char_522 rTemp;
	int nResult = pSimulator->m_pfnCharArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_char, 522, array_char_522_projection);
	if (nResult == 1)
		kcg_copy_array_char_522(&(*((array_char_522*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_char_522_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_char_signature, 522);
}

FilterUtils get_array_char_522_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_char_Utils, strFilter, (void**)pValue, 522, array_char_522_projection);
}

int check_array_char_522_string(const char* strValue) {
	static array_char_522 rTemp;
	return string_to_array_char_522(strValue, &rTemp);
}


/****************************************************************
 ** String
 ****************************************************************/
struct SimTypeVTable* pSimStringVTable;
const char * String_to_string(const void* pValue) {
	if (pSimStringVTable != 0 && pSimStringVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimStringVTable->m_pfnToType(SptString, pValue);
	return array_char_512_to_string(pValue);
}

int string_to_String(const char* strValue, void* pValue) {
	if (pSimStringVTable != 0 && pSimStringVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static String rTemp;
		int nResult = pSimStringVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array_char_512(&(*((String*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array_char_512(strValue, pValue);
}

int is_String_allow_double_convertion() {
	if (pSimStringVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimStringVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimStringVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimStringVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimStringVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array_char_512_allow_double_convertion();
}

int String_to_double(double * nValue, const void* pValue) {
	if (pSimStringVTable != 0) {
		if (pSimStringVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimStringVTable->m_pfnToType(SptLong, pValue));
		else if (pSimStringVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimStringVTable->m_pfnToType(SptShort, pValue));
		else if (pSimStringVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimStringVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimStringVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimStringVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array_char_512_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array_char_512_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_String_string(const char* strValue) {
	static String rTemp;
	return string_to_String(strValue, &rTemp);
}


/****************************************************************
 ** Path
 ****************************************************************/
struct SimTypeVTable* pSimPathVTable;
const char * Path_to_string(const void* pValue) {
	if (pSimPathVTable != 0 && pSimPathVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimPathVTable->m_pfnToType(SptString, pValue);
	return array_char_256_to_string(pValue);
}

int string_to_Path(const char* strValue, void* pValue) {
	if (pSimPathVTable != 0 && pSimPathVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static Path rTemp;
		int nResult = pSimPathVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array_char_256(&(*((Path*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array_char_256(strValue, pValue);
}

int is_Path_allow_double_convertion() {
	if (pSimPathVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimPathVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimPathVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimPathVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimPathVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array_char_256_allow_double_convertion();
}

int Path_to_double(double * nValue, const void* pValue) {
	if (pSimPathVTable != 0) {
		if (pSimPathVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimPathVTable->m_pfnToType(SptLong, pValue));
		else if (pSimPathVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimPathVTable->m_pfnToType(SptShort, pValue));
		else if (pSimPathVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimPathVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimPathVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimPathVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array_char_256_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array_char_256_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_Path_string(const char* strValue) {
	static Path rTemp;
	return string_to_Path(strValue, &rTemp);
}


