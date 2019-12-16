//
// Created by user on 14/12/19.
//
#ifndef USER_MODEL_H
#define USER_MODEL_H

#define TABLE "users"
#define IPP_USER 10

#pragma pack(1)

struct User {
    int id;
    char name[256];
    char type[256];
    char email[256];
    char password[256];
    char error[256];
};

#pragma pack(0)

#endif