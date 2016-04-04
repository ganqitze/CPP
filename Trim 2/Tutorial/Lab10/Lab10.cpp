#include <iostream>
#include <cstring>
using namespace std;
/*
int count =0;

int sum(int number){
	count++;
	if(number == 0)
		return number;
	return number + sum(number-1);
}

int power(int number, int pow){
	count++;
	if(pow==0)
		return number;
	return number*power(number, pow-1);
}

int Fibonacci(int number){
	if(number<=2)
		return 1;
	count++;
	return Fibonacci(number-1) + Fibonacci(number-2);
}

//Q1~3
int main(){
	int number, x;
	number=6; x=3;
	//cout << sum(number) << endl;
	//cout << power(number, x) << endl;
	cout << Fibonacci(7) << endl;
	cout << count << endl;
	//for(int i=0; i<7; i++)
	//	cout << Fibonacci(i)<<" ";
	
	return 0;
}
*/

void reverse(char *p1, char *p2){
	if(p1>p2)
		return;
	else{
		char temp= *p1;
		*p1=*p2;
		*p2=temp;
		reverse(++p1, --p2);
	}
}

//Q4
int main(){
	char str[] = "Hello World";
	cout << str << endl; // prints Hello World
	reverse(&str[0], &str[strlen(str)-1]); //pass by ref to call ptr fn
	cout << str << endl; // prints dlroW olleH
	return 0;
}

