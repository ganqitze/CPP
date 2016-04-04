#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <iostream>
#include <string>
using namespace std;

class Employee : virtual public Human{
	protected:
	double salary;
public: 
	Employee (string name, double salary) : Human(name), salary(salary){
		cout << "An Employee is created: Name = " << name << " Salary = " << salary << endl;
	}
	double getSalary(){return salary;};
	void setSalary(double salary){this->salary = salary;};
};

#endif