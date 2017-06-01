/**
 * Implementation of a cart.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#include <stdlib.h>
#include <memory.h>
#include "Cart.h"

Cart* newCart(char* id){
    Cart* result = malloc(sizeof(Cart));
    result->id = malloc(sizeof(char) * strlen(id));
    result->id = id;
    strcpy(result->id , id);
    result->total = 0;
    result->itemsOnCart = malloc(sizeof(LineCart*) * 10);
    result->amountOfItemsOnCart = 0;
    result->maxCapacity = 10;

    return result;
}

/**
 * Method which enlarges the cart by doubling its size.
 * @param cart to be enlarged.
 */
void cartGrow(Cart* cart){
    cart->itemsOnCart = realloc(cart->itemsOnCart, sizeof(LineCart*) * (cart->maxCapacity*2));
    cart->maxCapacity *= 2;
}

/**
 * Adds an item to the cart.
 * @param item to be added.
 * @param cart which will receive an item.
 */
void addItemToCart(LineCart* item, Cart* cart){
    if (cart->amountOfItemsOnCart == cart->maxCapacity)
        cartGrow(cart);
    cart->itemsOnCart[cart->amountOfItemsOnCart] = item;
    cart->amountOfItemsOnCart++;
}

/**
 * Removes an item from the cart.
 * @param cart which will lose an item.
 * @param labelID the ID in the label from the item which will be removed.
 */
void removeItemFromCart(Cart* cart, char* labelID){
    for (int i = 0; i < cart->amountOfItemsOnCart; i++) {
        if (cart->itemsOnCart[i]->item->label->id == labelID){
            destroyLineCart(cart->itemsOnCart[i]);
            for(int j = i; j < cart->amountOfItemsOnCart - 1; j++){
                cart->itemsOnCart[j] = cart->itemsOnCart[j+1];
            }
            cart->amountOfItemsOnCart--;
        }
    }
}

/**
 * Sums the prices of every item in the cart and creates a ticket.
 * @param cart who will create the ticket based on the prices from its items' prices.
 * @return a ticket with the total to pay.
 */
Ticket* produceTicket(Cart* cart){
    for (int i = 0; i < cart->amountOfItemsOnCart; ++i) {
        cart->total += cart->itemsOnCart[i]->item->price;
    }
    return newTicket(cart->id, cart->total, cart->amountOfItemsOnCart);
}

void destroyCart(Cart* cart){
    free(cart->id);
    for (int i = 0; i < cart->maxCapacity; ++i) {
        destroyLineCart(cart->itemsOnCart[i]);
    }
    free(cart->itemsOnCart);
    free(cart);
}
