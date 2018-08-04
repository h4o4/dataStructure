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
    node = 0;
    next_node = nullptr;
}

template <class T>
int Queue<T>::size() {
    if (next_node != nullptr) {
        return next_node->size() + 1;
    } else {
        if (node == 0) {
            return 0;
        } else {
            return 1;
        }
    }
}

template <class T>
void Queue<T>::push(T item) {
    if (next_node != nullptr) {
        next_node->push(item);
    } else {
        if (node == 0) {
            node = item;
        } else {
            Queue *temp = new Queue;
            temp->node = item;
            temp->next_node = nullptr;
            next_node = temp;
        }
    }
}

template <class T>
T Queue<T>::front() {
    return node;
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
        Queue *temp = next_node->next_node;
        delete next_node;
        next_node = temp;
    }
}