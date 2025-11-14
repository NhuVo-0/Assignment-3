#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <istream>
#include <sstream>
#ifndef Queue_H
#define Queue_H
#include <stdexcept>

using namespace std;

template<typename T> 
class Queue {
private:
    struct Node { //node structure
        T data; //template class T data
        Node* nextPtr;
        Node(const T& d, Node* next = nullptr) : data(d), nextPtr(next){} //node constructor
    };
	Node* headPtr; //head pointer
	Node* tailPtr; //tail pointer
    size_t counter; //counter to keep track of the size 
public:
    Queue(); //constructor

    ~Queue(); //destructor

    bool isempty() const; //check if Queue is empty

    size_t qSize() const; //check for the queue's size

    void push(const T& val); //push a const value to the queue

    void pop(); //pop the front value of the queue

    T& front(); //return the front of the queue

    const T& front() const; //return the const front of the queue

    void move_rear(); //moving the front value of the queue to the end

    void printQ(); //displace the queue


};

extern template class Queue<int>;
#endif