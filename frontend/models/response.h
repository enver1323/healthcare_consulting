//
// Created by enver on 14/12/19.
//
#ifndef RESPONSE_H
#define RESPONSE_H

#include "modelList.h"

#define CODE_SUCCESS 200
#define CODE_ERROR_INTERNAL 500

#define MESSAGE_SUCCESS "success"
#define MESSAGE_ERROR "error"

/**
 * IPP - Items Per Page
 */
struct Data{
    union {
        struct Doctor doctorNode;
        struct Doctor doctorList[IPP_DOCTOR];
        struct Hospital hospitalNode;
        struct Hospital hospitalList[IPP_HOSPITAL];
        struct Disease diseaseList[IPP_DISEASE];
        struct Queue queueNode;
        struct Queue queueList[IPP_QUEUE];
        struct User userNode;
        struct Chat chatNode;
        struct Chat chatList[IPP_CHAT];
        struct Message messageNode;
        struct Message messageList[IPP_MESSAGE];
    };
};

struct Response {
    int code;
    char message[1024];
    struct Data data;
};

int sendall(int fd, void *buf, int n, int flags);

int sendall(int fd, void *buf, int n, int flags)
{
    int total = 0, temp;

    while (total < n)
    {
        temp = send(fd, buf + total, n - total, flags);
        if (temp == -1)
            break;
        total += temp;
    }

    return (temp == -1 ? -1 : total);
}

#endif