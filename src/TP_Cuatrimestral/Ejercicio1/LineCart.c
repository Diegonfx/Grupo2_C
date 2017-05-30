/**
 * Implementation of a lineCart.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "LineCart.h"

LineCart* newLineCart(char* id, Item* item, int units){

    LineCart* res = malloc(sizeof(LineCart));

    res->id = malloc(sizeof(char) * strlen(id));
    res->item= malloc(sizeof(Item));

    res->id = id;
    res->item = item;
    res->units = units;

    strcpy(res->id , id);

    return res;

}
void generateLineCart(LineCart* lineCart1){
    printf("Item: %s, amount: %d, unitary price: %.2f" ,lineCart1->item->name, lineCart1->units, lineCart1->item->price);
}

void destroyLineCart(LineCart* lineCart1){
    free(lineCart1->id);
    free(lineCart1->item);
    free(lineCart1);
}