//
// Created by enver on 17/12/19.
//

#include "../../routes/request.h"
#include "../models/response.h"
#include "../repositories/diseaseRepository.h"

struct Response diseaseList(struct Request request) {
    struct Response response;

    struct Disease *diseases = getDiseaseList(request.page, request.search);

    for (int i = 0; i < IPP_DISEASE; i++)
        response.data.diseaseList[i] = diseases[i];

    free(diseases);

    response.code = 200;
    sprintf(response.message, "%s", MESSAGE_SUCCESS);

    return response;
}
