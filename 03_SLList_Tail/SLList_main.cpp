#include "SLList.hpp"
#include <iostream>

int main(void) {
    SLList list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);

    list.print();
    std::cout << std::endl << list.size() << std::endl;
    
    list.clear();
    list.print();
    std::cout << std::endl << list.size() << std::endl;

    return 0;

}