#ifndef STACK_H
#define STACK_H
using namespace std;
#include<string>
struct element{
    int rank;
    string gift;
};
class Stack{
    int maxsize;
    int top;
    element* list;

    public:
        Stack(int a );
        ~Stack();
        void clean();
        bool isEmpty() const;
        bool isFull() const;
        void push(element& val);
        element pop();
        void print();
        void rprint();
};

#endif