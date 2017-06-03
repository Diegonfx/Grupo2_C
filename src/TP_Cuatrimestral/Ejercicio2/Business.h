/**
 * Declaration of a business.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#ifndef GRUPO2_C_SYSTEM_H
#define GRUPO2_C_SYSTEM_H

#include "Supplier.h"
#include "Sales.h"

typedef struct business Business;

struct business {
    char* name;
    Supplier** listSuppliers;
    int amountOfSuppliers;
    int maxCapacityOfSuppliers;
    Sales** listOfSales;
    int amountOfSales;
    int maxCapacityOfSales;
};

Business* newABusiness(char* name);

void growAListOfSuppliers(Business* business1);
void addASupplier(Supplier* supplier1, Business* system1);
void askForSupplies2(char* supplierName , Business* system1, char* manufacturerName, int amountOfItems, int amountOfAccessories, char* productType);
void removeASupplier(Business* business1, char* supplierName);

void destroyABusiness(Business* system1);

#endif //GRUPO2_C_SYSTEM_H
