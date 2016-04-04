//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "LinkedStack.h"

using namespace std;

void copyConstructorTester()
{
	LinkedStack<string> stack;
   string items[] = {"zero", "one", "two", "three", "four", "five"};
	for (int i = 0; i < 6; i++)
   {
		cout << "Pushing " << items[i] << endl;
      bool success = stack.push(items[i]);
      if (!success)
         cout << "Failed to push " << items[i] << " onto the stack." << endl;
	}
   cout << "Stack contains, from top to bottom, five four three two one zero." << endl;

   LinkedStack<string> copyOfStack(stack);
   cout << "Copy of stack contains, from top to bottom, ";
	for (int i = 0; i < 6; i++)
   {
      cout << " " << copyOfStack.peek();
      copyOfStack.pop();
   }
   cout << "." << endl;
   
   cout << "Original stack contains, from top to bottom,";
	for (int i = 0; i < 6; i++)
   {
      cout << " " << stack.peek();
      stack.pop();
   }
   cout << "." << endl;
}  // end copyConstructorTester

void stackTester()
{
	StackInterface<string>* stackPtr = new LinkedStack<string>();
	cout << "\nTesting the Link-Based Stack:" <<endl;
   
	string items[] = {"zero", "one", "two", "three", "four", "five"};
	cout << "Empty: " << stackPtr->isEmpty() << endl;
	for (int i = 0; i < 6; i++)
   {
		cout<<"Pushing " << items[i] << endl;
      bool success = stackPtr->push(items[i]);
      if (!success)
         cout << "Failed to push " << items[i] << " onto the stack." << endl;
	}
   
	cout << "Empty?: " << stackPtr->isEmpty() << endl;
	
	for (int i = 0; i < 5; i++)  // NEEDS TO BE 5 TO AVOID ASSERT ERROR
   {
		cout << "Loop " << i << endl;
      cout << "peek1: " << stackPtr->peek() << endl;
		cout << "pop: " << stackPtr->pop() << endl;
		cout << "Empty: " << stackPtr->isEmpty() << endl;
	}
	cout << "Empty: " << stackPtr->isEmpty() << endl;
   
   cout << "pop an empty stack: " << endl;
	cout << "pop: " << stackPtr->pop() << endl; // nothing to pop!
   
   cout << "peek into an empty stack: " << endl;
	cout << "peek: " << stackPtr->peek() << endl; // nothing to peek!
}  // end stackTester

int main()
{
   copyConstructorTester();
   stackTester();
   return 0;
}  // end main

/*
 Pushing zero
 Pushing one
 Pushing two
 Pushing three
 Pushing four
 Pushing five
 Stack contains, from top to bottom, five four three two one zero.
 Copy of stack contains, from top to bottom,  five four three two one zero.
 Original stack contains, from top to bottom, five four three two one zero.
 
 Testing the Link-Based Stack:
 Empty: 1
 Pushing zero
 Pushing one
 Pushing two
 Pushing three
 Pushing four
 Pushing five
 Empty?: 0
 Loop 0
 peek1: five
 pop: 1
 Empty: 0
 Loop 1
 peek1: four
 pop: 1
 Empty: 0
 Loop 2
 peek1: three
 pop: 1
 Empty: 0
 Loop 3
 peek1: two
 pop: 1
 Empty: 0
 Loop 4
 peek1: one
 pop: 1
 Empty: 0
 Empty: 0
 pop an empty stack:
 pop: 1
 peek into an empty stack:
 Assertion failed: (!isEmpty()), function peek, file /Users/Frank/Desktop/Test/Tester/Tester/LinkedStack.cpp, line 106.
 peek: 
*/
