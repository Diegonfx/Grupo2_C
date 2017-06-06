//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_ADMINISTRATOR_H
#define GRUPO2_C_ADMINISTRATOR_H

#include "Client.h"
#include "Rental.h"
#include "Excedent.h"
#include "Movie.h"

typedef struct admin Administrator;

struct admin {
    char* name;
    char* surname;
    int idNumber;
    Client** clientsRegistered;
    int amountOfClients;
    Rental** rentalsRegistered;
    int amountOfRentals;
    Movie** moviesRegiestered;
    int amountOfMovies;
    Excedent* excedent1;
};

Administrator* newAdministrator(char* name , char* surname , int idNumber);
void destroyAdministrator(Administrator* administrator1);
void addClient(Administrator* administrator1 , Client* client1);
void addRental(Administrator* administrator , Rental* rental1);
void addMovie(Administrator* administrator1 , Movie* movie1);
void rentMovie(Administrator* administrator1 , Client* client1 , Movie* movie1);
void returnMovie(Administrator* administrator1 , Client* client1 , Movie* movie1);
void printInfo(Administrator* administrator1);
void loadSystem(Administrator* administrator1);
Client* getClient(Administrator* administrator1 , int idn);
Movie* getMovie(Administrator* administrator1 , int price);

#endif //GRUPO2_C_ADMINISTRATOR_H
