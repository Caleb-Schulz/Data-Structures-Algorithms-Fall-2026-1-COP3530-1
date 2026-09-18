#include "SLList.hpp"
#include <iostream>
#include <stdexcept>

SLList::SLList() : head(nullptr), tail(nullptr), list_size(0) {

}

SLList::~SLList() {
    clear();
}

SLList::SLList(const SLList& other) : head(nullptr), tail(nullptr), list_size(0) {
    SLLNode* cur = other.head;
    while (cur != nullptr) {
        push_back(cur->data);
        cur = cur->next;
    }
}


SLList& SLList::operator=(const SLList& other) {
    if (this != &other) { 
        clear();
        SLLNode* cur = other.head;
        while (cur != nullptr) {
            push_back(cur->data);
            cur = cur->next;
        }
    }
    return *this;
}

unsigned SLList::size() const {
    return list_size;
}

bool SLList::empty() const {
    return (size() == 0);
}

void SLList::push_front(int val) {
    // SLLNode* new_node = new SLLNode(val);
    // new_node->next = head;
    // head = new_node;

    head = new SLLNode(val, head);

    list_size++;

    if (size() == 1) {
        tail = head;
    }
}

void SLList::print() const {
    std::cout << "{ ";

    SLLNode* cur = head;
    while (cur) {
        std::cout << cur->data;
        if (cur->next) {  // If not the last node
            std::cout << " -> ";
        }
        cur = cur->next; 
    }
    std::cout << " }";
}


void SLList::push_back(int val) {
    // if (empty()) {
    //     head = new SLLNode(val);
    // }
    // else {
    //     SLLNode* cur = head;
    //     // Find the last node in the list
    //     while (cur->next) {
    //         cur = cur->next;
    //     }
    //     cur->next = new SLLNode (val);
    // }

    if (empty()) {
        push_front(val);
        return;
    }

    tail->next = new SLLNode(val);  // Add the new node at the end
    tail = tail->next;              // Update the tail


    // Increment the list size 
    list_size++;
}

void SLList::pop_front(void) {
    if (!empty()) {
        SLLNode* old_head = head;
        head = head->next;
    
        delete old_head;
    
        list_size--;
        if (empty()) {              // If the last node was deleted
            tail = head;            // Update the tail
        }
    }
}

void SLList::pop_back(void) {
    if (empty()) {
        return;
    }


    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        list_size = 0;
        return;
    }

    SLLNode* cur = head;
    while (cur->next != tail) {
        cur = cur->next;
    }

    delete tail;
    tail = cur;
    tail->next = nullptr;
    list_size--;
}

void SLList::clear(void) {
    while (!empty()) {
        pop_front();
    }
}

int& SLList::at(unsigned index){
    if (index >= size()) {
        throw std::logic_error("at: incorrect index");
    }

    SLLNode* cur = head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur->data;
}