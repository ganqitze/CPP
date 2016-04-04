#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Point{
	int x, y;
	public:
	Point (int x=0, int y=0): x(x), y(y){}
	int getX(){return x;}
	int getY(){return y;}
	friend istream& operator>>(istream& is, Point& p);
};

class SortByYX{
	public:
		bool operator()(Point p, Point q){
			if (p.getY()==q.getY())
				return p.getX()< q.getX();
			return p.getY()< q.getY();
		}
};

class SortByXY{
	public:
		bool operator()(Point p, Point q){
			if (p.getX()==q.getX())
				return p.getY()< q.getY();
			return p.getX()< q.getX();
		}
};

bool operator==(Point p, Point q){
	return(p.getX()==q.getX() && q.getY()==p.getY());
}

istream& operator>>(istream& is, Point& p){
	is >> p.x >> p.y;
	return is;
}

ostream& operator<<(ostream& os, Point& p){
	os << "(" << p.getX() << ", " << p.getY() << ")";
	return os;
}


int main() {
  vector<Point> v;
  Point p;
  do {
    cout << "Input a Point (0 0 to end): ";
    cin >> p;
    if (p == Point(0,0)) break;
    v.push_back (p);
  } while (true);

  cout << "Sort points by x then y:\n";
  sort (v.begin(), v.end(), SortByXY());
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;

  cout << "Sort points by y then x:\n";
  // Add one line of code to sort.
  sort (v.begin(), v.end(), SortByYX());
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}
