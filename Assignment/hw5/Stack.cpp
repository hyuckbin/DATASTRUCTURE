#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack(int cap) : size(cap), top(-1){
    list = new int[size];
}

Stack::~Stack(){
    delete[] list;
}
void Stack::push(int val){
    if(isFull()) return;

    list[++top] = val;
}
bool Stack::isEmpty(){
    return top==-1;
}
bool Stack::isFull(){
    return top +1 == size;
}
int Stack::pop(){
    if(isEmpty()) return -1;

    int temp = list[top--];
    return temp;
}
int Stack::peek(){
    if(isEmpty()) return -1;
    return list[top];
}
void Stack::clear(){
    top = -1;
}
void Stack::print(){
    if(isEmpty()) return;

    for(int i=top; i>=0; i--){
        cout << list[i] <<" ";
    }
    cout<<" null " <<endl;
}