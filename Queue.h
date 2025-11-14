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
    struct Node { //node structure for the linked list
        T data; //template class T data
        Node* nextPtr;
        Node(const T& d, Node* next = nullptr) : data(d), nextPtr(next){} //node constructor
    };
	Node* headPtr; //head pointer
	Node* tailPtr; //tail pointer
    size_t counter; //counter to keep track of the size of the stack or the linked list, this will be inherited by the stack also
public:
    Queue();

    ~Queue();

    bool isempty() const;

    size_t qSize() const;

    void push(const T& val);

    void pop();

    T& front();

    const T& front() const;

    void move_rear();

    void printQ();


};

extern template class Queue<int>;
#endif