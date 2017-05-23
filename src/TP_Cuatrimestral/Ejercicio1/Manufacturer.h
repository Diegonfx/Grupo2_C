//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_MANUFACTURER_H
#define GRUPO2_C_MANUFACTURER_H

#include "Item.h"
#include "Business.h"

typedef struct manufacturer Manufacturer;

struct manufacturer {
    char* name;
    char* description;
    char* address;
    char* city;
    char* phone;
    char* website;
    Item** listItems;
};

Manufacturer* newManufacturer(char* name, char* description, char* address, char* city , char* phone, char* website);
Item* produceItem(Business* system1);
void annihilateManufacturer(Manufacturer* manufacturer1);

#endif //GRUPO2_C_MANUFACTURER_H
