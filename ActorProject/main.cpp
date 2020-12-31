#include <iostream>

#include "Movie.h"
#include "ActorList.h"

using namespace std;

int main()
{
    //Load our master list of actors
    ActorList mainActorList;

//    //Do stuff...

    Movie Movie1("Space Wars", 3);
    Movie Movie2("The Breakup", 2);

    Actor* actor1 = mainActorList.getActorByIndex(1);
    Actor* actor2 = mainActorList.getActorByIndex(2);
    Actor* actor3 = mainActorList.getActorByIndex(3);

    Movie1.addActor(actor1);
    Movie1.addActor(actor2);
    Movie1.addActor(actor3);

    Actor* actor0 = mainActorList.getActorByIndex(0);

    Movie2.addActor(actor0);
    Movie2.addActor(actor2);

    Movie1.print();
    Movie2.print();

    actor2->setFirstName("firstName");

    Movie1.print();
    Movie2.print();

    ActorList copyList(mainActorList);
    Actor* newActor0 = copyList.getActorByIndex(0);

    newActor0->setFirstName("thisFirstName");

    cout << actor0->getInfo() << endl;
    cout << newActor0->getInfo() << endl;

    return 0;
}
