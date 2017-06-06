//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include <printf.h>
#include "Library.h"


Library* newLibrary(char* name){

    Library* library1 = malloc(sizeof(Library));

    library1->name = malloc(sizeof(char) * strlen(name) + 1);
    library1->booksRegistered = malloc(sizeof(Book*) * 10);
    library1->magazinesRegistered = malloc(sizeof(Magazine*) * 10);
    library1->studentsRegistered = malloc(sizeof(Student*) * 10);
    library1->professorsRegistered = malloc(sizeof(Professor*) * 10);
    library1->transactionsMade = malloc(sizeof(Loan*) * 10);

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
        realloc(library1->booksRegistered, sizeof(Book*) *10);
    }
        library1->booksRegistered[library1->booksQuantity] = book1;
        library1->booksQuantity++;

}

void addMagazine(Magazine* magazine1, Library* library1){
    if(library1->magazineQuantity % 10 == 0) {
        realloc(library1->magazinesRegistered, sizeof(Magazine*) *10);
    }
        library1->magazinesRegistered[library1->magazineQuantity] = magazine1;
        library1->magazineQuantity++;

}

void addStudent(Student* student1, Library* library1){
    if(library1->studentQuantity % 10 == 0) {
        realloc(library1->studentsRegistered, sizeof(Student*) *10);
    }
        library1->studentsRegistered[library1->studentQuantity] = student1;
        library1->studentQuantity++;

}

void addProfessor(Professor* professor1, Library* library1){
    if(library1->professorQuantity % 10 == 0) {
        realloc(library1->professorsRegistered, sizeof(Professor*) *10);
    }
        library1->professorsRegistered[library1->professorQuantity] = professor1;
        library1->professorQuantity++;

}

void addLoan(Loan* loan1, Library* library1){
    if(library1->loanQuantity % 10 == 0) {
        realloc(library1->transactionsMade, sizeof(Loan*) *10);
    }
        library1->transactionsMade[library1->loanQuantity] = loan1;
        library1->loanQuantity++;

}

void rentBookStudent(Book* book1, Library* library1 , Student* student1, char* taken , char* returndate) {
    Loan* loan1;
    for (int i = 0; i < library1->booksQuantity; ++i) {
        if (library1->booksRegistered[i]->codeISBN== book1->codeISBN) {
            book1->status = "TAKEN";
            loan1 = newLoan(book1->codeISBN , student1->idStudent);
            loan1->dateTaken = taken;
            loan1->dateDueReturn = returndate;
            addLoan(loan1 , library1);
            student1->amountBooks++;
        }
    }
}

void rentMagazineStudent(Magazine* magazine1, Library* library1, Student* student1, char* taken , char* returndate){
    Loan* loan1;
    for (int i = 0; i < library1->magazineQuantity; ++i) {
        if (library1->magazinesRegistered[i]->codeISBN == magazine1->codeISBN) {
            magazine1->status = "TAKEN";
            loan1 = newLoan(magazine1->codeISBN , student1->idStudent);
            loan1->dateTaken = taken;
            loan1->dateDueReturn = returndate;
            addLoan(loan1 , library1);
            student1->amountMagazines++;
        }
    }
}

void rentBookProfessor(Book* book1, Library* library1 , Professor* professor, char* taken , char* returndate){
    Loan* loan1;
    for (int i = 0; i < library1->booksQuantity; ++i) {
        if (library1->booksRegistered[i]->codeISBN == book1->codeISBN) {
            book1->status = "TAKEN";
            loan1  = newLoan(book1->codeISBN , professor->idProfessor);
            loan1->dateTaken = taken;
            loan1->dateDueReturn = returndate;
            addLoan(loan1 , library1);
            professor->amountBooks++;
        }
    }
}

void rentMagazineProfessor(Magazine* magazine1, Library* library1, Professor* professor1, char* taken , char* returndate){
    Loan* loan1;

    for (int i = 0; i < library1->magazineQuantity; ++i) {
        if (library1->magazinesRegistered[i]->codeISBN == magazine1->codeISBN) {
            magazine1->status = "TAKEN";
            loan1  = newLoan(magazine1->codeISBN , professor1->idProfessor);
            loan1->dateTaken = taken;
            loan1->dateDueReturn = returndate;
            addLoan(loan1 , library1);
            professor1->amountMagazines++;
        }
    }

}

void returnBookStudent(Book* book1 , Library* library1 , Student* student1) {
    for (int i = 0; i < library1->booksQuantity; ++i) {
        if (library1->booksRegistered[i]->codeISBN == book1->codeISBN) {
            book1->status = "NOT TAKEN";
            student1->amountBooks--;
        }
    }
}

void returnMagazineStudent(Magazine* magazine1, Library* library1 , Student* student1) {
    for (int i = 0; i < library1->magazineQuantity; ++i) {
        if (library1->magazinesRegistered[i]->codeISBN == magazine1->codeISBN) {
            magazine1->status = "NOT TAKEN";

            student1->amountMagazines--;
        }
    }
}

void returnBookProfessor(Book* book1, Library* library1 , Professor* professor){
    for (int i = 0; i < library1->booksQuantity; ++i) {
        if (library1->booksRegistered[i]->codeISBN == book1->codeISBN) {
            book1->status = "NOT TAKEN";
            professor->amountBooks--;
        }
    }
}

void returnMagazineProfessor(Magazine* magazine1, Library* library1, Professor* professor1){
    for (int i = 0; i < library1->magazineQuantity; ++i) {
        if (library1->magazinesRegistered[i]->codeISBN == magazine1->codeISBN) {
            magazine1->status = "NOT TAKEN";
            professor1->amountMagazines--;
        }
    }
}

void printInfo(Library* library1) {
    printf("\n---- PROFESSORS ----\n");
    if (library1->professorQuantity == 0) {
        printf("EMPTY");
    } else {
        for (int j = 0; j < library1->professorQuantity; ++j) {
            printf("\nProfessor %d --> Name: %s %s ||| ID: %d \n", j+1, library1->professorsRegistered[j]->name,
                   library1->professorsRegistered[j]->surname, library1->professorsRegistered[j]->idProfessor);
        }
    }
    printf("\n---- STUDENTS ----\n");
    if (library1->studentQuantity == 0) {
        printf("EMPTY\n");
    } else {
        for (int j = 0; j < library1->studentQuantity; ++j) {
            printf("\nStudent %d --> Name: %s %s ||| ID: %d \n", j+1, library1->studentsRegistered[j]->name,
                   library1->studentsRegistered[j]->surname, library1->studentsRegistered[j]->idStudent);
        }
    }
    printf("\n---- BOOKS ----\n");
    if (library1->booksQuantity == 0) {
        printf("EMPTY\n");
    } else {
        for (int k = 0; k < library1->booksQuantity; ++k) {
            printf("\nBook %d --> Name: %s ||| Author: %s ||| ISBN: %d ||| Status: %s \n", k+1,
                   library1->booksRegistered[k]->title, library1->booksRegistered[k]->author,
                   library1->booksRegistered[k]->codeISBN, library1->booksRegistered[k]->status);
        }
    }
    printf("\n---- MAGAZINES ----\n");
    if (library1->magazineQuantity == 0) {
        printf("EMPTY\n");
    } else {
        for (int l = 0; l < library1->magazineQuantity; ++l) {
            printf("\nMagazine %d --> Name: %s ||| Author: %s ||| ISBN: %d ||| Status: %s \n", l+1,
                   library1->magazinesRegistered[l]->title, library1->magazinesRegistered[l]->author,
                   library1->magazinesRegistered[l]->codeISBN, library1->magazinesRegistered[l]->status);
        }
    }
    printf("\n---- LOANS ----\n");
    if (library1->loanQuantity == 0) {
        printf("EMPTY\n");
    } else {
        for (int m = 0; m < library1->loanQuantity; ++m) {
            printf("\nLoan %d --> Code: %d ||| ID: %d ||| Date taken: %s ||| Date return: %s ", m+1,
                   library1->transactionsMade[m]->code, library1->transactionsMade[m]->id,
                   library1->transactionsMade[m]->dateTaken, library1->transactionsMade[m]->dateDueReturn);
        }
    }
}

void loadDatabase(Library* library1) {

    Student* student1 = newStudent("student" , "number 1" , "email 1" , 111, 123);
    Student* student2 = newStudent("student" , "number 2" , "email 2" , 222, 456);
    Student* student3 = newStudent("student" , "number 3" , "email 3" , 333, 789);

    Professor* professor1 = newProfessor("professor" , "number 4" , "email 1" , 444 , 133);
    Professor* professor2 = newProfessor("professor" , "number 5" , "email 2" , 555 , 233);

    Book* book1 = newBook(1111 , "book" , "number 1" , 111 , "editorialA");
    Book* book2 = newBook(2222 , "book" , "number 2" , 222 , "editorialB");
    Book* book3 = newBook(3333 , "book" , "number 3" , 333 , "editorialC");
    Book* book4 = newBook(4444 , "book" , "number 4" , 444 , "editorialD");
    Book* book5 = newBook(5555 , "book" , "number 5" , 555 , "editorialE");

    Magazine* magazine1 = newMagazine(1111, "magazine" , "number 1" , 111 );
    Magazine* magazine2 = newMagazine(2222 , "magazine" , "number 2" , 222);
    Magazine* magazine3 = newMagazine(3333, "magazine" , "number 3" , 333 );
    Magazine* magazine4 = newMagazine(4444 , "magazine" , "number 4" , 444);
    Magazine* magazine5 = newMagazine(5555, "magazine" , "number 5" , 555 );

    addBook(book1 , library1);
    addBook(book2 , library1);
    addBook(book3 , library1);
    addBook(book4 , library1);
    addBook(book5 , library1);

    addStudent(student1 , library1);
    addStudent(student2 , library1);
    addStudent(student3 , library1);

    addProfessor(professor1 , library1);
    addProfessor(professor2 , library1);

    addMagazine(magazine1 , library1);
    addMagazine(magazine2 , library1);
    addMagazine(magazine3 , library1);
    addMagazine(magazine4 , library1);
    addMagazine(magazine5 , library1);

    char* taken1 = "Today";
    char* return2 = "NEVER";

    rentBookStudent(book1 , library1 , student1 , taken1 , return2);
    rentMagazineProfessor(magazine1 , library1 , professor1 , taken1, return2);
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
    for (int m = 0; m < library->loanQuantity ; m++) {
        destroyLoan(library->transactionsMade[m]);
    }

    free(library);
}