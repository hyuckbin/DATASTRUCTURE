//inorder Tree -- 값 수동 입력
#include <iostream>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left,*right;
        TreeNode(int v) : val(v) , left(nullptr) , right(nullptr){}

};
    void inorder(TreeNode* root){
        if(root == nullptr) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root -> right);
    }
int main() {
    // 수동으로 트리 구성
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Inorder Traversal: ";
    inorder(root); // 출력: 4 2 5 1 3
    cout << endl;

    return 0;
}
