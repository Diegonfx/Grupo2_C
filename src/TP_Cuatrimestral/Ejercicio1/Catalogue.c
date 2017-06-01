/**
 * Implementation of a catalogue.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#include <stdlib.h>
#include <memory.h>
#include "Catalogue.h"

Catalogue* newCatalogue(char* id, char* name){

    Catalogue* result = malloc(sizeof(Catalogue));

    result->id = malloc(sizeof(char) * strlen(id));
    result->name = malloc(sizeof(char) * strlen(name));
    result->maxCapacityOfItems = 10;
    result->listItems = malloc(sizeof(Item) * result->maxCapacityOfItems);

    result->id = id;
    result->name = name;
    result->amountOfItems = 0;

    strcpy(result->id , id);
    strcpy(result->name , name);

    return result;
}

/**
 * Expands the capacity of items allowed in a catalogue.
 * @param catalogue1 whose items' list will be expanded.
 */
void growListOfItems(Catalogue* catalogue1){
    catalogue1->listItems = realloc(catalogue1->listItems, sizeof(Item*) * (catalogue1->maxCapacityOfItems*2));
    catalogue1->maxCapacityOfItems *= 2;
}

void destroyCatalogue(Catalogue* catalogue1){
    free(catalogue1->name);
    free(catalogue1->id);
    for (int i = 0; i < catalogue1->maxCapacityOfItems; ++i) {
        destroyItem(catalogue1->listItems[i]);
    }
    free(catalogue1->listItems);
    free(catalogue1);
}