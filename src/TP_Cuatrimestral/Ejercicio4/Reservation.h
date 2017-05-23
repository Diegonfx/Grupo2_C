//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_RESERVATION_H
#define GRUPO2_C_RESERVATION_H

typedef struct reservation Reservation;

struct reservation {
    char* clientNumber;
    char* clientSurname;
    int clientID;
    int roomNumber;
};

Reservation* newReservation(char* clientNumber , char* clientSurname, int clientID , int roomNumber);
void destroyReservation(Reservation* reservation1);

#endif //GRUPO2_C_RESERVATION_H
