#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP
#include <vector>

template <typename T>
class MinHeap {
public:
    void insert(const T& val);
    void print() const;

    T deleteMin();

    bool empty() const;

private:
    std::vector<T> data;

    int getParent(int index) const;
    int getLeftChild(int index) const;
    int getRightChild(int index) const;
    void percolateUp(int index); // Think or implement
    void percolateDown();

    void swap(T& v1, T& v2);
};

#include "MinHeap.tpp"


#endif