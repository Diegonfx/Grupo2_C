//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_CLIENT_H
#define GRUPO2_C_CLIENT_H

#include "IDcard.h"
#include "Movie.h"

typedef struct client Client;

struct client {
    char* name;
    char* surname;
    int dni;
    IDcard* iDcard;
    Movie** moviesRented;
    int amountOfMoviesRented;
};

Client* newClient(char* name , char* surname , int id , IDcard* iDcard1);
void destroyClient(Client* client1);

#endif //GRUPO2_C_CLIENT_H
