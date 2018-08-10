#include <iostream>
using namespace std;

template <class T>
class Stack {
    private:
        T node;
        Stack *next_node;
    public:
        Stack();
        ~Stack() {};
        int size();
        void push(T item);
        T top();
        void pop();
};

template <class T>
Stack<T>::Stack() {
    next_node = nullptr;
}

template <class T>
int Stack<T>::size() {
    if (next_node != nullptr) {
        return next_node->size() + 1;
    } else {
        return 0;
    }
}

template <class T>
void Stack<T>::push(T item) {
    if (next_node != nullptr) {
        next_node->push(item);
    } else {
        next_node = new Stack<T>;
        next_node->node = item;
    }
}

template <class T>
T Stack<T>::top() {
    if (next_node != nullptr) {
        return next_node->top();
    } else {
        return node;
    }
}

template <class T>
void Stack<T>::pop() {
    if (next_node == nullptr) {
        return;
    }
    if (next_node->next_node == nullptr) {
        delete next_node;
        next_node = nullptr;
    } else {
        next_node->pop();
    }
}