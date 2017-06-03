/**
 * Declaration of a producer.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#include <stdlib.h>
#include <memory.h>
#include "Producer.h"

Producer* newManufacturer(char* name , char* code){

    Producer* producer1 = malloc(sizeof(Producer));

    producer1->code = malloc(sizeof(char) * strlen(code)+1);
    producer1->name = malloc(sizeof(char) * strlen(name)+1);
    producer1->maxCapacityOfCameras = 10;
    producer1->listOfCameras = malloc(sizeof(Camera*) * producer1->maxCapacityOfCameras);
    producer1->maxCapacityOfAccessories = 10;
    producer1->listOfAccessories = malloc(sizeof(Accessory*) * producer1->maxCapacityOfAccessories);

    producer1->name = name;
    producer1->code = code;
    producer1->amountOfCameras = 0;
    producer1->amountOfAccessories = 0;

    strcpy(producer1->name, name);
    strcpy(producer1->code,  code);

    return producer1;
}

/**
 * Expands the amount of cameras a producer can store.
 * @param producer1 whose cameras' list will be expanded.
 */
void growListOfCameras(Producer* producer1){
    producer1->listOfCameras = realloc(producer1->listOfCameras, sizeof(Camera*) * (producer1->maxCapacityOfCameras*2));
    producer1->maxCapacityOfCameras *= 2;
}

/**
 * Make a camera.
 * @return the produced camera.
 */
void produceCamera(char* name, char* code, int price, FILE image, int megapixels, int screenSize, int zoom, Producer* producer1){
    if (producer1->amountOfCameras == producer1->maxCapacityOfCameras) growListOfCameras(producer1);
    producer1->listOfCameras[producer1->amountOfCameras] = newCamera(name, code, price, image, megapixels, screenSize, zoom);
    producer1->amountOfCameras++;
}

/**
 * Empties the list of cameras inside a producer.
 * @param producer1 whose cameras' list will be emptied.
 */
void emptyListOfCameras(Producer* producer1){
    producer1->amountOfCameras = 0;
}

/**
 * Expands the amount of accessories a producer can store.
 * @param producer1 whose accessories' list will be expanded.
 */
void growListOfAccessories(Producer* producer1){
    producer1->listOfAccessories = realloc(producer1->listOfAccessories, sizeof(Accessory*) * (producer1->maxCapacityOfAccessories*2));
    producer1->maxCapacityOfAccessories *= 2;
}

/**
 * Make an accessory.
 * @return the produced accessory.
 */
void produceAccessory(char* name, char* code, int price, FILE image, char* type , char* description, Producer* producer1){
    if (producer1->amountOfAccessories == producer1->maxCapacityOfAccessories) growListOfAccessories(producer1);
    producer1->listOfAccessories[producer1->amountOfAccessories] = newAccessory(name, code, price, image, type, description);
    producer1->amountOfAccessories++;
}

/**
 * Empties the list of accessories inside a producer.
 * @param producer1 whose accessories' list will be emptied.
 */
void emptyListOfAccessories(Producer* producer1){
    producer1->amountOfAccessories = 0;
}

void destroyProducer(Producer* producer){
    free(producer->name);
    free(producer->code);
    for (int i = 0; i < producer->maxCapacityOfCameras; ++i) {
        destroyCamera(producer->listOfCameras[i]);
    }
    free(producer->listOfCameras);
    for (int j = 0; j < producer->maxCapacityOfAccessories; ++j) {
        destroyAccessory(producer->listOfAccessories[j]);
    }
    free(producer->listOfAccessories);
    free(producer);
}