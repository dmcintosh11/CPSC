#include "StudentTree.h"
#include "BST.h"
#include "Student.h"

StudentTree::StudentTree() {
  BST<Student>();
}

StudentTree::~StudentTree() {

}

void StudentTree::printAllAscending() {
  recPrint(getRoot());
}

void StudentTree::recPrint(TreeNode<Student> *node){
    if(node == NULL)
        return;

    recPrint(node->left);
    node->key.printInfo();
    cout << "-----------" << endl;
    recPrint(node->right);
}

int StudentTree::getAdvisor(int studID) {
  return find(studID)->key.getAdvisor();
}

void StudentTree::addStudent(Student s) {
  insert(s);
}

bool StudentTree::deleteStudent(int id) {
  Student* s = new Student(id);
  return deleteNode(*s);
}

void StudentTree::setAdvisor(int studID, int facID) {
  find(studID)->key.setAdvisor(facID);
}

bool StudentTree::contains(int id){
    if(isEmpty())
        return false;

    TreeNode<Student> *current = getRoot();

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

TreeNode<Student>* StudentTree::find(int id) {
  if(isEmpty())
      return NULL;

  TreeNode<Student> *current = getRoot();

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

void StudentTree::unassignAdvisor(int id) {
  recUnassign(getRoot(), id);
}

void StudentTree::recUnassign(TreeNode<Student>* node, int id) {
  if(node == NULL)
      return;

  recUnassign(node->left, id);
  if(node->key.getAdvisor() == id) {
    node->key.setAdvisor(-1);
  }
  recUnassign(node->right, id);
}

DoublyLinkedList<int> StudentTree::fillEmptyAdv(int id) {
  DoublyLinkedList<int>* emptyAdvs = new DoublyLinkedList<int>();
  recFillEmpty(getRoot(), emptyAdvs, id);
  return *emptyAdvs;

}

void StudentTree::recFillEmpty(TreeNode<Student>* node, DoublyLinkedList<int>* emptyAdvs, int id) {

  if(node == NULL)
      return;

  recFillEmpty(node->left, emptyAdvs, id);
  if(node->key.getAdvisor() == -1) {
    emptyAdvs->insertBack(node->key.getID());
    node->key.setAdvisor(id);
  }
  recFillEmpty(node->right, emptyAdvs, id);
}

void StudentTree::toCSV(TreeNode<Student>* node, string &s) {

  if(node == NULL)
      return;

  toCSV(node->left, s);
  s += (node->key.toCSV() + "\n");
  toCSV(node->right, s);

}
