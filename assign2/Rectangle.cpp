#include <iostream>
#include <cmath>

#include "Rectangle.h"
#include "Point.h"

using namespace std;

Rectangle::Rectangle(Point p1, double heightValue, double widthValue)
{
    upperLeftVertex = p1;
    height = abs(heightValue);
    width = abs(widthValue);
}
Rectangle::Rectangle(Point& p1, Point& p2)
{
    upperLeftVertex = p1;
    height = abs(p2.getY()) - abs(p1.getY());
    width = abs(p2.getX()) - abs(p1.getY());
}
Point Rectangle::getUpperLeftVertex()
{
    return upperLeftVertex;
}
double Rectangle::getWidth()
{
    return width;
}
double Rectangle::getHeight()
{
    return height;
}
double Rectangle::getArea()
{
    return width * height;
}
double Rectangle::getPerimeter()
{
    return 2 * width + 2 * height;
}
Point Rectangle::getCenter()
{
    Point center;
    double newX = upperLeftVertex.getX() + (width / 2);
    double newY = upperLeftVertex.getY() - (height / 2);
    center.setX(newX);
    center.setY(newY);
    return center;
}
Rectangle::shift(double x, double y)
{
    upperLeftVertex.translate(x, y);
}
bool Rectangle::contains(Point p)
{
    if (p.getX() >= upperLeftVertex.getX() && p.getX() <= upperLeftVertex.getX() + width)
    {
        if (p.getY() <= upperLeftVertex.getY() && p.getY() >= upperLeftVertex.getY() - height)
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
