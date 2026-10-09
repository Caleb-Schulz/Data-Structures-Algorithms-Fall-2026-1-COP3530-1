#ifndef BST_HPP
#define BST_HPP

#include "BTNode.hpp"

template <typename T>
class BST {
public:
    BST();

    bool empty() const;

    void insert(const T& val);

    bool contains(const T& val) const; 
    BTNode<T>* search(const T& val) const ;
    BTNode<T>* searchParent(const T& val) const;

    void inorder() const;

    BTNode<T>* getMinNode() const;
    void deleteLeaf(BTNode<T>* child, BTNode<T>* parent);
    void deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent);


private:
    BTNode<T>* root;
    void inorder(const BTNode<T>* node) const;
    BTNode<T>* search(BTNode<T>* node, const T& val) const;
};

#include "BST.tpp"

#endif