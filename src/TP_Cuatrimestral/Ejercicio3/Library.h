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

void addBook(Book* book1 , Library* library1);
void addMagazine(Magazine* magazine1, Library* library1);
void addStudent(Student* student1, Library* library1);
void addProfessor(Professor* professor1, Library* library1);
void addLoan(Loan* loan1, Library* library1);

void rentBookStudent(Book* book1, Library* library1 , Student* student1);
void rentMagazineStudent(Magazine* magazine1, Library* library1, Student* student1);
void rentBookProfessor(Book* book1, Library* library1 , Professor* professor);
void rentMagazineProfessor(Magazine* magazine1, Library* library1, Professor* professor1);

void returnBookStudent(Book* book1, Library* library1 , Student* student1);
void returnMagazineStudent(Magazine* magazine1, Library* library1 , Student* student1);
void returnBookProfessor(Book* book1, Library* library1 , Professor* professor);
void returnMagazineProfessor(Magazine* magazine1, Library* library1, Professor* professor1);

void destroyLibrary(Library* library);

#endif //GRUPO2_C_LIBRARY_H
