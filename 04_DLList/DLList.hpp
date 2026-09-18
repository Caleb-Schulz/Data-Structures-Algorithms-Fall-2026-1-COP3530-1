#ifndef DLIST_HPP
#define DLIST_HPP

#include "DLLNode.hpp"

template <typename T>
class DLList {
public:
    // No-arg constructor
    DLList();

    // ~SLList();
    
    // // The copy constructor
    // SLList(const SLList& other);
    // // Assignment operator (=)
    // SLList& operator=(const SLList& other);


    // unsigned    size() const;           // Return the size of the list
    // bool        empty() const;          // Return true if list is empty
    void        push_front(const T& val);    // Insert the node at the beginning
    void        print() const;          // Print the list
    void        push_back(const T& val);     // Insert the node at the end 
    
    // void        pop_front(void);        // Remove the first node from the list
    // void        pop_back(void);         // Remove the last node from the list

    // void        clear(void);            // Remove all the nodes

    // int& at(unsigned index);
private:
    DLLNode<T>* head;                      // First node in the linked list
    DLLNode<T>* tail;                      // Last node in the linked list
    unsigned list_size;                 // The number of nodes in the linked list
};


#endif