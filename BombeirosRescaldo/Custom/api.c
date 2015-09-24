#include "kcg_types.h"

const String VICTIM1 = "victim1";
const String VICTIM2 = "victim2";

const String MOCK_VICTIM1_ID = "victim1";
const kcg_int MOCK_VICTIM1_SEX = 2;
const kcg_int MOCK_VICTIM1_STATE = 3;
const String MOCK_VICTIM1_COMMENT = "comment\nsecond line";

const String MOCK_VICTIM2_ID = "victim2";
const kcg_int MOCK_VICTIM2_SEX = 3;
const kcg_int MOCK_VICTIM2_STATE = 4;
const String MOCK_VICTIM2_COMMENT = "comment victim2 lalalalalalalalalalalalallalala";

const String NOT_FOUND = "Not Found";

void GetVictimInfo(
  /* GetVictimInfo::VictimID */String *VictimID,
  /* GetVictimInfo::VictimComment */String *VictimComment,
  /* GetVictimInfo::VictimSex */kcg_int *VictimSex,
  /* GetVictimInfo::VictimState */kcg_int *VictimState)
{
	*VictimSex = MOCK_VICTIM1_SEX;
	*VictimState = MOCK_VICTIM1_STATE;
	kcg_copy_String(VictimComment, MOCK_VICTIM1_COMMENT);

	if(kcg_comp_array_char_512(VictimID, VICTIM1))
	{
		*VictimSex = MOCK_VICTIM1_SEX;
		*VictimState = MOCK_VICTIM1_STATE;
		kcg_copy_String(VictimComment, MOCK_VICTIM1_COMMENT);
	}
	else if(kcg_comp_array_char_512(VictimID, VICTIM2))
	{
		*VictimSex = MOCK_VICTIM2_SEX;
		*VictimState = MOCK_VICTIM2_STATE;
		kcg_copy_String(VictimComment, MOCK_VICTIM2_COMMENT);
	}
	else
	{
		*VictimSex = 0;
		*VictimState = 0;
		kcg_copy_String(VictimComment, NOT_FOUND);
	}
}

