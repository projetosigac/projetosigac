/*******************************************************************
 * HTTP Client for SIGAC project.
 * 
 * It contains operations for making HTTP POST and GET requests to remote servers.
 * This code does not contains any dependency with external libraries, just
 * with standard Unix libraries or WIN32 libraries, making it portable across
 * the environments.
 * 
 * The code reuses the HTTP client developed by Stanley Huangyc on the MiniWeb project,
 * available at: https://code.google.com/p/miniweb
 * 
 * Copyright (c) 2005-06 Stanley Huang <stanleyhuangyc@yahoo.com.cn> Original Author
 * Copyright (c) 2015    Vinicius Souza <viniciusjssouza@gmail.com> 
 *  
 *  Distributed under GPL license
 *  All rights reserved.
 *******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#include "httpclient.h"

// headers for WIN32 platforms
#ifdef WIN32
#include <Winsock2.h>
#include <io.h>

#define read _read
#define open _open
#define close _close
#define lseek _lseek
#define snprintf _snprintf
#define stricmp _stricmp

// headers for Unix-based platforms
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define closesocket close
#define CloseHandle close
#define stricmp strcasecmp

#define 	DEF_KEY_QUOTES		1
#define 	DEF_KEY				2
#define 	DEF_MIDDLE			4
#define 	DEF_VAL_QUOTES		5
#define 	DEF_VAL_NO_QUOTES	6
#define 	DEF_VAL_WITH_QUOTES	7
#define 	DEF_COMMA			8

#if !defined(O_BINARY)
#define O_BINARY 0
#endif

#endif


/****************************************************************************
 * HTTP protocol client
 ****************************************************************************/
#define HEADER_END_FLAG  "\r\n\r\n"

#define CONN_RETRIES 3
#define HTTP_GET_HEADER "%s %s HTTP/1.0\r\nAccept: */*\r\nConnection: %s\r\nUser-Agent: Transerver/1.0\r\nHost: %s\r\n%s\r\n"
#define HTTP_POST_HEADER "POST %s HTTP/1.1\r\nHost: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nUser-Agent: Mozilla/5.0\r\nContent-Length: %d\r\n\r\n%s\r\n\r\n"
#define HTTP_POST_MULTIPART_HEADER "POST %s HTTP/1.0\r\nHost: %s\r\nUser-Agent: Mozilla/5.0\r\nAccept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5\r\nAccept-Language: en-us,en;q=0.5\r\nAccept-Encoding: gzip,deflate\r\nAccept-Charset: ISO-8859-1;q=0.7,*;q=0.7\r\nKeep-Alive: 300\r\nConnection: keep-alive\r\nContent-Type: multipart/form-data; boundary=%s\r\nContent-Length: %d\r\n%s\r\n"
#define MULTIPART_BOUNDARY "---------------------------24464570528145"
#define HTTP_POST_STREAM_HEADER "POST %s HTTP/1.0\r\nHost: %s\r\nUser-Agent: Mozilla/5.0\r\nAccept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5\r\nAccept-Language: en-us,en;q=0.5\r\nAccept-Encoding: gzip,deflate\r\nAccept-Charset: ISO-8859-1;q=0.7,*;q=0.7\r\nKeep-Alive: 300\r\nConnection: close\r\nContent-Type: application/octet-stream; filename=%s\r\nContent-Length: %d\r\n%s\r\n"

/**
 * Parse the provided url, setting the hostname and port into
 * the provided HTTP connection. Returns the remaining path to the requested resource.
 * 
 * @param url the URL to be parsed.
 * @param req the HTTP request
 * @param conn the HTTP connection data
 * @return NULL if the provided URL is invalid. Else, returns the path to the
 * requested resource.
 */
static char* parseURL(const HTTP_REQUEST * req, HTTP_CONN * const conn) {
    const char *url = req->url;
    char *ptr;
    size_t len;
    char *path;

    // The url must start with the "http://" preffix.
    if (strncmp(url, "http://", 7) != 0) {
        return NULL;
    }

    url += 7; // skip the first 7 chars.
    ptr = strchr(url, '/'); // search for the first occurrence of the slash
    // if there is no '/', the URL points to the root of the host.
    // After this, the 'len' variable contains the length of the hostname in the url
    // and the path will contain the path in the server to the required resource.
    if (ptr == NULL) {
        path = "/";
        len = strlen(url);
    } else {
        len = (int) (ptr - url);
        path = ptr;
    }
    // Get the port number
    ptr = strchr(url, ':');
    if (ptr && *(ptr + 1) != '/') {
        unsigned short int port = atoi(ptr + 1);
        if (port) {
            conn->port = port;
        } else {
            conn->port = 80;
        }
        len = (int) (ptr - url);
    } else {
        conn->port = 80;
    }
    conn->hostname = (char*) malloc(len + 1);
    memcpy(conn->hostname, url, len);
    conn->hostname[len] = 0;
    // returns the path to the requested resource, without the hostname, port and protocol.
    return path;
}

/**
 * Send the provided chunk of data using the given HTTP request.
 * It assumes that the socket is currently opened.
 * 
 * @param conn the HTTP request to be sent.
 * @param data the data of the request (body).
 * @param length the length, in bytes, of the request.
 * @return the number of bytes sent.
 */
static size_t sendData(HTTP_CONN * const conn, char* data, size_t length) {
    size_t offset = 0;
    size_t bytes;
    do {
        bytes = send(conn->sockfd, data + offset, (int) (length - offset), 0);
        if (bytes <= 0) break;
        offset += bytes;
        DEBUG("Sent %d/%d bytes\n", offset, length);
    } while (offset < length);
    return offset;
}

/**
 * Release the resources allocated by the HTTP connection.
 * @param param the HTTP request.
 */
static void releaseResources(HTTP_CONN * const conn) {
    if (conn->sockfd) {
        closesocket(conn->sockfd);
        conn->sockfd = 0;
    }
    if (conn->hostname) {
        free(conn->hostname);
        conn->hostname = 0;
    }
    free(conn);
}

static HTTP_RESPONSE* httpGetResponse(HTTP_CONN * const conn) {
    int receivedBytes;
    int rspHeaderBytes;
    int ret;
    char *p = 0;
    HTTP_RESPONSE* resp = malloc(sizeof (HTTP_RESPONSE));

    do {
        //receive header
        DEBUG("Receiving response...\n");
        receivedBytes = 0;
        for (;;) {
            ret = recv(conn->sockfd, resp->header + receivedBytes, MAX_HEADER_SIZE - receivedBytes, 0);
            if (ret <= 0) break;
            receivedBytes += ret;
            resp->header[receivedBytes] = 0;
            DEBUG("Received %d/%d bytes\n", ret, receivedBytes);
            if ((p = strstr(resp->header, "\r\n\r\n"))) {
                *(p + 2) = '\0';
                break;
            }
            if (receivedBytes == MAX_HEADER_SIZE) {
                p = resp->header + receivedBytes - 4;
            }
        }
        if (!p) {
            DEBUG("Invalid server response\n");
            resp->status = ERROR;
            continue;
        } else {
            resp->status = OK;
            p += 4;
        }
        rspHeaderBytes = (int) (p - resp->header);

        //process header
        char *p;
        DEBUG("Response header:\n%s\n", resp->header);
        if (p = strstr(resp->header, "HTTP/1.")) {
            resp->httpCode = atoi(p + 9);
        }
        if (resp->httpCode >= 404) {
            DEBUG("Invalid response or file not found on server\n");
            closesocket(conn->sockfd);
            conn->sockfd = 0;
            conn->state = IDLE;
            resp->status = ERROR;
            return resp;
        }
        while ((p = strstr(p, "\r\n"))) {
            char *q;
            q = strchr((p += 2), ':');
            if (!q) continue;
            *q = 0;
            if (!stricmp(p, "Content-length")) {
                resp->payloadSize = atoi(q + 2);
            } else if (!stricmp(p, "Content-type")) {
                resp->contentType = q + 2;
            } else if (!stricmp(p, "Transfer-Encoding")) {
                if (!strncmp(p + 19, "chunked", 7)) {
                    conn->flags |= FLAG_CHUNKED;
                }
            } else if (!stricmp(p, "Location")) {
                resp->location = q + 2;
            }
            *q = ':';
        }
        DEBUG("Payload bytes: %d\n", resp->payloadSize);
        if (resp->payloadSize == 0 && resp->dataSize > 0)
            resp->payloadSize = resp->dataSize - 1;
        if (conn->flags & FLAG_REQUEST_ONLY) {
            closesocket(conn->sockfd);
            conn->state = IDLE;
            return NULL;
        }
        // receive payload
        int bytes;
        int recvBytes = 0;
        int bytesToRecv;
        int payloadWithHeader = receivedBytes - rspHeaderBytes;
        int eof = 0;
        conn->state = RECEIVING;
        do {
            if (resp->bufferSize > 0) {
                if (resp->payloadSize > 0) {
                    if (resp->bufferSize < resp->payloadSize + 1) {
                        free(resp->buffer);
                        resp->bufferSize = resp->payloadSize + 1;
                        resp->buffer = (char*) calloc(1, resp->bufferSize);
                    }
                } else {
                    resp->bufferSize *= 2;
                    resp->buffer = (char*) realloc(resp->buffer, resp->bufferSize);
                }
            } else {
                DEBUG("Allocating %d bytes for payload buffer\n", resp->payloadSize);
                if (resp->payloadSize) {
                    resp->bufferSize = resp->payloadSize + 1;
                    resp->buffer = (char*) calloc(1, resp->bufferSize);
                } else {
                    resp->bufferSize = 1024 + payloadWithHeader;
                    resp->buffer = (char*) calloc(1, resp->bufferSize);
                }
            }
            if (recvBytes == 0) {
                recvBytes = payloadWithHeader;
                if (recvBytes > 0) {
                    DEBUG("Header includes %d bytes of payload\n", recvBytes);
                    memcpy(resp->buffer, resp->header + rspHeaderBytes, recvBytes);
                }
            }
            //receive payload data
            bytesToRecv = resp->payloadSize ? resp->payloadSize : resp->bufferSize - 1;
            for (; recvBytes < bytesToRecv; recvBytes += bytes) {
                bytes = recv(conn->sockfd, resp->buffer + recvBytes, bytesToRecv - recvBytes, 0);
                if (bytes <= 0) {
                    eof = 1;
                    break;
                }
            }
            if (recvBytes == resp->payloadSize) eof = 1;
            DEBUG("Payload received: %d bytes\n", recvBytes);
        } while (!eof);
        DEBUG("End of stream\n");
        *(resp->buffer + recvBytes) = 0;
        resp->dataSize = recvBytes;

    } while (0);
    if (conn->sockfd && !(conn->flags & FLAG_KEEP_ALIVE)) {
        closesocket(conn->sockfd);
        conn->sockfd = 0;
    }
    conn->state = IDLE;
    return resp;
}

/**
 * Send the provided HTTP request, returning the response.
 * 
 * @param req the HTTP request to be sent.
 * @return the HTTP response.
 */
HTTP_RESPONSE* sendRequest(const HTTP_REQUEST * const req) {
    const char *path;
    struct hostent *target_host;
    int ret = 0;
    int bytes;
    int postSize;
    HTTP_CONN* conn = malloc(sizeof (HTTP_CONN));

    conn->state = REQUESTING;
    conn->sockfd = 0;

    path = parseURL(req, conn);
    if (!path) {
        DEBUG("Invalid URL path");
        releaseResources(conn);        
        return NULL;
    }

    
    switch (req->method) {
        case HTTP_GET:
            snprintf(conn->header, MAX_HEADER_SIZE + 1, HTTP_GET_HEADER, "GET",
                    path, (conn->flags & FLAG_KEEP_ALIVE) ? "Keep-Alive" : "close", conn->hostname, "\0");
            break;
        case HTTP_POST:
            conn->postPayloadBytes =  strlen(req->postPayload);
            snprintf(conn->header, MAX_HEADER_SIZE + 1, HTTP_POST_HEADER, path, conn->hostname, conn->postPayloadBytes, req->postPayload);
            DEBUG("post request: %s", conn->header);
            break;
    }
    do {
        int hdrsize = (int) strlen(conn->header);
        int retry = 3;
        ret = 0;
        do {
            if (!conn->sockfd) {
                struct sockaddr_in server_addr;

                if ((target_host = gethostbyname((const char*) conn->hostname)) == NULL) {
                    ret = -1;
                    continue;
                }

                if ((conn->sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                    DEBUG("Failed to open socket\n");
                    ret = -1;
                    continue;
                }

                memset(&server_addr.sin_zero, 0, 8);
                server_addr.sin_family = AF_INET;
                server_addr.sin_addr.s_addr = ((struct in_addr *) (target_host->h_addr))->s_addr;
                server_addr.sin_port = htons(conn->port);
                DEBUG("Connecting to server...\n");

                if (connect(conn->sockfd, (struct sockaddr *) &server_addr, sizeof (struct sockaddr)) < 0) {
                    DEBUG("Failed to connect\n");
                    ret = -1;
                    continue;
                }
            }
            DEBUG("Sending request...\n");
            if (sendData(conn, conn->header, hdrsize) != hdrsize) {
                closesocket(conn->sockfd);
                conn->sockfd = 0;
                ret = -1;
                continue;
                ;
            }
            break;
        } while (--retry > 0);
        if (ret == -1) break;

//        if (req->method == HTTP_POST) {
//            if (sendData(conn, req->postPayload, conn->postPayloadBytes) != conn->postPayloadBytes)
//                break;
//        }
    } while (0);
    HTTP_RESPONSE* resp = httpGetResponse(conn);
    releaseResources(conn);
    return resp;

}

int isJsonResponse(const HTTP_RESPONSE* const resp) {
    int respSize;
    
    if (resp == NULL || resp->buffer == NULL) {
        return 0;
    }
    
    respSize = strlen(resp->buffer);

    return resp->buffer[0] == '{' && resp->buffer[respSize -1] == '}';
}

static char* trim(char *str)
{
  char *end;

  // Trim leading space
  while(isspace(*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace(*end)) end--;

  // Write new null terminator
  *(end+1) = 0;
  return str;
}

char* removeChar(char *s, char c)
{
    int writer = 0, reader = 0;

    while (s[reader])
    {
        if (s[reader]!=c) 
        {   
            s[writer++] = s[reader];
        }

        reader++;       
    }
    s[writer]=0;
    return s;
}

void parseJson(HTTP_RESPONSE* const resp) {
    int len, i, j, c, state;
    
    if (resp == NULL) {
        return;
    } 
    resp->jsonSize = 0;
	
	if (resp->buffer == NULL) {
        return;
    }
    
	len = strlen(resp->buffer);
	state = DEF_KEY_QUOTES;
	j = 0;	
    for (i = 0; i < len; i++) {
		if (state == DEF_KEY_QUOTES) {	
			if (resp->buffer[i] == '"') {
				state = DEF_KEY;
				c = 0;		
			}			
			else {
				continue;
			}			
		}
		else if (state == DEF_KEY) {
			if (resp->buffer[i] == '"' && resp->buffer[i-1] != '\\') {
				state = DEF_MIDDLE;
				resp->json[j].key[c] = '\0';
			} else {
				resp->json[j].key[c++] = resp->buffer[i]; 
			}		
		}
		else if (state == DEF_MIDDLE) {	
			if (resp->buffer[i] == ':') {
				state = DEF_VAL_QUOTES;				
			} else {
				continue;
			}			
		}
		else if (state == DEF_VAL_QUOTES) {
			if (isspace(resp->buffer[i])) {
				continue;
			}		
			else if (resp->buffer[i] == '"') {
				state = DEF_VAL_WITH_QUOTES;
				c = 0;		
			} 
			else {
				c = 0;
				resp->json[j].value[c++] = resp->buffer[i];
				state = DEF_VAL_NO_QUOTES;
			}			
		}
		else if (state == DEF_VAL_WITH_QUOTES) {
			if (resp->buffer[i] == '"' && resp->buffer[i-1] != '\\') {
				state = DEF_COMMA;
				resp->json[j].value[c] = '\0';				
			} else {
				resp->json[j].value[c++] = resp->buffer[i]; 
			}		
		}
		else if (state == DEF_VAL_NO_QUOTES) {
			if (resp->buffer[i] == ',') {
				state = DEF_COMMA;
				i--;				
			} else {
				resp->json[j].value[c++] = resp->buffer[i]; 
			}		
		}
		else if (state == DEF_COMMA) {
			if (resp->buffer[i] == ',' || resp->buffer[i] == '}' ||
				isspace(resp->buffer[i])) {
				state = DEF_KEY_QUOTES;
				c = 0;
				j++;				
			} else {
				continue;
			}		
		}
	}
	resp->jsonSize = j;	
}

HTTP_RESPONSE* get(const char* const url) {
    HTTP_REQUEST req;
    HTTP_RESPONSE* resp;    

    req.method = HTTP_GET;
    req.url = url;

    resp = sendRequest(&req);

    if (resp == NULL) {
        return NULL;
    }

    if (isJsonResponse(resp)) {
    	DEBUG("Parsing JSON response: %s", resp->buffer);
        parseJson(resp);
    }
    return resp;
}

HTTP_RESPONSE* post(const char* url, const char body[]) {
    HTTP_REQUEST req;
    HTTP_RESPONSE* resp;    

    req.method = HTTP_POST;
    req.url = url;
    req.postPayload = body;
    resp = sendRequest(&req);
    
    if (resp == NULL) {
        return NULL;
    }
    if (isJsonResponse(resp)) {
        DEBUG("Parsing JSON response: %s", resp->buffer);
        parseJson(resp);
    }
    return resp;
}

char* getJsonValue(Json json[], size_t jsonSize,  char* key) {
    int i;
    if (key == NULL) {
        DEBUG("Null object key parameter");
        return NULL;
    }
    for (i = 0; i < jsonSize; i++) {
        if (strcmp(json[i].key, key) == 0) {
            return json[i].value;
        }
    }
    return NULL;
}

static int fd;
static char fileheader[512];

static int readData(void* buffer, int bufsize) {
    if (fileheader[0]) {
        int ret = snprintf(buffer, bufsize, "%s", fileheader);
        fileheader[0] = 0;
        return ret;
    } else {
        return read(fd, buffer, bufsize);
    }
}


void main(void) {
	int i = 0;
	HTTP_RESPONSE* resp = get("http://10.0.2.2:4300/api/verificarOcorrencia?lat=-23.229287&long=-45.927731&placa=ENH-3553");
	
	parseJson(resp);	
	for (i = 0; i <= resp->jsonSize; i++) {
		printf("%s = %s\n", resp->json[i].key, resp->json[i].value);
	}
		
	return 0;
}

