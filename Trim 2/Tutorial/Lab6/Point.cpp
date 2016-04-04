#include <iostream>
#include "Point.h"

using namespace std;

Point::Point() 
  : x( 0 ), y( 0 )
{
  cout << "Default constructor called." << endl;
}

Point::Point(int seed) 
  : x(seed), y(seed) 
{
  cout << "Overloaded constructor called." << endl;
}

Point::~Point() 
{
  cout << "Destructor called." << endl; 
}

int Point::getX()
{
  return x; 
}

int Point::getY()
{
  return y;
}
