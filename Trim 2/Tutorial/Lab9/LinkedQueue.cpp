#include <iostream>
#include "Node.h"
using namespace std;

template<class ItemType>
class LinkedQueue{
private:
    Node<ItemType>* backPtr;
    Node<ItemType>* frontPtr;
public:
    LinkedQueue(){backPtr=nullptr;frontPtr=nullptr;}
    ~LinkedQueue(){while(!isEmpty())dequeue();}
    bool isEmpty() const{return backPtr == nullptr;}
    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;

    void display()const{
        if(isEmpty()){
            cout << "EMPTY\n";
            return;
        }
        Node<ItemType>* curPtr = frontPtr;
        cout << "Front->";
        while(curPtr!=nullptr){
            cout << curPtr->getItem() << " ";
            curPtr = curPtr->getNext();
        }
        cout << "-> End\n";
    }

    friend ostream& operator<< (ostream& o,const LinkedQueue<ItemType>& i){
        return o<<i.peekFront();
    }
};

template<class ItemType>
bool LinkedQueue<ItemType>:: enqueue(const ItemType& newEntry){
    Node <ItemType>* newNodePtr = new Node<ItemType>(newEntry);
    if(isEmpty())
        frontPtr=newNodePtr;
    else backPtr->setNext(newNodePtr);
    backPtr=newNodePtr;
    return true;
}

template<class ItemType>
bool LinkedQueue<ItemType>:: dequeue(){
    bool result = false;
    if(!isEmpty()){
        Node <ItemType>* newNodePtr = frontPtr;
        if(frontPtr== backPtr){
            frontPtr=nullptr;
            backPtr = nullptr;
        }
        else frontPtr = frontPtr->getNext();
        newNodePtr->setNext(nullptr);
        delete newNodePtr;
        newNodePtr = nullptr;
        result = true;
    }
    return result;
}

template<class ItemType>
ItemType LinkedQueue<ItemType>:: peekFront() const{
    if(!isEmpty())
        return frontPtr->getItem();
}


