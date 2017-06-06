/**
 * Declaration of a sale.
 * @authors Tomas Iturralde, Diego Mancini
 */

#ifndef GRUPO2_C_SALES_H
#define GRUPO2_C_SALES_H

#include "LineSales.h"

typedef struct sales Sales;

struct sales {
    char* code;
    time_t date;
    int totalPrice;
    int discount;
    LineSales** listOfLineSales;
    int amountOfLines;
};

Sales* newSales(char* code, time_t date, int discount, int amountOfLines);
void printSales(Sales* sales1);
void destroySales(Sales* sales1);

#endif //GRUPO2_C_SALES_H
