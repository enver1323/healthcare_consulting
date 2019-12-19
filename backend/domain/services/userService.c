//
// Created by enver on 14/12/19.
//

#include "../../routes/request.h"
#include "../models/response.h"
#include "../repositories/userRepository.h"
#include "../../controller/clientsInjection.h"

/** Function Declarations */
struct Response userRegister(struct Request request);

struct Response userLogin(struct Client *client, struct Request request);

struct Response userRestoreSession(struct Client *client, struct Request request);

int startUserSession(struct Client *client, struct User user);

int closeUserSession(struct Client *client);

struct Response userRegister(struct Request request) {
    fprintf(stderr, "Name: %s\nEmail: %s\nPassword: %s\n", request.name, request.email, request.password);

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

struct Response userLogin(struct Client *client, struct Request request) {
    fprintf(stderr, "Email: %s\nPassword: %s\n", request.email, request.password);

    struct User user = loginUser(request.email, request.password);
    struct Response response;

    if (strlen(user.email)) {
        startUserSession(client, user);

        response.code = CODE_SUCCESS;
        sprintf(response.message, MESSAGE_SUCCESS);
        response.data.userNode = user;
    } else {
        response.code = CODE_ERROR_INTERNAL;
        sprintf(response.message, "%s", user.error);
    }

    return response;
}

struct Response userRestoreSession(struct Client *client, struct Request request){
    struct User user  = getUser(request.email);
    struct Response response;

    if (strlen(user.email)) {
        startUserSession(client, user);

        response.code = CODE_SUCCESS;
        sprintf(response.message, MESSAGE_SUCCESS);
        response.data.userNode = user;
    } else {
        response.code = CODE_ERROR_INTERNAL;
        sprintf(response.message, "%s", user.error);
    }

    return response;
}

int startUserSession(struct Client *client, struct User user) {
    client->userModel = user;
    return EXIT_SUCCESS;
}

int closeUserSession(struct Client *client) {
    struct User user;
    client->userModel = user;

    close(client->socket);
    client->socket = 0;

    return EXIT_SUCCESS;
}
