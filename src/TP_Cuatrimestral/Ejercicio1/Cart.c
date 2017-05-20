//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Cart.h"

Cart* newCart(char* id, float units){

    Cart* result = malloc(sizeof(Cart));

    result->id = malloc(sizeof(char) * strlen(id));

    result->id = id;
    result->total = units;

    strcpy(result->id , id);

    return result;
}

void annihilateCart(Cart* cart1){
    free(cart1->id);
    free(cart1);
}
