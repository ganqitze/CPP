#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  string s; // input as string.
  int n;  // input as int.
  cout << "Enter a positive integer or 0: ";
  try{
    cin >> s;
    if (!(istringstream (s) >> n))
      throw 1;
    else if (n < 0)
      throw 0.1;    
    else {
        long long result = 1;
        for (int i = 1; i <= n; i++)
          result *= i;
        cout << "Factorial(" << n << ") = " << result << endl;    
      }
    }
    catch(int a){
      cout << "Error: You input string \"" << s << "\".\n" << "Input must be a positive integer or 0 only.\n";
    }
    catch(double a){
      cout << "Error: You input negative integer " << n << ".\n" << "Input must be a positive integer or 0 only.\n";
    }
    cout << "Good bye.\n";
  }