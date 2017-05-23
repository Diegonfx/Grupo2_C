//
// Created by Diego Mancini on 22/5/17.
//

#ifndef GRUPO2_C_PERSON_H
#define GRUPO2_C_PERSON_H

//CLIENT

typedef struct client Client;

struct client {
    char* name;
    char* surname;
    int idNumber;
};

Client* newClient(char* name , char* surname , int id);
void destroyClient(Client* client1);

// RECEPTIONIST

typedef struct receptionist Receptionist;

struct receptionist {
    char* name;
    char* surname;
    int idNumber;
};

Receptionist* newReceptionist(char* name , char* surname , int idNumber);
void destroyReceptionist(Receptionist* receptionist1);

#endif //GRUPO2_C_PERSON_H
