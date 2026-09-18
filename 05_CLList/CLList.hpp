#ifndef CLLIST_HPP
#define CLLIST_HPP

#include "SLLNode.hpp"

template <typename T>
class CLList {
public:
    // No-arg constructor
    CLList();
    // The copy constructor
    //CLList(const CLList<T>& other);
    
    // Destructor
    //~CLList();
    
    // Assignment operator (=)
    //CLList<T>& operator=(const CLList<T>& other);


    // unsigned    size() const;               // Return the size of the list
    bool        empty() const;              // Return true if list is empty
    void        push_front(const T& val);   // Insert the node at the beginning
    void        print() const;              // Print the list
    // void        push_back(const T& val);    // Insert the node at the end 
    
    void        pop_front(void);            // Remove the first node from the list
    // void        pop_back(void);             // Remove the last node from the list

    // void        clear(void);                // Remove all the nodes

    // T&          at(unsigned);               // Return the value of the certain node
private:
    
    SLLNode<T>* tail;                       // Last node in the linked list
    unsigned list_size;                     // The number of nodes in the linked list
};

#include "CLList.tpp" // Include implementation file for template class compilation

#endif