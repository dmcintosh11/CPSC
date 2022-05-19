#ifndef TREENODE_H
#define TREENODE_H

template <class T>
class TreeNode{
    public:
        TreeNode();
        TreeNode(T key);
        virtual ~TreeNode();

        T key; //key = data
        TreeNode<T> *left;
        TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    key = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k){
    left = NULL;
    right = NULL;
    key = k;
}

template <class T>
TreeNode<T>::~TreeNode(){

    left = NULL;
    right = NULL;

}

#endif
