//
// Created by Diego Mancini on 19/5/17.
//

#include <sys/time.h>
#include <stdlib.h>
#include <memory.h>
#include "Loan.h"

Loan* newLoan(int code, int id){

    Loan* loan1 = malloc(sizeof(Loan));
    loan1->dateTaken = malloc(sizeof(char) * 20);
    loan1->dateDueReturn = malloc(sizeof(char) * 20);

    loan1->code = code;
    loan1->dateTaken = "";
    loan1->dateDueReturn = "";
    loan1->id = id;


    return loan1;
}

void destroyLoan(Loan *loan1){
    free(loan1->dateTaken);
    free(loan1->dateDueReturn);
    free(loan1);
}