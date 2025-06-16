#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left, * right;
    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

// 0은 빈 노드로 간주하여 건너뜀
TreeNode* buildTree(int* nums, int size) {
    if(size == 0 || nums[0] == 0) return nullptr;
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i= 1;

    while(i < size){
        TreeNode* curr = q.front(); q.pop();
        //왼쪽 자식
        if(i<size && nums[i] !=0){
            curr->left = new TreeNode(nums[i]);
            q.push(curr->left);
        }

        i ++;

        if(i<size&&nums[i] !=0){
            curr->right = new TreeNode(nums[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) return ;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    int n, method;
    cin >> n >> method;

    int* nums = new int[n];
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    TreeNode* root = buildTree(nums, n);

    if (method == 1) {
        cout << "preorder traversal: ";
        preorder(root);
    }
    else if (method == 2) {
        cout << "postorder traversal: ";
        postorder(root);
    }
    else {
        cout << "inorder traversal: ";
        inorder(root);
    }
    cout << endl;
    delete[] nums;
    return 0;
}