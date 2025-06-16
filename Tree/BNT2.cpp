//inorderTree, preorder , postorder 값 사용자가 입력
#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val) : data(val) ,left(nullptr) , right(nullptr){}
};

//사용자에게 입력받은 배열과 크기를 파라미터로 받아서 트리를 생성한다.
TreeNode* buildTree(int* nums,int n){
    if(n==0 || nums[0] ==0) return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while(i < n){
        TreeNode* curr = q.front();
        q.pop();

        if(i < n){
            if(nums[i] != 0){
                curr->left = new TreeNode(nums[i]);
                q.push(curr->left);
            }
            i++;
        }
        if(i<n){
            if(nums[i]!=0){
                curr->right = new TreeNode(nums[i]);
                q.push(curr->right);
            }
            i++;
        }
    }
    return root;
}

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    cout <<root->data<<" ";
    inorder(root->right);
}

void preorder(TreeNode* root){
    if(!root) return;
    cout << root -> data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root -> data << " ";
}
int main(){
    int count;
    int choice;
    cin >> count >> choice;
    int *arr = new int[count];
    for(int i=0; i<count ; i++){
        cin >> arr[i];
    }
    TreeNode* root = buildTree(arr,count);
    switch(choice){
        case 1 : {
            preorder(root);
            break;
        }
        case 2 : {
            postorder(root);
            break;
        }
    }
    
    delete[] arr;
    return 0;
}