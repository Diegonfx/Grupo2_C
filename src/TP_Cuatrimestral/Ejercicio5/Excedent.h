//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_EXCEDENT_H
#define GRUPO2_C_EXCEDENT_H

typedef struct excedent Excedent;

struct excedent {
    char* moviesUnreturned;
    int debt;
    int moneyPaid;
    char* mostActiveClients;
};

Excedent* newExcedent(char* moviesUnreturned , int debt , int moneyPaid , char* mostActiveClients);
void destroyExcedent(Excedent* excedent1);

#endif //GRUPO2_C_EXCEDENT_H
