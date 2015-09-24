#include "kcg_types.h"

const String VICTIM1 = "victim1";
const String VICTIM2 = "victim2";

const String MOCK_VICTIM1_NAME = "lala";
const String MOCK_VICTIM1_ID = "victim1";
const String MOCK_VICTIM1_SEX = "M";
const String MOCK_VICTIM1_STATE = "DEAD";
const String MOCK_VICTIM1_COMMENT = "test comment";

const String MOCK_VICTIM2_NAME = "pooh";
const String MOCK_VICTIM2_ID = "victim2";
const String MOCK_VICTIM2_SEX = "F";
const String MOCK_VICTIM2_STATE = "CRITICAL";
const String MOCK_VICTIM2_COMMENT = "test comment";

const String NOT_FOUND = "Not Found";

void GetVictimInfo(
  /* GetVictimInfo::VictimID */String *VictimID,
  /* GetVictimInfo::VictimDisplayText */kcg_bool *VictimDisplayText,
  /* GetVictimInfo::VictimSex */kcg_bool *VictimSex,
  /* GetVictimInfo::VictimState */kcg_bool *VictimState)
{
	kcg_copy_String(VictimDisplayText, VictimID);
	kcg_copy_String(VictimSex, VictimID);
	kcg_copy_String(VictimState, VictimID);
}

