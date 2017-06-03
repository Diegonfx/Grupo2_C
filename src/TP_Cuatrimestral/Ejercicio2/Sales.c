/**
 * Implementation of a sale.
 * @authors Tomas Iturralde, Diego Mancini
 */

#include <stdlib.h>
#include <memory.h>
#include <sys/time.h>
#include "Sales.h"

Sales* newSales(char* code, time_t date, int discount){

    Sales* sales1 = malloc(sizeof(Sales));

    sales1->code = malloc(sizeof(char) * strlen(code));
    sales1->maxAmountOfLines = 10;
    sales1->listOfLineSales = malloc(sizeof(LineSales*) * sales1->maxAmountOfLines);
    date = time(0);

    sales1->code = code;
    sales1->date = date;
    sales1->totalPrice = 0;
    sales1->discount = discount;
    sales1->amountOfLines = 0;

    strcpy(sales1->code , code);

    return sales1;
}

/**
 * Method which enlarges the amount of lineSales inside the sale.
 * @param sales1 to be enlarged.
 */
void salesGrow(Sales* sales1){
    sales1->listOfLineSales = realloc(sales1->listOfLineSales, sizeof(LineSales*) * (sales1->maxAmountOfLines*2));
    sales1->maxAmountOfLines *= 2;
}

/**
 * Adds an item to the sale.
 * @param product to be added.
 * @param sales1 which will receive an item.
 * @param productType shows if the product is a camera or an accessory.
 */
void addItemToSale(LineSales* product, Sales* sales1, char* productType){
    if (sales1->amountOfLines == sales1->maxAmountOfLines) salesGrow(sales1);
    sales1->listOfLineSales[sales1->amountOfLines] = product;
    sales1->amountOfLines++;
    if (product->camera1->name == productType)
        sales1->totalPrice += product->camera1->price;
    else
        sales1->totalPrice += product->accessory1->price;
}

/**
 * Removes an item from the sale.
 * @param sales1 which will lose an item.
 * @param productName the ID in the label from the item which will be removed.
 */
void removeItemFromSale(Sales* sales1, char* productName){
    for (int i = 0; i < sales1->amountOfLines; i++) {
        if (sales1->listOfLineSales[i]->camera1->name == productName || sales1->listOfLineSales[i]->accessory1->name == productName){
            destroyLineSales(sales1->listOfLineSales[i]);
            if (sales1->listOfLineSales[i]->camera1->name == productName)
                sales1->totalPrice -= sales1->listOfLineSales[i]->camera1->price;
            else
                sales1->totalPrice -= sales1->listOfLineSales[i]->accessory1->price;
            for(int j = i; j < sales1->amountOfLines - 1; j++){
                sales1->listOfLineSales[j] = sales1->listOfLineSales[j+1];
            }
            sales1->amountOfLines--;
        }
    }
}

void destroySales(Sales* sales1){
    free(sales1->code);
    for (int i = 0; i < sales1->maxAmountOfLines; ++i) {
        destroyLineSales(sales1->listOfLineSales[i]);
    }
    free(sales1->listOfLineSales);
    free(sales1);
}