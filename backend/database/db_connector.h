//
// Created by enver on 12/12/19.
//
#ifndef DB_CONNECTOR_H
#define DB_CONNECTOR_H

#include <mysql/mysql.h>
#include <stdio.h>

#define DB_USER "os"
#define DB_SERVER "localhost"
#define DB_DATABASE "hcs"
#define DB_PASSWORD "cderfv34"

/** Function declarations */
MYSQL *estDBConnection();

void closeDBConnection();

int makeDBQuery(MYSQL *conn, char *query);

const char *getDBError(MYSQL *conn);

MYSQL_RES *getDBResult(MYSQL *conn);

MYSQL *estDBConnection() {
    MYSQL *conn;
    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, DB_SERVER, DB_USER, DB_PASSWORD, DB_DATABASE, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    return conn;
}

int makeDBQuery(MYSQL *conn, char *query) {
    return mysql_query(conn, query);
}

const char *getDBError(MYSQL *conn) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    return mysql_error(conn);
}

MYSQL_RES *getDBResult(MYSQL *conn) {
    return mysql_use_result(conn);
}

void closeDBConnection(MYSQL *conn) {
    mysql_close(conn);
}

#endif


/**
 * DB Example
 */
/*int init_db() {
    MYSQL_ROW row;

    *//* Connect to database *//*
    MYSQL *conn = estDBConnection();

    *//* send SQL query *//*
    MYSQL_RES *res = makeDBQuery(conn, "SHOW TABLES");

    *//* output table name *//*
    printf("MySQL Tables in mysql database:\n");
    while ((row = mysql_fetch_row(res)) != NULL)
        printf("%s \n", row[0]);

    *//* close connection *//*
    mysql_free_result(res);

    closeDBConnection();

    return 0;
}*/