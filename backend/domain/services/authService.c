//
// Created by enver on 14/12/19.
//

#include "../../routes/request.h"
#include "../models/response.h"
#include "../repositories/userRepository.h"

struct Response authRegister(struct Request request) {
    struct User user = createUser(request.name, request.type, request.email, request.password);
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

struct Response authLogin(struct Request request){
    struct User user;
    struct Response response;

    
}