//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Room.h"

Room* newRoom(int roomNumber, char* type , int price){
    Room* room1 = malloc(sizeof(Room));

    room1->type = malloc(sizeof(char) * strlen(type));

    room1->roomNumber = roomNumber;
    room1->price = price;

    strcpy(room1->type , type);

    return room1;
}

void destroyRoom(Room* room1){
    free(room1->type);
    free(room1);
}