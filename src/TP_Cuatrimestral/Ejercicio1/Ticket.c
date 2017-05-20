//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Ticket.h"

Ticket* newTicket(char* id , float toPay){

    Ticket* ticket1 = malloc(sizeof(Ticket));

    ticket1->id = malloc(sizeof(char) * strlen(id));

    ticket1->id = id;
    ticket1->toPay = toPay;

    strcpy(ticket1->id , id);

    return ticket1;
}

void annihilateTicket(Ticket* ticket1){
    free(ticket1->id);
    free(ticket1);
}