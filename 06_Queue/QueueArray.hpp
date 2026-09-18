#ifndef QUEUEARRAY_HPP
#define QUEUEARRAY_HPP

template <typename T, int size = 100>
class QueueArray {
    public:
        QueueArray();

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
        T data [size];
        int front_idx, back_idx;
        int queue_size;
};
#include "QueueArray.tpp"

#endif