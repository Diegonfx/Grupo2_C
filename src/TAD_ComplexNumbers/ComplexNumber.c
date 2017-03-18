
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ComplexNumber.h"
#include "math.h"

/*
    Creates a complex number from scratch, where the first number is the real part , the second is the imaginary
    part and the last character is the letter 'i' stating that is the imaginary part.
 */
ComplexNumber* createComplexNumber(double realPart , double imaginaryPart){
    ComplexNumber* result = malloc(sizeof(ComplexNumber));

    result -> realPart = realPart;
    result -> imaginaryPart = imaginaryPart;

    return result;
}

/*
    Sums the second complex number to the first complex number.
 */
void add(ComplexNumber* myComplex , ComplexNumber* anyComplex){
    myComplex->realPart = myComplex->realPart + anyComplex->realPart;
    myComplex->imaginaryPart = myComplex->imaginaryPart + anyComplex->imaginaryPart;
}

/*
    Substracts the second complex number to the first complex number.
 */
void substract(ComplexNumber* myComplex , ComplexNumber* anyComplex){
    myComplex->realPart = myComplex->realPart - anyComplex->realPart;
    myComplex->imaginaryPart = myComplex->imaginaryPart - anyComplex->imaginaryPart;
}

/*
    Multiplies the second complex number to the first complex number.
 */
void multiply(ComplexNumber* myComplex , ComplexNumber* anyComplex){
    myComplex->realPart = (myComplex->realPart * anyComplex->realPart) - (myComplex->imaginaryPart * anyComplex->imaginaryPart);
    myComplex->imaginaryPart = myComplex->imaginaryPart + anyComplex->imaginaryPart;
}

/*
    Divides the second complex number to the first complex number.
 */
void divide(ComplexNumber* myComplex , ComplexNumber* anyComplex){
    myComplex->realPart = (myComplex->realPart * anyComplex->realPart + myComplex->imaginaryPart * anyComplex->imaginaryPart) / (anyComplex->realPart * anyComplex->realPart + anyComplex->imaginaryPart * anyComplex->imaginaryPart);
    myComplex->imaginaryPart = (myComplex->imaginaryPart * anyComplex->realPart - myComplex->realPart * anyComplex->imaginaryPart)/(anyComplex->realPart * myComplex->realPart + anyComplex->imaginaryPart * anyComplex->imaginaryPart);
}

/*
    Retrieves the absolute value (module) of the desired complex number.
 */
double getAbsoluteValue(ComplexNumber* myComplex){
    double absoluteValue = (sqrt (pow(myComplex->realPart , 2)) + (pow(myComplex->imaginaryPart , 2)));
    return absoluteValue;
}

/*
    Prints the complex number in its totality.
 */
void printComplex(ComplexNumber* myComplex){

    printf( "\nMy complex number is formed by --> Real part: %.2f || Imaginary part: %.2fi --------- Therefore the number is = %2.f +(%2.f)i \n" , myComplex->realPart , myComplex->imaginaryPart, myComplex->realPart , myComplex->imaginaryPart);

}

/*
    Frees the memory space where the complex number is being stored at.
 */
void destroyComplexNumber(ComplexNumber* myComplex) {
    free(myComplex);
}