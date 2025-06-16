#ifndef STACK_H
#define STACK_H
struct Node{
    int data;
    Node* nextnode;

    Node(int val) : data(val), nextnode(nullptr){}
};

class Stack{
    Node* head;
    int size;

    public:
        Stack();
        ~Stack();
        void initialize();
        bool isEmpty() const;
        void push(const int val);
        void pop();
        int top();
        int getNodeCount();
        void printAll();
};
#endif