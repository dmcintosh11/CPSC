//File that contatins template classes for implementations of ListNode, DoublyLinkedList, and GenQueue
#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include <exception>
using namespace std;

//Declaration of ListNode
template <class T>
class ListNode{
    public:
        ListNode();
        ListNode(T d);
        ~ListNode();
        ListNode<T> *next;
        ListNode<T> *prev;
        T data;
};

//implementation
template <class T>
ListNode<T>::ListNode(){}

//Constructor
template <class T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL; // 0 nullptr
    prev = NULL;
}

//Destructor
template <class T>
ListNode<T>::~ListNode(){
    //research
    delete next;
    delete prev;
}

///doublylinked list class
template <class T>
class DoublyLinkedList{
    private:
        ListNode<T> *front;
        ListNode<T> *back;
        unsigned int size;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        void insertFront(T d);
        void insertBack(T d);
        ListNode<T>* getFront();
        T removeFront();
        T removeBack();
        T removeNode(T value);
        T find(T value);
        bool isEmpty();
        unsigned int getSize();
        void printList(bool isPrintLink);
};

//Constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}

//Destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    //guess what??? build some character and research
    ListNode<T> *node = front;
    ListNode<T> *nodeToDelete = front;
    while (node != NULL){
        nodeToDelete = node->next;
        delete node;
        node = nodeToDelete;
    }

/*    while (front->next != front)
	{
		ListNode<T>* p = front->next;
		p->next->prev = front;
		front->next = p->next;
		delete p;
	}
	delete front; */
}

//Inserts node at front of list
template <class T>
void DoublyLinkedList<T>::insertFront(T d){
    ListNode<T> * node = new ListNode<T>(d);

    if(isEmpty()){
        back = node;
    }
    else{
        //it's not empty
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}

//Inserts node at back of list
template <class T>
void DoublyLinkedList<T>::insertBack(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        front = node;
    }
    else{
        node->prev = back;
        back->next = node;
    }
    back = node;
    ++size;
}

//Returns data from front node
template <class T>
ListNode<T>* DoublyLinkedList<T>::getFront() {
  return front;
}

//Removes node at front of list
template <class T>
T DoublyLinkedList<T>::removeFront(){
    if(isEmpty()){
        throw runtime_error("list is empty!");
    }

    ListNode<T> *temp = front;

    if(front->next == NULL){
        back = NULL;
    }
    else{
        //more than one node in the list
        front->next->prev = NULL;
    }
    front = front->next;
    temp->next = NULL;
    T data = temp->data;
    --size;
    delete temp;
    return data;
}

//Removes node at back of list
template <class T>
T DoublyLinkedList<T>::removeBack(){
    if(isEmpty()){
        throw runtime_error("list is empty");
    }

    ListNode<T> *temp = front;

    if(back->prev == NULL){
        //only node in the list
        front = NULL;
    }
    else{
        //more than one node in the list
        back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    T data = temp->data;
    --size;
    delete temp;
    return data;
}

//Finds location of a node in list
template <class T>
T DoublyLinkedList<T>::find(T value){
    int pos = -1;
    ListNode<T> *curr = front;

    while(curr != NULL){
        ++pos;
        if(curr->data == value)
            break;

        curr = curr->next;
    }
    //checks if curr is NULL which signifies value not in Linked List
    if(curr == NULL)
        pos = -1;

    return pos;
}

//Removes a Node from list
template <class T>
T DoublyLinkedList<T>::removeNode(T value){
    if(isEmpty()){
        throw runtime_error("list is empty!");
    }

    //we could leverage the find method

    ListNode<T> *curr = front;
    while(curr->data != value){
        curr = curr->next;

        if(curr == NULL)
            return -1;
    }
    //but if we make it here, we found the value
    //we found it , let's proceed to remove it

    if(curr != front && curr != back){
        //it's in between front and back
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    if(curr == front){
        front = curr->next;
        front->prev = NULL;
    }

    if(curr == back){
        back = curr->prev;
        back->next = NULL;
    }

    curr->next = NULL;
    curr->prev = NULL;
    T data = curr->data;
    --size;
    delete curr;

    return data;
}

//Returns size of list
template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
    return size;
}

//Checks if list is empty
template <class T>
bool DoublyLinkedList<T>::isEmpty(){
    return (size == 0);
}

//Prints all items in list
template <class T>
void DoublyLinkedList<T>::printList(bool printLink)
{
    ListNode<T> *curr = front;
    while(curr != 0){
       if(curr == front){
         cout << "{FRONT}: ";
       }
       else if(curr == back){
         cout << "{REAR}: ";
       }
       if(printLink)
        cout << "[ PREV: "<< curr->prev << " || " << curr->data << " || NEXT: "<< curr->next << " ] ";
      else
        cout << "[ " << curr->data << " ] ";

       curr = curr->next;
       if(curr != 0){
         cout << " <==> ";
       }
    }
    cout << endl;
}

//Queue implementation using DoublyLinkedList
template <class T>
class GenQueue {
  public:
    GenQueue();//default constructor
    ~GenQueue();//destructor

    //core function
    void insert(T d);//aka enqueue
    void enqueue(T d);
    T remove(); //aka dequeue

    //aux functions
    T peek();
    bool isEmpty();
    unsigned int getSize();
    void printArray();

  private:
    DoublyLinkedList<T> *myQueue;
};

//Constructor
template <class T>
GenQueue<T>::GenQueue() {
  myQueue = new DoublyLinkedList<T>();
}

//Destructor
template <class T>
GenQueue<T>::~GenQueue() {
  delete myQueue;
}

//Inserts to the bacj of DoublyLinkedList
template <class T>
void GenQueue<T>::insert(T d) {
  myQueue->insertBack(d);
}

//Removes and returns first item from the DoublyLinkedList
template <class T>
T GenQueue<T>::remove() {
  if(isEmpty()) {
    throw runtime_error("queue is empty");
  }

  return myQueue->removeFront();
}

//Returns the first item in DoublyLinkedList
template <class T>
T GenQueue<T>::peek() {
  return myQueue->getFront->data;
}

//Checks if the DoublyLinkedList is empty
template <class T>
bool GenQueue<T>::isEmpty() {
  return myQueue->getSize() == 0;
}

//Returns the size of the DoublyLinkedList
template <class T>
unsigned int GenQueue<T>::getSize() {
  return myQueue->getSize();
}

#endif
