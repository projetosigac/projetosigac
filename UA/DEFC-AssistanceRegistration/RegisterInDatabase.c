#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "RegisterInDatabase.h"
#include "../../integration/librest/httpclient.c"
#include "../../integration/libsqlgac/sqlite3.c"
#include "../../integration/libsqlgac/sqlgac.c"

void RegisterInDatabase_reset(outC_RegisterInDatabase *outC)
{
}

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
  outC_RegisterInDatabase *outC) {
  	if (Enable) {
  		char sqlCommand[10000];
  		sprintf(sqlCommand, "insert into assistance values (%s, %s, %s, %s, %s, %s, %s, %s)", 
  			*ComboBoxEditValue, *DescriptionBoxValue, *EditBoxNumericValue, *LatitudeBoxValue, *LocationBoxValue,
  			*LongitudeBoxValue, *NameBoxValue, *StartTimeBoxValue);
		sendHttpSqlRequest(sqlCommand);
		outC->FinishRegistration = true;
	}
	else {
		outC->FinishRegistration = false;
	}
}