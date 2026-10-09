#ifndef BST_HPP
#define BST_HPP

#include "BTNode.hpp"
#include <string>

template <typename T>
class BST {
public:
    BST();

    bool empty() const;
    void insert(const T& val);

    bool contains(const T& val) const; 
    const BTNode<T>* search(const T& val) const;
    const BTNode<T>* searchParent(const T& val) const;
    
    void inorder() const;
    void print() const;
    
    const BTNode<T>* getMinNode() const;

    void remove(const T& val);
    

    void rotateRight(BTNode<T>*& node);
    void rotateLeft(BTNode<T>*& node);
    void rotateLeftRight(BTNode<T>*& node);
    void rotateRightLeft(BTNode<T>*& node);

    BTNode<T>* root;

private:
    
    void inorder(const BTNode<T>* node) const;
    
    const BTNode<T>* search(const BTNode<T>* node, const T& val) const;
    const BTNode<T>* getMinNode(const BTNode<T>* node) const;
    void print(const std::string& prefix, const BTNode<T>* node, bool isRight) const;

    void deleteLeaf(BTNode<T>* child, BTNode<T>* parent);
    void deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent);
    void deleteNodeWithTwoChild(BTNode<T>* child);

    int height(const BTNode<T>* node) const;
    int getBalance(const BTNode<T>* node) const;
};

#include "BST.tpp"

#endif