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
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)	{
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    printf("CLIENT CONNECTING ON PORT 8080 TO COMMUNICATE WITH SERVER.....\n");

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    struct Request request;
    sprintf(request.route.module, MODULE_AUTH);
    sprintf(request.route.method, METHOD_REGISTER);
    sprintf(request.name, "TEST_NAME");
    sprintf(request.type, "type");
    sprintf(request.password, "password");
    sprintf(request.email, "email@mail.mail");

    sendto(sock, &request, sizeof(request), 0, (const struct sockaddr *) &serv_addr, sizeof(serv_addr));

    struct Response response;

    recvfrom(sock, &response, sizeof(response), 0, (const struct sockaddr *) &serv_addr, sizeof(serv_addr));

    printf("%d", response.code);
    printf("%s", response.message);

    close(sock);

    return 0;
}
