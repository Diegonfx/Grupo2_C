/**
 * Declaration of a lineCart.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#ifndef GRUPO2_C_LINECART_H
#define GRUPO2_C_LINECART_H

#include "Item.h"

typedef struct lineCart LineCart;

struct lineCart {
    char* id;
    int units;
    Item* item;
};

LineCart* newLineCart(char* id, Item* item, int units);
void generateLineCart(LineCart* lineCart1);
void destroyLineCart(LineCart* lineCart1);

#endif //GRUPO2_C_LINECART_H