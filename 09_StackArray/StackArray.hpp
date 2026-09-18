#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP

template <typename T, int capacity = 100>
class StackArray {
public:
    StackArray();

    void push(const T& val);
    T pop();
    bool full() const;
    bool empty() const;
    const T& top() const;

    //to do
    void print() const;

private:
    T data[capacity];
    int top_idx;
    
};





#endif