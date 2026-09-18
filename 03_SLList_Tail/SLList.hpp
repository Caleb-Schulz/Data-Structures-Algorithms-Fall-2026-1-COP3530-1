#ifndef SLLIST_HPP
#define SLLIST_HPP

#include "SLLNode.hpp"

class SLList {
public:
    // No-arg constructor
    SLList();

    ~SLList();
    
    // The copy constructor
    SLList(const SLList& other);
    // Assignment operator (=)
    SLList& operator=(const SLList& other);


    unsigned    size() const;           // Return the size of the list
    bool        empty() const;          // Return true if list is empty
    void        push_front(int val);    // Insert the node at the beginning
    void        print() const;          // Print the list
    void        push_back(int val);     // Insert the node at the end 
    
    void        pop_front(void);        // Remove the first node from the list
    void        pop_back(void);         // Remove the last node from the list

    void        clear(void);            // Remove all the nodes

    int& at(unsigned index);
private:
    SLLNode* head;                      // First node in the linked list
    SLLNode* tail;                      // Last node in the linked list
    unsigned list_size;                 // The number of nodes in the linked list
};


#endif