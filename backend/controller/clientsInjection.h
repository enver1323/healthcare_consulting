//
// Created by enver on 16/12/19.
//

#ifndef CLIENTS_INJECTION_H
#define CLIENTS_INJECTION_H

#define MAX_CLIENTS 30

#include "../domain/models/userModel.h"

//static int clients[MAX_CLIENTS];
//static struct User clientModels[MAX_CLIENTS];

struct Client{
    int socket;
    struct User userModel;
};

static struct Client clients[MAX_CLIENTS];

//struct User getUserModelBySocket(int sd);
//
//struct User getUserModelBySocket(int sd){
//    for(int i = 0; i < MAX_CLIENTS; i++)
//        if(clients[i] == sd)
//            return clientModels[i];
//}

#endif
