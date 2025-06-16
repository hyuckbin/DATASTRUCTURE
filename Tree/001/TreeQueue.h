#ifndef TREEQUEUE_H
#define TREEQUEUE_H

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};


struct TreeQNode {
    TreeNode* data;
    TreeQNode* next;
    TreeQNode(TreeNode* val) : data(val), next(nullptr) {}
};

class TreeQueue {
private:
    TreeQNode* front;
    TreeQNode* rear;

public:
    TreeQueue();
    ~TreeQueue();
    void enqueue(TreeNode* val);
    void dequeue();
    TreeNode* Front();
    bool isEmpty();
};

#endif
