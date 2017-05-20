//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Supplier.h"

Supplier* newSupplier(char* cif, char* name, char* phone, char* fax, char* responsible, char* address, char* town, char* city,char* country,char* postalCode){

    Supplier* registeredUser = malloc(sizeof(Supplier));

    registeredUser->cif  = malloc(sizeof(char) * strlen(cif));
    registeredUser->name = malloc(sizeof(char) * strlen(name));
    registeredUser->phone = malloc(sizeof(char) * strlen(phone));
    registeredUser->fax = malloc(sizeof(char) * strlen(fax));
    registeredUser->responsible = malloc(sizeof(char) * strlen(responsible));
    registeredUser->address = malloc(sizeof(char) * strlen(address));
    registeredUser->town = malloc(sizeof(char) * strlen(town));
    registeredUser->city = malloc(sizeof(char) * strlen(city));
    registeredUser->country = malloc(sizeof(char) * strlen(country));
    registeredUser->postalCode = malloc(sizeof(char) * strlen(postalCode));

    registeredUser->cif = cif;
    registeredUser->name = name;
    registeredUser->address = address;
    registeredUser->phone = phone;
    registeredUser->fax = fax;
    registeredUser->responsible = responsible;
    registeredUser->town = town;
    registeredUser->city = city;
    registeredUser->country = country;
    registeredUser->postalCode = postalCode;

    strcpy(registeredUser->cif , cif);
    strcpy(registeredUser->name , name);
    strcpy(registeredUser->address , address);
    strcpy(registeredUser->phone , phone);
    strcpy(registeredUser->fax , fax);
    strcpy(registeredUser->responsible , responsible);
    strcpy(registeredUser->town , town);
    strcpy(registeredUser->city , city);
    strcpy(registeredUser->country , country);
    strcpy(registeredUser->postalCode , postalCode);

    return registeredUser;
}

void annihilateSupplier(Supplier* supplier1){

    free(supplier1->cif);
    free(supplier1->name);
    free(supplier1->address);
    free(supplier1->phone);
    free(supplier1->fax);
    free(supplier1->responsible);
    free(supplier1->town);
    free(supplier1->city);
    free(supplier1->country);
    free(supplier1->postalCode);
    free(supplier1);
}