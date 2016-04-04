#ifndef POINT_HPP
#define POINT_HPP

class Point {
  int x;
  int y;
public:
  void setX (int x);
  void setY (int y);
  int getX();
  int getY();
  double distance (Point p);
  Point(int x=0, int y=0) :x(x) , y(y) {}
};

#endif