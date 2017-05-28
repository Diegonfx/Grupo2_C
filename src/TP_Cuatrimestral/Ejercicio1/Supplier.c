//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Supplier.h"

Supplier* newSupplier(char* name, char* description, char* address, char* city, char* phone, char* website){

    Supplier* supplier = malloc(sizeof(Supplier));

    supplier->name = malloc(sizeof(char) * strlen(name));
    supplier->description  = malloc(sizeof(char) * strlen(description));
    supplier->address = malloc(sizeof(char) * strlen(address));
    supplier->city = malloc(sizeof(char) * strlen(city));
    supplier->phone = malloc(sizeof(char) * strlen(phone));
    supplier->website = malloc(sizeof(char) * strlen(website));

    supplier->name = name;
    supplier->description = description;
    supplier->address = address;
    supplier->city = city;
    supplier->phone = phone;
    supplier->website = website;

    strcpy(supplier->name , name);
    strcpy(supplier->description , description);
    strcpy(supplier->address , address);
    strcpy(supplier->city , city);
    strcpy(supplier->phone , phone);
    strcpy(supplier->website , website);

    return supplier;
}

//Item* supplyItems(int amount , Manufacturer* manufacturer1 , Business* system1){}

void annihilateSupplier(Supplier* supplier){

    free(supplier->name);
    free(supplier->description);
    free(supplier->address);
    free(supplier->city);
    free(supplier->phone);
    free(supplier->website);
    free(supplier);
}