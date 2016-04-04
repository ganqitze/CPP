#ifndef WORKINGSTUDENT_HPP
#define WORKINGSTUDENT_HPP
#include <iostream>
#include <string>
using namespace std;

class WorkingStudent : public Student, public Employee{
public: 
	WorkingStudent(string name, int id, double salary): Human(name), Student(name, id), Employee (name, salary) {
    cout << "A working student is created: Name = " << Student::getName()
         << ". Id = " << getId() << ". Salary = " << getSalary() << endl;
  };
	void print();
};

#endif