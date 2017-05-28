//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Cart.h"

Cart* newCart(char* id, Item** items){

    Cart* result = malloc(sizeof(Cart));

    result->id = malloc(sizeof(char) * strlen(id));

    result->id = id;
    /*for (int i = 0; i < ; ++i) {
        result->total += items[i];
    }*/


    strcpy(result->id , id);

    return result;
}

Ticket* produceTicket(Cart* cart){
    return newTicket(cart->id, cart->total);
}

void annihilateCart(Cart* cart){
    free(cart->id);
    free(cart);
}
