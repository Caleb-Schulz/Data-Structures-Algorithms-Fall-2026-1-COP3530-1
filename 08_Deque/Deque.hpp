#ifndef DEQUE_HPP
#define DEQUE_HPP

template <typename T, int size = 100>
class Deque {
public:
    Deque();

    bool        empty() const;
    bool        full() const;
    void        print() const;
    void        push_back(const T& val);
    void        push_front(const T& val);

    T    pop_front();
    T    pop_back();

    // TODO
    const T&    front(); // Return the first element in the queue
    const T&    back();
    void        clear(); // Remove all the elements from the queue
    int         size();  // Return the size of the queue

    
private:
    T data[size];
    int front_idx, back_idx;
    int queue_size;
};

#include "Deque.tpp"

#endif