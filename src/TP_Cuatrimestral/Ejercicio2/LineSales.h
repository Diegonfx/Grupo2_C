/**
 * Declaration of a line inside a sale.
 * @authors Tomas Iturralde, Diego Mancini
 */

#ifndef GRUPO2_C_LINESALES_H
#define GRUPO2_C_LINESALES_H

#include "Product.h"

typedef struct lineSales LineSales;

struct lineSales {
    char* code;
    int units;
    Camera* camera1;
    Accessory* accessory1;
};

LineSales* newLineSalesCamera(char* code, Camera* camera1, int units);
LineSales* newLineSalesAccessory(char* code, Accessory* accessory1, int units);
void generateLineSalesCamera(LineSales* lineSales1);
void generateLineSalesAccessory(LineSales* lineSales1);
void destroyLineSales(LineSales* lineSales1);

#endif //GRUPO2_C_LINESALES_H
