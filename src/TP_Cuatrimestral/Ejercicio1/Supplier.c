/**
 * Implementation of a supplier.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#include <stdlib.h>
#include <memory.h>
#include "Supplier.h"

Supplier* newSupplier(char* name, char* description, char* address, char* city, char* phone, char* website){

    Supplier* supplier = malloc(sizeof(Supplier));

    supplier->name = malloc(sizeof(char) * strlen(name));
    supplier->description  = malloc(sizeof(char) * strlen(description));
    supplier->address = malloc(sizeof(char) * strlen(address));
    supplier->city = malloc(sizeof(char) * strlen(city));
    supplier->phone = malloc(sizeof(char) * strlen(phone));
    supplier->website = malloc(sizeof(char) * strlen(website));
    supplier->maxAmountOfManufacturers = 10;
    supplier->listOfManufacturers = malloc(sizeof(Manufacturer*) * supplier->maxAmountOfManufacturers);

    supplier->name = name;
    supplier->description = description;
    supplier->address = address;
    supplier->city = city;
    supplier->phone = phone;
    supplier->website = website;
    supplier->amountOfManufacturers = 0;

    strcpy(supplier->name , name);
    strcpy(supplier->description , description);
    strcpy(supplier->address , address);
    strcpy(supplier->city , city);
    strcpy(supplier->phone , phone);
    strcpy(supplier->website , website);

    return supplier;
}

/**
 * Expands the capacity of manufacturers allowed in a supplier.
 * @param supplier1 whose manufacturers' list will be expanded.
 */
void growListOfManufacturers(Supplier* supplier1){
    supplier1->listOfManufacturers = realloc(supplier1->listOfManufacturers, sizeof(Manufacturer*) * (supplier1->maxAmountOfManufacturers*2));
    supplier1->maxAmountOfManufacturers *= 2;
}

/**
 * Adds a manufacturer to the supplier's list.
 * @param manufacturer1 to be added.
 * @param supplier1 supplier who will add a manufacturer.
 */
void addManufacturer(Manufacturer* manufacturer1 , Supplier* supplier1){
    if (supplier1->amountOfManufacturers == supplier1->maxAmountOfManufacturers) growListOfManufacturers(supplier1);
    supplier1->listOfManufacturers[supplier1->amountOfManufacturers] = manufacturer1;
    supplier1->amountOfManufacturers++;
}

/**
 * removes a manufacturer from the supplier's list.
 * @param supplier1 who will remove a manufacturer.
 * @param manufacturerName name of the manufacturer to be removed.
 */
void removeManufacturer(Supplier* supplier1, char* manufacturerName){
    for (int i = 0; i < supplier1->amountOfManufacturers; i++) {
        if (supplier1->listOfManufacturers[i]->name == manufacturerName){
            destroyManufacturer(supplier1->listOfManufacturers[i]);
            for(int j = i; j < supplier1->amountOfManufacturers - 1; j++){
                supplier1->listOfManufacturers[j] = supplier1->listOfManufacturers[j+1];
            }
            supplier1->amountOfManufacturers--;
        }
    }
}

void destroySupplier(Supplier* supplier){
    free(supplier->name);
    free(supplier->description);
    free(supplier->address);
    free(supplier->city);
    free(supplier->phone);
    free(supplier->website);
    for (int i = 0; i < supplier->maxAmountOfManufacturers; ++i) {
        destroyManufacturer(supplier->listOfManufacturers[i]);
    }
    free(supplier->listOfManufacturers);
    free(supplier);
}