#ifndef STACKLIST_HPP
#define STACKLIST_HPP


template <typename T>
class StackList {
public:
    StackList();
    ~StackList();

    void        push(const T& val);
    bool        empty() const;
    void        print() const;
    T           pop();
    const T&    top() const;
    
private:
    template <typename U>
    class Node {
        public:
            U data;
            Node<U>* next;
            Node(const U& val = U(), Node<U>* n = nullptr)
                : data(val), next (n) {

            }

    };
    Node<T>* top_node;

};

#endif