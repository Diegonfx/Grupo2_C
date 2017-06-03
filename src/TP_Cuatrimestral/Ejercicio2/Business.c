/**
 * Implementation of a business.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#include <stdlib.h>
#include <memory.h>
#include "Business.h"

Business* newABusiness(char* name){
    Business* business1 = malloc(sizeof(Business));

    business1->name = malloc(sizeof(char) * strlen(name)+1);
    business1->maxCapacityOfSuppliers = 10;
    business1->listSuppliers = malloc(sizeof(Supplier*) * business1->maxCapacityOfSuppliers);
    business1->maxCapacityOfSales = 10;
    business1->listOfSales = malloc(sizeof(Sales*) * business1->maxCapacityOfSales);

    business1->name = name;
    business1->amountOfSuppliers = 0;
    business1->amountOfSales = 0;

    strcpy(business1->name , name);

    return business1;
}

/**
 * Expands the capacity of suppliers allowed in a business.
 * @param business1 whose suppliers' list will be expanded.
 */
void growAListOfSuppliers(Business* business1){
    business1->listSuppliers = realloc(business1->listSuppliers, sizeof(Supplier*) * (business1->maxCapacityOfSuppliers*2));
    business1->maxCapacityOfSuppliers *= 2;
}

/**
 * Adds a supplier to the business' list.
 * @param supplier1 to be added.
 * @param system1 business who will add a supplier.
 */
void addASupplier(Supplier* supplier1, Business* system1){
    if (system1->amountOfSuppliers == system1->maxCapacityOfSuppliers) growAListOfSuppliers(system1);
    system1->listSuppliers[system1->amountOfSuppliers] = supplier1;
    system1->amountOfSuppliers++;
}


/**
 * Ask a supplier for more products.
 * @param supplierName supplier who will supply more products.
 * @param system1 business who will receive the products.
 * @param producerName name of the name of the producer inside the chosen supplier to produce the products.
 * @param amountOfCameras to be supplied.
 * @param amountOfAccessories to be supplied.
 * @param productType camera or accessory.
 */
void askForSupplies2(char* supplierName , Business* system1, char* producerName, int amountOfCameras, int amountOfAccessories, char* productType){
    for (int i = 0; i < system1->amountOfSuppliers; ++i) {
        if (system1->listSuppliers[i]->name == supplierName){
            for (int j = 0; j < system1->listSuppliers[i]->amountOfProducers; ++j) {
                if (system1->listSuppliers[i]->listOfProducers[j]->name == producerName){
                    for (int k = 0; k < amountOfCameras || system1->listSuppliers[i]->listOfProducers[j]->amountOfCameras == 0; ++k) {
                        //?????
                        system1->listSuppliers[i]->listOfProducers[j]->amountOfCameras--;
                    }
                    for (int k = 0; k < amountOfAccessories || system1->listSuppliers[i]->listOfProducers[j]->amountOfAccessories == 0; ++k) {
                        //?????
                        system1->listSuppliers[i]->listOfProducers[j]->amountOfAccessories--;
                    }
                }
            }
        }
    }
}

/**
 * removes a supplier from the business' list.
 * @param business1 who will remove a supplier.
 * @param supplierName name of the supplier to be removed.
 */
void removeASupplier(Business* business1, char* supplierName){
    for (int i = 0; i < business1->amountOfSuppliers; i++) {
        if (business1->listSuppliers[i]->name == supplierName){
            destroyASupplier(business1->listSuppliers[i]);
            for(int j = i; j < business1->amountOfSuppliers - 1; j++){
                business1->listSuppliers[j] = business1->listSuppliers[j+1];
            }
            business1->amountOfSuppliers--;
        }
    }
}

void destroyABusiness(Business* system1){
    free(system1->name);
    for (int i = 0; i < system1->maxCapacityOfSuppliers; ++i) {
        destroyASupplier(system1->listSuppliers[i]);
    }
    free(system1->listSuppliers);
    free(system1);
}