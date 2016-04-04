#include <iostream>
#include "Triangle.hpp"
using namespace std;

  

void Triangle::calcPerimeter() {
    double d1, d2, d3;
    d1 = p[0].distance(p[1]);
    d2 = p[1].distance(p[2]);
    d3 = p[2].distance(p[0]);
    perimeter = d1 + d2 + d3;
}

// void Triangle::set3Points () {
//     int x, y;

//     for (int i=0; i<3; i++) {
//         cout << "\nEnter a point: ";
//         cin >> x >> y;
//         p[i].setX(x);
//         p[i].setY(y);
//     }
//     calcPerimeter();
// }

void Triangle::display() {
    cout << "Points: ";
    for (int i=0; i<3; i++) {
        cout << "(" << p[i].getX() << "," << p[i].getY() << ") ";
    }
    cout << "\nPerimeter: " << perimeter;
}

