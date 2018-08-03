#include <iostream>
using namespace std;

class Stack {
    private:
        char node;
        Stack *next_node;
    public:
        Stack();
        ~Stack();
        int size();
        void push(char &item);
        char top();
        void pop();
};

Stack::Stack() {
    node = '\0';
    next_node = nullptr;
}

Stack::~Stack() {}

int Stack::size() {
    if (next_node != nullptr) {
        return next_node->size() + 1;
    } else {
        if (node == '\0') {
            return 0;
        } else {
            return 1;
        }
    }
}

void Stack::push(char &item) {
    if (next_node != nullptr) {
        next_node->push(item);
    } else {
        if (node == '\0') {
            node = item;
        } else {
            Stack *temp = new Stack;
            temp->node = item;
            temp->next_node = nullptr;
            next_node = temp;
        }
    }
}

char Stack::top() {
    if (next_node != nullptr) {
        return next_node->top();
    } else {
        return node;
    }
}

void Stack::pop() {
    if (next_node == nullptr) {
        node = '\0';
        return;
    }
    if (next_node->next_node == nullptr) {
        next_node = nullptr;
    } else {
        next_node->pop();
    }
}