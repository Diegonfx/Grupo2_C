//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "LineCart.h"

LineCart* newLineCart(char* id, char* item, int units){

    LineCart* res = malloc(sizeof(LineCart));

    res->id = malloc(sizeof(char) * strlen(id));
    res->item= malloc(sizeof(char) * strlen(item));

    res->id = id;
    res->item = item;
    res->units = units;

    strcpy(res->id , id);
    strcpy(res->item , item);

    return res;

}
void annihilateLineCart(LineCart* lineCart1){
    free(lineCart1->id);
    free(lineCart1->item);
    free(lineCart1);
}