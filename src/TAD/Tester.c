//
// Created by Diego Mancini on 17/3/17.
//

#include "ComplexNumber.h"
#include "stdlib.h"
#include "stdio.h"

int main() {

    ComplexNumber* complexNumber1 = createComplexNumber(10 , 4 );
    ComplexNumber* complexNumber2 = createComplexNumber(6 , 2 );

    printf("This is the TAD exercise of: 'Complex Number' into display. ");

    printComplex(complexNumber1);
    printComplex(complexNumber2);

    add(complexNumber1 , complexNumber2);
    printf("\n AFTER THE SUM PROCESS");
    printComplex(complexNumber1);

    substract(complexNumber1 , complexNumber2);
    printf("\n AFTER THE SUBSTRACT PROCESS");
    printComplex(complexNumber1);

    multiply(complexNumber1 , complexNumber2);
    printf("\n AFTER THE MULTIPLY PROCESS");
    printComplex(complexNumber1);

    divide(complexNumber1 , complexNumber2);
    printf("\n AFTER THE DIVIDE PROCESS");
    printComplex(complexNumber1);

    printf("\n THE ABSOLUTE VALUE IS: ");
    getAbsoluteValue(complexNumber1);
    printf("%f \n ", getAbsoluteValue(complexNumber1));

    // TP Memoria dinamica

    int a = 10;
    int* b;
    b = &a;
    *b = 1;
    printf("\nvalue of a: %d" , a);
    printf("\nvalue of *b: %d" , *b);

    int c,d, *e;
    e = &c;
    *e = 10;
    printf("\nvalue of c: %d" , c);
    printf("\nvalue of *e:  %d" , *e);
    e = &d;
    *e = -2;
    printf("\nvalue of d: %d" , d);
    printf("\nvalue of *e: %d" , *e);

    destroyComplexNumber(complexNumber1);
    destroyComplexNumber(complexNumber2);

    return 0;
}


