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
    business1->maxCapacityOfUsers = 10;
    business1->listOfUsers = malloc(sizeof(RegisteredUser*) * business1->maxCapacityOfUsers);
    business1->maxAmountOfCameras = 10;
    business1->camerasOnStore = malloc(sizeof(Camera*) * business1->maxAmountOfCameras);
    business1->maxAmountOfAccessories = 10;
    business1->accessoriesOnStore = malloc(sizeof(Accessory*) * business1->maxAmountOfAccessories);

    business1->name = name;
    business1->amountOfSuppliers = 0;
    business1->amountOfSuppliers = 0;
    business1->amountOfCameras = 0;
    business1->amountOfAccessories = 0;

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
 * Expands the capacity of cameras allowed in a business.
 * @param business1 whose cameras' list will be expanded.
 */
void growAListOfCameras(Business* business1){
    business1->camerasOnStore = realloc(business1->camerasOnStore, sizeof(Camera*) * (business1->maxAmountOfCameras*2));
    business1->maxAmountOfCameras *= 2;
}

/**
 * Adds a camera to the business' list.
 * @param camera1 to be added.
 * @param system1 business who will add a camera.
 */
void addACamera(Camera* camera1, Business* system1){
    if (system1->amountOfCameras == system1->maxAmountOfCameras) growAListOfCameras(system1);
    system1->camerasOnStore[system1->amountOfCameras] = camera1;
    system1->amountOfCameras++;
}

/**
 * Expands the capacity of accessories allowed in a business.
 * @param business1 whose accessories' list will be expanded.
 */
void growAListOfAccessories(Business* business1){
    business1->accessoriesOnStore = realloc(business1->accessoriesOnStore, sizeof(Accessory*) * (business1->maxAmountOfAccessories*2));
    business1->maxAmountOfAccessories *= 2;
}

/**
 * Adds an accessory to the business' list.
 * @param accessory1 to be added.
 * @param system1 business who will add an accessory.
 */
void addAnAccessory(Accessory* accessory1, Business* system1){
    if (system1->amountOfAccessories == system1->maxAmountOfAccessories) growAListOfAccessories(system1);
    system1->accessoriesOnStore[system1->amountOfAccessories] = accessory1;
    system1->amountOfAccessories++;
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
                        addACamera(system1->listSuppliers[i]->listOfProducers[j]->listOfCameras[k], system1);
                        system1->listSuppliers[i]->listOfProducers[j]->amountOfCameras--;
                    }
                    for (int k = 0; k < amountOfAccessories || system1->listSuppliers[i]->listOfProducers[j]->amountOfAccessories == 0; ++k) {
                        addAnAccessory(system1->listSuppliers[i]->listOfProducers[j]->listOfAccessories[k], system1);
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

/**
 * Expands the capacity of users allowed in a business.
 * @param business1 whose users' list will be expanded.
 */
void growAListOfUsers(Business* business1){
    business1->listOfUsers = realloc(business1->listOfUsers, sizeof(RegisteredUser*) * (business1->maxCapacityOfUsers*2));
    business1->maxCapacityOfUsers *= 2;
}

/**
 * Adds a user to the business' list.
 * @param registeredUser1 to be added.
 * @param system1 business who will add an user.
 */
void addAUser(RegisteredUser* registeredUser1, Business* system1){
    if (system1->amountOfUsers == system1->maxCapacityOfUsers) growAListOfUsers(system1);
    system1->listOfUsers[system1->amountOfUsers] = registeredUser1;
    system1->amountOfUsers++;
}

/**
 * removes an user from the business' list.
 * @param business1 who will remove an user.
 * @param userName name of the user to be removed.
 */
void removeAUser(Business* business1, char* userName){
    for (int i = 0; i < business1->amountOfUsers; i++) {
        if (business1->listOfUsers[i]->name == userName){
            destroyRegisteredUser(business1->listOfUsers[i]);
            for(int j = i; j < business1->amountOfUsers - 1; j++){
                business1->listOfUsers[j] = business1->listOfUsers[j+1];
            }
            business1->amountOfUsers--;
        }
    }
}

/**
 * removes a product from the business' list.
 * @param business1 who will remove a product.
 * @param productName name of the product to be removed.
 */
void removeAProduct(Business* business1, char* productName){
    for (int i = 0; i < business1->amountOfCameras; ++i) {
        if (business1->camerasOnStore[i]->name == productName){
            destroyCamera(business1->camerasOnStore[i]);
            business1->amountOfCameras--;
        }
    }
    for (int i = 0; i < business1->amountOfAccessories; ++i) {
        if (business1->accessoriesOnStore[i]->name == productName){
            destroyAccessory(business1->accessoriesOnStore[i]);
            business1->amountOfAccessories--;
        }
    }
}

void destroyABusiness(Business* system1){
    free(system1->name);
    for (int i = 0; i < system1->maxCapacityOfSuppliers; ++i) {
        destroyASupplier(system1->listSuppliers[i]);
    }
    free(system1->listSuppliers);
    for (int j = 0; j < system1->maxCapacityOfUsers; ++j) {
        destroyRegisteredUser(system1->listOfUsers[j]);
    }
    free(system1->listOfUsers);
    for (int k = 0; k < system1->maxAmountOfCameras; ++k) {
        destroyCamera(system1->camerasOnStore[k]);
    }
    free(system1->camerasOnStore);
    for (int l = 0; l < system1->maxAmountOfAccessories; ++l) {
        destroyAccessory(system1->accessoriesOnStore[l]);
    }
    free(system1->accessoriesOnStore);
    free(system1);
}