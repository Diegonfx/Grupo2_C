//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_CART_H
#define GRUPO2_C_CART_H

typedef struct cart Cart;

struct cart {
    char* id;
    float total;
};

Cart* newCart(char* id, float units);
void annihilateCart(Cart* cart1);

#endif //GRUPO2_C_CART_H
