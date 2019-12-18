//
// Created by enver on 19/12/19.
//

#ifndef MESSAGE_MODEL_H
#define MESSAGE_MODEL_H

#define TABLE_MESSAGE "messages"
#define IPP_MESSAGE 4

struct Message{
    int chatId;
    char senderEmail[256];
    char receiverEmail[256];
    char text[256];
    int time;
};

#endif //BACKEND_MESSAGEMODEL_H
