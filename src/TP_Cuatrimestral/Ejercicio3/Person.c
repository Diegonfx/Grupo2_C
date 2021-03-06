//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Person.h"

//STUDENT

Student* newStudent(char* name, char* surname, char* email, int phone, int idStudent){
    Student* student1 = malloc(sizeof(Student));

    student1->type = malloc(sizeof(char) * 9);
    student1->name = malloc(sizeof(char) * strlen(name) + 1);
    student1->surname = malloc(sizeof(char) * strlen(surname) + 1);
    student1->email = malloc(sizeof(char) * strlen(email) + 1);

    student1->type = "Student";
    student1->phone = phone;
    student1->amountBooks = 0;
    student1->amountMagazines = 0;
    student1->payment = 0;
    student1->idStudent = idStudent;

    strcpy(student1->name , name);
    strcpy(student1->surname , surname);
    strcpy(student1->email, email);

    return student1;

}

void destroyStudent(Student *student1){
    free(student1->name);
    free(student1->surname);
    free(student1->email);
    free(student1->type);
    free(student1);
}

//PROFESSOR

Professor* newProfessor(char* name, char* surname, char* email, int phone, int idProfessor){
    Professor* pro = malloc(sizeof(Professor));

    pro->type = malloc(sizeof(char) * 10);
    pro->name = malloc(sizeof(char) * strlen(name) + 1);
    pro->surname = malloc(sizeof(char) * strlen(surname) + 1);
    pro->email = malloc(sizeof(char) * strlen(email) +1 );

    pro->type = "Professor";
    pro->phone = phone;
    pro->amountBooks = 0;
    pro->amountMagazines = 0;
    pro->payment = 0;
    pro->idProfessor = idProfessor;

    strcpy(pro->name , name);
    strcpy(pro->surname , surname);
    strcpy(pro->email, email);

    return pro;
}

void destroyProfessor(Professor *professor){
    free(professor->name);
    free(professor->surname);
    free(professor->email);
    free(professor->type);
    free(professor);
}