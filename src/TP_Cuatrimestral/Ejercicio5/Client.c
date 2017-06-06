//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Client.h"
#include "Movie.h"

Client* newClient(char* name , char* surname , int id , IDcard* iDcard1) {
    Client* client1 = malloc(sizeof(Client));

    client1->name = malloc(sizeof(char) * strlen(name) + 1);
    client1->surname = malloc(sizeof(char) * strlen(surname) + 1);
    client1->iDcard = malloc(sizeof(IDcard));
    client1->moviesRented = malloc(sizeof(Movie*) * 5);

    client1->dni = id;
    client1->iDcard = iDcard1;
    client1->amountOfMoviesRented = 0;

    strcpy(client1->name , name);
    strcpy(client1->surname , surname);

    return client1;
}

void destroyClient(Client* client1) {
    free(client1->surname);
    free(client1->name);
    destroyIDcard(client1->iDcard);
    for (int i = 0; i < client1->amountOfMoviesRented; ++i) {
        free(client1->moviesRented[i]);
    }
    free(client1);
}
