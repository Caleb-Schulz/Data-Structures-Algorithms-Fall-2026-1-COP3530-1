#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int d = 0, Node* n = nullptr) : data(d), next (n) {

    }

};

void printList(const Node* node);

void printListReverse(const Node* node);

int getListSize(const Node* node);

Node* reverseList(Node* node);

int main (void) {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "printList: "; 
    printList(head);

    std::cout << "Size: " << getListSize(head) << std::endl;

    std::cout << "printListReverse: "; 
    printListReverse(head);
    std::cout << "\n";

    std::cout << "reverseList & printList: "; 
    head = reverseList(head);
    printList(head);

    return 0;
}

void printList(const Node* node){
    if (!node){
        std::cout << "\n";
        return;
    }
    std::cout << node->data << " ";
    printList(node->next);
}

int getListSize(const Node* node){
    if (!node){
        return 0;
    }
    return 1 + getListSize(node->next);
}


void printListReverse(const Node* node){
    if (!node){
        return;
    }
    printListReverse(node->next);
    std::cout << node->data << " ";
}

Node* reverseList(Node* node) {
    if(!node ||!node->next){
        return node;
    }
    Node* new_head = reverseList(node->next);
    node->next->next = node;
    node->next = nullptr;

    return new_head;
}