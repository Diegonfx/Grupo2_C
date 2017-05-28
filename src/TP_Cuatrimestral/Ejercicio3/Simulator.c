//
// Created by Diego Mancini on 20/5/17.
//

#include <stdlib.h>
#include <stdio.h>
#include "Library.h"

int main() {
    Library* library = newLibrary("Austral");

    //VARIABLES
    int choice;
    char* name;
    char* surname;
    char* email;
    int idStudent , phone;
    char* name2;
    char* surname2;
    char* email2;
    int phone2;
    int idProfessor;
    char* code;
    char* author;
    char* title;
    char* editorial;
    int year;
    char* code2;
    char* author2;
    char* title2;
    int year2;
    Book* book2;
    Student* student2;
    int id;
    char* codeStudent;
    Book* book3;
    Student* student3;
    int id3;
    char* codeStudent2;
    Magazine* magazine2;
    Student* student4;
    int id2;
    char* codeStudent3;
    Magazine* magazine3;
    Student* student5;
    int id4;
    char* codeStudent4;
    Book* book4;
    Professor* professor2;
    int id5;
    char* codeProfessor2;
    Book* book5;
    Professor* professor3;
    int id6;
    char* codeProfessor3;
    Magazine* magazine4;
    Professor* professor4;
    int id7;
    char* codeProfessor4;
    Magazine* magazine5;
    Professor* professor5;
    int id8;
    char* codeProfessor5;

    while(choice!=7){

        printf("\n Welcome to the library, please choose an option\n" );
        printf("1- Add Student\n");
        printf("2- Add Teacher\n");
        printf("3- Add Book\n");
        printf("4- Add Magazine\n");
        printf("5- Rent book with a Student \n");
        printf("6- Return book with a Student \n");
        printf("7- Rent magazine with a Student \n");
        printf("8- Return magazine with a Student \n");
        printf("9- Rent book with a Professor \n");
        printf("10- Return book with a Professor \n");
        printf("11- Rent magazine with a Professor \n");
        printf("12- Return magazine with a Professor \n");
        printf("0- Exit\n");

        scanf("%d", &choice);

        switch(choice){

            case 0:

                exit(0);

            case 1:

                name = malloc(sizeof(char)*12);
                surname =  malloc(sizeof(char) * 12);
                email =  malloc(sizeof(char) * 20);
                printf("Enter name: \n");
                scanf("%s \n", name);
                printf("Enter surname: \n");
                scanf("%s \n", surname);
                printf("Enter email: \n");
                scanf("%s \n" , email);
                printf("Enter phone: \n");
                scanf("%d \n", phone);
                printf("Enter id: \n");
                scanf("%d \n", idStudent);
                Student* student1 = newStudent(name , surname , email , phone , idStudent);
                addStudent(newStudent, library);
                free(name);
                free(surname);
                free(email);

            case 2:

                name2 = malloc(sizeof(char)*12);
                surname2 =  malloc(sizeof(char) * 12);
                email2 =  malloc(sizeof(char) * 20);
                printf("Enter name: \n");
                scanf("%s \n", name2);
                printf("Enter surname: \n");
                scanf("%s \n", surname2);
                printf("Enter email: \n");
                scanf("%s \n" , email2);
                printf("Enter phone: \n");
                scanf("%d \n", phone2);
                printf("Enter id: \n");
                scanf("%d \n", idProfessor);
                Professor* professor1 = newProfessor(name2, surname2, email2, phone2 , idProfessor);
                addProfessor(professor1, library);
                free(name2);
                free(surname2);
                free(email2);

            case 3:

                code = malloc(sizeof(char)*10);
                author = malloc(sizeof(char)*30);
                title = malloc(sizeof(char)*30);
                editorial = malloc(sizeof(char)*10);
                printf("Enter code: \n");
                scanf("%s \n", code);
                printf("Enter author: \n");
                scanf("%s \n", author);
                printf("Enter title: \n");
                scanf("%s \n", title);
                printf("Enter editorial: \n");
                scanf("%s \n", editorial);
                printf("Enter year: \n");
                scanf("%d \n", year);
                Book* book1 = newBook(code, author, title, year , editorial);
                addBook(book1, library);

                free(code);
                free(author);
                free(title);
                free(editorial);

            case 4:


                code2 = malloc(sizeof(char)*10);
                author2 = malloc(sizeof(char)*30);
                title2 = malloc(sizeof(char)*30);
                printf("Enter code: \n");
                scanf("%s \n", code2);
                printf("Enter author: \n");
                scanf("%s \n", author2);
                printf("Enter title: \n");
                scanf("%s \n", title2);
                printf("Enter year: \n");
                scanf("%d \n" , year2);

                Magazine* magazine1 = newMagazine(code2, author2, title2, year2);
                addMagazine(magazine1, library);

                free(code2);
                free(author2);
                free(title2);

            case 5:


                code = malloc(sizeof(char)*10);
                printf("Enter your id: \n");
                scanf("%d \n", id);
                printf("Enter ISBN code: \n");
                scanf("%s \n", codeStudent);
                for (int i = 0; i < library->booksQuantity; ++i) {
                    if (library->booksRegistered[i]->codeISBN == codeStudent) {
                        book2 = library->booksRegistered[i];
                    }
                }
                for (int j = 0; j < library->studentQuantity; ++j) {
                    if (library->studentsRegistered[j]->idStudent == id) {
                        student2 = library->studentsRegistered[j];
                    }
                }
                Loan* loan1 = newLoan(codeStudent, id , library);
                addLoan(loan1 , library);
                rentBookStudent(book2, library , student2);
                free(code);
                destroyBook(book2);
                destroyStudent(student2);

            case 6:


                codeStudent2 = malloc(sizeof(char) * 10);
                printf("Enter your id: \n");
                scanf("%d \n", id3);
                printf("Enter ISBN code: \n");
                scanf("%s \n", codeStudent2);
                for (int i = 0; i < library->booksQuantity; ++i) {
                    if (library->booksRegistered[i]->codeISBN == codeStudent2) {
                        book3 = library->booksRegistered[i];
                    }
                }
                for (int j = 0; j < library->studentQuantity; ++j) {
                    if (library->studentsRegistered[j]->idStudent == id3) {
                        student3 = library->studentsRegistered[j];
                    }
                }

                returnBookStudent(book3 , library , student3);
                free(codeStudent2);
                destroyBook(book3);
                destroyStudent(student3);

            case 7:


                code2 = malloc(sizeof(char)*10);
                printf("Enter your id: \n");
                scanf("%d \n", id2);
                printf("Enter ISBN code: \n");
                scanf("%s \n", codeStudent2);
                for (int i = 0; i < library->magazineQuantity; ++i) {
                    if (library->magazinesRegistered[i]->codeISBN == codeStudent2) {
                        magazine2 = library->magazinesRegistered[i];
                    }
                }
                for (int j = 0; j < library->studentQuantity; ++j) {
                    if (library->studentsRegistered[j]->idStudent == id2) {
                        student2 = library->studentsRegistered[j];
                    }
                }
                Loan* loan2 = newLoan(codeStudent2, id2 , library);
                addLoan(loan2 , library);
                rentMagazineStudent(magazine2, library , student3);
                free(code);
                destroyMagazine(magazine2);
                destroyStudent(student3);

            case 8:


                codeStudent4 = malloc(sizeof(char) * 10);
                printf("Enter your id: \n");
                scanf("%d \n", id4);
                printf("Enter ISBN code: \n");
                scanf("%s \n", codeStudent4);
                for (int i = 0; i < library->magazineQuantity; ++i) {
                    if (library->magazinesRegistered[i]->codeISBN == codeStudent4) {
                        magazine3= library->magazinesRegistered[i];
                    }
                }
                for (int j = 0; j < library->studentQuantity; ++j) {
                    if (library->studentsRegistered[j]->idStudent == id4) {
                        student5 = library->studentsRegistered[j];
                    }
                }
                returnMagazineStudent(magazine3, library , student5);
                free(codeStudent4);
                destroyBook(magazine3);
                destroyStudent(student5);

            case 9:


                codeProfessor2 = malloc(sizeof(char)*10);
                printf("Enter your id: \n");
                scanf("%d \n", id5);
                printf("Enter ISBN code: \n");
                scanf("%s \n", codeProfessor2);
                for (int i = 0; i < library->booksQuantity; ++i) {
                    if (library->booksRegistered[i]->codeISBN == codeProfessor2) {
                        book4 = library->booksRegistered[i];
                    }
                }
                for (int j = 0; j < library->professorQuantity; ++j) {
                    if (library->professorsRegistered[j]->idProfessor == id5) {
                        professor2 = library->professorsRegistered[j];
                    }
                }
                Loan* loan4 = newLoan(codeProfessor2, id5 , library);
                addLoan(loan4, library);
                rentBookProfessor(book4, library , professor2);
                free(codeProfessor2);
                destroyBook(book4);
                destroyProfessor(professor2);

            case 10:


                codeProfessor3 = malloc(sizeof(char) * 10);
                printf("Enter your id: \n");
                scanf("%d \n", id6);
                printf("Enter ISBN code: \n");
                scanf("%s \n", codeProfessor3);
                for (int i = 0; i < library->booksQuantity; ++i) {
                    if (library->booksRegistered[i]->codeISBN == codeProfessor3) {
                        book3 = library->booksRegistered[i];
                    }
                }
                for (int j = 0; j < library->professorQuantity; ++j) {
                    if (library->professorsRegistered[j]->idProfessor == id6) {
                        professor3 = library->professorsRegistered[j];
                    }
                }

                returnBookProfessor(book5, library , professor3);
                free(codeProfessor3);
                destroyBook(book5);
                destroyStudent(professor3);



            case 11:


                codeProfessor4 = malloc(sizeof(char)*10);
                printf("Enter your id: \n");
                scanf("%d \n", id7);
                printf("Enter ISBN code: \n");
                scanf("%s \n", codeProfessor4);
                for (int i = 0; i < library->magazineQuantity; ++i) {
                    if (library->magazinesRegistered[i]->codeISBN == codeProfessor4) {
                        magazine2 = library->magazinesRegistered[i];
                    }
                }
                for (int j = 0; j < library->professorQuantity; ++j) {
                    if (library->professorsRegistered[j]->idProfessor == id7) {
                        professor4= library->professorsRegistered[j];
                    }
                }
                Loan* loan6 = newLoan(codeProfessor4, id7 , library);
                addLoan(loan6, library);
                rentMagazineProfessor(magazine4, library , professor4);
                free(codeProfessor4);
                destroyMagazine(magazine4);
                destroyProfessor(professor4);


            case 12:


                codeProfessor5 = malloc(sizeof(char) * 10);
                printf("Enter your id: \n");
                scanf("%d \n", id8);
                printf("Enter ISBN code: \n");
                scanf("%s \n", codeProfessor5);
                for (int i = 0; i < library->magazineQuantity; ++i) {
                    if (library->magazinesRegistered[i]->codeISBN == codeProfessor5) {
                        magazine3= library->magazinesRegistered[i];
                    }
                }
                for (int j = 0; j < library->professorQuantity; ++j) {
                    if (library->professorsRegistered[j]->idProfessor == id8) {
                        professor5 = library->professorsRegistered[j];
                    }
                }
                returnMagazineProfessor(magazine5, library , professor5);
                free(codeProfessor5);
                destroyBook(magazine5);
                destroyStudent(professor5);

            default:
                printf("Please choose a value from 0 to 12!\n");

        }

    }


    return 0;

}