//
// Created by enver on 17/12/19.
//

#ifndef QUEUE_REPOSITORY_H
#define QUEUE_REPOSITORY_H

#include <string.h>
#include "../../database/db_connector.h"
#include "../models/queueModel.h"

/** Function Declarations */
struct Queue enqueue(char *doctor, char *patient);

struct Queue *getQueueList(int page, char *email);

struct Queue *fillQueueModels(MYSQL_RES *result);

struct Queue fillQueueModel(char *doctor, char *patient, int order);

int dequeue(char *doctor, char *patient);

struct Queue enqueue(char *doctor, char *patient) {
    struct Queue queue;
    MYSQL *conn = estDBConnection();
    char query[1024];

    MYSQL_ROW row;

    sprintf(query, "SELECT MAX(`order`) FROM %s WHERE doctor_email = '%s';", TABLE_QUEUE, doctor);
    if (makeDBQuery(conn, query))
        sprintf(queue.error, "%s", getDBError(conn));

    MYSQL_RES *res = getDBResult(conn);
    row = mysql_fetch_row(res);
    int order = (row[0] == NULL) ? 1 : atoi(row[0]) + 1;
    mysql_free_result(res);

    sprintf(query, "INSERT INTO %s (`doctor_email`, `patient_email`, `order`) VALUES('%s','%s', '%d')", TABLE_QUEUE,
            doctor, patient, order);

    if (makeDBQuery(conn, query))
        sprintf(queue.error, "%s", getDBError(conn));

    closeDBConnection(conn);

    sprintf(queue.doctor_email, "%s", doctor);
    sprintf(queue.patient_email, "%s", patient);
    queue.order = order;

    return queue;
}

int dequeue(char *doctor, char *patient) {
    MYSQL *conn = estDBConnection();
    char query[1024];

    sprintf(query, "DELETE FROM %s WHERE doctor_email = '%s' AND patient_email = '%s'", TABLE_QUEUE, doctor, patient);

    if (makeDBQuery(conn, query)) {
        closeDBConnection(conn);
        return EXIT_FAILURE;
    }

    closeDBConnection(conn);

    return EXIT_SUCCESS;
}

struct Queue *getQueueList(int page, char *email) {
    char query[1024];
    int offset = page * IPP_QUEUE;
    struct Queue *queues;

    sprintf(query,
            "SELECT * FROM %s WHERE patient_email = '%s' OR doctor_email = '%s' ORDER BY `order` DESC LIMIT %d OFFSET %d",
            TABLE_QUEUE, email, email, IPP_QUEUE, offset);

    fprintf(stderr, "%s", query);

    MYSQL *conn = estDBConnection();

    makeDBQuery(conn, query);
    MYSQL_RES *result = getDBResult(conn);

    queues = fillQueueModels(result);

    closeDBConnection(conn);

    return queues;
}

struct Queue *fillQueueModels(MYSQL_RES *result) {
    struct Queue *queues = calloc(IPP_QUEUE, sizeof(struct Queue));
    int counter = 0;
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)) != NULL)
        queues[counter++] = fillQueueModel(row[0], row[1], atoi(row[2]));

    mysql_free_result(result);

    return queues;
}

struct Queue fillQueueModel(char *doctor, char *patient, int order) {
    struct Queue queue;

    queue.order = order;
    sprintf(queue.doctor_email, "%s", doctor);
    sprintf(queue.patient_email, "%s", patient);

    return queue;
}


#endif //BACKEND_QUEUEREPOSITORY_H