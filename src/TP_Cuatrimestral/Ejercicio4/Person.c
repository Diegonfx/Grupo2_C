//
// Created by Diego Mancini on 22/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "Person.h"

Client* newClient(char* name , char* surname , int id) {
    Client* client1 = malloc(sizeof(Client));

    client1->name = malloc(sizeof(char) * strlen(name) + 1);
    client1->surname = malloc(sizeof(char) * strlen(surname) + 1);

    client1->idNumber = id;
    client1->debt = 0;

    strcpy(client1->name , name);
    strcpy(client1->surname , surname);

    return client1;
}

void destroyClient(Client* client1) {
    free(client1->surname);
    free(client1->name);
    free(client1);
}


Receptionist* newReceptionist(char* name , char* surname , int idNumber , char* hotelName , int hotelCuit){
    Receptionist* receptionist = malloc(sizeof(Receptionist));

    receptionist->name = malloc(sizeof(char) * strlen(name) + 1);
    receptionist->surname = malloc(sizeof(char) * strlen(surname) + 1);
    receptionist->hotelName = malloc(sizeof(char) * strlen(hotelName) + 1);
    receptionist->clientsRegistered = malloc(sizeof(Client*) * 10) ;
    receptionist->roomsRegistered = malloc(sizeof(Room*) * 10);
    receptionist->ticketsIssued = malloc(sizeof(Ticket*) * 10);
    receptionist->reservationsRegistered = malloc(sizeof(Reservation*) * 10);

    receptionist->idNumber = idNumber;
    receptionist->hotelCUIT = hotelCuit;
    receptionist->amountOfClients = 0;
    receptionist->amountOfRooms = 0;
    receptionist->amountOfTicketsIssued = 0;
    receptionist->amountOfReservations = 0;

    strcpy(receptionist->name , name);
    strcpy(receptionist->hotelName , hotelName);
    strcpy(receptionist->surname , surname);

    return receptionist;
}

void destroyReceptionist(Receptionist* receptionist1){
    free(receptionist1->name);
    free(receptionist1->surname);
    for (int i = 0; i < receptionist1->amountOfTicketsIssued; ++i) {
        destroyTicket(receptionist1->ticketsIssued[i]);
    }
    free(receptionist1->ticketsIssued);
    for (int j = 0; j < receptionist1->amountOfRooms; ++j) {
        destroyRoom(receptionist1->roomsRegistered[j]);
    }
    free(receptionist1->roomsRegistered);
    for (int k = 0; k < receptionist1->amountOfClients; ++k) {
        destroyClient(receptionist1->clientsRegistered[k]);
    }
    free(receptionist1->clientsRegistered);
    for (int l = 0; l < receptionist1->amountOfReservations; ++l) {
        destroyReservation(receptionist1->reservationsRegistered[l]);
    }
    free(receptionist1->reservationsRegistered);
    free(receptionist1);
}

void addClient(Receptionist* receptionist1 , Client* client1){
    if(receptionist1->amountOfClients % 10 == 0) {
        realloc(receptionist1->clientsRegistered, sizeof(Client*) *10);
    }

    receptionist1->clientsRegistered[receptionist1->amountOfClients] = client1;
    receptionist1->amountOfClients++;

}

void addRoom(Receptionist* receptionist1 , Room* room1){
    if(receptionist1->amountOfRooms % 10 == 0) {
        realloc(receptionist1->roomsRegistered, sizeof(Room*) *10);
    }
        receptionist1->roomsRegistered[receptionist1->amountOfRooms] = room1;
        receptionist1->amountOfRooms++;

}

void addTicket(Receptionist* receptionist1 , Ticket* ticket1){
    if(receptionist1->amountOfTicketsIssued % 10 == 0) {
        realloc(receptionist1->ticketsIssued, sizeof(Ticket*) *10);
    }
    receptionist1->ticketsIssued[receptionist1->amountOfTicketsIssued] = ticket1;
    receptionist1->amountOfTicketsIssued++;
}

void addReservation(Receptionist* receptionist1 , Reservation* reservation1){
    if(receptionist1->amountOfReservations % 10 == 0) {
        realloc(receptionist1->reservationsRegistered, sizeof(Reservation*) *10);
    }
        receptionist1->reservationsRegistered[receptionist1->amountOfReservations] = reservation1;
        receptionist1->amountOfReservations++;

}

void registerClientToRoom(Receptionist* receptionist1 , Client* client1 , int price){
    Reservation* reservation1;
    for (int i = 0; i < receptionist1->amountOfRooms ; ++i) {
        if (receptionist1->roomsRegistered[i]->price == price) {
//            printf("\nRoom Info\n");
//            printf("Room number: %d |||| Price: $%d \n" , receptionist1->roomsRegistered[i]->roomNumber , receptionist1->roomsRegistered[i]->price);
            reservation1 = newReservation(receptionist1->amountOfClients , client1->surname , client1->idNumber , receptionist1->roomsRegistered[i]->roomNumber);
            client1->debt = receptionist1->roomsRegistered[i]->price;
            addClient(receptionist1 , client1);
            addReservation(receptionist1  , reservation1);
//            receptionist1->amountOfClients++;
            break;
        }
    }
}

void clientLeaves(Receptionist* receptionist1 , Client* client1){
    Ticket* ticket1;
    for (int i = 0; i < receptionist1->amountOfClients ; ++i) {
        if (receptionist1->clientsRegistered[i]->idNumber == client1->idNumber) {
//            receptionist1->clientsRegistered[i] = NULL;
            receptionist1->amountOfClients--;
            ticket1 = newTicket(receptionist1->amountOfTicketsIssued+1 , client1->name , client1->idNumber , client1->debt);
            client1->debt = 0;
            addTicket(receptionist1 , ticket1);
            break;
        }
    }
}

void printInfo(Receptionist* receptionist1){
    printf("My name is %s %s and I'm the receptionist." , receptionist1->name , receptionist1->surname );
    printf("\n---Clients Info---\n");
    if (receptionist1->amountOfClients == 0) {
        printf("NO CLIENTS");
    } else {
        for (int j = 0; j < receptionist1->amountOfClients; ++j) {
            printf("\nName: %s \n Surname: %s \n ID: %d \n", receptionist1->clientsRegistered[j]->name,
                   receptionist1->clientsRegistered[j]->surname, receptionist1->clientsRegistered[j]->idNumber);
        }
    }
    printf("\n---Reservations Info---\n");
    if (receptionist1->amountOfReservations == 0) {
        printf("NO RESERVATIONS");
    } else {
        for (int i = 0; i < receptionist1->amountOfReservations; ++i) {
            printf("\nRoom type: %d \n Client surname: %s \n Client ID: %d \n" , receptionist1->reservationsRegistered[i]->roomNumber, receptionist1->reservationsRegistered[i]->clientSurname , receptionist1->reservationsRegistered[i]->clientID);
        }
    }

    printf("\nTickets Info\n");
    if (receptionist1->amountOfTicketsIssued == 0) {
        printf("NO TICKETS\n \n");
    } else {
        printf("Hotel %s --> CUIT: %d \n", receptionist1->hotelName, receptionist1->hotelCUIT);
        for (int k = 0; k < receptionist1->amountOfTicketsIssued; ++k) {
            printf("\nTicket Number: %d \n ID NUMBER: %d \n Client name: %s \n PRICE: $%d \n",
                   receptionist1->ticketsIssued[k]->ticketNumber, receptionist1->ticketsIssued[k]->idNumber,
                   receptionist1->ticketsIssued[k]->clientName, receptionist1->ticketsIssued[k]->price);
        }
    }
    printf("\n---Room Info---\n");
    if (receptionist1->amountOfRooms == 0) {
        printf("NO ROOMS");
    } else {
        for (int i = 0; i < receptionist1->amountOfRooms; ++i) {
            printf("\nRoom type: %s \n Room Number: %d \n PRICE: $%d \n", receptionist1->roomsRegistered[i]->type,
                   receptionist1->roomsRegistered[i]->roomNumber, receptionist1->roomsRegistered[i]->price);
        }
    }

}

Client* getClient(Receptionist* receptionist1, int idn) {
    Client *client1;
    for (int i = 0; i < receptionist1->amountOfClients; ++i) {
        if (receptionist1->clientsRegistered[i]->idNumber == idn) {
            client1 = receptionist1->clientsRegistered[i];
        }
    }
    return client1;
}

Room* getRoom(Receptionist* receptionist1, int price){
    Room* room1;
    for (int i = 0; i < receptionist1->amountOfRooms; ++i) {
        if (receptionist1->roomsRegistered[i]->price == price) {
            room1 = receptionist1->roomsRegistered[i];
        }
    }
    return room1;
}

void loadDatabase(Receptionist* receptionist1) {

    Client* client1 = newClient("Valle" , "Mano" , 123);
    Client* client2 = newClient("Tincho" , "Lalo" , 456);
    Client* client3 = newClient("Marcos" , "Dele" , 789);

    Room* room1 = newRoom(1 , "Regular" , 50);
    Room* room2 = newRoom(2 , "Deluxe" , 80);
    Room* room3 = newRoom(3 , "Suite" , 100);
    Room* room4 = newRoom(4 , "Poor" , 5);
    Room* room5 = newRoom(5 , "No-Bed-No-Bathroom-Just-Floor-Not-Even-Light" , 1);
    Room* room6 = newRoom(6 , "Presidential" , 350);

    addRoom(receptionist1 , room1);
    addRoom(receptionist1 , room2);
    addRoom(receptionist1 , room3);
    addRoom(receptionist1 , room4);
    addRoom(receptionist1 , room5);
    addRoom(receptionist1 , room6);

    registerClientToRoom(receptionist1 , client1 , room1->price);
    registerClientToRoom(receptionist1 , client2 , room2->price);
    registerClientToRoom(receptionist1 , client3 , room3->price);

}
