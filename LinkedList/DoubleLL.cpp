#include <iostream>

template <class T>
class Node {
    private:
        T key;
        Node *next;
        Node *prev;
    public:
        Node(int = 0, Node* = nullptr, Node* = nullptr);
        ~Node() {/*empty*/};
};

template <class T>
Node<T>::Node(int k, Node *p, Node *n) {
    key = k;
    prev = p;
    next = n;
}


int main(int argc, char const *argv[])
{
    Node<int> a;
    return 0;
}
