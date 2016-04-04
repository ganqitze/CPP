/********************************
Program: Tourists Best Friend
Course: TCP1201 OOPDS
Year: 2015/16 Trimester 2
Name: Gan Qi Tze
ID: 1142700525
Lecture: TC02
Lab: TT04
Email: ganqitze@gmail.com
Phone: 010-2527511
*********************************/
#include <iostream>
#include "LinkedStack.h"
#include "Flight.hpp"
using namespace std;

Flight::Flight(int size):size(size){
    array = new int*[size];
    for(int i = 0; i < size; i++)
        array[i] = new int[size]; 
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            array[i][j]=0;
} 

Flight::~Flight(){
    for(int i=0;i<size;i++)
        delete [] array[i];
    delete [] array;
}

void Flight::addEdge(int City1, int City2){    
    array[City1][City2]=1;
    // for(int i=0; i<size; i++){
    //     for(int j=0; j<size; j++){
    //         cout << array[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

}

void Flight::markVisited(int visitedCity){
    visited[visitedCity]=true;
}

void Flight::unvisitAll(){
    for (int i = 0; i < size; i++)
        visited[i] = false;
}

int Flight::getNextCity(int aCity){
    for(int j=0; j<size; j++){
        if(array[aCity][j]==1 && !visited[j]){
            return j;
            break;
        }               
    }
    return 404;
}

bool Flight::isPath(int Origin, int Destination){
    if (Origin == Destination || array[Origin][Destination] == 1){
        direct=true;
        return true;
    }
    LinkedStack<int> aStack;
    unvisitAll(); // Clear marks on all cities
    aStack.push(Origin);    // Push origin city onto aStack and mark it as visited
    markVisited(Origin);
    int topCity = aStack.peek();
    int count(0);
    while (!aStack.isEmpty()){   
        direct=false;
        if (topCity == Destination){
            if(count == 1) direct=true;
            return true;
        }
        int nextCity = getNextCity(topCity);   
        if (nextCity == 404){
            aStack.pop(); // No city found; backtrack   
        }
        else{   
            aStack.push(nextCity);
            markVisited(nextCity);
        } 
        if (!aStack.isEmpty()){
            topCity = aStack.peek();
        }

        count=count+1;
    }
    direct=false;
    return false;
}

void Flight::display(){
    int count(0);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(array[i][j]==1){
                cout << " |  City[" << i+1 << "] >>> City[" << j+1 << "] ";
                count++;
            }
            if(count == 3){
                cout << " |" << endl;
                count=0;
            }
        }
    }
    while(count!=3){
        if(count==0)return;
        cout << " |                      ";
        count++;
    }
    cout << " |" << endl;
}


// int main(){ 

    // LinkedList<int> FlightCity;
    // Flight f(5);
    // ifstream fin;   
    // string FlightData; 
    // string convert; 
    // fin.open("Flight.csv");
    // if(fin.fail()){
    //     cout << "Fail to load file.\n";
    //     cout <<"bye\n";
    // }
    // else{
    //     while(!fin.eof()){
    //         while(getline(fin, FlightData, '\n')){
    //             stringstream ss(FlightData);
    //             string temp;
    //             while(getline(ss, temp, ',')){
    //                 int a = atoi((temp).c_str());
    //                 FlightCity.push_back(a);
    //             } 
    //             f.addEdge(FlightCity.getEntry(1), FlightCity.getEntry(2)); 
    //             FlightCity.clear();   
    //         }
    //     }       
    // }
    // fin.close();
    // int u = 3, v = 1;
    // if(f.isPath(u, v)){
    //     if(f.direct)
    //         cout<< "\n There is a direct path from " << u << " to " << v;
    //     else cout<< "\n There is a indirect path from " << u << " to " << v;        
    // }
    // else
    //     cout<< "\n There is no path from " << u << " to " << v;
    // return 0;
// }