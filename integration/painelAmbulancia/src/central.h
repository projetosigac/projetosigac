/* 
 * File with functions for communication with the SIGAC central.
 * 
 * It depends on the configurations read from the configuration file.
 * 
 * File:   central.h
 * Author: Vinicius Souza
 *
 * Created on October 27, 2015, 8:34 PM
 */

#ifndef CENTRAL_H
#define	CENTRAL_H

#include "kcg_types.h"
#include "utils.h"

typedef struct {
	char plate[10];
	double latitude;
	double longitude;
} AmbulanceInfo;

#ifdef	__cplusplus
extern "C" {
#endif

    int checkOccurrence(AmbulanceInfo* info, Ocurrence* occurence);
    void confirmService(char* plate, int occurenceId);


#ifdef	__cplusplus
}
#endif

#endif	/* CENTRAL_H */

