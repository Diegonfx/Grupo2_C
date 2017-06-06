/**
 * Declaration of a business.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#ifndef GRUPO2_C_SYSTEM_H
#define GRUPO2_C_SYSTEM_H

#include "Supplier.h"
#include "RegisteredUser.h"

typedef struct business Business;

struct business {
    char* name;
    Supplier** listSuppliers;
    int amountOfSuppliers;
    int maxCapacityOfSuppliers;
    RegisteredUser** listOfUsers;
    int amountOfUsers;
    int maxCapacityOfUsers;
    Camera** camerasOnStore;
    int amountOfCameras;
    int maxAmountOfCameras;
    Accessory** accessoriesOnStore;
    int amountOfAccessories;
    int maxAmountOfAccessories;
};

Business* newABusiness(char* name);

void growAListOfSuppliers(Business* business1);
void addASupplier(Supplier* supplier1, Business* system1);
void growAListOfCameras(Business* business1);
void addACamera(Camera* camera1, Business* system1);
void growAListOfAccessories(Business* business1);
void addAnAccessory(Accessory* accessory1, Business* system1);
void askForSupplies2(char* supplierName , Business* system1, char* manufacturerName, int amountOfItems, int amountOfAccessories, char* productType);
void removeASupplier(Business* business1, char* supplierName);
void growAListOfUsers(Business* business1);
void addAUser(RegisteredUser* registeredUser1, Business* system1);
void removeAUser(Business* business1, char* UserName);
void removeAProduct(Business* business1, char* productName);

void destroyABusiness(Business* system1);

#endif //GRUPO2_C_SYSTEM_H
