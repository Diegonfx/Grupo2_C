/**
 * Implementation of a ticket.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "Ticket.h"

Ticket* newTicket(char* id , float toPay, int amountOfLinesOnTicket){
    Ticket* ticket1 = malloc(sizeof(Ticket));

    ticket1->id = malloc(sizeof(char) * strlen(id));
    ticket1->id = id;
    strcpy(ticket1->id , id);
    ticket1->toPay = toPay;

    ticket1->amountOfLinesOnTicket = amountOfLinesOnTicket;
    ticket1->linesOnTicket = malloc(sizeof(LineTicket*) * amountOfLinesOnTicket);

    return ticket1;
}

void printTicket(Ticket* ticket1){
    printf("Ticket:  %s", ticket1->id);
    for (int i = 0; i < ticket1->amountOfLinesOnTicket; i++) {
        generateLineTicket(ticket1->linesOnTicket[i]);
        printf("-----------");
    }
    printf("Total to pay: %.2f", ticket1->toPay);
}

void destroyTicket1(Ticket* ticket){
    free(ticket->id);
    free(ticket->linesOnTicket);
    free(ticket);
}