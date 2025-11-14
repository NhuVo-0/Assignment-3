#include "Queue.h"

template<typename T>
Queue<T>::Queue()
    : headPtr(nullptr), tailPtr(nullptr), counter(0) {}  // constructor

template<typename T>
Queue<T>::~Queue() {
    Node* temp = headPtr;
    Node* hold;  // holder for head pointer

    while (temp != nullptr) {  // checking if headptr is null
        hold = temp->nextPtr;
        delete temp; //deleting the temp value 
        temp = hold;
    }

    headPtr = nullptr; //setting the head and tail pointer == nullpointer to indicate  is empty
    tailPtr = nullptr;
}

template<typename T>
size_t Queue<T>::qSize() const {
    return counter; //return the counter that keep track of the queue size
}

template<typename T>
void Queue<T>::push(const T& val) { //pushing value into the queue
    Node* newNode = new Node(val);
    if (isempty()) {
        headPtr = tailPtr = newNode;
    }
    else  {
        tailPtr->nextPtr = newNode;
        tailPtr = newNode;
    }
    counter++; 
}

template<typename T>
bool Queue<T>::isempty() const {  // check if Queue is empty
    return headPtr == nullptr;
}


template<typename T>
void Queue<T>::pop() { //removing the front value of the queue
    if (isempty()) return;

    Node* OGfront = headPtr;
    headPtr = headPtr->nextPtr;
    delete OGfront;
    --counter;
    
    if (counter == 0){
        tailPtr = nullptr;
    }
}


template<typename T>
T& Queue<T>::front() { //returning the front value
    return headPtr->data;
}


template<typename T> //returning the const front value
const T& Queue<T>::front() const{
    return headPtr->data;
}

template<typename T>
void Queue<T>::move_rear() { //moving the front value to the rear
    if (qSize() <= 1) {
        return;
    }

    T firstVal = front();
    pop();
    push(firstVal);
}

template<typename T>
void Queue<T>::printQ() { //print the entire queue unless it's empty
    if (isempty()) {
        cout << "Queue is empty!\n";
        return;
    }

    Node* current = headPtr;
    while(current != nullptr) {
        cout << current->data << " ";
        current = current->nextPtr;
    }
    cout << endl;
}


template class Queue<int>;