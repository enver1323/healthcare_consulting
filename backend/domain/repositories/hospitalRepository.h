//
// Created by enver on 16/12/19.
//

#ifndef HOSPITAL_REPOSITORY_H
#define HOSPITAL_REPOSITORY_H

#include <string.h>
#include "../../database/db_connector.h"
#include "../models/hospitalModel.h"

/** Function Declarations */
struct Hospital *fillHospitalModels(MYSQL_RES *result);

struct Hospital fillHospitalModel(int id, char *name, char *address);

struct Hospital *getHospitalList(int page, char *search);

struct Hospital *getHospitalList(int page, char *search) {
    char query[1024];
    int offset = page * IPP_HOSPITAL;
    struct Hospital *hospitals;

    sprintf(query,
            "SELECT * FROM %s WHERE (name LIKE '%%%s%%' OR address LIKE '%%%s%%') ORDER BY id DESC LIMIT %d OFFSET %d",
            TABLE_HOSPITAL, search, search, IPP_HOSPITAL, offset);

    MYSQL *conn = estDBConnection();

    makeDBQuery(conn, query);
    MYSQL_RES *result = getDBResult(conn);

    hospitals = fillHospitalModels(result);

    closeDBConnection(conn);

    return hospitals;
}

struct Hospital getHospital(int id) {
    char query[1024];
    struct Hospital *hospitals;
    struct Hospital hospital;

    sprintf(query, "SELECT * FROM %s WHERE id = %d", TABLE_HOSPITAL, id);

    MYSQL *conn = estDBConnection();

    makeDBQuery(conn, query);
    MYSQL_RES *result = getDBResult(conn);

    hospitals = fillHospitalModels(result);
    hospital = hospitals[0];

    free(hospitals);

    closeDBConnection(conn);

    return hospital;
}

struct Hospital *fillHospitalModels(MYSQL_RES *result) {
    struct Hospital *hospitals = malloc(sizeof(struct Hospital) * IPP_HOSPITAL);
    int counter = 0;
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)) != NULL)
        hospitals[counter++] = fillHospitalModel(atoi(row[0]), row[1], row[2]);

    for (; counter < IPP_DOCTOR;)
        hospitals[counter++] = fillHospitalModel(0, "", "");

    mysql_free_result(result);

    return hospitals;
}

struct Hospital fillHospitalModel(int id, char *name, char *address) {
    struct Hospital hospital;

    hospital.id = id;
    sprintf(hospital.name, "%s", name);
    sprintf(hospital.address, "%s", address);

    return hospital;
}

#endif
