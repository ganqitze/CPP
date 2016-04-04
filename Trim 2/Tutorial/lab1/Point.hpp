
class Point {
  int x;
  int y;
 public:
 	Point() : x(0), y(0) {}
	Point(int x) : x(x), y(0) {}
	Point(int x, int y) : x(x), y(y) {}

  void setX (int x);
  void setY (int y);
  int getX();
  int getY();
  double distance (Point& p);
};

