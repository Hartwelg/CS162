
//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "Location.h"

TEST_CASE( "Location/NoArgConstructor", "No-arg ctor test" ) {
    Location testLoc;

    REQUIRE( testLoc.getName() == "?" );
    REQUIRE( testLoc.isExit() == false );
}


TEST_CASE( "Location/TwoArgConstructor", "2-arg constructor" ) {
    Location testLoc("The pool", true);
    Location testLoc2("The lawn", false);

    REQUIRE( testLoc.getName() == "The pool" );
    REQUIRE( testLoc.isExit() == true );

    REQUIRE( testLoc2.getName() == "The lawn" );
    REQUIRE( testLoc2.isExit() == false );
}



TEST_CASE( "Location/Visiting", "Test ability to visit a location" ) {
    Location testLoc;

    REQUIRE( testLoc.isVisited() == false );
    testLoc.visit();
    REQUIRE( testLoc.isVisited() == true );
}



TEST_CASE( "Location/HasNoNeighborInitial", "Verify no starting neighbors" ) {
    Location testLoc;

    REQUIRE( testLoc.hasNeighbor(NORTH) == false );
    REQUIRE( testLoc.hasNeighbor(SOUTH) == false );
    REQUIRE( testLoc.hasNeighbor(EAST) == false );
    REQUIRE( testLoc.hasNeighbor(WEST) == false );
}


TEST_CASE( "Location/SetNeighbor", "Set a neighbor" ) {
    Location testLoc;
    Location testLoc2("The end", true);

    testLoc.setNeighbor(EAST, &testLoc2);

    REQUIRE( testLoc.hasNeighbor(NORTH) == false );
    REQUIRE( testLoc.hasNeighbor(SOUTH) == false );
    REQUIRE( testLoc.hasNeighbor(EAST) == true );
    REQUIRE( testLoc.hasNeighbor(WEST) == false );

    testLoc.setNeighbor(NORTH, &testLoc2);

    REQUIRE( testLoc.hasNeighbor(NORTH) == true );
    REQUIRE( testLoc.hasNeighbor(SOUTH) == false );
    REQUIRE( testLoc.hasNeighbor(EAST) == true );
    REQUIRE( testLoc.hasNeighbor(WEST) == false );
}


TEST_CASE( "Location/GetNeighbor", "Retrieve a set neighbor" ) {
    Location testLoc;
    Location testLoc2("The end", true);

    testLoc.setNeighbor(EAST, &testLoc2);

    Location* neighborAddrNorth = testLoc.getNeighbor(NORTH);
    REQUIRE( neighborAddrNorth == nullptr );
    Location* neighborAddrSouth = testLoc.getNeighbor(SOUTH);
    REQUIRE( neighborAddrSouth == nullptr );
    Location* neighborAddrEast = testLoc.getNeighbor(EAST);
    REQUIRE( neighborAddrEast == &testLoc2 );
    Location* neighborAddrWest = testLoc.getNeighbor(WEST);
    REQUIRE( neighborAddrWest == nullptr );
}
