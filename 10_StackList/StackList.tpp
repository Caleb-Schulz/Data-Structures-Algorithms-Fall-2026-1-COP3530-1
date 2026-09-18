#include "StackList.hpp"
#include <stdexcept>
#include <iostream>


template <typename T>
StackList<T>::StackList() {
    top_node = nullptr;
    
}


template <typename T>
StackList<T>::~StackList() {
    while(!empty()) {
        pop();
    }
}

template <typename T>
void StackList<T>::push(const T& val) {
    top_node = new Node<T>(val, top_node);
}


template <typename T>
bool        StackList<T>::empty() const {
    return top_node == nullptr;

}

template <typename T>
void        StackList<T>::print() const {
// don't need to do
}

template <typename T>
T           StackList<T>::pop() {
    if(empty()){
        throw STD::out_of_range("pop: Empty Stack");
    }
    else{
        Node<T>* temp = top_node;
        T val = temp->data;
        top_node = top_node->next;
        delete temp;
        return val;
    }

}

template <typename T>
const T& StackList<T>::top() const {
    if (empty()) {
        throw std::underflow_error("Stack is empty");
    }
    return top_node->data;
}
    