#include "ActorList.h"
#include <iostream>
#include <fstream>
using namespace std;

ActorList::ActorList()
{
    ifstream infile("actors.txt");
    infile >> numActors;
    actors = new Actor[numActors];
    for (int i = 0; i < numActors; i++)
    {
        string firstName, lastName;
        int year;
        infile >> firstName >> lastName >> year;
        actors[i] = Actor(firstName, lastName, year);
    }
}
ActorList::~ActorList()
{
    delete [] actors;
}
ActorList::ActorList(const ActorList& otherList)
{
    numActors = otherList.numActors;
    std::ifstream infile("actors.txt");
    infile >> numActors;
    actors = new Actor[numActors];
    for (int i = 0; i < numActors; i++)
    {
        actors[i] = otherList.actors[i];
    }
}
Actor* ActorList::getActorByIndex(int n) const
{
    return &actors[n];
}
