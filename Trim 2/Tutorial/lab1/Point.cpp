#include <cmath>
#include "Point.hpp"
using namespace std;



void Point::setX (int x) {
    this->x = x;
}

void Point::setY (int y) {
    this->y = y;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

double Point::distance (Point& p) {
    int dx = x - p.x;
    int dy = y - p.y;
    return sqrt (dx*dx + dy*dy);

}


