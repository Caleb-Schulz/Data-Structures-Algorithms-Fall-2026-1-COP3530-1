#ifndef QUEUELIST_HPP
#define QUEUELIST_HPP
#include "../04_DLList/DLList.hpp"

template <typename T>
class QueueList {
    public:
        QueueList();

        bool        empty() const;
        bool        full() const;
        void        print() const;
        void        enqueue(const T& val);

        const T&    dequeue();

        // todo
        // const t& front(); show fist don't remove
        // void clear(); remove all elements
        // int size(); retuen queue size

    private:
        DLList<T> list;
};
#include "QueueList.tpp"

#endif