#include<iostream>
using namespace std;

// Inheritance way 1 with protected variable
class Attraction{
protected:
    string name;
public:
    Attraction(){}
    Attraction(string name):name(name){}
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return this->name;
    }
};

// Inheritance Way
class City:public Attraction{
public:
    void setAttraction(string name){
        this->name = name;
    }
};

int main(){
    City c;
    c.setAttraction("ABC");
    cout << c.getName();
}
