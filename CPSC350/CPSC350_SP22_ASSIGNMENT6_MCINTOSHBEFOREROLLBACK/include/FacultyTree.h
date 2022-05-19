//Header file for FacultyTree.cpp
//Simulates a Faculty Tree in the record
#ifndef FACULTYTREE_H
#define FACULTYTREE_H

#include "Faculty.h"
#include <string>
#include "DoublyLinkedList.h"
#include "BST.h"
#include "Student.h"

using namespace std;

class FacultyTree: public BST<Faculty>
{
  protected:


  public:
    FacultyTree();
    ~FacultyTree();

    void printAllAscending();
    void recPrint(TreeNode<Faculty> *node);
    DoublyLinkedList<int> getAdvisees(int facID);
    void removeAdvisee(int facID, int studID);
    void addFaculty(Faculty f);
    bool deleteFaculty(int id);
    void addAdvisee(int facID, int studID);
    bool contains(int id);
    TreeNode<Faculty>* find(int id);
    void unassignAdvisee(int id);
    void recUnassign(TreeNode<Faculty>* node, int id);
    void toCSV(TreeNode<Faculty>* node, string &s);




};

#endif
