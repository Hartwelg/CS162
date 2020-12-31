#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "actor.h"
#include <iostream>

class Movie
{
public:
    Movie();
    ~Movie();
    Movie(std::string theTitle, int numberActors);
    print();
    void addActor(Actor* person);
private:
    std::string title;
    Actor** actors;
    int numActors;
    int maxActors;
};

#endif // MOVIE_H
