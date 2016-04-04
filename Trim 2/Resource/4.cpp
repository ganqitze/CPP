#include<iostream>
using namespace std;

// polymorphism example from (http://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm)
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
        cout << "This is in Attraction" << endl;
        return this->name;
    }
};

class City:public Attraction{
public:
    City(string name):Attraction(name){}
    string getName(){
        return "This is in City";
    }
};

int main(){
    Attraction *a;
    City c("ABC");
    cout << c.getName() << endl;

    a = &c;
    cout << a->getName();
}

