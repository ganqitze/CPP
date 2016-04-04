#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

template <typename ItemType>
class ArrayStack{
	
protected: 
		ItemType* items; // Stack array
		int top,arraysize; // Index to top of stack
	public:
		ArrayStack(int sz);
		bool isEmpty() const;
		bool push(ItemType newEntry);
		bool pop();
		int getSize();
		ItemType peek() const;
	};

template<typename ItemType>
	ArrayStack<ItemType>::ArrayStack(int sz) : top(-1),arraysize(sz){
		items=new ItemType[arraysize];
	}

template<typename ItemType>
	bool ArrayStack<ItemType>::isEmpty() const {
		return (top < 0);
	}

template<typename ItemType>
	bool ArrayStack<ItemType>::push(ItemType newEntry){
		bool result = false;
		if (top < arraysize){
		// Stack has room for another item
			top++;
			items[top] = newEntry;
			result = true;
	} // end if
	return result;
}

template<class ItemType>
bool ArrayStack<ItemType>::pop() {
	bool result = false;
	if (!isEmpty()) {
		result = true;
		top--;
	} // end if
	return result;
}

template<typename ItemType>
int ArrayStack<ItemType>::getSize(){
	return top;
}

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const{
	if (!isEmpty()) { // no exception handling used, so check validity elsewhere
		return items[top];
	} // end if
}

class Card{
	string deck;
	string suit;
public:
	Card(){}
	Card(string d, string s):deck(d), suit(s){}
	string getCard(){
		return deck+" of "+suit;
	}
	friend ostream& operator<< (ostream& os, Card c){
		os << c.getCard();
		return os;
	}
};


class DeckOfCards:public ArrayStack<Card>{
public:
	DeckOfCards(): ArrayStack<Card>(52){
		string decks[]={"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
		string suits[]={"Diamonds", "Hearts", "Spades", "Clubs"};
		for(int i=0; i<4; i++){
			for(int j=0; j<13; j++){
				this->push(Card(decks[j], suits[i]));
			}
		}
	}
	void shuffle(){
		Card temp[52];
		for(int i=0;i<52;i++){
			temp[i]=peek();
			pop();
		}
		srand(time(0));
		random_shuffle(&temp[0], &temp[52]);
		for(int i=0;i<52; i++){
			push(temp[i]);
		}
	}
	Card getCard(){
		Card temp=peek();
		pop();
		return temp;
	}
	int remainingCards(){
		return getSize()+1;
	}

};

int main(){
	DeckOfCards newdeck; // call a shuffle of the deck
	newdeck.shuffle();
	// cout << newdeck.getCard() << endl;
	// cout << newdeck.getCard() << endl;
	// cout << "remaining " << newdeck.remainingCards() << endl;
	int decision,numofplayers;
	bool cont=true;
	cout << "Enter number of players: ";
	cin >> numofplayers;
	if (!cin.fail()){
		while(cont){
			cout<<"[1] Draw cards\n[2] End Game\nEnter a number: ";
			cin>>decision;
			if (!cin.fail()){
				switch (decision){
					case 1:
					for (int i = 0; i < numofplayers; ++i)
					{
						newdeck.getCard();
						cout << "draw" << newdeck.remainingCards() << endl;
					}
					break;
					case 2: cout << "bye";
					cont = false;
					break;
					default:
					cout<<"Unknown option entered\n\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
			} 
			else{
				cout <<"Enter a number only\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}
	else
		cout<<"Ending game.\n";
	return 0;
}

//int main(){
	//ArrayStack<Card*> myCard(2);
	//Card myCard("Ace", "Hearts");

	//myCard.push(new Card("Ace", "Hearts"));
	//cout << *myCard.peek();
//}