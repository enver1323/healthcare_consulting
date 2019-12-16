//
// Created by enver on 16/12/19.
//

#ifndef DOCTOR_REPOSITORY_H
#define DOCTOR_REPOSITORY_H

#include <string.h>
#include "../../database/db_connector.h"
#include "../models/doctorModel.h"

/** Function Declarations */
struct Doctor *fillDoctorModels(MYSQL_RES *result);

struct Doctor *getDoctorList(int page, int hospital, char *search);

struct Doctor *getDoctorList(int page, int hospital, char *search) {
    char query[1024];
    int offset = page * IPP_DOCTOR;
    struct Doctor *doctors;

    sprintf(query, "SELECT * FROM %s WHERE name LIKE '%%%s%%' OR email LIKE '%%%s%%'", TABLE_DOCTOR, search, search);

    if (hospital > 0)
        sprintf(query, "AND hospital_id = %d ", hospital);

    sprintf(query, "%s LIMIT %d OFFSET %d", query, IPP_DOCTOR, offset);

    MYSQL *conn = estDBConnection();

    makeDBQuery(conn, query);
    MYSQL_RES *result = getDBResult(conn);

    doctors = fillDoctorModels(result);

    closeDBConnection(conn);

    return doctors;
}

struct Doctor *fillDoctorModels(MYSQL_RES *result) {
    struct Doctor *doctors = malloc(sizeof(struct Doctor) * IPP_DOCTOR);
    int counter = 0;
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)) != NULL) {
        struct Doctor doctor;

        doctor.id = atoi(row[0]);
        doctor.hospital_id = atoi(row[1]);
        sprintf(doctor.name, "%s", row[2]);
        sprintf(doctor.email, "%s", row[3]);
        sprintf(doctor.phone, "%s", row[4]);

        doctors[counter++] = doctor;
    }

    mysql_free_result(result);

    return doctors;
}

#endif
