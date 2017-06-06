/**
 * Implementation of a Registered user.
 * @authors Tomas Iturralde, Diego Mancini
 */

#include <stdlib.h>
#include <memory.h>
#include "RegisteredUser.h"

RegisteredUser* newRegisteredUser(char* name, char* dni, char* address, char* phone, char* town , char* city, char* country, char* postalCode){

    RegisteredUser* registeredUser = malloc(sizeof(RegisteredUser));

    registeredUser->name = malloc(sizeof(char) * strlen(name)+1);
    registeredUser->dni  = malloc(sizeof(char) * strlen(dni)+1);
    registeredUser->address = malloc(sizeof(char) * strlen(address)+1);
    registeredUser->phone = malloc(sizeof(char) * strlen(phone)+1);
    registeredUser->town = malloc(sizeof(char) * strlen(town))+1;
    registeredUser->city = malloc(sizeof(char) * strlen(city))+1;
    registeredUser->country = malloc(sizeof(char) * strlen(country)+1);
    registeredUser->postalCode = malloc(sizeof(char) * strlen(postalCode)+1);
    registeredUser->role = malloc(sizeof(char*) * 2);
    registeredUser->maxCameras = 10;
    registeredUser->camerasToBuy = malloc(sizeof(Camera*) * registeredUser->maxCameras);
    registeredUser->maxAccessories = 10;
    registeredUser->accessoriesToBuy = malloc(sizeof(Accessory*) * registeredUser->maxAccessories);

    registeredUser->name = name;
    registeredUser->dni = dni;
    registeredUser->address = address;
    registeredUser->phone = phone;
    registeredUser->town = town;
    registeredUser->city = city;
    registeredUser->country = country;
    registeredUser->postalCode = postalCode;
    registeredUser->role[0] = "Client";
    registeredUser->role[1] = "Administrator";
    registeredUser->amountOfCamerasToBuy = 0;
    registeredUser->amountOfAccessoriesToBuy = 0;

    strcpy(registeredUser->name , name);
    strcpy(registeredUser->dni , dni);
    strcpy(registeredUser->address , address);
    strcpy(registeredUser->phone , phone);
    strcpy(registeredUser->town , town);
    strcpy(registeredUser->city , city);
    strcpy(registeredUser->country , country);
    strcpy(registeredUser->postalCode , postalCode);

    return registeredUser;

}

/**
 * Expands the capacity of cameras allowed in an user.
 * @param registeredUser1 whose cameras' list will be expanded.
 */
void growListOfCameras(RegisteredUser* registeredUser1){
    registeredUser1->camerasToBuy = realloc(registeredUser1->camerasToBuy, sizeof(Camera*) * (registeredUser1->maxCameras*2));
    registeredUser1->maxCameras *= 2;
}

/**
 * Adds a camera to the user's list.
 * @param camera1 to be added.
 * @param registeredUser1 user who will add a camera.
 */
void addCamera(Camera* camera1, RegisteredUser* registeredUser1){
    if (registeredUser1->amountOfCamerasToBuy == registeredUser1->maxCameras) growListOfCameras(registeredUser1);
    registeredUser1->camerasToBuy[registeredUser1->amountOfCamerasToBuy] = camera1;
    registeredUser1->amountOfCamerasToBuy++;
}

/**
 * Expands the capacity of accessories allowed in an user.
 * @param registeredUser1 whose accessories' list will be expanded.
 */
void growListOfAccessories(RegisteredUser* registeredUser1){
    registeredUser1->accessoriesToBuy = realloc(registeredUser1->accessoriesToBuy, sizeof(Accessory*) * (registeredUser1->maxAccessories*2));
    registeredUser1->maxAccessories *= 2;
}

/**
 * Adds an accessory to the user's list.
 * @param accessory1 to be added.
 * @param registeredUser1 user who will add an accessory.
 */
void addAccessory(Accessory* accessory1, RegisteredUser* registeredUser1){
    if (registeredUser1->amountOfAccessoriesToBuy == registeredUser1->maxAccessories) growListOfAccessories(registeredUser1);
    registeredUser1->accessoriesToBuy[registeredUser1->amountOfAccessoriesToBuy] = accessory1;
    registeredUser1->amountOfAccessoriesToBuy++;
}

/**
 * Removes a product from the user.
 * @param registeredUser1 user who will lose the product.
 * @param productName product's name.
 */
void removeProduct(RegisteredUser* registeredUser1, char* productName){
    for (int i = 0; i < registeredUser1->amountOfCamerasToBuy; ++i) {
        if (registeredUser1->camerasToBuy[i]->name == productName){
            destroyCamera(registeredUser1->camerasToBuy[i]);
            registeredUser1->amountOfCamerasToBuy--;
        }
    }
    for (int i = 0; i < registeredUser1->amountOfAccessoriesToBuy; ++i) {
        if (registeredUser1->accessoriesToBuy[i]->name == productName){
            destroyAccessory(registeredUser1->accessoriesToBuy[i]);
            registeredUser1->amountOfAccessoriesToBuy--;
        }
    }
}

void destroyRegisteredUser(RegisteredUser* registeredUser1){

    free(registeredUser1->name);
    free(registeredUser1->address);
    free(registeredUser1->city);
    free(registeredUser1->country);
    free(registeredUser1->dni);
    free(registeredUser1->phone);
    free(registeredUser1->postalCode);
    free(registeredUser1->town);
    free(registeredUser1->role[0]);
    free(registeredUser1->role[1]);
    free(registeredUser1->role);
    for (int i = 0; i < registeredUser1->maxCameras; ++i) {
        destroyCamera(registeredUser1->camerasToBuy[i]);
    }
    free(registeredUser1->camerasToBuy);
    for (int j = 0; j < registeredUser1->maxAccessories; ++j) {
        destroyAccessory(registeredUser1->accessoriesToBuy[j]);
    }
    free(registeredUser1->accessoriesToBuy);
    free(registeredUser1);
}