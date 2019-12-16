//
// Created by enver on 16/12/19.
//

#ifndef CLIENTS_INJECTION_H
#define CLIENTS_INJECTION_H

#define MAX_CLIENTS 30

#include "../domain/models/userModel.h"

static int clients[MAX_CLIENTS];
static struct User clientModels[MAX_CLIENTS];

#endif
