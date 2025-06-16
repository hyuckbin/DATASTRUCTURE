#include "LLQueue.h"
#include <iostream>
using namespace std;

int main(){
    LLQueue q;
    int choice, value;

    while (true) {
        cout << "\n1.enqueue 2.dequeue 3.showfront 4.showrear 5.displayQueue 6.exit > ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter Value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "element at front: " << q.Front() << endl;
                break;
            case 4:
                cout << "element at rear: " << q.Rear() << endl;
                break;
            case 5:
                q.display();
                break;
            case 6:
                cout << "bye!" << endl;
                return 0;
        }
    }
    return 0;
}