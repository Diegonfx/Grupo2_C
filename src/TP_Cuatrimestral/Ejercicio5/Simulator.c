//
// Created by Diego Mancini on 2/6/17.
//

#include <printf.h>
#include <stdlib.h>
#include "Administrator.h"


void choiceONE(Administrator* administrator1) {
    int dni;
    char* name = malloc(sizeof(char) * 10);
    char* surname = malloc(sizeof(char) * 10);
    printf("Insert client DNI: ");
    scanf("%d", &dni);
    IDcard* iDcardClient = newIDcard(dni);
    printf("Insert name: ");
    scanf("%s" ,name );
    printf("Insert surname: ");
    scanf("%s" , surname);
    Client* client1 = newClient(name, surname, dni, iDcardClient);
    addClient(administrator1 , client1);
}

void choiceTWO(Administrator* administrator1) {
    char* name = malloc(sizeof(char) * 20);
    int price;
    printf("Insert name: ");
    scanf("%s" ,name );
    printf("Insert price: ");
    scanf("%d", &price);
    Movie* movie1 = newMovie(name , price);
    addMovie(administrator1 , movie1);
}

void choiceTHREE(Administrator* administrator1) {
    printInfo(administrator1);
    int dni;
    printf("Enter clients DNI: ");
    scanf("%d" , &dni);
    Client* client1 = getClient(administrator1 , dni);
    int price;
    printf("Enter movie price:");
    scanf("%d" , &price);
    Movie* movie1 = getMovie(administrator1 , price);
    rentMovie(administrator1 , client1 , movie1);
}

void choiceFOUR(Administrator* administrator1) {
    int dni;
    printf("Enter clients DNI: ");
    scanf("%d" , &dni);
    Client* client1 = getClient(administrator1 , dni);
    int price;
    printf("Enter movie price: ");
    scanf("%d" , &price);
    Movie* movie1 = getMovie(administrator1 , price);
    returnMovie(administrator1 , client1 , movie1);
}

void choiceFIVE(Administrator *pAdmin) {
    printInfo(pAdmin);
}

int main () {

    Administrator* diego = newAdministrator("Diego" , "Mancini" , 38931523);
    loadSystem(diego);

    int choice;
    while (choice != 7) {
        printf("\n---Welcome to Rentals---\n");
        printf("\n 1- Add client \n 2- Add Movie \n 3- Rent Movie \n 4- Return Movie \n 5-PrintINFO \n 6-Exit \n");
        printf("\nEnter choice please: \n");
        scanf("%d" , &choice);
        switch (choice) {
            case 1:
                choiceONE(diego);
                break;
            case 2:
                choiceTWO(diego);
                break;
            case 3:
                choiceTHREE(diego);
                break;
            case 4:
                choiceFOUR(diego);
                break;
            case 5:
                choiceFIVE(diego);
                break;
            case 6:
                destroyAdministrator(diego);
                exit(0);
            default:
                printf("PUT RIGHT INPUT");
        }
    }

    return 0;
}


