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
        delete temp; //deleting the temp value within the Linked List
        temp = hold;
    }

    headPtr = nullptr; //setting the head and tail pointer == nullpointer to indicate Linked List is empty
    tailPtr = nullptr;
}

template<typename T>
size_t Queue<T>::qSize() const {
    return counter;
}

template<typename T>
void Queue<T>::push(const T& val) {
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
void Queue<T>::pop() {
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
T& Queue<T>::front() {
    return headPtr->data;
}


template<typename T>
const T& Queue<T>::front() const{
    return headPtr->data;
}

template<typename T>
void Queue<T>::move_rear() {
    if (qSize() <= 1) {
        return;
    }

    T firstVal = front();
    pop();
    push(firstVal);
}

template<typename T>
void Queue<T>::printQ() {
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