#ifndef LISTNODE_H
#define LISTNODE_H

#include <string>

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

#endif
