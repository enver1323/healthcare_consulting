//
// Created by enver on 13/12/19.
//
#ifndef HOSPITAL_MODEL_H
#define HOSPITAL_MODEL_H

#define IPP_HOSPITAL 10
#define TABLE_HOSPITAL "hospitals"

struct Hospital {
    int id;
    char name[256];
    char address[1024];

    struct Doctor doctorList[IPP_DOCTOR];
};

#endif