//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "LineSales.h"

LineSales* newLineSales(char* code, int amount){

    LineSales* lineSales1 = malloc(sizeof(LineSales));

    lineSales1->code = malloc(sizeof(char) * strlen(code));

    lineSales1->code = code;
    lineSales1->amount = amount;

    strcpy(lineSales1->code , code);

    return lineSales1;
}

void annihilateLineSales(LineSales* lineSales1){
    free(lineSales1->code);
    free(lineSales1);
}