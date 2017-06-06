/**
 * Declaration of a business.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#ifndef GRUPO2_C_SYSTEM_H
#define GRUPO2_C_SYSTEM_H

#include "Supplier.h"
#include "Catalogue.h"

typedef struct business Business;

struct business {
    char* name;
    Supplier** listSuppliers;
    int amountOfSuppliers;
    Catalogue* catalogue;
    int maxCapacityOfSuppliers;
};

Business* newBusiness(char* name , Catalogue* catalogue1);

void growListOfSuppliers(Business* business1);
void addSupplier(Supplier* supplier1, Business* system1);
void addItemToCatalogue(Item* item1 , Business* system1);
void askForSupplies(char* supplierName , Business* system1, char* manufacturerName, int amountOfItems);
void removeSupplier(Business* business1, char* supplierName);
void removeItemFromCatalogue(Business* business1, char* itemLabelID);

void destroyBusiness(Business* system1);

#endif //GRUPO2_C_SYSTEM_H