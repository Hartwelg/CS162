
//Bring in unit testing code
#include "catch.hpp"

//Include your .h files
#include "Rectangle.h"
#include "Point.h"

TEST_CASE( "Rectangle/Constructor1", "3 Argument constructor" ) {
//Build rectangle
Point p1(1, 5);
Rectangle r1(p1, 2, 4);
//now see if it has the right info
Point temp = r1.getUpperLeftVertex();
REQUIRE( temp.isSameAs(p1) == true);

//dimensions are doubles, compare using Approx from catch.hpp to check equality
REQUIRE( r1.getHeight() == Approx(2));
REQUIRE( r1.getWidth() == Approx(4));
REQUIRE(p1.getX() == Approx(1));
REQUIRE(p1.getY() == Approx(5));
}
TEST_CASE("Rectangle/Constructor2", "2 argument constructor")
{
Point p1(0, 0);
Point p2(2, -4);
Rectangle r1(p1, p2);
Point temp1 = r1.getUpperLeftVertex();
REQUIRE(temp1.isSameAs(p1) == true);
REQUIRE(r1.getHeight() == Approx(4));
REQUIRE(r1.getWidth() == Approx(2));
REQUIRE(temp1.getX() == Approx(0));
REQUIRE(temp1.getY() == Approx(0));
REQUIRE(p2.getX() == Approx(2));
REQUIRE(p2.getY() == Approx(-4));
REQUIRE(r1.getArea() == Approx(8));
REQUIRE(r1.getPerimeter() == Approx(12));
}
TEST_CASE("Rectangle/Shift", "2 argument constructor")
{
    Point p1(0, 0);
    Point p2(4, -4);
    Rectangle r1(p1, p2);
    Point temp = r1.getUpperLeftVertex();
    REQUIRE(temp.isSameAs(p1) == true);
    r1.shift(2, 2);
    Point temp1 = r1.getUpperLeftVertex();
    REQUIRE(temp1.getX() == Approx(2));
    REQUIRE(temp1.getY() == Approx(2));
}
TEST_CASE("Rectangle/Shift1", "3 argument constructor")
{
    Point p1(0, 0);
    Rectangle r1(p1, 2, 4);
    Point temp = r1.getUpperLeftVertex();
    REQUIRE(temp.isSameAs(p1) == true);
    r1.shift(2, 2);
    temp = r1.getUpperLeftVertex();
    REQUIRE(temp.isSameAs(p1) == false);
    REQUIRE(temp.getX() == Approx(2));
    REQUIRE(temp.getY() == Approx(2));
}
TEST_CASE("Rectangle/getCenter", "2 argument constructor")
{
    Point p1(0, 0);
    Point p2(4, -4);
    Rectangle r1(p1, p2);
    REQUIRE(r1.getCenter().getX() == Approx(2));
    REQUIRE(r1.getCenter().getY() == Approx(-2));
}
TEST_CASE("Rectangle/getCenter1", "3 argument constructor")
{
    Point p1(0, 0);
    Rectangle r1(p1, 2, 4);
    REQUIRE(r1.getCenter().getX() == Approx(2));
    REQUIRE(r1.getCenter().getY() == Approx(-1));
}
TEST_CASE("Rectangle/Contains", "3 argument constructor")
{
    Point p1(0, 0);
    Rectangle r1(p1, 2, 4);
    REQUIRE(r1.contains(p1) == true);
    Point center(1, -2);
    Point temp = r1.getUpperLeftVertex();
    REQUIRE(temp.isSameAs(p1) == true);
    REQUIRE(r1.contains(center) == true);
}
TEST_CASE("Rectangle/contains1", "2 argument constructor")
{
    Point p1(0, 0);
    Point p2(4, -4);
    Rectangle r1(p1, p2);
    REQUIRE(r1.contains(p1) == true);
    REQUIRE(r1.contains(p2) == true);
    Point center = r1.getCenter();
    Point temp = r1.getUpperLeftVertex();
    REQUIRE(temp.isSameAs(p1) == true);
    REQUIRE(r1.contains(temp) == true);
    REQUIRE(r1.contains(center) == true);
}
