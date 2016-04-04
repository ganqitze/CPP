template<typename itemtype>
void LinkedList<itemtype>::sortedInsert(const itemtype& newEntry){
	Node<itemtype>* newNode = new Node<itemtype>(newEntry);
	if(start == nullptr){
		start = newNode;
	} else if (newEntry < start->getItem()){
		newNode->setNext(start);
		start = newNode;
	}else {
		Node<itemtype>* curPtr = start;
		Node<itemtype>* prevPtr = start;
		while(curPtr->getNext() != nullptr){
			curPtr = curPtr->getNext();
			if(newEntry < curPtr->getItem()){
				newNode->setNext(curPtr);
				prevPtr->setNext(newNode);
				itemcount++;
				return;
			}
			prevPtr = curPtr;
		}
		curPtr->setNext(newNode);
	}
	itemcount++;
	return;
}