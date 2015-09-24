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

#include "CommunicationInterfaces.h"
#include "OperatorInformation.h"

extern int gethostname(char *, size_t);
extern int clock_gettime(clockid_t, struct timespec*);

char *DF_server_ip = "127.0.0.1";
int DF_server_port = 1231;
int DF_server_socket;

char *broadcast_group = "224.255.255.255";
char *network_interface_ip = "127.0.0.1";
int broadcast_port = 12340;

int broadcast_socket;
struct sockaddr_in broadcast_address;

int listening_socket;

pthread_t thread_receiver;
pthread_mutex_t lock;


extern void receiveMessage(FRAMEWORK_MESSAGE);
extern void buildMessage(FRAMEWORK_MESSAGE*);
extern void executeOperator();
extern void clear_ua_inputs();
extern void clear_ua_outputs();
extern void initializeCustomLogic();
extern void executeCustomLogic();

extern operator_input_type ua_inputs;
extern operator_output_type ua_outputs;


void connectToDFServer() {
    printf("DF server IP...: [%s]\n", DF_server_ip);
    printf("DF server Port: [%d]\n", DF_server_port);
    printf("\n");

    struct hostent *server = NULL;
    struct sockaddr_in address;

    DF_server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (DF_server_socket < 0) {
        printf("ERROR: cannot open a socket !\n");
        exit(1);
    }

    server = gethostbyname(DF_server_ip);
    if (server == NULL) {
        printf("ERROR: cannot resolve hostname (%s) !\n", DF_server_ip);
        exit(1);
    }

    memset(&address, 0, sizeof(address));
    memcpy(&address.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    address.sin_family = AF_INET;
    address.sin_port = htons(DF_server_port);

    if (connect(DF_server_socket, (const struct sockaddr *) &address, sizeof(address)) < 0) {
        printf("ERROR: cannot connect with host (%s/%d) !\n", DF_server_ip, DF_server_port);
        exit(1);
    }

    printf("Connected to DF Server (%s/%d) .\n", DF_server_ip, DF_server_port);
}

void * receiveMessagesFromPeers(void *ptr) {
    struct sockaddr_in listening_address;
    int reuseaddr_option = 1;
    struct ip_mreq listening_to_group;

    listening_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (listening_socket < 0 ) {
        printf("ERROR: cannot open a socket !\n");
        exit(1);
    }

    /* This call is what allows broadcast packets to be received by many processes on same host */
    if (setsockopt(listening_socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr_option, sizeof(reuseaddr_option)) < 0 ) {
        printf("ERROR: cannot configure socket for SO_REUSEADDR !\n");
        exit(1);
    }

    memset(&listening_address, 0, sizeof(listening_address));

    listening_address.sin_family = AF_INET;
    listening_address.sin_port = htons(broadcast_port);
    listening_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listening_socket, (struct sockaddr *) &listening_address, sizeof(listening_address)) < 0 ) {
        printf("ERROR: cannot bind socket !\n");
        exit(1);
    }

    memset(&listening_to_group, 0, sizeof(listening_to_group));
    listening_to_group.imr_multiaddr.s_addr = inet_addr(broadcast_group);
    listening_to_group.imr_interface.s_addr = inet_addr(network_interface_ip);

    if (setsockopt(listening_socket, IPPROTO_IP, IP_ADD_MEMBERSHIP, &listening_to_group, sizeof(listening_to_group)) < 0) {
        printf("ERROR: cannot add to multicast group !\n");
        exit(1);
    }

    int num_received_bytes;
    struct sockaddr_in address_receiver;
    int address_length = sizeof(struct sockaddr_in);

    char buffer[MSG_SIZE];

    while(1) {
        num_received_bytes = recvfrom(listening_socket, buffer, MSG_SIZE, 0, (struct sockaddr *) &address_receiver, (socklen_t *) &address_length);
        if (num_received_bytes < 0) {
            printf("ERROR: could not receive messages from peers !\n");
            exit(1);
        }

        pthread_mutex_lock(&lock);
        receiveMessage(*(FRAMEWORK_MESSAGE*)buffer);
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

void connectToPeers() {
    int broadcast_option = 1;
    struct in_addr network_interface;

    broadcast_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (broadcast_socket < 0) {
        printf("ERROR: cannot open a socket !\n");
        exit(1);
    }

    if (setsockopt(broadcast_socket, SOL_SOCKET, SO_BROADCAST, &broadcast_option, sizeof(broadcast_option)) < 0) {
        printf("ERROR: cannot configure socket for SO_BROADCAST !\n");
        exit(1);
    }

    memset(&network_interface, 0, sizeof(network_interface));
    network_interface.s_addr = inet_addr(network_interface_ip);

    if (setsockopt(broadcast_socket, IPPROTO_IP, IP_MULTICAST_IF, &network_interface, sizeof(network_interface)) < 0) {
        printf("ERROR: cannot configure internet interface for MULTICAST !\n");
        exit(1);
    }

    memset(&broadcast_address, 0, sizeof(broadcast_address));
    broadcast_address.sin_family = AF_INET;
    broadcast_address.sin_port = htons(broadcast_port);
    broadcast_address.sin_addr.s_addr = inet_addr(broadcast_group);

    pthread_attr_t attri;
    struct sched_param params;

    pthread_attr_init(&attri);
    pthread_attr_setinheritsched(&attri, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_getschedparam(&attri, &params);

    params.sched_priority = 20;
    pthread_attr_setschedparam(&attri, &params);

    pthread_create(&thread_receiver, &attri, receiveMessagesFromPeers, NULL);

    printf("Connected to Peers.\n");
}

void sendMessagesToPeers() {
    FRAMEWORK_MESSAGE message;

    memset(&message, 0, sizeof(message));
    message.to = UTI_AVAILABILITY;
    buildMessage(&message);
    sendto(broadcast_socket, (char *) &message, sizeof(message), 0, (struct sockaddr *) &broadcast_address, sizeof(broadcast_address));

    memset(&message, 0, sizeof(message));
    message.to = UTI_COUNTS;
    buildMessage(&message);
    sendto(broadcast_socket, (char *) &message, sizeof(message), 0, (struct sockaddr *) &broadcast_address, sizeof(broadcast_address));

    /* Send a message to each peer */
}

void usage() {
    printf("USAGE: Launch.exe <DF_server_ip> <DF_server_port> <broadcast_group> <network_interface> <broadcast_port> \n");
    exit(1);
}

void parseParameters(int argc, char **argv) {
    if (argc != 6)
        usage();
    DF_server_ip = argv[1];
    DF_server_port = atoi(argv[2]);
    broadcast_group = argv[3];
    network_interface_ip = argv[4];
    broadcast_port = atoi(argv[5]);
}

int main(int argc, char **argv) {
    parseParameters(argc, argv);

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("ERROR: cannot initialize mutex! \n");
        exit(1);
    }

    connectToDFServer();

    connectToPeers();

    unsigned long t1, t2;
    struct timespec clock;
    unsigned long sleep_time;

    char buffer[MSG_SIZE];
    int num_received_bytes;
    int num_sent_bytes;

    /* Start by resetting the inputs and outputs to their default values */
    pthread_mutex_lock(&lock);
    clear_ua_inputs();
    clear_ua_outputs();
    initializeCustomLogic();
    pthread_mutex_unlock(&lock);

    while (1) {
        clock_gettime(CLOCK_REALTIME, &clock);
        t1 = clock.tv_sec * 1000000L;

        pthread_mutex_lock(&lock);

        /* Receive all input signals from DF server */
        num_received_bytes = recv(DF_server_socket, buffer, MSG_SIZE, MSG_DONTWAIT);
        if (num_received_bytes > 0)
            ua_receive((buffer_el *) buffer, num_received_bytes, &ua_inputs, NULL);

        /* Call the User Application generated by SCADE */
		executeOperator();

        /* Clear inputs after each cycle update */
        clear_ua_inputs();

        pthread_mutex_unlock(&lock);

        /* Send all output signals to DF server */
        num_sent_bytes = ua_send((buffer_el *) buffer, &ua_outputs, NULL);
        send(DF_server_socket, buffer, num_sent_bytes, MSG_DONTWAIT);

        /* Send messages to each peer */
        sendMessagesToPeers();

        executeCustomLogic();

        clock_gettime(CLOCK_REALTIME, &clock);
        t2 = clock.tv_sec * 1000000L;

        sleep_time = 100000L;
        if (t2 - t1 > sleep_time)
            printf("Timing: cycle delayed by %d milliseconds! \n", (int) (((t2 - t1) - sleep_time)/1000L));
        else
            usleep(sleep_time - (t2 - t1));
    }

    pthread_join(thread_receiver, NULL);

    close(DF_server_socket);
    close(broadcast_socket);
    close(listening_socket);

    pthread_mutex_destroy(&lock);

    return 0;
}
