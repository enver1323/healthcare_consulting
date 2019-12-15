//
// Created by enver on 13/12/19.
//

#define IPP_DOCTOR 10

#pragma pack(1)

struct Doctor {
    int id;
    char name[256];
    char description[1024];
};

#pragma pack(0)