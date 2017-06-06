/**
 * Declaration of a cart.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#ifndef GRUPO2_C_CART_H
#define GRUPO2_C_CART_H

#include "Ticket.h"
#include "LineCart.h"

typedef struct cart Cart;

struct cart {
    char* id;
    float total;
    LineCart** itemsOnCart;
    int amountOfItemsOnCart;
    int maxCapacity;
};

Cart* newCart(char* id);
void cartGrow(Cart* cart);
void addItemToCart(LineCart* item, Cart* cart);
void removeItemFromCart(Cart* cart, char* labelID);
Ticket* produceTicket(Cart* cart);
void destroyCart(Cart* cart);

#endif //GRUPO2_C_CART_H