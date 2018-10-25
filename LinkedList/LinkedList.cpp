#include <iostream>

class Node {
    private:
        int element;
        Node *next_node;
    public:
        Node(int = 0, Node* = nullptr);
        ~Node();
        int get();
};

Node::Node(int e, Node *n) {
    element = e;
    next_node = n;
}

Node::~Node() {
    
}

int Node::get() {
    element += 1;
    return element;
}

int main(int argc, char const *argv[])
{
    Node a;
    std::cout << a.get() << std::endl;
    return 0;
}
