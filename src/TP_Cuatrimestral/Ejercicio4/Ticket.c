//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Ticket.h"

Ticket* newTicket(int ticketNumber, char* clientName , int idNumber , int price) {
    Ticket* ticket1 = malloc(sizeof(Ticket));

    ticket1->hotelName = malloc(sizeof(char) * 20);
    ticket1->clientName = malloc(sizeof(char) * strlen(clientName));

    ticket1->ticketNumber = ticketNumber;
    ticket1->idNumber = idNumber;
    ticket1->price = price;

    strcpy(ticket1->clientName , clientName);

    return ticket1;
}

void destroyTicket(Ticket* ticket1){
    free(ticket1->hotelName);
    free(ticket1->clientName);
    free(ticket1);
}