#include <iostream>
#include "triangle.hpp"

using namespace std;

// void Triangle::set3Points(){
//   for(int i=0;i<3;i++){
//     int x,y;
//     cin >> x;
//     p[i].setX(x);
//     cin >> y;
//     p[i].setY(y);
//   }
//   calcPerimeter();
// }

void Triangle::display(){
  cout << "Points:\n";
  for (int i=0;i<3;i++){
    cout << "(" << p[i].getX() << "," << p[i].getY() << ")\n";
  }
  cout << "Perimeter: " << perimeter << endl;
}

void Triangle::calcPerimeter() {
  double d1 = p[0].distance(p[1]);
  double d2 = p[1].distance(p[2]);
  double d3 = p[2].distance(p[0]);
  perimeter = d1 + d2 + d3;
}