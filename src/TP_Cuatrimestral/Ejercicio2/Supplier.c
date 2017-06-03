/**
 * Implementation of a supplier.
 * @authors Tomas Iturralde, Diego Mancini
 */

#include <stdlib.h>
#include <memory.h>
#include "Supplier.h"

Supplier* newASupplier(char* cif, char* name, char* phone, char* fax, char* responsible, char* address, char* town, char* city,char* country,char* postalCode){

    Supplier* supplier = malloc(sizeof(Supplier));

    supplier->cif  = malloc(sizeof(char) * strlen(cif)+1);
    supplier->name = malloc(sizeof(char) * strlen(name)+1);
    supplier->phone = malloc(sizeof(char) * strlen(phone)+1);
    supplier->fax = malloc(sizeof(char) * strlen(fax)+1);
    supplier->responsible = malloc(sizeof(char) * strlen(responsible)+1);
    supplier->address = malloc(sizeof(char) * strlen(address)+1);
    supplier->town = malloc(sizeof(char) * strlen(town)+1);
    supplier->city = malloc(sizeof(char) * strlen(city)+1);
    supplier->country = malloc(sizeof(char) * strlen(country)+1);
    supplier->postalCode = malloc(sizeof(char) * strlen(postalCode)+1);
    supplier->maxAmountOfProducers = 10;
    supplier->listOfProducers = malloc(sizeof(Producer*) * supplier->maxAmountOfProducers);

    supplier->cif = cif;
    supplier->name = name;
    supplier->address = address;
    supplier->phone = phone;
    supplier->fax = fax;
    supplier->responsible = responsible;
    supplier->town = town;
    supplier->city = city;
    supplier->country = country;
    supplier->postalCode = postalCode;
    supplier->amountOfProducers = 0;

    strcpy(supplier->cif , cif);
    strcpy(supplier->name , name);
    strcpy(supplier->address , address);
    strcpy(supplier->phone , phone);
    strcpy(supplier->fax , fax);
    strcpy(supplier->responsible , responsible);
    strcpy(supplier->town , town);
    strcpy(supplier->city , city);
    strcpy(supplier->country , country);
    strcpy(supplier->postalCode , postalCode);

    return supplier;
}

/**
 * Expands the capacity of producers allowed in a supplier.
 * @param supplier1 whose producers' list will be expanded.
 */
void growListOfProducers(Supplier* supplier1){
    supplier1->listOfProducers = realloc(supplier1->listOfProducers, sizeof(Producer*) * (supplier1->maxAmountOfProducers*2));
    supplier1->maxAmountOfProducers *= 2;
}

/**
 * Adds a producer to the supplier's list.
 * @param producer1 to be added.
 * @param supplier1 supplier who will add a producer.
 */
void addProducer(Producer* producer1 , Supplier* supplier1){
    if (supplier1->amountOfProducers == supplier1->maxAmountOfProducers) growListOfProducers(supplier1);
    supplier1->listOfProducers[supplier1->amountOfProducers] = producer1;
    supplier1->amountOfProducers++;
}

/**
 * removes a producer from the supplier's list.
 * @param supplier1 who will remove a producer.
 * @param producerName name of the producer to be removed.
 */
void removeProducer(Supplier* supplier1, char* producerName){
    for (int i = 0; i < supplier1->amountOfProducers; i++) {
        if (supplier1->listOfProducers[i]->name == producerName){
            destroyProducer(supplier1->listOfProducers[i]);
            for(int j = i; j < supplier1->amountOfProducers - 1; j++){
                supplier1->listOfProducers[j] = supplier1->listOfProducers[j+1];
            }
            supplier1->amountOfProducers--;
        }
    }
}

void destroyASupplier(Supplier* supplier1){

    free(supplier1->cif);
    free(supplier1->name);
    free(supplier1->address);
    free(supplier1->phone);
    free(supplier1->fax);
    free(supplier1->responsible);
    free(supplier1->town);
    free(supplier1->city);
    free(supplier1->country);
    free(supplier1->postalCode);
    for (int i = 0; i < supplier1->maxAmountOfProducers; ++i) {
        destroyProducer(supplier1->listOfProducers[i]);
    }
    free(supplier1->listOfProducers);
    free(supplier1);
}