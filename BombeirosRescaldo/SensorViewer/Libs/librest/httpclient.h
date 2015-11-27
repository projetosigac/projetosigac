/*******************************************************************
* Definition file for the HTTP Client library for SIGAC project.
* 
* It contains operations for making HTTP POST and GET requests to remote servers.
* This code does not contains any dependency with external libraries, just
* with standard Unix libraries or WIN32 libraries, making it portable across
* the environments.
* 
* The code is reuses the HTTP client developed by Stanley Huangyc on the MiniWeb project,
 * available at: https://code.google.com/p/miniweb
* 
* Copyright (c) 2005-06 Stanley Huang <stanleyhuangyc@yahoo.com.cn> Original Author
* Copyright (c) 2015    Vinicius Souza <viniciusjssouza@gmail.com> 
*  
*  Distributed under GPL license
*  All rights reserved.
*******************************************************************/

/*******************************************************************
* HTTP helper
* Distributed under GPL license
* Copyright (c) 2005-06 Stanley Huang <stanleyhuangyc@yahoo.com.cn>
* All rights reserved.
*******************************************************************/

#ifndef _HTTPCLIENT_H
#define _HTTPCLIENT_H
#define FLAG_REQUEST_ONLY 0x1
#define FLAG_KEEP_ALIVE 0x2
#define FLAG_KEEP_HEADER 0x4
#define FLAG_CHUNKED 0x8

#define MAX_JSON_KEY_SIZE   64
#define MAX_JSON_VAL_SIZE   1024    

#ifdef _DEBUG
#define DEBUG printf
#else
#define DEBUG
#endif

#include <stddef.h>

typedef enum {
    IDLE=0,
    REQUESTING,
    RECEIVING,
    STOPPING,
} HTTP_STATES;

typedef enum {
    HTTP_GET = 0,
    HTTP_POST   
} HTTP_METHOD;

typedef enum {
    OK = 0,
    LIBREST_ERROR = -1           
} RESPONSE_STATUS;

#define postPayload_STRING 0
#define postPayload_BINARY 1
#define postPayload_FD 2
#define postPayload_CALLBACK 3
#define MAX_JSON_SIZE 100
#define MAX_HEADER_SIZE (8192 - 1)
// This is the maximum buffer size for post request. May be tweaked.
#define POST_BUFFER_SIZE 1024

typedef int (*PFNpostPayloadCALLBACK)(void* buffer, int bufsize);

typedef struct {
    void* data;
    int type;
    size_t length;
} POST_CHUNK;

typedef struct {
    int sockfd;
    HTTP_STATES state;
    unsigned short flags;
    unsigned short port;
    char header[MAX_HEADER_SIZE+1];
    char* hostname;
    int postPayloadBytes;
} HTTP_CONN;

typedef struct  {
    char key[MAX_JSON_KEY_SIZE];
    char value[MAX_JSON_VAL_SIZE];
} Json;

typedef struct {
    HTTP_METHOD method;    
    const char *url;
    //Multipart-Post 
    POST_CHUNK* chunk;
    char* postPayload;
    int chunkCount;
    const char* filename;
} HTTP_REQUEST;

typedef struct {
    //info parsed from response header
    char header[MAX_HEADER_SIZE+1];
    Json json[MAX_JSON_SIZE]; // the json structure    
    size_t jsonSize; // number of json objects returned.
    char* contentType;
    char* location;
    int httpVer;    // 0 for 1.0, 1 for 1.1
    int httpCode;
    int payloadSize;
    int bufferSize;
    int dataSize;
    char* buffer;
    RESPONSE_STATUS status;    
} HTTP_RESPONSE;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Send a HTTP get request to the provided URL address.
 * 
 * @param url the URL which will receive the request.
 * @return  a pointer to the HTTP response.
 */
HTTP_RESPONSE* get(const char* const url);    

/**
 * Send a HTTP post request to the provided URL address.
 * 
 * @param url the URL which will receive the request.
 * @param body a string containing the body of the POST request.
 * @return a pointer to the HTTP response.
 */
HTTP_RESPONSE* post(const char* url, const char body[]);

/**
 * Return the value of the provided key in the json
 * object.
 * 
 * @param json array containing the json objects.
 * @param jsonSize the number of json objects in the json array.
 * @param key the object key.
 * @return the object value of NULL, if no object is found.
 */
char* getJsonValue(Json json[], size_t jsonSize, char* key);

/**
 * Send the provided HTTP request. 
 * 
 * @param request the request to be sent.
 * @return the HTTP response.
 */
HTTP_RESPONSE* sendRequest(const HTTP_REQUEST*  const request);

#ifdef __cplusplus
}
#endif

#endif