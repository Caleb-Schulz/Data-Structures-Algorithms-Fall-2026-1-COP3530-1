#include "CLList.hpp"

#include <iostream>

template <typename T>
CLList<T>::CLList() {
    tail = nullptr;
    list_size = 0;
}
template <typename T>

bool CLList<T>::empty() const {
    return list_size == 0;
}

template <typename T>
void CLList<T>::push_front(const T& val) {
    if (empty()) {
        tail = new SLLNode<T>(val);
        tail->next = tail;
    }
    else {
        tail->next = new SLLNode<T>(val, tail->next);
    }
    list_size++;
}

template <typename T>
void CLList<T>::print() const {
    if (list_size == 0) {
        return;
    }
    SLLNode<T>* cur = tail->next;
    do {
        std::cout << cur->data;
        if (cur != tail) { // not the last node
            std::cout << " -> ";
        }
        cur = cur->next;
    } while (cur != tail->next);
}

template <typename T>
void CLList<T>::pop_front() {
    if (empty()) {
        return;
    }
    SLLNode<T>* to_delete = tail->next;

    if (list_size == 1) {
        tail = nullptr;
    }
    else {
        tail->next = to_delete->next;
    }

    delete to_delete;
    list_size--;
}
