/* 
 * This file is the starting point of the Ambulance Panel.
 * 
 * File:   main.c
 * Author: Vinicius Souza
 *
 * Created on October 26, 2015, 10:35 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <pthread.h>
#include <errno.h>
#include <fcntl.h>

#include "config.h"
#include "display.h"
#include "central.h"
#include "utils.h"
#include "panelUA.h"

/*
 * The entry point of the Ambulance Panel.
 */
int main(int argc, char** argv) {
    printf("Reading configurations...\n");
    readConfig(); // read the environment configuration from the config file.
    
    connectToDisplayServer(); 
    
    while(true) {
        readPanelSignals();
        
        executePanelUA();
    }
    
    releaseDisplayConnection();
    
    return (EXIT_SUCCESS);
}

