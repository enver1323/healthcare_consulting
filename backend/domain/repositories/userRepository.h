//
// Created by enver on 14/12/19.
//
#ifndef USER_REPOSITORY_H
#define USER_REPOSITORY_H

#include <string.h>
#include "../../database/db_connector.h"

/** Function Declarations */
int getIntegerFromASCII(char number);

struct User loginUser(char *email, char *password);

struct User *fillModel(MYSQL_RES *result);


struct User createUser(char *name, char *email, char *password) {
    struct User user;
    MYSQL *conn = estDBConnection();
    char query[1024];

    sprintf(query, "INSERT INTO %s (name, email, password) VALUES('%s','%s',MD5('%s'))", TABLE, name,
            email, password);

    if (makeDBQuery(conn, query))
        sprintf(user.error, "%s", getDBError(conn));

    closeDBConnection(conn);

    sprintf(user.name, "%s", name);
    sprintf(user.email, "%s", email);

    return user;
}

struct User loginUser(char *email, char *password) {
    struct User user;

    MYSQL *conn = estDBConnection();
    char query[1024];

    sprintf(query, "SELECT * FROM %s WHERE email = '%s' AND password = MD5('%s')", TABLE, email, password);

    if (makeDBQuery(conn, query))
        sprintf(user.error, "%s", getDBError(conn));

    MYSQL_RES *result = getDBResult(conn);

    user = fillModel(result)[0];

    closeDBConnection(conn);

    return user;
}

struct User *fillModel(MYSQL_RES *result) {
    struct User temp;
    struct User *users = malloc(sizeof(struct User) * IPP_USER);
    int counter = 0;
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)) != NULL) {
        struct User user;

        sprintf(user.name, "%s", row[0]);
        sprintf(user.email, "%s", row[1]);
        sprintf(user.password, "%s", row[2]);

        users[counter++] = user;
    }

    mysql_free_result(result);

    return users;
}

int getIntegerFromASCII(char number) {
    return ((int) number) - 48;
}

#endif