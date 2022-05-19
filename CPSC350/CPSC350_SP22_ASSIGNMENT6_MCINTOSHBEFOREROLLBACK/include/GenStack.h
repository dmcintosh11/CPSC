#ifndef GENSTACK_H
#define GENSTACK_H

#include "DoublyLinkedList.h"

//Stack implementation using DoublyLinkedList
template <class T>
class GenStack {
  public:
    GenStack(); //Default constructor
    ~GenStack(); //Destructor

    //core functions
    void push(T data);
    T pop();
    T peek();

    //aux functions
    bool isEmpty();
    int getSize();
    void empty();
  private:
    DoublyLinkedList<T>* doubleList;
    int size;
};

//Constructor
template <class T>
GenStack<T>::GenStack() {
  doubleList = new DoublyLinkedList<T>();
  size = 0;
}

//Destructor
template <class T>
GenStack<T>::~GenStack() {
  delete doubleList;
}

//Inserts new object onto top of stack
template <class T>
void GenStack<T>::push(T data) {
    doubleList->insertFront(data);
    size++;

}

//Removes and returns top of stack
template <class T>
T GenStack<T>::pop() {
  //make sure stack is not empty before proceeding
  if(isEmpty()) {
    throw runtime_error("stack is empty, nothing to pop (missing delimiter)");
  } else {
    T temp = doubleList->removeFront();
    size--;
    return temp;
  }
}

//Returns item on the top of stack
template <class T>
T GenStack<T>::peek() {
  //Make sure stack is not empty
  if(isEmpty()) {
    throw runtime_error("stack is empty, nothing to peek");
  } else {
    return doubleList->getFront();
  }
}

//Checks if stack is empty
template <class T>
bool GenStack<T>::isEmpty() {
  return doubleList->isEmpty();
}

//Returns size of stack
template <class T>
int GenStack<T>::getSize() {
  return doubleList->getSize();
}

//Empties out all items in stack
template <class T>
void GenStack<T>::empty() {
  while (!isEmpty()) {
    pop();
  }
}

#endif
