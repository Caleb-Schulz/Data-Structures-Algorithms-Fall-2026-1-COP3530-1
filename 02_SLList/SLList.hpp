#ifndef SLLIST_HPP
#define SLLIST_HPP

#include "SLLNode.hpp"

class SLList {
public:
    SLList();

    unsigned    size() const;
    bool        empty() const;
    void        push_front(int val);
    void        print() const;


private:
    SLLNode* head;
    unsigned list_size;

};

#endif