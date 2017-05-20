//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Producer.h"

Producer* newManufacturer(char* name , char* code){

    Producer* producer1 = malloc(sizeof(Producer));

    producer1->code = malloc(sizeof(char) * strlen(code));
    producer1->name = malloc(sizeof(char) * strlen(name));

    producer1->name = name;
    producer1->code = code;

    strcpy(producer1->name, name);
    strcpy(producer1->code,  code);

    return producer1;

}

void annihilateManufacturer(Producer* producer){
    free(producer->name);
    free(producer->code);
    free(producer);
}