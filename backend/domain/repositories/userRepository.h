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

    sprintf(query, "INSERT INTO %s (name, email, password) VALUES('%s','%s',MD5(%s))", TABLE, name,
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

    sprintf(query, "SELECT * FROM %s WHERE email = '%s' AND password = MD5(%s)", TABLE, email, password);
    MYSQL_RES *result = getDBResult(conn);

    if (makeDBQuery(conn, query))
        sprintf(user.error, "%s", getDBError(conn));

    fprintf(stderr, "%s", query);

    user = fillModel(result)[0];

    closeDBConnection(conn);

    return user;
}

struct User *fillModel(MYSQL_RES *result) {
    struct User temp;
    struct User *users = malloc(sizeof(struct User) * IPP_USER);
    int counter = 0;
    MYSQL_ROW row;
    MYSQL_FIELD *field;

    for (int i = 0; (field = mysql_fetch_field(result)); i++) {
        char *fieldName = field->name;

        if (strcmp("id", fieldName) == 0)
            temp.id = i;

        if (strcmp("name", fieldName) == 0)
            sprintf(temp.name, "%d", i);

        if (strcmp("type", fieldName) == 0)
            sprintf(temp.type, "%d", i);

        if (strcmp("email", fieldName) == 0)
            sprintf(temp.email, "%d", i);

        if (strcmp("password", fieldName) == 0)
            sprintf(temp.password, "%d", i);
    }

    while ((row = mysql_fetch_row(result)) != NULL) {
        struct User user;

        user.id = atoi(row[temp.id]);
        sprintf(user.name, "%s", row[getIntegerFromASCII(temp.name[0])]);
        sprintf(user.type, "%s", row[getIntegerFromASCII(temp.type[0])]);
        sprintf(user.email, "%s", row[getIntegerFromASCII(temp.email[0])]);
        sprintf(user.password, "%s", row[getIntegerFromASCII(temp.password[0])]);

        users[counter++] = user;
    }

    mysql_free_result(result);

    return users;
}

int getIntegerFromASCII(char number) {
    return ((int) number) - 48;
}

#endif