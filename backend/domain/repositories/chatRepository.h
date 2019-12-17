//
// Created by enver on 18/12/19.
//

#ifndef CHAT_REPOSITORY_H
#define CHAT_REPOSITORY_H

#include <string.h>
#include "../../database/db_connector.h"
#include "../models/chatModel.h"
#include "../models/userModel.h"

/** Function Declarations */
struct Chat *fillChatModels(MYSQL_RES *result);

struct Chat fillChatModel(int id, char *userEmail1, char *userEmail2, char *userName1, char *userName2);

struct Chat *getChatList(int page, char *email);

struct Chat *getChatList(int page, char *email) {
    char query[1024];
    int offset = page * IPP_CHAT;
    struct Chat *chats;

    sprintf(query,
            "SELECT * FROM %s INNER JOIN %s as u1 ON (user1 = u1.email) INNER JOIN %s as u2 ON (user2 = u2.email) WHERE user1 = '%s' OR user2 = '%s' LIMIT %d OFFSET %d",
            TABLE_CHAT, TABLE_USER, TABLE_USER, email,
            email, IPP_CHAT, offset);

    fprintf(stderr, "%s", query);

    MYSQL *conn = estDBConnection();

    makeDBQuery(conn, query);
    MYSQL_RES *result = getDBResult(conn);

    chats = fillChatModels(result);

    closeDBConnection(conn);

    return chats;
}

struct Chat startShat(char *user1, char *user2) {
    char query[1024];
    struct Chat chat;

    sprintf(query, "INSERT INTO %s (user1, user2) VALUES('%s', '%s')", TABLE_CHAT, user1, user2);

    fprintf(stderr, "%s\n", query);

    MYSQL *conn = estDBConnection();

    makeDBQuery(conn, query);

    sprintf(query, "INSERT INTO %s (user1, user2) VALUES('%s', '%s')", TABLE_CHAT, user1, user2);

    MYSQL_RES *result = getDBResult(conn);

//    chat = fillChatModels(result);

    closeDBConnection(conn);

    return chat;
}

struct Chat *fillChatModels(MYSQL_RES *result) {
    struct Chat *chats = malloc(sizeof(struct Chat) * IPP_CHAT);
    int counter = 0;
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)) != NULL)
        chats[counter++] = fillChatModel(atoi(row[0]), row[1], row[2], row[3], row[6]);

    for (; counter < IPP_CHAT;)
        chats[counter++] = fillChatModel(0, "", "", "", "");

    mysql_free_result(result);

    return chats;
}

struct Chat fillChatModel(int id, char *userEmail1, char *userEmail2, char *userName1, char *userName2) {
    struct Chat chat;

    chat.id = id;
    sprintf(chat.user1.email, "%s", userEmail1);
    sprintf(chat.user2.email, "%s", userEmail2);
    sprintf(chat.user1.name, "%s", userName1);
    sprintf(chat.user2.name, "%s", userName2);

    return chat;
}

#endif //BACKEND_CHATREPOSITORY_H
