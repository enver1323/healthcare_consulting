//
// Created by enver on 13/12/19.
//
#ifndef REQUEST_H
#define REQUEST_H

#define MODULE_DEFAULT "defaultModule"

#define MODULE_AUTH "moduleAuth"
#define METHOD_REGISTER "methodRegister"
#define METHOD_LOGIN "methodLogin"

#define MODULE_HOSPITAL "moduleHospital"
#define MODULE_DOCTOR "moduleDoctor"

#define METHOD_LIST "methodList"
#define METHOD_SEARCH "methodSearch"

#pragma pack(1)

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

    char name[256];
    char email[256];
    char search[256];
    char password[1024];
    char description[1024];
};

#pragma pack(0)

#endif