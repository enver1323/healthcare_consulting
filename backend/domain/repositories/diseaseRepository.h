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

struct Disease *getDiseaseList(int page, char *search);

struct Disease *getDiseaseList(int page, char *search) {
    char query[1024];
    int offset = page * IPP_DISEASE;
    struct Disease *diseases;

    sprintf(query, "SELECT * FROM %s WHERE name LIKE '%%%s%%' OR synonyms LIKE '%%%s%%' ORDER BY id DESC LIMIT %d OFFSET %d", TABLE_DISEASE, search,
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

    while ((row = mysql_fetch_row(result)) != NULL) {
        struct Disease disease;

        disease.id = atoi(row[0]);
        sprintf(disease.name, "%s", row[1]);
        disease.treats = atoi(row[2]);
        disease.palliates = atoi(row[3]);
        disease.total_edges = atoi(row[4]);
        sprintf(disease.synonyms, "%s", row[5]);
        if(row[6] != NULL && strlen(row[6]))
            disease.auroc = atof(row[6]);
        if(row[7] != NULL && strlen(row[7]))
            sprintf(disease.description, "%s", row[7]);

        diseases[counter++] = disease;
    }

    mysql_free_result(result);

    return diseases;
}

#endif
