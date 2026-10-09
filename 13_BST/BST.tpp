#include "BST.hpp"
#include <iostream>

template <typename T>
BST<T>::BST() : root(nullptr) {
    
}


template <typename T>
bool BST<T>::empty() const {
    return root == nullptr;
}

template <typename T>
void BST<T>::insert(const T& val) {
    if (empty()) {
        root = new BTNode<T>(val);
        return;
    }

    BTNode<T>* cur = root;
    BTNode<T>* parent = root;

    // Iterate through BST
    while (cur) {
        parent = cur;

        if (val < cur->data) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    if (val < parent->data) {
        parent->left = new BTNode<T>(val);
    }
    else {
        parent->right = new BTNode<T>(val);
    }
}

template <typename T>
bool BST<T>::contains(const T& val) const {
    const BTNode<T>* cur = root;

    while (cur) {
        if (cur->data == val) {
            return true;
        }
        else if (cur->data > val) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    return false;
}

template <typename T>
BTNode<T>* BST<T>::search(BTNode<T>* node, const T& val) const {
    // Base case
    if (!node || node->data == val) {
        return node;
    }
    else if (val < node->data) {
        return search(node->left, val);
    }
    else {
        return search(node->right, val);
    }
}

template <typename T>
BTNode<T>* BST<T>::search(const T& val) const {
    return search(root, val);
}

template <typename T>
void BST<T>::inorder() const {
    std::cout << "Inorder: [ ";
    inorder(root);
    std::cout << "]\n";
}

template <typename T>
void BST<T>::inorder(const BTNode<T>* node) const {
    if (!node) {
        return;
    }
    inorder(node->left);
    std::cout << node->data << ' ';
    inorder(node->right);
}

template <typename T>
BTNode<T>* BST<T>::getMinNode() const {
    if (empty()) {
        return nullptr;
    }
    BTNode<T>* cur = root;
    while (cur->left) {
        cur = cur->left;
    }
    return cur;
}

template <typename T>
BTNode<T>* BST<T>::searchParent(const T& val) const {
    if (empty() || root->data == val) {
        return nullptr;
    }

    BTNode<T>* cur = root;

    while (cur) {
        if ((cur->left && cur->left->data == val) || 
            (cur->right && cur->right->data == val)) {
            return cur;
        }
        else if (cur->data > val) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }

    return nullptr;
}

template <typename T>
void BST<T>::deleteLeaf(BTNode<T>* child, BTNode<T>* parent) {
    if (!child || !child->isLeaf()) {
        return;
    }
    if (root == child) {
        root = nullptr;
    }
    else if (parent->left == child) {
        parent->left = nullptr;
    }
    else if (parent->right == child) {
        parent->right = nullptr;
    }
    delete child;
}

template <typename T>
void BST<T>::deleteNodeWithOneChild(BTNode<T>* child, BTNode<T>* parent) {
    if (!child) {
        return;
    }

    if (child->isLeaf()) {
        deleteLeaf(child, parent);
        return;
    }

    if (!child->hasOnlyOneChild()) {
        return;
    }

    BTNode<T>* grandchild = (child->left != nullptr) ? child->left : child->right;

    if (child == root) {
        root = grandchild;
    } 
    else if (parent) {
        if (parent->left == child) {
            parent->left = grandchild;
        } 
        else if (parent->right == child) {
            parent->right = grandchild;
        }
    }

    delete child;
}