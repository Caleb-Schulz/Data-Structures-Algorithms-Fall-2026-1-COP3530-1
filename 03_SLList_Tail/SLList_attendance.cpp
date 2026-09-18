#include "SLList.hpp"
#include <iostream>

int main(void) {
    SLList list;

    for (int i = 0; i < 100; i++) {
        if (i % 4 == 0) {
            list.push_front(i * 2);
            list.push_back(i * 2);
        }
        if (i % 5 == 2 || i % 5 == 3) {
            list.pop_back();
        }
    }

    std::cout << (char) (list.at(0) - 127);
    std::cout << (char) (list.at(1) - 108);
    std::cout << (char) (list.at(2) - 95);
    std::cout << (char) (list.at(3) - 101);
    std::cout << (char) (list.at(4) - 83) << std::endl;


    return 0;
}