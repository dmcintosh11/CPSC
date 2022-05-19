//Header file for StudentTree.cpp
//Simulates a Student Tree in the record
#ifndef STUDENTTREE_H
#define STUDENTTREE_H

#include "Student.h"
#include <string>
#include "DoublyLinkedList.h"
#include "BST.h"

using namespace std;

class StudentTree: public BST<Student>
{
  protected:


  public:
    StudentTree();
    ~StudentTree();

    void printAllAscending();
    void recPrint(TreeNode<Student> *node);
    int getAdvisor(int studID);
    void addStudent(Student s);
    bool deleteStudent(int id);
    void setAdvisor(int studID, int facID);
    bool contains(int id);
    TreeNode<Student>* find(int id);
    void unassignAdvisor(int id);
    void recUnassign(TreeNode<Student>* node, int id);
    DoublyLinkedList<int> fillEmptyAdv(int id);
    void recFillEmpty(TreeNode<Student>* node, DoublyLinkedList<int>* emptyAdvs, int id);




};

#endif
