//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_SUPPLIER_H
#define GRUPO2_C_SUPPLIER_H

#include "Item.h"
#include "Manufacturer.h"

typedef struct supplier Supplier ;

struct supplier {
    char* name;
    char* description;
    char* address;
    char* city;
    char* phone;
    char* website;
};

Supplier* newSupplier(char* name, char* description, char* address, char* citychar, char* phone, char* website);
Item* supplyItems(int amount , Manufacturer* manufacturer1 , Business* system1);
void annihilateSupplier(Supplier* supplier1);

#endif //GRUPO2_C_SUPPLIER_H
