//
// Created by user on 14/12/19.
//
#ifndef USER_MODEL_H
#define USER_MODEL_H

#define TABLE_USER "users"
#define IPP_USER 10

struct User {
    int id;
    char name[256];
    char type[256];
    char email[256];
    char password[256];
    char error[256];
};

#endif