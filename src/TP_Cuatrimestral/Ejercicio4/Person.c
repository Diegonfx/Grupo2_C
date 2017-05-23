//
// Created by Diego Mancini on 22/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Person.h"

Client* newClient(char* name , char* surname , int id) {
    Client* client1 = malloc(sizeof(Client));

    client1->name = malloc(sizeof(char) * strlen(name));
    client1->surname = malloc(sizeof(char) * strlen(surname));

    client1->name = name;
    client1->surname = surname;
    client1->idNumber = id;

    strcpy(client1->name , name);
    strcpy(client1->surname , surname);

    return client1;
}

void destroyClient(Client* client1) {
    free(client1->surname);
    free(client1->name);
    free(client1);
}


Receptionist* newReceptionist(char* name , char* surname , int idNumber){
    Receptionist* receptionist = malloc(sizeof(Client));

    receptionist->name = malloc(sizeof(char) * strlen(name));
    receptionist->surname = malloc(sizeof(char) * strlen(surname));

    receptionist->name = name;
    receptionist->surname = surname;
    receptionist->idNumber = idNumber;

    strcpy(receptionist->name , name);
    strcpy(receptionist->surname , surname);

    return receptionist;
}

void destroyReceptionist(Receptionist* receptionist1){
    free(receptionist1->surname);
    free(receptionist1->name);
    free(receptionist1);
}
