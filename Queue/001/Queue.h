#ifndef Queue_H
#define Queue_H
class Queue{
    int maxsize;
    int front;
    int rear;
    int* list;

    public:
        Queue(int cap);
        ~Queue();
        void clear();
        bool isEmpty () const;
        bool isFull () const;
        void enqueue(int val);
        void dequeue();
        int Front();
        int Rear();
        int size() const;
        void printAll();
};
#endif
