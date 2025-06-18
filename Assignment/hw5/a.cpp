#include <iostream>
#include "Stack.h"
using namespace std;
int main(){
    Stack *stack = new Stack(5);
    stack->push(1);
    stack->push(3);
    stack->print();

    cout << "Pop: " << stack->pop() << endl;
    stack->print();

    delete stack;

    return 0;   
}