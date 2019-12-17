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
                 char *description);

struct Disease *getDiseaseList(int page, char *search);

struct Disease *getDiseaseList(int page, char *search) {
    char query[1024];
    int offset = page * IPP_DISEASE;
    struct Disease *diseases;

    sprintf(query,
            "SELECT * FROM %s WHERE name LIKE '%%%s%%' OR synonyms LIKE '%%%s%%' ORDER BY id DESC LIMIT %d OFFSET %d",
            TABLE_DISEASE, search,
            search, IPP_DISEASE, offset);

    MYSQL *conn = estDBConnection();

    makeDBQuery(conn, query);
    MYSQL_RES *result = getDBResult(conn);

    diseases = fillDiseaseModels(result);

    closeDBConnection(conn);

    return diseases;
}

struct Disease *fillDiseaseModels(MYSQL_RES *result) {
    struct Disease *diseases = malloc(sizeof(struct Disease) * IPP_DISEASE);
    int counter = 0;
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)) != NULL)
        diseases[counter++] = fillDiseaseModel(atoi(row[0]), row[1], atoi(row[2]),
                                               atoi(row[3]), atoi(row[4]), row[5],
                                               row[6] != NULL && strlen(row[6]) ? atof(row[6]) : 0.0,
                                               row[7] != NULL && strlen(row[7]) ? row[7] : "");

    for (; counter < IPP_DOCTOR;)
        diseases[counter++] = fillDiseaseModel(0, "", 0, 0, 0, "", 0.0, "");

    mysql_free_result(result);

    return diseases;
}

struct Disease
fillDiseaseModel(int id, char *name, int treats, int palliates, int total_edges, char *synonyms, float auroc,
                 char *description) {
    struct Disease disease;

    disease.id = id;
    sprintf(disease.name, "%s", name);
    disease.treats = treats;
    disease.palliates = palliates;
    disease.total_edges = total_edges;
    sprintf(disease.synonyms, "%s", synonyms);
    disease.auroc = auroc;
    sprintf(disease.description, "%s", description);

    return disease;
}


#endif
