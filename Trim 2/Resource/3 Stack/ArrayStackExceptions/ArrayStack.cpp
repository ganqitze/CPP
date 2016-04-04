//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class ArrayStack.
@file ArrayStack.cpp */

#include "ArrayStack.h"  // Stack class specification file

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
}  // end default constructor

// Copy constructor and destructor are supplied by the compiler

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
	return top < 0;	
}  // end isEmpty

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	bool result = false;	
	if (top < MAX_STACK - 1)
	{
      // Stack has room for another item
		top++;
		items[top] = newEntry;
		result = true;
	}  // end if
   
	return result;
}  // end push


template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
	bool result = false;
	if (!isEmpty())
	{
		result = true;
		top--;
	}  // end if
   
	return result;
}  // end pop


template<class ItemType> 
ItemType ArrayStack<ItemType>::peek() const throw(PrecondViolatedExcep)
{
   // Enforce precondition
	if (isEmpty())
        throw PrecondViolatedExcep("peek() called with empty stack"); 
      
	// Stack is not empty; return top
	return items[top];
}  // end peek

// End of implementation file.

