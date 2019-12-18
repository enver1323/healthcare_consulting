//
// Created by enver on 16/12/19.
//

#ifndef CLIENTS_INJECTION_H
#define CLIENTS_INJECTION_H

#define MAX_CLIENTS 30

#include "../domain/models/clientModel.h"

static struct Client clients[MAX_CLIENTS];

struct Client getClientModelByEmail(char *email);

struct Client getClientModelByEmail(char *email){
    for(int i = 0; i < MAX_CLIENTS; i++)
        if(strcmp(clients[i].userModel.email, email) == 0)
            return clients[i];
}

#endif
