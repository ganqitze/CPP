#include <iostream>
#include <vector>
#include "triangle.hpp"
#include "point.hpp"
using namespace std;

int main() {
  int x,y,z=0;
  vector<Point> points;
  vector<Triangle> t;
  while(x!=-1){
  cout << "Enter a point (x y), type -1 to end : ";
  	x=0,y=0;
  	cin >> x;
  	if(x==-1) {break;} else {cin>>y;}
  	points.push_back(Point(x,y));
  }

  for (int i = 0; i < points.size(); i++) 
    cout << i << "  (" << points[i].getX() << "," << points[i].getY() << ")\n"; 
	x=0;
  while(x!=-1){
	  cout << "Select 3 points (x y z) to create triangle: ";
	  cin >> x;
	  if(x==-1) { break; } else { cin>> y >> z; }
 	 t.push_back(Triangle(points[x],points[y],points[z]));
	}
	cout << "\nTriangle created :\n";
    for (int i = 0; i < t.size(); i++) {
    	t[i].display();
    	cout << endl;
    }
}
