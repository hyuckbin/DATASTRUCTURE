#include "CirQueue.h"
#include <iostream>
using namespace std;
        CirQueue::CirQueue(int n) : maxsize(n+1),front(0),rear(0){
                list = new Student[maxsize];
        }
        CirQueue::~CirQueue(){
                delete[] list;
        }
        void CirQueue::clear(){
                rear =0;
                front =0;
        }
        void CirQueue::enqueue(const Student& val){
                if(isFull()) return;
                list[rear] = val;
                rear =(rear+1) % maxsize;
        }
        void CirQueue::dequeue(){
                if(isEmpty()) return;
                front = (front+1) % maxsize;
        }
        Student  CirQueue::Rear(){
                if(isEmpty()) return {"", -1.0};
                return list[(rear-1 +maxsize) %maxsize];
        }
        Student  CirQueue::Front(){
                if(isEmpty()) return {"", -1.0};
                return list[front];
        }
        bool CirQueue::isEmpty(){
                return rear == front;
        }
        bool CirQueue::isFull(){
                return (rear+1) % maxsize == front;
        }
        void CirQueue::print(){
                if(isEmpty()) return;
                
                for(int i=0; i<size(); i++){
                        int index = (front +i) % maxsize;
                        cout << list[index].name <<" " << list[index].gpa <<endl;
                }
        }
        int CirQueue::size(){
                return (rear - front + maxsize) %maxsize;
        }