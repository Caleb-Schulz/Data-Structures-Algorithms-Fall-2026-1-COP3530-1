#include "Deque.hpp"
#include <iostream>
#include <stdexcept>

template <typename T, int size>
Deque<T, size>::Deque() {
    front_idx = back_idx = queue_size = 0;
}

template <typename T, int size>
bool        Deque<T, size>::empty() const {
    return queue_size == 0;
}

template <typename T, int size>
bool        Deque<T, size>::full() const {
    return queue_size == size;
}

template <typename T, int size>
void        Deque<T, size>::print() const {
    std::cout << "[ ";
    int i = front_idx;
    while (i != back_idx) {
        std::cout << data[i] << " ";
        i = (i + 1) % size;     // Go to the next element
    }
    std::cout << "]\n";
}

template <typename T, int size>
void       Deque<T, size>::push_back(const T& val) {
    if (full()) {
        throw std::out_of_range("push_back : Full deque");
    }
    
    data[back_idx] = val;
    back_idx = (back_idx + 1) % size;
    queue_size++;
    
}

template <typename T, int size>
void       Deque<T, size>::push_front(const T& val) {
    if (full()) {
        throw std::out_of_range("push_front : Full deque");
    }
    front_idx = (front_idx - 1 + size) % size;
    data[front_idx] = val;
    queue_size++;
    
}

template <typename T, int size>
T    Deque<T, size>::pop_front() {
    if (empty()) {
        throw std::out_of_range("pop_front: Empty queue");
    }
    int old_front = front_idx;
    front_idx = (front_idx + 1) % size;
    queue_size--;
    return data[old_front];
}

template <typename T, int size>
T    Deque<T, size>::pop_back() {
    if (empty()) {
        throw std::out_of_range("pop_back: Empty queue");
    }
    back_idx = (back_idx - 1 + size) % size;
    queue_size--;
    return data[back_idx];
}
