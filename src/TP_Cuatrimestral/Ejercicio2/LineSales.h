//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_LINESALES_H
#define GRUPO2_C_LINESALES_H

typedef struct lineSales LineSales;

struct lineSales {
    char* code;
    int amount;
};

LineSales* newLineSales(char* code, int amount);
void annihilateLineSales(LineSales* lineSales1);

#endif //GRUPO2_C_LINESALES_H
