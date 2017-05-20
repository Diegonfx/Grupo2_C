//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include <sys/time.h>
#include "Sales.h"

Sales* newSales(char* code, time_t date,  int pvpTotal , int discount){

    Sales* sales1 = malloc(sizeof(Sales));

    sales1->code = malloc(sizeof(char) * strlen(code));
    date = time(0);

    sales1->code = code;
    sales1->date = date;
    sales1->pvpTotal = pvpTotal;
    sales1->discount = discount;

    strcpy(sales1->code , code);

    return sales1;
}

void annihilateSales(Sales* sales1){
    free(sales1->code);
    free(sales1);
}