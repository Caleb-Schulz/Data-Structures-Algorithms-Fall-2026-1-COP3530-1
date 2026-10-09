#include "BST.hpp"

#include <iostream>
#include <string>

int main(void) {
    BST<std::string> tree;
    tree.insert("$$$$");
    tree.insert("a");
    tree.insert("Have");
    tree.insert("good");
    tree.insert("don't");
    tree.insert("bad");
    tree.insert("weekend!");
    tree.insert("year!");
    

    tree.inorder();

    auto n = tree.getMinNode();
    if (!n || n->data != "$$$$") {
        std::cout << "!!!FIX getMinNode()!!!" << std::endl;
    }

    auto c = tree.search("bad");
    auto p = tree.searchParent("bad");
    tree.deleteLeaf(c, p);
    tree.inorder();
    
    c = tree.search("year!");
    p = tree.searchParent("year!");
    tree.deleteLeaf(c, p);
    tree.inorder();
    
    c = tree.search("don't");
    p = tree.searchParent("don't");
    tree.deleteNodeWithOneChild(c, p);
    tree.inorder();
    
    c = tree.search("$$$$");
    p = tree.searchParent("$$$$");
    tree.deleteNodeWithOneChild(c, p);
    
    tree.inorder();

    return 0;
}


