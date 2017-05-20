//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_SALES_H
#define GRUPO2_C_SALES_H

#include <sys/_types/_time_t.h>

typedef struct sales Sales;

struct sales {
    char* code;
    time_t date;
    int pvpTotal;
    int discount;
};

Sales* newSales(char* code, time_t date,  int pvpTotal , int discount);
void annihilateSales(Sales* sales1);

#endif //GRUPO2_C_SALES_H
