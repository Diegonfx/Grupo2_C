/**
 * Implementation of a label.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#include <stdlib.h>
#include <memory.h>
#include "Label.h"

Label* newLabel(char* id, char* name){

    Label* result = malloc(sizeof(Label));

    result->name = malloc(sizeof(char) * strlen(name)+1);
    result->id = malloc(sizeof(char) * strlen(id)+1);

    strcpy(result->name , name);
    strcpy(result->id , id);

    return result;
}

void destroyLabel(Label* label1){
    free(label1->name);
    free(label1->id);
    free(label1);
}