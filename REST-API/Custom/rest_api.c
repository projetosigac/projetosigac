#include "kcg_types.h"

const String VICTIM1 = "victim1";
const String VICTIM2 = "victim2";

const String MOCK_VICTIM1_NAME = "lala";
const String MOCK_VICTIM1_ID = "victim1";
const String MOCK_VICTIM1_SEX = "M";
const String MOCK_VICTIM1_STATE = "DEAD";
const String MOCK_VICTIM1_COMMENT = "peeenis";

const String MOCK_VICTIM2_NAME = "pooh";
const String MOCK_VICTIM2_ID = "victim2";
const String MOCK_VICTIM2_SEX = "F";
const String MOCK_VICTIM2_STATE = "CRITICAL";
const String MOCK_VICTIM2_COMMENT = "b00bs";

const String NOT_FOUND = "Not Found";

void Operator3(
  /* Operator3::URL */	String *URL,
  /* Operator3::Name */	String *Name,
  /* Operator3::ID */	String *ID,
  /* Operator3::Sex */	String *Sex,
  /* Operator3::State */String *State,
  /* Operator3::Comment */String *Comment)
{
	if(kcg_comp_array_char_512(URL, VICTIM1))
	{
		kcg_copy_String(Name, MOCK_VICTIM1_NAME);
		kcg_copy_String(ID, MOCK_VICTIM1_ID);
		kcg_copy_String(Sex, MOCK_VICTIM1_SEX);
		kcg_copy_String(State, MOCK_VICTIM1_STATE);
		kcg_copy_String(Comment, MOCK_VICTIM1_COMMENT);
	}
	else if(kcg_comp_array_char_512(URL, VICTIM2))
	{
		kcg_copy_String(Name, MOCK_VICTIM2_NAME);
		kcg_copy_String(ID, MOCK_VICTIM2_ID);
		kcg_copy_String(Sex, MOCK_VICTIM2_SEX);
		kcg_copy_String(State, MOCK_VICTIM2_STATE);
		kcg_copy_String(Comment, MOCK_VICTIM2_COMMENT);
	}
	else
	{
		kcg_copy_String(Name, NOT_FOUND);
		kcg_copy_String(ID, NOT_FOUND);
		kcg_copy_String(Sex, NOT_FOUND);
		kcg_copy_String(State, NOT_FOUND);
		kcg_copy_String(Comment, NOT_FOUND);
	}
}

