//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Excedent.h"

Excedent* newExcedent(char* moviesUnreturned , int debt , int moneyPaid , char* mostActiveClients){
    Excedent* excedent1 = malloc(sizeof(Excedent));

    excedent1->moviesUnreturned = malloc(sizeof(char) * strlen(moviesUnreturned) + 1);
    excedent1->mostActiveClients = malloc(sizeof(char) * strlen(mostActiveClients) + 13);

    excedent1->debt = debt;
    excedent1->moneyPaid = moneyPaid;

    strcpy(excedent1->moviesUnreturned , moviesUnreturned);
    strcpy(excedent1->mostActiveClients , mostActiveClients);

    return excedent1;
}

void destroyExcedent(Excedent* excedent1) {
    free(excedent1->moviesUnreturned);
    free(excedent1->mostActiveClients);
    free(excedent1);
}