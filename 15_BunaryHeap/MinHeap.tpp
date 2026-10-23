#include "MinHeap.hpp"
#include <iostream>
#include <stdexcept>

template <typename T>
void MinHeap<T>::swap(T& v1, T& v2) {
    T temp = v1;
    v1 = v2;
    v2 = temp;
}

template <typename T>
void MinHeap<T>::print() const {
    for (const T& val : data) {
        std::cout << val << " ";
    }
    std::cout << '\n';
}


template <typename T>
void MinHeap<T>::insert(const T& val) {
    data.push_back(val);
    int index = data.size() - 1;
    percolateUp(index);
}


// TODO implement 3 methods (Return -1 if the index doesn't exist)
template <typename T>
int MinHeap<T>::getParent(int index) const {
    if (index <= 0 || index >= data.size()) {
        return -1;
    }
    
    return (index - 1) / 2;
}

template <typename T>
int MinHeap<T>::getLeftChild(int index) const {
    if (index < 0 || index >= data.size()) {
        return -1;
    }
    
    int left = 2 * index + 1;
    if (left >= data.size()) {
        return -1;
    }
    
    return left;
}

template <typename T>
int MinHeap<T>::getRightChild(int index) const {
    if (index < 0 || index >= data.size()) {
        return -1;
    }
    
    int right = 2 * index + 2;
    if (right >= data.size()) {
        return -1;
    }

    return right;
}

template <typename T>
void MinHeap<T>::percolateUp(int index) {
    if (index < 0 || index >= data.size()) {
        std::cout << "percolateUp: incorrect index\n";
        return;
    }

    while (true) {
        int parent_idx = getParent(index);

        if (parent_idx == -1) {
            break;
        }

        if (data[index] < data[parent_idx]) {
            swap(data[index], data[parent_idx]);
            index = parent_idx;
        } 
        else {
            break;
        }
    }
}

template <typename T>
T MinHeap<T>::deleteMin(){
    if(data.empty()){
        throw std::out_of_range("deleteMin: empty Heap");
    }

    T res = data[0];
    int last_idx = data.size() -1;
    data[0] = data[last_idx];
    data.pop_back();

    percolateDown();
    return res;
}

template <typename T>
void MinHeap<T>::percolateDown() {
    int index = 0;
    while(true) {
        int left = getLeftChild(index);
        int right = getRightChild(index);

        if (left == -1) {
            break;
        }

        int smallest = index;

        if (data[left] < data[smallest]) {
            smallest = left;
        }

        if (right != -1 && data[right] < data[smallest]) {
            smallest = right;
        }

        if (smallest == index) {
            break;
        }

        swap(data[index], data[smallest]);
        index = smallest;
    }
}