#ifndef HASHMAP_HPP
#define HASHMAP_HPP

template <typename T>
class HashMap {
public:
    HashMap(int capacity = 31);

    void insert(int key, const T& value);
    void print() const;
private:
    std::vector<HasNode<T>> data;
    int size;

    int hash(int key) const;
};

#include "HashMap.tpp"

#endif