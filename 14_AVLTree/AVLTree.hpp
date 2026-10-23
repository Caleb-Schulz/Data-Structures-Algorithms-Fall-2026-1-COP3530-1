#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "AVLNode.hpp"
#include <string>

template <typename T>
class AVLTree {
public:
    // Constructor and Destructor
    AVLTree();
    ~AVLTree();

    // Basic Operations
    bool empty() const;
    void insert(const T& val);
    void remove(const T& val);
    bool contains(const T& val) const;

    // Traversal and Printing
    void inorder() const;
    void print() const;

private:
    AVLNode<T>* root;

    // Memory Management
    void clear(AVLNode<T>* node);

    // Searching
    const AVLNode<T>* search(const AVLNode<T>* node, const T& val) const;

    const AVLNode<T>* getMinNode(const AVLNode<T>* node) const;

    // Traversal and Printing
    void inorder(const AVLNode<T>* node) const;
    void print(const std::string& prefix, const AVLNode<T>* node, bool isRight) const;

    // Recursive Insertion and Deletion
    void insert(const T& val, AVLNode<T>*& node);
    void remove(const T& val, AVLNode<T>*& node);

    // Height and Balance
    int getHeight(const AVLNode<T>* node) const;
    int getBalance(const AVLNode<T>* node) const;
    void updateHeight(AVLNode<T>* node);
    void rebalance(AVLNode<T>*& node);

    // Rotations
    void rotateLeft(AVLNode<T>*& node);
    void rotateRight(AVLNode<T>*& node);
    void rotateLeftRight(AVLNode<T>*& node);
    void rotateRightLeft(AVLNode<T>*& node);
};

#include "AVLTree.tpp"

#endif