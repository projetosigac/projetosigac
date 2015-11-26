/*******************************************************************
 * SQL-GAC: SQL Client for the SI-GAC project.
 * 
 * It contains operations for making SQL operations.
 * 
 * Copyright (c) 2015    Fernando Fonseca <fetofs@gmail.com> 
 * Copyright (c) 2015    Rodrigo Roim <roim.rodrigo@gmail.com> 
 *  
 *  Distributed under GPL license
 *  All rights reserved.
 *******************************************************************/

// Include <string.h>
#include <string.h>

// Include "../librest/httpclient.h"
#include "../librest/httpclient.h"

// Implement the sendSqlRequest function.
char* sendSqlRequest(const char* sqlOperation) {
	// Declare the URL char array.
	char url[1515];

	// Set the first character to be '\0'.
	url[0] = '\0';

	// Set the base URL to "http://www.google.com/query" by using strcat.
	// TODO: Use the HTTP Proxy URL.
	strcat(url, "http://www.google.com/query");

	// Append the query string "?q=" by using strcat.
	strcat(url, "?q=");

	// Append the sqlOperation string.
	strcat(url, sqlOperation);

	// Prepare an HTTP_REQUEST.
	HTTP_REQUEST req;

	// Set the request method to HTTP_GET.
	req.method = HTTP_GET;

	// Set the request url to url.
	req.url = url;

	// Return the sent request buffer.
	return sendRequest(&req)->buffer;
}
