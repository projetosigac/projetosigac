#include "kcg_types.h"
#include "../Libs/librest/httpclient.h"

#define URL "http://192.168.1.2:1880/sensordata"

kcg_int32 GetData(/* GetData::sensor_code */ kcg_int32 sensor_code)
{
    HTTP_RESPONSE* res = get(URL);
    char* value = getJsonValue(res->json, res->jsonSize, "value");
	return atoi(value);
}



