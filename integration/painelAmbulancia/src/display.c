/**
 * Implementation of the communication with the display API
 * using sockets.
 * 
 * File:   display.h
 * Author: Vinicius Souza
 *
 * Created on October 27, 2015, 8:41 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <pthread.h>
#include <errno.h>
#include <fcntl.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#include "ua.h"
#include "utils.h"
#include "config.h"
#include "panelUA.h"

#define MSG_SIZE 2048

int diplaySocket;
bool isConnected = false;

void sendAlertaOcorrencia(outC_alertaOcorrencia* operatorOut) {
    int num_sent_bytes, i = 0;
	char buffer[MSG_SIZE];	
			
    if (!isConnected) {
    	log_error("It was not possible to send data to the display. The application is not connected to the display server.");
    	return;
    }
	debug("Sending data to the display...\n");
    num_sent_bytes = ua_send((buffer_el *) buffer, operatorOut, NULL);
    send(diplaySocket, buffer, num_sent_bytes, 0);
	
}

void receiveAlertaOcorrencia(inC_alertaOcorrencia* operatorInput) {
    char buffer[MSG_SIZE];
    int num_received_bytes;
    
    if (!isConnected) {
		log_error("It was not possible to receive data from the display. The application is not connected to the display server.");
		return;
	}	
    /* Receive all input signals from DF server */
	debug("Receiving data from the display...\n");
	
    num_received_bytes = recv(diplaySocket, buffer, MSG_SIZE, 0);
    if (num_received_bytes > 0) {
    	ua_receive((buffer_el *) buffer, num_received_bytes, operatorInput, NULL);
    }
	debug("Received bytes: %d\n", num_received_bytes);	
}

void connectToDisplayServer(void) {
    struct hostent *server = NULL;
    struct sockaddr_in address;
    
    log("Connecting to ARINC 661 server...\n");

	diplaySocket = socket(AF_INET, SOCK_STREAM, 0);
    if (diplaySocket < 0) {
        log_error("ERROR: cannot open a socket !\n");
        fflush(stdout);
        exit(1);
    }

    server = gethostbyname(displayHost);
    if (server == NULL) {
        log_error("ERROR: cannot resolve display hostname (%s) !\n", displayHost);
        fflush(stdout);
        exit(EXIT_FAILURE);
    }

    memset(&address, 0, sizeof (address));
    memcpy(&address.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    address.sin_family = AF_INET;
    address.sin_port = htons(displayPort);

	while (true) {
		if (connect(diplaySocket, (const struct sockaddr *) &address, sizeof (address)) < 0) {
			log_error("ERROR: cannot connect with host (%s/%d) !\n", displayHost, displayPort);
			fflush(stdout);
			usleep(3000000); // sleep for 3 seconds.
		} else {
			break;
		}
	}
	
    log("Connected to ARINC 661 Server (%s/%d) .\n", displayHost, displayPort);
    isConnected = true;
}

void releaseDisplayConnection(void) {
    if (diplaySocket) {
        close(diplaySocket);
    }
    isConnected = false;
}
