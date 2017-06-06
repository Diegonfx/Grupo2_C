/**
 * Declaration of a ticket.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#ifndef GRUPO2_C_TICKET_H
#define GRUPO2_C_TICKET_H

#include "LineTicket.h"

typedef struct ticket Ticket;

struct ticket{
    char* id;
    float toPay;
    LineTicket** linesOnTicket;
    int amountOfLinesOnTicket;

};

Ticket* newTicket(char* id , float toPay, int amountOfLinesOnTicket);
void printTicket(Ticket* ticket1);
void destroyTicket1(Ticket* ticket1);


#endif //GRUPO2_C_TICKET_H