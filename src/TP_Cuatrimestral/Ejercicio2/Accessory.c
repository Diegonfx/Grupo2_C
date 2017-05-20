//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Accessory.h"

Accessory* newAccessory(char* type , char* description){

    Accessory* result = malloc(sizeof(Accessory));

    result->type = malloc(sizeof(char) * strlen(type)+1);
    result->description = malloc(sizeof(char) * strlen(description)+1);

    result->type = type;
    result->description = description;

    strcpy(result->type , type);
    strcpy(result->description, description);

    return result;
}

void annihilateAccessory(Accessory* accessory){
    free(accessory->type);
    free(accessory->description);
    free(accessory);
}
