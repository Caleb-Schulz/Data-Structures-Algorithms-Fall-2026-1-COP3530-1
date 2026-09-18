#include "DLList.hpp"
#include <iostream>

template <typename T>
DLList<T>::DLList() {
    head = new DLLNode<T>;      // Sentinel node
    tail = new DLLNode<T>;      // Sentinel node
    // Connecting head and tail
    head->next = tail;
    tail->prev = head;
    list_size = 0;
}

template <typename T>
void DLList<T>::push_front(const T& val) {
    head->next = new DLLNode<T>(val, head, head->next);
    head->next->next->prev = head->next;   // Think about it

    list_size++;
}

template <typename T>
void DLList<T>::print() const {
    DLLNode<T>* cur = head->next;

    while (cur != tail) {
        std::cout << cur->data;
        cur = cur->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DLList<T>:: push_back(const T& val) {
    DLLNode<T>* newNode = new DLLNode<T>(val, tail->prev, tail);
    tail->prev->next = newNode;
    tail->prev = newNode;

    list_size++;
}