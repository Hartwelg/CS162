#include "Movie.h"
#include <sstream>
//Movie::Movie()
//{
//    numActors = 0;
//    title = "?";
//    maxActors = 0;
//}
Movie::~Movie()
{
    delete [] actors;
}
Movie::Movie(std::string theTitle, int numberActors)
{
    title = theTitle;
    actors = new Actor*[numberActors];
    for (int i = 0; i < numberActors; i++)
    {
        actors[i] = nullptr;
    }
    numActors = 0;
    maxActors = numberActors;
}
Movie::print()
{
    cout << title << endl;
    for (int i = 0; i < maxActors; i++)
    {
        cout << actors[i]->getInfo() << endl;
    }
    cout << endl;
//    std::stringstream out;
//    out << title << endl;
//    for (int i = 0; i < numActors; i++)
//    {
//        out << actors[i]->getInfo() << endl;
//    }
//    out << endl;
//    return out.str();
}
void Movie::addActor(Actor* person)
{
    if (numActors == maxActors)
    {
        cout << "no" << endl;
        exit(0);
    }
    actors[numActors] = person;
    numActors++;
}
