//
// Created by enver on 13/12/19.
//
#ifndef DOCTOR_MODEL_H
#define DOCTOR_MODEL_H

#define TABLE_DOCTOR "doctors"

#define IPP_DOCTOR 10

#pragma pack(1)

struct Doctor {
    int id;
    int hospital_id;
    char name[256];
    char email[256];
    char phone[256];
};

#pragma pack(0)

#endif
