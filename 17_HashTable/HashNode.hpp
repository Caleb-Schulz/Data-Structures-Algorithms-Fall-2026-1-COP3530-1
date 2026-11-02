#ifndef HASHNODE_HPP
#define HASHNODE_HPP

template <typename T>
class HashNode {
public:
    HashNode(int key, const T& value) : key(key), value(value) {
    
    }

    bool empty () const {
        return key == -1;
    }

    bool deleted() const {
        return key == -2;
    }

    static HashNode<T> makeDeleted() {
        return HashNode<T>(-2, T());
    }

    static HashNode<T> makeEmpty() {
        return HashNode<T>(-1, T());
    }

    int key;
    T value;
};

#endif