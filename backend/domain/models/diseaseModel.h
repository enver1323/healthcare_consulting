//
// Created by enver on 13/12/19.
//
#ifndef DISEASE_MODEL_H
#define DISEASE_MODEL_H

#define TABLE_DISEASE "diseases"

#define IPP_DISEASE 4

struct Disease {
    int id;
    char name[256];
    int treats;
    int palliates;
    int total_edges;
    char synonyms[1024];
    float auroc;
    char description[1024];
    char specification[256];

    struct Doctor doctorNode;
};

#endif