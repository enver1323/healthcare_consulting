//
// Created by enver on 18/12/19.
//

#include "../../routes/request.h"
#include "../models/response.h"
#include "../repositories/chatRepository.h"

/** Function Declarations */
struct Response chatList(struct Request request);

struct Response startChat(struct Request request);

struct Response chatList(struct Request request) {
    struct Response response;

    struct Chat *chats = getChatList(request.page, request.email, "%%%%");

    for (int i = 0; i < IPP_CHAT; i++)
        response.data.chatList[i] = chats[i];

    free(chats);

    response.code = 200;
    sprintf(response.message, "%s", MESSAGE_SUCCESS);

    return response;
}

struct Response startChat(struct Request request) {
    struct Response response;

    response.code = 200;
    response.data.chatNode = createChat(request.email, request.email);
    sprintf(response.message, "%s", MESSAGE_SUCCESS);

    return response;
}