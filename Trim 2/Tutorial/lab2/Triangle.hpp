
#include "Point.hpp"


class Triangle {
   Point p[3];
   double perimeter;
   void calcPerimeter();

 public:
	   Triangle (Point& p1, Point& p2, Point& p3){
    p[0] = p1;
    p[1] = p2;
    p[3] = p3;
    calcPerimeter();}
   void set3Points();
   void display();
};

