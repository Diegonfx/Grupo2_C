/**
 * Declaration of a manufacturer.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#ifndef GRUPO2_C_MANUFACTURER_H
#define GRUPO2_C_MANUFACTURER_H

#include "Item.h"

typedef struct manufacturer Manufacturer;

struct manufacturer {
    char* name;
    char* description;
    char* address;
    char* city;
    char* phone;
    char* website;
    Item** listItems;
    int amountOfItems;
    int maxCapacityOfItems;
};

Manufacturer* newManufacturer(char* name, char* description, char* address, char* city , char* phone, char* website);
void growListOfItem(Manufacturer* manufacturer1);
void produceItem(char* name, char* model, float price , Label* label1, Manufacturer* manufacturer1);
void emptyListOfItems(Manufacturer* manufacturer1);
void destroyManufacturer(Manufacturer* manufacturer1);

#endif //GRUPO2_C_MANUFACTURER_H