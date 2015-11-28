/**
 * Implementation of the functions of the environment configuration.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "config.h"

#define CONFILE_FILE_LOCATION   "./panel.cfg"
#define PROPERTY_SEPARATOR      "="

#define CENTRAL_HOST            "central_host"
#define CENTRAL_PORT            "central_port"
#define DISPLAY_HOST            "display_host"
#define DISPLAY_PORT            "display_port"



//////////////////////////////////////////////////////////////
//      GLOBALS
//////////////////////////////////////////////////////////////
char centralHost[30];
int centralPort;

char displayHost[30];
int displayPort;


//////////////////////////////////////////////////////////////
//      PRIVATE FUNCTIONS
//////////////////////////////////////////////////////////////

static void readProperty(char* line) {
    char* token;
    char name[64];
    char val[64];
    
    token = strtok(line, PROPERTY_SEPARATOR);
    if (token == NULL) {
        log_error("Invalid configuration file: name not found\n");
        return;
    }
    strcpy(name, trim(token));
    
    token = strtok(NULL, PROPERTY_SEPARATOR);
    if (token == NULL) {
        log_error("Invalid configuration file: value not found\n");
        return;
    }
    strcpy(val, trim(token));
    
    if (!strcmp(name, DISPLAY_HOST)) {
        strcpy(displayHost, val);
        printf("Display host: %s\n", displayHost);
    }    
    else if (!strcmp(name, DISPLAY_PORT)) {
        displayPort = atoi(val);
        printf("Display port: %d\n", displayPort);
    }
    else if (!strcmp(name, CENTRAL_HOST)) {
        strcpy(centralHost, val);
        printf("Central host: %s\n", centralHost);
    }    
    else if (!strcmp(name, CENTRAL_PORT)) {
        centralPort = atoi(val);
        printf("Central port: %d\n", centralPort);
    }
}

//////////////////////////////////////////////////////////////
//      PUBLIC FUNCTIONS
//////////////////////////////////////////////////////////////

void readConfig(void) {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    bool hasError = false;
    
    fp = fopen(CONFILE_FILE_LOCATION, "r+");
    if (fp == NULL) {
        log_error("Panel config file not found.\n");
        exit(EXIT_FAILURE);
    }

    printf("--- PANEL CONFIGURATION --- \n");
    
    while ((read = getline(&line, &len, fp)) != -1) {
        readProperty(line);
    }
    
    printf("---------------------------- \n");
    
    
    if (!centralHost[0]) {
        log_error("Central host IP not provided.\n");       
        hasError = true;
    }
    if (!displayHost[0]) {
        log_error("Display host IP not provided.\n");       
        hasError = true;
    }
        
    fclose(fp);
    if (line)
        free(line);
    if (hasError) {
        exit(EXIT_FAILURE);
    }
}
