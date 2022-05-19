#ifndef BST_H
#define BST_H
#include <iostream>
#include "TreeNode.h"

using namespace std;


template <class T>
class BST{
    public:
        BST();
        ~BST();
        void insert(T value);
        bool contains(T value);//search
        bool deleteNode(T k);
        bool isEmpty();
        void destructRecursive(TreeNode<T>* node);

        T* getMin();
        T* getMax();
        TreeNode<T> *getSuccessor(TreeNode<T> *d); //d represents the node we are going to delete
        void printNodes();
        void recPrint(TreeNode<T> *node);
        T calcSum(TreeNode<T> *node);
        TreeNode<T>* getRoot();
    private:
        TreeNode<T> *root;
};

template <class T>
BST<T>::BST(){
    root = NULL;
}

template <class T>
BST<T>::~BST(){
    destructRecursive(root);
}

template <class T>
void BST<T>::destructRecursive(TreeNode<T>* node)
{
    if (node != NULL)
    {
        destructRecursive(node->left);
        destructRecursive(node->right);
        delete node;
    }
}

template <class T>
TreeNode<T>* BST<T>::getRoot(){
    return root;
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
    if(node == NULL)
        return;

    cout << node->key << endl;
    recPrint(node->left);
    recPrint(node->right);
}

template <class T>
T BST<T>::calcSum(TreeNode<T> *node){
    if(node == NULL)
        return 0;

    return (node->key + calcSum(node->left) + calcSum(node->right));
}

template <class T>
/*this function prints the entire tree*/
void BST<T>::printNodes(){
    recPrint(root);
}

template <class T>
bool BST<T>::isEmpty(){
    return (root == NULL);
}

template <class T>
T* BST<T>::getMin(){
    if(isEmpty())
        return NULL;

    TreeNode<T> *current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return &(current->key);
}

template <class T>
T* BST<T>::getMax(){
    if(isEmpty())
        return NULL;

    TreeNode<T> *current = root;
    while(current->right != NULL){
        current = current->right;
    }
    return &(current->key);
}

template <class T>
void BST<T>::insert(T value){
    TreeNode<T> *node = new TreeNode<T>(value);
    if(isEmpty()) {
        root = node;
      }
    else{
        //the tree is not empty
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;

        while(true){
            parent = current;

            if(value < current->key){
                //we go left
                current = current->left;
                if(current == NULL){
                    //we found the insertion point
                    parent->left = node;
                    break;
                }
            }
            else{
                //we go right
                current = current->right;
                if(current == NULL){
                    //we found the insertion point
                    parent->right = node;
                    break;
                }
            }
        }
    }



}

template <class T>
bool BST<T>::contains(T value){
    if(isEmpty())
        return false;

    TreeNode<T> *current = root;

    while(current->key != value){
        if(value < current->key)
            current = current->left;
        else
            current = current->right;

        if(current == NULL)
            return NULL;
    }
    return true;
}

template <class T>
bool BST<T>::deleteNode(T k){
  if(isEmpty()) {
    return false;
  }
    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    //search for node to be deleted
    while(current->key != k) {
      parent = current;

      if(current->key > k) {
        isLeft = true;
        current = current->left;
      } else {
        isLeft = false;
        current = current->right;
      }

      if(current == NULL) {
        return false;
      }
    }

    //found the node to be deleted time to process

    if(current->left == NULL && current->right == NULL) { //its a leaf node to be deleted
      if(current == root) {
        root = NULL;

      } else if(isLeft) {
        parent->left = NULL;
      } else {
        parent->right = NULL;
      }
    } else if(current->right == NULL) {//Node to be deleted only has a left child
      if(current == root) {
        root = current->left;
      } else if(isLeft) {
        parent->left = current->left;
      } else {
        parent->right = current->left;
      }
    } else if(current->left == NULL) {//Node to be deleted only has a right child
      if(current == root) {
        root = current->right;
      } else if(isLeft) {
        parent->left = current->right;
      } else {
        parent->right = current->right;
      }
    } else { //node tp be deleted has two children
        TreeNode<T> *successor = getSuccessor(current);

        if(current == root) {
          root = successor;
        } else if(isLeft) {
          parent->left = successor;
        } else {
          parent->right = successor;
        }

        successor->left = current->left;
    }

    current->left = NULL;
    current->right = NULL;
    delete current;
    return true;




}

template <class T>
/* d represents the node to be delete */
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
  TreeNode<T> *sp = d;
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right;

  while(current != NULL) {
    sp = successor;
    successor = current;
    current = current->left;
  }
  //we found the successor but need to check if the successor is a descendant of the right child
  if(successor != d->right) {
    sp->left = successor->right;
    successor->right = d->right;
  }

  return successor;
}



#endif
