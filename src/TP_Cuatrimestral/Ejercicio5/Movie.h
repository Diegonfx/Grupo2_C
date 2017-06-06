//
// Created by Diego Mancini on 2/6/17.
//

#ifndef EJERCICIO5_MOVIE_H
#define EJERCICIO5_MOVIE_H

typedef struct movie Movie;

struct movie {
    char* name;
    int price;
};

Movie* newMovie(char* name , int price);
void destroyMovie(Movie* movie1);

#endif //EJERCICIO5_MOVIE_H
