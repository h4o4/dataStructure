#include <iostream>
#include <queue>
using namespace std;

template <class T>
class Queue {
    private:
        T node;
        Queue *next_node;
    public:
        Queue();
        ~Queue() {};
        int size();
        void push(T item);
        T front();
        T back();
        void pop();
};

template <class T>
Queue<T>::Queue() {
    next_node = nullptr;
}

template <class T>
int Queue<T>::size() {
    if (next_node != nullptr) {
        return next_node->size() + 1;
    } else {
        return 0;
    }
}

template <class T>
void Queue<T>::push(T item) {
    if (next_node != nullptr) {
        next_node->push(item);
    } else {
        Queue *temp = new Queue;
        temp->node = item;
        next_node = temp;
    }
}

template <class T>
T Queue<T>::front() {
    if (next_node != nullptr) {
        return next_node->node; 
    } else {
        return node;
    }
}

template <class T>
T Queue<T>::back() {
    if (next_node != nullptr) {
        return next_node->back();
    } else {
        return node;
    }
}

template <class T>
void Queue<T>::pop() {
    if (next_node == nullptr) {
        node = 0;
    } else {
        node = next_node->node;
        next_node = next_node->next_node;
    }
}