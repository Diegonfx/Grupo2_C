/**
 * Declaration of a supplier.
 * @authors Tomas Iturralde, Diego Mancini
 */

#ifndef GRUPO2_C_SUPPLIER_H
#define GRUPO2_C_SUPPLIER_H

#include "Producer.h"

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
    Producer** listOfProducers;
    int amountOfProducers;
    int maxAmountOfProducers;
};

Supplier* newASupplier(char* cif, char* name, char* phone, char* fax, char* responsible, char* address, char* town, char* city,char* country,char* postalCode);
void growListOfProducers(Supplier* supplier1);
void addProducer(Producer* producer1 , Supplier* supplier1);
void removeProducer(Supplier* supplier1, char* producerName);
void destroyASupplier(Supplier* supplier1);

#endif //GRUPO2_C_SUPPLIER_H
