#include "LinkedList.h"  // Header file
#include <iostream>
#include <cassert>

template<class T>
LinkedList<T>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& aList) : itemCount(aList.itemCount)
{
   Node<T>* origChainPtr = aList.headPtr;  // Points to nodes in original chain

   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original list is empty
   else
   {
      // Copy first node
      headPtr = new Node<T>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<T>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         T nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item 
         Node<T>* newNodePtr = new Node<T>(nextItem);  
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr); 
         
         // Advance pointer to new last node      
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class T>
LinkedList<T>::~LinkedList()
{
   clear();
}  // end destructor

template<class T>
bool LinkedList<T>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class T>
int LinkedList<T>::getLength() const
{
   return itemCount;
}  // end getLength

template<class T>
bool LinkedList<T>::insert(int newPosition, const T& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry 
      Node<T>* newNodePtr = new Node<T>(newEntry);  
      
      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr); 
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         Node<T>* prevPtr = getNodeAt(newPosition - 1);
         
         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext()); 
         prevPtr->setNext(newNodePtr);
      }  // end if

      itemCount++;  // Increase count of entries
   }  // end if
   else cerr << "Unable to Insert.";
   return ableToInsert;
}  // end insert

template<class T>
bool LinkedList<T>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<T>* curPtr = nullptr;
      if (isEmpty()) 
         return false;
      else if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<T>* prevPtr = getNodeAt(position - 1);
         
         // Point to node to delete
         curPtr = prevPtr->getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
      }  // end if
      
      // Return node to system
      curPtr->setNext(nullptr);
      delete curPtr;
      curPtr = nullptr;
      
      itemCount--;  // Decrease count of entries
   }  // end if
   return ableToRemove;
}  // end remove

template<class T>
void LinkedList<T>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class T>
T LinkedList<T>::getEntry(int position) const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<T>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "getEntry() called with an empty list or "; 
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end getEntry

template<class T>
void LinkedList<T>::setEntry(int position, const T& newEntry) throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      Node<T>* nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      string message = "setEntry() called with an invalid position."; 
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end setEntry

template<class T>
Node<T>* LinkedList<T>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   Node<T>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();
   return curPtr;
}  // end getNodeAt

template <class T>
void LinkedList<T> :: push_back(const T& newEntry){
   Node<T>* newNode = new Node<T>(newEntry);
   if(headPtr == nullptr)
      headPtr = newNode;

   else {
      Node<T>* temp = headPtr;
      while(temp->getNext()!=nullptr){
         temp = temp->getNext();
      }
      temp->setNext(newNode);
   }
   itemCount++;
}  // end push_back

template <class T>
void LinkedList<T> :: swap(int pos1, int pos2){
   insert(pos2+1, getEntry(pos1));
   remove(pos1);
} 

template <class T>
T LinkedList<T>::getLast(){
   Node<T>* temp = headPtr;
   while(temp->getNext()!=nullptr){
      temp = temp->getNext();
   }
   return temp->getItem();   
   // return getNodeAt(5);
}


//  End of implementation file.
