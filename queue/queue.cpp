#include <iostream>
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
        next_node = new Queue;
        next_node->node = item;
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
        return;
    } else {
        Queue *temp = next_node;
        if (next_node->next_node != nullptr) {
            delete next_node;
            next_node = temp->next_node;
        } else {
            delete next_node;
            next_node = nullptr;
        }
    }
}