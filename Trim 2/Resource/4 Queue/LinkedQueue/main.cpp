//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "LinkedQueue.h" // ADT Queue operations

using namespace std;

void copyConstructorTester()
{
	LinkedQueue<string> queue;
   string items[] = {"zero", "one", "two", "three", "four", "five"};
	for (int i = 0; i < 6; i++)
   {
		cout << "Adding " << items[i] << endl;
      bool success = queue.enqueue(items[i]);
      if (!success)
         cout << "Failed to add " << items[i] << " to the queue." << endl;
	}
   cout << "Queue contains, from front to back, zero one two three four five." << endl;
   
   LinkedQueue<string> copyOfQueue(queue);
   cout << "Copy of queue contains, from front to back, ";
	for (int i = 0; i < 6; i++)
   {
      cout << " " << copyOfQueue.peekFront();
      copyOfQueue.dequeue();
   }
   cout << "." << endl;
   
   cout << "Original queue contains, from front to back,";
	for (int i = 0; i < 6; i++)
   {
      cout << " " << queue.peekFront();
      queue.dequeue();
   }
   cout << "." << endl << endl;
}  // end copyConstructorTester

void queueTester()
{
	QueueInterface<string>* queuePtr = new LinkedQueue<string>();
	cout << "Testing the Link-based queue:" <<endl;

	string items[] = {"one", "two", "three", "four", "five", "six"};
	cout << "Empty: " << queuePtr->isEmpty() << endl;
	for (int i = 0; i < 6; i++)
   {
		cout<<"Adding " << items[i] << endl;
      bool success = queuePtr->enqueue(items[i]);
      if (!success)
         cout << "Failed to add " << items[i] << " to the queue." << endl;
	}  // end for
   
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
	}  // end for
   
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
   copyConstructorTester();
   queueTester();
   return 0;
}  // end main

/*
 Adding zero
 Adding one
 Adding two
 Adding three
 Adding four
 Adding five
 Queue contains, from front to back, zero one two three four five.
 Copy of queue contains, from front to back,  zero one two three four five.
 Original queue contains, from front to back, zero one two three four five.
 
 Testing the Link-based queue:
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
 peekFront: Precondition Violated Exception: getFront() called with empty queue.
*/
