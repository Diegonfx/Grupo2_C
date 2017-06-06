/**
 * Declaration of a Registered user.
 * @authors Tomas Iturralde, Diego Mancini
 */

#ifndef GRUPO2_C_REGISTEREDUSER_H
#define GRUPO2_C_REGISTEREDUSER_H

#include "Product.h"
#include "Sales.h"

typedef struct registeredUser RegisteredUser;

struct registeredUser {
    char* name;
    char* dni;
    char* address;
    char* phone;
    char* town;
    char* city;
    char* country;
    char* postalCode;
    char** role;
    Camera** camerasToBuy;
    int amountOfCamerasToBuy;
    int maxCameras;
    Accessory** accessoriesToBuy;
    int amountOfAccessoriesToBuy;
    int maxAccessories;
};

RegisteredUser* newRegisteredUser(char* name, char* dni, char* address, char* phone, char* town , char* city, char* country, char* postalCode);
void growListOfCameras(RegisteredUser* registeredUser1);
void addCamera(Camera* camera1, RegisteredUser* registeredUser1);
void growListOfAccessories(RegisteredUser* registeredUser1);
void addAccessory(Accessory* accessory1, RegisteredUser* registeredUser1);
void removeProduct(RegisteredUser* registeredUser1, char* productName);
void destroyRegisteredUser(RegisteredUser* registeredUser1);

#endif //GRUPO2_C_REGISTEREDUSER_H
