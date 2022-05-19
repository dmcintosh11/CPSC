#include "FacultyTree.h"
#include "BST.h"
#include "Faculty.h"
#include "Student.h"

FacultyTree::FacultyTree() {
  BST<Faculty>();

}

FacultyTree::~FacultyTree() {

}


void FacultyTree::printAllAscending() {
  recPrint(getRoot());
}

void FacultyTree::recPrint(TreeNode<Faculty> *node){
    if(node == NULL)
        return;

    recPrint(node->left);
    node->key.printInfo();
    cout << "-----------" << endl;
    recPrint(node->right);
}

DoublyLinkedList<int> FacultyTree::getAdvisees(int facID) {
  return find(facID)->key.getAdvisees();
}

void FacultyTree::removeAdvisee(int facID, int studID) {
  find(facID)->key.removeAdvisee(studID);
}

void FacultyTree::addFaculty(Faculty f) {
  cout << endl;
  insert(f);
}

bool FacultyTree::deleteFaculty(int id) {
  Faculty* f = new Faculty(id);
  return deleteNode(*f);
}

void FacultyTree::addAdvisee(int facID, int studID) {
  Faculty f = find(studID)->key;
  f.addAdvisee(studID);
}

bool FacultyTree::contains(int id){
    if(isEmpty())
        return false;

    TreeNode<Faculty> *current = getRoot();

    while(current->key.getID() != id){
        if(id < current->key.getID())
            current = current->left;
        else
            current = current->right;

        if(current == NULL)
            return NULL;
    }
    return true;
}

TreeNode<Faculty>* FacultyTree::find(int id) {
  if(isEmpty())
      return NULL;

  TreeNode<Faculty> *current = getRoot();

  while(current->key.getID() != id){
      if(id < current->key.getID())
          current = current->left;
      else
          current = current->right;

      if(current == NULL)
          return NULL;
  }
  return current;
}

void FacultyTree::unassignAdvisee(int id) {
  recUnassign(getRoot(), id);
}

void FacultyTree::recUnassign(TreeNode<Faculty>* node, int id) {
  if(node == NULL)
      return;

  recUnassign(node->left, id);
  node->key.removeAdvisee(id);
  recUnassign(node->right, id);
}
