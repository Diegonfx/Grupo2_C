//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "RegisteredUser.h"

RegisteredUser* newRegisteredUser(char* name, char* dni, char* address, char* phone, char* town , char* city, char* country, char* postalCode, char** role){

    RegisteredUser* registeredUser = malloc(sizeof(RegisteredUser));

    registeredUser->name = malloc(sizeof(char) * strlen(name));
    registeredUser->dni  = malloc(sizeof(char) * strlen(dni));
    registeredUser->address = malloc(sizeof(char) * strlen(address));
    registeredUser->phone = malloc(sizeof(char) * strlen(phone));
    registeredUser->town = malloc(sizeof(char) * strlen(town));
    registeredUser->city = malloc(sizeof(char) * strlen(city));
    registeredUser->country = malloc(sizeof(char) * strlen(country));
    registeredUser->postalCode = malloc(sizeof(char) * strlen(postalCode));
    registeredUser->role = malloc(sizeof(char*) * 2);

    registeredUser->name = name;
    registeredUser->dni = dni;
    registeredUser->address = address;
    registeredUser->phone = phone;
    registeredUser->town = town;
    registeredUser->city = city;
    registeredUser->country = country;
    registeredUser->postalCode = postalCode;
    registeredUser->role[0] = "Client";
    registeredUser->role[1] = "Administrator";

    strcpy(registeredUser->name , name);
    strcpy(registeredUser->dni , dni);
    strcpy(registeredUser->address , address);
    strcpy(registeredUser->phone , phone);
    strcpy(registeredUser->town , town);
    strcpy(registeredUser->city , city);
    strcpy(registeredUser->country , country);
    strcpy(registeredUser->postalCode , postalCode);

    return registeredUser;

}

void annihilateRegisteredUser(RegisteredUser* registeredUser1){

    free(registeredUser1->name);
    free(registeredUser1->address);
    free(registeredUser1->city);
    free(registeredUser1->country);
    free(registeredUser1->dni);
    free(registeredUser1->phone);
    free(registeredUser1->postalCode);
    free(registeredUser1->town);
    free(registeredUser1->role[0]);
    free(registeredUser1->role[1]);
    free(registeredUser1->role);
    free(registeredUser1);
}