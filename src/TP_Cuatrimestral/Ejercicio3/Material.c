//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Material.h"

//BOOK

Book* newBook(char* codeISBN, char* author, char* title, int year,  char* editorial){

    Book* book1 = malloc(sizeof(Book));

    book1->type = malloc(sizeof(char) * 5);
    book1->codeISBN = malloc(sizeof(char) * strlen(codeISBN));
    book1->author = malloc(sizeof(char) * strlen(author));
    book1->title = malloc(sizeof(char) * strlen(title));
    book1->status = malloc(sizeof(char) * 11);
    book1->editorial = malloc(sizeof(char) * strlen(editorial));

    book1->type = "Book";
    book1->codeISBN = codeISBN;
    book1->author = author;
    book1->title = title;
    book1->year = year;
    book1->status = "Not Taken";
    book1->editorial = editorial;

    strcpy(book1->codeISBN , codeISBN);
    strcpy(book1->author, author);
    strcpy(book1->title , title);
    strcpy(book1->editorial, editorial);

    return book1;
}

void annihilateBook(Book* book1){
    free(book1->type);
    free(book1->codeISBN);
    free(book1->author);
    free(book1->title);
    free(book1->status);
    free(book1->editorial);
    free(book1);
}

//MAGAZINE

Magazine* newMagazine(char* codeISBN, char* author, char* title, int year){
    Magazine* magazine = malloc(sizeof(Magazine));

    magazine->type = malloc(sizeof(char) * 9);
    magazine->codeISBN = malloc(sizeof(char) * strlen(codeISBN));
    magazine->author = malloc(sizeof(char) * strlen(author));
    magazine->title = malloc(sizeof(char) * strlen(title));
    magazine->status = malloc(sizeof(char) * 11);

    magazine->type = "Magazine";
    magazine->codeISBN = codeISBN;
    magazine->author = author;
    magazine->title = title;
    magazine->year = year;
    magazine->status = "Not Taken";

    strcpy(magazine->codeISBN , codeISBN);
    strcpy(magazine->author, author);
    strcpy(magazine->title , title);

    return magazine;
}

void annihilateMagazine(Magazine* magazine1){
    free(magazine1->type);
    free(magazine1->codeISBN);
    free(magazine1->author);
    free(magazine1->title);
    free(magazine1->status);
    free(magazine1);
}