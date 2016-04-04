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
#ifndef FLIGHT_HPP
#define FLIGHT_HPP
#include <iostream>
// #include <string>
using namespace std;

class Flight{   
    int size;           
    int** array;
public:
    Flight(int size); 
    ~Flight();
    void addEdge(int City1, int City2); // function to add an edge to graph
    void markVisited(int visitedCity);
    void unvisitAll();
    int getNextCity(int aCity);
    bool isPath(int Origin, int Destination); // function to find whether there is a path (directly or indirectly)
    bool direct;
    bool *visited = new bool[size];    
    void display();
};
#include "Flight.cpp"
#endif