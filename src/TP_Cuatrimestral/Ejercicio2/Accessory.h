//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_ACCESSORY_H
#define GRUPO2_C_ACCESSORY_H

typedef struct accessory Accessory;

struct accessory {
    char* type;
    char* description;
};

Accessory* newAccessory(char* type , char* description);
void annihilateAccessory(Accessory* accessory1);

#endif //GRUPO2_C_ACCESSORY_H
