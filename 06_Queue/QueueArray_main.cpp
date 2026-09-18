#include "QueueArray.hpp"

int main(void) {
    QueueArray<int> q;

    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);

    q.print();

    while (!q.empty()){
        std::cout << q.dequeue() << std::endl;
    }

    return 0;
}