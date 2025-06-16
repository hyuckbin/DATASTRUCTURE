#include "TreeQueue.h"
#include <iostream>
using namespace std;

TreeQueue::TreeQueue(): front(nullptr), rear(nullptr) {}
TreeQueue::~TreeQueue() {
    while (!isEmpty()) dequeue();
}

void TreeQueue::enqueue(TreeNode* val) {
    TreeQNode* newnode = new TreeQNode(val);
    if (isEmpty()) front = rear = newnode;
    else {
        rear->next = newnode;
        rear = newnode;
    }
}

void TreeQueue::dequeue() {
    if (isEmpty()) return;
    TreeQNode* temp = front;
    front = front->next;
    delete temp;
    if (!front) rear = nullptr;
}

TreeNode* TreeQueue::Front() {
    if (isEmpty()) return nullptr;
    return front->data;
}

bool TreeQueue::isEmpty() {
    return front == nullptr;
}
