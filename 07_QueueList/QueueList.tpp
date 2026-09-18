#include "QueueList.hpp"

template <typename T>
bool QueueList<T>::empty() const {
    return list.empty();
}