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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return (root -> val) % 2 ? dfs (root, targetSum) : bfs (root, targetSum);
    }

    bool dfs (TreeNode* root, int targetSum) {
        if (!root) return 0;
        if (!root -> left && !root -> right) return root -> val == targetSum;

        targetSum -= root -> val;
        return hasPathSum (root -> left, targetSum) || hasPathSum (root -> right, targetSum);
    }

    bool bfs (TreeNode* root, int& targetSum) {
        if (!root) return false;

        queue<pair<TreeNode*, int>> q;
        q.push({root, targetSum - root->val});

        while (!q.empty()) {
            auto [node, remaining] = q.front();
            q.pop();

            if (!node->left && !node->right &&
                remaining == 0) {
                return true;
            }

            if (node->left) {
                q.push({
                    node->left,
                    remaining - node->left->val
                });
            }

            if (node->right) {
                q.push({
                    node->right,
                    remaining - node->right->val
                });
            }
        }

        return false;
    }
};