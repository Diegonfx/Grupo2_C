//
// Created by Diego Mancini on 22/5/17.
//

#ifndef GRUPO2_C_SYSTEM_H
#define GRUPO2_C_SYSTEM_H

#include "Person.h"
#include "Room.h"
#include "Ticket.h"
#include "Reservation.h"

typedef struct hotel Hotel;

struct hotel {
    char* name;
    Receptionist* receptionist;
    Client** clientsRegistered;
    Room** roomsRegistered;
    Ticket** ticketsIssued;
    int amountOfClients;
    int amountOfRooms;
    int amountOfTicketsIssued;
};

Hotel* newHotel(char* name , Receptionist* receptionist1);
Reservation* rentRoom(Client* client1 , Hotel* hotel1);
void destroyHotel(Hotel* hotel1);

#endif //GRUPO2_C_SYSTEM_H
