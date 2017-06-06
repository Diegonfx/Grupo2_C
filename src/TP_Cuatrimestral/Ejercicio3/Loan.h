//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_LOAN_H
#define GRUPO2_C_LOAN_H

typedef struct loan Loan;

struct loan {
    int code;
    int id;
    char* dateTaken;
    char* dateDueReturn;
};

Loan* newLoan(int code, int id);
void destroyLoan(Loan *loan1);

#endif //GRUPO2_C_LOAN_H
