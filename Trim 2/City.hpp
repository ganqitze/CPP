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
#ifndef CITY_HPP
#define CITY_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include "LinkedList.h" 
#include "Attraction.hpp"
#include "Sport.hpp"
#include "Culture.hpp"
#include "Shopping.hpp"
using namespace std;

class City{
	int id;
	string name;
	LinkedList<Attraction*> Attractions;
public: 
	City(int cid, string cname, LinkedList<Attraction*>&Attractions): id(cid),name(cname),Attractions(Attractions){}
	void setName(string name);
	void setID(int id);
	int getID();
	string getName();
	string getAttractionTypeName(int pos);
	int getAttractionTypeID(int pos);
	string getAttractionName(int pos);
	string getAttractionDesc(int pos);
	int getAttractionID(int pos);
	int getAttractionLength();
	void displayByAttractions();
	void displayByType(int& y);
	void checkType(int position);
};
#include "City.cpp"
#endif