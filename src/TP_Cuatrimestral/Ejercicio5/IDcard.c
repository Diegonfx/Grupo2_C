//
// Created by Diego Mancini on 2/6/17.
//

#include <stdlib.h>
#include "IDcard.h"

IDcard* newIDcard(int id) {
    IDcard* iDcard1 = malloc(sizeof(IDcard));

    iDcard1->id = id;

    return iDcard1;
}

void destroyIDcard(IDcard* iDcard) {
    free(iDcard);
}
