//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_PRODUCT_H
#define GRUPO2_C_PRODUCT_H

#include <stdio.h>

typedef struct product Product;

struct product {
    char* name;
    char* code;
    int pvp;
    FILE image;
};

Product* newProduct(char* name, char* code, int pvp, FILE image);
void annihilateProduct(Product* product1);

#endif //GRUPO2_C_PRODUCT_H
