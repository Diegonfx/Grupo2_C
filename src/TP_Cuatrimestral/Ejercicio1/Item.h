//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_ITEM_H
#define GRUPO2_C_ITEM_H

#include "Label.h"

typedef struct item Item;

struct item {
    char* name;
    char* model;
    float price;
    Label* label;
};

Item* newItem(char* name, char* model, float price , Label* label1);
void annihilateItem(Item* item1);

#endif //GRUPO2_C_ITEM_H
