#include<iostream>
#include <string>
#include "LinkedQueue.cpp"
using namespace std;

class Student {
    string name;
    int id;
public:
    Student (string name = "", int id = 0) : name(name), id(id) {}
    friend ostream& operator<< (ostream& os, const Student& s) {
        os << s.name << "/" << s.id;
        return os;
    }
};


int main(){
    LinkedQueue<Student> queue;
    Student s;
    string name;
    bool cont=true;
    int id;
    int choice;
    do {
        cout << "Queue: ";
        queue.display();
        cout << "Option:\n"
        << "1: Enqueue a student\n"
        << "2: Dequeue a student\n"
        << "3: Peek\n"
        << "4: Quit\n";
        cin >> choice;
        switch (choice) {
        case 1: cout << "Student name: "; cin >> name;
                cout << "Student ID: "; cin >> id;
                queue.enqueue(Student(name, id));
                break;
        case 2: cout << "Student dequeue-d: " << queue.peekFront()<< endl;
                queue.dequeue();
                break;
        case 3: cout << queue.peekFront();
                break;
        case 4: cont=false;break;
        }
    } while (cont);
}
