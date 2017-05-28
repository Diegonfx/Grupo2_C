//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_MATERIAL_H
#define GRUPO2_C_MATERIAL_H

//BOOK
typedef struct book Book;

struct book{
    char* type;
    char* codeISBN;
    char* author;
    char* title;
    int year;
    char* status;
    char* editorial;
};

//Methods
Book* newBook(char* codeISBN, char* author, char* title, int year, char* editorial);
void destroyBook(Book* book1);


//MAGAZINE
typedef struct magazine Magazine;

struct magazine{
    char* type;
    char* codeISBN;
    char* author;
    char* title;
    int year;
    char* status;
};

//Methods
Magazine* newMagazine(char* codeISBN, char* author, char* title, int year);
void destroyMagazine(Magazine* magazine1);

#endif //GRUPO2_C_MATERIAL_H
