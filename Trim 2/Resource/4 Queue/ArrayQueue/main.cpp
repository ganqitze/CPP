//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "ArrayQueue.h" // ADT Queue operations
#include <iostream>
#include <string>

using namespace std;

void queueTester(QueueInterface<string>* queuePtr)
{
	string items[] = {"one", "two", "three", "four", "five", "six"};
	cout << "Empty: " << queuePtr->isEmpty() << endl;
	for (int i = 0; i < 6; i++)
   {
		cout<<"Adding " << items[i] << endl;
      bool success = queuePtr->enqueue(items[i]);
      if (!success)
         cout << "Failed to add " << items[i] << " to the queue." << endl;
	}
   
	cout << "Empty?: " << queuePtr->isEmpty() << endl;
	
	for (int i = 0; i < 6; i++) 
   {
		cout << "Loop " << i << endl;
      
      try 
      {
         cout << "peekFront: " << queuePtr->peekFront() << endl;
      } 
      catch (PrecondViolatedExcep e) 
      {
         cout << e.what() << endl;
      }  // end try/catch

		cout << "Empty: " << queuePtr->isEmpty() << endl;
		cout << "dequeue: " << queuePtr->dequeue() << endl;
	}
   
   cout << "dequeue with an empty queue: " << endl;
	cout << "Empty: " << queuePtr->isEmpty() << endl;
	cout << "dequeue: " << queuePtr->dequeue() << endl; // nothing to dequeue!
   
   try 
   {
      cout << "peekFront with an empty queue: " << endl;
	   cout << "peekFront: " << queuePtr->peekFront() << endl; // nothing to see!
   } 
   catch (PrecondViolatedExcep e) 
   {
      cout << e.what();
   }  // end try/catch
}  // end queueTester

int main()
{
	QueueInterface<string>* queuePtr = new ArrayQueue<string>();
	cout << "Testing the Array-based queue:" <<endl;
	queueTester(queuePtr);
	
   return 0;
}  // end main
/*
 Testing the Array-based queue:
 Empty: 1
 Adding one
 Adding two
 Adding three
 Adding four
 Adding five
 Adding six
 Empty?: 0
 Loop 0
 peekFront: one
 Empty: 0
 dequeue: 1
 Loop 1
 peekFront: two
 Empty: 0
 dequeue: 1
 Loop 2
 peekFront: three
 Empty: 0
 dequeue: 1
 Loop 3
 peekFront: four
 Empty: 0
 dequeue: 1
 Loop 4
 peekFront: five
 Empty: 0
 dequeue: 1
 Loop 5
 peekFront: six
 Empty: 0
 dequeue: 1
 dequeue with an empty queue:
 Empty: 1
 dequeue: 0
 peekFront with an empty queue:
 peekFront: Precondition Violated Exception: peekFront() called with empty queue
 */