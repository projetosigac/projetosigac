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
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <errno.h>
#include <fcntl.h>

#include "config.h"
#include "utils.h"
#include "realtime.h"
#include "central.h"
#include "panelUA.h"
#include "display.h"
#include "alertaOcorrenciaController.h"


#define MAIN_LOOP_DURATION  5 // the duration of the main loop, in milliseconds.

typedef enum {
	ALERTA_OCORRENCIA_UI
} widget;

widget currentUI;

void mainLoop() {
    fflush(stdout);
    switch(currentUI) {
    case ALERTA_OCORRENCIA_UI:
    	executeAlertaOcorrencia();
    	break;
    default:
    	break;
    }
}

/*
 * The entry point of the Ambulance Panel.
 */
int main(int argc, char** argv) {
    log("Reading configurations...\n");
    readConfig(); // read the environment configuration from the config file.

    currentUI = ALERTA_OCORRENCIA_UI;	

    connectToDisplayServer();
    loopInTimeWindow(MAIN_LOOP_DURATION, &mainLoop);
    releaseDisplayConnection();

    fflush(stdout);
    return (EXIT_SUCCESS);

}



