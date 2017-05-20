//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_LOAN_H
#define GRUPO2_C_LOAN_H

typedef struct loan Loan;

struct loan {
    char* code;
    char* id;
    char* dateTaken;
    char* dateDueReturn;
};

Loan* newLoan(char* code, char* id , char* dateTaken , char* dateDueReturn);
void annihilateLoan(Loan* loan1);

#endif //GRUPO2_C_LOAN_H
