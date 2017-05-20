//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "LineTicket.h"

LineTicket* newLineTicket(char* id, char* item, int units){

    LineTicket* res = malloc(sizeof(LineTicket));

    res->id = malloc(sizeof(char) * strlen(id));
    res->item= malloc(sizeof(char) * strlen(item));

    res->id = id;
    res->item = item;
    res->units = units;

    strcpy(res->id , id);
    strcpy(res->item , item);

    return res;

}

void annihilateLineTicket(LineTicket* lineTicket1){
    free(lineTicket1->id);
    free(lineTicket1->item);
    free(lineTicket1);
}