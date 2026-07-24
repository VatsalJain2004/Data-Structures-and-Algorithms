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
    int bfs (TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);

        int levels = 0;
        while (!q.empty()) {
            int size = q.size();
            levels += 1;
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                
                if (node -> left) 
                    q.push(node -> left);
                
                if (node -> right) 
                    q.push(node -> right);
            }
        }
        return levels;
    }

    int dfs (TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root -> left), right = dfs(root -> right);
        return max(left, right) + 1;
    }

    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};