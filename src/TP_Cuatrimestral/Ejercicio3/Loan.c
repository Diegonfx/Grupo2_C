//
// Created by Diego Mancini on 19/5/17.
//

#include <sys/time.h>
#include <stdlib.h>
#include <memory.h>
#include "Loan.h"
#include "Library.h"

Loan* newLoan(char* code, char* id , Library* library){

    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    Loan* loan1 = malloc(sizeof(Loan));
    loan1->code = malloc(sizeof(char) * strlen(code));
    loan1->id = malloc(sizeof(char) * strlen(id));
    loan1->code = malloc(sizeof(char) * strlen(code));
    loan1->dateTaken = malloc(sizeof(char) * 20);
    loan1->dateDueReturn = malloc(sizeof(char) * 20);

    loan1->code = code;
    loan1->id = id;
    loan1->dateTaken = asctime(timeinfo);
    timeinfo += 24*7*60*60;
    loan1->dateDueReturn = asctime(timeinfo);

    strcpy(loan1->code , code);
    strcpy(loan1->id , id);

    return loan1;
}

void destroyLoan(Loan *loan1){
    free(loan1->code);
    free(loan1->id);
    free(loan1->dateTaken);
    free(loan1->dateDueReturn);
    free(loan1);
}