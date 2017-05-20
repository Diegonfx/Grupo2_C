//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_TICKET_H
#define GRUPO2_C_TICKET_H

typedef struct ticket Ticket;

struct ticket{
    char* id;
    float toPay;
};

Ticket* newTicket(char* id , float toPay);
void annihilateTicket(Ticket* ticket1);


#endif //GRUPO2_C_TICKET_H
