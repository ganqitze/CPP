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
#ifndef SPORT_HPP
#define SPORT_HPP
#include <iostream>
#include <string>
#include "Attraction.hpp"
using namespace std;

class Sport : public Attraction{
	string ageLimit;
public:
	void display(){cout << getAgeLimit()<< ".\n";}
	Sport (int aid, string aname,int atype, string adesc) : Attraction(aid, aname, atype), ageLimit(adesc){}
	void setAgeLimit(string ageLimit){this->ageLimit=ageLimit;}
	string getAgeLimit(){return ageLimit;}
};
#endif