#include "HashMap.hpp"
#include "HashNode.hpp"

template <typename T>
HashMap<T>::HashMap(int capacity) : size(0){
    data.resize(capacity, HashNode(-1, T()))
}

template <typename T>
void HashMap<T>::insert(int key, const T& value) {
    if (size == data.size()) {
        return;
    }

    int index = hash(key);

    if (data[index].key != -1) {
        std::cout << "insert: the slot is already occupied" << std::endl;
        return;
    }

    data[index] = HashNode(key, value);
    size++;
}

template <typename T>
void HashMap<T>::print() const {

}

template <typename T>
int HashMap<T>::hash(int key) const {
    return key % data.size();
}