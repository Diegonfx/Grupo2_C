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
    int maxAmountOfLines;
};

Sales* newSales(char* code, time_t date, int discount);
void salesGrow(Sales* sales1);
void addItemToSale(LineSales* product, Sales* sales1, char* productType);
void removeItemFromSale(Sales* sales1, char* productName);
void destroySales(Sales* sales1);

#endif //GRUPO2_C_SALES_H
