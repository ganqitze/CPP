#include<iostream>
using namespace std;

// Inheritance way 1 with private variable
class Attraction{
private:
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

class City:public Attraction{
public:
    void setAttraction(string name){
        this->setName(name);
    }
};

int main(){
    City c;
    c.setAttraction("ABC");
    cout << c.getName();
}
