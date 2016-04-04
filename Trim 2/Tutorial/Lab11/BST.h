//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 16-4.

/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"

template<class ItemType>
class BST
{
private:
   BinaryNode<ItemType>* rootPtr;

protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Recursive helper methods for the public methods.
   //------------------------------------------------------------
   // Recursively finds where the given node should be placed and
   // inserts it in a leaf at that point.
   BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr,
                                       BinaryNode<ItemType>* newNode);

   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
                                  ItemType& target) const;

   // Recursive traversal helper methods:
   void preorder(BinaryNode<ItemType>* treePtr) const;
   void inorder(BinaryNode<ItemType>* treePtr) const;
   void postorder(BinaryNode<ItemType>* treePtr) const;

    int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;
    void destroyTree(BinaryNode<ItemType>* subTreePtr);

public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BST();
   BST(const ItemType& rootItem);
   virtual ~BST();

   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
   bool isEmpty() const;
   int getNumberOfNodes() const;
   bool insert(const ItemType& newEntry);
   bool search(ItemType& anEntry) const;

   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void preorderTraverse() const;
   void inorderTraverse() const;
   void postorderTraverse() const;

}; // end BinarySearchTree

#include "BST.cpp"

#endif
