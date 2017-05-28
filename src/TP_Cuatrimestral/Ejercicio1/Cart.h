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
};

Cart* newCart(char* id, Item** items);
Ticket* produceTicket(Cart* cart);
void annihilateCart(Cart* cart);

#endif //GRUPO2_C_CART_H
