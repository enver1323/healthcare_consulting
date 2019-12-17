//
// Created by enver on 14/12/19.
//
#ifndef RESPONSE_H
#define RESPONSE_H

#include "modelList.h"

#define MODULE_HOSPITAL "moduleHospital"
#define MODULE_DOCTOR "moduleDoctor"

#define CODE_SUCCESS 200
#define CODE_ERROR_INTERNAL 500

#define MESSAGE_SUCCESS "success"
#define MESSAGE_ERROR "error"

/**
 * IPP - Items Per Page
 */
struct Data{
//    union {
        struct Doctor doctorNode;
        struct Doctor doctorList[IPP_DOCTOR];
        struct Hospital hospitalNode;
        struct Hospital hospitalList[IPP_HOSPITAL];
        struct Disease diseaseList[IPP_DISEASE];
        struct User userNode;
//    };
};

struct Response {
    int code;
    char message[1024];
    struct Data data;
};

#endif