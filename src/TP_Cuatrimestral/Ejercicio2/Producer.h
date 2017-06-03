/**
 * Implementation of a producer.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#ifndef GRUPO2_C_MANUFACTURER_H
#define GRUPO2_C_MANUFACTURER_H

#include "Product.h"

typedef struct producer Producer;

struct producer {
    char* name;
    char* code;
    Camera** listOfCameras;
    int amountOfCameras;
    int maxCapacityOfCameras;
    Accessory** listOfAccessories;
    int amountOfAccessories;
    int maxCapacityOfAccessories;
};

Producer* newProducer(char* name , char* code);
void growListOfCameras(Producer* producer1);
void produceCamera(char* name, char* code, int price, FILE image, int megapixels, int screenSize, int zoom, Producer* producer1);
void emptyListOfCameras(Producer* producer1);
void growListOfAccessories(Producer* producer1);
void produceAccessory(char* name, char* code, int price, FILE image, char* type , char* description, Producer* producer1);
void emptyListOfAccessories(Producer* producer1);
void destroyProducer(Producer* producer1);

#endif //GRUPO2_C_MANUFACTURER_H
