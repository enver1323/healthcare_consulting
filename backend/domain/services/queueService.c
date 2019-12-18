//
// Created by enver on 17/12/19.
//

#include "../../routes/request.h"
#include "../models/response.h"
#include "../repositories/queueRepository.h"

struct Response queueAdd(struct Request request) {
    struct Response response;

    response.code = 200;
    sprintf(response.message, "%s", MESSAGE_SUCCESS);
    response.data.queueNode = enqueue(request.doctorEmail, request.patientEmail);;

    return response;
}

struct Response queueDelete(struct Request request) {
    struct Response response;

    if (dequeue(request.doctorEmail, request.patientEmail)) {
        response.code = CODE_ERROR_INTERNAL;
        sprintf(response.message, "%s", MESSAGE_ERROR);
    } else {
        response.code = CODE_SUCCESS;
        sprintf(response.message, "%s", MESSAGE_SUCCESS);
    }

    return response;
}

struct Response queueList(struct Request request) {
    struct Response response;
    struct Queue *queues = getQueueList(request.page, request.email);

    for(int i = 0; i < IPP_QUEUE; i++)
        response.data.queueList[i] = queues[i];

    free(queues);

    response.code = 200;
    sprintf(response.message, "%s", MESSAGE_SUCCESS);

    return response;
}