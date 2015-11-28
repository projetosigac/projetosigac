
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "config.h"
#include "display.h"
#include "central.h"
#include "utils.h"
#include "panelUA.h"
#include "kcg_types.h"
#include "realtime.h"

// define the update rate with the central, in seconds.
#define CENTRAL_UPDATE_RATE  30

inC_alertaOcorrencia inAlertaOcorrencia;
outC_alertaOcorrencia outAlertaOcorrencia;
AmbulanceInfo ambulanceInfo;

unsigned long lastUpdate = 0, current, diff;
static bool initialized = false;
static int occurenceId = 0;

void resetUI_alertaOcorrencia(void) {
	inAlertaOcorrencia.occurence.comments[0] = STR_END;
	inAlertaOcorrencia.occurence.location[0] = STR_END;
	inAlertaOcorrencia.occurence.nVictims[0] = STR_END;
}

void* receiveFromDisplay(void* prt) {
	receiveAlertaOcorrencia(&inAlertaOcorrencia);	
	
	debug("ACCEPT: %d  FINISH: %d  UPDATE: %d\n", inAlertaOcorrencia.accept, 
		inAlertaOcorrencia.finish, outAlertaOcorrencia.update);
}

void* sendToDisplay(void* ptr) {	
	sendAlertaOcorrencia(&outAlertaOcorrencia);	
}

void executeAlertaOcorrencia(void) {	
	if (!initialized) {
		initialized = true;
		alertaOcorrencia_init(&outAlertaOcorrencia);
	}	

	receiveFromDisplay(NULL);
	
	if (inAlertaOcorrencia.finish) {
		inAlertaOcorrencia.newOcurrence = false;
		resetUI_alertaOcorrencia();
		lastUpdate = timeInSeconds();
		confirmService(ambulanceInfo.plate, occurenceId);
	}
		
	executeAlertaOcorrenciaUA(&inAlertaOcorrencia, &outAlertaOcorrencia);	
	
	///////////////////////////////////////////////////////////////
	debug("Plate: %s\n", inAlertaOcorrencia.plate);
	if (strlen(inAlertaOcorrencia.plate) > 0) {
		strcpy(ambulanceInfo.plate, inAlertaOcorrencia.plate);
	}
	if (strlen(inAlertaOcorrencia.lat) > 0) {
		ambulanceInfo.latitude = atof(inAlertaOcorrencia.lat);
	}
	if (strlen(inAlertaOcorrencia.lon) > 0) {
		ambulanceInfo.longitude = atof(inAlertaOcorrencia.lon);
	}
	///////////////////////////////////////////////////////////////
		
	
	clearInputs(&inAlertaOcorrencia);
		
	sendToDisplay(NULL);
	
	if(outAlertaOcorrencia.alertaOcorrenciaSM_state_nxt == SSM_st_idle_alertaOcorrenciaSM) {
		  current = timeInSeconds();
		  diff = (current - lastUpdate);
		  
		  if (diff >= CENTRAL_UPDATE_RATE) {
					  
			  debug("Updating occurrences information.\n");
			  lastUpdate = current;
			  
			  occurenceId = checkOccurrence(&ambulanceInfo, &inAlertaOcorrencia.occurence);
			  if (occurenceId > 0) {
				  debug("Changing the state to warning \n");
				  inAlertaOcorrencia.newOcurrence = true;
			  }	
						  
		  }
		  
	}		
}
