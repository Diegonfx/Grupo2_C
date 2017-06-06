//
// Created by Diego Mancini on 2/6/17.
//

#ifndef GRUPO2_C_IDCARD_H
#define GRUPO2_C_IDCARD_H

typedef struct idCard IDcard;

struct idCard {
    int id;
};

IDcard* newIDcard(int id);
void destroyIDcard(IDcard* iDcard);


#endif //GRUPO2_C_IDCARD_H
