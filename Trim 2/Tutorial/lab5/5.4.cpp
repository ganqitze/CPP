#include <iostream>
#include <string>
using namespace std;

int main () {
	for (int i = 1; i < 7; i++) {
		try {
			if (i == 1) throw 1; // int
			if (i == 2) throw 3.3; // double
			if (i == 3) throw 'c'; // char
			if (i == 4) throw string("str"); // string
			if (i == 5) throw "const char[]"; // array of char
			cout << "No exception.\n";
		}
		catch(int a){cout << "No int.\n";}
		catch(double a){cout << "No double.\n";}
		catch(char a){cout << "No char.\n";}
		catch(string a){cout << "No string.\n";}
		catch(const char[]){cout << "No array of char.\n";}
	}
}