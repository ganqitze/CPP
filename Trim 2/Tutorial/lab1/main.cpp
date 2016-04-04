#include <iostream>
#include "Triangle.hpp"
using namespace std;
// int main() {
//   Triangle t;
//   t.set3Points();
//   t.display();
// }



int main(){
	Point p[] = { Point(), Point(1), Point(2,3) };
	for (int i = 0; i < 3; i++) 
		cout << "(" << p[i].getX() << "," << p[i].getY() << ")\n"; 

	cout << "\nTriangle ";
	Triangle t;
	t.display();
}
