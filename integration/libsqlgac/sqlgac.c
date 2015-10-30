/*******************************************************************
 * SQL-GAC: SQL Client for the SI-GAC project.
 * 
 * It contains operations for making SQL operations.
 * 
 * Copyright (c) 2015    Fernando Fonseca <fetofs@gmail.com> 
 * Copyright (c) 2015    Rodrigo Roim <roim.rodrigo@gmail.com> 
 *  
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *******************************************************************/

// Include <stdio.h>
#include <stdio.h>

// Include <string.h>
#include <string.h>

// Include "sqlite3.h"
#include "sqlite3.h"

// Include "../librest/httpclient.h"
#include "../librest/httpclient.h"

// Declare the default detabase name.
static const char DBNAME[] = "sqlgac.db";

// Implement the callback private function.
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	return 0;
}

// Implement the execSqlOperation function.
int execSqlOperation(const char* sqlOperation) {
    sqlite3 *db;
    char *errmsg = 0;

    if (sqlite3_open(DBNAME, &db)) {
    	errmsg = sqlite3_errmsg(db);
        fprintf(stderr, "Error opening database: %s\n", errmsg);
        sqlite3_close(db);
        return 1;
    }

    if (sqlite3_exec(db, sqlOperation, callback, 0, &errmsg) != SQLITE_OK) {
        fprintf(stderr, "Error executing operation on database: %s\n", errmsg);
        sqlite3_close(db);
    	return 1;
    }

    sqlite3_close(db);
    return 0;
}

// Implement the sendHttpSqlRequest function.
char* sendHttpSqlRequest(const char* sqlOperation) {
	// Declare the URL char array.
	char url[1515];

	// Set the first character to be '\0'.
	url[0] = '\0';

	// Set the base URL to "http://www.google.com/query" by using strcat.
	strcat(url, "http://powerful-forest-9086.herokuapp.com/");

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

char* sendCrisesForm(const char* name, const char* location, const char* coordinates, const char* lt, const char* lg, const char* address, const char* reference, const char* history, const char* description){
	// Declare the SQL char array
	char sqlOp[1400];
	
	// Set the first character to be '\0'.
	sqlOp[0] = '\0';

	// Set the base of the INSERT query
	strcat(sqlOp, "insert into TABLE_NAME (column_names) values (");
	strcat(sqlOp, name);
	strcat(sqlOp, ",");
	strcat(sqlOp, location);
	strcat(sqlOp, ",");
	strcat(sqlOp, coordinates);
	strcat(sqlOp, ",");
	strcat(sqlOp, lt);
	strcat(sqlOp, ",");
	strcat(sqlOp, lg);
	strcat(sqlOp, ",");
	strcat(sqlOp, address);
	strcat(sqlOp, ",");
	strcat(sqlOp, reference);
	strcat(sqlOp, ",");
	strcat(sqlOp, history);
	strcat(sqlOp, ",");
	strcat(sqlOp, description);
	strcat(sqlOp, ")");

	return sendHttpSqlRequest(sqlOp);
}

char* sendAssistanceForm(const char* solicitor, const char* phone, const char* dispatcher, const char* dateTime, const char* ocr, const char* address, const char* reference, const char* history){
	// Declare the SQL char array
	char sqlOp[1400];
	
	// Set the first character to be '\0'.
	sqlOp[0] = '\0';

	// Set the base of the INSERT query
	strcat(sqlOp, "insert into TABLE_NAME (column_names) values (");
	strcat(sqlOp, solicitor);
	strcat(sqlOp, ",");
	strcat(sqlOp, phone);
	strcat(sqlOp, ",");
	strcat(sqlOp, dispatcher);
	strcat(sqlOp, ",");
	strcat(sqlOp, dateTime);
	strcat(sqlOp, ",");
	strcat(sqlOp, ocr);
	strcat(sqlOp, ",");
	strcat(sqlOp, address);
	strcat(sqlOp, ",");
	strcat(sqlOp, reference);
	strcat(sqlOp, ",");
	strcat(sqlOp, history);
	strcat(sqlOp, ")");

	return sendHttpSqlRequest(sqlOp);
}
