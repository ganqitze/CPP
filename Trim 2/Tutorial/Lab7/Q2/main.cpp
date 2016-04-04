#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "LinkedList.h" // ADT list operations
#include "PrecondViolatedExcep.cpp"

using namespace std;

void displayList(const LinkedList<string> &aList)
{
   cout << "The list contains " << endl;
   for (int pos = 1; pos <= aList.getLength(); pos++)
   {
      cout << aList.getEntry( pos ) << " ";
   } 
   cout << endl << endl;
}  

int main()
{	
	LinkedList<string> list;
	char choice;
	bool done = false;
	
	do 
	{ 
		system("cls");
		cout << endl << endl << endl;
		cout << "          1. Add Record To Back" << endl;
		cout << "          2. Insert a Record" << endl;
		cout << "          3. Erase a Record by Record Number" << endl;
		cout << "          4. Remove A Record by Content" << endl;
		cout << "          5. Clear ALL Records" << endl;
		cout << "          6. Display A Record" << endl;
		cout << "          7. Display ALL Records" << endl;
		cout << "          8. Save Records to File" << endl;
		cout << "          9. Load Records from File" << endl;
		cout << "          Q. Quit" << endl;
		cout << endl;
		cout << "        => "; 
		cin >> choice;

		
		choice = toupper(choice);
		char ch, yesorno;
		string filename, record, hue;
		int recno;
		bool lol;
		
		ifstream fin;
		ofstream fout;

		switch( choice ) 
		{
			case '1' :	cout << "Enter a string: ";
						cin >> record;
						if(!list.insert(list.getLength()+1, record)) cerr << "Invalid Input\n";
						break;
	
			case '2' :	cout << "Enter a string: ";
						cin >> record;
						list.insert(1, record);
						break;

			case '3' :	cout << "Enter a number position: ";
						cin >> recno;
						if(!list.remove(recno)) cerr << "Invalid Input\n";
						break;
						
			case '4' :	cout << "Enter a string: ";
						cin.sync();
						getline(cin, record);
						for(int i=1;i<=list.getLength(); i++){
							if(list.getEntry(i)==record)
								lol = list.remove(i);
								if(lol=false)cerr << "Invalid Input\n";
								else cout << "removed\n";
						}
						break;
						
			case '5' :	list.clear();
						break;	
						
			case '6' :	cout << "Enter a number position: ";
						cin >> recno;
						cout << "The entry is " << list.getEntry(recno) <<endl;
						break;	
						
			case '7' :	displayList(list);
						break;	
			
			case '8' :	cout << "Enter a string: ";
						cin.sync();
						getline(cin, record);
						record = record + ".txt";
						fout.open(record);
						for(int i=1; i<=list.getLength(); i++){
							fout << list.getEntry(i) << " ";
						}
						fout.close();
						break;	
			
			case '9' :	cout << "Enter a string: ";
						cin.sync();
						getline(cin, record);
						record = record + ".txt";
						fin.open(record);
						while(fin>>hue){
							list.insert(list.getLength()+1, hue); 
						}
						fin.close();
						break;	
						
			case 'Q' :	list.clear();
						return 0;
						break;							
						
			default : cout << "Invalid choice" << endl;
		} 
		system("pause");  
		
	} while ( !done );
	  cout << "Good Bye !!" << endl; 
		return 0;
	}



/* Output

The list contains 
aa bb cc dd ee 

The list contains 
bb cc dd ee 

The list contains 
bb cc ee 

The list contains 
bb cc ee 

The list contains 
bb cc OO ee 

*/
