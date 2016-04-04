#include <iostream>
#include "Point.h"
using namespace std;

ostream& operator<< (ostream& os, Point& p)
{
    os << "(" << p.getX() << "," << p.getY() << ")";
  return os;
}

template <typename T>
struct Node
{
  T info;
  Node<T> *next;
};

template <typename T>
void print (Node<T> *start)
{
  if (start == nullptr)
  {
    cout << "List is empty.\n";   // cout a meesage if the list is empty.
    return;
  }
  Node<T> *ptr = start;
  while (ptr != nullptr)        // while not at the end of list
  {
    cout << ptr->info << " ";
    ptr = ptr->next;             // move to next node.
  }
  cout << endl;
}

template <typename T>
void addFront(Node<T> *&start, T& newPoint)
{
    Node<T>*newNode = new Node<T>;
    newNode->info = newPoint;
    newNode->next = start;
    start = newNode;
}

template <typename T>
void addEnd(Node<T> *&start, T& newPoint)
{
    Node<T>*temp = start;
    while(temp->next!=nullptr){
        temp=temp->next;

    }
    Node<T>*newNode = new Node<T>;
    newNode->info = newPoint;
    newNode->next = nullptr;

    temp->next = newNode;

}

template <typename T>
void removeFront(Node<T> *&start)
{
    if(start == nullptr){
        return;
    }
    else{
        Node<T>*newNode = start;
        start = start->next;
        delete newNode;
    }
}

template <typename T>
void removeEnd(Node<T> *&start)
{
    if(start == nullptr){
        return;
    }
    else if(start->next == nullptr){
        Node<T>*temp = start->next;
        delete temp;
        start = nullptr;
    }
    else{
        Node<T>*prevtemp = start;
        Node<T>*lasttemp = start;
        while(lasttemp->next!=nullptr){
            prevtemp=lasttemp;
            lasttemp=lasttemp->next;
        }
        delete lasttemp;
        prevtemp->next = nullptr;
    }

}

int main()
{
  int seed = 0;         // seed for automatic value of x and y.
  Node<Point> *start = nullptr;
  int choice; // user choice.
  Point newPoint;
  do
  {
    print(start);
    cout << "Choice:\n"
         << "1: Add new point at the front\n"
         << "2: Add new point at the end\n"
         << "3: Remove point at the front\n"
         << "4: Remove point at the end\n"
         << "Others: Exit\n";
    cin >> choice;
    switch (choice)
    {
      case 1 :
        newPoint = Point(++seed);
        addFront(start, newPoint);
        break;
      case 2 :
        newPoint = Point(++seed);
        addEnd(start, newPoint);
        break;
      case 3 :
        removeFront(start);
        break;
      case 4 :
        removeEnd(start);
        break;
    }
  } while (choice >= 1 && choice <= 4);
  print(start);
}
