//
// Created by enver on 13/12/19.
//
#ifndef HOSPITAL_MODEL_H
#define HOSPITAL_MODEL_H

#define IPP_HOSPITAL 10
#define TABLE_HOSPITAL "hospitals"

#pragma pack(1)

struct Hospital {
    int id;
    char name[256];
    char address[1024];

    struct Doctor doctorList[IPP_DOCTOR];
};

#pragma pack(0)

#endif