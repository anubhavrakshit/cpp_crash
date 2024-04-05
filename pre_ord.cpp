#include <iostream>
#include <stack>
#include <unistd.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int val) : data{val} {}
};

void printInOrder(TreeNode* root) {
    if (!root) {
        return;
    }

    cout << root->data << ", ";
    printInOrder(root->left);
    printInOrder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(8);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(9);
    root->right->right = new TreeNode(7);

    printInOrder(root);
    cout << endl;

    stack<TreeNode*> io_stack;
    auto curr = root;
    while (!io_stack.empty() or curr) {
        if (curr) {
            cout << curr->data << ", ";
            io_stack.push(curr);
            curr = curr->left; 
        } else {
            auto parent = io_stack.top();
            io_stack.pop();
            curr = parent->right;
        }
    }
    cout << endl;
    return 0;
}