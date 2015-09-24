#include "kcg_types.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "curl/curl.h"

void RandomString(char *, unsigned);

const String REQUEST = "request";
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
const String CURL_ERROR_STRING = "CURL_ERROR";
const String CURL_OK_STRING = "CURL_OK";

void GETRequest(
  /* Operator3::URL */	String *URL,
  /* Operator3::Name */	String *Name,
  /* Operator3::ID */	String *ID,
  /* Operator3::Sex */	String *Sex,
  /* Operator3::State */String *State,
  /* Operator3::Comment */String *Comment)
{
	if(kcg_comp_String(URL, VICTIM1))
	{
		kcg_copy_String(Name, MOCK_VICTIM1_NAME);
		kcg_copy_String(ID, MOCK_VICTIM1_ID);
		kcg_copy_String(Sex, MOCK_VICTIM1_SEX);
		kcg_copy_String(State, MOCK_VICTIM1_STATE);
		kcg_copy_String(Comment, MOCK_VICTIM1_COMMENT);
	}
	else if(kcg_comp_String(URL, VICTIM2))
	{
		kcg_copy_String(Name, MOCK_VICTIM2_NAME);
		kcg_copy_String(ID, MOCK_VICTIM2_ID);
		kcg_copy_String(Sex, MOCK_VICTIM2_SEX);
		kcg_copy_String(State, MOCK_VICTIM2_STATE);
		kcg_copy_String(Comment, MOCK_VICTIM2_COMMENT);
	}
	else if(kcg_comp_String(URL, REQUEST))
	{
		CURL *curl;
		CURLcode res;

		curl = curl_easy_init();

		if(curl) {
			curl_easy_setopt(curl, CURLOPT_URL, "http://jsonplaceholder.typicode.com/posts/1");
			/* example.com is redirected, so we tell libcurl to follow redirection */
			curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

			res = curl_easy_perform(curl);

			if(res != CURLE_OK)
			  	kcg_copy_String(Comment, CURL_ERROR_STRING);
			else
				kcg_copy_String(Comment, CURL_OK_STRING);

			/* always cleanup */
			curl_easy_cleanup(curl);
		}
	}
	else
	{
		kcg_copy_String(Name, NOT_FOUND);
		kcg_copy_String(ID, NOT_FOUND);
		kcg_copy_String(Sex, NOT_FOUND);
		kcg_copy_String(State, NOT_FOUND);
		RandomString(Comment, 32);
	}
}

void RandomString(char * string, unsigned length)
{
	// Seed number for rand()
	srand((unsigned int) time(0) + getpid());

	// ASCII characters 33 to 126
	int i;
	for (i = 0; i < length; ++i)
	{
		string[i] = rand() % 94 + 33;
	}

	string[i] = '\0';
}
