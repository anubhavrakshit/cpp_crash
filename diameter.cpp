#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        return 1 + std::max(depth(root->left), depth(root->right));
    }
   
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        return max(depth(root->left) + depth(root->right), max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)) );
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode{2};
    TreeNode* node1 = new TreeNode{3};
    TreeNode* node2 = new TreeNode{4};
    TreeNode* node3 = new TreeNode{5};
    root->left = node1;
    root->right = node2;
    node1->left = node3;

    cout << s.diameterOfBinaryTree(root);    
    return 0;
}