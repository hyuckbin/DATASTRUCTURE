#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;
    Stack::Stack(int a ) {
        top = -1;
        list = new element[a];
    }

    Stack::~Stack() {
        delete[] list;
    }

    void Stack::clean() {
        top = -1;
    }

    bool Stack::isEmpty() const {
        return top == -1;
    }

    bool Stack::isFull() const {
        return top == maxsize - 1;
    }

    void Stack::push(element& e) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }
        list[++top] = e;
    }


    element Stack::pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return { -1, "" };
        }
        return list[top--];
    }
    
    //현재 stack 값들을 모두 출력
    void Stack::print()  {
        for (int i = top; i >= 0; i--) {
            cout << list[i].rank << "등 " << list[i].gift << endl;
            }
    }

    //pop 하면서 전체 출력하고 stack은 비워지게 된다
    void Stack::rprint() {
        while (!isEmpty()) {
            element e = pop();
            cout << e.rank << "등 " << e.gift << endl;
        }
    }