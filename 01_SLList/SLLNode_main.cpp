#include <iostream>
#include "SLLNode.hpp"

int main(void) {
    //create SLLNodes
    SLLNode* n1 = new SLLNode(1);
    SLLNode* n2 = new SLLNode(2);
    SLLNode* n3 = new SLLNode(3);
    SLLNode* n4 = new SLLNode(4);

    //Link the nodes
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    //print the value of the first node

    std::cout << n1->data <<std::endl;


    std::cout << n2->data <<std::endl;
    std::cout << n1->next->data <<std::endl;

    SLLNode* cur = n1;

    while (cur != nullptr) {
        std::cout << cur->data << " ";
        cur = cur->next;
    }






    return 0;

}