#ifndef STACK_H
#define STACK_H

class Node{
    public:
        int data;
        Node* next;

        Node(int val) : data(val) , next(nullptr) {}
};

class Stack{
    Node* head;
    int count;
    public :
        Stack();
        ~Stack();
        void push(int val);
        void pop();
        int top();
        bool isEmpty() const;
        void clear();
        int getNodeCount();
        void printAll();
};
#endif