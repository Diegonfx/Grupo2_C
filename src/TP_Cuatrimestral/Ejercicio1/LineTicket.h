/**
 * Declaration of a lineTicket.
 * @authors Tomas Iturralde, Diego Mancini.
 */

#ifndef GRUPO2_C_LINETICKET_H
#define GRUPO2_C_LINETICKET_H

#include "Item.h"

typedef struct lineTicket LineTicket;

struct lineTicket {
    char* id;
    int units;
    Item* item;
};

LineTicket* newLineTicket(char* id, Item* item, int units);
void generateLineTicket(LineTicket* lineTicket1);
void destroyLineTicket(LineTicket* lineTicket1);

#endif //GRUPO2_C_LINETICKET_H