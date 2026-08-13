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
        diameterOfBinaryTree(root);      
        return heightBalance;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        if (!root -> left && !root -> right) return 1;

        int left = diameterOfBinaryTree (root -> left);
        int right = diameterOfBinaryTree (root -> right);
        
        if (abs(left - right) > 1) heightBalance = false;

        return 1 + max(left, right);
    }
};