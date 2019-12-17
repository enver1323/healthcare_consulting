//
// Created by enver on 18/12/19.
//

#ifndef CHAT_MODEL_H
#define CHAT_MODEL_H

#define TABLE_CHAT "chats"
#define IPP_CHAT 4

struct Chat {
    int id;
    struct User user1;
    struct User user2;
};

#endif //BACKEND_CHATMODEL_H
