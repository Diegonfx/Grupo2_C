//
// Created by Diego Mancini on 17/3/17.
//


#include "Parking.h"
#include "Car.h"
#include <stdio.h>
#include <stdlib.h>

//int main(){
//
//    printf("Implementar el TAD \"número complejo\" en lenguaje C.\n"
//                   "\n"
//                   "El correcto diseño de un TAD, en un lenguaje estructurado como C,\n"
//                   "implica que las operaciones (funciones) del respectivo TAD se encuentran implementados en un módulo (archivo .h)\n"
//                   "y que el TAD (typedef struct) se encuentra implementado en el archivo que contiene la función main().\n"
//                   "Realizar un tester (main()) que utilice el TAD \"número complejo\" con sus respectivas operaciones.\n"
//                   "Este ejercicio es individual y se debe entregar impreso y virtual.");
//
//    Parking* parking = createParking(10);
//
//    printf("%d\n", amountOfCarsParked(parking));
//    if(isEmpty(parking)) printf("The parking is Empty\n");
//
//    parkCar(parking, createCar("AAA001", "Porsche", "Negro"));
//    parkCar(parking, createCar("AAA002", "Porsche", "Blanco"));
//    parkCar(parking, createCar("AAA003", "Porsche", "Rojo"));
//    parkCar(parking, createCar("AAA004", "Porsche", "Azul"));
//    parkCar(parking, createCar("AAA005", "Porsche", "Corsa"));
//
//    printf("%d\n", amountOfCarsParked(parking));
//
//    if(isCarParked(parking, createCar("AAB001", "Porsche", "Negro")) == 1){
//        printf("Car is parked\n");
//    }else{
//        printf("The Car is not parked\n");
//    }
//
//    printParking(parking);
//
//    removeCar(parking, 1);
//
//    printParking(parking);
//
//    return 0;
//}