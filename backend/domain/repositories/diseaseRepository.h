//
// Created by enver on 16/12/19.
//

#ifndef DISEASE_REPOSITORY_H
#define DISEASE_REPOSITORY_H

#include <string.h>
#include "../../database/db_connector.h"
#include "../models/diseaseModel.h"

/** Function Declarations */
struct Disease *fillDiseaseModels(MYSQL_RES *result);

struct Disease
fillDiseaseModel(int id, char *name, int treats, int palliates, int total_edges, char *synonyms, float auroc,
                 char *description, char *specification);

struct Disease *getDiseaseList(int page, char *search);

struct Disease *getDiseaseList(int page, char *search) {
    char query[1024];
    int offset = page * IPP_DISEASE;
    struct Disease *diseases;

    sprintf(query,
            "SELECT * FROM %s INNER JOIN (SELECT * FROM %s INNER JOIN %s USING(email)) as docs ON( docs.specification = %s.specification) WHERE %s.name LIKE '%%%s%%' OR synonyms LIKE '%%%s%%' LIMIT %d OFFSET %d",
            TABLE_DISEASE, TABLE_DOCTOR, TABLE_USER, TABLE_DISEASE, TABLE_DISEASE, search, search, IPP_DISEASE, offset);

    MYSQL *conn = estDBConnection();

    makeDBQuery(conn, query);
    MYSQL_RES *result = getDBResult(conn);

    diseases = fillDiseaseModels(result);

    closeDBConnection(conn);

    return diseases;
}

struct Disease *fillDiseaseModels(MYSQL_RES *result) {
    struct Disease *diseases = calloc(IPP_DISEASE, sizeof(struct Disease));
    int counter = 0;
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)) != NULL){
        struct Disease disease = fillDiseaseModel(atoi(row[0]), row[1], atoi(row[2]),
                                                  atoi(row[3]), atoi(row[4]), row[5],
                                                  row[6] != NULL && strlen(row[6]) ? atof(row[6]) : 0.0,
                                                  row[7] != NULL && strlen(row[7]) ? row[7] : "", row[8]);


        disease.doctorNode = fillDoctorModel(row[9], atoi(row[10]), row[11], row[13], 0, row[8]);
        diseases[counter++] = disease;
    }
    mysql_free_result(result);

    return diseases;
}

struct Disease
fillDiseaseModel(int id, char *name, int treats, int palliates, int total_edges, char *synonyms, float auroc,
                 char *description, char *specification) {
    struct Disease disease;

    disease.id = id;
    sprintf(disease.name, "%s", name);
    disease.treats = treats;
    disease.palliates = palliates;
    disease.total_edges = total_edges;
    sprintf(disease.synonyms, "%s", synonyms);
    disease.auroc = auroc;
    sprintf(disease.description, "%s", description);
    sprintf(disease.specification, "%s", specification);

    return disease;
}

#endif
