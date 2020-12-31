
//A main funciton for running unit tests on the project
//Uses Catch unit test framework:
//https://github.com/philsquared/Catch/wiki/Reference


//Tell catch to define a main function for us in this file
#define CATCH_CONFIG_RUNNER

#include "catch.hpp"


int main(int argc, char * argv[] )
{
    //Run unit tests in other file(s)
    return Catch::Session().run( argc, argv );

}



