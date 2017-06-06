//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_ROOM_H
#define GRUPO2_C_ROOM_H

typedef struct room Room ;

struct room {
    int roomNumber;
    char* type;
    int price;
};

Room* newRoom(int roomNumber, char* type , int price);
void destroyRoom(Room* room1);

#endif //GRUPO2_C_ROOM_H
