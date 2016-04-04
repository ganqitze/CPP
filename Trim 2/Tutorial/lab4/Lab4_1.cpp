#include <iostream>
#include <string>
using namespace std;

class Human {
  string name;
 public:
  Human (string name) 
    : name(name) {}
  void shout()  { 
    cout << "I'm a human. Name = " << name << endl;
  }
  string getName()  { return name; }
};

class Student : public Human {
  int id;
 public:
  Student (string name, int id) 
    : Human(name), id(id) { }
};

int main() {
  Human *h1 = new Human("Michael");        // LINE1
  h1->shout();                             // LINE2
  delete h1;

  Student *s1 = new Student("Kelly", 111); // LINE3
  s1->shout();                             // LINE4

  h1 = new Student("Obama", 222);          // LINE5
  h1->shout();                             // LINE6
  delete h1;

  Human& hr = *s1;                         // LINE7
  hr.shout();                              // LINE8

  delete s1;
};