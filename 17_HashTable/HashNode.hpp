#ifndef HASHNODE_HPP
#define HASHNODE_HPP

template <typename T>
class HashNode {
public:
    HashNode(int k, T val) : key(k), value(val) {}
    //miss his constructor

    int key;
    T value;
};

#endif