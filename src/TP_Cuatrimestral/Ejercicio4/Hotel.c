//
// Created by Diego Mancini on 1/6/17.
//

#include <printf.h>
#include <stdlib.h>
#include "Person.h"

void choiceONE(Receptionist* pReceptionist) {
    int dni;
    char* name = malloc(sizeof(char) * 10);
    char* surname = malloc(sizeof(char) * 10);
    printf("Insert client DNI: ");
    scanf("%d", &dni);
    printf("Insert name: ");
    scanf("%s" ,name );
    printf("Insert surname: ");
    scanf("%s" , surname);
    Client* client1 = newClient(name, surname, dni);
    addClient(pReceptionist, client1);
}

void choiceTWO(Receptionist* pReceptionist) {
    char* type = malloc(sizeof(char) * 20);
    int price;
    printf("Insert type: ");
    scanf("%s" ,type );
    printf("Insert price: ");
    scanf("%d", &price);
    Room* room1= newRoom(pReceptionist->amountOfRooms+1 , type , price);
    addRoom(pReceptionist , room1);
}

void choiceTHREE(Receptionist* pReceptionist) {
    printInfo(pReceptionist);
    int dni;
    char* name = malloc(sizeof(char) * 10);
    char* surname = malloc(sizeof(char) * 10);
    printf("\n---Clients info---\n");
    printf("Enter clients name: ");
    scanf("%s" , name);
    printf("Enter clients surname: ");
    scanf("%s" , surname);
    printf("Enter clients DNI: ");
    scanf("%d" , &dni);
    Client* client1 = newClient(name , surname , dni);
    int price;
    printf("\n---Room Info---\n");
    printf("Enter room price:");
    scanf("%d" , &price);
    Room* room1 = getRoom(pReceptionist, price);
    registerClientToRoom(pReceptionist, client1 , room1->price);
}

void choiceFOUR(Receptionist* pReceptionist) {
    int dni;
    printf("Enter clients DNI: ");
    scanf("%d" , &dni);
    Client* client1 = getClient(pReceptionist , dni);
//    int price;
//    printf("Enter room price: ");
//    scanf("%d" , &price);
//    Room* room1 = getRoom(pReceptionist, price);
    clientLeaves(pReceptionist, client1);
}

void choiceFIVE(Receptionist* pReceptionist) {
    printInfo(pReceptionist);
}

int main() {

    Receptionist* receptionist1  = newReceptionist("Diego" , "Mancini" , 38931523 , "HOTEL ONE STAR" , 123456789) ;

    loadDatabase(receptionist1);

    int choice;
    while (choice != 7) {
        printf("\n---Welcome to Hotel---\n");
        printf("\n 1- Add client \n 2- Add Room\n 3- Rent Room \n 4- Leave Room \n 5-PrintINFO \n 6-Exit \n");
        printf("\nEnter choice please: \n");
        scanf("%d" , &choice);

        switch (choice) {
            case 1:
                choiceONE(receptionist1);
                break;
            case 2:
                choiceTWO(receptionist1);
                break;
            case 3:
                choiceTHREE(receptionist1);
                break;
            case 4:
                choiceFOUR(receptionist1);
                break;
            case 5:
                choiceFIVE(receptionist1);
                break;
            case 6:
                destroyReceptionist(receptionist1);
                exit(0);
            default:
                printf("PUT RIGHT INPUT");
        }
    }

    return 0;
}
