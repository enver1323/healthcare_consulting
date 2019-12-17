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
    while(time(NULL) < startTime + delayTime){

    } //stranno vrode ne rabotaet chto li, t.k slishkom bistro res daet ++
}

void makeRequest(int);

int initSocket() {
    printf("CREATING CLIENT SOCKET .....\n");
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n"); //wtf krch go git last push
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

    for (int i = 0; i < 7; ++i) {
        makeRequest(i);
        delay(1);
    }
    for (int j = 5; j >= 0; --j) { //v proshliy raz Page 4 first item was L.Luchkov Page 2 broken right now, that is y it shifted
        makeRequest(j);
        delay(1);
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    close(sock);

    return 0;
}

void makeRequest(int page) {
    struct Request request;
    sprintf(request.route.module, MODULE_DOCTOR);
    sprintf(request.route.method, METHOD_LIST);
//    request.hospital_id = 0;
    request.page = page;
    sprintf(request.search, "");

    send(sock, &request, sizeof(request), 0);

    struct Response response;

    read(sock, &response, sizeof(response));

    printf("\n\nPAGE %d\n %d\n", page+1,response.code);
    for (int i = 0; i < IPP_HOSPITAL; i++) {
        printf("%s\n", response.data.doctorList[i].name);
    }

}
