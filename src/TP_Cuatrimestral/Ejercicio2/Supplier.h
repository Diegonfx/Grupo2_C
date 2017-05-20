//
// Created by Diego Mancini on 19/5/17.
//

#ifndef GRUPO2_C_SUPPLIER_H
#define GRUPO2_C_SUPPLIER_H

typedef struct supplier Supplier;

struct supplier {
    char* cif;
    char* name;
    char* phone;
    char* fax;
    char* responsible;
    char* address;
    char* town;
    char* city;
    char* country;
    char* postalCode;
};

Supplier* newSupplier(char* cif, char* name, char* phone, char* fax, char* responsible, char* address, char* town, char* city,char* country,char* postalCode);
void annihilateSupplier(Supplier* supplier1);

#endif //GRUPO2_C_SUPPLIER_H
