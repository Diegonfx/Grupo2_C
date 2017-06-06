/**
 * Declaration of a catalogue.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#ifndef GRUPO2_C_CATALOGUE_H
#define GRUPO2_C_CATALOGUE_H

#include "Item.h"

typedef struct catalogue Catalogue;

struct catalogue {
    char* id;
    char* name;
    int discount;
    Item** listItems;
    int amountOfItems;
    int maxCapacityOfItems;
};

Catalogue* newCatalogue(char* id, char* name);
void growListOfItems(Catalogue* catalogue1);
void destroyCatalogue(Catalogue* catalogue1);

#endif //GRUPO2_C_CATALOGUE_H