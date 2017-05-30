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
};

Catalogue* newCatalogue(char* id, char* name, int discount);
void destroyCatalogue(Catalogue* catalogue1);

#endif //GRUPO2_C_CATALOGUE_H
