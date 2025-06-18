#ifndef STACK_H
#define STACK_H

class Stack{
    int size;
    int top;
    int* list;
    
    public :
        Stack(int cap);
        ~Stack();
        void push(int val);
        bool isEmpty();
        bool isFull();
        int pop();
        int peek();
        void clear();
        void print();
};
#endif