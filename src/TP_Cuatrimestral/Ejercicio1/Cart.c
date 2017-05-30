//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Cart.h"

Cart* newCart(char* id){
    Cart* result = malloc(sizeof(Cart));
    result->id = malloc(sizeof(char) * strlen(id));
    result->id = id;
    strcpy(result->id , id);

    return result;
}

void addItemToCart(Item* item, Cart* cart){

    cart->amountOfItemsOnCart++;
}

void removeItemFromCart(Cart* cart, char* labelID){

    cart->amountOfItemsOnCart--;
}

Ticket* produceTicket(Cart* cart){
    for (int i = 0; i < cart->amountOfItemsOnCart; ++i) {
        //cart->total += cart->itemsOnCart
    }
    return newTicket(cart->id, cart->total);
}

void annihilateCart(Cart* cart){
    free(cart->id);
    free(cart);
}
