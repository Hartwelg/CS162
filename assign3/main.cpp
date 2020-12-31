#include <iostream>
#include "Location.h"
using namespace std;
const int NUM_LOCATIONS = 8;
/**
* @brief Sets up the map shown in the assignment 3 document.
*
* Should fill the array with the appropriate places and
* set all neighbor relationships
* Location 0 should be the start: a deep, dark cave
*/
void buildMap(Location allLocations[]) {
    allLocations[0] = Location("A deep, dark cave", false);
    allLocations[1] = Location("A musty passage", false);
    allLocations[2] = Location("A collapsed cavern", false);
    allLocations[3] = Location("Shores of an underground lake", false);
    allLocations[4] = Location("A twisting shaft", false);
    allLocations[5] = Location("A dusty Alcove", false);
    allLocations[6] = Location("A passage to the surface", false);
    allLocations[7] = Location("Exit", true);

    allLocations[0].setNeighbor(NORTH, &allLocations[1]);
    allLocations[0].setNeighbor(SOUTH, &allLocations[2]);
    allLocations[0].setNeighbor(EAST, &allLocations[3]);

    allLocations[1].setNeighbor(SOUTH, &allLocations[0]);
    allLocations[1].setNeighbor(EAST, &allLocations[4]);

    allLocations[2].setNeighbor(NORTH, &allLocations[0]);

    allLocations[3].setNeighbor(WEST, &allLocations[0]);
    allLocations[3].setNeighbor(NORTH, &allLocations[4]);

    allLocations[4].setNeighbor(SOUTH, &allLocations[3]);
    allLocations[4].setNeighbor(EAST, &allLocations[5]);

    allLocations[5].setNeighbor(SOUTH, &allLocations[6]);

    allLocations[6].setNeighbor(NORTH, &allLocations[5]);
    allLocations[6].setNeighbor(WEST, &allLocations[7]);
}
Direction getInput()
{
    cout << "Where do you want to go?" << endl;
    string movement;
    cin >> movement;
    if (movement == "N")
    {
        return NORTH;
    }
    else if (movement == "E")
    {
        return EAST;
    }
    else if (movement == "S")
    {
        return SOUTH;
    }
    else if (movement == "W")
    {
        return WEST;
    }
}
int main()
{
 //Make an array to hold all the locations in the map
 // Will have placeholder data created by default constructor
 Location allLocations[NUM_LOCATIONS];
 //Setup the map
 buildMap(allLocations);
 //Current Location will keep track of where the player is
 //Initially points to room 0
 Location* currentLocation = &allLocations[0];
 //Until the currentLocation is an exit:
 // print out a description of the current Location, mark it as visited,
 // get input of N S E or W and update currentLocation based on input
 //TODO - fixme
 while (currentLocation->isExit() == false)
 {
     currentLocation->getDescription();
     if (currentLocation->isVisited() == false)
     {
         currentLocation->visit();
     }
     Direction movement = getInput();

         if (currentLocation->hasNeighbor(movement) == true)
         {
             currentLocation = currentLocation->getNeighbor(movement);
         }
 if (currentLocation == &allLocations[7])
 {
     cout << "You emerge safely from the maze!" << endl;
 }
 }
}
