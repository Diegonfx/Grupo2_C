//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_REGISTEREDUSER_H
#define GRUPO2_C_REGISTEREDUSER_H

typedef struct registeredUser RegisteredUser;

struct registeredUser {
    char* name;
    char* dni;
    char* address;
    char* phone;
    char* town;
    char* city;
    char* country;
    char* postalCode;
    char** role;
};

RegisteredUser* newRegisteredUser(char* name, char* dni, char* address, char* phone, char* town , char* city, char* country, char* postalCode, char** role);
void annihilateRegisteredUser(RegisteredUser* registeredUser1);

#endif //GRUPO2_C_REGISTEREDUSER_H
