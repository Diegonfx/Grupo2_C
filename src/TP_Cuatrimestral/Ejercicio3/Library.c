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

}

void annihilateLibrary(Library* library){
    free(library->name);
    for (int i = 0; i < library->booksQuantity; i++) {
        annihilateBook(library->booksRegistered[i]);
    }
    for (int j = 0; j < library->magazineQuantity; j++) {
        annihilateMagazine(library->magazinesRegistered[j]);
    }
    for (int k = 0; k < library->studentQuantity; k++) {
        annihilateStudent(library->studentsRegistered[k]);
    }
    for (int l = 0; l < library->professorQuantity; l++) {
        annihilateProfessor(library->professorsRegistered[l]);
    }
    for (int m = 0; m < library->loanQuantity; m++) {
        annihilateLoan(library->transactionsMade[m]);
    }
    free(library);
}