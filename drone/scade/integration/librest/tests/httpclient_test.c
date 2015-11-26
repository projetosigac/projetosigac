/*
 * File:   httpclient_test.c
 * Author: vinicius
 *
 * Created on Sep 19, 2015, 5:20:22 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../httpclient.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testIsJson() {
     HTTP_RESPONSE resp;
    
    resp.buffer = "{objA:1; objB:2.3;   objC:\"teste fsd sd sad fsad\" }";
    
    if (!isJsonResponse(resp)) {
        CU_ASSERT(0);
    }
    
    resp.buffer = "[objA:1; objB:2.3;   objC:\"teste fsd sd sad fsad\" ]";
    
    if (isJsonResponse(resp)) {
        CU_ASSERT(0);
    }
}

void testParseJson() {
    HTTP_RESPONSE resp;
    
    resp.buffer = "{objA:1, objB:2.3,   objC:\"teste fsd sd sad fsad\" }";    
    parseJson(&resp);    
    CU_ASSERT_EQUAL(resp.jsonSize,3);
    CU_ASSERT_STRING_EQUAL("objA", resp.json[0].key);
    CU_ASSERT_STRING_EQUAL("objB", resp.json[1].key);
    CU_ASSERT_STRING_EQUAL("objC", resp.json[2].key);
    
    resp.buffer = "{\"one\":\"1\"}";    
    parseJson(&resp);    
    CU_ASSERT_EQUAL(resp.jsonSize,1);
    
    resp.buffer = "{}";    
    parseJson(&resp);    
    CU_ASSERT_EQUAL(resp.jsonSize,0);
    
    resp.buffer = "";    
    parseJson(&resp);    
    CU_ASSERT_EQUAL(resp.jsonSize,0);
    
    parseJson(NULL);    
    CU_ASSERT_EQUAL(resp.jsonSize,0);
}

void testGetJsonValue() {
    HTTP_RESPONSE resp;
    
    strcpy(resp.json[0].key, "f1rst");
    strcpy(resp.json[0].value, "abc1");
    
    strcpy(resp.json[1].key, "second");
    strcpy(resp.json[1].value, "def2");
    
    strcpy(resp.json[2].key, "third");
    strcpy(resp.json[2].value, "ghi3");
    
    strcpy(resp.json[3].key, "fourth");
    strcpy(resp.json[3].value, "jkl4");
    
    strcpy(resp.json[4].key, "fifth");
    strcpy(resp.json[4].value, "mno5");
    
    CU_ASSERT_STRING_EQUAL("ghi3", getJsonValue(resp.json, 5, "third"));
    CU_ASSERT_STRING_EQUAL("abc1", getJsonValue(resp.json, 5, "f1rst"));
    CU_ASSERT_STRING_EQUAL("mno5", getJsonValue(resp.json, 5, "fifth"));
    CU_ASSERT_PTR_NULL(getJsonValue(resp.json, 5, "somekeynotfound"));
}

void testGet() {
    HTTP_RESPONSE* resp = get("http://jsonplaceholder.typicode.com/posts/1");
   
    CU_ASSERT_PTR_NOT_NULL(resp);
    CU_ASSERT_EQUAL(4, resp->jsonSize);
    
    CU_ASSERT_STRING_EQUAL("userId", resp->json[0].key);
    CU_ASSERT_STRING_EQUAL("1", resp->json[0].value);
    
    CU_ASSERT_STRING_EQUAL("title", resp->json[2].key);
    CU_ASSERT_STRING_EQUAL("sunt aut facere repellat provident occaecati excepturi optio reprehenderit", resp->json[2].value);
}

void testPost() {
     HTTP_RESPONSE* resp = post("http://jsonplaceholder.typicode.com/posts",
             "title=foo&body=bar&userId=1");
   
    CU_ASSERT_PTR_NOT_NULL(resp);
    CU_ASSERT_EQUAL(4, resp->jsonSize);
  
    CU_ASSERT_STRING_EQUAL("title", resp->json[0].key);
    CU_ASSERT_STRING_EQUAL("foo", resp->json[0].value);
    
    CU_ASSERT_STRING_EQUAL("body", resp->json[1].key);
    CU_ASSERT_STRING_EQUAL("bar", resp->json[1].value);
    
    CU_ASSERT_STRING_EQUAL("id", resp->json[3].key);
    CU_ASSERT_STRING_EQUAL("101", resp->json[3].value);
}

int main() {
    CU_pSuite pSuite = NULL;
    
    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("httpclient_test", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    
    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "test IsJson", testIsJson)) ||
        (NULL == CU_add_test(pSuite, "test parseJson", testParseJson)) ||
        (NULL == CU_add_test(pSuite, "test GetJsonValue", testGetJsonValue)) ||
        (NULL == CU_add_test(pSuite, "test get", testGet)) ||
        (NULL == CU_add_test(pSuite, "test post", testPost))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    return CU_get_error();
}
