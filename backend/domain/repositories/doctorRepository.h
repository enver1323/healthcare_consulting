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

struct Doctor fillDoctorModel(char *email, int hospital_id, char *phone, char *name, int order, char *specification);

struct Doctor *getDoctorList(char *email, int page, int hospital, char *search);

struct Doctor *getDoctorList(char *email, int page, int hospital, char *search) {
    char query[1024];
    int offset = page * IPP_DOCTOR;
    struct Doctor *doctors;

    sprintf(query,
            "SELECT * FROM %s INNER JOIN %s USING (email) LEFT OUTER JOIN (SELECT doctor_email, `order` FROM %s WHERE patient_email = '%s') as queues ON(doctor_email = email) WHERE (name LIKE '%%%s%%' OR email LIKE '%%%s%%' OR hospital_id IN (SELECT id FROM %s WHERE %s.name LIKE '%%%s%%' OR %s.address LIKE '%%%s%%'))",
            TABLE_DOCTOR, TABLE_USER, TABLE_QUEUE, email, search, search, TABLE_HOSPITAL, TABLE_HOSPITAL, search,
            TABLE_HOSPITAL, search);

    if (hospital > 0)
        sprintf(query, "%s AND hospital_id = %d ", query, hospital);

    sprintf(query, "%s ORDER BY hospital_id DESC LIMIT %d OFFSET %d", query, IPP_DOCTOR, offset);

    MYSQL *conn = estDBConnection();

    makeDBQuery(conn, query);
    MYSQL_RES *result = getDBResult(conn);

    doctors = fillDoctorModels(result);

    closeDBConnection(conn);

    return doctors;
}

struct Doctor *fillDoctorModels(MYSQL_RES *result) {
    struct Doctor *doctors = calloc(IPP_DOCTOR, sizeof(struct Doctor));
    int counter = 0;
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)) != NULL)
        doctors[counter++] = fillDoctorModel(row[0], atoi(row[1]), row[2], row[3], row[6] == NULL ? 0 : atoi(row[6]), row[7]);

    mysql_free_result(result);

    return doctors;
}

struct Doctor fillDoctorModel(char *email, int hospital_id, char *phone, char *name, int order, char *specification) {
    struct Doctor doctor;

    doctor.order = order;
    doctor.hospital_id = hospital_id;
    sprintf(doctor.name, "%s", name);
    sprintf(doctor.email, "%s", email);
    sprintf(doctor.phone, "%s", phone);
    sprintf(doctor.specification, "%s", specification);

    return doctor;
}

#endif
