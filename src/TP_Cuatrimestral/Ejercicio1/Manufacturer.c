/**
 * Implementation of a manufacturer.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#include <stdlib.h>
#include <memory.h>
#include "Manufacturer.h"

Manufacturer* newManufacturer(char* name, char* description, char* address, char* city, char* phone, char* website){

    Manufacturer* manufacturer1 = malloc(sizeof(Manufacturer));

    manufacturer1->name = malloc(sizeof(char) * strlen(name)+1);
    manufacturer1->description  = malloc(sizeof(char) * strlen(description)+1);
    manufacturer1->address = malloc(sizeof(char) * strlen(address)+1);
    manufacturer1->city = malloc(sizeof(char) * strlen(city)+1);
    manufacturer1->phone = malloc(sizeof(char) * strlen(phone)+1);
    manufacturer1->website = malloc(sizeof(char) * strlen(website)+1);
    manufacturer1->maxCapacityOfItems = 10;
    manufacturer1->listItems = malloc(sizeof(Item*) * manufacturer1->maxCapacityOfItems);

    manufacturer1->name = name;
    manufacturer1->description = description;
    manufacturer1->address = address;
    manufacturer1->city = city;
    manufacturer1->phone = phone;
    manufacturer1->website = website;
    manufacturer1->amountOfItems = 0;

    strcpy(manufacturer1->name , name);
    strcpy(manufacturer1->description , description);
    strcpy(manufacturer1->address , address);
    strcpy(manufacturer1->city , city);
    strcpy(manufacturer1->phone , phone);
    strcpy(manufacturer1->website , website);

    return manufacturer1;

}

/**
 * Expands the amount of items a manufacturer can store.
 * @param manufacturer1 whose items' list will be expanded.
 */
void growListOfItem(Manufacturer* manufacturer1){
    manufacturer1->listItems = realloc(manufacturer1->listItems, sizeof(Item*) * (manufacturer1->maxCapacityOfItems*2));
    manufacturer1->maxCapacityOfItems *= 2;
}

/**
 * Make an item.
 * @return the produced item.
 */
void produceItem(char* name, char* model, float price , Label* label1, Manufacturer* manufacturer1){
    if (manufacturer1->amountOfItems == manufacturer1->maxCapacityOfItems) growListOfItem(manufacturer1);
    manufacturer1->listItems[manufacturer1->amountOfItems] = newItem(name, model, price, label1);
    manufacturer1->amountOfItems++;
}

/**
 * Empties the list of items inside a manufacturer.
 * @param manufacturer1 whose items' list will be emptied.
 */
void emptyListOfItems(Manufacturer* manufacturer1){
    manufacturer1->amountOfItems = 0;
}

void destroyManufacturer(Manufacturer* manufacturer1){
    free(manufacturer1->name);
    free(manufacturer1->description);
    free(manufacturer1->address);
    free(manufacturer1->city);
    free(manufacturer1->phone);
    free(manufacturer1->website);
    for (int i = 0; i < manufacturer1->maxCapacityOfItems; ++i) {
        destroyItem(manufacturer1->listItems[i]);
    }
    free(manufacturer1->listItems);
    free(manufacturer1);
}