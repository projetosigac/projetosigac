/**
 * Implementation for the communication with the SIGAC central.
 */
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "central.h"
#include "config.h"
#include  "httpclient.h"

#define CHECK_OCCURRENCE_URL	"http://%s:%d/api/verificarOcorrencia?lat=%f&long=%f&placa=%s"
#define CONFIRM_SERVICE_URL		"http://%s:%d/api/confirmarAtendimento"
#define CONFIRM_SERVICE_PARAMS	"ocorrenciaId=%d&placaAmbulancia=%s"
#define LOCATION_KEY	"endereco"
#define COMMENTS_KEY	"comentarios"
#define N_VICTIMS_KEY	"n_vitimas"
#define DATE_KEY		"data_abertura"
#define ID_KEY			"id"


int checkOccurrence(AmbulanceInfo* info, Ocurrence* occurence) {
	char url[255];
	char* address;
	char* comments;
	char* nVictims;
	char* id;
	HTTP_RESPONSE* resp;

	sprintf(url, CHECK_OCCURRENCE_URL, centralHost, centralPort, info->latitude, info->longitude,
			info->plate);
	log("Accessing the central at: %s\n", url);
	fflush(stdout);
	resp = get(url);
	
	if (resp->status == OK) {
		
		if (resp->jsonSize > 0) {
			log("Occurrence found!\n");
			
			id = getJsonValue(resp->json, resp->jsonSize, ID_KEY);
			if (id == NULL) id = '\0';
			
			address = getJsonValue(resp->json, resp->jsonSize, LOCATION_KEY);
			if (address == NULL) address = '\0';
			
			nVictims = getJsonValue(resp->json, resp->jsonSize, N_VICTIMS_KEY);
			if (nVictims == NULL) nVictims = '\0';
			
			comments = getJsonValue(resp->json, resp->jsonSize, COMMENTS_KEY);
			if (comments == NULL) comments = '\0';			
			
			strncpy(occurence->location, address, 255);
			strncpy(occurence->nVictims, nVictims, 32);
			strncpy(occurence->comments, comments, 255);
			
			return atoi(id);
		} else {
			log("No occurrence received from the central.\n");
			return false;
		}
		
	} else {
		log_error("Error on the connection with the central. Status:%d\n", resp->httpCode);
		return 0;
	}

}

void confirmService(char* plate, int occurenceId) {
	char url[255];
	char params[255];
	
	sprintf(url, CONFIRM_SERVICE_URL, centralHost, centralPort);
	sprintf(params, CONFIRM_SERVICE_PARAMS, occurenceId, plate);
	log("Confirming service at: %s  Params:%s \n", url, params);
	fflush(stdout);
	post(url, params);
	log("Service confirmed.\n");
	
}