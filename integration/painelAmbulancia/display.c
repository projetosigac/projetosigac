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

#include "display.h"
#include "utils.h"
#include "config.h"

#define MSG_SIZE 2048

int displaySocket;

void writePanelSignals(void) {
    char buffer[MSG_SIZE];
    int num_sent_bytes;
    
//    TODO call the ARINC 661 protocol
//    num_sent_bytes = ua_send((buffer_el *) buffer, &ua_outputs, NULL);
    send(displaySocket, buffer, num_sent_bytes, MSG_DONTWAIT);
}

void readPanelSignals(void) {
    char buffer[MSG_SIZE];
    int num_received_bytes;
    
    /* Receive all input signals from DF server */
    num_received_bytes = recv(displaySocket, buffer, MSG_SIZE, MSG_DONTWAIT);
    if (num_received_bytes > 0) {
//        TODO Connect with the SCADE display API
//        ua_receive((buffer_el *) buffer, num_received_bytes, &ua_inputs, NULL);
    }
}

void connectToDisplayServer(void) {
    log("Connecting to ARINC 661 server...\n")

            struct hostent *server = NULL;
    struct sockaddr_in address;

    displaySocket = socket(AF_INET, SOCK_STREAM, 0);
    if (displaySocket < 0) {
        log_error("ERROR: cannot open a socket !\n");
        exit(1);
    }

    server = gethostbyname(displayHost);
    if (server == NULL) {
        log_error("ERROR: cannot resolve display hostname (%s) !\n", DF_server_ip);
        exit(EXIT_FAILURE);
    }

    memset(&address, 0, sizeof (address));
    memcpy(&address.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    address.sin_family = AF_INET;
    address.sin_port = htons(displayPort);

    if (connect(displaySocket, (const struct sockaddr *) &address, sizeof (address)) < 0) {
        log_error("ERROR: cannot connect with host (%s/%d) !\n", displayHost, displayPort);
        exit(1);
    }

    log("Connected to ARINC 661 Server (%s/%d) .\n", displayHost, displayPort);
}

void releaseDisplayConnection(void) {
    if (displaySocket) {
        close(displaySocket);
    }
}