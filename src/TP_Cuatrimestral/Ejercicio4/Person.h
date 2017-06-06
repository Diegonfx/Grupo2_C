//
// Created by Diego Mancini on 22/5/17.
//

#ifndef GRUPO2_C_PERSON_H
#define GRUPO2_C_PERSON_H

//CLIENT

#include "Room.h"
#include "Ticket.h"
#include "Reservation.h"

typedef struct client Client;

struct client {
    char* name;
    char* surname;
    int idNumber;
    int debt;
};

Client* newClient(char* name , char* surname , int id);
void destroyClient(Client* client1);

// RECEPTIONIST

typedef struct receptionist Receptionist;

struct receptionist {
    char* name;
    char* surname;
    int idNumber;
    Client** clientsRegistered;
    Room** roomsRegistered;
    Reservation** reservationsRegistered;
    Ticket** ticketsIssued;
    int amountOfClients;
    int amountOfRooms;
    int amountOfTicketsIssued;
    int amountOfReservations;
    char* hotelName;
    int hotelCUIT;
};

Receptionist* newReceptionist(char* name , char* surname , int idNumber, char* hotelName, int hotelCuit);
void destroyReceptionist(Receptionist* receptionist1);
void addClient(Receptionist* receptionist1 , Client* client1);
void addRoom(Receptionist* receptionist1 , Room* room1);
void addTicket(Receptionist* receptionist1 , Ticket* ticket1);
void addReservation(Receptionist* receptionist1 , Reservation* reservation1);
void registerClientToRoom(Receptionist* receptionist1 , Client* client1 , int price);
void clientLeaves(Receptionist* receptionist1 , Client* client1);
void printInfo(Receptionist* receptionist1);
void loadDatabase(Receptionist* receptionist1);
Client* getClient(Receptionist* receptionist1, int idn);
Room* getRoom(Receptionist* receptionist1, int price);

#endif //GRUPO2_C_PERSON_H
