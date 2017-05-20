//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_MANUFACTURER_H
#define GRUPO2_C_MANUFACTURER_H

typedef struct producer Producer;

struct producer {
    char* name;
    char* code;
};

Producer* newProducer(char* name , char* code);
void annihilateProducer(Producer* manufacturer);

#endif //GRUPO2_C_MANUFACTURER_H
