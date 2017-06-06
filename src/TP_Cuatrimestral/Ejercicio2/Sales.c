/**
 * Implementation of a sale.
 * @authors Tomas Iturralde, Diego Mancini
 */

#include <stdlib.h>
#include <memory.h>
#include <sys/time.h>
#include "Sales.h"

Sales* newSales(char* code, time_t date, int discount, int amountOfLines){

    Sales* sales1 = malloc(sizeof(Sales));

    sales1->code = malloc(sizeof(char) * strlen(code));
    sales1->listOfLineSales = malloc(sizeof(LineSales*) * sales1->amountOfLines);
    date = time(0);

    sales1->code = code;
    sales1->date = date;
    sales1->totalPrice = 0;
    sales1->discount = discount;
    sales1->amountOfLines = amountOfLines;

    strcpy(sales1->code , code);

    return sales1;
}

/**
 * Prints the sale.
 * @param sales1 to be printed.
 */
/*void printSales(Sales* sales1){
    printf("Sale:  %s", sales1->code);
    for (int i = 0; i < sales1->amountOfLines; i++) {
        if (sales1->listOfLineSales[i]){
            generateLineSalesAccessory(sales1->listOfLineSales[i]);
            printf("-----------");
        }
        else {
            generateLineSalesCamera(sales1->listOfLineSales[i]);
            printf("-----------");
        }
    }
    printf("Total to pay: %d", sales1->totalPrice);
}*/

void destroySales(Sales* sales1){
    free(sales1->code);
    for (int i = 0; i < sales1->amountOfLines; ++i) {
        destroyLineSales(sales1->listOfLineSales[i]);
    }
    free(sales1->listOfLineSales);
    free(sales1);
}