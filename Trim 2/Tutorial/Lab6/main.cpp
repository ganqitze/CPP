#include <iostream>
#include "Point.h"
using namespace std;

ostream& operator<< (ostream& os, Point& p)
{
  os << "(" << p.getX() << "," << p.getY() << ")";
  return os;
}

template <typename T>
void print (T *array, int size)
{
  if (size == 0)
  {
    cout << "Array is empty.\n";
    return;
  }
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}


template <typename T>
void addFront (T *&array, int& size, T& elementToInsert)
{
    int newsize = size+1;
    T *newArray = new T[newsize];
    for(int i=0; i<size; i++)
        newArray[i+1]= array[i];
    newArray[0]=elementToInsert;
    delete [] array;
    array = newArray;
    size =newsize;
}

template <typename T>
void addEnd (T *&array, int& size, T& elementToInsert)
{
    int newsize = size+1;
    T *newArray = new T[newsize];
    for(int i=0; i<size; i++)
        newArray[i]= array[i];
    newArray[newsize-1]=elementToInsert;
    delete [] array;
    array = newArray;
    size =newsize;
}

template <typename T>
void removeFront (T *&array, int& size)
{
    int newsize = size-1;
    T *newArray = new T[newsize];
    for(int i=0; i<newsize; i++)
        newArray[i]= array[i+1];
    delete [] array;
    array = newArray;
    size =newsize;
}

template <typename T>
void removeEnd (T *&array, int& size)
{
    int newsize = size-1;
    T *newArray = new T[newsize];
    for(int i=0; i<newsize; i++)
        newArray[i]= array[i];
    delete [] array;
    array = newArray;
    size =newsize;
}

int main()
{
  int seed = 0;         // seed for automatic value of x and y.
  int size = 0;         // array size.
  Point *points = NULL; // dynamic array.
  int choice; // user choice.
  Point newPoint;
  do {
    print (points, size);
    cout << "Choice:\n"
         << "1: Add new point at the front\n"
         << "2: Add new point at the end\n"
         << "3: Remove point at the front\n"
         << "4: Remove point at the end\n"
         << "Others: Exit\n";
    cin >> choice;
    switch (choice) {
      case 1 : newPoint = Point(++seed);
               addFront (points, size, newPoint); break;
      case 2 : newPoint = Point(++seed);
               addEnd (points, size, newPoint); break;
      case 3 : removeFront (points, size); break;
      case 4 : removeEnd (points, size); break;
    }
  } while (choice >= 1 && choice <= 4);
  print (points, size);
  if (size > 0)
    delete [] points;
}
