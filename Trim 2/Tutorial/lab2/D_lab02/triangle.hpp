#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "point.hpp"

class Triangle {
 Point p[3];
 double perimeter;
 void calcPerimeter();
public:
 void set3Points();
 void display();
 Triangle() :perimeter(0) {}
 Triangle (Point& x, Point& y, Point& z) {
 	p[0] = x;
 	p[1] = y;
 	p[2] = z;
 	calcPerimeter();
 }
};


#endif