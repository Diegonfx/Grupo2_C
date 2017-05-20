//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_LINETICKET_H
#define GRUPO2_C_LINETICKET_H

typedef struct lineTicket LineTicket;

struct lineTicket {
    char* id;
    char* item;
    int units;
};

LineTicket* newLineTicket(char* id, char* item, int units);
void annihilateLineTicket(LineTicket* lineTicket1);

#endif //GRUPO2_C_LINETICKET_H
