//
// Created by enver on 18/12/19.
//

#include "../../routes/request.h"
#include "../models/response.h"
#include "../repositories/chatRepository.h"
#include "../repositories/messageRepository.h"

/** Function Declarations */
struct Response chatList(struct Client *client, struct Request request);

struct Response startChat(struct Client *client, struct Request request);

struct Response sendMessage(struct Client *client, struct Request request);

struct Response messageList(struct Request request);

struct Response chatList(struct Client *client, struct Request request) {
    struct Response response;

    struct Chat *chats = getChatList(request.page, client->userModel.email, "%%%%");

    for (int i = 0; i < IPP_CHAT; i++)
        response.data.chatList[i] = chats[i];

    free(chats);

    response.code = CODE_SUCCESS;
    sprintf(response.message, "%s", MESSAGE_SUCCESS);

    return response;
}

struct Response startChat(struct Client *client, struct Request request) {
    struct Response response;

    response.code = CODE_SUCCESS;
    response.data.chatNode = createChat(client->userModel.email, request.email);
    sprintf(response.message, "%s", MESSAGE_SUCCESS);

    return response;
}

struct Response messageList(struct Request request) {
    struct Response response;
    struct Message *messages;

    messages = getMessageList(request.page, request.id);

    for (int i = 0; i < IPP_MESSAGE; i++)
        response.data.messageList[i] = messages[i];

    free(messages);

    response.code = CODE_SUCCESS;
    sprintf(response.message, MESSAGE_SUCCESS);

    return response;
}

struct Response sendMessage(struct Client *client, struct Request request) {
    struct Response response;
    struct Client receiver;
    struct Message message;

    message = createMessage(request.id, client->userModel.email, request.email, request.text);
    receiver = getClientModelByEmail(message.receiverEmail);

    response.code = CODE_SUCCESS;
    sprintf(response.message, MESSAGE_SUCCESS);
    response.data.messageNode = message;

    if (receiver.socket)
        send(receiver.socket, &response, sizeof(response), 0);

    response.data.messageNode = fillMessageModel(0, client->userModel.email, request.email, request.text, 0);

    return response;
}