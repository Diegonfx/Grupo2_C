//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Library.h"


Library* newLibrary(char* name){

    Library* library1 = malloc(sizeof(Library));

    library1->name = malloc(sizeof(char) * strlen(name));
    library1->booksRegistered = malloc(sizeof(Book*) * 10);
    library1->magazinesRegistered = malloc(sizeof(Magazine*) * 10);
    library1->studentsRegistered = malloc(sizeof(Student*) * 10);
    library1->professorsRegistered = malloc(sizeof(Professor*) * 10);
    library1->transactionsMade = malloc(sizeof(Loan*) * 10);

    library1->name = name;
    library1->booksQuantity = 0;
    library1->magazineQuantity = 0;
    library1->studentQuantity = 0;
    library1->professorQuantity = 0;
    library1->loanQuantity = 0;

    strcpy(library1->name,name);

    return library1;

}

void addBook(Book* book1 , Library* library1){
    if(library1->booksQuantity % 10 == 0) {
        realloc(library1->booksRegistered, sizeof(Book*) +10);
    } else {
        library1->booksRegistered[library1->booksQuantity] = book1;
        library1->booksQuantity++;
    }
}

void addMagazine(Magazine* magazine1, Library* library1){
    if(library1->magazineQuantity % 10 == 0) {
        realloc(library1->magazinesRegistered, sizeof(Magazine*) +10);
    } else {
        library1->magazinesRegistered[library1->magazineQuantity] = magazine1;
        library1->magazineQuantity++;
    }
}

void addStudent(Student* student1, Library* library1){
    if(library1->studentQuantity % 10 == 0) {
        realloc(library1->studentsRegistered, sizeof(Student*) +10);
    } else {
        library1->studentsRegistered[library1->studentQuantity] = student1;
        library1->studentQuantity++;
    }
}

void addProfessor(Professor* professor1, Library* library1){
    if(library1->professorQuantity % 10 == 0) {
        realloc(library1->professorsRegistered, sizeof(Professor*) +10);
    } else {
        library1->professorsRegistered[library1->professorQuantity] = professor1;
        library1->professorQuantity++;
    }
}

void addLoan(Loan* loan1, Library* library1){
    if(library1->loanQuantity % 10 == 0) {
        realloc(library1->transactionsMade, sizeof(Loan*) +10);
    } else {
        library1->transactionsMade[library1->loanQuantity] = loan1;
        library1->loanQuantity++;
    }
}

void rentBookStudent(Book* book1, Library* library1 , Student* student1) {
    Loan* loan1 = newLoan(book1->codeISBN , student1->idStudent , library1);
    student1->amountBooks++;
    book1->status = "Taken";
    library1->loanQuantity++;
    for (int i = 0; i < library1->booksQuantity; ++i) {
        if (strcmp(book1->codeISBN , (const char *) library1->booksRegistered[i]) == 0) {
            library1->booksRegistered[i] = NULL;
            library1->booksQuantity--;
        }
    }
    addLoan(loan1 , library1);
}

void rentMagazineStudent(Magazine* magazine1, Library* library1, Student* student1){
    Loan* loan1 = newLoan(magazine1->codeISBN , student1->idStudent , library1);
    student1->amountMagazines++;
    magazine1->status = "Taken";
    library1->loanQuantity++;
    for (int i = 0; i < library1->magazineQuantity; ++i) {
        if (strcmp(magazine1->codeISBN , (const char *) library1->magazinesRegistered[i]) == 0) {
            library1->magazinesRegistered[i] = NULL;
            library1->magazineQuantity--;
        }
    }
    addLoan(loan1 , library1);
}

void rentBookProfessor(Book* book1, Library* library1 , Professor* professor){
    Loan* loan1 = newLoan(book1->codeISBN , professor->idProfessor , library1);
    professor->amountBooks++;
    book1->status = "Taken";
    library1->loanQuantity++;
    for (int i = 0; i < library1->booksQuantity; ++i) {
        if (strcmp(book1->codeISBN , (const char *) library1->booksRegistered[i]) == 0) {
            library1->booksRegistered[i] = NULL;
            library1->booksQuantity--;
        }
    }
    addLoan(loan1 , library1);
}

void rentMagazineProfessor(Magazine* magazine1, Library* library1, Professor* professor1){
    Loan* loan1 = newLoan(magazine1->codeISBN , professor1->idProfessor , library1);
    professor1->amountMagazines++;
    magazine1->status = "NOT TAKEN";
    library1->loanQuantity++;
    for (int i = 0; i < library1->magazineQuantity; ++i) {
        if (strcmp(magazine1->codeISBN , (const char *) library1->magazinesRegistered[i]) == 0) {
            library1->magazinesRegistered[i] = NULL;
            library1->magazineQuantity--;
        }
    }
    addLoan(loan1 , library1);

}

void returnBookStudent(Book* book1 , Library* library1 , Student* student1) {
    addBook(book1 , library1);
    student1->amountBooks--;
}

void returnMagazineStudent(Magazine* magazine1, Library* library1 , Student* student1) {
    addMagazine(magazine1, library1);
    student1->amountMagazines--;
}

void returnBookProfessor(Book* book1, Library* library1 , Professor* professor){
    addBook(book1 , library1);
    professor->amountBooks--;
}

void returnMagazineProfessor(Magazine* magazine1, Library* library1, Professor* professor1){
    addMagazine(magazine1, library1);
    professor1->amountMagazines--;
}


void destroyLibrary(Library* library){
    free(library->name);
    for (int i = 0; i < library->booksQuantity; i++) {
        destroyBook(library->booksRegistered[i]);
    }
    for (int j = 0; j < library->magazineQuantity; j++) {
        destroyMagazine(library->magazinesRegistered[j]);
    }
    for (int k = 0; k < library->studentQuantity; k++) {
        destroyStudent(library->studentsRegistered[k]);
    }
    for (int l = 0; l < library->professorQuantity; l++) {
        destroyProfessor(library->professorsRegistered[l]);
    }
    for (int m = 0; m < library->loanQuantity; m++) {
        destroyLoan(library->transactionsMade[m]);
    }
    free(library);
}