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

struct Chat *getChatList(int page, char *user1, char *user2);

struct Chat createChat(char *user1, char *user2);

struct Chat *getChatList(int page, char *user1, char *user2) {
    char query[1024];
    int offset = page * IPP_CHAT;
    struct Chat *chats;

    sprintf(query,
            "SELECT * FROM %s INNER JOIN %s as u1 ON (user1 = u1.email) INNER JOIN %s as u2 ON (user2 = u2.email) WHERE (user1 LIKE '%s' OR user2 LIKE '%s') AND (user1 LIKE '%s' OR user2 LIKE '%s') LIMIT %d OFFSET %d",
            TABLE_CHAT, TABLE_USER, TABLE_USER, user1,
            user1, user2, user2, IPP_CHAT, offset);

    MYSQL *conn = estDBConnection();

    makeDBQuery(conn, query);
    MYSQL_RES *result = getDBResult(conn);

    chats = fillChatModels(result);

    closeDBConnection(conn);

    return chats;
}

struct Chat createChat(char *user1, char *user2) {
    char query[1024];
    struct Chat chat;

    MYSQL *conn = estDBConnection();

    sprintf(query, "INSERT INTO %s (user1, user2) VALUES('%s', '%s')", TABLE_CHAT, user1, user2);

    makeDBQuery(conn, query);

    chat = getChatList(0, user1, user2)[0];

    closeDBConnection(conn);

    return chat;
}

struct Chat *fillChatModels(MYSQL_RES *result) {
    struct Chat *chats = calloc(IPP_CHAT, sizeof(struct Chat));
    int counter = 0;
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)) != NULL)
        chats[counter++] = fillChatModel(atoi(row[0]), row[1], row[2], row[3], row[6]);

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
