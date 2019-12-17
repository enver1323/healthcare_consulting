//
// Created by enver on 16/12/19.
//

#include "../../routes/request.h"
#include "../models/response.h"
#include "../repositories/hospitalRepository.h"

struct Response hospitalList(struct Request request) {
    struct Response response;

    struct Hospital *hospitals = getHospitalList(request.page, request.search);

    printf("\nPAGE: %d\n", request.page);
    for (int i = 0; i < IPP_DOCTOR; i++){
        response.data.hospitalList[i] = hospitals[i];
        printf("ID: %d, name: %s\n", response.data.hospitalList[i].id, response.data.hospitalList[i].name);
    }

    free(hospitals);

    response.code = 200;
    sprintf(response.message, "%s", MESSAGE_SUCCESS);

    return response;
}

struct Response hospitalNode(struct Request request) {
    struct Response response;
    struct Hospital hospital = getHospital(request.id);
    struct Doctor *doctors = getDoctorList(request.page, hospital.id, "");

    for (int i = 0; i < IPP_DOCTOR; i++)
        hospital.doctorList[i] = doctors[i];

    response.code = 200;
    sprintf(response.message, "%s", MESSAGE_SUCCESS);
    response.data.hospitalNode = hospital;

    return response;
}