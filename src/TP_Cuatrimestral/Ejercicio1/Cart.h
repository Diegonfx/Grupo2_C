//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_CART_H
#define GRUPO2_C_CART_H

#include "Ticket.h"
#include "Item.h"

typedef struct cart Cart;

struct cart {
    char* id;
    float total;
    Item** itemsOnCart;
    int amountOfItemsOnCart;
};

Cart* newCart(char* id);
void addItemToCart(Item* item, Cart* cart);
void removeItemFromCart(Cart* cart, char* labelID);
Ticket* produceTicket(Cart* cart);
void annihilateCart(Cart* cart);

#endif //GRUPO2_C_CART_H
