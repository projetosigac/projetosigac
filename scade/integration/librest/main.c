/* 
 * File:   main.c
 * Author: vinicius
 *
 * Created on September 14, 2015, 8:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "httpclient.h"
/*
 * 
 */
int main(int argc, char** argv) {
    HTTP_REQUEST* req;
    HTTP_RESPONSE* resp;
    
    resp = get("http://localhost:8080/HellorREST-war/test/hello/vsadfa");
    printf(resp->buffer);
    
    resp = get("http://localhost:8080/HellorREST-war/test/hello/vsadfa");
    printf(resp->buffer);
    return (EXIT_SUCCESS);
}

