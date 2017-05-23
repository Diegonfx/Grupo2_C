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
    double price;
};

Ticket* newTicket(int ticketNumber, int hotelCUIT , char* hotelName , char* clientName , int idNumber , double price);
void destroyTicket(Ticket* ticket1);

#endif //GRUPO2_C_TICKET_H
