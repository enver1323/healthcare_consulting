//
// Created by enver on 13/12/19.
//
#ifndef CONTROLLER_INJECTION_H
#define CONTROLLER_INJECTION_H

#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h> //close
#include <arpa/inet.h> //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros

#include "clientsInjection.h"
#include "../routes/router.h"

/** Constants */
#define TRUE 1
#define FALSE 0
#define PORT 8080

#endif