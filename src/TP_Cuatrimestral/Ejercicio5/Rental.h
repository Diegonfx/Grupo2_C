//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_RENTAL_H
#define GRUPO2_C_RENTAL_H

typedef struct rental Rental;

struct rental {
    char* movieName;
    int id;
    char* rentalDate;
    char* rentalReturn;
};

Rental* newRental(char* movieName ,char* rentalDate, char* returnDate);
void destroyRental(Rental* rental1);

#endif //GRUPO2_C_RENTAL_H
