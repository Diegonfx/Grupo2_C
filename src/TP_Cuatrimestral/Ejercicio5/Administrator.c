//
// Created by Diego Mancini on 19/5/17.
//

#include <stdlib.h>
#include <memory.h>
#include <printf.h>
#include "Administrator.h"

Administrator* newAdministrator(char* name , char* surname , int idNumber) {

    Administrator* administrator1 = malloc(sizeof(Administrator));

    administrator1->name = malloc(sizeof(char) * strlen(name) + 1);
    administrator1->surname = malloc(sizeof(char) * strlen(surname) + 1);
    administrator1->clientsRegistered = malloc(sizeof(Client*) * 10) ;
    administrator1->rentalsRegistered = malloc(sizeof(Rental*) * 10);
    administrator1->moviesRegiestered = malloc(sizeof(Movie*) * 10);
    administrator1->excedent1 = malloc(sizeof(Excedent));

    administrator1->idNumber = idNumber;
    administrator1->amountOfClients = 0;
    administrator1->amountOfMovies = 0;
    administrator1->amountOfRentals = 0;

    strcpy(administrator1->name , name);
    strcpy(administrator1->surname , surname);

    return administrator1;
}

void addClient(Administrator* administrator1 , Client* client1){
    if(administrator1->amountOfClients % 10 == 0) {
        realloc(administrator1->clientsRegistered, sizeof(Client*) *10);
    }

    administrator1->clientsRegistered[administrator1->amountOfClients] = client1;
    administrator1->amountOfClients++;
}

void addRental(Administrator* administrator1 , Rental* rental1) {
    if(administrator1->amountOfRentals % 10 == 0) {
        realloc(administrator1->rentalsRegistered, sizeof(Rental*) *10);
    }
    administrator1->rentalsRegistered[administrator1->amountOfRentals] = rental1;
    administrator1->amountOfRentals++;
}

void addMovie(Administrator* administrator1 , Movie* movie1) {
    if(administrator1->amountOfMovies % 10 == 0) {
        realloc(administrator1->moviesRegiestered, sizeof(Movie*) *10);
    }

    administrator1->moviesRegiestered[administrator1->amountOfMovies] = movie1;
    administrator1->amountOfMovies++;
}

void rentMovie(Administrator* administrator1 , Client* client1 , Movie* movie1) {
    Rental* rental1;
    for (int i = 0; i < administrator1->amountOfMovies; ++i) {
        if (administrator1->moviesRegiestered[i]->price == movie1->price) {
            rental1->id = client1->dni;
            rental1 = newRental(movie1->name, "Today", "Never");
            addRental(administrator1 , rental1);
            client1->moviesRented[client1->amountOfMoviesRented] = movie1;
            client1->amountOfMoviesRented++;
            break;
        }
    }
}

void returnMovie(Administrator* administrator1 , Client* client1 , Movie* movie1) {
    for (int i = 0; i < client1->amountOfMoviesRented; ++i) {
        if (client1->moviesRented[i]->name == movie1->name) {
            client1->amountOfMoviesRented--;
            break;
        }
    }
}

void printInfo(Administrator* administrator1){
    printf("---- CLIENTS ----\n");
    for (int i = 0; i < administrator1->amountOfClients; ++i) {
        printf("\nName: %s \nSurname: %s \nDNI: %d \nMovies rented: %d \n" , administrator1->clientsRegistered[i]->name , administrator1->clientsRegistered[i]->surname, administrator1->clientsRegistered[i]->dni , administrator1->clientsRegistered[i]->amountOfMoviesRented);
        for (int j = 0; j < administrator1->clientsRegistered[i]->amountOfMoviesRented; ++j) {
            printf("%d- Movie Name: %s \nPrice: %d \n" ,j, administrator1->clientsRegistered[i]->moviesRented[j]->name , administrator1->clientsRegistered[i]->moviesRented[j]->price);
        }
    }
    printf("\n---- MOVIES ----\n");
    for (int k = 0; k < administrator1->amountOfMovies; ++k) {
        printf("\n %d -Movie name: %s  -->  Price: %d \n" ,k , administrator1->moviesRegiestered[k]->name ,  administrator1->moviesRegiestered[k]->price);
    }
    printf("\n---- RENTALS ----\n");
    for (int l = 0; l < administrator1->amountOfRentals; ++l) {
        printf("\n %d ID: %d ---> Movie name: %s ---> Taken: %s ---> Return: %s \n" , l ,administrator1->rentalsRegistered[l]->id , administrator1->rentalsRegistered[l]->movieName , administrator1->rentalsRegistered[l]->rentalDate , administrator1->rentalsRegistered[l]->rentalReturn);
    }
}

Client* getClient(Administrator* administrator1 , int idn) {
    Client *client1;
    for (int i = 0; i < administrator1->amountOfClients; ++i) {
        if (administrator1->clientsRegistered[i]->dni == idn) {
            client1 = administrator1->clientsRegistered[i];
        }
    }
    return client1;
}

Movie* getMovie(Administrator* administrator1 , int price) {
    Movie* movie1;
    for (int i = 0; i < administrator1->amountOfMovies; ++i) {
        if (administrator1->moviesRegiestered[i]->price == price) {
            movie1 = administrator1->moviesRegiestered[i];
        }
    }
    return movie1;
}

void loadSystem(Administrator* administrator1){

    IDcard* iDcard1 = newIDcard(123);
    IDcard* iDcard2 = newIDcard(456);
    IDcard* iDcard3 = newIDcard(789);

    Client* client1 = newClient("Valle" , "Manoc" , 123 , iDcard1);
    Client* client2 = newClient("Tincho" , "KAL" , 456 , iDcard2);
    Client* client3 = newClient("Apu" , "LOLO" , 789 , iDcard3);

    Movie* movie1 = newMovie("Snowhitey" , 10);
    Movie* movie2 = newMovie("WhiteyShow" , 20);
    Movie* movie3 = newMovie("Whitey's got talent" , 30);
    Movie* movie4 = newMovie("Whitey's idol" , 40);
    Movie* movie5 = newMovie("Whiteyformers" , 50);

    addClient(administrator1 , client1);
    addClient(administrator1 , client2);
    addClient(administrator1 , client3);

    addMovie(administrator1 , movie1);
    addMovie(administrator1 , movie2);
    addMovie(administrator1 , movie3);
    addMovie(administrator1 , movie4);
    addMovie(administrator1 , movie5);

}


void destroyAdministrator(Administrator* administrator1){
    free(administrator1->name);
    free(administrator1->surname);

    for (int i = 0; i < administrator1->amountOfMovies; ++i) {
        destroyMovie(administrator1->moviesRegiestered[i]);
    }
    free(administrator1->moviesRegiestered);

    for (int j = 0; j < administrator1->amountOfRentals; ++j) {
        destroyRental(administrator1->rentalsRegistered[j]);
    }
    free(administrator1->rentalsRegistered);

    for (int k = 0; k < administrator1->amountOfClients; ++k) {
        destroyClient(administrator1->clientsRegistered[k]);
    }
    free(administrator1->clientsRegistered);
    destroyExcedent(administrator1->excedent1);
    free(administrator1);
}
