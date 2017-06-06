//
// Created by Diego Mancini on 20/5/17.
//

#include <stdlib.h>
#include <stdio.h>
#include "Library.h"
void addStudentsTerminal(Library *pLibrary) {
    char* name = malloc(sizeof(char) * 12);
    char* surname = malloc(sizeof(char) * 12);
    char* email = malloc(sizeof(char) * 20);
    int phone;
    int idStudent;
    printf("\nEnter name: \n");
    scanf("%s", name);
    printf("Enter surname: \n");
    scanf("%s", surname);
    printf("Enter email: \n");
    scanf("%s", email);
    printf("Enter phone: \n");
    scanf("%d", &phone);
    printf("Enter id: \n");
    scanf("%d", &idStudent);
    Student *student1 = newStudent(name, surname, email, phone, idStudent);
    addStudent(student1, pLibrary);
}
void addTeacherTerminal(Library *pLibrary) {
    char* name2 = malloc(sizeof(char) * 12);
    char* surname2 = malloc(sizeof(char) * 12);
    char* email2 = malloc(sizeof(char) * 20);
    int phone2;
    int idProfessor;
    printf("Enter name: \n");
    scanf("%s", name2);
    printf("Enter surname: \n");
    scanf("%s", surname2);
    printf("Enter email: \n");
    scanf("%s", email2);
    printf("Enter phone: \n");
    scanf("%d¡", &phone2);
    printf("Enter id: \n");
    scanf("%d", &idProfessor);
    Professor *professor1 = newProfessor(name2, surname2, email2, phone2, idProfessor);
    addProfessor(professor1, pLibrary);
}
void addBookTerminal(Library *library) {
    int code;
    char* author = malloc(sizeof(char) * 30);
    char* title = malloc(sizeof(char) * 30);
    char* editorial = malloc(sizeof(char) * 10);
    int year;
    printf("Enter code: \n");
    scanf("%d", &code);
    printf("Enter author: \n");
    scanf("%s", author);
    printf("Enter title: \n");
    scanf("%s", title);
    printf("Enter editorial: \n");
    scanf("%s", editorial);
    printf("Enter year: \n");
    scanf("%d", &year);
    Book *book1 = newBook(code, author, title, year, editorial);
    addBook(book1, library);
}
void addMagazineTerminal(Library *library) {
    int code2;
    char* author2 = malloc(sizeof(char) * 30);
    char* title2 = malloc(sizeof(char) * 30);
    int year2;
    printf("Enter code: \n");
    scanf("%d", &code2);
    printf("Enter author: \n");
    scanf("%s", author2);
    printf("Enter title: \n");
    scanf("%s", title2);
    printf("Enter year: \n");
    scanf("%d", &year2);

    Magazine* magazine1 = newMagazine(code2, author2, title2, year2);
    addMagazine(magazine1, library);

}
void rentMaterialTerminal(Library *library) {
    int isbnCode;
    int id;
    int choiceMaterial;
    int choicePerson;
    char* taken =malloc(sizeof(char) * 10) ;
    char* returnDate =malloc(sizeof(char) * 10);
    Book* book2;
    Magazine* magazine1;
    Student* student2;
    Professor* professor1;
    printf("IF STUDENT: 1 ||| ");
    printf("IF PROFESSOR: 2 --> ");
    printf("Select person: ");
    scanf("%d" , &choicePerson);
    if (choicePerson == 1) {
        printf("IF BOOK: 1 |||");
        printf("IF MAGAZINE: 2 -->");
        printf("Select material: ");
        scanf("%d" , &choiceMaterial);
        if (choiceMaterial == 1) {
            printInfo(library);
            printf("");
            printf("\nEnter your id: \n");
            scanf("%d", &id);
            printf("Enter ISBN code: \n");
            scanf("%d", &isbnCode);
            printf("Enter date taken: \n");
            scanf("%s" , taken);
            printf("Enter return date: \n");
            scanf("%s" , returnDate);
            for (int i = 0; i < library->booksQuantity; ++i) {
                if (library->booksRegistered[i]->codeISBN == isbnCode) {
                    book2 = library->booksRegistered[i];
                }
            }
            for (int j = 0; j < library->studentQuantity; ++j) {
                if (library->studentsRegistered[j]->idStudent == id) {
                    student2 = library->studentsRegistered[j];
                }
            }
            rentBookStudent(book2, library, student2 , taken , returnDate);
        } else if(choiceMaterial == 2) {
            printInfo(library);
            printf("Enter your id: \n");
            scanf("%d", &id);
            printf("Enter ISBN code: \n");
            scanf("%d", &isbnCode);
            printf("Enter date taken: \n");
            scanf("%s" , taken);
            printf("Enter return date: \n");
            scanf("%s" , returnDate);
            for (int i = 0; i < library->magazineQuantity; ++i) {
                if (library->magazinesRegistered[i]->codeISBN == isbnCode) {
                    magazine1 = library->magazinesRegistered[i];
                }
            }
            for (int j = 0; j < library->studentQuantity; ++j) {
                if (library->studentsRegistered[j]->idStudent == id) {
                    student2 = library->studentsRegistered[j];
                }
            }
            rentMagazineStudent(magazine1 , library , student2, taken , returnDate);
        } else {
            printf("PLEASE TYPE 1 OR 2!");
            return;
        }
    } else if (choicePerson == 2) {
        printf("IF BOOK: 1 |||");
        printf("IF MAGAZINE: 2 --> ");
        printf("Select material: ");
        scanf("%d" , &choiceMaterial);
        if (choiceMaterial == 1) {
            printInfo(library);
            printf("Enter your id: \n");
            scanf("%d", &id);
            printf("Enter ISBN code: \n");
            scanf("%d", &isbnCode);
            printf("Enter date taken: \n");
            scanf("%s" , taken);
            printf("Enter return date: \n");
            scanf("%s" , returnDate);
            for (int i = 0; i < library->booksQuantity; ++i) {
                if (library->booksRegistered[i]->codeISBN == isbnCode) {
                    book2 = library->booksRegistered[i];
                }
            }
            for (int j = 0; j < library->professorQuantity; ++j) {
                if (library->professorsRegistered[j]->idProfessor == id) {
                    professor1 = library->professorsRegistered[j];
                }
            }
            rentBookProfessor(book2 , library , professor1, taken , returnDate);
        } else if(choiceMaterial == 2) {
            printInfo(library);
            printf("Enter your id: \n");
            scanf("%d", &id);
            printf("Enter ISBN code: \n");
            scanf("%d", &isbnCode);
            printf("Enter date taken: \n");
            scanf("%s" , taken);
            printf("Enter return date: \n");
            scanf("%s" , returnDate);
            for (int i = 0; i < library->magazineQuantity; ++i) {
                if (library->magazinesRegistered[i]->codeISBN == isbnCode) {
                    magazine1 = library->magazinesRegistered[i];
                }
            }
            for (int j = 0; j < library->professorQuantity; ++j) {
                if (library->professorsRegistered[j]->idProfessor == id) {
                    professor1 = library->professorsRegistered[j];
                }
            }
            rentMagazineProfessor(magazine1 , library , professor1, taken , returnDate);
        } else {
            printf("PLEASE TYPE 1 OR 2!");
            return;
        }
    }
}
void returnMaterialTerminal(Library *library) {
    int isbnCode;
    int id;
    int choiceMaterial;
    int choicePerson;
    Book* book2;
    Magazine* magazine1;
    Student* student2;
    Professor* professor1;
    printf("IF STUDENT: 1 |||");
    printf("IF PROFESSOR: 2 --> ");
    printf("Select person: ");
    scanf("%d" , &choicePerson);
    if (choicePerson == 1) {
        printf("IF BOOK: 1 ||| ");
        printf("IF MAGAZINE: 2 -->");
        printf("Select material: ");
        scanf("%d" , &choiceMaterial);
        if (choiceMaterial == 1) {
            printInfo(library);
            printf("Enter your id: \n");
            scanf("%d", &id);
            printf("Enter ISBN code: \n");
            scanf("%d", &isbnCode);
            for (int i = 0; i < library->booksQuantity; ++i) {
                if (library->booksRegistered[i]->codeISBN == isbnCode) {
                    book2 = library->booksRegistered[i];
                }
            }
            for (int j = 0; j < library->studentQuantity; ++j) {
                if (library->studentsRegistered[j]->idStudent == id) {
                    student2 = library->studentsRegistered[j];
                }
            }
            returnBookStudent(book2, library, student2);
        } else if(choiceMaterial == 2) {
            printInfo(library);
            printf("Enter your id: \n");
            scanf("%d", &id);
            printf("Enter ISBN code: \n");
            scanf("%d", &isbnCode);
            for (int i = 0; i < library->magazineQuantity; ++i) {
                if (library->magazinesRegistered[i]->codeISBN == isbnCode) {
                    magazine1 = library->magazinesRegistered[i];
                }
            }
            for (int j = 0; j < library->studentQuantity; ++j) {
                if (library->studentsRegistered[j]->idStudent == id) {
                    student2 = library->studentsRegistered[j];
                }
            }
            returnMagazineStudent(magazine1 , library , student2);
        } else {
            printf("PLEASE TYPE 1 OR 2!");
            return;
        }
    } else if (choicePerson == 2) {
        printf("IF BOOK: 1 ||| ");
        printf("IF MAGAZINE: 2 -->");
        printf("Select material: ");
        scanf("%d" , &choiceMaterial);
        if (choiceMaterial == 1) {
            printInfo(library);
            printf("Enter your id: \n");
            scanf("%d", &id);
            printf("Enter ISBN code: \n");
            scanf("%d", &isbnCode);
            for (int i = 0; i < library->booksQuantity; ++i) {
                if (library->booksRegistered[i]->codeISBN == isbnCode) {
                    book2 = library->booksRegistered[i];
                }
            }
            for (int j = 0; j < library->professorQuantity; ++j) {
                if (library->professorsRegistered[j]->idProfessor == id) {
                    professor1 = library->professorsRegistered[j];
                }
            }
            returnBookProfessor(book2 , library , professor1);
        } else if(choiceMaterial == 2) {
            printInfo(library);
            printf("Enter your id: \n");
            scanf("%d", &id);
            printf("Enter ISBN code: \n");
            scanf("%d", &isbnCode);
            for (int i = 0; i < library->magazineQuantity; ++i) {
                if (library->magazinesRegistered[i]->codeISBN == isbnCode) {
                    magazine1 = library->magazinesRegistered[i];
                }
            }
            for (int j = 0; j < library->professorQuantity; ++j) {
                if (library->professorsRegistered[j]->idProfessor == id) {
                    professor1 = library->professorsRegistered[j];
                }
            }
            returnMagazineProfessor(magazine1 , library , professor1);
        } else {
            printf("PLEASE TYPE 1 OR 2!");
            return;
        }
    }
}

int main() {

    Library* library = newLibrary("Austral");

    loadDatabase(library);
    int choice;
    while (choice != 8) {
        printf("\n\n-------------Welcome to the library, please choose an option\n");
        printf("1- Add Student\n");
        printf("2- Add Teacher\n");
        printf("3- Add Book\n");
        printf("4- Add Magazine\n");
        printf("5- Rent material\n");
        printf("6- Return material\n");
        printf("7- INFO\n");
        printf("8- Exit\n");
        printf("\nCHOICE: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudentsTerminal(library);
                break;
            case 2:
                addTeacherTerminal(library);
                break;
            case 3:
                addBookTerminal(library);
                break;
            case 4:
                addMagazineTerminal(library);
                break;
            case 5:
                rentMaterialTerminal(library);
                break;
            case 6:
                returnMaterialTerminal(library);
                break;
            case 7:
                printInfo(library);
                break;
            case 8:
                destroyLibrary(library);
                exit(0);
            default:
                printf("Please choose a value from 0 to 12!\n");
        }
    }

    return 0;
}


