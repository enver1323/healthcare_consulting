//
// Created by enver on 17/12/19.
//

#ifndef ROUTER_H
#define ROUTER_H

#include "../domain/services/serviceList.h"

/** Function Declarations */
int handleRequest(struct Client *client, struct Request *request);

int sendResponse(int sd, struct Response response);

int handleRequest(struct Client *client, struct Request *request) {
    struct Response response;
    struct Route route = request->route;

    if (strcmp(route.module, MODULE_AUTH) == 0) {
        if (strcmp(METHOD_REGISTER, route.method) == 0) {
            response = userRegister(*request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        } else if (strcmp(METHOD_LOGIN, route.method) == 0) {
            response = userLogin(client, *request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        } else if (strcmp(METHOD_RESTORE, route.method) == 0) {
            response = userRestoreSession(client, *request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        }
    } else if (strcmp(route.module, MODULE_DOCTOR) == 0) {
        if (strcmp(route.method, METHOD_LIST) == 0) {
            response = doctorList(client, *request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        }
    } else if (strcmp(route.module, MODULE_HOSPITAL) == 0) {
        if (strcmp(route.method, METHOD_LIST) == 0) {
            response = hospitalList(*request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        } else if (strcmp(route.method, METHOD_SHOW) == 0) {
            response = hospitalNode(client, *request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        }
    } else if (strcmp(route.module, MODULE_DISEASE) == 0) {
        if (strcmp(route.method, METHOD_LIST) == 0) {
            response = diseaseList(*request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        }
    } else if (strcmp(route.module, MODULE_QUEUE) == 0) {
        if (strcmp(route.method, METHOD_ADD) == 0) {
            response = queueAdd(*request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        } else if (strcmp(route.method, METHOD_DELETE) == 0) {
            response = queueDelete(*request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        } else if (strcmp(route.method, METHOD_LIST) == 0) {
            response = queueList(client, *request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        }
    } else if (strcmp(route.module, MODULE_CHAT) == 0) {
        if (strcmp(route.method, METHOD_LIST) == 0) {
            response = chatList(client, *request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        } else if (strcmp(route.method, METHOD_ADD) == 0) {
            response = startChat(client, *request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        } else if (strcmp(route.method, METHOD_SEND) == 0) {
            response = sendMessage(client, *request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        } else if (strcmp(route.method, METHOD_SHOW) == 0) {
            response = messageList(*request);

            if (sendResponse(client->socket, response))
                return EXIT_FAILURE;
        }
    }

    sprintf(request->route.module, MODULE_DEFAULT);

    return EXIT_SUCCESS;
}

int sendResponse(int sd, struct Response response) {
    int size = sizeof(response);
    if (sendall(sd, &response, size, 0))
        return EXIT_SUCCESS;

    fprintf(stderr, "Failed to send response");
    return EXIT_FAILURE;
}

#endif
