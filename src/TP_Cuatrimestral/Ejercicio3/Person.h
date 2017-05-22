//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_PERSON_H
#define GRUPO2_C_PERSON_H

//STUDENT

#include "Material.h"
#include "Library.h"

typedef struct student Student;

struct student {
    char* type;
    char* name;
    char* surname;
    char* email;
    int phone;
    int amountBooks;
    int amountMagazines;
    double payment;
    int idStudent;
};

//Methods
Student* newStudent(char* name, char* surname, char* email, int phone, int idStudent);
void annihilateStudent(Student* student1);

//PROFESSOR

typedef struct professor Professor;

struct professor {
    char* type;
    char* name;
    char* surname;
    char* email;
    int phone;
    int amountBooks;
    int amountMagazines;
    double payment;
    int idProfessor;
};

//Methods
Professor* newProfessor(char* name, char* surname, char* email, int phone, int idProfessor);
void annihilateProfessor(Professor* professor);


#endif //GRUPO2_C_PERSON_H
