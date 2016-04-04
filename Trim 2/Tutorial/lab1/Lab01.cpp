#include <iostream>
#include <cmath>
using namespace std;

class Point {
  int x;
  int y;
 public:
  void setX (int x);
  void setY (int y);
  int getX();
  int getY();
  double distance (Point p);
};

class Triangle {
   Point p[3];
   double perimeter;
   void calcPerimeter();
 public:
   void set3Points();
   void display();
};


void Point::setX (int x){
	this -> x = x;
}

void Point::setY (int y){
	this -> y = y;
}

int Point::getX (){
	return x;
}

int Point::getY (){
	return y;
}

double Point::distance ( Point p){
	int dx = x-p.x;
	int dy = y-p.y;
	return sqrt(dx*dx + dy*dy);
}

void Triangle::calcPerimeter(){
	double p1 = p[0].distance(p[1]);
	double p2 = p[1].distance(p[2]);
	double p3 = p[2].distance(p[0]);
	cout << p1;
	cout << p2;
	cout << p3;
	perimeter = p1+p2+p3;
}

void Triangle::set3Points(){
	cout << "Enter 3 points in the following format: \n"
		 << "x1 y1 x2 y2 x3 y3 \n";
		 for (int i=0; i<3; i++){
		 	int x, y;
		 	cin >> x >> y;
		 	p[i].setX(x);
		 	p[i].setY(y);
		 }
		 calcPerimeter();
}

void Triangle::display(){
	cout << "Points\n";
	for (int i=0; i<3; i++){
		cout << "("
			 << p[i].getX() << "," << p[i].getY()
			 << ")\n";
	};
	cout << "perimeter: " << perimeter << "\n";

}

int main() {
  Triangle t;
  t.set3Points();
  t.display();
}