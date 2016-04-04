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
#ifndef ATTRACTION_HPP
#define ATTRACTION_HPP
#include <iostream>
#include <string>
using namespace std;

class Attraction{
	int id;
	string name;
	int typeID;
public:
	virtual void display()=0 ;
	Attraction(int aid, string aname,int atype):id(aid), name(aname),typeID(atype){}
	void setName(string name){this->name=name;}
	void setID(int id){this->id=id;}
	void settypeID(int typeID){this->typeID = typeID;}
	int getID(){return id;}
	string getName(){return name;}
	int gettypeID(){return typeID;}
};
#endif