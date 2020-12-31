//collaborated with Abby Johnson and Nicole Geiger
#include <iostream>
#include "Location.h"

using namespace std;

Location::Location()
{
    name = "?";
    for (int i = 0; i < 4; i++)
    {
        neighbors[i] = nullptr;
    }
    visited = false;
    exit = false;
}
Location::Location(string locName, bool isTheExit)
{
    name = locName;
    exit = isTheExit;
    for (int i = 0; i < 4; i++)
    {
        neighbors[i] = nullptr;
    }
    visited = false;
}
string Location::getName() const
{
    return name;
}
string Location::getDescription() const
{
    cout << getName() << endl;
    if (isVisited() == true)
    {
        cout << "You have been here before" << endl;
    }
    cout << "Exits: ";
    string exits;

        if (this->hasNeighbor(NORTH))
        {
            exits += "North ";
        }
        if (this->hasNeighbor(EAST))
        {
            exits += "East ";
        }
        if (this->hasNeighbor(SOUTH))
        {
            exits += "South ";
        }
        if (this->hasNeighbor(WEST))
        {
            exits += "West ";
        }
    cout << exits << endl;
}
bool Location::hasNeighbor(Direction dir) const
{
    if (neighbors[dir] == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}
Location* Location::getNeighbor(Direction dir) const
{
    return neighbors[dir];
}
void Location::setNeighbor(Direction dir, Location *neighborLoc)
{
    neighbors[dir] = neighborLoc;
}
bool Location::isExit() const
{
    if (exit == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Location::visit()
{
    visited = true;
    return visited;
}
bool Location::isVisited() const
{
    if (visited == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
