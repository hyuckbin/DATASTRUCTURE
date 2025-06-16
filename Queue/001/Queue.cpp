#include "Queue.h"
#include <iostream>
using namespace std;

    Queue::Queue(int cap): maxsize(cap+1) , front(0) , rear(0){
        list = new int[maxsize];
    }
    Queue::~Queue(){
        delete[] list;
    }
    void Queue::clear(){
        front= 0;
        rear = 0;
    }
    bool Queue::isEmpty () const{
        return rear == front;
    }
    bool Queue::isFull () const{
        return (rear+1) % maxsize ==front; 
    }
    void Queue::enqueue(int val){
        if(isFull()) return;
        list[rear] = val;
        rear = (rear+1) %maxsize;
    }
    void Queue::dequeue(){
        if(isEmpty()) return;
        front = (front+1) %maxsize;
    }
    int Queue::Front(){
        if(isEmpty()) return -1;
        return list[front];
    }
    int Queue::Rear(){
        if(isEmpty()) return -1;
        return list[(rear-1 + maxsize)%maxsize] ;
    }
    int Queue::size() const{
        return (rear - front+maxsize) %maxsize ;
    }
    // void Queue::printAll(){
    // if(isEmpty())return;
    // int i = front;
    // while(i<rear){
    //     cout << list[i] << " -> ";
    //     i++;
    // }
    //
    //    cout << endl;}

    void Queue::printAll(){
        int index = size();
        cout << "Size : "<< index <<endl;

        cout << "Queue : ";
        for(int i=0; i<index; i++){
            int a = (front+i) % maxsize;
            cout << "[" << list[a] << "]";
        }
        cout <<endl;
        
        cout << "index : ";
        for(int i=0; i<index; i++){
            int a = (front+i+1) % maxsize;
            if(a==10) a=1;
            cout << a <<" ";
        }
        cout <<endl;

        cout << "front : " <<front << ", rear : " <<rear<<endl;


    }

   