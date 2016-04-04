#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations

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
   list.insert( 1, "dd" );
   list.insert( 2, "ee" );
   list.insert( 1, "aa" );
   list.insert( 2, "bb" );
   list.insert( 3, "cc" );
   displayList( list );

   list.remove(1);
   displayList( list );
   list.remove(3);
   displayList( list );

   LinkedList<string> bList( list );
   bList.insert( 3, "OO" );
   displayList( list );
   displayList( bList );

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
