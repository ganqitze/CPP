#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape {
protected:
  double perimeter;
  virtual void calcPerimeter() = 0;
public:
  Shape() : perimeter(0) {}
  virtual void display()  = 0;
};

class Point : public Shape {
  int x;
  int y;
public:
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  int getX()  { return x; }
  int getY()  { return y; }
  double distance ( Point& p)  {
    int dx = x - p.x;
    int dy = y - p.y;
    return sqrt (dx*dx + dy*dy);
  }
  void calcPerimeter() { perimeter = 0; }
  void print()  { cout << "(" << x << "," << y << ")"; }
  void display()  { 
    cout << "Point:\n";
    cout << "(" << x << "," << y << ")\n";
    cout << "Perimeter = " << perimeter << endl;
  }
};

class Circle : public Shape {
  Point center;
  double radius;
public:
  Circle(Point center, double radius)
  : center(center), radius(radius) {
    calcPerimeter();
  }
  void calcPerimeter(){
    perimeter=2*3.14*radius;
  }
  void display()  { 
    cout << "Point:\n";
    cout << "(" << center.getX() << "," << center.getY() << ")\n";
    cout << "Perimeter = " << perimeter << endl;
  }
};

class Triangle : public Shape {
  Point points[3];
public:
  Triangle(Point p1, Point p2, Point p3) {
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    calcPerimeter();
  }
  void calcPerimeter(){
    double d1 = points[0].distance(points[1]);
    double d2 = points[1].distance(points[2]);
    double d3 = points[2].distance(points[0]);
    perimeter = d1+d2+d3;
  }
  void display()  { 
    cout << "Point:\n";
    for (int i = 0; i < 3; ++i)
      cout << "(" << points[i].getX() << "," << points[i].getY() << ")\n";
    cout << "Perimeter = " << perimeter << endl;
  }
};

int main() {
  Point p(1,1);
  Circle c(Point(1,1), 10); // radius = 10.
  Triangle t(Point(0,0), Point(3,0), Point(3,4));
  p.display();
  c.display();
  t.display();
}