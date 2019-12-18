//
// Created by enver on 19/12/19.
//

#ifndef MODEL_REPOSITORY_H
#define MODEL_REPOSITORY_H

#include <string.h>
#include <time.h>
#include "../../database/db_connector.h"
#include "../models/messageModel.h"

/** Function Declarations */
struct Message *fillMessageModels(MYSQL_RES *result);

struct Message fillMessageModel(int chatId, char *senderEmail, char *receiverEmail, char *text, int time);

struct Message *getMessageList(int page, int chatId);

struct Message createMessage(int chatId, char *sender, char *receiver, char *text);

struct Message *getMessageList(int page, int chatId) {
    char query[1024];
    int offset = page * IPP_MESSAGE;
    struct Message *messages;

    sprintf(query, "SELECT * FROM %s, WHERE chat_id = %d ORDER BY `time` DESC LIMIT %d OFFSET %d", TABLE_MESSAGE,
            chatId, IPP_MESSAGE, offset);

    MYSQL *conn = estDBConnection();

    makeDBQuery(conn, query);
    MYSQL_RES *result = getDBResult(conn);

    messages = fillMessageModels(result);

    closeDBConnection(conn);

    return messages;
}

struct Message createMessage(int chatId, char *sender, char *receiver, char *text) {
    char query[1024];

    MYSQL *conn = estDBConnection();

    sprintf(query,
            "INSERT INTO %s (chat_id, sender_email, receiver_email, text, time) VALUES('%d', '%s', '%s', '%s', '%ld')",
            TABLE_MESSAGE, chatId, sender, receiver, text, clock());

    fprintf(stderr, "%s\n", query);

    makeDBQuery(conn, query);

    closeDBConnection(conn);

    return fillMessageModel(chatId, sender, receiver, text);
}

struct Message *fillMessageModels(MYSQL_RES *result) {
    struct Message *messages = calloc(IPP_MESSAGE, sizeof(struct Message));
    int counter = 0;
    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)) != NULL)
        messages[counter++] = fillMessageModel(atoi(row[0]), row[1], row[2], row[3], atoi(row[4]));

    mysql_free_result(result);

    return messages;
}

struct Message fillMessageModel(int chatId, char *senderEmail, char *receiverEmail, char *text, int time) {
    struct Message message;

    message.time = time;
    message.chatId = chatId;
    sprintf(message.senderEmail, "%s", senderEmail);
    sprintf(message.receiverEmail, "%s", receiverEmail);
    sprintf(message.text, "%s", text);

    return message;
}


#endif //BACKEND_MODELREPOSITORY_H
