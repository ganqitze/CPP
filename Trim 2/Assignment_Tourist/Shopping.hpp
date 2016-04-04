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
#ifndef SHOPPING_HPP
#define SHOPPING_HPP
#include <iostream>
#include <string>
#include "Attraction.hpp"
using namespace std;

class Shopping : public Attraction{
	string malls;
public:
	void display(){cout << getMalls()<< ".\n";}
	Shopping (int aid, string aname,int atype, string adesc) : Attraction(aid, aname, atype), malls(adesc){}
	void setMalls(string malls){this->malls=malls;}
	string getMalls(){return malls;}
};

#endif