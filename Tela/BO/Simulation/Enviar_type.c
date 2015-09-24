
#include <stdlib.h>
#include "SmuTypes.h"
#include "kcg_types.h"
#include "Enviar_type.h"
#include "Enviar_mapping.h"

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
TypeUtils _SCSIM_array_char_1000_Utils = {array_char_1000_to_string,
	check_array_char_1000_string,
	string_to_array_char_1000,
	is_array_char_1000_allow_double_convertion,
	0,
	compare_array_char_1000_type,
	get_array_char_1000_signature,
	get_array_char_1000_filter_utils,
	array_char_1000_filter_size,
	array_char_1000_filter_values};
TypeUtils _SCSIM_array_char_20_Utils = {array_char_20_to_string,
	check_array_char_20_string,
	string_to_array_char_20,
	is_array_char_20_allow_double_convertion,
	0,
	compare_array_char_20_type,
	get_array_char_20_signature,
	get_array_char_20_filter_utils,
	array_char_20_filter_size,
	array_char_20_filter_values};
TypeUtils _SCSIM_struct__273_Utils = {struct__273_to_string,
	check_struct__273_string,
	string_to_struct__273,
	is_struct__273_allow_double_convertion,
	0,
	compare_struct__273_type,
	get_struct__273_signature,
	get_struct__273_filter_utils,
	struct__273_filter_size,
	struct__273_filter_values};
TypeUtils _SCSIM_array_char_5_Utils = {array_char_5_to_string,
	check_array_char_5_string,
	string_to_array_char_5,
	is_array_char_5_allow_double_convertion,
	0,
	compare_array_char_5_type,
	get_array_char_5_signature,
	get_array_char_5_filter_utils,
	array_char_5_filter_size,
	array_char_5_filter_values};
TypeUtils _SCSIM_Name_Utils = {Name_to_string,
	check_Name_string,
	string_to_Name,
	is_Name_allow_double_convertion,
	Name_to_double,
	compare_Name_type,
	get_Name_signature,
	get_Name_filter_utils,
	Name_filter_size,
	Name_filter_values};
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
TypeUtils _SCSIM_BigText_Utils = {BigText_to_string,
	check_BigText_string,
	string_to_BigText,
	is_BigText_allow_double_convertion,
	BigText_to_double,
	compare_BigText_type,
	get_BigText_signature,
	get_BigText_filter_utils,
	BigText_filter_size,
	BigText_filter_values};
TypeUtils _SCSIM_Boletim_Utils = {Boletim_to_string,
	check_Boletim_string,
	string_to_Boletim,
	is_Boletim_allow_double_convertion,
	Boletim_to_double,
	compare_Boletim_type,
	get_Boletim_signature,
	get_Boletim_filter_utils,
	Boletim_filter_size,
	Boletim_filter_values};

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
 ** array_char_1000
 ****************************************************************/
void* array_char_1000_projection(void** pValues, int nIndex) {
	return &((*(array_char_1000*)pValues)[nIndex]);
}

const char * array_char_1000_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnCharArrayToString((const void**)pValue, kcg_char_to_string, 1000, array_char_1000_projection);
}

int compare_array_char_1000_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_char_type , 1000, array_char_1000_projection);
}

int is_array_char_1000_allow_double_convertion() {
	return 0;
}

int string_to_array_char_1000(const char* strValue, void* pValue) {
	static array_char_1000 rTemp;
	int nResult = pSimulator->m_pfnCharArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_char, 1000, array_char_1000_projection);
	if (nResult == 1)
		kcg_copy_array_char_1000(&(*((array_char_1000*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_char_1000_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_char_signature, 1000);
}

FilterUtils get_array_char_1000_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_char_Utils, strFilter, (void**)pValue, 1000, array_char_1000_projection);
}

int check_array_char_1000_string(const char* strValue) {
	static array_char_1000 rTemp;
	return string_to_array_char_1000(strValue, &rTemp);
}


/****************************************************************
 ** array_char_20
 ****************************************************************/
void* array_char_20_projection(void** pValues, int nIndex) {
	return &((*(array_char_20*)pValues)[nIndex]);
}

const char * array_char_20_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnCharArrayToString((const void**)pValue, kcg_char_to_string, 20, array_char_20_projection);
}

int compare_array_char_20_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_char_type , 20, array_char_20_projection);
}

int is_array_char_20_allow_double_convertion() {
	return 0;
}

int string_to_array_char_20(const char* strValue, void* pValue) {
	static array_char_20 rTemp;
	int nResult = pSimulator->m_pfnCharArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_char, 20, array_char_20_projection);
	if (nResult == 1)
		kcg_copy_array_char_20(&(*((array_char_20*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_char_20_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_char_signature, 20);
}

FilterUtils get_array_char_20_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_char_Utils, strFilter, (void**)pValue, 20, array_char_20_projection);
}

int check_array_char_20_string(const char* strValue) {
	static array_char_20 rTemp;
	return string_to_array_char_20(strValue, &rTemp);
}


/****************************************************************
 ** struct__273
 ****************************************************************/
static void Fill_struct__273_StructSimValue(struct__273 * pStruct, StructSimValue * pValues) {
	/*description label.*/
	pValues[0].m_pPtr = pStruct != 0 ? &(pStruct->description) : 0;
	pValues[0].m_pTypeUtils = &_SCSIM_array_char_1000_Utils;
	pValues[0].m_pszName = "description";
	/*dt_fato label.*/
	pValues[1].m_pPtr = pStruct != 0 ? &(pStruct->dt_fato) : 0;
	pValues[1].m_pTypeUtils = &_SCSIM_array_char_20_Utils;
	pValues[1].m_pszName = "dt_fato";
	/*hora_fato label.*/
	pValues[2].m_pPtr = pStruct != 0 ? &(pStruct->hora_fato) : 0;
	pValues[2].m_pTypeUtils = &_SCSIM_array_char_20_Utils;
	pValues[2].m_pszName = "hora_fato";
	/*dt_ini_atend label.*/
	pValues[3].m_pPtr = pStruct != 0 ? &(pStruct->dt_ini_atend) : 0;
	pValues[3].m_pTypeUtils = &_SCSIM_array_char_20_Utils;
	pValues[3].m_pszName = "dt_ini_atend";
	/*hora_ini_atend label.*/
	pValues[4].m_pPtr = pStruct != 0 ? &(pStruct->hora_ini_atend) : 0;
	pValues[4].m_pTypeUtils = &_SCSIM_array_char_20_Utils;
	pValues[4].m_pszName = "hora_ini_atend";
	/*dt_fim_atend label.*/
	pValues[5].m_pPtr = pStruct != 0 ? &(pStruct->dt_fim_atend) : 0;
	pValues[5].m_pTypeUtils = &_SCSIM_array_char_20_Utils;
	pValues[5].m_pszName = "dt_fim_atend";
	/*hora_fim_atend label.*/
	pValues[6].m_pPtr = pStruct != 0 ? &(pStruct->hora_fim_atend) : 0;
	pValues[6].m_pTypeUtils = &_SCSIM_array_char_20_Utils;
	pValues[6].m_pszName = "hora_fim_atend";
	/*rg label.*/
	pValues[7].m_pPtr = pStruct != 0 ? &(pStruct->rg) : 0;
	pValues[7].m_pTypeUtils = &_SCSIM_array_char_20_Utils;
	pValues[7].m_pszName = "rg";
}

const char * struct__273_to_string(const void* pValue) {
	static StructSimValue values[8];
	Fill_struct__273_StructSimValue(((struct__273*)pValue), values);
	return pSimulator->m_pfnStructureToString(values, 8);
}

int string_to_struct__273(const char* strValue, void* pValue) {
	static struct__273 rTemp;
	int nResult = 0;
	static StructSimValue values[8];
	kcg_copy_struct__273(&(rTemp), &(*((struct__273*)pValue)));
	Fill_struct__273_StructSimValue(&rTemp, values);
	nResult = pSimulator->m_pfnStructureFromString(strValue, values, 8);
	if (nResult == 1)
		kcg_copy_struct__273(&(*((struct__273*)pValue)), &(rTemp));
	return nResult;
}

int compare_struct__273_type(int* pResult, const char* toCompare, const void* pValue) {
	static StructSimValue values[8];
	Fill_struct__273_StructSimValue((struct__273*)pValue, values);
	return pSimulator->m_pfnStructureComparison(pResult, toCompare, values, 8);
}


int is_struct__273_allow_double_convertion() {
	return 0;
}


const char * get_struct__273_signature() {
	static StructSimValue values[8];
	Fill_struct__273_StructSimValue(0, values);
	return pSimulator->m_pfnStructureSignature(values, 8);
}

FilterUtils get_struct__273_filter_utils(const char* strFilter, void* pValue) {
	static StructSimValue values[8];
	Fill_struct__273_StructSimValue((struct__273*)pValue, values);
	return pSimulator->m_pfnGetStructureFilterUtils(values, 8, strFilter);
}

const char * struct__273_filter_values[8] = {"description", "dt_fato", "hora_fato", "dt_ini_atend", "hora_ini_atend", "dt_fim_atend", "hora_fim_atend", "rg"};
int check_struct__273_string(const char* strValue) {
	static struct__273 rTemp;
	return string_to_struct__273(strValue, &rTemp);
}


/****************************************************************
 ** array_char_5
 ****************************************************************/
void* array_char_5_projection(void** pValues, int nIndex) {
	return &((*(array_char_5*)pValues)[nIndex]);
}

const char * array_char_5_to_string(const void* pValue) {
	return (char*) pSimulator->m_pfnCharArrayToString((const void**)pValue, kcg_char_to_string, 5, array_char_5_projection);
}

int compare_array_char_5_type(int* pResult, const char* toCompare, const void* pValue) {
	return pSimulator->m_pfnArrayComparison(pResult, toCompare, (const void**)pValue, compare_kcg_char_type , 5, array_char_5_projection);
}

int is_array_char_5_allow_double_convertion() {
	return 0;
}

int string_to_array_char_5(const char* strValue, void* pValue) {
	static array_char_5 rTemp;
	int nResult = pSimulator->m_pfnCharArrayFromString(strValue, (void**)(void*)&rTemp, string_to_kcg_char, 5, array_char_5_projection);
	if (nResult == 1)
		kcg_copy_array_char_5(&(*((array_char_5*)pValue)), &(rTemp));
	return nResult;
}

const char * get_array_char_5_signature() {
	return pSimulator->m_pfnArraySignature(get_kcg_char_signature, 5);
}

FilterUtils get_array_char_5_filter_utils(const char* strFilter, void* pValue) {
	return pSimulator->m_pfnGetArrayFilterUtils(&_SCSIM_kcg_char_Utils, strFilter, (void**)pValue, 5, array_char_5_projection);
}

int check_array_char_5_string(const char* strValue) {
	static array_char_5 rTemp;
	return string_to_array_char_5(strValue, &rTemp);
}


/****************************************************************
 ** Name
 ****************************************************************/
struct SimTypeVTable* pSimNameVTable;
const char * Name_to_string(const void* pValue) {
	if (pSimNameVTable != 0 && pSimNameVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimNameVTable->m_pfnToType(SptString, pValue);
	return array_char_5_to_string(pValue);
}

int string_to_Name(const char* strValue, void* pValue) {
	if (pSimNameVTable != 0 && pSimNameVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static Name rTemp;
		int nResult = pSimNameVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array_char_5(&(*((Name*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array_char_5(strValue, pValue);
}

int is_Name_allow_double_convertion() {
	if (pSimNameVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimNameVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimNameVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimNameVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimNameVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array_char_5_allow_double_convertion();
}

int Name_to_double(double * nValue, const void* pValue) {
	if (pSimNameVTable != 0) {
		if (pSimNameVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimNameVTable->m_pfnToType(SptLong, pValue));
		else if (pSimNameVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimNameVTable->m_pfnToType(SptShort, pValue));
		else if (pSimNameVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimNameVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimNameVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimNameVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array_char_5_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array_char_5_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_Name_string(const char* strValue) {
	static Name rTemp;
	return string_to_Name(strValue, &rTemp);
}


/****************************************************************
 ** String
 ****************************************************************/
struct SimTypeVTable* pSimStringVTable;
const char * String_to_string(const void* pValue) {
	if (pSimStringVTable != 0 && pSimStringVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimStringVTable->m_pfnToType(SptString, pValue);
	return array_char_20_to_string(pValue);
}

int string_to_String(const char* strValue, void* pValue) {
	if (pSimStringVTable != 0 && pSimStringVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static String rTemp;
		int nResult = pSimStringVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array_char_20(&(*((String*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array_char_20(strValue, pValue);
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
	return is_array_char_20_allow_double_convertion();
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
	if (_SCSIM_array_char_20_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array_char_20_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_String_string(const char* strValue) {
	static String rTemp;
	return string_to_String(strValue, &rTemp);
}


/****************************************************************
 ** BigText
 ****************************************************************/
struct SimTypeVTable* pSimBigTextVTable;
const char * BigText_to_string(const void* pValue) {
	if (pSimBigTextVTable != 0 && pSimBigTextVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimBigTextVTable->m_pfnToType(SptString, pValue);
	return array_char_1000_to_string(pValue);
}

int string_to_BigText(const char* strValue, void* pValue) {
	if (pSimBigTextVTable != 0 && pSimBigTextVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static BigText rTemp;
		int nResult = pSimBigTextVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_array_char_1000(&(*((BigText*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_array_char_1000(strValue, pValue);
}

int is_BigText_allow_double_convertion() {
	if (pSimBigTextVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimBigTextVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimBigTextVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimBigTextVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimBigTextVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_array_char_1000_allow_double_convertion();
}

int BigText_to_double(double * nValue, const void* pValue) {
	if (pSimBigTextVTable != 0) {
		if (pSimBigTextVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimBigTextVTable->m_pfnToType(SptLong, pValue));
		else if (pSimBigTextVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimBigTextVTable->m_pfnToType(SptShort, pValue));
		else if (pSimBigTextVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimBigTextVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimBigTextVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimBigTextVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_array_char_1000_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_array_char_1000_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_BigText_string(const char* strValue) {
	static BigText rTemp;
	return string_to_BigText(strValue, &rTemp);
}


/****************************************************************
 ** Boletim
 ****************************************************************/
struct SimTypeVTable* pSimBoletimVTable;
const char * Boletim_to_string(const void* pValue) {
	if (pSimBoletimVTable != 0 && pSimBoletimVTable->m_pfnGetConvInfo(SptString, SptNone) == 1)
		return *(char**)pSimBoletimVTable->m_pfnToType(SptString, pValue);
	return struct__273_to_string(pValue);
}

int string_to_Boletim(const char* strValue, void* pValue) {
	if (pSimBoletimVTable != 0 && pSimBoletimVTable->m_pfnGetConvInfo(SptNone, SptString) == 1) {
		static Boletim rTemp;
		int nResult = pSimBoletimVTable->m_pfnFromType(SptString, (const void*)&strValue, &rTemp);
		if (nResult == 1)
			kcg_copy_struct__273(&(*((Boletim*)pValue)), &(rTemp));
		return nResult;
	}
	return string_to_struct__273(strValue, pValue);
}

int is_Boletim_allow_double_convertion() {
	if (pSimBoletimVTable != 0) {
		int nConvertionAllowed = 0;
		nConvertionAllowed |= pSimBoletimVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1;
		nConvertionAllowed |= pSimBoletimVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1;
		nConvertionAllowed |= pSimBoletimVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1;
		nConvertionAllowed |= pSimBoletimVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1;
		return nConvertionAllowed;
	}
	return is_struct__273_allow_double_convertion();
}

int Boletim_to_double(double * nValue, const void* pValue) {
	if (pSimBoletimVTable != 0) {
		if (pSimBoletimVTable->m_pfnGetConvInfo(SptNone, SptLong) == 1)
			*nValue = (double)(*(long*)pSimBoletimVTable->m_pfnToType(SptLong, pValue));
		else if (pSimBoletimVTable->m_pfnGetConvInfo(SptNone, SptShort) == 1)
			*nValue = (double)(*(int*)pSimBoletimVTable->m_pfnToType(SptShort, pValue));
		else if (pSimBoletimVTable->m_pfnGetConvInfo(SptNone, SptDouble) == 1)
			*nValue = (*(double*)pSimBoletimVTable->m_pfnToType(SptDouble, pValue));
		else if (pSimBoletimVTable->m_pfnGetConvInfo(SptNone, SptFloat) == 1)
			*nValue = (double)(*(float*)pSimBoletimVTable->m_pfnToType(SptFloat, pValue));
		else
			return 0;
		return 1;
	}
	if (_SCSIM_struct__273_Utils.m_pfnTypeToDouble != 0)
		return _SCSIM_struct__273_Utils.m_pfnTypeToDouble(nValue, pValue);
	return 0;
}

int check_Boletim_string(const char* strValue) {
	static Boletim rTemp;
	return string_to_Boletim(strValue, &rTemp);
}


