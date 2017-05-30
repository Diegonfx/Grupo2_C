//
// Created by Diego Mancini on 22/5/17.
//

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

void addManufacturer(Manufacturer* manufacturer1 , Business* system1){}

void addSupplier(Supplier* supplier1, Business* system1){}

void addItemToCatalogue(Item* manufacturer1 , Business* system1){}

void askForSupplies(Supplier* supplier1 , Business* system1){}

void removeManufacturer(Business* business1, char* manufacturerName){}

void removeSupplier(Business* business1, char* supplierName){}

void removeItemFromCatalogue(Business* business1, char* itemLabelID){}

void freeBusiness(Business* system1){
    free(system1->name);
    free(system1->catalogue);
    free(system1->listManufacturers);
    free(system1->listSuppliers);
    free(system1);
}