#include <iostream>
#include "AVLTree.hpp"

int main(void) {
    AVLTree<int> tree;
    tree.insert(30);
    tree.insert(10);
    tree.insert(20);
    tree.print();
    return 0;
}