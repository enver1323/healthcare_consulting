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

int initSocket()
{
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
    if(inet_pton(AF_INET, IP, &serv_addr.sin_addr)<=0)	{
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    printf("CLIENT CONNECTING ON PORT 8080 TO COMMUNICATE WITH SERVER.....\n");

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    struct Request request;
    sprintf(request.route.module, MODULE_HOSPITAL);
    sprintf(request.route.method, METHOD_LIST);
    request.id = 88;
    request.page = 3;
//    sprintf(request.search,"%s", "");

    send(sock, &request, sizeof(request), 0);

    struct Response response;

    read(sock, &response, sizeof(response));

    printf("%d\n", response.code);
    for(int i = 0; i < IPP_DOCTOR; i++){
        printf("%s\n", response.data.hospitalList[i].name);
    }

    close(sock);

    return 0;
}
