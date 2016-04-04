#include <iostream>
#include <vector>
#include "Triangle.hpp"
using namespace std;
// int main() {
//   Triangle t;
//   t.set3Points();
//   t.display();
// }



int main(){

	vector <Point> p;
	vector <Triangle> ta;
	int x(0); int y(0); int z(0);

	while(x!=-1){
		
		cout << "enter points, end when enter -1.\n";
		cin >> x;
		if (x ==-1){break;} else {cin >> y;}
		p.push_back(Point (x, y));
	}
	//loop for input
	//display all the point
	//create triangle using points selected vector Triangle
	//display point same as triangle.cpp..loop


	for (int i = 0; i < p.size(); i++) 
		cout << "(" << p[i].getX() << "," << p[i].getY() << ")\n"; 

	cout << "\nTriangle ";
	ta.push_back(Triangle(p[0],p[1],p[2]));
	ta[0].display();
}

