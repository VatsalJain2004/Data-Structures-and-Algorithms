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
    int maxSum = -1001;

    int dfs (TreeNode* root) {
        if (!root) return 0;

        int leftSum = max(0, dfs (root -> left));
        int rightSum = max(0, dfs (root -> right));

        maxSum = max({
            root -> val, 
            root -> val + leftSum + rightSum, 
            maxSum
        });
        // cout <<  maxSum<< " " << root -> val << " " << leftSum << " " << rightSum << endl;
        // cout << "-------------------------------" << endl << endl;

        return root -> val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};