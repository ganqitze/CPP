#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <windows.h>
using namespace std;

class Mars
{
	private:
	vector < vector<char> > map;
	int dimX, dimY;

	public:
	Mars()
	{
		init();
	}
	void init();
	void display();
	int getDimX();
	int getDimY();
	char getObject(int x,int y);
	void setObject(int x,int y, char hue);
	bool isEmpty(int x,int y);
	bool isInsideMap(int x,int y);
};
class Rover
{
	private:
		int x,y;
		char heading; \
	public:
		Rover()
		{

		}
		void land(Mars& mars);
		bool turnLeft(Mars& mars);
		bool turnRight(Mars& mars);
		bool move(Mars& mars);
};

bool Rover::move(Mars& mars){
	int newx=x, newy =y;
	
	switch(heading){
		case '^': 
			newy=y+1;
			break;
		case '<': 
			newx=x-1;
			break;
		case 'v': 
			newy = y-1;
			break;
		case '>': 
			newx=x+1;
			break;
	}
	if (mars.isInsideMap(newx, newy) && mars.isEmpty(newx, newy)){
		mars.setObject(newx, newy, heading);
		mars.setObject(newx, newy, heading);
		x=newx;
		y=newy;
		return true;
	}
	else{
		return false;
	}
}

bool Rover::turnRight(Mars& mars){
	switch(heading){
		case '^': 
			heading='>';
			break;
		case '<': 
			heading='^';
			break;
		case 'v': 
			heading='<';
			break;
		case '>': 
			heading='v';
			break;
	}
	mars.setObject(x, y, heading);
	return true; //always possible to turn 
}

bool Rover::turnLeft(Mars& mars){
	switch(heading){
		case '^': 
			heading='<';
			break;
		case '<': 
			heading='v';
			break;
		case 'v': 
			heading='>';
			break;
		case '>': 
			heading='^';
			break;
	}
	mars.setObject(x, y, heading);
	return true; //always possible to turn 
}

void Rover::land(Mars& mars)
{
	char possibleHeading[] = {'^', '>', '<', 'v'};

	x = rand() % mars.getDimX() + 1;
	y = rand() % mars.getDimY() + 1;
	heading = possibleHeading[ rand() % 4 ]; 
	mars.setObject(x,y,heading);
}


bool Mars::isInsideMap(int x,int y){
	if(x>=1 && y>=1 && x<dimX && y<=dimY)
		return true;
	else 
		return false;
	}

bool Mars::isEmpty(int x,int y){
	char hue = getObject(x, y);
	return hue==' ';
}

void Mars::setObject(int x,int y, char hue){
	map[dimY-y][x-1]=hue;	
}
char Mars::getObject(int x,int y){
	return map[dimY-y][x-1];
}

int Mars::getDimX(){
	return dimX;	
}
int Mars::getDimY(){
	return dimY;	
}

void Mars::init()
{
	char objects[] = {' ', ' ', ' ', ' ', ' ', ' ','X', '#', '@', '$' };
	int noOfObjects = 10;	//number of objects in the objects array

	dimX = 15;
	dimY = 5;

	//create dynamic 2D array using vector 
	map.resize(dimY);	
	//create rows
	for (int i=0; i<dimY; ++i)
	{
		map[i].resize(dimX);	//resize each rows
	}

	//put random chars into the vector array 
	for (int i=0; i<dimY; ++i)
	{
		for (int j=0; j<dimX; ++j)
		{
			int objNo = rand() % noOfObjects; 
			map[i][j] =	objects[ objNo ];
		}
	}
}

void Mars::display()
{
	system("cls");
	cout << " 	-- -- --  --  --  --  --  --_" << endl; 
	cout << " = Curiosity, welcome to Mars! =" << endl; 
	cout << "   --  --  --  --  --  --  --  -" << endl;

	for (int i=0; i<dimY; ++i)
	{
		cout << "  ";
		for (int j=0; j<dimX; ++j)
		{
			cout << "+-";
		}
		cout << "+" << endl;
		cout << setw(2) << (dimY-i); 
		for (int j=0; j<dimX; ++j)
		{
		cout << "|" << map[i][j];
		}
		cout << "|" << endl;
	}

	cout << "  ";

	for (int j=0; j<dimX; ++j)
	{
		cout << "+-";
	}
	cout << "+" << endl;

	cout << "  ";
	for (int j=0; j<dimX; ++j)
	{
		int digit = (j+1)/10; 
		cout << " ";
		if (digit==0) 
			cout << " ";
		else
			cout << digit;
	}
	cout << endl;

	cout << "  ";
	for (int j=0; j<dimX; ++j)
	{
		cout << " " << (j+1)%10;
	}
		cout << endl << endl;
	}

void test1()
{
	Mars mars;
	mars.display();
}

void test2()
{
	Mars mars;
	mars.display();

	cout << "Dim X = " << mars.getDimX() << endl; 
	cout << "Dim Y = " << mars.getDimY() << endl;
}

void test3()
{
	Mars mars; 
	mars.display(); 
	int x,y;
	char obj;
	x =	1;
	y = 1;
	obj = mars.getObject(x,y);
	cout << "Object at column " << x << " and row " << y << " is ["
		<< obj << "]" << endl; 
	x = 15; y = 5;
	obj = mars.getObject(x,y);
	cout << "Object at column " << x << " and row " << y << " is ["
		<< obj << "]" << endl; 
	x =	5; y = 2;
	obj = mars.getObject(x,y);
	cout << "Object at column " << x << " and row " << y << " is ["
		<< obj << "]" << endl; 
	x = 10; y = 4;
	obj = mars.getObject(x,y);
	cout << "Object at column " << x << " and row " << y << " is ["
		<< obj << "]" << endl;
}

void test4()
{
	Mars mars;
	mars.setObject( 1, 1, 'A');
	mars.setObject(15, 1, 'B');
	mars.setObject(15, 5, 'C');
	mars.setObject( 1, 5, 'D'); 
	mars.display();
	cout << "The object A should be at column 1 and row 1" << endl; 
	cout << "The object B should be at column 15 and row 1" << endl;
	cout << "The object C should be at column 15 and row 5" << endl;
	cout << "The object D should be at column  1 and row 5" << endl;
}

void test5()
{
	Mars mars;
	mars.setObject( 2,	4, 'Z');
	mars.setObject( 10, 3, ' '); 
	mars.display();

	cout << "Coordinate (2,4) is "; 
	if ( mars.isEmpty(2,4) )
		cout << "empty.";
	else
		cout << "Not empty."; 
	cout << endl;
	cout << "Coordinate (10,3) is "; 
	if ( mars.isEmpty(10,3) )
		cout << "empty."; 
	else
		cout << "not empty.";

	cout << endl;

	cout << "Coordinate (15,5) is "; 
	if ( mars.isInsideMap(15,5) )
		cout << "inside map.";
	else
		cout << "not inside map."; 
	cout << endl;
	cout << "Coordinate (0,0) is "; 
	if ( mars.isInsideMap(0,0) )
		cout << "inside map."; 
	else
		cout << "not inside map.";
	cout << endl;
}

void test6()
{
	Mars mars;
	Rover curiosity;
	curiosity.land(mars);
	mars.display();
}

void test7()
{
	Mars mars;

	Rover curiosity; 
	curiosity.land(mars);
	mars.display(); 
	system("pause");

	curiosity.turnLeft(mars);
	mars.display(); 
	system("pause");

	curiosity.move(mars);
	mars.display();
	system("pause");

	curiosity.move(mars);
	mars.display();
	system("pause");

	curiosity.turnRight(mars);
	mars.display();
	system("pause");

	curiosity.move(mars); 
	mars.display();
	system("pause");
}

int main()
{
	//srand( time(NULL) );	//different map each time the program is run 
	srand( 1 );	//start with seed number 1, can be any other number

	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
}


