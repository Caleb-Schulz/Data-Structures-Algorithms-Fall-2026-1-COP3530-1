#include "DLList.hpp"
#include "DLList.tpp"
#include <string>

int main(void) {
    std::string s("aBcDeFgHiJkLmNoPqRsTuVwXyZaBcDeOgHiJkLmNoPqRsTuVwXyZaBcDeFgHiJkLmNoPqRsTuVwXyZaBcDeFgHiJkLmNoPqRsTuV");

    DLList<char> list;

    list.push_back(s[58]);
    list.push_front(s[60]);
    list.push_front(s[53]);
    list.push_front(s[10]);
    list.push_back(s[31]);
    //list.pop_front();

 
    list.print();

    return 0;
}