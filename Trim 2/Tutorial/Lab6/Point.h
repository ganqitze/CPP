#ifndef POINT
#define POINT

class Point 
{
  private:
    int x;
    int y;
  public:
    Point();
    Point(int seed);
    ~Point();
    int getX();
    int getY();
};

#endif
