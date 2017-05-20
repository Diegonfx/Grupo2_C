//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Product.h"

Product* newProduct(char* name, char* code, int pvp, FILE image){

    Product* product = malloc(sizeof(Product));

    product->code = malloc(sizeof(char) * strlen(code));
    product->name = malloc(sizeof(char) * strlen(name));

    product->name = name;
    product->code = code;
    product->pvp = pvp;
    product->image = image;

    strcpy(product->name, name);
    strcpy(product->code,  code);

    return product;

}

void annihilateProduct(Product* product1){
    free(product1->name);
    free(product1->code);
    free(product1);
}