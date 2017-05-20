//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_MANUFACTURER_H
#define GRUPO2_C_MANUFACTURER_H

typedef struct manufacturer Manufacturer;

struct manufacturer {
    char* name;
    char* description;
    char* address;
    char* city;
    char* phone;
    char* website;
};

Manufacturer* newManufacturer(char* name, char* description, char* address, char* city , char* phone, char* website);
void annihilateManufacturer(Manufacturer* manufacturer1);

#endif //GRUPO2_C_MANUFACTURER_H
