//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_LIBRARY_H
#define GRUPO2_C_LIBRARY_H

#include "Material.h"
#include "Person.h"
#include "Loan.h"

typedef struct library Library;

struct library {
    char* name;
    Book** booksRegistered;
    int booksQuantity;
    Magazine** magazinesRegistered;
    int magazineQuantity;
    Student** studentsRegistered;
    int studentQuantity;
    Professor** professorsRegistered;
    int professorQuantity;
    Loan** transactionsMade;
    int loanQuantity;
};

Library* newLibrary(char* name);
void annihilateLibrary(Library* library);
void addBook(Book* book1 , Library* library1);
void addMagazine(Magazine* magazine1, Library* library1);
void addStudent(Student* student1, Library* library1);
void addProfessor(Professor* professor1, Library* library1);
void addLoan(Loan* loan1, Library* library1);

#endif //GRUPO2_C_LIBRARY_H
