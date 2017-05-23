//
// Created by Diego Mancini on 22/5/17.
//

#ifndef GRUPO2_C_SYSTEM_H
#define GRUPO2_C_SYSTEM_H

#include "Manufacturer.h"
#include "Supplier.h"
#include "Catalogue.h"

typedef struct business Business;

struct business {
    Manufacturer** listManufacturers;
    Supplier** listSuppliers;
    Catalogue* catalogue;
};

Business* newBusiness(char* name , Catalogue* catalogue1);
void addManufacturer(Manufacturer* manufacturer1 , Business* system1);
void addSupplier(Supplier* supplier1, Business* system1);
void addItemToCatalogue(Item* manufacturer1 , Business* system1);
void askForSupplies(Supplier* supplier1 , Business* system1);
void freeBusiness(Business* system1);

#endif //GRUPO2_C_SYSTEM_H
