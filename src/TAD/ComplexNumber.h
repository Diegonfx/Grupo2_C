//
// Created by Diego Mancini on 17/3/17.
//

#ifndef AYED_COMPLEXNUMBER_H
#define AYED_COMPLEXNUMBER_H

typedef struct complexNumber ComplexNumber;

struct complexNumber {

    double realPart;
    double imaginaryPart;

};

ComplexNumber* createComplexNumber(double realPart , double imaginaryPart);
void add(ComplexNumber* myComplex , ComplexNumber* anyComplex);
void substract(ComplexNumber* myComplex , ComplexNumber* anyComplex);
void multiply(ComplexNumber* myComplex , ComplexNumber* anyComplex);
void divide(ComplexNumber* myComplex , ComplexNumber* anyComplex);
double getAbsoluteValue(ComplexNumber* myComplex);
void printComplex(ComplexNumber* myComplex);
void destroyComplexNumber(ComplexNumber* myComplex);

#endif //AYED_COMPLEXNUMBER_H
