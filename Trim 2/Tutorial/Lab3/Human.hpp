#ifndef HUMAN_HPP
#define HUMAN_HPP
#include <iostream>
#include <string>
using namespace std;

class Human{
	protected:
	string name;
public:
	Human (string name):name(name){
		cout << "An human is created: Name = " << name << endl;
	};
	string getName(){return name;};
	void setName(string name){this->name = name;};
};

#endif