#include <iostream>
using namespace std;

class Attraction{
    string name;
public:
    Attraction(string name):name(name){}
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }

};

// Assignment Way
class City{c
    string name;
    Attraction b;
public:
    City(Attraction b):b("HUI"){
        cout << b.getName();
    }
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return this->name;
    }
};

int main(){
    cout << "Hello World!";

    Attraction a("JKL");
    cout << a.getName() << endl;

    City c(a);
    c.setName("ABC");
    cout << c.getName() << endl;

}
