#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define IP "127.0.0.1"

static int sock = 0;
struct sockaddr_in serv_addr;

#include "routes/request.h"
#include "models/response.h"

void delay(int delayTime) {
    time_t startTime = time(NULL);
    while (time(NULL) < startTime + delayTime) {}
}

void makeRequest(int);

void restoreSession();

void *rcvMsgs(void *threadId);

void *sendMsgs(void *threadId);


int initSocket() {
    pthread_t threads[2];

    printf("CREATING CLIENT SOCKET .....\n");
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    printf("DEFINING CLIENT SOCKET FAMILY, ADDRESS & PORT .....\n");
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, IP, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    printf("CLIENT CONNECTING ON PORT 8080 TO COMMUNICATE WITH SERVER.....\n");

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    restoreSession();
    makeRequest(0);
//    pthread_create(&threads[0], NULL, rcvMsgs, (void *) 0);

//    pthread_create(&threads[1], NULL, sendMsgs, (void *) 1);
//    while (1) {

//    }

    close(sock);

    return 0;
}

void restoreSession() {
    struct Request request;
    sprintf(request.route.module, MODULE_AUTH);
    sprintf(request.route.method, METHOD_RESTORE);
    sprintf(request.email, "info@enver.uz");

    send(sock, &request, sizeof(request), 0);

    struct Response response;

    read(sock, &response, sizeof(response));

    printf("\nCODE %d", response.code);
    printf("\nUSER EMAIL: %s", response.data.userNode.email);
    printf("\nUSER NAME: %s", response.data.userNode.name);
}

void *rcvMsgs(void *threadId) {
    char buffer[1024] = {0};
    while (1) {
        struct Response response;
        read(sock, &response, sizeof(response));
        if(response.code == 200 && response.data.messageNode.chatId)
            printf("\nSender %s:\n %s\n\n", response.data.messageNode.senderEmail, response.data.messageNode.text);

        response.code = 500;
    }
    pthread_exit(NULL);
    return 0;
}

void *sendMsgs(void *threadId) {
    char cchat[256];
    while (1) {
        memset(cchat, 0, sizeof(cchat));
        fgets(cchat, sizeof(cchat), stdin);

        struct Request request;
        sprintf(request.route.module, MODULE_CHAT);
        sprintf(request.route.method, METHOD_SEND);

        request.id = 1;
        sprintf(request.email, "enver1323@gmail.com");
        sprintf(request.text, "%s", cchat);

        send(sock, &request, sizeof(request), 0);

        if (strncmp(cchat, "bye", strlen("bye")) == 0)
            break;
    }
    pthread_exit(NULL);
    return 0;
}

void makeRequest(int page) {
    struct Request request;
    sprintf(request.route.module, MODULE_CHAT);
    sprintf(request.route.method, METHOD_SHOW);

    request.id = 1;
//    sprintf(request.doctorEmail, "info@enver.uz");
//    sprintf(request.patientEmail, "abduhakim.muminov@minzdrav.uz");
    request.page = page;

    send(sock, &request, sizeof(request), 0);

    struct Response response;

    read(sock, &response, sizeof(response));

    printf("\nCODE %d\n", response.code);
//    printf("\nORDER %d\n", response.data.queueNode.order);
    for (int i = 0; i < IPP_CHAT; i++){
//        printf("%s\n", response.data.hospitalNode.doctorList[i].name);
        printf("%d\n", response.data.chatList[i].id);
    }
}
