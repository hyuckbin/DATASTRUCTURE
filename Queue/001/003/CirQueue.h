#ifndef CIRQUEUE_H
#define CIRQUEUE_H
#include <string>
using namespace std;
struct Student{
    string name;
    double gpa;
};
class CirQueue{
    int front, rear;
    int maxsize;
    Student* list;

    public:
        CirQueue(int n);
        ~CirQueue();
        void clear();
        void enqueue(const Student& elem);
        void dequeue();
        Student Rear();
        Student Front();
        bool isEmpty();
        bool isFull();
        void print();
        int size();
};
#endif