#include "Stack.h"
#include <iostream>
using namespace std;

    Stack::Stack():head(nullptr),count(0){}
    Stack::~Stack(){
        clear();
    }
    void Stack::push(int val){
        Node* p = new Node(val);
        p->next = head;
        head = p;
        count ++;
    }
    void Stack::pop(){
        if(isEmpty()) return;

        Node* temp = head;
        head = head->next;
        delete temp;
        count --;
    }
    int Stack::top(){
        return head->data;
    }
    bool Stack::isEmpty() const{
        return head == nullptr;
    }
    void Stack::clear(){
        while(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    int Stack::getNodeCount(){
        return count;
    }
    void Stack::printAll(){
        Node* temp = head;
        while(temp != nullptr){
            cout <<temp->data << " -> ";
            temp = temp->next;
        }
    }