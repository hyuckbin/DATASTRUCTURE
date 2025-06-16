#include "Queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue queue(9);
    cout << "===== Dequeue x 1 =====" << endl;
    queue.dequeue();  
    queue.printAll();

    cout << "===== Enqueue x 7 (10 ~ 70) =====" << endl;
    for (int i = 1; i <= 7; i++) {
        queue.enqueue(i * 10);
    }
    queue.printAll();

    cout << "===== Dequeue x 3 =====" << endl;
    for (int i = 0; i < 3; i++) {
        queue.dequeue();
    }
    queue.printAll();

    cout << "===== Enqueue x 6 (10 ~ 60) =====" << endl;
    for (int i = 1; i <= 6; i++) {
        queue.enqueue(i * 10);
    }
    queue.printAll();

}