//
// Created by Diego Mancini on 2/6/17.
//

#include <stdlib.h>
#include <memory.h>
#include "Movie.h"

Movie* newMovie(char* name , int price){
    Movie* movie1 = malloc(sizeof(Movie));

    movie1->name = malloc(sizeof(char) * strlen(name) + 1);

    movie1->price = price;
    strcpy(movie1->name , name);

    return movie1;
}

void destroyMovie(Movie* movie1){
    free(movie1->name);
    free(movie1);
}
