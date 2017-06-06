//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_TICKET_H
#define GRUPO2_C_TICKET_H

typedef struct ticket Ticket;

struct ticket {
    int ticketNumber;
    int hotelCUIT;
    char* hotelName;
    char* clientName;
    int idNumber;
    int price;
};

Ticket* newTicket(int ticketNumber,char* clientName , int idNumber , int price);
void destroyTicket(Ticket* ticket1);

#endif //GRUPO2_C_TICKET_H
