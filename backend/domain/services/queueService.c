//
// Created by enver on 17/12/19.
//

#include "../../routes/request.h"
#include "../models/response.h"
#include "../repositories/queueRepository.h"

struct Response queueAdd(struct Request request) {
    struct Response response;

    struct Queue queue = enqueue(request.doctorEmail, request.patientEmail);

    response.code = 200;
    response.data.queueNode = queue;
    sprintf(response.message, "%s", MESSAGE_SUCCESS);

    return response;
}

struct Response queueDelete(struct Request request) {
    struct Response response;

    if(dequeue(request.doctorEmail, request.patientEmail)){
        response.code = CODE_ERROR_INTERNAL;
        sprintf(response.message, "%s", MESSAGE_ERROR);
    }else{
        response.code = CODE_SUCCESS;
        sprintf(response.message, "%s", MESSAGE_SUCCESS);
    }

    return response;
}