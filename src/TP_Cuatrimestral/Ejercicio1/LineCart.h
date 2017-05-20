//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_LINECART_H
#define GRUPO2_C_LINECART_H

typedef struct lineCart LineCart;

struct lineCart {
    char* id;
    char* item;
    int units;
};

LineCart* newLineCart(char* id, char* item, int units);
void annihilateLineCart(LineCart* lineCart1);

#endif //GRUPO2_C_LINECART_H
