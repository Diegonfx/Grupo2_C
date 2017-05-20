//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Person.h"

//STUDENT

Student* newStudent(char* name, char* surname, char* email, int phone, int idStudent){
    Student* student1 = malloc(sizeof(Student));

    student1->type = malloc(sizeof(char) * 8);
    student1->name = malloc(sizeof(char) * strlen(name));
    student1->surname = malloc(sizeof(char) * strlen(surname));
    student1->email = malloc(sizeof(char) * strlen(email));

    student1->type = "Student";
    student1->name = name;
    student1->surname = surname;
    student1->email = email;
    student1->phone = phone;
    student1->amountBooks = 0;
    student1->payment = 0;
    student1->idStudent = idStudent;

    strcpy(student1->name , name);
    strcpy(student1->surname , surname);
    strcpy(student1->email, email);

    return student1;

}

void studentTakesBook(Book* book1 , Library* library1, Student* student1){

}

void studentTakesMagazine(Magazine* book1 , Library* library1, Student* student1){

}

void annihilateStudent(Student* student1){

}

//PROFESSOR

Professor* newProfessor(char* name, char* surname, char* email, int phone, int idProfessor){
    Professor* pro = malloc(sizeof(Professor));

    pro->type = malloc(sizeof(char) * 10);
    pro->name = malloc(sizeof(char) * strlen(name));
    pro->surname = malloc(sizeof(char) * strlen(surname));
    pro->email = malloc(sizeof(char) * strlen(email));

    pro->type = "Professor";
    pro->name = name;
    pro->surname = surname;
    pro->email = email;
    pro->phone = phone;
    pro->amountBooks = 0;
    pro->payment = 0;
    pro->idProfessor = idProfessor;

    strcpy(pro->name , name);
    strcpy(pro->surname , surname);
    strcpy(pro->email, email);

    return pro;
}

void professorTakesBook(Book* book1 , Library* library1, Professor* professor1){

}

void professorTakesMagazine(Magazine* book1 , Library* library1, Professor* professor1){

}

void annihilateProfessor(Professor* professor1){

}