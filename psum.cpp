#include <iostream>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sol{0};
    int target;
    int pathSumHlpr(TreeNode* root, int sum) {
        
        if (root) {
            cout << "At " << root->val << "Sum " << sum << endl;
            if (root->val == sum) {
                cout << "Sum " << root->val << endl;
                sol++;
            } else {
                cout << "Try left" << endl;
                pathSumHlpr(root->left, sum - root->val);
                cout << "Try right" << endl;
                pathSumHlpr(root->right, sum - root->val);
                
            }

            if (sum == target) {
                cout << "Try left subtree" << endl;
                pathSumHlpr(root->left, target);
                cout << "Try rightt subtree" << endl;
                pathSumHlpr(root->right, target);
            }
            return root->val;
        }
        
        return 0;
    }
    
    int pathSum(TreeNode* root, int sum) {
        
        target = sum;
        pathSumHlpr(root,sum);
        
        return sol;
    }
};

int main()
{
    

    
    TreeNode five(5);
    TreeNode four(4, nullptr, &five);
    TreeNode three(3, nullptr, &four);
    TreeNode two(2, nullptr, &three);
    TreeNode root(1, nullptr, &two);

    Solution s;

    cout << "Answ " << s.pathSum(&root, 3);

    return 0;
}