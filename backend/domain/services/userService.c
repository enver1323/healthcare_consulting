//
// Created by enver on 14/12/19.
//

#include "../../routes/request.h"
#include "../models/response.h"
#include "../repositories/userRepository.h"
#include "../../controller/clientsInjection.h"

/** Function Declarations */
struct Response userRegister(struct Request request);

struct Response userLogin(int sd, struct Request request);

int findClientIndex(int socket);

int startUserSession(int sd, struct User user);

int closeUserSession(int socket);

struct Response userRegister(struct Request request) {
    struct User user = createUser(request.name, request.email, request.password);
    struct Response response;
    if (strlen(user.error)) {
        response.code = CODE_ERROR_INTERNAL;
        sprintf(response.message, "%s", user.error);
    } else {
        response.code = CODE_SUCCESS;
        sprintf(response.message, MESSAGE_SUCCESS);
        response.data.userNode = user;
    }

    return response;
}

struct Response userLogin(int sd, struct Request request) {
    struct User user = loginUser(request.email, request.password);
    struct Response response;

    if (strlen(user.email)) {
        startUserSession(sd, user);

        response.code = CODE_SUCCESS;
        sprintf(response.message, MESSAGE_SUCCESS);
        response.data.userNode = user;
    } else {
        response.code = CODE_ERROR_INTERNAL;
        sprintf(response.message, "%s", user.error);
    }

    return response;
}

int startUserSession(int socket, struct User user) {
    int index = findClientIndex(socket);
    if(index == -1)
        return EXIT_FAILURE;

    clientModels[index] = user;
    return EXIT_SUCCESS;
}

int closeUserSession(int socket) {
    int index = findClientIndex(socket);
    if(index == -1)
        return EXIT_FAILURE;

    struct User user;
    clientModels[index] = user;

    return EXIT_SUCCESS;
}

int findClientIndex(int socket){
    for(int i = 0; i < MAX_CLIENTS; i++)
        if(clients[i] == socket)
            return i;

    return -1;
}
