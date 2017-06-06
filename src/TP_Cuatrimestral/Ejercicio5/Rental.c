//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include <printf.h>
#include "Rental.h"

Rental* newRental(char* movieName ,char* rentalDate, char* returnDate ) {
    Rental* rental1 = malloc(sizeof(Rental));

    rental1->movieName = malloc(sizeof(char) * strlen(movieName) + 1);
    rental1->rentalDate = malloc(sizeof(char) * strlen(rentalDate) + 1);
    rental1->rentalReturn = malloc(sizeof(char) * strlen(returnDate) + 1);

    rental1->id = 0;

    strcpy(rental1->movieName , movieName);
    strcpy(rental1->rentalDate , rentalDate);
    strcpy(rental1->rentalReturn , returnDate);

    return rental1;
}

void destroyRental(Rental* rental1) {
    free(rental1->movieName);
    free(rental1->rentalDate);
    free(rental1->rentalReturn);
    free(rental1);
}