#include "LLQueue.h"
#include <iostream>
using namespace std;

    LLQueue::LLQueue():front(nullptr) , rear(nullptr){}
    LLQueue::~LLQueue(){
        while(!isEmpty()){
            dequeue();
        }
    }
    bool LLQueue::isEmpty(){
        return front == nullptr && rear == nullptr;
    }
    void LLQueue::enqueue(int value){
        Node* newnode = new Node(value);
        if(isEmpty()){
            front = rear = newnode;
        }
        rear->next = newnode;
        rear = newnode;
    }
    void LLQueue::dequeue(){
        if(isEmpty()) return;
        Node* temp = front;
        front = front->next;
        delete temp;

        if(front == nullptr) rear = nullptr;
    }
    int LLQueue::Front(){
        if(isEmpty()) return -1;
        return front->data;
    }
    int LLQueue::Rear(){
        if(isEmpty()) return -1;
        return rear->data;
    }
    void LLQueue::display(){
        if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
        Node* temp = front;
        while(temp != nullptr){
            cout << temp->data;
            temp = temp->next;
            if(temp != nullptr) cout <<" -> ";
        }
        cout <<endl;
    }