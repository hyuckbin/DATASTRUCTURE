#include "TreeQueue.h"
#include <iostream>
using namespace std;

TreeNode* buildTree(int* arr, int size) {
    if (size == 0 || arr[0] == 0) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    TreeQueue q;
    q.enqueue(root);
    int i = 1;

    while (i < size) {
        TreeNode* current = q.Front(); q.dequeue();

        if (i < size && arr[i] != 0) {
            current->left = new TreeNode(arr[i]);
            q.enqueue(current->left);
        }
        i++;

        if (i < size && arr[i] != 0) {
            current->right = new TreeNode(arr[i]);
            q.enqueue(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    int arr[] = {1, 2, 3, 0, 4, 5, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = buildTree(arr, size);
    // 이후 root를 이용해 트리를 순회하거나 출력 가능
}
