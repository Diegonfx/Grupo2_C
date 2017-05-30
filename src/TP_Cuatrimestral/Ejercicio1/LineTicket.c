/**
 * Implementation of a lineTicket.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "LineTicket.h"

LineTicket* newLineTicket(char* id, Item* item, int units){

    LineTicket* res = malloc(sizeof(LineTicket));

    res->id = malloc(sizeof(char) * strlen(id));
    res->item= malloc(sizeof(Item));

    res->id = id;
    res->item = item;
    res->units = units;

    strcpy(res->id , id);

    return res;
}

void generateLineTicket(LineTicket* lineTicket1){
    printf("Item: %s, amount: %d, unitary price: %.2f" ,lineTicket1->item->name, lineTicket1->units, lineTicket1->item->price);
}

void destroyLineTicket(LineTicket* lineTicket1){
    free(lineTicket1->id);
    free(lineTicket1->item);
    free(lineTicket1);
}