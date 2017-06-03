/**
 * Implementation of a product (Camera and Accessory).
 * @authors Tomas Iturralde, Diego Mancini
 */

#include <stdlib.h>
#include <memory.h>
#include "Product.h"

//CAMERA
Camera* newCamera(char* name, char* code, int price, FILE image, int megapixels, int screenSize, int zoom){

    Camera* camera1 = malloc(sizeof(Camera));

    camera1->name = malloc(sizeof(char) * strlen(name)+1);
    camera1->code = malloc(sizeof(char) * strlen(code)+1);
    camera1->type = malloc(sizeof(char*) * 2);

    camera1->name = name;
    camera1->code = code;
    camera1->price = price;
    camera1->image = image;
    camera1->megapixels = megapixels;
    camera1->screenSize = screenSize;
    camera1->zoom = zoom;
    camera1->type[0] = "Reflex";
    camera1->type[1] = "Compact";

    strcpy(camera1->name, name);
    strcpy(camera1->code,  code);

    return camera1;
}

void destroyCamera(Camera* camera1){
    free(camera1->name);
    free(camera1->code);
    free(camera1->type[0]);
    free(camera1->type[1]);
    free(camera1->type);
    free(camera1);
}

//ACCESSORY
Accessory* newAccessory(char* name, char* code, int price, FILE image, char* type , char* description){

    Accessory* result = malloc(sizeof(Accessory));

    result->name = malloc(sizeof(char) * strlen(name)+1);
    result->code = malloc(sizeof(char) * strlen(code)+1);
    result->type = malloc(sizeof(char) * strlen(type)+1);
    result->description = malloc(sizeof(char) * strlen(description)+1);

    result->name = name;
    result->code = code;
    result->price = price;
    result->image = image;
    result->type = type;
    result->description = description;

    strcpy(result->name, name);
    strcpy(result->code,  code);
    strcpy(result->type , type);
    strcpy(result->description, description);

    return result;
}

void destroyAccessory(Accessory* accessory){
    free(accessory->name);
    free(accessory->code);
    free(accessory->type);
    free(accessory->description);
    free(accessory);
}
