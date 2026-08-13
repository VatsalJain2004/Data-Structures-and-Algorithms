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
    vector<int> ans;
    
    TreeNode* recursion (TreeNode* root) {
        if (!root) return nullptr;

        ans.push_back(root -> val);
        recursion(root -> left);
        recursion(root -> right);

        return root;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        ans = {};
        recursion(root);
        return ans;    
    }
};