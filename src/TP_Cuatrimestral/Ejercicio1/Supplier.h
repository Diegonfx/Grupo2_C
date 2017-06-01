/**
 * Declaration of a supplier.
 * @authors Tomas Iturralde, Diego Mancini.
 */

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
    Manufacturer** listOfManufacturers;
    int amountOfManufacturers;
    int maxAmountOfManufacturers;
};

Supplier* newSupplier(char* name, char* description, char* address, char* city, char* phone, char* website);
void growListOfManufacturers(Supplier* supplier1);
void addManufacturer(Manufacturer* manufacturer1 , Supplier* supplier1);
void removeManufacturer(Supplier* supplier1, char* manufacturerName);
void destroySupplier(Supplier* supplier1);

#endif //GRUPO2_C_SUPPLIER_H
