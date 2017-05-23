//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Item.h"

Item* newItem(char* name, char* model, float price , Label* label1){

    Item* result = malloc(sizeof(Item));

    result->name = malloc(sizeof(char) * strlen(name));
    result->model = malloc(sizeof(char) * strlen(model));
    result->label = malloc(sizeof(Label));

    result->name = name;
    result->model = model;
    result->price = price;
    result->label = label1;

    strcpy(result->name , name);
    strcpy(result->model , model);

    return result;
}

void annihilateItem(Item* item1){
    free(item1->name);
    free(item1->model);
    free(item1->label);
    free(item1);
}