#ifndef SLLNODE_HPP
#define SLLNODE_HPP

template <typename T>
class SLLNode {
public:
    T data;         // The data value
    SLLNode* next;  // Pointer to the next node

    SLLNode(T d = T(), SLLNode* n = nullptr) : data(d), next(n) {

    }
};


#endif