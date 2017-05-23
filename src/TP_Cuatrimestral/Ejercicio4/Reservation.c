//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Reservation.h"

Reservation* newReservation(char* clientNumber , char* clientSurname, int clientID , int roomNumber) {
    Reservation* reservation = malloc(sizeof(Reservation));

    reservation->clientNumber = malloc(sizeof(char) * strlen(clientNumber));
    reservation->clientSurname = malloc(sizeof(char) * strlen(clientSurname));

    reservation->clientNumber = clientNumber;
    reservation->clientSurname = clientSurname;
    reservation->clientID = clientID;
    reservation->roomNumber = roomNumber;

    strcpy(reservation->clientNumber , clientNumber);
    strcpy(reservation->clientSurname , clientSurname);

    return reservation;
}

void destroyReservation(Reservation* reservation1) {
    free(reservation1->clientNumber);
    free(reservation1->clientSurname);
    free(reservation1);
}