/**
 * Implementation of a line inside a sale.
 * @authors Tomas Iturralde, Diego Mancini
 */

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "LineSales.h"

LineSales* newLineSalesCamera(char* code, Camera* camera1, int units){

    LineSales* lineSales1 = malloc(sizeof(LineSales));

    lineSales1->code = malloc(sizeof(char) * strlen(code)+1);
    lineSales1->camera1 = malloc(sizeof(Camera));

    lineSales1->code = code;
    lineSales1->camera1 = camera1;
    lineSales1->units = units;

    strcpy(lineSales1->code , code);

    return lineSales1;
}

LineSales* newLineSalesAccessory(char* code, Accessory* accessory1, int units){

    LineSales* lineSales1 = malloc(sizeof(LineSales));

    lineSales1->code = malloc(sizeof(char) * strlen(code)+1);
    lineSales1->accessory1 = malloc(sizeof(Accessory));

    lineSales1->code = code;
    lineSales1->accessory1 = accessory1;
    lineSales1->units = units;

    strcpy(lineSales1->code , code);

    return lineSales1;
}

void generateLineSalesCamera(LineSales* lineSales1){
    printf("Item: %s, amount: %d, unitary price: %d" ,lineSales1->camera1->name, lineSales1->units, lineSales1->camera1->price);
}

void generateLineSalesAccessory(LineSales* lineSales1){
    printf("Item: %s, amount: %d, unitary price: %d" ,lineSales1->accessory1->name, lineSales1->units, lineSales1->accessory1->price);
}

void destroyLineSales(LineSales* lineSales1){
    free(lineSales1->code);
    destroyAccessory(lineSales1->accessory1);
    destroyCamera(lineSales1->camera1);
    free(lineSales1);
}