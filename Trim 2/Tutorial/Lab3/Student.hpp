#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <iostream>
#include <string>
using namespace std;

class Student : virtual public Human{
	protected:
	int id;
public:
	Student(string name, int id):Human(name), id(id){
		cout << "An student is created: Name = " << name << " ID = " << id << endl;
	};
	int getId(){return id;};
	void setId(int id){this->id = id;};
};
#endif