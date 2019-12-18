//
// Created by enver on 19/12/19.
//

#ifndef CLIENT_MODEL_H
#define CLIENT_MODEL_H

#include "userModel.h"

struct Client{
    int socket;
    struct User userModel;
};

#endif //BACKEND_CLIENTMODEL_H
