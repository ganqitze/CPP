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

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <windows.h>
#include "City.hpp"
#include "Flight.hpp"
#include "LinkedList.h" 
#include "LinkedStack.h"
using namespace std;

LinkedList<string> Ctemp;
LinkedList<string> Atemp;
LinkedList<int> cid;
LinkedList<string> cname;
LinkedList<int> aid;
LinkedList<string> aname;
LinkedList<string> adesc;
LinkedList<int> atype;
LinkedList<int> FlightCity;
LinkedList<Attraction*> Attractions;
LinkedList<City*> Cities;

void fullscreen();
void loadCity();
void loadAttraction();
void loadFlight();
void breakevenvec();
void DontKnowWhatName();
void sortCities();
void UserAttractionPanel();
int askcity();
void SortByType(int& x);
void DisplayAll();
void DisplayFlight();
void AdminPanel();
void UserFlightPanel(); 

int main(){	
	system("CLS");
	int OriCity, DestCity;	
	char c(' ');
	string LogIn, selection;
	bool input8(false), input9(false), input10(false);
	string password("");
	cout << " Hi!\n Login as\n 1. User\n 2. Admin\n 3. Help\n 4. Quit\n >> ";
	cin >> LogIn;
	while(!input8){
		try{
			if(	LogIn.length()>1 || (LogIn!="1"&& LogIn!="2"&& LogIn!="3" && LogIn!="4" )) throw LogIn;
			else if (LogIn =="1"){
				input8=true;
				system("CLS");
				cout << " Search for\n 1. Attraction\n 2. City Connections Flight\n 3. Back\n >> ";
				cin >> selection;
				while(!input9){
					try{
						if(selection.length()>1 || (selection !="1" && selection !="2" && selection!="3")) throw selection;	
						else input9 = true;				 
					}
					catch(...){
						cin.clear(); cin.ignore();
						cout << " Input incorrect. Please enter either 1 or 2  >> "; 
						cin >> selection;
					}
				}
				if(selection=="1")	UserAttractionPanel();			
				else if(selection=="2")	UserFlightPanel();
				else if (selection =="3") main();
			}
			else if(LogIn=="2"){
				input8=true;
				system("CLS");
				cout << " Welcome back! Admin. \n";
				cout << " Please input \"password\" to login.  ";
				while(c!=13){
					c=getch();
					if(c!=13){
						password+=c;
						cout << "*";
					}
				}
				while(!input10){
					for(int o=0; o<password.length(); o++)
						password[o]=tolower(password[o]); 
					if(password == "password"){
						input10 = true;
					}	
					else{
						cout << endl;
						c=' '; password="";
						cout << " Input incorrect. Please enter \"password\" to login. >>  "; 
						while(c!=13){
							c=getch();
							if(c!=13){
								password+=c;
								cout << "*";
							}
						}
					}
				}
				if(input10) AdminPanel();
			}
			else if(LogIn=="3"){
				string a = "Documentation.pdf";
				cout << "\n Please close the file in order to proceed. ";
				system(a.c_str());
				main();
			}
			else if(LogIn=="4") exit(0);
		}		
		catch(...){
			cin.clear(); cin.ignore(); 
			cout << " Input incorrect. Please in range of 1 to 3 >>  "; 
			cin >> LogIn;
		}
	}	
	return 0;
}

//This Initiates the fullscreen function
void fullscreen(){
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

ostream& operator<< (ostream& os, City& p){				//to print all the city name
	return os << p.getName() <<  endl; 
}

template <typename T>
string NumberToString( T Number ){
	stringstream ss;
	ss << Number;
	return ss.str();
}

void loadCity(){					//read and load all the City data from csv file
	Ctemp.clear();
	string CityData;
	ifstream IfCity;	
	IfCity.open("City.csv");
	if(IfCity.fail()){
		cout << "Fail to load file.\n";
		cout <<"bye\n";
	}
	else{
		int i=1;
		while(!IfCity.eof()){
			while(getline(IfCity, CityData, '\n')){
				stringstream ss(CityData);
				string temp;
				i=1;
				while(getline(ss, temp, ',')){
					Ctemp.insert(i, temp);
					i++;
				}				
			}
			
		}		
	}
	IfCity.close();
	loadAttraction();
}

void loadAttraction(){					//read and load all the Attraction data from csv file
	Atemp.clear();
	string AttractionData;
	ifstream IfAttraction;	
	IfAttraction.open("Attraction.csv");	
	if(IfAttraction.fail()){
		cout << "Fail to load file.\n";
		cout <<"bye\n";
	}
	else{
		int i=1;
		while(!IfAttraction.eof()){
			while(getline(IfAttraction, AttractionData, '\n')){
				stringstream ss(AttractionData);
				string temp;
				i=1;
				while(getline(ss, temp, ',')){
					Atemp.insert(i, temp);
					i++;
				}				
			}
			
		}		
	}	
	IfAttraction.close();
	breakevenvec();
}

void loadFlight(){					//read and load all the Flight data from csv file
	FlightCity.clear();
	Flight f(Cities.getLast()->getID());
	ifstream fin;   
	string FlightData; 
	string convert; 
	fin.open("Flight.csv");
	if(fin.fail()){
		cout << "Fail to load file.\n";
		cout <<"bye\n";
	}
	else{
		while(!fin.eof()){
			while(getline(fin, FlightData, '\n')){
				stringstream ss(FlightData);
				string temp;
				while(getline(ss, temp, ',')){
					int a = atoi((temp).c_str());
					FlightCity.push_back(a);
				} 
				f.addEdge(FlightCity.getEntry(1), FlightCity.getEntry(2)); 
				FlightCity.clear();   
			}
		}       
	}
	fin.close();
	f.display();
}

void breakevenvec(){								//Breaking all the data to itself into Linkedlist
	string Convert;	cid.clear(); cname.clear(); aid.clear();aname.clear();atype.clear(); adesc.clear();
	for (int data = Ctemp.getLength(); data > 0; data=data-2){
		Convert = Ctemp.getEntry(data-1);				
		if (Convert!=""){
			int a = atoi((Convert).c_str());
			if (a!=0) cid.push_back(a);			
		}
		if (Ctemp.getEntry(data)!="")	cname.push_back(Ctemp.getEntry(data));		
	}
	for (int data = Atemp.getLength(); data > 0; data=data-4){
		Convert = Atemp.getEntry(data-3);				
		if (Convert!=""){
			int a = atoi((Convert).c_str());
			if (a!=0) atype.push_back(a);			
		}
		Convert = Atemp.getEntry(data-2);					
		if (Convert!=""){
			int a = atoi((Convert).c_str());
			if (a!=0) aid.push_back(a);			
		}	
		if (Atemp.getEntry(data-1)!="")	aname.push_back(Atemp.getEntry(data-1));				
		if (Atemp.getEntry(data)!="") adesc.push_back(Atemp.getEntry(data));				
	}	
	Atemp.clear();Ctemp.clear();
}

void DontKnowWhatName(){
	Attractions.clear(); Cities.clear();
	loadCity();
	for(int k=1;k<=cid.getLength();k++){					//loading data values into the classes
		for(int v=1;v<=aid.getLength();v++){
			if(aid.getEntry(v)/100 == cid.getEntry(k)){
				if (atype.getEntry(v) == 1) 
					Attractions.push_back(new Sport(aid.getEntry(v), aname.getEntry(v), atype.getEntry(v), adesc.getEntry(v)));
				if (atype.getEntry(v) == 2)
					Attractions.push_back(new Culture(aid.getEntry(v), aname.getEntry(v), atype.getEntry(v), adesc.getEntry(v)));
				if (atype.getEntry(v) == 3)
					Attractions.push_back(new Shopping(aid.getEntry(v), aname.getEntry(v), atype.getEntry(v), adesc.getEntry(v)));
			}
		}				
		if(Attractions.getLength()>0){
			Cities.push_back(new City(cid.getEntry(k), cname.getEntry(k), Attractions));				
			Attractions.clear();
		}
	}
	cname.clear();aid.clear();aname.clear();adesc.clear();atype.clear();cid.clear();
	sortCities();
}

void sortCities(){
	string name1, name2;
	for (int i = 1; i <= Cities.getLength(); i++){
		for(int j = i+1; j <= Cities.getLength(); j++){
			name1 = Cities.getEntry(i)->getName();
			name2 = Cities.getEntry(j)->getName();
			if(name1[0] > name2[0])
				Cities.swap(i, j);
		}
	}
}

void UserAttractionPanel(){
	Cities.clear();
	DontKnowWhatName();
	char yorb;
	string f;
	int x=askcity(); 
	bool input(false), input2(false);
	cout << "\n Sort by?:\n 1.  Type\n 2.  Attraction\n Input the number >>  ";	//user can choose whether thro type or straight to the attractions itself
	cin >> f;											
	while(!input2){									
		try{
			if(f=="1" || f=="2") input2=true;
			else throw f;
		}
		catch(...){
			cin.clear(); cin.ignore();
			cout << " Input incorrect. Please enter the valid number >>  "; 
			cin >> f;
		}
	}
	if (f=="1") SortByType(x);
	else if (f=="2") Cities.getEntry(x)->displayByAttractions();
	cout << "\n ";system ("pause");
	cout << " Do you wish to continue(Y) OR  go back to menu(B)? ";
	cin >> yorb; 	
	while(!input){
		try{
			if (yorb == 'Y' || yorb == 'y')
				UserAttractionPanel();
			else if(yorb == 'B' || yorb == 'b')
				main();
			else
				throw yorb;
		}
		catch(...){
			cin.clear(); cin.ignore();
			cout << " Input incorrect. Please enter either Y or B >> "; 
			cin >> yorb;
		}
	} 										
}

int askcity(){								//first step, asking user which city he want to visit.
	string y;
	int x(0);
	system("CLS");
	bool input1(false);
	cout << " Hello there. \n Please choose a city.\n"; 
	for (int i=1; i<=Cities.getLength(); i++)
		cout << " " << Cities.getEntry(i)->getID() << ".  " << Cities.getEntry(i)->getName() <<endl; 
	cout << " Input the number >>  ";
	cin >> y; 
	while(!input1){							
		try{		
			istringstream (y) >> x;
			if(!(istringstream (y) >> x)) throw y;
			for(int i=1; i<=Cities.getLength();i++){
				if(x == Cities.getEntry(i)->getID())
					input1 = true;
			}
			if(!input1) throw x;

		}
		catch(...){
			cin.clear(); cin.ignore();
			cout << " Input incorrect. Please enter the valid number >>  "; 
			cin >> y;
		}
	}
	return x;
}

void SortByType(int& x){
	system("CLS");
	cout << " You have chosen sort by Type.";
	cout << "\n\n Here are the Type.\n";
	cout << " 1. Sport\n 2. Culture\n 3. Shopping";				//having for user to choose among these 3 types
	cout << "\n Input the number >>  ";
	bool input3(false);
	string xx;
	int y(0);
	cin >> xx;
	while(!input3){										
		try{
			if(xx=="1" || xx=="2" || xx=="3") input3=true;
			else throw xx;
		}
		catch(...){
			cin.clear(); cin.ignore();
			cout << " Input incorrect. Please enter the valid number >>  "; 
			cin >> xx;
		}
	}
	y= atoi((xx).c_str());
	Cities.getEntry(x)->displayByType(y);
}

void DisplayAll(){
	system("CLS");	
	cout << "\n All Records Table\n" 
	<< " +--------------------+---------------------------------+----------------+\n"
	<<" |    City ID, Name   |    Attraction ID, Name          |  Type ID, Name |\n" 
	<< " +--------------------+---------------------------------+----------------+\n";
	for(int i=1; i<= Cities.getLength(); i++){
		for (int j=1; j<=Cities.getEntry(i)->getAttractionLength(); j++){
			cout << " | ["<<Cities.getEntry(i)->getID() << "] "<<setw(14) <<left <<Cities.getEntry(i)->getName()<<" | ";
			cout <<"[" << Cities.getEntry(i)->getAttractionID(j)<< "] " << setw (25) << Cities.getEntry(i)->getAttractionName(j)<<" | ";
			cout <<"[" << Cities.getEntry(i)->getAttractionTypeID(j)<< "] " << setw (10) << Cities.getEntry(i)->getAttractionTypeName(j) << " | " << endl;
		}
	}
	cout << " +====================+=================================+================+\n";
}

void DisplayFlight(){
	Flight f(Cities.getLength());
	cout <<" |                     City Flight Connection Lines                      |\n"
	<<" +-----------------------------------------------------------------------+\n";
	loadFlight();
	cout <<" +-----------------------------------------------------------------------+\n";
}

void AdminPanel(){
	fullscreen();
	char choice, yesorno;
	int i(0), j, IDChecker, rename_file, IDChecker2, intTemp, intTemp2;
	string newRecord, oldRecord, temp, temp2, temp3, newRecord2, newRecord3, stringTemp, inputE1, inputE2, inputE3, inputE4, huehue;
	ifstream fin;
	ofstream fout;
	bool done(false);
	do{	
		bool input(false), admin(false), admin2(false), admin3(false), admin4(false);
		DontKnowWhatName();
		DisplayAll();
		DisplayFlight();
		cout << endl;
		cout << "  1. Add a New City Record" << endl;				
		cout << "  2. Edit a City Record" << endl;					
		cout << "  3. Remove a City Record" << endl;				
		cout << "  4. Add a New Attraction Record" << endl;				
		cout << "  5. Edit a Attraction Record" << endl;					
		cout << "  6. Remove a Attraction Record" << endl;		
		cout << "  7. Add City Connections Record" << endl;
		cout << "  8. Edit City Connections Record" << endl;
		cout << "  9. Remove City Connections Record" << endl;	
		cout << "  Q. Back" << endl;								
		cout << "  => "; 
		cin >> choice;
		choice = toupper(choice);
		cout << endl;
		switch( choice ){
			case '1' :	cout << " Please enter a new City name you wish to add >> ";
				cin >> newRecord;
				cout << " Confirm to add a new City Record (Y/N)? >> ";
				cin >> yesorno;													
				if(yesorno=='Y' || yesorno=='y'){
					fin.open("City.csv");
					fout.open("temp.csv");
					while(getline(fin, oldRecord))
						fout << oldRecord << endl;
					fout << Cities.getLast()->getID()+1 << ","<< newRecord;
					fout.close();
					fin.close();
					remove("City.csv");
					rename_file = rename( "temp.csv" , "City.csv" );
					if(rename_file==0)  puts ( "City file successfully updated" );
					else perror( "Error updating file" );
					fin.open("Attraction.csv");
					fout.open("temp.csv");
					newRecord = "N/A";
					while(getline(fin, oldRecord))
						fout << oldRecord << endl;
					fout << 1 << ","<< (Cities.getLast()->getID()+1)*100+1 << "," << newRecord << "," << newRecord<<endl;
					fout.close();
					fin.close();
					remove("Attraction.csv");
					rename_file = rename( "temp.csv" , "Attraction.csv" );
				}
			break;
			case '2' :	cout << " Please enter the City ID you wish to edit >> ";
				cin >> inputE1;												
				while(!admin){
					try{
						istringstream (inputE1) >> IDChecker;
						if(!(istringstream (inputE1) >> IDChecker)) throw inputE1;
						for( i=1; i<=Cities.getLast()->getID();i++){
							if(IDChecker == Cities.getEntry(i)->getID()){
								admin = true;break;
							}
								
						}
						if(!admin) throw IDChecker;
					}
					catch(...){
						cin.clear(); cin.ignore();
						cout << " Input incorrect. Please enter the valid City ID >>  "; 
						cin >> inputE1;												
					}
				}
				cout << " Please enter a new City name >> ";
				cin >> newRecord;
				cout << " Confirm to edit a City Record (Y/N)? >> ";
				cin >> yesorno;
				if(yesorno=='Y' || yesorno=='y'){
					fin.open("City.csv");
					fout.open("temp.csv");
					temp = NumberToString(IDChecker);
					temp2 = temp+','+Cities.getEntry(i)->getName();
					while(getline(fin, oldRecord)){
						if(oldRecord!=temp2)
							fout << oldRecord << endl;
						else fout << IDChecker << ',' << newRecord << endl;
					}
					fout.close();
					fin.close();
					remove("City.csv");
					rename_file = rename( "temp.csv" , "City.csv" );
					if(rename_file==0) puts ( "City file successfully updated" );
					else perror( "Error updating file" );
				}
			break;
			case '3' :	cout << " Please enter the City ID you wish to remove >> ";
				cin.sync();
				getline(cin, inputE1);									
				while(!admin){
					try{
						istringstream (inputE1) >> IDChecker;
						if(!(istringstream (inputE1) >> IDChecker)) throw inputE1;
						for( i=1; i<=Cities.getLast()->getID();i++){
							if(IDChecker == Cities.getEntry(i)->getID()){
								admin = true;break;
							}
						}
						if(!admin) throw IDChecker;
					}
					catch(...){
						inputE1.clear(); 
						cout << " Input incorrect. Please enter the valid City ID >>  "; 
						cin.sync();getline(cin, inputE1);									
					}
				}
				cout << " Confirm to remove a City Record (Y/N)? >> ";
				cin >> yesorno;
				if(yesorno == 'Y' || yesorno == 'y'){
					fin.open("City.csv");
					fout.open("temp.csv");
					newRecord = Cities.getEntry(i)->getName();
					temp = NumberToString(IDChecker);
					temp2 = temp+','+newRecord;
					while(getline(fin, oldRecord)){
						if(oldRecord!=temp2)	
							fout << oldRecord << endl;
					}
					fout.close();
					fin.close();
					remove("City.csv");
					rename_file = rename( "temp.csv" , "City.csv" );
					if(rename_file==0)  puts ( "City file successfully updated" );
					else perror( "Error updating file" );
					fin.open("Flight.csv");
					fout.open("temp.csv");
					while(getline(fin, oldRecord)){
						admin4=false;
						for(int k=1; k<=Cities.getLast()->getID(); k++){
							temp3=NumberToString(k-1)+','+NumberToString(IDChecker-1);
							stringTemp = NumberToString(IDChecker-1)+','+NumberToString(k-1);
							if(oldRecord==temp3 || oldRecord==stringTemp){
								admin4=true;break;
							}
						}	
						if(!admin4)
							fout << oldRecord << endl;
					}
					fout.close();
					fin.close();
					remove("Flight.csv");
					rename_file = rename( "temp.csv" , "Flight.csv" );
				}
			break;
			case '4' :	cout << " Please enter a new Attraction Name, Type ID and Description you wish to add >> ";
				cin >> newRecord >> newRecord2 >> newRecord3;									
				cout << " Please enter the City ID its belongs to >> ";	
				cin.sync();getline(cin, inputE1);
				while(!admin){
					try{
						istringstream (inputE1) >> IDChecker;
						if(!(istringstream (inputE1) >> IDChecker)) throw inputE1;
						for( i=1; i<=Cities.getLast()->getID();i++){
							if(IDChecker == Cities.getEntry(i)->getID()){
								admin = true;break;
							}	
						}
						if(!admin) throw IDChecker;
					}
					catch(...){
						cin.clear(); 
						cout << " Input incorrect. Please enter the valid City ID >>  "; 
						cin.sync();getline(cin, inputE1);												
					}
				}															
				cout << " Confirm to add a new Attraction Record (Y/N)? >> ";
				cin >> yesorno;
				if(yesorno=='Y' || yesorno=='y'){
					fin.open("Attraction.csv");
					fout.open("temp.csv");							
					while(getline(fin, oldRecord))
						fout << oldRecord << endl;
					fout << newRecord2 << ","<< (Cities.getEntry(i)->getID()*100)+ (Cities.getEntry(i)->getAttractionLength()+1) << "," << newRecord << "," << newRecord3<<endl;
					fout.close();
					fin.close();
					remove("Attraction.csv");
					rename_file = rename( "temp.csv" , "Attraction.csv" );
					if(rename_file==0)  puts ( "Attraction file successfully updated" );
					else perror( "Error updating file" );
				}
			break;
			case '5' :	cout << " Please enter the Attraction ID you wish to edit >> ";
				cin >> IDChecker;															
				while(!admin){
					try{
						for( j=1; j<=Cities.getLast()->getID(); j++){
							if(IDChecker/100==Cities.getEntry(j)->getID()) break;
						}
						for(int i=1; i<=Cities.getEntry(j)->getAttractionLength();i++){
							if(IDChecker == Cities.getEntry(j)->getAttractionID(i))
								input = true;
						}
						if(!input) throw IDChecker;
						else admin=true;
					}
					catch(...){
						cin.clear(); cin.ignore();
						cout << " Input incorrect. Please enter the valid Attraction ID >>  "; 
						cin >> IDChecker;												
					}
				}
				cout << " What do you wish to edit?\n Attraction Name(1), Type(2), Description(3) or City its belongs to(4) >> ";
				cin.sync();getline(cin, inputE1);																		
				while(!admin2){
					try{
						istringstream (inputE1) >> IDChecker2;
						if(!(istringstream (inputE1) >> IDChecker2)) throw inputE1;
						else if(IDChecker2>=5 || IDChecker2<=0) throw IDChecker2;
						else admin2=true;
					}
					catch(...){
						cin.clear();
						cout << " Input incorrect. Please enter in range of 1 to 4 only >> "; 
						cin.sync();getline(cin, inputE1);												
					}
				}		
				newRecord=NumberToString(Cities.getEntry(j)->getAttractionTypeID(IDChecker%((IDChecker/100)*100)));
				newRecord2=Cities.getEntry(j)->getAttractionName(IDChecker%((IDChecker/100)*100));
				newRecord3=Cities.getEntry(j)->getAttractionDesc(IDChecker%((IDChecker/100)*100));
				intTemp = IDChecker;
				if(IDChecker2==1){
					cout << " Please enter a new Attraction Name >> ";
					cin >> newRecord2;																			
				}
				else if(IDChecker2==2){
					cout << " Please enter the new Attraction Type ID >> ";
					cin >> newRecord;																			
					while(!admin3){
						try{
							if( newRecord.length()!=1 || (atoi((newRecord).c_str()) >=4 || atoi((newRecord).c_str()) <=0))
								throw newRecord;
							else admin3=true;
						}
						catch(...){
							cin.clear(); cin.ignore();
							cout << " Input incorrect. Please enter in range of 1 to 3 only >>  "; 
							cin >> newRecord;												
						}
					}	
				}
				else if(IDChecker2 == 3){
					cout << " Please enter the new Attraction Description >> ";
					cin >> newRecord3;																			
				}
				else if(IDChecker2==4){
					cout << " Please enter the new City ID to change to >> ";
					cin.sync();getline(cin,inputE2);	
					while(!admin4){
						try{
							istringstream (inputE2) >> intTemp;
							if(!(istringstream (inputE2) >> intTemp)) throw inputE2;
							for(i=1; i<=Cities.getLast()->getID();i++){
								if(intTemp == Cities.getEntry(i)->getID()){
									admin4 = true;break;
								}
							}
							if(!admin4) throw intTemp;
						}
						catch(...){
							cin.clear(); 
							cout << " Input incorrect. Please enter the valid City ID >>  "; 
							cin.sync();getline(cin,inputE2);												
						}
					}
					intTemp = (intTemp*100)+(Cities.getEntry(i)->getAttractionLength())+1;
				}
				cout << " Confirm to edit a Attraction Record (Y/N)? >> ";
				cin >> yesorno;
				if(yesorno=='Y' || yesorno=='y'){
					fin.open("Attraction.csv");
					fout.open("temp.csv");
					stringTemp = NumberToString(intTemp);
					temp = NumberToString(IDChecker);
					temp3 = NumberToString(Cities.getEntry(j)->getAttractionTypeID(IDChecker%((IDChecker/100)*100)));
					temp2 = temp3+','+temp+','+Cities.getEntry(j)->getAttractionName(IDChecker%((IDChecker/100)*100))+','+Cities.getEntry(j)->getAttractionDesc(IDChecker%((IDChecker/100)*100));
					while(getline(fin, oldRecord)){
						if(oldRecord!=temp2)	
							fout << oldRecord << endl;
						else fout << newRecord+','+stringTemp+','+newRecord2+','+newRecord3<<endl;							
					}
					fout.close();
					fin.close();
					remove("Attraction.csv");
					rename_file = rename( "temp.csv" , "Attraction.csv" );
					if(rename_file==0)  puts ( "Attraction file successfully updated" );
					else perror( "Error updating file" );
				}
			break;
			case '6' :	cout << " Please enter the Attraction ID you wish to remove >> ";
				cin>> IDChecker;																			
				while(!admin){
					try{
						for( j=1; j<=Cities.getLast()->getID(); j++){
							if(IDChecker/100==Cities.getEntry(j)->getID()) break;
						}
						for(int i=1; i<=Cities.getEntry(j)->getAttractionLength();i++){
							if(IDChecker == Cities.getEntry(j)->getAttractionID(i))
								input = true;
						}
						if(!input)	throw IDChecker;
						else admin=true;
					}
					catch(...){
						cin.clear(); cin.ignore();
						cout << " Input incorrect. Please enter the valid Attraction ID >> "; 
						cin >> IDChecker;												
					}
				}
				cout << " Confirm to remove a Attraction Record (Y/N)? >> ";
				cin >> yesorno;
				if(yesorno=='Y' || yesorno=='y'){
					fin.open("Attraction.csv");
					fout.open("temp.csv");
					IDChecker2 = Cities.getEntry(j)->getAttractionTypeID(IDChecker%((IDChecker/100)*100));
					newRecord2 = Cities.getEntry(j)->getAttractionName(IDChecker%((IDChecker/100)*100));
					newRecord3 = Cities.getEntry(j)->getAttractionDesc(IDChecker%((IDChecker/100)*100));
					temp = NumberToString(IDChecker);
					newRecord = NumberToString(IDChecker2);
					temp2 = newRecord+','+temp+','+newRecord2+','+newRecord3;
					while(getline(fin, oldRecord)){
						if(oldRecord!=temp2)
							fout << oldRecord << endl;
					}
					fout.close();
					fin.close();
					remove("Attraction.csv");
					rename_file = rename( "temp.csv" , "Attraction.csv" );
					if(rename_file==0)  puts ( "Attraction file successfully updated" );
					else perror( "Error updating file" );
				}
			break;
			case '7' :	cout << " Please enter new Origin City ID to add >> ";
				cin >> inputE1;																			
				while(!admin){
					try{
						istringstream (inputE1) >> IDChecker;
						if(!(istringstream (inputE1) >> IDChecker)) throw inputE1;
						for(int i=1; i<=Cities.getLast()->getID();i++){
							if(IDChecker == Cities.getEntry(i)->getID())
								admin = true;
						}
						if(!admin) throw IDChecker;
					}
					catch(...){
						cin.clear(); cin.ignore();
						cout << " Input incorrect. Please enter the valid City ID >>  "; 
						cin >> inputE1;												
					}
				}
				cout << " Please enter new Destination City ID to add >> ";
				cin >> inputE2;																			
				while(!admin2){
					try{
						istringstream (inputE2) >> IDChecker2;
						if(!(istringstream (inputE2) >> IDChecker2)) throw inputE2;
						for(int i=1; i<=Cities.getLast()->getID();i++){
							if(IDChecker2 == Cities.getEntry(i)->getID())
								admin2 = true;
						}
						if(!admin2) throw IDChecker2;
					}
					catch(...){
						cin.clear(); cin.ignore();
						cout << " Input incorrect. Please enter the valid City ID >>  "; 
						cin >> inputE2;												
					}
				}
				cout << " Confirm to add a new Flight Record (Y/N)? >> ";
				cin >> yesorno;
				if(yesorno=='Y' || yesorno=='y'){
					fin.open("Flight.csv");
					fout.open("temp.csv");
					temp = NumberToString(IDChecker-1)+','+NumberToString(IDChecker2-1);
					while(getline(fin, oldRecord))
						fout << oldRecord << endl;
					fout << temp;
					fout.close();
					fin.close();
					remove("Flight.csv");
					rename_file = rename( "temp.csv" , "Flight.csv" );
					if(rename_file==0)  puts ( "Flight file successfully updated" );
					else perror( "Error updating file" );							
				}
			break;
			case '8' :	cout << " Please enter old Origin City ID >> ";
				cin >> inputE1;																			
				while(!admin){
					try{
						istringstream (inputE1) >> IDChecker;
						if(!(istringstream (inputE1) >> IDChecker)) throw inputE1;
						for(int i=1; i<=Cities.getLast()->getID();i++){
							if(IDChecker == Cities.getEntry(i)->getID())
								admin = true;
						}
						if(!admin) throw IDChecker;
					}
					catch(...){
						cin.clear(); cin.ignore();
						cout << " Input incorrect. Please enter the valid City ID >> "; 
						cin >> inputE1;												
					}
				}
				cout << " Please enter old Destination City ID >> ";
				cin >> inputE2;																			
				while(!admin2){
					try{
						istringstream (inputE2) >> IDChecker2;
						if(!(istringstream (inputE2) >> IDChecker2)) throw inputE2;
						for(int i=1; i<=Cities.getLast()->getID();i++){
							if(IDChecker2 == Cities.getEntry(i)->getID())
								admin2 = true;
						}
						if(!admin2) throw IDChecker2;
					}
					catch(...){
						cin.clear(); cin.ignore();
						cout << " Input incorrect. Please enter the valid City ID >> "; 
						cin >> inputE2;												
					}
				}
				cout << " Please enter new Origin City ID >> ";
				cin >> inputE3;		
				while(!admin3){
					try{
						istringstream (inputE3) >> intTemp;
						if(!(istringstream (inputE3) >> intTemp)) throw inputE3;
						for(int i=1; i<=Cities.getLast()->getID();i++){
							if(intTemp == Cities.getEntry(i)->getID())
								admin3 = true;
						}
						if(!admin3) throw intTemp;
					}
					catch(...){
						cin.clear(); cin.ignore();
						cout << " Input incorrect. Please enter the valid City ID >>  "; 
						cin >> inputE3;												
					}
				}																	
				cout << " Please enter new Destination City ID >> ";
				cin >> inputE4;									
				while(!admin4){
					try{
						istringstream (inputE4) >> intTemp2;
						if(!(istringstream (inputE4) >> intTemp2)) throw inputE4;
						for(int i=1; i<=Cities.getLast()->getID();i++){
							if(intTemp2 == Cities.getEntry(i)->getID())
								admin4 = true;
						}
						if(!admin4) throw intTemp2;
					}
					catch(...){
						cin.clear(); cin.ignore();
						cout << " Input incorrect. Please enter the valid City ID >> "; 
						cin >> inputE4;												
					}
				}											
				cout << " Confirm to edit a Flight Record (Y/N)? >> ";
				cin >> yesorno;
				if(yesorno=='Y' || yesorno=='y'){
					fin.open("Flight.csv");
					fout.open("temp.csv");
					temp = NumberToString(IDChecker-1)+','+NumberToString(IDChecker2-1);
					temp2 = NumberToString(intTemp-1)+','+NumberToString(intTemp2-1); 
					while(getline(fin, oldRecord)){
						if(oldRecord!=temp)
							fout << oldRecord << endl;
						else fout <<temp2<< endl;
					}
					fout.close();
					fin.close();
					remove("Flight.csv");
					rename_file = rename( "temp.csv" , "Flight.csv" );
					if(rename_file==0)  puts ( "Flight file successfully updated" );
					else perror( "Error updating file" );
				}
			break;
			case '9' :	cout << " Please enter Origin City ID to remove >> ";
				cin >> inputE1;																			
				while(!admin){
					try{
						istringstream (inputE1) >> IDChecker;
						if(!(istringstream (inputE1) >> IDChecker)) throw inputE1;
						for(int i=1; i<=Cities.getLast()->getID();i++){
							if(IDChecker == Cities.getEntry(i)->getID())
								admin = true;
						}
						if(!admin) throw IDChecker;
					}
					catch(...){
						cin.clear(); cin.ignore();
						cout << " Input incorrect. Please enter the valid City ID >> "; 
						cin >> inputE1;												
					}
				}
				cout << " Please enter Destination City ID to remove >> ";
				cin >> inputE2;																			
				while(!admin2){
					try{
						istringstream (inputE2) >> IDChecker2;
						if(!(istringstream (inputE2) >> IDChecker2)) throw inputE2;
						for(int i=1; i<=Cities.getLast()->getID();i++){
							if(IDChecker2 == Cities.getEntry(i)->getID())
								admin2 = true;
						}
						if(!admin2) throw IDChecker2;
					}
					catch(...){
						cin.clear(); cin.ignore();
						cout << " Input incorrect. Please enter the valid City ID >> "; 
						cin >> inputE2;												
					}
				}
				cout << " Confirm to remove a Flight Record (Y/N)? >> ";
				cin >> yesorno;
				if(yesorno=='Y' || yesorno=='y'){
					fin.open("Flight.csv");
					fout.open("temp.csv");
					temp = NumberToString(IDChecker-1)+','+NumberToString(IDChecker2-1);
					while(getline(fin, oldRecord)){
						if(oldRecord!=temp)
							fout << oldRecord << endl;
					}
					fout.close();
					fin.close();
					remove("Flight.csv");
					rename_file = rename( "temp.csv" , "Flight.csv" );
					if(rename_file==0)  puts ( "Flight file successfully updated" );
					else perror( "Error updating file" );
				}						
			break;
			case 'Q' :	done = true; 
			break;
			default : cout << "Invalid choice" << endl;
		}
		system("pause");  
	} 
	while ( !done );
	fullscreen();
	main();
}

void UserFlightPanel(){   
	DontKnowWhatName();
	DisplayAll();
	FlightCity.clear();
	int OriCity, DestCity;	
	string Ori, Dest;
	Flight f(Cities.getLast()->getID());
	ifstream fin;   
	string FlightData, convert; 
	char proceed, yorb;
	bool input(false), input2(false), input3(false);
	fin.open("Flight.csv");
	if(fin.fail()){
		cout << "Fail to load file.\n";
		cout <<"bye\n";
	}
	else{
		while(!fin.eof()){
			while(getline(fin, FlightData, '\n')){
				stringstream ss(FlightData);
				string temp;
				while(getline(ss, temp, ',')){
					int a = atoi((temp).c_str());
					FlightCity.push_back(a);
				} 
				f.addEdge(FlightCity.getEntry(1), FlightCity.getEntry(2)); 
				FlightCity.clear();   
			}
		}       
	}
	fin.close();
	cout << " Please input the Origin City ID >> ";
	cin >> Ori;
	while(!input2){
		try{
			istringstream (Ori) >> OriCity;
			if(!(istringstream (Ori) >> OriCity)) throw Ori;
			for(int i=1; i<=Cities.getLength();i++){
				if(OriCity == Cities.getEntry(i)->getID())
					input2 = true;
			}
			if(!input2) throw OriCity;
		}
		catch (...){
			cin.clear(); cin.ignore();
			cout << " Input incorrect. Please enter the Origin City ID >>  "; 
			cin >> Ori;	
		}
	}	
	cout << " Please input the Destination City ID >> ";
	cin >> Dest;
	while(!input3){
		try{
			istringstream (Dest) >> DestCity;
			if(!(istringstream (Dest) >> DestCity)) throw Dest;
			for(int i=1; i<=Cities.getLength();i++){
				if(DestCity == Cities.getEntry(i)->getID())
					input3 = true;
			}
			if(!input3) throw DestCity;
		}
		catch (...){
			cin.clear(); cin.ignore();
			cout << " Input incorrect. Please enter the Destination City ID >>  "; 
			cin >> Dest;	
		}
	}
	if(f.isPath(OriCity-1, DestCity-1)){
		if(f.direct)
			cout<< "\n There is a direct flight from " << Cities.getEntry(OriCity)->getName() << " to " << Cities.getEntry(DestCity)->getName();
		else cout<< "\n There is a indirect flight from " << Cities.getEntry(OriCity)->getName() << " to " << Cities.getEntry(DestCity)->getName();        
	}
	else
		cout<< "\n There is no flight from " << Cities.getEntry(OriCity)->getName() << " to " << Cities.getEntry(DestCity)->getName();
	cout << "\n ";system ("pause");
	cout << " Do you wish to continue(Y) OR go back to menu(B)? ";		
	cin >> yorb; 	
	while(!input){
		try{
			if (yorb == 'Y' || yorb == 'y')
				UserFlightPanel();
			else if(yorb == 'B' || yorb == 'b')
				main();
			else
				throw yorb;
		}
		catch(...){
			cin.clear(); cin.ignore();
			cout << " Input incorrect. Please enter either Y or B >> "; 
			cin >> yorb;
		}
	} 	
}
