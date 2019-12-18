//
// Created by enver on 13/12/19.
//
#ifndef REQUEST_H
#define REQUEST_H

#include "../controller/clientsInjection.h"

#define MODULE_DEFAULT "defaultModule"

#define MODULE_AUTH "moduleAuth"
#define METHOD_REGISTER "methodRegister"
#define METHOD_RESTORE "methodRestore"
#define METHOD_LOGIN "methodLogin"

#define MODULE_HOSPITAL "moduleHospital"
#define MODULE_DISEASE "moduleDisease"
#define MODULE_DOCTOR "moduleDoctor"

#define METHOD_LIST "methodList"
#define METHOD_SHOW "methodShow"
#define METHOD_SEARCH "methodSearch"

#define MODULE_QUEUE "moduleQueue"
#define METHOD_ADD "methodAdd"
#define METHOD_SEND "methodSend"
#define METHOD_DELETE "methodDelete"

#define MODULE_CHAT "moduleChat"

struct Route {
    char module[1024];
    char method[1024];
};

struct Request {
    struct Route route;

    /** Request Parameters */
    int id;
    int page;
    int hospital_id;

    char text[256];
    char name[256];
    char email[256];
    char search[256];
    char password[1024];
    char description[1024];

    char doctorEmail[256];
    char patientEmail[256];
};

#endif