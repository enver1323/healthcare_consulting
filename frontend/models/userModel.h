//
// Created by user on 14/12/19.
//
#ifndef USER_MODEL_H
#define USER_MODEL_H

#define TABLE_USER "users"
#define IPP_USER 4

struct User {
    char name[256];
    char email[256];
    char password[256];
    char error[256];
};

#endif