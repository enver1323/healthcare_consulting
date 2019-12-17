//
// Created by enver on 15/12/19.
//
#include "../../routes/request.h"
#include "../models/response.h"
#include "../repositories/doctorRepository.h"

struct Response doctorList(struct Request request) {
    struct Response response;

    struct Doctor *doctors = getDoctorList(request.page, request.hospital_id, request.search);

    for (int i = 0; i < IPP_DOCTOR; i++)
        response.data.doctorList[i] = doctors[i];

    free(doctors);

    response.code = 200;
    sprintf(response.message, "%s", MESSAGE_SUCCESS);

    return response;
}
