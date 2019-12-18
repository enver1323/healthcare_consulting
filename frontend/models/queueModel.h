//
// Created by enver on 17/12/19.
//

#ifndef QUEUE_MODEL_H
#define QUEUE_MODEL_H

#define IPP_QUEUE 4

#define TABLE_QUEUE "queues"

struct Queue {
    int order;
    char doctor_email[256];
    char patient_email[256];
    char error[256];
};

#endif //BACKEND_QUEUEMODEL_H
