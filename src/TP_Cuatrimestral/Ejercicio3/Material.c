//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Material.h"

//BOOK

Book* newBook(int codeISBN, char* author, char* title, int year,  char* editorial){

    Book* book1 = malloc(sizeof(Book));

    book1->type = malloc(sizeof(char) * 5);
    book1->author = malloc(sizeof(char) * strlen(author) + 1);
    book1->title = malloc(sizeof(char) * strlen(title) + 1);
    book1->status = malloc(sizeof(char) * 11);
    book1->editorial = malloc(sizeof(char) * strlen(editorial) + 1);

    book1->type = "Book";
    book1->status = "Not Taken";
    book1->codeISBN = codeISBN;
    book1->year = year;

    strcpy(book1->author, author);
    strcpy(book1->title , title);
    strcpy(book1->editorial, editorial);

    return book1;
}

void destroyBook(Book* book1){
    free(book1->type);
    free(book1->author);
    free(book1->title);
    free(book1->status);
    free(book1->editorial);
    free(book1);
}

//MAGAZINE

Magazine* newMagazine(int codeISBN, char* author, char* title, int year){
    Magazine* magazine = malloc(sizeof(Magazine));

    magazine->type = malloc(sizeof(char) * 9);
    magazine->author = malloc(sizeof(char) * strlen(author) + 1);
    magazine->title = malloc(sizeof(char) * strlen(title) + 1);
    magazine->status = malloc(sizeof(char) * 11);

    magazine->codeISBN = codeISBN;
    magazine->type = "Magazine";
    magazine->year = year;
    magazine->status = "Not Taken";

    strcpy(magazine->author, author);
    strcpy(magazine->title , title);

    return magazine;
}

void destroyMagazine(Magazine* magazine1){
    free(magazine1->type);
    free(magazine1->author);
    free(magazine1->title);
    free(magazine1->status);
    free(magazine1);
}