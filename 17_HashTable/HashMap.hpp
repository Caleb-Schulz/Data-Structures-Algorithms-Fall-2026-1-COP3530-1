#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include "HashNode.hpp"
#include <vector>


template <typename T>
class HashMap {
public:
    HashMap(int capacity = 31);

    void insert(int key, const T& value);
    void print() const;

    const T& search(int key) const;

    void remove(int key);

private:
    std::vector<HashNode<T>> data;
    int size; // The number of records in the table

    int hash(int key) const;
    int searchIndex(int key) const;

};

#include "HashMap.tpp"

#endif 