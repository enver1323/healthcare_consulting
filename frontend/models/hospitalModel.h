//
// Created by enver on 13/12/19.
//

#define IPP_HOSPITAL 10

#pragma pack(1)

struct Hospital {
    int id;
    char name[256];
    char description[1024];
};

#pragma pack(0)