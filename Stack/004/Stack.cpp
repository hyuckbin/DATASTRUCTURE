#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(): head(nullptr),size(0){}
Stack::~Stack(){
    initialize();
}

void Stack::initialize(){
        while(head!=nullptr){
            Node *temp = head;
            head = head->nextnode;
            delete temp;
        }
        size =0;
    }
bool Stack::isEmpty() const{
    return head== nullptr;
}
void Stack::push(const int val){
    Node* x = new Node(val);
    
    x->nextnode = head;
    head = x;
    size ++;
}

void Stack::pop(){
    if(isEmpty()){
        cout <<"under Flow!" <<endl;
        return;
    }
    Node* p = head;
    head = head->nextnode;
    size --;
    delete p;
}

int Stack::top(){
    if(isEmpty()){
        cout <<"Stack is empty!" <<endl;
        return -1;
    }
    return head->data;
}

int Stack::getNodeCount(){
    return size;
}

void Stack::printAll(){
    Node* p = head;
    for(int i=0; i<size; i++){
        cout << p->data << " -> ";
        p = p->nextnode;
    }
    cout << " null " <<endl;
}