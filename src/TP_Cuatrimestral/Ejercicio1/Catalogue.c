//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Catalogue.h"

Catalogue* newCatalogue(char* id, char* name, int discount){

    Catalogue* result = malloc(sizeof(Catalogue));

    result->id = malloc(sizeof(char) * strlen(id));
    result->name = malloc(sizeof(char) * strlen(name));

    result->id = id;
    result->name = name;
    result->discount = discount;

    strcpy(result->id , id);
    strcpy(result->name , name);

    return result;
}

void annihilateCatalogue(Catalogue* catalogue1){
    free(catalogue1->name);
    free(catalogue1->id);
    free(catalogue1);
}