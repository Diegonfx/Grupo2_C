//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_LOAN_H
#define GRUPO2_C_LOAN_H

#include "Library.h"

typedef struct loan Loan;

struct loan {
    char* code;
    char* id;
    char* dateTaken;
    char* dateDueReturn;
};

Loan* newLoan(char* code, char* id ,Library* library1);
void destroyLoan(Loan *loan1);

#endif //GRUPO2_C_LOAN_H
