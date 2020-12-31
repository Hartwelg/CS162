#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle{
public:
    /**
     * @brief Rectangle creates a rectangle based on two given points
     * @param p1 first point to create rectangle with
     * @param p2 second point to create rectangle with
     */
    Rectangle(Point &p1, Point &p2);
    /**
     * @brief Rectangle creates a rectangle based on one point and width and height parameters
     * @param p1 top left vertex of rectangle
     * @param height height of the rectangle
     * @param width width of the rectangle
     */
    Rectangle(Point p1, double height, double width);
    /**
     * @brief getUpperLeftVertex gets the coordinates of the upper left vertex of the rectangle
     * @return upper left vertex of the rectangle
     */
    Point getUpperLeftVertex();
    /**
     * @brief getWidth gets the width of the rectangle
     * @return width of the rectangle
     */
    double getWidth();
    /**
     * @brief getHeight gets the height of the rectangle
     * @return height of the rectangle
     */
    double getHeight();
    /**
     * @brief getArea gets the area of the rectangle
     * @return orea of the rectangle
     */
    double getArea();
    /**
     * @brief getPerimeter gets the perimeter of the rectangle
     * @return perimeter of the rectangle
     */
    double getPerimeter();
    /**
     * @brief getCenter gets the ceter of the rectangle
     * @return center point of the rectangle
     */
    Point getCenter();
    /**
     * @brief shift moves the rectangle on the cartesian plane
     * @param xShift how far to shift the rectangle on the x axis
     * @param yShift how far to shift the rectangle on the y axis
     */
    shift(double xShift, double yShift);
    /**
     * @brief contains checks whether the rectangle contains a given point
     * @param p point to check within the rectangle
     * @return whether the point resides within the rectangle
     */
    bool contains(Point p);
private:
    Point upperLeftVertex;
    double height;
    double width;
};

#endif // RECTANGLE_H
