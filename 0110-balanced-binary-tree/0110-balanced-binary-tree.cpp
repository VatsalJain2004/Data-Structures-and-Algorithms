/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool heightBalance = true;

    bool isBalanced(TreeNode* root) {
        return function2(root) != -1;
    }
    
    int function2 (TreeNode* root) {
        if (!root) return 0;

        int left = function2 (root -> left);
        if (left == -1) return -1;
        int right = function2 (root -> right);
        if (right == -1) return -1;
        
        if (abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }

    int function1(TreeNode* root) {
        if (!root) return 0;
        if (!root -> left && !root -> right) return 1;

        int left = function1 (root -> left);
        int right = function1 (root -> right);
        
        if (abs(left - right) > 1) heightBalance = false;

        return 1 + max(left, right);
    }
};