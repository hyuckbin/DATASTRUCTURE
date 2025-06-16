#ifndef LLQUEUE_H
#define LLQUEUE_H
struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr){}
    };

class LLQueue {
private:
    
    Node* front;
    Node* rear;

public:
    LLQueue();
    ~LLQueue();
    bool isEmpty();
    void enqueue(int value);
    void dequeue();
    int Front();
    int Rear();
    void display();
};

#endif