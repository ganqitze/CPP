/********************************
Program: Tourists Best Friend
Course: TCP1201 OOPDS
Year: 2015/16 Trimester 2
Name: Gan Qi Tze
ID: 1142700525
Lecture: TC02
Lab: TT04
Email: ganqitze@gmail.com
Phone: 010-2527511
*********************************/
#ifndef CULTURE_HPP
#define CULTURE_HPP
#include <iostream>
#include <string>
#include "Attraction.hpp"
using namespace std;

class Culture : public Attraction{
	string entranceFees;
public:
	void display(){cout << getEntranceFees()<< ".\n";}
	Culture (int aid, string aname,int atype, string adesc) : Attraction(aid, aname, atype), entranceFees(adesc){;}
	void setEntranceFees(string entranceFees){this->entranceFees=entranceFees;}
	string getEntranceFees(){return entranceFees;}
};

#endif