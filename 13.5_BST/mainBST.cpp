// Create BST, insert nodes, check contain method

#include "BST.hpp"
#include <string>
#include <iostream>

int main(void) {
    BST<int> tree;

    tree.insert(30);
    tree.insert(20);
    tree.insert(10);


    tree.print();

    tree.rotateRight(tree.root);
    tree.print();

    tree.insert(40);
    tree.insert(50);
    tree.insert(60);

    tree.print();

    tree.rotateLeft(tree.root);
    tree.print();

    
    
    return 0;
}

