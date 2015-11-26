#ifndef _RegisterInDatabase_H_
#define _RegisterInDatabase_H_

#include "kcg_types.h"

/* ========================  input structure  ====================== */
typedef struct {
  texto /* RegisterInDatabase::StartTimeBoxValue */ StartTimeBoxValue;
  texto /* RegisterInDatabase::NameBoxValue */ NameBoxValue;
  texto /* RegisterInDatabase::LongitudeBoxValue */ LongitudeBoxValue;
  texto /* RegisterInDatabase::LocationBoxValue */ LocationBoxValue;
  texto /* RegisterInDatabase::LatitudeBoxValue */ LatitudeBoxValue;
  texto /* RegisterInDatabase::EditBoxNumericValue */ EditBoxNumericValue;
  textolongo /* RegisterInDatabase::DescriptionBoxValue */ DescriptionBoxValue;
  texto /* RegisterInDatabase::ComboBoxEditValue */ ComboBoxEditValue;
  kcg_bool /* RegisterInDatabase::Enable */ Enable;
} inC_RegisterInDatabase;

/* ========================  context type  ========================= */
typedef struct {
	kcg_bool FinishRegistration;
} outC_RegisterInDatabase;

/* ===========  node initialization and cycle functions  =========== */
/* RegisterInDatabase */
extern void RegisterInDatabase(
  kcg_bool /* RegisterInDatabase::Enable */ Enable,
  texto* /* RegisterInDatabase::ComboBoxEditValue */ ComboBoxEditValue,
  textolongo * /* RegisterInDatabase::DescriptionBoxValue */ DescriptionBoxValue,
  texto* /* RegisterInDatabase::EditBoxNumericValue */ EditBoxNumericValue,
  texto* /* RegisterInDatabase::LatitudeBoxValue */ LatitudeBoxValue,
  texto* /* RegisterInDatabase::LocationBoxValue */ LocationBoxValue,
  texto* /* RegisterInDatabase::LongitudeBoxValue */ LongitudeBoxValue,
  texto* /* RegisterInDatabase::NameBoxValue */ NameBoxValue,
  texto* /* RegisterInDatabase::StartTimeBoxValue */ StartTimeBoxValue,
  outC_RegisterInDatabase *outC);
extern void RegisterInDatabase_reset(outC_RegisterInDatabase *outC);

#endif /* _Main_H_ */