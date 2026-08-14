/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaNode = NULL;

    int lca(TreeNode* node, TreeNode*p, TreeNode* q) {
        if (!node) return 0;

        int left = lca (node -> left, p, q);
        int right = lca (node -> right, p, q);
        
        int self = (node == p || node == q), total = (left + right + self);

        if (total == 2 && !lcaNode) lcaNode = node;

        return total;
    }

    TreeNode* dfs (TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        TreeNode *left = dfs (root -> left, p, q);
        TreeNode *right = dfs (root -> right, p, q);

        return left && right ? root : left ? left : right; 
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};