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

    business1->name = name;
    business1->catalogue = catalogue;

    strcpy(business1->name , name);

    return business1;
}

/**
 * Adds a manufacturer to the business' list.
 * @param manufacturer1 to be added.
 * @param system1 business who will add a manufacturer.
 */
void addManufacturer(Manufacturer* manufacturer1 , Business* system1){}

/**
 * Adds a supplier to the business' list.
 * @param supplier1 to be added.
 * @param system1 business who will add a supplier.
 */
void addSupplier(Supplier* supplier1, Business* system1){}

/**
 * Adds an item to the business' catalogue.
 * @param item1 to be added.
 * @param system1 business who will add an item.
 */
void addItemToCatalogue(Item* item1 , Business* system1){}

/**
 * Ask a supplier for more items.
 * @param supplier1 supplier who will supply more items.
 * @param system1 business who will receive the items.
 */
void askForSupplies(Supplier* supplier1 , Business* system1){}

/**
 * removes a manufacturer from the business' list.
 * @param business1 who will remove a manufacturer.
 * @param manufacturerName name of the manufacturer to be removed.
 */
void removeManufacturer(Business* business1, char* manufacturerName){}

/**
 * removes a supplier from the business' list.
 * @param business1 who will remove a supplier.
 * @param supplierName name of the supplier to be removed.
 */
void removeSupplier(Business* business1, char* supplierName){}

/**
 * removes an item from the business' catalogue.
 * @param business1 who will remove an item.
 * @param itemLabelID name of the item to be removed.
 */
void removeItemFromCatalogue(Business* business1, char* itemLabelID){}

void destroyBusiness(Business* system1){
    free(system1->name);
    free(system1->catalogue);
    free(system1->listManufacturers);
    free(system1->listSuppliers);
    free(system1);
}