#ifndef STACK_H
#define STACK_H

class Node{
    public:
        char data;
        Node* next;
        Node(char val) : data(val) , next(nullptr){}
};

class Stack{
    Node* head;
    int size;
    
    public:
        Stack();
        ~Stack();
        void push(char val);
        void pop();
        char top();
        bool isEmpty();
        void printAll();
        void clear();
};

#endif