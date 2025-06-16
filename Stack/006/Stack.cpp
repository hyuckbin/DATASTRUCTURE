#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack():head(nullptr) , size(0){}

Stack::~Stack(){
    void clear();
}
void Stack:: push(char val){
    Node* p = new Node(val);

    p->next = head;
    head = p;
    size++;
}
void Stack::pop(){
    if(isEmpty()) return;
    size --;
    Node * temp = head;
    head = head->next;
    delete temp;
}
char Stack::top(){
    return head->data;
}
bool Stack::isEmpty(){
    return head==nullptr;
}
void Stack::printAll(){
    Node* temp = head;
    for(int i=0; i<size; i++){
        cout << temp->data;
        temp = temp->   next;
    }
    cout << endl;
}
void Stack::clear(){
    while(head!= nullptr){
        Node*temp =head;
        temp = temp->next;
        delete head;
    }
}