/**
 * Implementation of a business.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#include <stdlib.h>
#include <memory.h>
#include "Business.h"

Business* newBusiness(char* name , Catalogue* catalogue){
    Business* business1 = malloc(sizeof(Business));

    business1->name = malloc(sizeof(char) * strlen(name));
    business1->catalogue = malloc(sizeof(Catalogue));
    business1->maxCapacityOfSuppliers = 10;
    business1->listSuppliers = malloc(sizeof(Supplier*) * business1->maxCapacityOfSuppliers);

    business1->name = name;
    business1->catalogue = catalogue;
    business1->amountOfSuppliers = 0;

    strcpy(business1->name , name);

    return business1;
}

/**
 * Expands the capacity of suppliers allowed in a business.
 * @param business1 whose suppliers' list will be expanded.
 */
void growListOfSuppliers(Business* business1){
    business1->listSuppliers = realloc(business1->listSuppliers, sizeof(Manufacturer*) * (business1->maxCapacityOfSuppliers*2));
    business1->maxCapacityOfSuppliers *= 2;
}

/**
 * Adds a supplier to the business' list.
 * @param supplier1 to be added.
 * @param system1 business who will add a supplier.
 */
void addSupplier(Supplier* supplier1, Business* system1){
    if (system1->amountOfSuppliers == system1->maxCapacityOfSuppliers) growListOfSuppliers(system1);
    system1->listSuppliers[system1->amountOfSuppliers] = supplier1;
    system1->amountOfSuppliers++;
}

/**
 * Adds an item to the business' catalogue.
 * @param item1 to be added.
 * @param system1 business who will add an item.
 */
void addItemToCatalogue(Item* item1 , Business* system1){
    if (system1->catalogue->amountOfItems == system1->catalogue->maxCapacityOfItems) growListOfItems(system1->catalogue);
    system1->catalogue->listItems[system1->catalogue->amountOfItems] = item1;
    system1->catalogue->amountOfItems++;
}

/**
 * Ask a supplier for more items.
 * @param supplier1 supplier who will supply more items.
 * @param system1 business who will receive the items.
 * @param manufacturerName
 * @param amountOfItems
 */
void askForSupplies(char* supplierName , Business* system1, char* manufacturerName, int amountOfItems){
    for (int i = 0; i < system1->amountOfSuppliers; ++i) {
        if (system1->listSuppliers[i]->name == supplierName){
            for (int j = 0; j < system1->listSuppliers[i]->amountOfManufacturers; ++j) {
                if (system1->listSuppliers[i]->listOfManufacturers[j]->name == manufacturerName){
                    for (int k = 0; k < amountOfItems || system1->listSuppliers[i]->listOfManufacturers[j]->amountOfItems == 0; ++k) {
                        addItemToCatalogue(system1->listSuppliers[i]->listOfManufacturers[j]->listItems[k], system1);
                        system1->listSuppliers[i]->listOfManufacturers[j]->amountOfItems--;
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
void removeSupplier(Business* business1, char* supplierName){
    for (int i = 0; i < business1->amountOfSuppliers; i++) {
        if (business1->listSuppliers[i]->name == supplierName){
            destroySupplier(business1->listSuppliers[i]);
            for(int j = i; j < business1->amountOfSuppliers - 1; j++){
                business1->listSuppliers[j] = business1->listSuppliers[j+1];
            }
            business1->amountOfSuppliers--;
        }
    }
}

/**
 * removes an item from the business' catalogue.
 * @param business1 who will remove an item.
 * @param itemLabelID name of the item to be removed.
 */
void removeItemFromCatalogue(Business* business1, char* itemLabelID){
    for (int i = 0; i < business1->catalogue->amountOfItems; i++) {
        if (business1->catalogue->listItems[i]->label->name == itemLabelID){
            destroyItem(business1->catalogue->listItems[i]);
            for(int j = i; j < business1->catalogue->amountOfItems - 1; j++){
                business1->catalogue->listItems[j] = business1->catalogue->listItems[j+1];
            }
            business1->catalogue->amountOfItems--;
        }
    }
}

void destroyBusiness(Business* system1){
    free(system1->name);
    destroyCatalogue(system1->catalogue);
    for (int i = 0; i < system1->maxCapacityOfSuppliers; ++i) {
        destroySupplier(system1->listSuppliers[i]);
    }
    free(system1->listSuppliers);
    free(system1);
}