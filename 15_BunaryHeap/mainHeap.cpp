#include "MinHeap.hpp"
#include <iostream>

int main(void) {
    MinHeap<int> heap;

    for (int i = 20; i > 0; i--) {
        heap.insert(i);
    }

    heap.print();


    return 0;
}