/**
  * @author Gauge Hartwell
  * @brief assignment 3
  **/
#ifndef LOCATION_H
#define LOCATION_H

#include <string>

enum Direction
{
    NORTH = 0, EAST, SOUTH, WEST
};
class Location{
public:
    /**
     * @brief Location
     */
    Location();
    /**
     * @brief Location
     * @param locName
     * @param isTheExit
     */
    Location(std::string locName, bool isTheExit);
    /**
     * @brief getName
     * @return
     */
    std::string getName() const;
    /**
     * @brief getDescription
     * @return
     */
    std::string getDescription() const;
    /**
     * @brief hasNeighbor
     * @param dir
     * @return
     */
    bool hasNeighbor(Direction dir) const;
    /**
     * @brief getNeighbor
     * @param dir
     * @return
     */
    Location* getNeighbor(Direction dir) const;
    /**
     * @brief setNeighbor
     * @param dir
     * @param neighborLoc
     */
    void setNeighbor(Direction dir, Location *neighborLoc) ;
    /**
     * @brief isExit
     * @return whether the location is an exit
     */
    bool isExit() const;
    /**
     * @brief visit
     */
    visit();
    /**
     * @brief isVisited
     * @return whether the location has been visited
     */
    bool isVisited() const;
private:
    std::string name;
    bool visited;
    bool exit;
    Location* neighbors[4];
};
#endif // LOCATION_H
