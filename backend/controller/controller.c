#include "controllerInjection.h"

/** Function declaration*/

int startServer();

int initMasterSocket();

int initAddress();

int handleConnections();

int handleNewConnection();

int handleRequest(int sd, struct Request *request);

int sendResponse(int sd, struct Response response);

/** Attributes */
fd_set readFds;
struct sockaddr_in address;
int masterSocket, addressLength, activity;

int startServer() {
    /** Initialize socket */
    if (initMasterSocket()) {
        fprintf(stderr, "Socket initialisation error");
        return EXIT_FAILURE;
    }

    /** Initialize address */
    if (initAddress()) {
        fprintf(stderr, "Address initialisation error");
        return EXIT_FAILURE;
    }

    printf("Waiting for connections\n");

    if (handleConnections()) {
        fprintf(stderr, "Connection error");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int initMasterSocket() {
    int opt = TRUE;

    for (int i = 0; i < MAX_CLIENTS; i++)
        clients[i] = 0;

    /** Create master controller */
    if ((masterSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("controller creation failed");
        return EXIT_FAILURE;
    }

    /** Set master controller to allow multiple connections*/
    if (setsockopt(masterSocket, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int initAddress() {
    /** Set type of controller created */
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    addressLength = sizeof(address);

    /** Bind controller to localhost port 8080 */
    if (bind(masterSocket, (struct sockaddr *) &address, addressLength) < 0) {
        perror("bind failed");
        return EXIT_FAILURE;
    }
    printf("Listener on port %d \n", PORT);

    /** Specify maximum of 3 pending connections for the master controller */
    if (listen(masterSocket, 3) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int handleConnections() {
    int maxSd, curSd, newSocket;
    struct Request request;

    while (TRUE) {
        /** Clear the controller set */
        FD_ZERO(&readFds);
        /** Add Master Controller to set */
        FD_SET(masterSocket, &readFds);
        maxSd = masterSocket;
        /** Add child sockets to set */
        for (int i = 0; i < MAX_CLIENTS; i++) {
            /** Controller Descriptor */
            curSd = clients[i];
            /** Add to read list if valid */
            if (curSd > 0)
                FD_SET(curSd, &readFds);

            /** Highest file descriptor number, is needed for the select function */
            if (curSd > maxSd)
                maxSd = curSd;
        }

        /** Wait for an activity on one of the sockets, timeout is NULL, so wait indefinitely */
        activity = select(maxSd + 1, &readFds, NULL, NULL, NULL);
        if ((activity < 0) && (errno != EINTR))
            fprintf(stderr, "Select error");

        /** Handle request to master controller (incoming connection) */
        if (handleNewConnection()) {
            fprintf(stderr, "New connection error");
            return EXIT_FAILURE;
        }

        /** Handle request from non-master controller (request to other controller)*/
        for (int i = 0; i < MAX_CLIENTS; i++) {
            curSd = clients[i];
            if (FD_ISSET(curSd, &readFds)) {
                /** Read incoming request and check if is closing one */
                if (read(curSd, &request, sizeof(struct Request)) == 0) {

                    getpeername(curSd, (struct sockaddr *) &address, (socklen_t *) &addressLength);
                    printf("Host disconnected , ip %s , port %d \n", inet_ntoa(address.sin_addr),
                           ntohs(address.sin_port));

                    closeUserSession(curSd);
                    close(curSd);
                    clients[i] = 0;
                } else {
                    /** Handle incoming request */
                    if (handleRequest(curSd, &request))
                        fprintf(stderr, "Failed to handle request");
                }
            }
        }
    }

}

int handleNewConnection() {
    int newSocket;

    if (FD_ISSET(masterSocket, &readFds)) {
        if ((newSocket = accept(masterSocket, (struct sockaddr *) &address, (socklen_t *) &addressLength)) < 0) {
            perror("accept");
            return EXIT_FAILURE;
        }

        printf("New connection , controller fd is %d , ip is : %s , port : %d \n", newSocket,
               inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        /** Add new controller to an array of sockets */
        for (int i = 0; i < MAX_CLIENTS; i++)
            if (clients[i] == 0) {
                clients[i] = newSocket;
                printf("Adding to list of sockets as %d\n", i);
                break;
            }
    }

    return EXIT_SUCCESS;
}

int handleRequest(int sd, struct Request *request) {
    struct Response response;
    struct Route route = request->route;

    if (strcmp(route.module, MODULE_AUTH) == 0) {
        if (strcmp(METHOD_REGISTER, route.method) == 0) {
            response = userRegister(*request);

            if (sendResponse(sd, response))
                return EXIT_FAILURE;
        }else if (strcmp(METHOD_LOGIN, route.method) == 0) {
            response = userLogin(sd, *request);

            if (sendResponse(sd, response))
                return EXIT_FAILURE;
        }
    }else if(strcmp(route.module, MODULE_DOCTOR) == 0){
        if(strcmp(route.method, METHOD_LIST) == 0){
            response = doctorList(*request);

            if (sendResponse(sd, response))
                return EXIT_FAILURE;
        }
    }

    sprintf(request->route.module, MODULE_DEFAULT);

    return EXIT_SUCCESS;
}

int sendResponse(int sd, struct Response response) {
    int size = sizeof(response);
    if (send(sd, &response, size, 0))
        return EXIT_SUCCESS;

    fprintf(stderr, "Failed to send response");
    return EXIT_FAILURE;
}