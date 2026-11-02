#include "HashMap.hpp"


#include <iostream>

template <typename T>
HashMap<T>::HashMap(int capacity) : size(0) {
    data.resize(capacity, HashNode(-1, T()));
}

template <typename T>
void HashMap<T>::insert(int key, const T& value) {
    if (size == data.size()) {
        return;
    }

    // Find the hash value
    int index = hash(key);


    // Search for the next available position (Linear Probing)
    while (!data[index].empty()) {
        if (data[index].deleted()) {
            break;
        }
        // Go to the next postion
        index = (index + 1) % data.size();
    }

    // Insert the node into the table
    data[index] = HashNode(key, value);
    size++;
}


// Iterate through the vector 
// If the record is empty - print empty
// If not - print key, value pair
template <typename T>
void HashMap<T>::print() const {
    for (int i = 0; i < data.size(); i++) {
        if (data[i].empty()) {
            std::cout << i << " empty";
        } 
        else if (data[i].deleted()) {
            std::cout << i << " deleted";
        } 
        else {
            std::cout << i << " {key: " << data[i].key;
            std::cout << "; value: " << data[i].value << "}";
        }
        std::cout << '\n';
    }

}

template <typename T>
int HashMap<T>::hash(int key) const {
    return key % data.size();
}


template <typename T>
int HashMap<T>::searchIndex(int key) const {
    int index = hash(key);
    int counter = 0;

    while (!data[index].empty()) {
        if (data[index].key == key) {
            return index;
        }
        index = (index + 1) % data.size();
        counter++;

        if (counter >= data.size()) {
            return -1;
        }
    }

    return -1;
}

template <typename T>
const T& HashMap<T>::search(int key) const {
    int index = searchIndex(key);

    if (index == -1) {
        throw std::out_of_range("search: key not found");
    }

    return data[index].value;
}

template <typename T>
void HashMap<T>::remove(int key) {
    int index =searchIndex(key);

    if (index == -1) {
        std::cout << " remove: no such key" << std::endl;
        return;
    }
    data[index] = HashNode<T>::makeDeleted();
    size--;
}