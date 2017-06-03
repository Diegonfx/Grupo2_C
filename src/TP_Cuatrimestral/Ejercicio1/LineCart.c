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

    res->id = malloc(sizeof(char) * strlen(id)+1);
    res->item= malloc(sizeof(Item));

    res->id = id;
    res->item = item;
    res->units = units;

    strcpy(res->id , id);

    return res;

}

/**
 * prints the line cart.
 * @param lineCart1 to be printed.
 */
void generateLineCart(LineCart* lineCart1){
    printf("Item: %s, amount: %d, unitary price: %.2f" ,lineCart1->item->name, lineCart1->units, lineCart1->item->price);
}

void destroyLineCart(LineCart* lineCart1){
    free(lineCart1->id);
    destroyItem(lineCart1->item);
    free(lineCart1);
}