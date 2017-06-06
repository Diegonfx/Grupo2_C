/**
 * Declaration of a product (Camera and Accessory).
 * @authors Tomas Iturralde, Diego Mancini
 */

#ifndef GRUPO2_C_PRODUCT_H
#define GRUPO2_C_PRODUCT_H

#include <stdio.h>

//CAMERA
typedef struct camera Camera;

struct camera {
    char* name;
    char* code;
    int price;
    FILE image;
    int megapixels;
    int screenSize;
    int zoom;
    char **type;
    char* productType;
};

Camera* newCamera(char* name, char* code, int price, FILE image, int megapixels, int screenSize, int zoom);
void destroyCamera(Camera* camera1);

//ACCESSORY
typedef struct accessory Accessory;

struct accessory {
    char* name;
    char* code;
    int price;
    FILE image;
    char* type;
    char* description;
    char* productType;
};

Accessory* newAccessory(char* name, char* code, int price, FILE image, char* type , char* description);
void destroyAccessory(Accessory* accessory1);

#endif //GRUPO2_C_PRODUCT_H
