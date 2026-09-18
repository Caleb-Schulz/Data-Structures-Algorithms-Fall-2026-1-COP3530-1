#include "DLList.hpp"
#include "DLList.tpp"
#include <iostream>

int main(void) {
    DLList<char> list;

    list.push_front('q');
    list.push_front('e');
    list.push_front('r');
    

    list.print();

    return 0;
}