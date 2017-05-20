//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Manufacturer.h"
#include "../Ejercicio2/Producer.h"

Manufacturer* newManufacturer(char* name, char* description, char* address, char* city, char* phone, char* website){

    Manufacturer* manufacturer1 = malloc(sizeof(Manufacturer));

    manufacturer1->name = malloc(sizeof(char) * strlen(name));
    manufacturer1->description  = malloc(sizeof(char) * strlen(description));
    manufacturer1->address = malloc(sizeof(char) * strlen(address));
    manufacturer1->city = malloc(sizeof(char) * strlen(city));
    manufacturer1->phone = malloc(sizeof(char) * strlen(phone));
    manufacturer1->website = malloc(sizeof(char) * strlen(website));

    manufacturer1->name = name;
    manufacturer1->description = description;
    manufacturer1->address = address;
    manufacturer1->city = city;
    manufacturer1->phone = phone;
    manufacturer1->website = website;

    strcpy(manufacturer1->name , name);
    strcpy(manufacturer1->description , description);
    strcpy(manufacturer1->address , address);
    strcpy(manufacturer1->city , city);
    strcpy(manufacturer1->phone , phone);
    strcpy(manufacturer1->website , website);

    return manufacturer1;

}

void annihilateManufacturer(Manufacturer* manufacturer1){

    free(manufacturer1->name);
    free(manufacturer1->description);
    free(manufacturer1->address);
    free(manufacturer1->city);
    free(manufacturer1->phone);
    free(manufacturer1->website);
    free(manufacturer1);
}