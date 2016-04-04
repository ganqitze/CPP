//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "ArrayStack.h"

using namespace std;

void stackTester(StackInterface<string>* stackPtr)
{
	try
   {
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
      
      for (int i = 0; i < 5; i++)
      {
         cout << "Loop " << i << endl;
         cout << "peek1: " << stackPtr->peek() << endl;
         cout << "pop: " << stackPtr->pop() << endl;
         cout << "Empty: " << stackPtr->isEmpty() << endl;
      }
      cout << "Empty: " << stackPtr->isEmpty() << endl;
      cout << "pop an empty stack: " << endl;
      cout << "pop: " << stackPtr->pop() << endl;   // nothing to pop!

      cout << "peek into an empty stack: " << endl;
      cout << "peek: " << stackPtr->peek() << endl; // nothing to peek!
   }
   catch (PrecondViolatedExcep e)
   {
      cout << e.what();
   }  // end try/catch
}  // end stackTester

int main()
{
	StackInterface<string>* stackPtr = new ArrayStack<string>();
	cout << "Testing the Array-Based Stack:" << endl;
	stackTester(stackPtr);
	
   return 0;
}  // end main

/*
 Testing the Array-Based Stack:
 Empty: 1
 Pushing zero
 Pushing one
 Pushing two
 Pushing three
 Pushing four
 Pushing five
 Failed to push five onto the stack.
 Empty?: 0
 Loop 0
 peek1: four
 pop: 1
 Empty: 0
 Loop 1
 peek1: three
 pop: 1
 Empty: 0
 Loop 2
 peek1: two
 pop: 1
 Empty: 0
 Loop 3
 peek1: one
 pop: 1
 Empty: 0
 Loop 4
 peek1: zero
 pop: 1
 Empty: 1
 Empty: 1
 pop an empty stack:
 pop: 0
 peek into an empty stack:
 peek: Precondition Violated Exception: peek() called with empty stack
*/
