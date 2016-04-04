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
#include "City.hpp"  // Header file
#include <iostream>
#include <string>

void City::setName(string name){
	this->name=name;
}

void City::setID(int id){
	this->id=id;
}

int City::getID(){
	return id;
}

string City::getName(){
	return name;
}

string City::getAttractionName(int pos){
	return Attractions.getEntry(pos)->getName();
}

int City::getAttractionID(int pos){
	return Attractions.getEntry(pos)->getID();
}

string City::getAttractionDesc(int pos){
	if (Attractions.getEntry(pos)->gettypeID() == 1){
		Sport *pointer = dynamic_cast<Sport*>(Attractions.getEntry(pos));					
		return pointer->getAgeLimit();
	}
	if (Attractions.getEntry(pos)->gettypeID() == 2){
		Culture *pointer = dynamic_cast<Culture*>(Attractions.getEntry(pos));				
		return pointer->getEntranceFees();
	}
	if (Attractions.getEntry(pos)->gettypeID() == 3){
		Shopping *pointer = dynamic_cast<Shopping*>(Attractions.getEntry(pos));				
		return pointer->getMalls();		
	}
}


int City::getAttractionLength(){
	return Attractions.getLength();
}

int City::getAttractionTypeID(int pos){
	return Attractions.getEntry(pos)->gettypeID();
}

string City::getAttractionTypeName(int pos){
	if(Attractions.getEntry(pos)->gettypeID() == 1)
		return "Sport";
	else if(Attractions.getEntry(pos)->gettypeID() == 2)
		return "Culture";
	else if(Attractions.getEntry(pos)->gettypeID() == 3)
		return "Shopping";
}

void City::displayByAttractions(){
	system("cls");
	cout << " You have chosen sort by Attraction.";
	cout << "\n\n Here are the Attractions.\n";
	for (int m = 1; m <= (int)Attractions.getLength(); m++){
		cout << " "<< m << ".  " << Attractions.getEntry(m)->getName() << endl;
	}
	cout << "\n Input the exact name >>  ";
	bool input5(false); 
	int position(0); 
	string z;
	cin.sync();
	getline(cin, z);	
	while(!input5){							//input error handlings, no case sensitive
		for(int o=0; o<z.length(); o++){
			z[o]=tolower(z[o]); 
		}
		for(int p=0;p<z.length();p++){
			if(isspace(z[p])) 
				z[p+1]=toupper(z[p+1]);
		}
		z[0]=toupper(z[0]); 
		try{					
			for (int m = 1; m <= (int)Attractions.getLength(); m++){
				if(z==Attractions.getEntry(m)->getName()) {
					position=m;
					input5=true;
				}
			}
			if(input5==false) throw z;
		}
		catch(...){
			cout << " Input incorrect. Please enter the exact name >>  "; 
			cin.sync();
			getline(cin, z);
		}
	}	
	checkType(position);
}

void City::displayByType(int& y){
	int counter(0), temp(0), position(0); 
	string z;
	for (int m = 1; m <= (int)Attractions.getLength(); m++){
		if(Attractions.getEntry(m)->gettypeID()==y){
			counter++;
			temp=m;
		}
	}												//if the type having only one attraction, it will straight display the attraction and its description.
	if(counter>1){								// or else it require user to choose which attraction he want to visit
		cout << "\n Here are the Attractions.\n";								
		counter=0; 	
		bool input4(false);		
		for (int m = 1; m <= (int)Attractions.getLength(); m++){
			if(Attractions.getEntry(m)->gettypeID()==y){
				counter++;
				cout << " " << counter  << ". " << Attractions.getEntry(m)->getName() << endl;
			}
		}
		cout << "\n Input the exact name >>  ";
		cin.sync();	
		getline(cin, z);
		while(!input4){					//input error handlings, no case sensitive
			for(int o=0; o<z.length(); o++){
				z[o]=tolower(z[o]); 
			}
			for(int p=0;p<z.length();p++){
				if(isspace(z[p]))  
					z[p+1]=toupper(z[p+1]);
			}
			z[0]=toupper(z[0]);
			try{
				for (int m = 1; m <= (int)Attractions.getLength(); m++){
					if(Attractions.getEntry(m)->gettypeID()==y && Attractions.getEntry(m)->getName()==z){
						position=m;
						input4=true;
					}
				}
				if (input4==false)throw z;
			}
			catch(...){
				cout << " Input incorrect. Please enter the exact name >>  "; 
				cin.sync();
				getline(cin, z);
			}
		}	
		checkType(position);													
	} else{ 
		checkType(temp);
	}
}

void City::checkType(int position){
	system("CLS");
	cout << "\n The city chosen is " << City::getName() << ".";
	cout << "\n The attraction is " << Attractions.getEntry(position)->getName() << ".";
	if (Attractions.getEntry(position)->gettypeID() == 1){
		cout << "\n The age limit for " <<Attractions.getEntry(position)->getName() << " is ";
		Sport *pointer = dynamic_cast<Sport*>(Attractions.getEntry(position));					
		pointer->display();
	}
	if (Attractions.getEntry(position)->gettypeID() == 2){
		cout << "\n The entrance fees for " <<Attractions.getEntry(position)->getName() << " is:\n ";
		Culture *pointer = dynamic_cast<Culture*>(Attractions.getEntry(position));				
		pointer->display();
	}
	if (Attractions.getEntry(position)->gettypeID() == 3){
		cout << "\n " << Attractions.getEntry(position)->getName() << " is ";
		Shopping *pointer = dynamic_cast<Shopping*>(Attractions.getEntry(position));				
		pointer->display();		
	}
}
//  End of implementation file.
